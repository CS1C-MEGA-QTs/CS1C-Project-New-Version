/******************************************************************************
 * PROGRAMMERS: - Jonathan Aguirre
 *              - Tina     Faraji
 *              - Suhyr    Hasan
 *              - Weston   Mathews
 * CLASS      : CS1C
 * SECTION    : MW 5:00p - 7:30p
 * DUE DATE   : 02/23/20
 *****************************************************************************/
#include "checkout.h"
#include "mainwindow.h"
#include "ui_checkout.h"

checkout::checkout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::checkout)
{
    ui->setupUi(this);
}

checkout::~checkout()
{
    delete ui;
}

void checkout::on_pushButtonBackMain_clicked()
{
    // Hide the HelpWindow itself
    hide();

    // Show the MainWindow (i.e. the parent window)
    MainWindow *newmain= new MainWindow();
    newmain->show();

}
