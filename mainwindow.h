/******************************************************************************
 * PROGRAMMERS: - Jonathan Aguirre
 *              - Tina     Faraji
 *              - Suhyr    Hasan
 *              - Weston   Mathews
 * CLASS      : CS1C
 * SECTION    : MW 5:00p - 7:30p
 * DUE DATE   : 02/23/20
 *****************************************************************************/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtDebug>
#include <QFileInfo>
#include <QPixmap>
#include "Robot.h"
#include "CustomerService.h"
#include "Help.h"
#include "Admin.h"
#include "Pamphlet.h"
#include "Review.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_RobotPage_clicked();

    void on_pushButton_CustomerService_clicked();

    void on_pushButton_HelpPage_clicked();

    void on_pushButton_AdminPage_clicked();

    void on_pushButton_SendPamphlet_clicked();

    void on_pushButton_ReviewPage_clicked();

private:
    Ui::MainWindow *ui;
    Robot *robot;
    CustomerService *customerService;
    Help *help;
    Pamphlet *pamphlet;
    Admin *admin;
    Review *review;
};
#endif // MAINWINDOW_H
