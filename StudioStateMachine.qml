import QtQuick 2.10
import QtQuick.Window 2.3
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import QtQml.StateMachine 1.0 as DSM

DSM.StateMachine {
    id: studioStateMachine
    initialState: emptyState
    Component.onCompleted: {
        studioStateMachine.start()
    }

    function startRendering() { renderingTimer.start() }
    function startEditing() { editScene() }
    signal renderingStarted()
    signal editScene()

    Timer {
        id: renderingTimer
        interval: 5000
        repeat: false
        running: false
    }

    property bool emptyActive: emptyState.active
    property bool editting: editState.active
    property bool rendering: renderingState.active
    property bool viewingRender: renderedState.active

    DSM.State {
        id: editState
        DSM.SignalTransition {
            targetState: renderingState
            signal: renderingTimer.runningChanged
            guard: renderingTimer.running
        }
        DSM.SignalTransition {
            targetState: emptyState
            signal: applicationService.projectChanged
            guard: applicationService.project == null
        }
    }
    DSM.State {
        id: renderingState
        DSM.SignalTransition {
            targetState: renderedState
            signal: renderingTimer.triggered
        }
        DSM.SignalTransition {
            targetState: emptyState
            signal: applicationService.projectChanged
            guard: applicationService.project == null
        }
    }
    DSM.State {
        id: renderedState
        DSM.SignalTransition {
            targetState: editState
            signal: studioStateMachine.editScene
        }
        DSM.SignalTransition {
            targetState: emptyState
            signal: applicationService.projectChanged
            guard: applicationService.project == null
        }
    }
    DSM.State {
        id: emptyState
        DSM.SignalTransition {
            targetState: editState
            signal: applicationService.projectChanged
            guard: applicationService.project != null
        }
    }
}
