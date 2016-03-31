#include "boardmodel.h"

BoardModel::BoardModel(QObject *parent) : QAbstractListModel(parent)
{
    m_items.resize(9);
    m_roles.insert(SYMBOL, "symbol");
}

int BoardModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_items.size();
}

QVariant BoardModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();

    if(index.row() < 0 || index.row() >= m_items.size())
        return QVariant();

    switch (role) {
    case SYMBOL:
        return m_items.at(index.row());
    }

    return QVariant();
}

QHash<int, QByteArray> BoardModel::roleNames() const
{
    return m_roles;
}

bool BoardModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!index.isValid())
        return false;

    if(index.row() < 0 || index.row() >= m_items.size())
        return false;

    if(role != Qt::EditRole)
        return false;

    QString symbol = value.toString();
    if(m_items[index.row()] != symbol)
    {
        m_items[index.row()] = symbol;
        emit dataChanged(index, index);
        return true;
    }
    else
        return false;
}

void BoardModel::setSymbol(QString symbol, int row)
{
    this->setData(createIndex(row, 0), QVariant(symbol), Qt::EditRole);
}

QString BoardModel::symbolAt(int row) const
{
    return data(createIndex(row, 0), SYMBOL).toString();
}
