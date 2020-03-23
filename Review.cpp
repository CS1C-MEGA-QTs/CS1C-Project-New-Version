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

    database = new Database("MegaQTDB.db", "QSQLITE");

}

Review::~Review()
{
    delete ui;
}


void Review::on_pushButton_SendReview_clicked()
{
    ///
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
