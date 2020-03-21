/******************************************************************************
 * PROGRAMMERS: - Jonathan Aguirre
 *              - Tina     Faraji
 *              - Suhyr    Hasan
 *              - Weston   Mathews
 * CLASS      : CS1C
 * SECTION    : MW 5:00p - 7:30p
 * DUE DATE   : 02/23/20
 *****************************************************************************/
#include "CustomerService.h"
#include "mainwindow.h"
#include "ui_CustomerService.h"

CustomerService::CustomerService(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerService)
{
    ui->setupUi(this);
}

CustomerService::~CustomerService()
{
    delete ui;
}
/************************************************************
* on_pushButtonBackMain_clicked()
* ----------------------------------------------------------
* This will allow the user to go back to the main window.
************************************************************/
void CustomerService::on_pushButtonBackMain_clicked()
{
    // Hide the HelpWindow itself
    hide();

    // Show the MainWindow (i.e. the parent window)
    MainWindow *newmain= new MainWindow();
    newmain->show();
}
/************************************************************
* on_pushButtonSend_clicked()
* ----------------------------------------------------------
* Erases data entered into the customer service page.
************************************************************/
void CustomerService::on_pushButtonSend_clicked()
{
    this -> ui -> labelFirstName   -> setText("");
    this -> ui -> labelLastName    -> setText("");
    this -> ui -> labelCompanyName -> setText("");
    this -> ui -> Messagebox       -> setText("");
    QMessageBox::information(this, "Message Sent Confirmation",
                             "Thank you for contacting us",QMessageBox::Ok);
    // Hide the HelpWindow itself
    hide();

    // Show the MainWindow (i.e. the parent window)
    MainWindow *newmain= new MainWindow();
    newmain->show();
}
