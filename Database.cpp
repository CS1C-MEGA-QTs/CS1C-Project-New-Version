/******************************************************************************
 * PROGRAMMERS: - Jonathan Aguirre
 *              - Tina     Faraji
 *              - Suhyr    Hasan
 *              - Weston   Mathews
 * CLASS      : CS1C
 * SECTION    : MW 5:00p - 7:30p
 * DUE DATE   : 02/23/20
 *****************************************************************************/
#include "Database.h"
#include "Review.h"

// Constructor
// Parameterized constructor
Database::Database(QString path, QString driver)
    :QSqlDatabase(addDatabase(driver))
{
    // Set Hostname to Local
    setHostName("localhost");
    setDatabaseName(path);

    // Check if open
    if(open())
    {
        qDebug() << "Database opened successfully";
    }
    else
    {
        qDebug() << this->lastError().text();
    }
}

// Mutators
// Testimonials Page //
//Add review (customerName, reviewText)
bool Database::AddReview(QString name, QString reviewText) { return false; }

// Login
bool Database::AttemptLogin(QString username, QString password)
{
    QSqlQuery query;
    // Run admin credential query
    query.prepare("SELECT * FROM users WHERE admin = 1 and username = :username"
                  " and password = :password;");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if(!query.exec())
    {
        qDebug() << query.lastError().text();
    }

    return query.next();
}

// Add customer (all fields at once)
bool Database::AddCustomer(QString name, QString address, QString website,
                           QString interestLevel, QString doNotContact,
                           QString keyAccount, QString pamphletSent)
{
    QSqlQuery query;

    // Prep "Add Customer" Query
    query.prepare("INSERT INTO customers VALUES (:customerID, :name, "
                  ":address, :website, :interestLevel, :doNotContact, "
                  ":keyAccount, :pamphletSent);");

    // Bind safe values
    query.bindValue(":name", name);
    query.bindValue(":address", address);
    query.bindValue(":website", website);
    query.bindValue(":interestLevel", interestLevel);
    query.bindValue(":doNotContact,", doNotContact);
    query.bindValue(":keyAccount", keyAccount);
    query.bindValue(":pamphletSent", pamphletSent);

    // Execute query and return status
    return query.exec();
}

// Edit customer data (individual fields)
bool Database::UpdateCustomer(QString customerID, QString name, QString address,
                              QString website, QString interestLevel,
                              QString doNotContact, QString keyAccount,
                              QString pamphletSent)
{
    QSqlQuery query;

    // Prepare query to update customer listing
    query.prepare("UPDATE customers "
                  "SET name = :name, "
                  "address = :address, "
                  "website = :website, "
                  "interestLevel = :interestLevel, "
                  "doNotContact = :doNotContact, "
                  "keyAccount = :keyAccount, "
                  "pamphletSent = :pamphletSent "
                  "WHERE customerID = :customerID;");

    // Bind safe values
    query.bindValue(":name", name);
    query.bindValue(":address", address);
    query.bindValue(":website", website);
    query.bindValue(":interestLevel", interestLevel);
    query.bindValue(":doNotContact,", doNotContact);
    query.bindValue(":keyAccount", keyAccount);
    query.bindValue(":pamphletSent", pamphletSent);
    query.bindValue(":customerID", customerID);

    // Execute query and return status
    return query.exec();
}

// Remove customer
// Note: This needs to convert the input to uppercase
bool Database::DeleteCustomer(QString customerID)
{
    QSqlQuery query;

    // Prepare query to delete listing
    query.prepare("DELETE from customers "
                  "WHERE customerID = :customerID;");

    // Bind safe values
    query.bindValue(":customerID", customerID);
    return query.exec();
}
// Remove customer
// Note: This needs to convert the input to uppercase

// Home Page (?) //
// Change 'pamphletSent' to 'true' (when customer orders pamphlet)
bool Database::SendPamphlet(QString name,QString pamphletSent)
{
    QSqlQuery query;
    // Prepare query to send pamphlet
   query.prepare("UPDATE customers "
                 "SET pamphletSent = :pamphletSent "
                 "WHERE name = :name;");
    // Bind safe values
     query.bindValue(":name",name);
     query.bindValue(":pamphletSent", pamphletSent);
    return query.exec();
}

// Accessors
// Print reviews (customerName, reviewText)
QStringList Database::GetReviews() {return QStringList();}

// Placing An Order
bool Database::PlacingOrder(QString customerID, QString qtyPurchased, QString date)
{
    QSqlQuery query;
    // Prepare query to add purchase
    query.prepare("INSERT INTO purchases VALUES(:customerID, :qtyPurchased, :date);");

    // Bind safe values
    query.bindValue(":customerID", customerID);
    query.bindValue(":qtyPurchased", qtyPurchased);
    query.bindValue(":date", date);
    return query.exec();
}

// Returning Shipping Address
QString Database::ShippingAddress(QString &name)
{
    QSqlQuery query;
    query.prepare("SELECT address FROM customers WHERE name = :name");
    query.bindValue(":name",name);
    if(query.exec())
    {
        while(query.next())
        {
            name = query.value(0).toString();
            return name;
        }
    }

    return name;
}

/******************************************************************
* ReturnName(QString ar[])
* -----------------------------------------------------------------
* This will assign all customer names and customer reviews into
* thier respective variables of the struct.
*
* RETURNS - Array of names
******************************************************************/
int Database::ReturnNames(QString ar[])
{
    QSqlQuery  query;
    const int  AR_SIZE = 100;

    // Set an index for iteration
    int index = 0;
    int count = 0;

    // First we need a loop to pull the names from the customerID's
    // Test this one in the command line version of SQLite3 until you get the query
    // right
    query.prepare("select customers.name, reviews.reviewText "
                  "from customers,reviews where "
                  "customers.customerID = reviews.customerid");

    if(query.exec())
    {
        // Start loop to iterate through available information
        while(query.next() && index < 100)
        {//begin while

            // Set the name using the 'reviewText' column on the 'reviews' table
            // '0' is the first column. If that's not the correct column, adjust
            // the number to the correct one with the name in it.
            ar[index] = (query.value(0).toString());

            qDebug() << "Name is: " << ar[index] << endl;

            // Go to next spot in array
            index++;
            count++;

        }//end while


    }
    else // else output the error
    {
        qDebug() << query.lastError().text();
    }


    return count;
}

/******************************************************************
* ReturnName(QString ar[])
* -----------------------------------------------------------------
* This will assign all customer names and customer reviews into
* thier respective variables of the struct.
*
* RETURNS - Array of names
******************************************************************/
void Database::ReturnReviews(QString ar[])
{
    QSqlQuery  query;
    const int  AR_SIZE = 100;

    // Set an index for iteration
    int index = 0;

    // First we need a loop to pull the names from the customerID's
    // Test this one in the command line version of SQLite3 until you get the query
    // right
    query.prepare("select customers.name, reviews.reviewText "
                  "from customers,reviews where "
                  "customers.customerID = reviews.customerid");

    if(query.exec())
    {
        // Start loop to iterate through available information
        while(query.next() && index < 100)
        {//begin while

            // Set the name using the 'reviewText' column on the 'reviews' table
            // '0' is the first column. If that's not the correct column, adjust
            // the number to the correct one with the name in it.
            ar[index] = (query.value(1).toString());

            qDebug() << "review is: " << ar[index] << endl;

            // Go to next spot in array
            index++;


        }//end while


    }
    else // else output the error
    {
        qDebug() << query.lastError().text();
    }


}

// Destructor
Database::~Database() {}
