/******************************************************************************
 * PROGRAMMERS: - Jonathan Aguirre
 *              - Tina     Faraji
 *              - Suhyr    Hasan
 *              - Weston   Mathews
 * CLASS      : CS1C
 * SECTION    : MW 5:00p - 7:30p
 * DUE DATE   : 02/23/20
 *****************************************************************************/
#include "ShoppingCart.h"
#include "mainwindow.h"
#include "Customer.h"
#include "ui_ShoppingCart.h"
/****************************************************************************
 * METHOD - ShoppingCart(QWidget *parent) :  QDialog(parent)
 * --------------------------------------------------------------------------
 * This method is the CONSTRUCTOR used to display and set default values for
 * the ShoppingCart window dialog object.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
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
 *          THIRD_PLAN_NAME    : price of the third  warranty plan
 *          SHIPPING           : shipping and handling amount
 *          TAX_RATE           : sales tax rate (example: 7.75)
 * POST-CONDITIONS
 *      ==> Returns nothing
 *      ==> Create an instance of the class object with default values.
 ***************************************************************************/
ShoppingCart::ShoppingCart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShoppingCart)
{
    ui->setupUi(this);
    // Initialize database
    database = new Database("MegaQTDB.db", "QSQLITE");
    /************************************************************
   * PROCESSING - Add a list of relevant state and country
   *              buyers when adding an item to cart.
   ************************************************************/
    ui->CountryComboBox->addItem(" ");
    ui->CountryComboBox->addItem("United States");
    ui->CountryComboBox->addItem("United Kingdom");
    ui->CountryComboBox->addItem("Canada");
    ui->CountryComboBox->addItem("France");

    ui->StateComboBox->addItem(" ");
    ui->StateComboBox->addItem("AK");
    ui->StateComboBox->addItem("AL");
    ui->StateComboBox->addItem("AR");
    ui->StateComboBox->addItem("AZ");
    ui->StateComboBox->addItem("CA");
    ui->StateComboBox->addItem("CO");
    ui->StateComboBox->addItem("CT");
    ui->StateComboBox->addItem("DE");
    ui->StateComboBox->addItem("FL");
    ui->StateComboBox->addItem("GA");
    ui->StateComboBox->addItem("HI");
    ui->StateComboBox->addItem("IA");
    ui->StateComboBox->addItem("ID");
    ui->StateComboBox->addItem("IL");
    ui->StateComboBox->addItem("IN");
    ui->StateComboBox->addItem("KS");
    ui->StateComboBox->addItem("KY");
    ui->StateComboBox->addItem("LA");
    ui->StateComboBox->addItem("MA");
    ui->StateComboBox->addItem("MD");
    ui->StateComboBox->addItem("ME");
    ui->StateComboBox->addItem("MI");
    ui->StateComboBox->addItem("MN");
    ui->StateComboBox->addItem("MO");
    ui->StateComboBox->addItem("MS");
    ui->StateComboBox->addItem("MT");
    ui->StateComboBox->addItem("NC");
    ui->StateComboBox->addItem("ND");
    ui->StateComboBox->addItem("NE");
    ui->StateComboBox->addItem("NH");
    ui->StateComboBox->addItem("NJ");
    ui->StateComboBox->addItem("NM");
    ui->StateComboBox->addItem("NV");
    ui->StateComboBox->addItem("NY");
    ui->StateComboBox->addItem("OH");
    ui->StateComboBox->addItem("OK");
    ui->StateComboBox->addItem("OR");
    ui->StateComboBox->addItem("PA");
    ui->StateComboBox->addItem("RI");
    ui->StateComboBox->addItem("SC");
    ui->StateComboBox->addItem("SD");
    ui->StateComboBox->addItem("TN");
    ui->StateComboBox->addItem("TX");
    ui->StateComboBox->addItem("UT");
    ui->StateComboBox->addItem("VA");
    ui->StateComboBox->addItem("VT");
    ui->StateComboBox->addItem("WA");
    ui->StateComboBox->addItem("WI");
    ui->StateComboBox->addItem("WV");
    ui->StateComboBox->addItem("WY");

    ui->CompanyNameComboBox->addItem(" ");
    ui->CompanyNameComboBox->addItem("FBI");
    ui->CompanyNameComboBox->addItem("CIA");
    ui->CompanyNameComboBox->addItem("Cisco");
    ui->CompanyNameComboBox->addItem("Amazon");
    ui->CompanyNameComboBox->addItem("Los Angeles Airport");
    ui->CompanyNameComboBox->addItem("Los Angeles Dodgers");
    ui->CompanyNameComboBox->addItem("Orange County Airport");
    ui->CompanyNameComboBox->addItem("Los Angeles Angels of Anaheim");
    /************************************************************
     * SET THE FIRST ROBOT VARIABLES & DISPLAY
     ************************************************************/
    // Set the first robot default values for variables
    FirstRobotQty = 0;
    FirstRobotPlan = 0;
    FirstRobotSubtotal = 0.0;

    // Set the first robot's name
    ui->label_FirstRobotName->setText(FIRST_ROBOT_NAME);

    // Assign images to QPixmap variables and  adjust the scaling for the image posted.
    QPixmap FirstRobotPix(":/new/prefix1/1l-iRobot-510-PackBot.jpg");
    int Robot1W = ui -> label_FirstRobotPic->width ();
    int Robot1H = ui -> label_FirstRobotPic->height();
    ui -> label_FirstRobotPic -> setPixmap(FirstRobotPix.scaled
                                           (Robot1W, Robot1H,
                                            Qt::KeepAspectRatio));

    // Set warranty display comboBox
    ui->FirstRobotComboBox->addItem(FIRST_PLAN_NAME + " ($" +
                                    QString::number(First_PLAN_PRICE, 'f', 2) + ")");
    ui->FirstRobotComboBox->addItem(SECOND_PLAN_NAME + " ($" +
                                    QString::number(SECOND_PLAN_PRICE, 'f', 2) + ")");
    ui->FirstRobotComboBox->addItem(THIRD_PLAN_NAME + " ($" +
                                    QString::number(THIRD_PLAN_PRICE, 'f', 2) + ")");

    ui->FirstRobotSubtotalBox->setText("0.00");

    /************************************************************
     * SET THE SECOND ROBOT VARIABLES & DISPLAY
     ************************************************************/
    // Set the second robot default values for variables
    SecondRobotQty = 0;
    SecondRobotPlan = 0;
    SecondRobotSubtotal = 0.0;

    // Set the second robot's name
    ui->label_SecondRobotName->setText(SECOND_ROBOT_NAME);

    // Assign images to QPixmap variables and  adjust the scaling for the image posted.
    QPixmap SecondRobotPix(":/new/prefix1/3l-Image-Talon.jpg");
    int Robot2W = ui -> label_SecondRobotPic -> width ();
    int Robot2H = ui -> label_SecondRobotPic -> height();

    ui -> label_SecondRobotPic -> setPixmap(SecondRobotPix.scaled
                                            (Robot2W, Robot2H,
                                             Qt::KeepAspectRatio));

    // Set warranty display comboBox
    ui->SecondRobotComboBox->addItem(FIRST_PLAN_NAME + " ($" +
                                     QString::number(First_PLAN_PRICE, 'f', 2) + ")");
    ui->SecondRobotComboBox->addItem(SECOND_PLAN_NAME + " ($" +
                                     QString::number(SECOND_PLAN_PRICE, 'f', 2) + ")");
    ui->SecondRobotComboBox->addItem(THIRD_PLAN_NAME + " ($" +
                                     QString::number(THIRD_PLAN_PRICE, 'f', 2) + ")");

    ui->SecondRobotSubtotalBox->setText("0.00");

    /************************************************************
     * SET THE THIRD ROBOT VARIABLES & DISPLAY
     ************************************************************/
    // Set the third robot default values for variables
    ThirdRobotQty = 0;
    ThirdRobotPlan = 0;
    ThirdRobotSubtotal = 0.0;

    // Set the third robot's name
    ui->label_ThirdRobotName->setText(THIRD_ROBOT_NAME);

    // Assign images to QPixmap variables and  adjust the scaling for the image posted.
    QPixmap ThirdRobotPix(":/new/prefix1/5l-Image-Dragon Runner.jpg");
    int Robot3W = ui -> label_ThirdRobotPic -> width ();
    int Robot3H = ui -> label_ThirdRobotPic -> height();

    ui -> label_ThirdRobotPic -> setPixmap(ThirdRobotPix.scaled
                                           (Robot3W, Robot3H,
                                            Qt::KeepAspectRatio));


    // Set warranty display comboBox
    ui->ThirdRobotComboBox->addItem(FIRST_PLAN_NAME + " ($" +
                                    QString::number(First_PLAN_PRICE, 'f', 2) + ")");
    ui->ThirdRobotComboBox->addItem(SECOND_PLAN_NAME + " ($" +
                                    QString::number(SECOND_PLAN_PRICE, 'f', 2) + ")");
    ui->ThirdRobotComboBox->addItem(THIRD_PLAN_NAME + " ($" +
                                    QString::number(THIRD_PLAN_PRICE, 'f', 2) + ")");

    ui->ThirdRobotSubtotalBox->setText("0.00");

    /************************************************************
     * SET TOTAL ORDER CALCULATION SECTION
     ************************************************************/
    ui->SubtotalPriceBox->setText("");
    ui->ShippingPriceBox->setText("");
    ui->TaxTotalPriceBox->setText("");
    ui->OrderTotalPriceBox->setText("");

    /************************************************************
     * SET BILLING AND ADDRESS SECTION
     ************************************************************/
    // Set default shipping address labels to uneditable because
    // yesCheckBox is default enabled
    if(ui->yesCheckBox->checkState() == Qt::Checked)
    {
        ui->AddressStreetBox->setEnabled(false);
        ui->CityBox->setEnabled(false);
        ui->ZipCodeBox->setEnabled(false);
        ui->StateComboBox->setEnabled(false);
        ui->CountryComboBox->setEnabled(false);
    }
    ui->CompanyAddressBox->setText("");
    /************************************************************
     * SET CREDIT CARD SECTION
     ************************************************************/
    ui->CreditCardMonthBox->setText("");
    ui->CreditCardYearBox->setText("");
    /************************************************************
     * SET BUTTON DEFAULT
     ************************************************************/
    ui->pushButton_Checkout->setEnabled(false);
}
/****************************************************************************
 * METHOD - ~ShoppingCart()
 * --------------------------------------------------------------------------
 * This method is the DESTRUCTOR for the shopping cart dialog object.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing
 *      ==> Deletes an instance of the class object.
 ***************************************************************************/
ShoppingCart::~ShoppingCart()
{
    delete ui;
}
/****************************************************************************
 * METHOD - setFirstRobotSubtotal
 * --------------------------------------------------------------------------
 * This method calculates and updates the subtotal for the first robot.
 * It also updates the order subtotal and decides if the "Checkout" button
 * is enabled or disabled.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 *      ==> Updates display for robot A subtotal.
 ***************************************************************************/
void ShoppingCart::setFirstRobotSubtotal()
{
    // updates subtotal if the first robot quantity is > 0
    if(FirstRobotQty > 0)
    {
        // Gets FirstRobotPlan from ComboBox's selected plan
        FirstRobotPlan = ui->FirstRobotComboBox->currentIndex();

        // Calculates FirstRobotSubtotal depending on the selected plan
        switch(FirstRobotPlan)
        {
        case 0 : FirstRobotSubtotal  = FirstRobotQty * (FIRST_ROBOT_PRICE + First_PLAN_PRICE);
            break;
        case 1 : FirstRobotSubtotal  = FirstRobotQty * (FIRST_ROBOT_PRICE + SECOND_PLAN_PRICE);
            break;
        case 2 :  FirstRobotSubtotal = FirstRobotQty * (FIRST_ROBOT_PRICE + THIRD_PLAN_PRICE);
            break;
        }

        // Sets checkout button to enabled(true)
        ui->pushButton_Checkout->setEnabled(true);
    }
    // Updates subtotal if the first robot quantity equals to  0
    else
    {
        FirstRobotSubtotal = 0.00;
    }
    // Disables "Checkout" button if all three robot quantities are equal to 0
    if(FirstRobotQty == 0 &&  SecondRobotQty == 0 && ThirdRobotQty == 0)
    {
        // Sets checkout button to enabled(false)
        ui->pushButton_Checkout->setEnabled(false);
    }

    // Displays updated subtotal on screen
    ui->FirstRobotSubtotalBox->setText(QString::number(FirstRobotSubtotal, 'f', 2));

    // Updates order subtotal
    setTotalSubtotal();
}

/****************************************************************************
 * METHOD - setSecondRobotSubtotal
 * --------------------------------------------------------------------------
 * This method calculates and updates the subtotal for the second robot.
 * It also updates the order subtotal and decides if the "Checkout" button
 * is enabled or disabled.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 *      ==> Updates display for robot B subtotal.
 ***************************************************************************/
void ShoppingCart::setSecondRobotSubtotal()
{
    // Updates subtotal if the second robot quantity is > 0
    if(SecondRobotQty > 0)
    {
        // Gets SecondRobotPlan from combobox's selected plan
        SecondRobotPlan = ui->SecondRobotComboBox->currentIndex();

        // Calculates SecondRobotSubtotal depending on the selected plan
        switch(SecondRobotPlan)
        {
        case 0 : SecondRobotSubtotal = SecondRobotQty * (SECOND_ROBOT_PRICE + First_PLAN_PRICE);
            break;
        case 1 : SecondRobotSubtotal = SecondRobotQty * (SECOND_ROBOT_PRICE + SECOND_PLAN_PRICE);
            break;
        case 2 : SecondRobotSubtotal = SecondRobotQty * (SECOND_ROBOT_PRICE + THIRD_PLAN_PRICE);
            break;
        }

        // Sets checkout button to enabled(true)
        ui->pushButton_Checkout->setEnabled(true);
    }
    // Updates subtotal if the second robot quantity equals to  0
    else
    {
        SecondRobotSubtotal = 0.00;
    }
    // Disables "Checkout" button if all three robot quantities are equal to 0
    if(FirstRobotQty == 0 &&  SecondRobotQty == 0 && ThirdRobotQty == 0)
    {
        // Sets checkout button to enabled(false)
        ui->pushButton_Checkout->setEnabled(false);
    }
    // Displays updated subtotal on screen
    ui->SecondRobotSubtotalBox->setText(QString::number(SecondRobotSubtotal, 'f', 2));

    // Updates order subtotal
    setTotalSubtotal();
}

/****************************************************************************
 * METHOD - setThirdRobotSubtotal()
 * --------------------------------------------------------------------------
 * This method calculates and updates the subtotal for the third robot.
 * It also updates the order subtotal and decides if the "Checkout" button
 * is enabled or disabled.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 *      ==> Updates display for robot C subtotal.
 ***************************************************************************/
void ShoppingCart::setThirdRobotSubtotal()
{
    // Updates subtotal if the third robot quantity is > 0
    if(ThirdRobotQty > 0)
    {
        // Get ThirdRobotPlan from combobox's selected plan
        ThirdRobotPlan = ui->ThirdRobotComboBox->currentIndex();

        // Calculate robotCSubtotal depending on the plan selected
        switch( ThirdRobotPlan)
        {
        case 0 : ThirdRobotSubtotal = ThirdRobotQty * (THIRD_PLAN_PRICE + First_PLAN_PRICE);
            break;
        case 1 : ThirdRobotSubtotal = ThirdRobotQty * (THIRD_PLAN_PRICE + SECOND_PLAN_PRICE);
            break;
        case 2 : ThirdRobotSubtotal = ThirdRobotQty * (THIRD_PLAN_PRICE + THIRD_PLAN_PRICE);
            break;
        }

        // Sets checkout button to enabled(true)
        ui->pushButton_Checkout->setEnabled(true);
    }
    // Updates subtotal if the third robot quantity equals to  0
    else
    {
        ThirdRobotSubtotal = 0.00;
    }
    // Disables "Checkout" button if all three robot quantities are equal to 0
    if(FirstRobotQty == 0 &&  SecondRobotQty == 0 && ThirdRobotQty == 0)
    {
        // Sets checkout button to enabled(false)
        ui->pushButton_Checkout->setEnabled(false);
    }
    // Displays updated subtotal on screen.
    ui->ThirdRobotSubtotalBox->setText(QString::number(ThirdRobotSubtotal, 'f', 2));

    // Updates order subtotal
    setTotalSubtotal();
}
/****************************************************************************
 * METHOD - setTotalSubtotal()
 * --------------------------------------------------------------------------
 * This method calculates and updates the total subtotal.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 *      ==> Updates display for total subtotal.
 ***************************************************************************/
void ShoppingCart::setTotalSubtotal()
{
    // Calculates order subtotal
    subtotal = FirstRobotSubtotal + SecondRobotSubtotal + ThirdRobotSubtotal;
    // Updates subtotal if > 0 to subtotal value
    if(subtotal > 0.0)
    {
        ui->SubtotalPriceBox->setText(QString::number(subtotal, 'f', 2));
    }
    // Updates subtotal if <= 0 to blank
    else
    {
        ui->SubtotalPriceBox->setText("");
    }
    // Updates total shipping cost displayed
    setTotalShipping();
    // Updates total sales tax displayed
    setTotalSalesTax();
    // Updates total order price displayed
    setTotalOrderPrice();
}
/****************************************************************************
 * METHOD - setTotalShipping()
 * --------------------------------------------------------------------------
 * This method updates the total shipping price.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following constant variables must be declared and initialized
 *      in the productWindow.h.
 *          SHIPPING : constant value for shipping & handling charges
 *                     used for calculating total price
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 *      ==> Updates display for shipping price.
 ***************************************************************************/
void ShoppingCart::setTotalShipping()
{
    // Updates shipping cost if subtotal > 0
    if(subtotal > 0.00)
    {
        ui->ShippingPriceBox->setText(QString::number(SHIPPING, 'f', 2));
    }
    // Updates shipping cost to blank if subtotal <= 0
    else
    {
        ui->ShippingPriceBox->setText("");
    }
}
/****************************************************************************
 * METHOD - setTotalSalesTax()
 * --------------------------------------------------------------------------
 * This method calculates and updates the order's sales tax.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 *      ==> Updates display for order sales tax.
 ***************************************************************************/
void ShoppingCart::setTotalSalesTax()
{
    // Updates sales tax amount if subtotal > 0
    if(subtotal > 0.00)
    {
        salesTax = ((subtotal + SHIPPING)*TAX_RATE);
        ui->TaxTotalPriceBox->setText(QString::number(salesTax, 'f', 2));
    }
    // Updates sales tax amount to blank if subtotal <= 0
    else
    {
        ui->TaxTotalPriceBox->setText("");
    }
}
/****************************************************************************
 * METHOD - setTotalOrderPrice()
 * --------------------------------------------------------------------------
 * This method calculates and updates the order's total price.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 *      ==> Updates display for order's total price.
 ***************************************************************************/
void ShoppingCart::setTotalOrderPrice()
{
    // Updates total order price if subtotal > 0
    if(subtotal > 0.00)
    {
        totalPrice = subtotal + SHIPPING + salesTax;
        ui->OrderTotalPriceBox->setText(QString::number(totalPrice, 'f', 2));
    }
    // Updates total order price to blank if subtotal <= 0
    else
    {
        ui->OrderTotalPriceBox->setText("");
    }
}
/************************************************************
* on_pushButtonBackMain_clicked()
* ----------------------------------------------------------
* This will allow the user to go back to the main window.
************************************************************/
void ShoppingCart::on_pushButtonBackMain_clicked()
{
    reject();
    // Hide the Window itself
    hide();
}
/************************************************************
* on_pushButton_Checkout_clicked()
* ----------------------------------------------------------
* Stores the customer's purchase into the database
************************************************************/
void ShoppingCart::on_pushButton_Checkout_clicked()
{

    //    bool querySuccess = false;
    //    QSqlQuery query(*database);
    //    querySuccess = database->PlacingOrder(customerID, qtyPurchased, date);
    //    // Execute query. If it works, update the tableview to display new entry
    //    if(querySuccess)
    //    {
    //        // Open and display order confirmation message box
    //        QMessageBox::information(this, "Order Confirmation",
    //                                 "Thank you for your order.", QMessageBox::Ok);
    //    }
    //    else
    //    {
    //        QMessageBox::information(this, "Error",
    //                                 "Company Name not found!", QMessageBox::Ok);
    //    }
}
/**********************************************************************
* on_FirstRobotComboBox_currentIndexChanged(int plan)
* --------------------------------------------------------------------
* When the value in the first robot combobox is changed, the robot
* plan choice and subtotal are updated.
**********************************************************************/
void ShoppingCart::on_FirstRobotComboBox_currentIndexChanged(int plan)
{
    // updates FirstRobotPlan plan choice
    FirstRobotPlan = plan;

    // displays the robot's subtotal change.
    setFirstRobotSubtotal();
}

/**********************************************************************
* on_FirstRobotSpinBox_valueChanged(int quantity)
* --------------------------------------------------------------------
* When the value in the first robot spinbox is changed, the robot
* quantity and subtotal is updated.
**********************************************************************/
void ShoppingCart::on_FirstRobotSpinBox_valueChanged(int quantity)
{
    // updates robot quantity
    FirstRobotQty = quantity;

    // updates robot subtotal
    setFirstRobotSubtotal();
}
/**********************************************************************
* on_SecondRobotComboBox_currentIndexChanged(int plan)
* --------------------------------------------------------------------
* When the value in the first robot combobox is changed, the robot
* plan choice and subtotal are updated.
**********************************************************************/
void ShoppingCart::on_SecondRobotComboBox_currentIndexChanged(int plan)
{
    // Updates SecondRobotPlan plan choice
    SecondRobotPlan = plan;

    // Displays the robot's subtotal change.
    setSecondRobotSubtotal();
}
/**********************************************************************
* on_SecondRobotSpinBox_valueChanged(int quantity)
* --------------------------------------------------------------------
* When the value in the second robot spinbox is changed, the robot
* quantity and subtotal is updated.
**********************************************************************/
void ShoppingCart::on_SecondRobotSpinBox_valueChanged(int quantity)
{
    // Updates robot quantity
    SecondRobotQty = quantity;

    // Updates robot subtotal
    setSecondRobotSubtotal();
}
/**********************************************************************
* on_ThirdRobotComboBox_currentIndexChanged(int plan)
* --------------------------------------------------------------------
* When the value in the first robot combobox is changed, the robot
* plan choice and subtotal are updated.
**********************************************************************/
void ShoppingCart::on_ThirdRobotComboBox_currentIndexChanged(int plan)
{
    // Updates ThirdRobotPlan plan choice
    ThirdRobotPlan = plan;

    // Displays the robot's subtotal change.
    setThirdRobotSubtotal();
}
/**********************************************************************
* on_ThirdRobotSpinBox_valueChanged(int quantity)
* --------------------------------------------------------------------
* When the value in the third robot spinbox is changed, the robot
* quantity and subtotal is updated.
**********************************************************************/
void ShoppingCart::on_ThirdRobotSpinBox_valueChanged(int quantity)
{
    // Updates robot quantity
    ThirdRobotQty = quantity;

    // Updates robot subtotal
    setThirdRobotSubtotal();
}
/****************************************************************************
 * METHOD - on_robotCComboBox_currentIndexChanged
 * --------------------------------------------------------------------------
 * This method is activated when the value in the robot C's maintenance
 * plan combobox value is changed.  The robot plan index and subtotal are
 * updated.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following parameters need to have a defined value
 *          index : the robot plan combo box index selected
 *
 * POST-CONDITIONS
 *      ==> Returns nothing
 ***************************************************************************/
void ShoppingCart::on_CompanyNameComboBox_currentIndexChanged(const QString &arg1)
{
    QSqlQuery query(*database);
    QString name = ui->CompanyNameComboBox->currentText();
    QString address ="";
    // Execute 'Add Customer' Query
    address = database->ShippingAddress(name);

    ui->CompanyAddressBox->setText(address);

}
/****************************************************************************
 * METHOD - on_yesCheckBox_toggled
 * --------------------------------------------------------------------------
 * This method is determines the shipping address display on screen using
 * the yesCheckBox toggled value.  If the "Yes" box is clicked, the
 * shipping address line edit boxes are updated with the billing address
 * information and disables the ability to edit it.  If the "Yes" box is not
 * clicked (the "No" box is clicked), then the shipping address information
 * is cleared and it is editable.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing
 ***************************************************************************/
void ShoppingCart::on_yesCheckBox_toggled(bool checked)
{
    // If "Yes".  Shipping address is same as billing address
    // Copy billing address to shipping address lines
    // Disable shipping address lines to no editing.
    if(checked == true)
    {
        ui->AddressStreetBox->setEnabled(false);
        ui->AddressStreetBox->setText(ui->CompanyAddressBox->text());
        ui->CityBox->setEnabled(false);
        ui->ZipCodeBox->setEnabled(false);
        ui->StateComboBox->setEnabled(false);
        ui->CountryComboBox->setEnabled(false);
    }
    // If "No".  Shipping address is not same as billing address
    // Empty shipping address lines so information can be entered
    // Enable shipping address lines so can be edited
    else
    {
        ui->AddressStreetBox->setEnabled(true);
        ui->AddressStreetBox->setText("");
        ui->CityBox->setEnabled(true);
        ui->CityBox->setText("");
        ui->ZipCodeBox->setEnabled(true);
        ui->ZipCodeBox->setText("");
        ui->StateComboBox->setEnabled(true);
        ui->StateComboBox->setCurrentText(" ");
        ui->CountryComboBox->setEnabled(true);
        ui->CountryComboBox->setCurrentText(" ");
    }
}

/****************************************************************************
 * METHOD - on_billingAddressLineOne_editingFinished
 * --------------------------------------------------------------------------
 * This method is activated when another element on the screen is selected.
 * This method saves the billing address line entered to a variable.  It
 * also updates the shipping address if the yesCheckBox is clicked.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing
 ***************************************************************************/
void ShoppingCart::on_CompanyAddressBox_editingFinished()
{
    // Save the entered billing address line into a variable
    shippingAddress = ui->CompanyAddressBox->text();

    // If the "Yes" check box is clicked that the shipping address is the
    // same as the billing address, update shipping address information on
    // the screen.
    if(ui->yesCheckBox->checkState() == Qt::Checked)
    {
        ui->AddressStreetBox->
                setText(ui->CompanyAddressBox->text());
    }
}
/****************************************************************************
 * METHOD - on_dateMonthLine_editingFinished
 * --------------------------------------------------------------------------
 * This method is activated when another element on the screen is selected.
 * This method saves the credit card expire month date line entered to a
 * variable.  It only saves the value if the month integer entered is
 * more than 0 and less than or equal to 12.  If the value entered is not
 * valid, the box clears when another element on the screen is selected.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing
 ***************************************************************************/
void ShoppingCart::on_CreditCardMonthBox_editingFinished()
{
    QString temp; // CALC - used to hold month QString value temporarily

    // Store QString value to temporary variable so it can be converted
    // to an integer value.
    temp = ui->CreditCardMonthBox->text();

    // Store the converted QString to integer into a variable
    // A non-integer value is stored as a 0.
    CardMonth = temp.toInt();

    // If the converted int month value is not between 1-12, clear the
    // month box so it can be re-entered.
    if(CardMonth > 12 || CardMonth <= 0)
    {
        ui->CreditCardMonthBox->setText("");
    }
}

/****************************************************************************
 * METHOD - on_dateYearLine_editingFinished
 * --------------------------------------------------------------------------
 * This method is activated when another element on the screen is selected.
 * This method saves the credit card expire year date line entered to a
 * variable.  It only saves the value if the year integer entered is
 * between 19 to 99.  If the value entered is not within this valid range,
 * the box clears when another element on the screen is selected.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing
 ***************************************************************************/
void ShoppingCart::on_CreditCardYearBox_editingFinished()
{
    QString temp; // CALC - used to hold year QString value temporarily

    // Store QString value to temporary variable so it can be converted
    // to an integer value.
    temp = ui->CreditCardYearBox->text();

    // Store the converted QString to integer into a variable
    // A non-integer value is stored as a 0.
    CardYear = temp.toInt();

    // If the converted int year value is not between 23-99, clear the
    // year box so it can be re-entered.
    if(CardYear >= 99 || CardYear < 23)
    {
        ui->CreditCardYearBox->setText("");
    }
}

/****************************************************************************
 * METHOD - on_cvvLine_editingFinished
 * --------------------------------------------------------------------------
 * This method is activated when another element on the screen is selected.
 * This method saves the credit card CVV line entered to a variable.
 * It only saves the value if it is between 1 to 9999.  If the value
 * entered is not within this valid range, the box clears when another
 * element on the screen is selected.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing
 ***************************************************************************/
void ShoppingCart::on_CreditCardCVVNumberBox_editingFinished()
{
    // CALC - used to hold CVV QString value temporarily
    QString temp;

    // Store QString value to temporary variable so it can be converted
    // to an integer value.
    temp = ui->CreditCardCVVNumberBox->text();

    // Store the converted QString to integer into a variable
    // A non-integer value is stored as a 0.
    CardCvv = temp.toInt();

    // If the converted int CVV value is not between 1 to 9999, clear the
    // CVV box so it can be re-entered.
    if(CardCvv >= 1000 || CardCvv <= 0)
    {
        ui->CreditCardCVVNumberBox->setText("");
    }
}
