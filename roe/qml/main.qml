import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 2.0
import Qt.labs.settings 1.0


Window {
    id: mainWindow
    width: 420; height: 420
    visible: true
    color: "#212121"


    Settings {
        id: mainSettings
        property alias x: mainWindow.x
        property alias y: mainWindow.y
        property alias width: mainWindow.width
        property alias height: mainWindow.height
    }
}
