/******************************************************************************
 * PROGRAMMERS: - Jonathan Aguirre
 *              - Tina     Faraji
 *              - Suhyr    Hasan
 *              - Weston   Mathews
 * CLASS      : CS1C
 * SECTION    : MW 5:00p - 7:30p
 * DUE DATE   : 02/23/20
 *****************************************************************************/
#ifndef CHECKOUT_H
#define CHECKOUT_H

#include <QDialog>

namespace Ui {
class checkout;
}

class checkout : public QDialog
{
    Q_OBJECT

public:
    explicit checkout(QWidget *parent = nullptr);
    ~checkout();

private slots:
    void on_pushButtonBackMain_clicked();

private:
    Ui::checkout *ui;
};

#endif // CHECKOUT_H
