#ifndef ANDROIDNOTIFICATIONRECEIVER_H
#define ANDROIDNOTIFICATIONRECEIVER_H

#include <QAndroidJniEnvironment>
#include <QAndroidJniObject>
#include <QGlobalStatic>

class NotificationReceiver;

class AndroidNotificationReceiver
{
public:
    AndroidNotificationReceiver();
    ~AndroidNotificationReceiver();
    void doRegister(NotificationReceiver *receiver, const QString& senderId);

    static AndroidNotificationReceiver *instance();
    static void registrationIdHandler(JNIEnv *env, jobject thiz, jstring registrationId);
    static void errorHandler(JNIEnv *env, jobject thiz, jstring errorMessage);

private:
    NotificationReceiver *m_receiver;
    QString m_senderId;

};

#endif // ANDROIDNOTIFICATIONRECEIVER_H
