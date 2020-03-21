/******************************************************************************
 * PROGRAMMERS: - Jonathan Aguirre
 *              - Tina     Faraji
 *              - Suhyr    Hasan
 *              - Weston   Mathews
 * CLASS      : CS1C
 * SECTION    : MW 5:00p - 7:30p
 * DUE DATE   : 02/23/20
 *****************************************************************************/
#include "Robot.h"
#include "mainwindow.h"
#include "ui_Robot.h"
#include "ShoppingCart.h"
/****************************************************************************
 * METHOD - Robot
 * --------------------------------------------------------------------------
 * This method is the CONSTRUCTOR used to display and set default values for
 * the Robot object.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following constant variables must be declared and initialized
 *      in the productWindow.h.
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
 *
 * POST-CONDITIONS
 *      ==> Returns nothing
 *      ==> Create an instance of the class object with default values.
 ***************************************************************************/
Robot::Robot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Robot)
{
    ui->setupUi(this);

/************************************************************
* PROCESSING - (For first robot picture)
*              Assign images to QPixmap variables and
*              adjust the scaling for the image posted.
************************************************************/
    QPixmap FirstRobotPix(":/new/prefix1/1l-iRobot-510-PackBot.jpg");

    int FirstRobotW = ui -> label_1stRobotPic->width ();
    int FirstRobotH = ui -> label_1stRobotPic->height();

    ui -> label_1stRobotPic -> setPixmap(FirstRobotPix.scaled
                                         (FirstRobotW, FirstRobotH,
                                          Qt::KeepAspectRatio));
/************************************************************
* PROCESSING - (For second robot picture)
*              Assign images to QPixmap variables and
*              adjust the scaling for the image posted.
************************************************************/
    QPixmap SecondRobotPix(":/new/prefix1/3l-Image-Talon.jpg");

    int SecondRobotW = ui -> label_2ndRobotPic -> width ();
    int SecondRobotH = ui -> label_2ndRobotPic -> height();

    ui -> label_2ndRobotPic -> setPixmap(SecondRobotPix.scaled
                                         (SecondRobotW, SecondRobotH,
                                          Qt::KeepAspectRatio));
    /************************************************************
* PROCESSING - (For third robot picture)
*              Assign images to QPixmap variables and
*              adjust the scaling for the image posted.
************************************************************/
    QPixmap ThirdRobotPix(":/new/prefix1/5l-Image-Dragon Runner.jpg");

    int ThirdRobotW = ui -> label_3rdRobotPic -> width ();
    int ThirdRobotH = ui -> label_3rdRobotPic -> height();

    ui -> label_3rdRobotPic -> setPixmap(ThirdRobotPix.scaled
                                         (ThirdRobotW, ThirdRobotH,
                                          Qt::KeepAspectRatio));
}

Robot::~Robot()
{
    delete ui;
}
/****************************************************************************
 * METHOD - getRobot1Price
 * --------------------------------------------------------------------------
 * This method returns the first robot price.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns the first robot price.
 ***************************************************************************/
float Robot::getFirstRobotPrice() const
{
    return FIRST_ROBOT_PRICE;
}
/****************************************************************************
 * METHOD - getFirstPlanPrice
 * --------------------------------------------------------------------------
 * This method returns the first warranty plan price.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns the first warranty plan price.
 ***************************************************************************/
float Robot::getFirstPlanPrice() const
{
    return First_PLAN_PRICE;
}
/****************************************************************************
 * METHOD - getSecondRobotPrice
 * --------------------------------------------------------------------------
 * This method returns the second robot price.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns the second robot price.
 ***************************************************************************/
float Robot::getSecondRobotPrice() const
{
    return SECOND_ROBOT_PRICE;
}
/****************************************************************************
 * METHOD -  getSecondPlanPrice
 * --------------------------------------------------------------------------
 * This method returns the warranty plan price.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns the second warranty plan price.
 ***************************************************************************/
float Robot::getSecondPlanPrice() const
{
    return SECOND_PLAN_PRICE;
}
/****************************************************************************
 * METHOD - getThirdRobotPrice
 * --------------------------------------------------------------------------
 * This method returns the third robot price.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns the third robot price.
 ***************************************************************************/
float Robot::getThirdRobotPrice() const
{
    return THIRD_ROBOT_PRICE;
}
/****************************************************************************
 * METHOD - getThirdPlanPric
 * --------------------------------------------------------------------------
 * This method returns the third warranty plan price.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns the third warranty plan price.
 ***************************************************************************/
float Robot::getThirdPlanPrice() const
{
    return THIRD_PLAN_PRICE;
}
/************************************************************
* on_pushButtonBackMain_clicked()
* ----------------------------------------------------------
* This will allow the user to go back to the main window.
************************************************************/
void Robot::on_pushButtonBackMain_clicked()
{
    // Hide the HelpWindow itself
    hide();

    // Show the MainWindow (i.e. the parent window)
    MainWindow *newmain= new MainWindow();
    newmain->show();
}
/************************************************************
* on_pushButton_NextShoppingCart_clicked()
* ----------------------------------------------------------
* This will allow the user to go to the shopping cart window.
************************************************************/
void Robot::on_pushButton_NextShoppingCart_clicked()
{
    // Shows the Shopping Cart Window
   ShoppingCart * shoppingCart =  new ShoppingCart(this);
    shoppingCart -> show();
}
