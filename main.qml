import QtQuick 2.10
import QtQuick.Window 2.3
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import QtQml.StateMachine 1.0

ApplicationWindow {
    visible: true
    visibility: ApplicationWindow.Maximized
    flags: Qt.Window | Qt.FramelessWindowHint
    width: 640
    height: 480
    title: qsTr("Hello World")

    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")
            Action {
               text: qsTr("&New...")
               onTriggered: applicationService.newProject()
            }
            Action {
               text: qsTr("&Open...")
               onTriggered: applicationService.loadProject("myProject.rsproj")
            }
            Action {
               text: qsTr("&Save")
               onTriggered: applicationService.saveProject("myProject.rsproj")
            }
            Action {
               text: qsTr("&Save as...")
               onTriggered: applicationService.saveProject("myProject.rsproj")
            }
            Action {
                text: qsTr("&Close")
                onTriggered: applicationService.closeProject()
            }

            MenuSeparator {}
            Action {
                text: qsTr("&Quit")
                onTriggered: Qt.quit()
            }
        }
    }

    RowLayout {
        id: rootView
        anchors.fill: parent
        Layout.fillHeight: true
        StudioStateMachine {
            id: studioStateMachineInstance
        }
        SceneView {
            id: sceneView
            Layout.fillHeight: true
            Layout.fillWidth: true
            studioStateMachine: studioStateMachineInstance
        }
        SettingsPane {
            id: settingsPane
            Layout.fillHeight: true
            Layout.preferredWidth: 450
            studioStateMachine: studioStateMachineInstance
        }
    }
}

