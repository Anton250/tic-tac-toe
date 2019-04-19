#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMap>
#include <QVector>
#include <Windows.h>

class MyServer : public QObject
{
    Q_OBJECT
public:
    explicit MyServer(QObject *parent = nullptr);
    void slotNewConnection();
    void slotReadClient();
    void slotClientDisconnected();
signals:

private:
    QTcpServer * MyTcpServer;
    int serverStatus;
    QMap<int, QTcpSocket *> SClients;
    QMap<QTcpSocket *,QTcpSocket *> SRooms;
    QTcpSocket * WaitingUser;
    int count_of_users=0;
public slots:
};

#endif // MYSERVER_H
