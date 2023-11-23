#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtWidgets_Projet.h"
#include <qtcpsocket.h>
#include <qtcpserver.h>

class QtWidgets_Projet : public QMainWindow
{
    Q_OBJECT

public:
    QtWidgets_Projet(QWidget *parent = nullptr);
    ~QtWidgets_Projet();

private:
    Ui::QtWidgets_ProjetClass ui;
    QTcpSocket* socket;
    QTcpServer* server;

public slots:
    void OnDisplayMessageButtonClicked();
    void OnConnectButtonClicked();

    void OnSocketConnected();
    void OnSocketDisconnected();
    void OnSendMessageButtonClicked();
    void OnSocketReadyRead();

    void OnServerNewConnection();
    void OnClientDisconnected();
    void OnClientReadyRead();
};
