#include <QDebug>

#include "notificationreceiver.h"
#include "androidnotificationreceiver.h"

Q_GLOBAL_STATIC(AndroidNotificationReceiver, androidReceiver)

AndroidNotificationReceiver::AndroidNotificationReceiver() :
    m_receiver(0)
{
    JNINativeMethod methods[] {
        {"handleRegisterId", "(Ljava/lang/String;)V", reinterpret_cast<void *>(&AndroidNotificationReceiver::registrationIdHandler)},
        {"handleRegisterError", "(Ljava/lang/String;)V", reinterpret_cast<void *>(&AndroidNotificationReceiver::registrationIdHandler)}
    };

    const char *className = "com/cutehacks/examples/qtgcm/RegisterTask";

    if (QAndroidJniObject::isClassAvailable(className)) {
        QAndroidJniObject javaClass(className);
        if (javaClass.isValid()) {
            QAndroidJniEnvironment env;
            jclass objectClass = env->GetObjectClass(javaClass.object<jobject>());
            env->RegisterNatives(objectClass,
                                 methods,
                                 sizeof(methods) / sizeof(methods[0]));
            env->DeleteLocalRef(objectClass);
        } else {
            qDebug() << className << "is not valid";
        }
    } else {
        qDebug() << className << "is not available";
    }
}

AndroidNotificationReceiver::~AndroidNotificationReceiver()
{
}

void AndroidNotificationReceiver::doRegister(NotificationReceiver *receiver, const QString &senderId)
{
    m_receiver = receiver;

    QAndroidJniObject jSenderId = QAndroidJniObject::fromString(senderId);
    QAndroidJniObject foo = QAndroidJniObject::callStaticObjectMethod(
                "com/cutehacks/examples/qtgcm/MainActivity",
                "registerGCM",
                "(Ljava/lang/String;)V",
                jSenderId.object<jstring>());
}

AndroidNotificationReceiver *AndroidNotificationReceiver::instance()
{
    return androidReceiver;
}

void AndroidNotificationReceiver::registrationIdHandler(JNIEnv *env, jobject thiz, jstring registrationId)
{
    Q_UNUSED(thiz)
    const char* nativeString = env->GetStringUTFChars(registrationId, 0);
    QString str = QString::fromUtf8(nativeString);
    env->ReleaseStringUTFChars(registrationId, nativeString);
    androidReceiver->m_receiver->setGcmRegistrationId(str);
}

void AndroidNotificationReceiver::errorHandler(JNIEnv *env, jobject thiz, jstring errorMessage)
{
    Q_UNUSED(thiz)
    const char* nativeString = env->GetStringUTFChars(errorMessage, 0);
    qWarning(nativeString);
    env->ReleaseStringUTFChars(errorMessage, nativeString);
}

