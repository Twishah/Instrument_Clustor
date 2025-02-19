import QtQuick 2.6
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.4

Rectangle {
    id: dateContainer

    property int index: 0               // index of this level
    property bool isCurrent: false      // when section selected and OK clicked, to navigate

    // DYNAMIC: regarding the next page (day setting)
    property var states: [dm.getPreHeatingDate(0), dm.getPreHeatingDate(1),
        dm.getPreHeatingDate(2), dm.getPreHeatingDate(3),
        dm.getPreHeatingDate(4), dm.getPreHeatingDate(5),
        dm.getPreHeatingDate(6)]

    width: parent.width
    height: 96
    color: parent.color

    function updateImageSources(index, value) {
        dateContainer.states[index] = value;

        for (var i = 0; i < 7; i++) {
            var image = row1.itemAt(i).children[0];
            image.source = dateContainer.states[i] ? "qrc:/graphics/PreHeatingSettings/7.81 Check mark - white.png" : "";
        }
    }

    Rectangle {
        id: levelRect

        width: 0.45 * parent.width
        height: 30
        color: levelsController.isCurrentIndex === index && pg_preHeating.layerdIndex === 0 ? color_blue : color_gray
        border {
            color: levelsController.isCurrentIndex === index && pg_preHeating.layerdIndex === 0  ? color_blue : color_gray_bar
            width: 2
        }
        anchors {
            leftMargin: 5
            left: parent.left
            topMargin: 5
            top: parent.top
        }

        Text {
            id: selectionLevelText
            color: color_white
            font.pixelSize: 14
            font.family: systemFont
            anchors {
                verticalCenter: parent.verticalCenter
                horizontalCenter: parent.horizontalCenter
            }
            text: qsTrId("LBL_0017") + translator.emptyString
        }
    }

    GridLayout {
       id: grid
       columns: 7
       rows: 2
       columnSpacing: 1
       rowSpacing: 1
        width: 216
        anchors {
            horizontalCenter: parent.horizontalCenter
            top: levelRect.bottom
            topMargin: 5
            bottom: parent.bottom
            bottomMargin: 14
        }

        // models
        property var titles: [ qsTrId("LBL_0043") + translator.emptyString, qsTrId("LBL_0044") + translator.emptyString, qsTrId("LBL_0045") + translator.emptyString,
           qsTrId("LBL_0046") + translator.emptyString, qsTrId("LBL_0047") + translator.emptyString, qsTrId("LBL_0048") + translator.emptyString, qsTrId("LBL_0049") + translator.emptyString ]
        property var colors: [color_white,color_white,color_white,color_white,color_white, color_blue, color_red ]

       Repeater {
           id: row0
           model: grid.titles
           Label {
               Layout.row: 0
               Layout.column: index
               Layout.fillWidth: true
               Layout.fillHeight: false
               text: modelData
               color: grid.colors[index]
               horizontalAlignment: Text.AlignHCenter
           }
       }

       Repeater {
           id: row1
           model: 7
           delegate: Rectangle {
               id: rec
               width: 30
               color: color_gray_bar
               Layout.row: 1
               Layout.column: index
               Layout.fillWidth: true
               Layout.fillHeight: true
               Image {
                   source: dateContainer.states[index] ? "qrc:/graphics/PreHeatingSettings/7.81 Check mark - white.png" : ""
                   fillMode: Image.Pad
                   visible: true
                   anchors {
                       horizontalCenter: rec.horizontalCenter
                       verticalCenter: rec.verticalCenter
                   }
               }
           }
       }
   }
}
