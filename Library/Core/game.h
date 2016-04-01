#ifndef GAME_H
#define GAME_H

#include "core_global.h"

#include <QObject>

class CORESHARED_EXPORT Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(QObject *parent = 0);

signals:
    void started();

public slots:
    void start();
};

#endif // GAME_H
