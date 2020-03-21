/******************************************************************************
 * PROGRAMMERS: - Jonathan Aguirre
 *              - Tina     Faraji
 *              - Suhyr    Hasan
 *              - Weston   Mathews
 * CLASS      : CS1C
 * SECTION    : MW 5:00p - 7:30p
 * DUE DATE   : 02/23/20
 *****************************************************************************/
#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <QDialog>
#include <QtDebug>
#include <QString>
#include <QPixmap>
#include <QFileInfo>
#include "Database.h"
/****************************************************************************
 * ShoppingCart Class
 *      A QDialog type class used to create the ShoppingCart window. This
 *      window displays the Guarantee Policy . Also this window allows the
 *      user to input the order and checkout.
 *
 *      PRE-CONDITONS
 *      The following constant variables must be declared and initialized
 *      in the robot.h.
 *          FIRST_ROBOT_NAME   : name  of the first  robot
 *          FIRST_ROBOT_PRICE  : price of the first  robot
 *          SECOND_ROBOT_NAME  : name  of the second robot
 *          SECOND_ROBOT_PRICE : price of the second robot
 *          THIRD_ROBOT_NAME   : name  of the third  robot
 *          THIRD_ROBOT_PRICE  : price of the third  robot
 *          FIRST_PLAN_NAME    : name  of the first  warranty plan
 *          First_PLAN_PRICE   : price of the first  warranty plan
 *          SECOND_PLAN_NAME   : name  of the second warranty plan
 *          SECOND_PLAN_PRICE  : price of the second warranty plan
 *          THIRD_PLAN_NAME    : name  of the third  warranty plan
 *          THIRD_PLAN_PRICE   : price of the third  warranty plan
 *          SHIPPING           : shipping and handling amount
 *          TAX_RATE           : sales tax rate (example: 0.0775)
 ***************************************************************************/
namespace Ui {
class ShoppingCart;
}

class ShoppingCart : public QDialog
{
    Q_OBJECT

public:
    //!< Constructor
    explicit ShoppingCart(QWidget *parent = nullptr);
    //!< Destructor
    ~ShoppingCart();
    //!< Sets and displays the subtotal for the first robot
    /*!< firstRobotSubtotal = FirstRobotQty * (FIRST_ROBOT_PRICE + (plan price)); */
    /*!< Purchase button enabled if any robot qty > 0 */
    void setFirstRobotSubtotal();

    //!< Sets and displays the subtotal for the second robot
    /*!< secondRobotSubtotal = secondRobotQty * (SECOND_ROBOT_PRICE + (plan price)); */
    /*!< Purchase button enabled if any robot qty > 0 */
    void setSecondRobotSubtotal();

    //!< Sets and displays the subtotal for the third Robot
    /*!< thirdRobotSubtotal = ThirdRobotQty * (THIRD_ROBOT_PRICE + (plan price)); */
    /*!< Purchase button enabled if any robot qty > 0 */
    void setThirdRobotSubtotal();

    //!< Sets and displays updated subtotal
    /*!< subtotal = FirstRobotSubtotal + SecondRobotSubtotal + ThirdRobotSubtotal; */
    void setTotalSubtotal();

    //!< Sets the order shipping & handling charge displayed or hidden
    /*!< If subtotal > 0, display shipping & handling flat rate charge */
    /*!< else, hide shipping & handling flat rate charge */
    void setTotalShipping();

    //!< Sets and displays updated sales tax amount
    /*!< salesTax = ((subtotal + SHIPPING)*TAX_RATE); */
    void setTotalSalesTax();

    //!< Sets and displays updated total price for order
    /*!< totalPrice = subtotal + SHIPPING + salesTax; */
    void setTotalOrderPrice();


private slots:
    //!< Closes current window and opens MainWindow when button is clicked
    void on_pushButtonBackMain_clicked();

    //!< Stores the customer's purchase into the database
    void on_pushButton_Checkout_clicked();

    //!< Update the first robot's plan value and subtotal when value changes
    /*!< POST: firstRobotPlan = plan; */
    /*!< POST: setFirstRobotSubtotal(); */
    void on_FirstRobotComboBox_currentIndexChanged(int index);

    //!< Update the first robot's quantity and subtotal when value changes
    /*!< POST: firstRobotQty = quantity; */
    /*!< POST: setFirstRobotSubtotal(); */
    void on_FirstRobotSpinBox_valueChanged(int quantity);

    //!< Update the second robot's plan value and subtotal when value changes
    /*!< POST: secondRobotPlan = plan; */
    /*!< POST: setSecondRobotSubtotal(); */
    void on_SecondRobotComboBox_currentIndexChanged(int plan);

    //!< Update the second robot's quantity and subtotal when value changes
    /*!< POST: secondRobotQty = quantity; */
    /*!< POST: setSecondRobotSubtotal(); */
    void on_SecondRobotSpinBox_valueChanged(int quantity);

    //!< Update the third robot's plan value and subtotal when value changes
    /*!< POST: thirdRobotPlan = plan; */
    /*!< POST: setThirdRobotSubtotal(); */
    void on_ThirdRobotComboBox_currentIndexChanged(int plan);

    //!< Update the third robot's quantity and subtotal when value changes
    /*!< POST: thirdRobotQty = quantity; */
    /*!< POST: setThirdRobotSubtotal(); */
    void on_ThirdRobotSpinBox_valueChanged(int quantity);

    //!< Update billing address box (and shipping address if same)
    /*!< POST: name = ui->CompanyNameComboBox->currentText(); */
    void on_CompanyAddressBox_editingFinished();

    //!< Checks to see if the customer is in the system
    /*!< POST: If true fills in billing address */
    void on_CompanyNameComboBox_currentIndexChanged(const QString &arg1);

    //!< Updates the shipping address labels whether the "Yes" or "No"
    //!< checkBox is clicked.
    void on_yesCheckBox_toggled(bool checked);

    //!< Saves credit card expiration date month in mm format
    /*!< POST: CardMonth from converted ui->CreditCardMonthBox->text(); */
    void on_CreditCardMonthBox_editingFinished();

    //!< Saves credit card expiration date year in yy format
    /*!< POST: CardYear from converted ui->CreditCardYearBox->text(); */
    void on_CreditCardYearBox_editingFinished();

    //!< Saves credit card CVV
    /*!< POST: CardCvv from converted ui->CreditCardCVVNumberBox->text(); */
    void on_CreditCardCVVNumberBox_editingFinished();

private:
    Ui::ShoppingCart *ui;
    Database *database;

    int    FirstRobotQty;      //!< CALC&OUT - quantity of the first robot
    int    FirstRobotPlan;     //!< CALC&OUT - the first robot warranty plan
    float  FirstRobotSubtotal; //!< CALC&OUT - first robot's subtotal

    int    SecondRobotQty;      //!< CALC&OUT - quantity of the second robot
    int    SecondRobotPlan;     //!< CALC&OUT - the second robot warranty plan
    float  SecondRobotSubtotal; //!< CALC&OUT - second robot's subtotal

    int    ThirdRobotQty;      //!< CALC&OUT - quantity of the third robot
    int    ThirdRobotPlan;     //!< CALC&OUT - the third robot's warranty plan
    float  ThirdRobotSubtotal; //!< CALC&OUT - third robot's subtotal

    float  subtotal;           //!< CALC&OUT - subtotal of all robots
    float  shipping;           //!< CALC&OUT - shipping
    float  salesTax;           //!< CALC&OUT - sales tax amount for order
    float  totalPrice;         //!< CALC&OUT - total price for order

    QString shippingAddress;    //!< IN&OUT - the shipping address line one
    int     CardMonth;          //!< IN&OUT - the credit card expire month
    int     CardYear;           //!< IN&OUT - the credit card expire year
    int     CardCvv;            //!< IN&OUT - the credit card CVV number

    QString orderID;            //!< CALC& OUT - order ID

};

#endif // SHOPPINGCART_H
