

### 4.5: Developing Custom Components

**Custom Components**
Creating custom components in QML allows for reusable and encapsulated UI functionality.
Creating a Custom Component: Typically involves deﬁning a new QML ﬁle.

**Key Concepts and Usage**
**Reusability:** Design components to be reusable across diﬀerent parts of applications.

**Example:** Creating a custom button component.

```
// Save as MyButton.qml import QtQuick 2.15 
 
Rectangle { 
    width: 100; height: 40 
    color: "green" 
    radius: 5 
 
    Text { 
        text: "Button" 
        anchors.centerIn: parent 
        color: "white" 
    } 
 
    MouseArea { 
        anchors.fill: parent 
        onClicked: console.log("Button clicked") 
    } 
} 
```
Usage:

```
import QtQuick 2.15 
import QtQuick.Controls 2.15 
 
ApplicationWindow { 
    visible: true 
    width: 400 
    height: 300 
 
    MyButton { 
        anchors.centerIn: parent 
    } 
} 
```
