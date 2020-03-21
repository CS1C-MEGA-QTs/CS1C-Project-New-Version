#ifndef PAMPHLET_H
#define PAMPHLET_H

#include <QDialog>
#include <QtDebug>
#include <QString>
#include <QFileInfo>
#include <QMessageBox>
#include "Database.h"

namespace Ui {
class Pamphlet;
}

class Pamphlet : public QDialog
{
    Q_OBJECT

public:
    //!< Constructor
    explicit Pamphlet(QWidget *parent = nullptr);
    //!< Destructor
    ~Pamphlet();

private slots:
    // Updates address box
    void on_CompanyNameComboBox_currentIndexChanged(const QString &arg1);
    // Send phamphlet to customers
    void on_pushButtonSendPamphlet_clicked();

private:
    Ui::Pamphlet *ui;
    Database *database;
};

#endif // PAMPHLET_H
