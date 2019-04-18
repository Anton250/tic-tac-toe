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
        checkList["11"] = true;
        return 0;
    }
    pos = str_answer.find("12$");
    if(pos != std::string::npos){
        ui->pushButton_1_2->setText(XorO(str_answer));
        checkList["12"] = true;
        return 0;
    }
    pos = str_answer.find("13$");
    if(pos != std::string::npos){
        ui->pushButton_1_3->setText(XorO(str_answer));
        checkList["13"] = true;
        return 0;
    }
    pos = str_answer.find("21$");
    if(pos != std::string::npos){
        ui->pushButton_2_1->setText(XorO(str_answer));
        checkList["21"] = true;
        return 0;
    }
    pos = str_answer.find("22$");
    if(pos != std::string::npos){
        ui->pushButton_2_2->setText(XorO(str_answer));
        checkList["22"] = true;
        return 0;
    }
    pos = str_answer.find("23$");
    if(pos != std::string::npos){
        ui->pushButton_2_3->setText(XorO(str_answer));
        checkList["23"] = true;
        return 0;
    }
    pos = str_answer.find("31$");
    if(pos != std::string::npos){
        ui->pushButton_3_1->setText(XorO(str_answer));
        checkList["31"] = true;
        return 0;
    }
    pos = str_answer.find("32$");
    if(pos != std::string::npos){
        ui->pushButton_3_2->setText(XorO(str_answer));
        checkList["32"] = true;
        return 0;
    }
    pos = str_answer.find("33$");
    if(pos != std::string::npos){
        ui->pushButton_3_3->setText(XorO(str_answer));
        checkList["33"] = true;
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
        gameStarted  = true;
         ui->Game->show();
         ui->label_status->setText("Game started!");
        if (str_answer == "X"){
            ui->label_textSign->setText("Your sign is X");
            userSign = "X";
        } else {
            ui->label_textSign->setText("Your sign is O");
            userSign = "O";
        }

        return 0;
    }
    pos = str_answer.find("$lose");
    if(pos != std::string::npos){
        ui->label_status->setText("You lose.");
        return 0;
    }
    pos = str_answer.find("$draw");
    if(pos != std::string::npos){
        ui->label_status->setText("Draw.");
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
    clientSocket->connectToHost("192.168.1.66", 6000);
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

}

QString MainWindow::XorO(std::string str)
{
    if (str.find("X") != std::string::npos){
        return "X";
    } else {

        return "O";
}}


void MainWindow::on_pushButton_1_1_clicked()
{
    if(gameStarted){
        if(!checkList["11"]){
            ui->pushButton_1_1->setText(userSign);
            checkList["11"] = true;
            messageToServer = "11$" + userSign;
            arr.clear();
            arr.append(messageToServer);
            clientSocket->write(arr);
        }
    }
}

void MainWindow::on_pushButton_1_2_clicked()
{
    if(gameStarted){
        if(!checkList["12"]){
            ui->pushButton_1_2->setText(userSign);
            checkList["12"] = true;
            messageToServer = "12$" + userSign;
            arr.clear();
            arr.append(messageToServer);
            clientSocket->write(arr);
        }
    }
}

void MainWindow::on_pushButton_1_3_clicked()
{
    if(gameStarted){
        if(!checkList["13"]){
            ui->pushButton_1_3->setText(userSign);
            checkList["13"] = true;
            messageToServer = "13$" + userSign;
            arr.clear();
            arr.append(messageToServer);
            clientSocket->write(arr);
        }
    }
}

void MainWindow::on_pushButton_2_1_clicked()
{
    if(gameStarted){
        if(!checkList["21"]){
            ui->pushButton_2_1->setText(userSign);
            checkList["21"] = true;
            messageToServer = "21$" + userSign;
            arr.clear();
            arr.append(messageToServer);
            clientSocket->write(arr);
        }
    }
}

void MainWindow::on_pushButton_2_2_clicked()
{
    if(gameStarted){
        if(!checkList["22"]){
            ui->pushButton_2_2->setText(userSign);
            checkList["22"] = true;
            messageToServer = "22$" + userSign;
            arr.clear();
            arr.append(messageToServer);
            clientSocket->write(arr);
        }
    }
}

void MainWindow::on_pushButton_2_3_clicked()
{
    if(gameStarted){
        if(!checkList["23"]){
            ui->pushButton_2_3->setText(userSign);
            checkList["23"] = true;
            messageToServer = "23$" + userSign;
            arr.clear();
            arr.append(messageToServer);
            clientSocket->write(arr);
        }
    }
}

void MainWindow::on_pushButton_3_1_clicked()
{
    if(gameStarted){
        if(!checkList["31"]){
            ui->pushButton_3_1->setText(userSign);
            checkList["31"] = true;
            messageToServer = "31$" + userSign;
            arr.clear();
            arr.append(messageToServer);
            clientSocket->write(arr);
        }
    }
}

void MainWindow::on_pushButton_3_2_clicked()
{
    if(gameStarted){
        if(!checkList["32"]){
            ui->pushButton_3_2->setText(userSign);
            checkList["32"] = true;
            messageToServer = "32$" + userSign;
            arr.clear();
            arr.append(messageToServer);
            clientSocket->write(arr);
        }
    }
}

void MainWindow::on_pushButton_3_3_clicked()
{
    if(gameStarted){
        if(!checkList["33"]){
            ui->pushButton_3_3->setText(userSign);
            checkList["33"] = true;
            messageToServer = "33$" + userSign;
            arr.clear();
            arr.append(messageToServer);
            clientSocket->write(arr);
        }
    }
}

void MainWindow::on_pushButton_exit_clicked()
{
    this->close();
}
