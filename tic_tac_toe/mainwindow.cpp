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
    for (int i = 1; i < 4; i++){
        for(int j = 1; j < 4; j++){
            checkList[QString(i)+QString(j)] = false;
        }
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
        checkList["11"] = true;
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
        checkList["12"] = true;
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
        checkList["13"] = true;
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
        checkList["21"] = true;
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
        checkList["22"] = true;
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
        checkList["23"] = true;
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
        checkList["31"] = true;
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
        checkList["32"] = true;
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
        checkList["33"] = true;
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
        clearButtons();
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
        gameStarted  = true;
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
    for (int i = 1; i < 4; i++){
        for(int j = 1; j < 4; j++){
            checkList[QString(i)+QString(j)] = false;
        }
    }
    result = false;
    turn = false;
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
    if (!winsRows[0] && checkList["11"] && checkList["12"] && checkList["13"]){
        first = ui->pushButton_1_1->text();
        second = ui->pushButton_1_2->text();
        third = ui->pushButton_1_3->text();
        winsRows[0] = true;
        if(first == second && first == third){
            return true;
        }
    }
    if (!winsRows[1] && checkList["21"] && checkList["22"] && checkList["23"]){
        first = ui->pushButton_2_1->text();
        second = ui->pushButton_2_2->text();
        third = ui->pushButton_2_3->text();
        winsRows[1] = true;
        if(first == second && first == third){
            return true;
        }
    }
    if (!winsRows[2] && checkList["31"] && checkList["32"] && checkList["33"]){
        first = ui->pushButton_3_1->text();
        second = ui->pushButton_3_2->text();
        third = ui->pushButton_3_3->text();
        winsRows[2] = true;
        if(first == second && first == third){
            return true;
        }
    }
    if (!winsRows[3] && checkList["11"] && checkList["21"] && checkList["31"]){
        first = ui->pushButton_1_1->text();
        second = ui->pushButton_2_1->text();
        third = ui->pushButton_3_1->text();
        winsRows[3] = true;
        if(first == second && first == third){
            return true;
        }
    }
    if (!winsRows[4] && checkList["12"] && checkList["22"] && checkList["32"]){
        first = ui->pushButton_1_2->text();
        second = ui->pushButton_2_2->text();
        third = ui->pushButton_3_2->text();
        winsRows[4] = true;
        if(first == second && first == third){
            return true;
        }
    }
    if (!winsRows[5] && checkList["13"] && checkList["23"] && checkList["33"]){
        first = ui->pushButton_1_3->text();
        second = ui->pushButton_2_3->text();
        third = ui->pushButton_3_3->text();
        winsRows[5] = true;
        if(first == second && first == third){
            return true;
        }
    }
    if (!winsRows[6] && checkList["11"] && checkList["22"] && checkList["33"]){
        first = ui->pushButton_1_1->text();
        second = ui->pushButton_2_2->text();
        third = ui->pushButton_3_3->text();
        winsRows[6] = true;
        if(first == second && first == third){
            return true;
        }
    }
    if (!winsRows[7] && checkList["13"] && checkList["22"] && checkList["31"]){
        first = ui->pushButton_1_3->text();
        second = ui->pushButton_2_2->text();
        third = ui->pushButton_3_1->text();
        winsRows[7] = true;
        if(first == second && first == third){
            return true;
        }
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
        if(!checkList["11"]){
            turn = false;
             checkList["11"] = true;
            result = checkWin();
            countOfActivatedCells++;
             ui->pushButton_1_1->setText(userSign);
            if (result){
                 ui->label_statusOfMove->setText("You win!");
                 messageToServer = "11$" + userSign + "$lose";
            } else if (countOfActivatedCells == 9) {

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
        if(!checkList["12"]){
            turn = false;
            checkList["12"] = true;
            result = checkWin();
            countOfActivatedCells++;
             ui->pushButton_1_2->setText(userSign);
            if (result){
                 ui->label_statusOfMove->setText("You win!");
                 messageToServer = "12$" + userSign + "$lose";
                 clearButtons();
            } else if (countOfActivatedCells == 9) {

                ui->label_statusOfMove->setText("Draw");
                clearButtons();

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
        if(!checkList["13"]){
            turn = false;
             checkList["13"] = true;
            result = checkWin();
            countOfActivatedCells++;
             ui->pushButton_1_3->setText(userSign);
            if (result){
                 ui->label_statusOfMove->setText("You win!");
                 messageToServer = "13$" + userSign + "$lose";
                 clearButtons();
            } else if (countOfActivatedCells == 9) {

                ui->label_statusOfMove->setText("Draw");
                clearButtons();

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
        if(!checkList["21"]){
            turn = false;
            checkList["21"] = true;
            result = checkWin();
            countOfActivatedCells++;
             ui->pushButton_2_1->setText(userSign);
            if (result){
                 ui->label_statusOfMove->setText("You win!");
                 messageToServer = "21$" + userSign + "$lose";
                 clearButtons();
            } else if (countOfActivatedCells == 9) {

                ui->label_statusOfMove->setText("Draw");
                clearButtons();

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
        if(!checkList["22"]){
            turn = false;
             checkList["22"] = true;
            result = checkWin();
            countOfActivatedCells++;
             ui->pushButton_2_2->setText(userSign);
            if (result){
                 ui->label_statusOfMove->setText("You win!");
                 messageToServer = "22$" + userSign + "$lose";
                 clearButtons();
            } else if (countOfActivatedCells == 9) {

                ui->label_statusOfMove->setText("Draw");
                clearButtons();

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
        if(!checkList["23"]){
            turn = false;
            checkList["23"] = true;
            result = checkWin();
            countOfActivatedCells++;
             ui->pushButton_2_3->setText(userSign);
            if (result){
                 ui->label_statusOfMove->setText("You win!");
                 messageToServer = "23$" + userSign + "$lose";
                 clearButtons();
            } else if (countOfActivatedCells == 9) {

                ui->label_statusOfMove->setText("Draw");
                clearButtons();

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
        if(!checkList["31"]){
            turn = false;
            checkList["31"] = true;
            result = checkWin();
            countOfActivatedCells++;
             ui->pushButton_3_1->setText(userSign);
            if (result){
                 ui->label_statusOfMove->setText("You win!");
                 messageToServer = "31$" + userSign + "$lose";
                 clearButtons();
            } else if (countOfActivatedCells == 9) {

                ui->label_statusOfMove->setText("Draw");
                clearButtons();

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
        if(!checkList["32"]){
            turn = false;
            checkList["32"] = true;
            result = checkWin();
            countOfActivatedCells++;
             ui->pushButton_3_2->setText(userSign);
            if (result){
                 ui->label_statusOfMove->setText("You win!");
                 messageToServer = "32$" + userSign + "$lose";
                 clearButtons();
            } else if (countOfActivatedCells == 9) {

                ui->label_statusOfMove->setText("Draw");

                messageToServer = "32$" + userSign + "$draw";
                clearButtons();
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
        if(!checkList["33"]){
            turn = false;
             checkList["33"] = true;
            result = checkWin();
            countOfActivatedCells++;
             ui->pushButton_3_3->setText(userSign);
            if (result){
                 ui->label_statusOfMove->setText("You win!");
                 messageToServer = "33$" + userSign + "$lose";
                 clearButtons();
            } else if (countOfActivatedCells == 9) {

                ui->label_statusOfMove->setText("Draw");
                clearButtons();

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
