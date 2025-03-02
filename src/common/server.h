// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef SERVER_H
#define SERVER_H

#include <QLockFile>
#include <QMetaType>
#include <QObject>

#include <memory>

class ClientSocket;
class QEventLoop;
class QLocalServer;

using ClientSocketPtr = std::shared_ptr<ClientSocket>;
Q_DECLARE_METATYPE(ClientSocketPtr)

class Server final : public QObject
{
    Q_OBJECT
public:
    explicit Server(const QString &name, QObject *parent = nullptr);

    ~Server();

    void start();

    bool isListening() const;

    void close();

signals:
    void newConnection(const ClientSocketPtr &socket);

private:
    void onNewConnection();
    void onSocketDestroyed();

    QLocalServer *m_server;
    QLockFile m_lockFile;
    int m_socketCount;
    QEventLoop *m_loop = nullptr;
};

#endif // SERVER_H
