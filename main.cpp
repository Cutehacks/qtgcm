#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include "notificationreceiver.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<NotificationReceiver>(
                "com.cutehacks.notifications",
                1, 0, "NotificationReceiver");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
