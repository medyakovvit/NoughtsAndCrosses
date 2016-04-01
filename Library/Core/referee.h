#ifndef REFEREE_H
#define REFEREE_H

#include "core_global.h"

#include <QObject>
#include <QVector>

class CORESHARED_EXPORT Referee : public QObject
{
    Q_OBJECT
public:
    explicit Referee(QObject *parent = 0);

    QString checkWinner(const QVector<QString>& board);

signals:

public slots:
};

#endif // REFEREE_H
