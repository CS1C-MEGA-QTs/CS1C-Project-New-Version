/******************************************************************************
 * PROGRAMMERS: - Jonathan Aguirre
 *              - Tina     Faraji
 *              - Suhyr    Hasan
 *              - Weston   Mathews
 * CLASS      : CS1C
 * SECTION    : MW 5:00p - 7:30p
 * DUE DATE   : 02/23/20
 *****************************************************************************/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Database.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /******************************
     **** SPECIFIC TO HOME TAB ****
     ******************************/

    /************************************************************
    * PROCESSING - Assign an image into new QPixmap variable
    ************************************************************/
    QPixmap homePageBackground (":/new/prefix1/Background.jpg");
    QPixmap homePageCornerImage(":/King Bob-Omb Pic/King Bob-Omb.png");

    /************************************************************
    * PROCESSING - Set the label to hold the image specified
    ************************************************************/
    int ImageLabelW =  ui -> ImageLabel->width ();
    int ImageLabelH =  ui -> ImageLabel->height();
    ui -> ImageLabel -> setPixmap(homePageBackground.scaled
                                  (ImageLabelW, ImageLabelH,
                                   Qt::KeepAspectRatio));
    /************************************************************
    * PROCESSING - Set the label to hold the image specified
    ************************************************************/
    int MEGAQTImageLabelW =  ui -> MEGAQTImageLabel->width ();
    int MEGAQTImageLabelH =  ui -> MEGAQTImageLabel->height();
    ui -> MEGAQTImageLabel -> setPixmap(homePageCornerImage.scaled
                                        (MEGAQTImageLabelW, MEGAQTImageLabelH,
                                         Qt::KeepAspectRatio));
    /************************************************************
    * PROCESSING - Access the label and give values of:
    *              Background = white
    ************************************************************/
    ui -> WelcomeLabel -> setStyleSheet("QLabel { background-color : white; }");
}

MainWindow::~MainWindow()
{
    delete ui;
}


/************************************************************
* on_pushButton_RobotPage_clicked()
* ----------------------------------------------------------
* This will allow the user to go to the robot page.
************************************************************/
void MainWindow::on_pushButton_RobotPage_clicked()
{
    // Hides the Main Window
    hide();

    // Shows the Robot Window
    robot =  new Robot(this);
    robot -> show();
}
/************************************************************
* on_pushButton_CustomerService_clicked()
* ----------------------------------------------------------
* This will allow the user to go to the Customer Service page.
************************************************************/
void MainWindow::on_pushButton_CustomerService_clicked()
{
    // Hides the Main Window
    hide();

    // Shows the Customer Service Window
    customerService =  new CustomerService(this);
    customerService -> show();
}
/************************************************************
* on_pushButton_HelpPage_clicked()
* ----------------------------------------------------------
* This will allow the user to go to the help page.
************************************************************/
void MainWindow::on_pushButton_HelpPage_clicked()
{
    // Shows the Help Window
    help =  new Help(this);
    help -> show();
}
/************************************************************
* on_pushButton_AdminPage_clicked()
* ----------------------------------------------------------
* This will allow the user to go to the admin page.
************************************************************/
void MainWindow::on_pushButton_AdminPage_clicked()
{
    // Hides the Main Window
    //  hide();

    // Shows the Admin Window
    admin =  new Admin(this);
    admin -> show();
}
/************************************************************
* on_pushButton_SendPamphlet_clicked()
* ----------------------------------------------------------
* This will allow the user to go to the send pamphlet page.
************************************************************/
void MainWindow::on_pushButton_SendPamphlet_clicked()
{
    // Shows the Phamphlet Window
    pamphlet =  new Pamphlet(this);
    pamphlet -> show();
}
/************************************************************
* on_pushButton_ReviewPage_clicked()
* ----------------------------------------------------------
* This will allow the user to go to the review page.
************************************************************/
void MainWindow::on_pushButton_ReviewPage_clicked()
{
    // Hides the Main Window
    //  hide();
    // Shows the Review Window
    review =  new Review(this);
    review -> show();
}
