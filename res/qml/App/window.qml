import QtQuick 2.6

import Lib 1.0 as Lib

Rectangle {
    id: root;

    color: "#282C34"

    Column {
        anchors.centerIn: parent;

        Lib.Icon {
            type: types.fa_compass;
            pointSize: 80;
        }

        Lib.Label {
            font.pointSize: 24;
            anchors.horizontalCenter: parent.horizontalCenter;
            text: "App"
        }
    }
}
