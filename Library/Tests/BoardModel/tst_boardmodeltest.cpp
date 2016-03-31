#include <QString>
#include <QtTest>

#include <boardmodel.h>

class BoardModelTest : public QObject
{
    Q_OBJECT

public:
    BoardModelTest();

private Q_SLOTS:
    void setSymbol();
};

BoardModelTest::BoardModelTest()
{
}

void BoardModelTest::setSymbol()
{
    BoardModel model;
    QString expected("x");
    model.setSymbol("x", 0);

    QString actual = model.symbolAt(0);
    QCOMPARE(actual, expected);
}

QTEST_APPLESS_MAIN(BoardModelTest)

#include "tst_boardmodeltest.moc"
