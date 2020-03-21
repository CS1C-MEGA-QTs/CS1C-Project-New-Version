/******************************************************************************
 * PROGRAMMERS: - Jonathan Aguirre
 *              - Tina     Faraji
 *              - Suhyr    Hasan
 *              - Weston   Mathews
 * CLASS      : CS1C
 * SECTION    : MW 5:00p - 7:30p
 * DUE DATE   : 02/23/20
 *****************************************************************************/
#ifndef REVIEW_H
#define REVIEW_H

#include <QDialog>

namespace Ui {
class Review;
}

class Review : public QDialog
{
    Q_OBJECT

public:
    explicit Review(QWidget *parent = nullptr);
    ~Review();

private:
    Ui::Review *ui;
};

#endif // REVIEW_H
