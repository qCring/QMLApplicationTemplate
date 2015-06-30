import QtQuick 2.4
import "Icons.js" as Icons
import "./" as Lib

Text
{
    id: root;

    property string type: "-";
    property var types: Icons.Icon;
    property int pixelSize: 14;

    FontLoader 
    {
        id: fontLoader;
        source: "../../font/font-awesome/fontawesome-webfont.ttf";
    }

    textFormat:             Text.PlainText;
    style:                  Text.Normal;
    color:                  "#fff"
    font.family:            fontLoader.name;
    verticalAlignment:      Text.AlignVCenter;
    text:                   root.type;
    font.pixelSize:         root.pixelSize;
}
