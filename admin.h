/******************************************************************************
 * PROGRAMMERS: - Jonathan Aguirre
 *              - Tina     Faraji
 *              - Suhyr    Hasan
 *              - Weston   Mathews
 * CLASS      : CS1C
 * SECTION    : MW 5:00p - 7:30p
 * DUE DATE   : 02/23/20
 *****************************************************************************/
#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QMessageBox>
#include "Database.h"
#include "CustomerTableModel.h"
#include <QTableView>

namespace Ui
{
    class Admin;
}


class Admin : public QDialog
{
    Q_OBJECT

public:

    // Enum to keep track of admin page stacked widget
    enum AdminPages
    {
        LOGIN,
        DB_INTERFACE,
        MODIFY_CUSTOMERS
    };

    // Function Declarations
    void InitializeTableView(QTableView *tableView);
    bool IsAnyEmptyField();

    // Constructor
    explicit Admin(QWidget *parent = nullptr);

    // Destructor
    ~Admin();
private slots:

    // Back to main program button
    void on_pushButton_FAdminTMain_clicked();


    // Login Button
    void on_button_login_clicked();


    // View Customer List Button
    void on_button_view_customer_clicked();

    void on_button_view_key_customer_clicked();

    void on_button_view_purchases_clicked();

    void on_button_edit_customer_db_clicked();

    void on_button_add_customer_clicked();

    void on_tableView_edit_database_activated(const QModelIndex &index);

    void on_button_update_customer_clicked();

    void on_button_delete_customer_clicked();

    void on_button_back_clicked();

private:
    Ui::Admin *ui;
    Database *database;
};

#endif // ADMIN_H
