#ifndef BOARDMODEL_H
#define BOARDMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QVector>

#include "core_global.h"


/*! \class BoardModel
 *  \brief Implements Gaming board
 *
*/

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
    /*! Set symbol a position \a row to \a symbol*/
    bool setSymbol(QString symbol, int row);

    /*! Check symbol at position \a row*/
    QString symbolAt(int row)const;

    /*! Reset all symbols on board to ""*/
    void clearBoard();

protected:
    QVector<QString> m_items; /*!< Symbols on board. Variable of type QString to pass to qml*/
    QHash<int, QByteArray> m_roles;
};

#endif // BOARDMODEL_H
