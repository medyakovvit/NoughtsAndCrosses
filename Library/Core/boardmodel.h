#ifndef BOARDMODEL_H
#define BOARDMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QVector>

#include "core_global.h"

class CORESHARED_EXPORT BoardModel : public QAbstractListModel
{
    Q_OBJECT

    enum Roles{
        SYMBOL = Qt::UserRole+1
    };

public:
    explicit BoardModel(QObject *parent = 0);

    QVector<QString> items()const{return m_items;}

    // QAbstractItemModel interface
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);

signals:

public slots:
    void setSymbol(QString symbol, int row);
    QString symbolAt(int row)const;
    void clearBoard();

protected:
    QVector<QString> m_items;
    QHash<int, QByteArray> m_roles;
};

#endif // BOARDMODEL_H
