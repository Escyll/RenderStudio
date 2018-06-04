import QtQuick 2.10
import QtQuick.Window 2.3
import QtQuick.Controls 2.3
import QtQuick.Controls.Material 2.3
import QtQuick.Layouts 1.3

ColumnLayout {
    id: renderSettings
    property StudioStateMachine studioStateMachine
    ColumnLayout {
        Layout.alignment: Qt.AlignTop
        width: parent.width
        Label {
            Layout.alignment: Qt.AlignHCenter
            color: Material.accent
            text: qsTr("Camera Settings")
        }
        RowLayout {
            width: parent.width
            CheckBox {
                Layout.fillWidth: true
                text: qsTr("Anti aliasing")
                checked: applicationService.project != null ? applicationService.project.renderSettings.antiAliasing : false
                onClicked: applicationService.project.renderSettings.antiAliasing = !applicationService.project.renderSettings.antiAliasing
            }
        }
        RowLayout {
            width: parent.width
            spacing: 16
            Label {
                Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                text: qsTr("Focal distance:")
            }
            TextField {
                Layout.alignment: Qt.AlignRight
                Layout.fillWidth: true
                text: "3 m"
                onAccepted: print("Accepted") // Do something
                Keys.onEscapePressed: {
                    focus = false
                }
            }
        }
    }
    Button {
        Layout.alignment: Qt.AlignBottom | Qt.AlignHCenter
        text: if (studioStateMachine.editting) {
                  "Render scene"
              } else {
                  "Edit scene"
              }
        visible: !studioStateMachine.rendering
        onClicked: studioStateMachine.editting
                   ? studioStateMachine.startRendering()
                   : studioStateMachine.startEditing()
    }
}
