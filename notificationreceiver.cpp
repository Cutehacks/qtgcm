#include "notificationreceiver.h"

#ifdef Q_OS_ANDROID
#include "androidnotificationreceiver.h"
#endif

#include <QDebug>

NotificationReceiver::NotificationReceiver(QObject *parent) :
    QObject(parent)
{
}

void NotificationReceiver::init()
{
#ifdef Q_OS_ANDROID
    if (!m_gcmSenderId.isEmpty()) {
        if (m_gcmRegistrationId.isEmpty()) {
            AndroidNotificationReceiver::instance()->doRegister(this, m_gcmSenderId);
        } else {
            // ?
        }
    }
#endif
}

void NotificationReceiver::setGcmSenderId(const QString &senderId)
{
    if (m_gcmSenderId == senderId)
        return;

    m_gcmSenderId = senderId;
    emit gcmSenderIdChanged(senderId);
}

void NotificationReceiver::setGcmRegistrationId(const QString &registrationId)
{
    if (m_gcmRegistrationId == registrationId)
        return;

    m_gcmRegistrationId = registrationId;
    emit gcmRegistrationIdChanged(registrationId);
}
