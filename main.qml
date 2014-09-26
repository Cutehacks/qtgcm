import QtQuick 2.2
import QtQuick.Controls 1.2
import com.cutehacks.notifications 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    NotificationReceiver {
        id: notificationReceiver
        gcmSenderId: "738724701239"

        function showRequestInfo(text) {
            console.log(text)
        }

        Component.onCompleted: {
            init();
        }

        onGcmRegistrationIdChanged: {
            console.log(gcmRegistrationId);

            var req = new XMLHttpRequest();
            req.onreadystatechange = function() {
                if (req.readyState == XMLHttpRequest.HEADERS_RECEIVED) {
                    showRequestInfo("Headers -->");
                    showRequestInfo(req.getAllResponseHeaders ());
                    showRequestInfo("Last modified -->");
                    showRequestInfo(req.getResponseHeader ("Last-Modified"));
                } else if (req.readyState == XMLHttpRequest.DONE) {
                    console.log(req.responseText);
                    var a = req.responseXML.documentElement;
                    for (var ii = 0; ii < a.childNodes.length; ++ii) {
                        showRequestInfo(a.childNodes[ii].nodeName);
                    }
                    showRequestInfo("Headers -->");
                    showRequestInfo(req.getAllResponseHeaders ());
                    showRequestInfo("Last modified -->");
                    showRequestInfo(req.getResponseHeader ("Last-Modified"));
                }
            }

            var data = {
                user: "user1",
                type: "android",
                token: gcmRegistrationId
            };

            req.open("POST", "http://192.168.0.7:8000/subscribe");
            req.setRequestHeader("Content-Type", "application/json;charset=UTF-8");
            req.send(JSON.stringify(data));
        }
    }

    Text {
        text: notificationReceiver.gcmRegistrationId
        anchors.centerIn: parent
    }
}
