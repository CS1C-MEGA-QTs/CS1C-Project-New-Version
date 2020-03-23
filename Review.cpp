/******************************************************************************
 * PROGRAMMERS: - Jonathan Aguirre
 *              - Tina     Faraji
 *              - Suhyr    Hasan
 *              - Weston   Mathews
 * CLASS      : CS1C
 * SECTION    : MW 5:00p - 7:30p
 * DUE DATE   : 02/23/20
 *****************************************************************************/
#include "Review.h"
#include "mainwindow.h"
#include "ui_Review.h"

Review::Review(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Review)
{
    ui->setupUi(this);

    ui->CompanyNameComboBox->addItem(" ");
    ui->CompanyNameComboBox->addItem("FBI");
    ui->CompanyNameComboBox->addItem("CIA");
    ui->CompanyNameComboBox->addItem("Cisco");
    ui->CompanyNameComboBox->addItem("Amazon");
    ui->CompanyNameComboBox->addItem("Los Angeles Airport");
    ui->CompanyNameComboBox->addItem("Los Angeles Dodgers");
    ui->CompanyNameComboBox->addItem("Orange County Airport");
    ui->CompanyNameComboBox->addItem("Los Angeles Angels of Anaheim");


}

Review::~Review()
{
    delete ui;
}

/******************************************************************
* on_pushButton_SendReview_clicked()
* -----------------------------------------------------------------
* This will allow the user to select the name of their organization
* as well as typing in a review. Once the button is clicked, the
* information they had entered will be saved and sent to the
* database where it will reload upon re-execution of the program.
* Once they send their review, they will be taken back to the
* homepage.
******************************************************************/
void Review::on_pushButton_SendReview_clicked()
{
    database = new Database("MegaQTDB.db", "QSQLITE");

    QSqlQuery query(*database);

    enum Name
    {
        OC_AIRPORT, //0
        LA_AIRPORT,//1
        FBI,//2
        CIA,//3
        LA_DODGERS,//4
        LA_ANGELS,//5
        AMAZON,//6
        CISCO,//7
    };

    Name customerID;

    QString name       = ui -> CompanyNameComboBox -> currentText();
    QString reviewText = ui -> NewReviewTextEdit   -> toPlainText();



    /******************************************************************
    * PROCESSING - For each name, cast it into the correct enumertor.
    ******************************************************************/
    switch(name.toStdString()[0])
    {
        case 'A': customerID = AMAZON;
                     break;
        case 'C': if(name.at(1) == 'I')
                  {
                    customerID = CIA;
                  }
                  else
                  {
                    customerID = CISCO;
                  }
                  break;
        case 'F': if(name.at(1) == 'B')
                  {
                    customerID = FBI;
                  }
                  break;
        case 'L': if(name.at(12) == 'D')
                  {
                    customerID = LA_DODGERS;
                  }
                  else if(name.at(13) == 'i')
                  {
                    customerID = LA_AIRPORT;
                  }
                  else
                  {
                    customerID = LA_ANGELS;
                  }
                  break;
        case 'O': customerID = OC_AIRPORT;
                  break;
    }


    qDebug() << "Name is: "   << name << endl;
    qDebug() << "Enum is: "   << customerID << endl;
    qDebug() << "Review is: " << reviewText << endl;

    query.prepare("INSERT INTO reviews VALUES (:customerID, :reviewText)");

    query.bindValue(":customerID", customerID);
    query.bindValue(":reviewText", reviewText);

    qDebug() << "Name is: "   << name << endl;
    qDebug() << "Enum is: "   << customerID << endl;
    qDebug() << "Review is: " << reviewText << endl;

    if(query.exec())
    {
        //leave the page so they cant keep submitting the same review over and over
    }
    else
    {
        //output the error code like "whoopsie!"
        qDebug() << query.lastError().text();
    }



}

/************************************************************
* on_pushButton_FAdminTMain_clicked()
* ----------------------------------------------------------
* This will allow the user to go back to the main window.
************************************************************/
void Review::on_pushButton_FAdminTMain_clicked()
{
    // Hide the HelpWindow itself
    hide();
}


void Review::AddNamesAndReviewsToListWidget()
{
    QString namesAr[100];
    QString reviewsAr[100];
    int     index;
    int     count = 0;

    /*******************
     * INITIALIZATIONS *
     *******************/
    database = new Database("MegaQTDB.db", "QSQLITE");
    index    = 0;

    // Hides the Main Window
    //  hide();
    // Shows the Review Window
    count = database -> ReturnNames  (namesAr);
    qDebug() << "Count is: " << count << endl;

    database -> ReturnReviews(reviewsAr);

    qDebug() << "Inside first forrrrr loop\n";
    for(index = 0; index < count; index++)
    {//begin for

        qDebug() << "Name is: " << namesAr[index] << endl;
        qDebug() << "Review is: " << reviewsAr[index] << endl;

        index++;

    }//end for

    /************************************************************
    * OUTPUT - All names and reviews to the old revews section
    *          of the reviews page to the list widget
    ************************************************************/
    qDebug() << "Inside second while loop\n";

    index = 0;

    while(index < count)
    {//begin while
        qDebug() << "Actually Inside second while loop\n";

//        ui -> OldReviewTextBrowser -> insertPlainText(namesAr[index]);
//        ui -> OldReviewTextBrowser -> insertPlainText(reviewsAr[index]);

        ui -> OldReviewsLabel -> setText("words ");

        qDebug() << "Name is: " << namesAr[index] << endl;
        qDebug() << "Review is: " << reviewsAr[index] << endl;

        index++;

    }//end while
};
