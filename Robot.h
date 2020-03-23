/******************************************************************************
 * PROGRAMMERS: - Jonathan Aguirre
 *              - Tina     Faraji
 *              - Suhyr    Hasan
 *              - Weston   Mathews
 * CLASS      : CS1C
 * SECTION    : MW 5:00p - 7:30p
 * DUE DATE   : 02/23/20
 *****************************************************************************/
#ifndef ROBOT_H
#define ROBOT_H

#include <QDialog>
#include <QPixmap>
#include <QWidget>
#include <QString>
#include <QDebug>
// CONSTANTS FOR ROBOT NAMES AND PRICES
const QString FIRST_ROBOT_NAME   = "iRobot 510 Packbot";
const float   FIRST_ROBOT_PRICE  = 900.00;
const QString SECOND_ROBOT_NAME  = "Talon";
const float   SECOND_ROBOT_PRICE = 600.00;
const QString THIRD_ROBOT_NAME   = "Dragon Runner";
const float   THIRD_ROBOT_PRICE  = 300.00;

// CONSTANTS FOR WARRANTY PLAN NAMES AND PRICES
const QString FIRST_PLAN_NAME   = "Basic Plan";
const float   First_PLAN_PRICE  = 0.00;
const QString SECOND_PLAN_NAME  = "Extended Plan";
const float   SECOND_PLAN_PRICE = 150.00;
const QString THIRD_PLAN_NAME   = "Exclusive Plan ";
const float   THIRD_PLAN_PRICE  = 250.00;

// CONSTANT FOR SHIPPING & HANDLING CHARGES used for calculating total price
const float   SHIPPING = 50.00;

// CONSTANT FOR SALES TAX RATE used for calculating total price
const float   TAX_RATE = 0.0775;

/****************************************************************************
 * Robot Class
 *      This class is use to create the Robot page. This window
 *      displays the three iRobot bomb available.
 *
 *      PRE-CONDITONS
 *      The following constant variables must be declared and initialized
 *      in this header file.
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
 *          THIRD_PLAN_NAME    : price of the third  warranty plan
 ***************************************************************************/

namespace Ui {
class Robot;
}

class Robot : public QDialog
{
    Q_OBJECT

public:
    //!< Constructor
    explicit Robot(QWidget *parent = nullptr);
    //!< Destructor
    ~Robot();
    float getFirstRobotPrice() const;
    //!< Gets the price for the first robot
    /*!< POST: return firstRobotPrice; */

    float getFirstPlanPrice() const;
    //!< Gets the price for the first plan
    /*!< POST: return firstPlanPrice; */

    float getSecondRobotPrice() const;
    //!< Gets the price for the second robot
    /*!< POST: return secondRobotPrice; */

    float getSecondPlanPrice() const;
    //!< Gets the price for the second plan
    /*!< POST: return secondPlanPrice; */

    float getThirdRobotPrice() const;
    //!< Gets the price for the third robot
    /*!< POST: return thirdRobotPrice; */

    float getThirdPlanPrice() const;
    //!< Gets the price for the third Plan
    /*!< POST: return thirdPlanPrice; */
private slots:
    void on_pushButtonBackMain_clicked();
    //!< Closes current window and opens MainWindow when button is clicked

    void on_pushButton_NextShoppingCart_clicked();
    //!< Closes current window and opens Shopping Cart Window when button is clicked

private:
    Ui::Robot *ui;
};

#endif // ROBOT_H
