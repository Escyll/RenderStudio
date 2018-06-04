import QtQuick 2.10
import QtQuick.Window 2.3
import QtQuick.Controls 2.3
import QtQuick.Controls.Material 2.3
import QtQuick.Layouts 1.3
import QtQml.StateMachine 1.0

Rectangle {
    id: sceneView
    property StudioStateMachine studioStateMachine

    color: Qt.darker(Material.background)

    Component {
        id: renderingView
        Item {
            Pane {
                anchors.centerIn: parent
                RowLayout {
                    BusyIndicator {
                        running: true
                    }
                    Label {
                        Layout.alignment: Qt.AlignVCenter
                        text: qsTr("Rendering image")
                    }
                }
            }
        }
    }

    Component {
        id: editView
        EditView {}
    }

    Component {
        id: renderView
        RenderView {}
    }

    Loader {
        id: sceneViewLoader
        anchors.fill: parent
        sourceComponent: {
            if (studioStateMachine.editting) {
                editView
            } else if (studioStateMachine.rendering) {
                renderingView
            } else if (studioStateMachine.viewingRender) {
                renderView
            } else if (studioStateMachine.emptyActive) {
                undefined
            }
        }
    }
}
