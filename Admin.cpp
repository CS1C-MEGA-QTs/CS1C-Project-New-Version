/******************************************************************************
 * PROGRAMMERS: - Jonathan Aguirre
 *              - Tina     Faraji
 *              - Suhyr    Hasan
 *              - Weston   Mathews
 * CLASS      : CS1C
 * SECTION    : MW 5:00p - 7:30p
 * DUE DATE   : 02/23/20
 *****************************************************************************/
#include "Admin.h"
#include "ui_Admin.h"
#include "mainwindow.h"

// Constructor
Admin::Admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);

    // Initialize database
    database = new Database("MegaQTDB.db", "QSQLITE");
}


// Destructor
Admin::~Admin()
{
    delete ui;
}

// This is the GO BACK button
void Admin::on_pushButton_FAdminTMain_clicked()
{
    // Show the MainWindow (i.e. the parent window)
    MainWindow *newmain= new MainWindow();
    newmain->show();
}

// Login button
void Admin::on_button_login_clicked()
{
    QString username ="";
    QString password ="";
    bool success;
    username = ui->inputField_username->text();
    password = ui->inputField_password->text();

    success = database->AttemptLogin(username, password);

    // If admin credentials are valid
    if(success)
    {
        // Switch to database interface window
        ui->stackedWidget_admin->setCurrentIndex(DB_INTERFACE);

        // Initialize basic view for customers list
        CustomerTableModel *model = new CustomerTableModel(this, database);
        model->InitializeCompleteTable();
        ui->tableView_view_database->setModel(model);

        // Initialize table view
        InitializeTableView(ui->tableView_view_database);
    }
    else // If invalid admin credentials
    {
        qDebug() << username;
        qDebug() << password;
        ui->label_login_status->setText("Username and password incorrect.");
    }
}

// Initialize Tableview
void Admin::InitializeTableView(QTableView *tableView)
{
    // Hide 'customerID' column
    tableView->setColumnHidden(CustomerTableModel::ID, true);
    // Hide numerical vertical header
    tableView->verticalHeader()->setVisible(false);
    // Make fields uneditable
    tableView->setEditTriggers(QTableView::NoEditTriggers);
}

// Check for empty fields
bool Admin::IsAnyEmptyField()
{
    return  ui->inputField_name->text().isEmpty()           ||
            ui->inputField_address->text().isEmpty()        ||
            ui->inputField_website->text().isEmpty()        ||
            ui->inputField_interest_level->text().isEmpty() ||
            ui->inputField_do_not_contact->text().isEmpty() ||
            ui->inputField_key_customer->text().isEmpty()   ||
            ui->inputField_pamphlet_sent->text().isEmpty();
}

// View Customer Listing Button
void Admin::on_button_view_customer_clicked()
{
    // Initialize basic view for customers list
    CustomerTableModel *model = new CustomerTableModel(this, database);
    model->InitializeCompleteTable();
    ui->tableView_view_database->setModel(model);

    // Initialize table view
    InitializeTableView(ui->tableView_view_database);
}


// View Key Customers
void Admin::on_button_view_key_customer_clicked()
{
    // Initialize basic view for customers list
    CustomerTableModel *model = new CustomerTableModel(this, database);
    model->InitializeKeyTable();
    ui->tableView_view_database->setModel(model);

    // Initialize table view
    InitializeTableView(ui->tableView_view_database);
}


// View Purchases
void Admin::on_button_view_purchases_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT customers.name, items.name, items.price, "
                    "purchases.qtyPurchased "
                    "FROM customers, items, purchases "
                    "WHERE customers.customerID = purchases.customerID "
                    "AND items.itemID = purchases.itemID;", QSqlDatabase());

    model->setHeaderData(0, Qt::Horizontal, tr("Name"));
    model->setHeaderData(1, Qt::Horizontal, tr("Item"));
    model->setHeaderData(2, Qt::Horizontal, tr("Price"));
    model->setHeaderData(3, Qt::Horizontal, tr("Quantity"));

    ui->tableView_view_database->setModel(model);
    ui->tableView_view_database->setColumnHidden(0, false);
}


// Go to 'Edit Customer Database' Page
void Admin::on_button_edit_customer_db_clicked()
{
    CustomerTableModel *model = new CustomerTableModel(this, database);

    // Move to modify customers screen
    ui->stackedWidget_admin->setCurrentIndex(MODIFY_CUSTOMERS);

    // Initialize basic view for customers list
    model->InitializeCompleteTable();
    ui->tableView_edit_database->setModel(model);

    // Initialize table view
    InitializeTableView(ui->tableView_edit_database);
}

// Double Click on any Cell (Activate)
void Admin::on_tableView_edit_database_activated(const QModelIndex &index)
{
    // Customer Listing Attributes
    QString name;
    QString address;
    QString website;
    QString interestLevel;
    QString doNotContact;
    QString keyAccount;
    QString pamphletSent;

    // Assign Customer Listing Attributes to Intermediate Variables
    name = ui->tableView_edit_database->model()->index(index.row(),1).data().toString();
    address = ui->tableView_edit_database->model()->index(index.row(),2).data().toString();
    website = ui->tableView_edit_database->model()->index(index.row(),3).data().toString();
    interestLevel = ui->tableView_edit_database->model()->index(index.row(),4).data().toString();
    doNotContact = ui->tableView_edit_database->model()->index(index.row(),5).data().toString();
    keyAccount = ui->tableView_edit_database->model()->index(index.row(),6).data().toString();
    pamphletSent = ui->tableView_edit_database->model()->index(index.row(),7).data().toString();

    // Reassign boolean values to "Yes" or "No"
    // Assign contact
    doNotContact = (doNotContact == "1") ? "Y" : "N";
    // Assign key account
    keyAccount = (keyAccount.toUpper() == "1") ? "Y" : "N";
    // Assign pamphlet sent status
    pamphletSent = (pamphletSent.toUpper() == "1") ? "Y" : "N";

    // Assign Customer Listing Attribute Variables to Input Fields
    ui->inputField_name->setText(name);
    ui->inputField_address->setText(address);
    ui->inputField_website->setText(website);
    ui->inputField_interest_level->setText(interestLevel);
    ui->inputField_do_not_contact->setText(doNotContact);
    ui->inputField_key_customer->setText(keyAccount);
    ui->inputField_pamphlet_sent->setText(pamphletSent);
}


// Add Customer Button
void Admin::on_button_add_customer_clicked()
{
    // Declaration
    CustomerTableModel *model = new CustomerTableModel(this, database);
    bool querySuccess;
    QSqlQuery query(*database);
    QString name = "";
    QString address = "";
    QString website = "";
    QString interestLevel = "";
    QString doNotContact = "";
    QString keyAccount = "";
    QString pamphletSent = "";

    // Execute if no NULL values exist in fields
    if(!IsAnyEmptyField())
    {
        // If no NULL values, assign to intermediate variables
        name = ui->inputField_name->text();
        address = ui->inputField_address->text();
        website = ui->inputField_website->text();
        interestLevel = ui->inputField_interest_level->text();
        doNotContact = ui->inputField_do_not_contact->text();
        keyAccount = ui->inputField_key_customer->text();
        pamphletSent = ui->inputField_pamphlet_sent->text();

        // Reassign boolean values to 1 or 0
        // Assign contact
        doNotContact = (doNotContact.toUpper() == "Y") ? "1" : "0";
        // Assign key account
        keyAccount = (keyAccount.toUpper() == "Y") ? "1" : "0";
        // Assign pamphlet sent status
        pamphletSent = (pamphletSent.toUpper() == "Y") ? "1" : "0";

        // Execute 'Add Customer' Query
        querySuccess = database->AddCustomer(name, address, website,
                                             interestLevel, doNotContact,
                                             keyAccount, pamphletSent);

        // Execute query. If it works, update the tableview to display new entry
        if(querySuccess)
        {
            // Initialize basic view for customers list
            model->InitializeCompleteTable();
            ui->tableView_edit_database->setModel(model);

            // Initialize table view
            InitializeTableView(ui->tableView_edit_database);

        }
        else // If it doesn't work, prompt the user with instruction
        {
            QMessageBox::warning(this, "ERROR", "Customer already exists! "
                                                "Please enter unique customer data.");
        }
    }
    else // If any NULL values, prompt user with instruction
    {
        QMessageBox::warning(this, "ERROR",
                             "Please enter ALL customer attributes");
    }
}

// Edit Customer
void Admin::on_button_update_customer_clicked()
{
    // Declaration
    int index = 0;
    bool querySuccess = false;
    CustomerTableModel *model = new CustomerTableModel(this, database);
    QSqlQuery query(*database);
    QString customerID = "";
    QString name = "";
    QString address = "";
    QString website = "";
    QString interestLevel = "";
    QString doNotContact = "";
    QString keyAccount = "";
    QString pamphletSent = "";

    // Execute if no NULL values
    if(!IsAnyEmptyField())
    {
        // Access Index
        index = ui->tableView_edit_database->currentIndex().row();

        // Pull data from cell
        customerID = ui->tableView_edit_database->model()->index(index, 0).data().toString();
        name = ui->inputField_name->text();
        address = ui->inputField_address->text();
        website = ui->inputField_website->text();
        interestLevel = ui->inputField_interest_level->text();
        doNotContact = ui->inputField_do_not_contact->text();
        keyAccount = ui->inputField_key_customer->text();
        pamphletSent = ui->inputField_pamphlet_sent->text();

        // Reassign boolean values to 1 or 0
        // Assign contact
        doNotContact = (doNotContact.toUpper() == "Y") ? "1" : "0";
        // Assign key account
        keyAccount = (keyAccount.toUpper() == "Y") ? "1" : "0";
        // Assign pamphlet sent status
        pamphletSent = (pamphletSent.toUpper() == "Y") ? "1" : "0";

        querySuccess = database->UpdateCustomer(customerID, name, address,
                                                website, interestLevel,
                                                doNotContact, keyAccount,
                                                pamphletSent);

        // Execute query. If it works, update the tableview to display new entry
        if(querySuccess)
        {
            // Initialize basic view for customers list
            model->InitializeCompleteTable();
            ui->tableView_edit_database->setModel(model);

            // Initialize table view
            InitializeTableView(ui->tableView_edit_database);
        }
        else
        {
            qDebug() << query.lastError().text();
        }
    }
    else // If any NULL values, prompt user with instruction
    {
        QMessageBox::warning(this, "ERROR", "Please enter ALL customer attributes");
    }
}

// Delete Customer
void Admin::on_button_delete_customer_clicked()
{
    // Declaration
    bool querySuccess = false;
    int rowIndex = 0;
    QSqlQuery query(*database);
    QString customerID = "";
    CustomerTableModel *model = new CustomerTableModel(this, database);

    // Access Index
    rowIndex = ui->tableView_edit_database->currentIndex().row();

    // Assign customerID
    customerID = ui->tableView_edit_database->model()->index(rowIndex, 0).data().toString();

    querySuccess = database->DeleteCustomer(customerID);

    // Execute query. If it works, update the tableview to display new entry
    if(querySuccess)
    {
        // Refresh tableview with updated model
        model->InitializeCompleteTable();
        ui->tableView_edit_database->setModel(model);
    }
    else
    {
        qDebug() << query.lastError().text();
    }
}

// Go back to basic view
void Admin::on_button_back_clicked()
{
    ui->stackedWidget_admin->setCurrentIndex(DB_INTERFACE);

    CustomerTableModel *model = new CustomerTableModel(this, database);
    // Initialize basic view for customers list
    model->InitializeCompleteTable();
    ui->tableView_view_database->setModel(model);

    // Initialize table view
    InitializeTableView(ui->tableView_view_database);
}
