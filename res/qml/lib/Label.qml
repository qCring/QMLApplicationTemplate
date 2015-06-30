import QtQuick 2.4

Text
{
	id: label;

	FontLoader  { id: loader; source: "../../font/roboto/Roboto-Regular.ttf"; }
	FontLoader  { source: "../../font/roboto/Roboto-Thin.ttf"; }
	FontLoader  { source: "../../font/roboto/Roboto-Light.ttf"; }
	FontLoader  { source: "../../font/roboto/Roboto-Medium.ttf"; }
	FontLoader  { source: "../../font/roboto/Roboto-Bold.ttf"; }
	FontLoader  { source: "../../font/roboto/Roboto-Black.ttf"; }

	elide: 					Text.ElideRight;
	textFormat: 			Text.PlainText;
	style: 					Text.Normal;
	color: 					"#44333333"
	font.family: 			loader.name;
	font.pixelSize:			12;
	verticalAlignment: 		Text.AlignVCenter;
}
