#include "myserver.h"

MyServer::MyServer(QObject *parent) : QObject(parent)
{
    MyTcpServer = new QTcpServer(this);
        connect(MyTcpServer, &QTcpServer::newConnection, this, &MyServer::slotNewConnection);
        if (MyTcpServer->listen(QHostAddress::Any, 6000)) {
            serverStatus = 1;
            qDebug() << "Server is working";
        }


}

void MyServer::slotNewConnection()
{
    if (serverStatus == 1) {
            count_of_users++;
            QTcpSocket* clientSocket = MyTcpServer->nextPendingConnection();
            qDebug() << "New connection!" << clientSocket->peerAddress();
            int idusersocs = clientSocket->socketDescriptor();
            SClients[idusersocs] = clientSocket;
            connect(SClients[idusersocs], &QTcpSocket::readyRead, this, &MyServer::slotReadClient);
            connect(SClients[idusersocs], &QTcpSocket::disconnected, this, &MyServer::slotClientDisconnected);
            if(count_of_users % 2 == 0){
                SRooms[clientSocket] = WaitingUser;
                SRooms[WaitingUser] = clientSocket;
                QString answer1 = "startGame$X";
                QString answer2 = "startGame$O";
                QByteArray arr;
                arr.append(answer1);
                clientSocket->write(arr);
                arr.clear();
                arr.append(answer2);
                WaitingUser->write(arr);
                WaitingUser = nullptr;

            } else {
                WaitingUser = clientSocket;
                QString answer = "wait$";
                QByteArray arr;

                arr.append(answer);
                 qDebug() << arr << '\n';
                clientSocket->write(arr);


}}
        }



void MyServer::slotReadClient()
{
    QTcpSocket* clientSocket = (QTcpSocket*)sender();
    QTcpSocket* secondClient = SRooms[clientSocket];
    QByteArray arr;

    arr.clear();
    QString str = clientSocket->readAll();
    arr.append(str);
    qDebug() << str << '\n';
    if(str == "startGame!"){
            Sleep(2000);
            arr.clear();
            str = "startGame$X";
            arr.append(str);
            clientSocket->write(arr);
            arr.clear();
            str = "startGame$O";
    }


    arr.append(str);
    secondClient->write(arr);
}

void MyServer::slotClientDisconnected()
{
    QTcpSocket* clientSocket = (QTcpSocket*)sender();
        qDebug() << "User disconected!" << clientSocket->peerAddress();
        int idusersoc = clientSocket->socketDescriptor();
        count_of_users--;
        if (WaitingUser != clientSocket){
             QTcpSocket* secondClient = SRooms[clientSocket];
            if (count_of_users % 2 == 0){
                SRooms[secondClient] = WaitingUser;
                SRooms[WaitingUser] = clientSocket;
                QString answer1 = "startGame$X";
                QString answer2 = "startGame$O";
                QByteArray arr;
                arr.append(answer1);
                secondClient->write(arr);
                arr.clear();
                arr.append(answer2);
                WaitingUser->write(arr);
                WaitingUser = nullptr;

            } else {
                WaitingUser = secondClient;
                QString answer = "userDisconnected$";
                QByteArray arr;
                arr.append(answer);
                WaitingUser->write(arr);
            }
        } else {
            WaitingUser = nullptr;
        }
        SClients.remove(idusersoc);
        clientSocket->close();
}


