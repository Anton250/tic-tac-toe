#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Game->close();
    ui->label_status->close();
    ui->pushButton_exit->close();
    for (int i = 0; i < 9; i++){

            checkList[i] = false;

    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::readFromServer()
{
    QString answer = clientSocket->readAll();
    std::string str_answer = answer.toStdString();
    int pos = str_answer.find("11$");
    if(pos != std::string::npos){
        ui->pushButton_1_1->setText(XorO(str_answer));
        ui->label_statusOfMove->setText("Your move");
        checkList[0] = true;
        turn = true;
        pos = str_answer.find("$lose");
        if(pos != std::string::npos){
            lose();
        }
        pos = str_answer.find("$draw");
        if(pos != std::string::npos){
            draw();
        }
        return 0;
    }
    pos = str_answer.find("12$");
    if(pos != std::string::npos){
        ui->pushButton_1_2->setText(XorO(str_answer));
        ui->label_statusOfMove->setText("Your move");
        checkList[1] = true;
        turn = true;
        pos = str_answer.find("$lose");
        if(pos != std::string::npos){
            lose();
        }
        pos = str_answer.find("$draw");
        if(pos != std::string::npos){
            draw();
        }
        return 0;
    }
    pos = str_answer.find("13$");
    if(pos != std::string::npos){
        ui->pushButton_1_3->setText(XorO(str_answer));
         ui->label_statusOfMove->setText("Your move");
        checkList[2] = true;
        turn = true;
        pos = str_answer.find("$lose");
        if(pos != std::string::npos){
            lose();
        }
        pos = str_answer.find("$draw");
        if(pos != std::string::npos){
            draw();
        }
        return 0;
    }
    pos = str_answer.find("21$");
    if(pos != std::string::npos){
        ui->pushButton_2_1->setText(XorO(str_answer));
         ui->label_statusOfMove->setText("Your move");
        checkList[3] = true;
        turn = true;
        pos = str_answer.find("$lose");
        if(pos != std::string::npos){
            lose();
        }
        pos = str_answer.find("$draw");
        if(pos != std::string::npos){
            draw();
        }
        return 0;
    }
    pos = str_answer.find("22$");
    if(pos != std::string::npos){
        ui->pushButton_2_2->setText(XorO(str_answer));
         ui->label_statusOfMove->setText("Your move");
        checkList[4] = true;
        turn = true;
        pos = str_answer.find("$lose");
        if(pos != std::string::npos){
            lose();
        }
        pos = str_answer.find("$draw");
        if(pos != std::string::npos){
            draw();
        }
        return 0;
    }
    pos = str_answer.find("23$");
    if(pos != std::string::npos){
        ui->pushButton_2_3->setText(XorO(str_answer));
         ui->label_statusOfMove->setText("Your move");
        checkList[5] = true;
        turn = true;
        pos = str_answer.find("$lose");
        if(pos != std::string::npos){
            lose();
        }
        pos = str_answer.find("$draw");
        if(pos != std::string::npos){
            draw();
        }
        return 0;
    }
    pos = str_answer.find("31$");
    if(pos != std::string::npos){
        ui->pushButton_3_1->setText(XorO(str_answer));
         ui->label_statusOfMove->setText("Your move");
        checkList[6] = true;
        turn = true;
        pos = str_answer.find("$lose");
        if(pos != std::string::npos){
            lose();
        }
        pos = str_answer.find("$draw");
        if(pos != std::string::npos){
            draw();
        }
        return 0;
    }
    pos = str_answer.find("32$");
    if(pos != std::string::npos){
        ui->pushButton_3_2->setText(XorO(str_answer));
         ui->label_statusOfMove->setText("Your move");
        checkList[7] = true;
        turn = true;
        pos = str_answer.find("$lose");
        if(pos != std::string::npos){
            lose();
        }
        pos = str_answer.find("$draw");
        if(pos != std::string::npos){
            draw();
        }
        return 0;
    }
    pos = str_answer.find("33$");
    if(pos != std::string::npos){
        ui->pushButton_3_3->setText(XorO(str_answer));
         ui->label_statusOfMove->setText("Your move");
        checkList[8] = true;
        turn = true;
        pos = str_answer.find("$lose");
        if(pos != std::string::npos){
            lose();
        }
        pos = str_answer.find("$draw");
        if(pos != std::string::npos){
            draw();
        }
        return 0;
    }
    pos = str_answer.find("wait$");
    if(pos != std::string::npos){
        ui->label_status->setText("Waiting for oponent");
        gameStarted = false;
        return 0;
    }
    pos = str_answer.find("userDisconnected$");
    if(pos != std::string::npos){
        ui->label_status->setText("Your oponent disconnected, waiting for other oponent");
        gameStarted = false;
        clearButtons();
        return 0;
    }
    pos = str_answer.find("startGame$");
    if(pos != std::string::npos){
        str_answer.erase(0, 10);
        clearButtons();
        gameStarted = true;
         ui->Game->show();
         ui->label_status->setText("Game started!");
        if (str_answer == "X"){
            ui->label_textSign->setText("Your sign is X");
             ui->label_statusOfMove->setText("Your move");
            userSign = "X";
            turn = true;
        } else {
            ui->label_textSign->setText("Your sign is O");
            ui->label_statusOfMove->setText("Your oponent moving");
            userSign = "O";
        }

        return 0;
    }
    return 0;
}

void MainWindow::disconnectClient()
{
    clientSocket->disconnect();
}

void MainWindow::on_pushButton_start_clicked()
{
    clientSocket = new QTcpSocket;
    clientSocket->connectToHost("127.0.0.1", 6000);
    connect(clientSocket, &QTcpSocket::readyRead, this, &MainWindow::readFromServer);
    connect(clientSocket, &QTcpSocket::disconnected, this, &MainWindow::disconnectClient);
    ui->pushButton_start->close();
    ui->label_status->show();
    ui->Game->show();
    ui->pushButton_exit->show();
}

void MainWindow::clearButtons()
{
    ui->pushButton_1_1->setText("");
    ui->pushButton_1_2->setText("");
    ui->pushButton_1_3->setText("");
    ui->pushButton_2_1->setText("");
    ui->pushButton_2_2->setText("");
    ui->pushButton_2_3->setText("");
    ui->pushButton_3_1->setText("");
    ui->pushButton_3_2->setText("");
    ui->pushButton_3_3->setText("");
    for (int i = 0; i < 8; i++){
        winsRows[i] = false;
    }
    countOfActivatedCells = 0;
    for (int i = 0; i < 9; i++){

            checkList[i] = false;

    }
    result = false;
    turn = false;
    userSign = "";
    messageToServer = "";
}

QString MainWindow::XorO(std::string str)
{
    if (str.find("X") != std::string::npos){
        return "X";
    } else {

        return "O";
    }}

bool MainWindow::checkWin()
{
    QString first, second, third;
    if (!winsRows[0] && checkList[0] && checkList[1] && checkList[2]){
        first = ui->pushButton_1_1->text();
        second = ui->pushButton_1_2->text();
        third = ui->pushButton_1_3->text();
        winsRows[0] = true;
        if(first == second && first == third){
            return true;
        }
        return false;
    }
    if (!winsRows[1] && checkList[3] && checkList[4] && checkList[5]){
        first = ui->pushButton_2_1->text();
        second = ui->pushButton_2_2->text();
        third = ui->pushButton_2_3->text();
        winsRows[1] = true;
        if(first == second && first == third){
            return true;
        }
        return false;
    }
    if (!winsRows[2] && checkList[6] && checkList[7] && checkList[8]){
        first = ui->pushButton_3_1->text();
        second = ui->pushButton_3_2->text();
        third = ui->pushButton_3_3->text();
        winsRows[2] = true;
        if(first == second && first == third){
            return true;
        }
        return false;
    }
    if (!winsRows[3] && checkList[0] && checkList[3] && checkList[6]){
        first = ui->pushButton_1_1->text();
        second = ui->pushButton_2_1->text();
        third = ui->pushButton_3_1->text();
        winsRows[3] = true;
        if(first == second && first == third){
            return true;
        }
        return false;
    }
    if (!winsRows[4] && checkList[1] && checkList[4] && checkList[7]){
        first = ui->pushButton_1_2->text();
        second = ui->pushButton_2_2->text();
        third = ui->pushButton_3_2->text();
        winsRows[4] = true;
        if(first == second && first == third){
            return true;
        }
        return false;
    }
    if (!winsRows[5] && checkList[2] && checkList[5] && checkList[8]){
        first = ui->pushButton_1_3->text();
        second = ui->pushButton_2_3->text();
        third = ui->pushButton_3_3->text();
        winsRows[5] = true;
        if(first == second && first == third){
            return true;
        }
        return false;
    }
    if (!winsRows[6] && checkList[0] && checkList[4] && checkList[8]){
        first = ui->pushButton_1_1->text();
        second = ui->pushButton_2_2->text();
        third = ui->pushButton_3_3->text();
        winsRows[6] = true;
        if(first == second && first == third){
            return true;
        }
        return false;
    }
    if (!winsRows[7] && checkList[2] && checkList[4] && checkList[6]){
        first = ui->pushButton_1_3->text();
        second = ui->pushButton_2_2->text();
        third = ui->pushButton_3_1->text();
        winsRows[7] = true;
        if(first == second && first == third){
            return true;
        }
        return false;
    }
    return false;
}

void MainWindow::lose()
{
    ui->label_statusOfMove->setText("You lose.");
    QString answer = "startGame!";
    arr.clear();
    arr.append(answer);
    clientSocket->write(arr);

}

void MainWindow::draw()
{
    QString answer = "startGame!";
    arr.clear();
    arr.append(answer);
    clientSocket->write(arr);

    ui->label_statusOfMove->setText("Draw.");
}


void MainWindow::on_pushButton_1_1_clicked()
{
    if(gameStarted && turn){
        if(!checkList[0]){
            turn = false;
             checkList[0] = true;
              ui->pushButton_1_1->setText(userSign);
            result = checkWin();
            countOfActivatedCells++;

            if (result){
                 ui->label_statusOfMove->setText("You win!");
                 messageToServer = "11$" + userSign + "$lose";
            } else if (countOfActivatedCells == 5) {

                ui->label_statusOfMove->setText("Draw");

                messageToServer = "11$" + userSign + "$draw";
            } else {
                ui->label_statusOfMove->setText("Your oponent moving");
                messageToServer = "11$" + userSign;
            }}

            arr.clear();
            arr.append(messageToServer);
            clientSocket->write(arr);

        }
    }


void MainWindow::on_pushButton_1_2_clicked()
{
    if(gameStarted && turn){
        if(!checkList[1]){
            turn = false;
            checkList[1] = true;
            ui->pushButton_1_2->setText(userSign);
            result = checkWin();
            countOfActivatedCells++;

            if (result){
                 ui->label_statusOfMove->setText("You win!");
                 messageToServer = "12$" + userSign + "$lose";

            } else if (countOfActivatedCells == 5) {

                ui->label_statusOfMove->setText("Draw");


                messageToServer = "12$" + userSign + "$draw";
            } else {
                ui->label_statusOfMove->setText("Your oponent moving");
                messageToServer = "12$" + userSign;
            }}

            arr.clear();
            arr.append(messageToServer);
            clientSocket->write(arr);

        }
    }


void MainWindow::on_pushButton_1_3_clicked()
{
    if(gameStarted && turn){
        if(!checkList[2]){
            turn = false;
             checkList[2] = true;
             ui->pushButton_1_3->setText(userSign);
            result = checkWin();
            countOfActivatedCells++;

            if (result){
                 ui->label_statusOfMove->setText("You win!");
                 messageToServer = "13$" + userSign + "$lose";

            } else if (countOfActivatedCells == 5) {

                ui->label_statusOfMove->setText("Draw");


                messageToServer = "13$" + userSign + "$draw";
            } else {
                ui->label_statusOfMove->setText("Your oponent moving");
                messageToServer = "13$" + userSign;
            }}

            arr.clear();
            arr.append(messageToServer);
            clientSocket->write(arr);

        }
    }


void MainWindow::on_pushButton_2_1_clicked()
{
    if(gameStarted && turn){
        if(!checkList[3]){
            turn = false;
            checkList[3] = true;
            ui->pushButton_2_1->setText(userSign);
            result = checkWin();
            countOfActivatedCells++;

            if (result){
                 ui->label_statusOfMove->setText("You win!");
                 messageToServer = "21$" + userSign + "$lose";

            } else if (countOfActivatedCells == 5) {

                ui->label_statusOfMove->setText("Draw");


                messageToServer = "21$" + userSign + "$draw";
            } else {
                ui->label_statusOfMove->setText("Your oponent moving");
                messageToServer = "21$" + userSign;
            }}

            arr.clear();
            arr.append(messageToServer);
            clientSocket->write(arr);

        }
    }


void MainWindow::on_pushButton_2_2_clicked()
{
    if(gameStarted && turn){
        if(!checkList[4]){
            turn = false;
             checkList[4] = true;
             ui->pushButton_2_2->setText(userSign);
            result = checkWin();
            countOfActivatedCells++;

            if (result){
                 ui->label_statusOfMove->setText("You win!");
                 messageToServer = "22$" + userSign + "$lose";

            } else if (countOfActivatedCells == 5) {

                ui->label_statusOfMove->setText("Draw");


                messageToServer = "22$" + userSign + "$draw";

            } else {
                ui->label_statusOfMove->setText("Your oponent moving");
                messageToServer = "22$" + userSign;
            }}

            arr.clear();
            arr.append(messageToServer);
            clientSocket->write(arr);

        }
    }


void MainWindow::on_pushButton_2_3_clicked()
{
    if(gameStarted && turn){
        if(!checkList[5]){
            turn = false;
            checkList[5] = true;
            ui->pushButton_2_3->setText(userSign);
            result = checkWin();
            countOfActivatedCells++;

            if (result){
                 ui->label_statusOfMove->setText("You win!");
                 messageToServer = "23$" + userSign + "$lose";

            } else if (countOfActivatedCells == 5) {

                ui->label_statusOfMove->setText("Draw");


                messageToServer = "23$" + userSign + "$draw";
            } else {
                ui->label_statusOfMove->setText("Your oponent moving");
                messageToServer = "23$" + userSign;
            }}

            arr.clear();
            arr.append(messageToServer);
            clientSocket->write(arr);

        }
    }


void MainWindow::on_pushButton_3_1_clicked()
{
    if(gameStarted && turn){
        if(!checkList[6]){
            turn = false;
            checkList[6] = true;
            ui->pushButton_3_1->setText(userSign);
            result = checkWin();
            countOfActivatedCells++;

            if (result){
                 ui->label_statusOfMove->setText("You win!");
                 messageToServer = "31$" + userSign + "$lose";

            } else if (countOfActivatedCells == 5) {

                ui->label_statusOfMove->setText("Draw");


                messageToServer = "31$" + userSign + "$draw";
            } else {
                ui->label_statusOfMove->setText("Your oponent moving");
                messageToServer = "31$" + userSign;
            }}

            arr.clear();
            arr.append(messageToServer);
            clientSocket->write(arr);

        }
    }


void MainWindow::on_pushButton_3_2_clicked()
{
    if(gameStarted && turn){
        if(!checkList[7]){
            turn = false;
            checkList[7] = true;
            ui->pushButton_3_2->setText(userSign);
            result = checkWin();
            countOfActivatedCells++;

            if (result){
                 ui->label_statusOfMove->setText("You win!");
                 messageToServer = "32$" + userSign + "$lose";

            } else if (countOfActivatedCells == 5) {

                ui->label_statusOfMove->setText("Draw");

                messageToServer = "32$" + userSign + "$draw";

            } else {
                ui->label_statusOfMove->setText("Your oponent moving");
                messageToServer = "32$" + userSign;
            }}

            arr.clear();
            arr.append(messageToServer);
            clientSocket->write(arr);

        }
    }


void MainWindow::on_pushButton_3_3_clicked()
{
    if(gameStarted && turn){
        if(!checkList[8]){
            turn = false;
             checkList[8] = true;
             ui->pushButton_3_3->setText(userSign);
            result = checkWin();
            countOfActivatedCells++;

            if (result){
                 ui->label_statusOfMove->setText("You win!");
                 messageToServer = "33$" + userSign + "$lose";

            } else if (countOfActivatedCells == 5) {

                ui->label_statusOfMove->setText("Draw");


                messageToServer = "33$" + userSign + "$draw";
            } else {
                ui->label_statusOfMove->setText("Your oponent moving");
                messageToServer = "33$" + userSign;
            }}

            arr.clear();
            arr.append(messageToServer);
            clientSocket->write(arr);
        }
    }


void MainWindow::on_pushButton_exit_clicked()
{
    this->close();
}
