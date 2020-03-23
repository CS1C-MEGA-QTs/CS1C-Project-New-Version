/******************************************************************************
 * PROGRAMMERS: - Jonathan Aguirre
 *              - Tina     Faraji
 *              - Suhyr    Hasan
 *              - Weston   Mathews
 * CLASS      : CS1C
 * SECTION    : MW 5:00p - 7:30p
 * DUE DATE   : 02/23/20
 *****************************************************************************/
#include "shoppingcartwindow.h"
#include "ui_shoppingcartwindow.h"
#include "mainwindow.h"

ShoppingCartWindow::ShoppingCartWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShoppingCartWindow)
{
    ui->setupUi(this);
}

ShoppingCartWindow::~ShoppingCartWindow()
{
    delete ui;
}

void ShoppingCartWindow::on_pushButton_BeforeRobotPage_clicked()
{
    // Hide the HelpWindow itself
    hide();

    // Show the MainWindow (i.e. the parent window)
    MainWindow *newmain= new MainWindow();
    newmain->show();
}

void ShoppingCartWindow::on_pushButton_NextCheckoutPage_clicked()
{
    // Hide the Robot Window itself
    hide();
    // Show the Shopping Cart Window
    Checkout = new checkout(this);
    Checkout->show();

}
