#include "Pamphlet.h"
#include "ui_Pamphlet.h"
#include "mainwindow.h"

Pamphlet::Pamphlet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pamphlet)
{
    ui->setupUi(this);
    // Initialize database
    database = new Database("MegaQTDB.db", "QSQLITE");
    /************************************************************
       * PROCESSING - Add a list of company names.
       ************************************************************/
    ui->CompanyNameComboBox->addItem("");
    ui->CompanyNameComboBox->addItem("FBI");
    ui->CompanyNameComboBox->addItem("CIA");
    ui->CompanyNameComboBox->addItem("Cisco");
    ui->CompanyNameComboBox->addItem("Amazon");
    ui->CompanyNameComboBox->addItem("Los Angeles Airport");
    ui->CompanyNameComboBox->addItem("Los Angeles Dodgers");
    ui->CompanyNameComboBox->addItem("Orange County Airport");
    ui->CompanyNameComboBox->addItem("Los Angeles Angels of Anaheim");
}

Pamphlet::~Pamphlet()
{
    delete ui;
}

/****************************************************************************
 * METHOD - on_CompanyNameComboBox_currentIndexChanged(const QString &arg1)
 * --------------------------------------------------------------------------
 * This method is the setting the Customer's address accordingly. This
 * specfic feature depends on the Company's name.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      const QString &arg1
 *
 * POST-CONDITIONS
 *      ==> Returns nothing
 ***************************************************************************/
void Pamphlet::on_CompanyNameComboBox_currentIndexChanged(const QString &arg1)
{
    QSqlQuery query(*database);
    QString name = ui->CompanyNameComboBox->currentText();
    QString address ="";
    // Execute 'Add Customer' Query
    address = database->ShippingAddress(name);

    ui->CompanyAddressBox->setText(address);
}
/****************************************************************************
 * METHOD - on_pushButtonSendPamphlet_clicked()
 * --------------------------------------------------------------------------
 * This method is for the implementation of sending the pamphlet. Through
 * a series of if and else statements, the databased is updated accordingly
 * depending on whether or not the customer/company has chosen to receive
 * a pamphlet. Once the customer submits that they would like to receive,
 * a message box is shown that confirms that this action has been done.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing
 ***************************************************************************/
void Pamphlet::on_pushButtonSendPamphlet_clicked()
{
    // Sends Pamphlet
    QSqlQuery query(*database);

    // Intializing variables
    bool querySuccess = false;
    QString pamphletSent = "1";
    QString companyName = ui->CompanyNameComboBox->currentText();

    // Checks to see if fields are empty or not
    if (ui->CompanyNameComboBox->currentText() == "")
    {
        QMessageBox::information(this, "Empty Fields",
                                 "Please choose your company name!",QMessageBox::Ok);
    }
    else
    {
        querySuccess = database->SendPamphlet(companyName,pamphletSent);
        // Confirms tha copy has been sent
        if(querySuccess)
        {
            QMessageBox::information(this, "Thank you","Thanks for submitting.",QMessageBox::Ok);

            // Hide the HelpWindow itself
            hide();
        }
        else
        {
            QMessageBox::warning(this, "ERROR", "Customer has already reviced a Pamphlet!");
        }
    }
}
