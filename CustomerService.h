/******************************************************************************
 * PROGRAMMERS: - Jonathan Aguirre
 *              - Tina     Faraji
 *              - Suhyr    Hasan
 *              - Weston   Mathews
 * CLASS      : CS1C
 * SECTION    : MW 5:00p - 7:30p
 * DUE DATE   : 02/23/20
 *****************************************************************************/
#ifndef CUSTOMERSERVICE_H
#define CUSTOMERSERVICE_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class CustomerService;
}

class CustomerService : public QDialog
{
    Q_OBJECT

public:
    explicit CustomerService(QWidget *parent = nullptr);
    ~CustomerService();

private slots:
    void on_pushButtonBackMain_clicked();

    void on_pushButtonSend_clicked();

private:
    Ui::CustomerService *ui;
};

#endif // CUSTOMERSERVICE_H
