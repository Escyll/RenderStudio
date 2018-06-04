import QtQuick 2.10
import QtQuick.Window 2.3
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

Pane {
    id: settingsPane
    property StudioStateMachine studioStateMachine

    Component {
        id: cameraSettingsComponent
        CameraSettings {
            id: cameraSettings
            studioStateMachine: settingsPane.studioStateMachine
        }
    }

    Loader {
        id: settingsLoader
        anchors.fill: parent
        sourceComponent: applicationService.project != null ? cameraSettingsComponent : undefined
    }
}
