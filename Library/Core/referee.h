#ifndef REFEREE_H
#define REFEREE_H

#include "core_global.h"

#include <QObject>
#include <QVector>

/*!
 * \brief The Referee class
 * Check board for the winning symbol
 */

class CORESHARED_EXPORT Referee : public QObject
{
    Q_OBJECT
public:
    explicit Referee(QObject *parent = 0);

    /*! Check the winner on the \a board
     * @param board vector of strings(symbols)
     * @return The winning symbol or empty string
    */
    QString checkWinner(const QVector<QString>& board);

signals:

public slots:
};

#endif // REFEREE_H
