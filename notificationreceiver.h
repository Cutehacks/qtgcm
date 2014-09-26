#ifndef NOTIFICATIONRECEIVER_H
#define NOTIFICATIONRECEIVER_H

#include <QObject>

class QQmlEngine;
class QJSEngine;

class NotificationReceiver : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString gcmSenderId READ gcmSenderId WRITE setGcmSenderId NOTIFY gcmSenderIdChanged)
    Q_PROPERTY(QString gcmRegistrationId READ gcmRegistrationId WRITE setGcmRegistrationId NOTIFY gcmRegistrationIdChanged)

public:
    explicit NotificationReceiver(QObject *parent = 0);

    QString gcmSenderId() const { return m_gcmSenderId; }
    QString gcmRegistrationId() const { return m_gcmRegistrationId; }

signals:
    void gcmSenderIdChanged(const QString &senderId);
    void gcmRegistrationIdChanged(const QString &registrationId);
    void gcmDeviceRegistered(const QString &);

public slots:
    void init();
    void setGcmSenderId(const QString &senderId);
    void setGcmRegistrationId(const QString &registrationId);

private:
    QString m_gcmSenderId;
    QString m_gcmRegistrationId;
};

#endif // NOTIFICATIONRECEIVER_H
