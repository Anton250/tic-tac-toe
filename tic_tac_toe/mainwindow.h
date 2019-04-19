#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QMap>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QTcpSocket * clientSocket;

private:
    Ui::MainWindow *ui;
    QMap <QString, bool> checkList;
    QString userSign;
    QString messageToServer;
    QByteArray arr;
    bool gameStarted = false;
    QString XorO(std::string str);
    bool winsRows[8] = {false, false, false, false, false, false, false, false};
    bool turn = false;
    bool checkWin();
    int countOfActivatedCells = 0;
    bool result = false;
    void lose();
    void draw();
private slots:
    int readFromServer();
    void disconnectClient();
    void on_pushButton_start_clicked();
    void clearButtons();

    void on_pushButton_1_1_clicked();
    void on_pushButton_1_2_clicked();
    void on_pushButton_1_3_clicked();
    void on_pushButton_2_1_clicked();
    void on_pushButton_2_2_clicked();
    void on_pushButton_2_3_clicked();
    void on_pushButton_3_1_clicked();
    void on_pushButton_3_2_clicked();
    void on_pushButton_3_3_clicked();
    void on_pushButton_exit_clicked();
};

#endif // MAINWINDOW_H
