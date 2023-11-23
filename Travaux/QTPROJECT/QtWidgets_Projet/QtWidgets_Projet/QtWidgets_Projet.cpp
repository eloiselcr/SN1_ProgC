#include "QtWidgets_Projet.h"

QtWidgets_Projet::QtWidgets_Projet(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    socket = new QTcpSocket(this);
    QObject::connect(socket, SIGNAL(connected()), this, SLOT(OnSocketConnected()));
    QObject::connect(socket, SIGNAL(disconnected()), this, SLOT(OnSocketDisconnected()));
    QObject::connect(socket, SIGNAL(readyRead()), this, SLOT(OnSocketReadyRead()));

    server = new QTcpServer(this);
    QObject::connect(server, SIGNAL(newConnection()), this, SLOT(OnServerNewConnection()));
    server->listen(QHostAddress::AnyIPv4, 4321);
}

QtWidgets_Projet::~QtWidgets_Projet()
{}

void QtWidgets_Projet::OnDisplayMessageButtonClicked()
{
    ui.label->setText("Antibes !");
}

void QtWidgets_Projet::OnConnectButtonClicked()
{
    QString ip = ui.IPLineEdit->text();
    QString port = ui.portLineEdit->text();

    bool ok;
    int portAsInt = port.toInt(&ok);
    if (ok)
    {
        socket->connectToHost(ip, portAsInt);
    }
}

void QtWidgets_Projet::OnSocketConnected()
{
    ui.connectionStatusLabel->setText("Status connexion : Connecte");
}

void QtWidgets_Projet::OnSocketDisconnected()
{
    ui.connectionStatusLabel->setText("Status connexion : Deconnecte");
}

void QtWidgets_Projet::OnSendMessageButtonClicked()
{
    socket->write("Hello server !\n");
}

void QtWidgets_Projet::OnSocketReadyRead()
{
    // ui.connectionStatusLabel->setText("Status connexion : des donnees ont ete recues depuis le serveur !");
    QByteArray data = socket->read(socket->bytesAvailable());
    QString str(data);
    ui.connectionStatusLabel->setText("Status connexion : Message recu = " + str);
}

void QtWidgets_Projet::OnServerNewConnection()
{
    ui.connectionStatusLabel->setText("Un client s'est connecte");
    QTcpSocket* client = server->nextPendingConnection();
    QObject::connect(client, SIGNAL(readyRead()), this, SLOT(OnClientReadyRead()));
    QObject::connect(client, SIGNAL(disconnected()), this, SLOT(OnClientDisconnected()));
}

void QtWidgets_Projet::OnClientDisconnected()
{
    QTcpSocket* obj = qobject_cast<QTcpSocket*>(sender());
    QObject::connect(obj, SIGNAL(readyRead()), this, SLOT(OnClientReadyRead()));
    QObject::connect(obj, SIGNAL(disconnected()), this, SLOT(OnClientDisconnected()));
    obj->deleteLater();
}

void QtWidgets_Projet::OnClientReadyRead()
{
    QTcpSocket* obj = qobject_cast<QTcpSocket*>(sender());
    QByteArray coucou = obj->read(obj->bytesAvailable());
    QString str(coucou);
    ui.connectionStatusLabel->setText("Status connexion : Message recu = " + str);
    obj->write(coucou);
}

