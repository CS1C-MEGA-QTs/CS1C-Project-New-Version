/******************************************************************************
 * PROGRAMMERS: - Jonathan Aguirre
 *              - Tina     Faraji
 *              - Suhyr    Hasan
 *              - Weston   Mathews
 * CLASS      : CS1C
 * SECTION    : MW 5:00p - 7:30p
 * DUE DATE   : 02/23/20
 *****************************************************************************/
#include "CustomerTableModel.h"

CustomerTableModel::CustomerTableModel(QObject *parent, QSqlDatabase *db)
    : QSqlTableModel(parent, *db) {}

void CustomerTableModel::InitializeCompleteTable()
{
    this->setTable("customers");

    this->setHeaderData(NAME, Qt::Horizontal, tr("Name"));
    this->setHeaderData(ADDRESS, Qt::Horizontal, tr("Address"));
    this->setHeaderData(WEBSITE, Qt::Horizontal, tr("Website"));
    this->setHeaderData(INTEREST_LEVEL, Qt::Horizontal, tr("Interest Level"));
    this->setHeaderData(DO_NOT_CONTACT, Qt::Horizontal, tr("Do Not Contact"));
    this->setHeaderData(KEY_ACCOUNT, Qt::Horizontal, tr("Key Account"));
    this->setHeaderData(PAMPHLET_SENT, Qt::Horizontal, tr("Pamphlet Sent"));

    this->select();
}

void CustomerTableModel::InitializeKeyTable()
{
    this->setTable("customers");
    this->setFilter("keyAccount=1");

    this->setHeaderData(NAME, Qt::Horizontal, tr("Name"));
    this->setHeaderData(ADDRESS, Qt::Horizontal, tr("Address"));
    this->setHeaderData(WEBSITE, Qt::Horizontal, tr("Website"));
    this->setHeaderData(INTEREST_LEVEL, Qt::Horizontal, tr("Interest Level"));
    this->setHeaderData(DO_NOT_CONTACT, Qt::Horizontal, tr("Do Not Contact"));
    this->setHeaderData(KEY_ACCOUNT, Qt::Horizontal, tr("Key Account"));
    this->setHeaderData(PAMPHLET_SENT, Qt::Horizontal, tr("Pamphlet Sent"));

    this->select();
}
