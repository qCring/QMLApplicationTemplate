import QtQuick 2.4
import QtQuick.Window 2.2
import "../lib" as Lib

Rectangle
{
	id: root;

	width: Screen.width;
	height: Screen.height;
	color: "#aaa";

	Item
	{
		anchors.fill: parent;

		Rectangle
		{
			id: header;

			anchors.left: parent.left;
			anchors.right: parent.right;
			anchors.top: parent.top;
			height: 36;
			color: "#888"
		}

		Item
		{
			id: content;

			anchors.left: parent.left;
			anchors.right: parent.right;
			anchors.top: header.bottom;
			anchors.bottom: footer.top;

			clip: true;

			Lib.Icon
			{
				anchors.centerIn: parent;
				type: types.fa_compass;
				pixelSize: 120;
				color: "#ddd"
			}
		}

		Rectangle
		{
			id: footer;

			anchors.left: parent.left;
			anchors.right: parent.right;
			anchors.bottom: parent.bottom;
			height: 36;
			color: "#888"

			Lib.Label
			{
				id: labelBuild;

				anchors.right: parent.right;
				anchors.verticalCenter: parent.verticalCenter;
				anchors.rightMargin: 16;
				color: "#000"
				font.weight: Font.Bold;
				text: App.config.isRelease ? "release" : "debug";
			}

			Lib.Label
			{
				id: labelVersion;
				
				anchors.right: labelBuild.left;
				anchors.verticalCenter: parent.verticalCenter;
				text: "v: " + App.config.version + " - ";
				color: "#000";
				font.weight: Font.Light;
			}
		}
	}
}