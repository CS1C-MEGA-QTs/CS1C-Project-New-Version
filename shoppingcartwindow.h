/******************************************************************************
 * PROGRAMMERS: - Jonathan Aguirre
 *              - Tina     Faraji
 *              - Suhyr    Hasan
 *              - Weston   Mathews
 * CLASS      : CS1C
 * SECTION    : MW 5:00p - 7:30p
 * DUE DATE   : 02/23/20
 *****************************************************************************/
#ifndef SHOPPINGCARTWINDOW_H
#define SHOPPINGCARTWINDOW_H

#include <QDialog>
#include "checkout.h"
namespace Ui {
class ShoppingCartWindow;
}

class ShoppingCartWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ShoppingCartWindow(QWidget *parent = nullptr);
    ~ShoppingCartWindow();

private slots:
    void on_pushButton_BeforeRobotPage_clicked();

    void on_pushButton_NextCheckoutPage_clicked();

private:
    Ui::ShoppingCartWindow *ui;
    checkout *Checkout;
};

#endif // SHOPPINGCARTWINDOW_H
