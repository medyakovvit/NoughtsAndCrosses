#include <QString>
#include <QtTest>

#include <referee.h>

class RefereeTest : public QObject
{
    Q_OBJECT

public:
    RefereeTest();

private Q_SLOTS:
    void topRow();
    void leftColumn();

    void centerRow();
    void centerColumn();
    void topLeft_to_bottomRight_diag();
    void topRight_to_bottomLeft_diag();

    void rightColumn();
    void bottomRow();

    void draw();
    void error();

protected:
    Referee referee;
    QVector<QString> board;
};

RefereeTest::RefereeTest()
{
    board.resize(9);
}

void RefereeTest::topRow()
{
    QString expected = "x";
    board[0]="x"; board[1]="x"; board[2]="x";
    board[3]="x"; board[4]="o"; board[5]="o";
    board[6]="o"; board[7]="o"; board[8]="x";
    QCOMPARE(referee.checkWinner(board), expected);
}

void RefereeTest::leftColumn()
{
    QString expected = "x";
    board[0]="x"; board[1]="o"; board[2]="x";
    board[3]="x"; board[4]="o"; board[5]="o";
    board[6]="x"; board[7]="x"; board[8]="o";
    QCOMPARE(referee.checkWinner(board), expected);
}

void RefereeTest::centerRow()
{
    QString expected = "x";
    board[0]="x"; board[1]="o"; board[2]="x";
    board[3]="o"; board[4]="x"; board[5]="x";
    board[6]="x"; board[7]="o"; board[8]="o";
    QCOMPARE(referee.checkWinner(board), expected);
}

void RefereeTest::centerColumn()
{
    QString expected = "x";
    board[0]="o"; board[1]="x"; board[2]="x";
    board[3]="x"; board[4]="x"; board[5]="o";
    board[6]="o"; board[7]="x"; board[8]="o";
    QCOMPARE(referee.checkWinner(board), expected);
}

void RefereeTest::topLeft_to_bottomRight_diag()
{
    QString expected = "x";
    board[0]="x"; board[1]="o"; board[2]="x";
    board[3]="x"; board[4]="x"; board[5]="o";
    board[6]="o"; board[7]="o"; board[8]="x";
    QCOMPARE(referee.checkWinner(board), expected);
}

void RefereeTest::topRight_to_bottomLeft_diag()
{
    QString expected = "x";
    board[0]="x"; board[1]="o"; board[2]="x";
    board[3]="o"; board[4]="x"; board[5]="x";
    board[6]="x"; board[7]="o"; board[8]="o";
    QCOMPARE(referee.checkWinner(board), expected);
}

void RefereeTest::rightColumn()
{
    QString expected = "x";
    board[0]="o"; board[1]="o"; board[2]="x";
    board[3]="x"; board[4]="o"; board[5]="x";
    board[6]="o"; board[7]="x"; board[8]="x";
    QCOMPARE(referee.checkWinner(board), expected);
}

void RefereeTest::bottomRow()
{
    QString expected = "x";
    board[0]="x"; board[1]="o"; board[2]="o";
    board[3]="o"; board[4]="o"; board[5]="x";
    board[6]="x"; board[7]="x"; board[8]="x";
    QCOMPARE(referee.checkWinner(board), expected);
}

void RefereeTest::draw()
{
    QString expected = "";
    board[0]="x"; board[1]="x"; board[2]="o";
    board[3]="o"; board[4]="o"; board[5]="x";
    board[6]="x"; board[7]="o"; board[8]="x";
    QCOMPARE(referee.checkWinner(board), expected);
}

void RefereeTest::error()
{
    QVector<QString> smallBoard;
    board.resize(3);
    QCOMPARE(referee.checkWinner(smallBoard), QString());
}

QTEST_APPLESS_MAIN(RefereeTest)

#include "tst_refereetest.moc"
