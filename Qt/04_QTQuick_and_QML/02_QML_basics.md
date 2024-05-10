### 4.2: QML Basics

**Basic Elements**
QML uses a hierarchy of elements, with properties and behaviors, to create UIs.
- **Properties:** Deﬁne the characteristics of QML elements.
- **Signals and Handlers:** React to events like user interaction.

**Key Concepts and Usage**
- **Property Bindings:** Dynamically link properties to maintain consistency between values.
- **JavaScript Integration:** Use JavaScript for handling complex logic.

#### Property Bindings

Property bindings are one of the core concepts in Qt Quick, which allow properties of QML elements to be dynamically linked together. This mechanism ensures that when one property changes, any other properties that are bound to it are automatically updated to reflect the new value. This feature is crucial for maintaining consistency across the UI without needing to manually synchronize values.
-   **Automatic Updates**: When you use property bindings, changes to one property automatically propagate to any other properties that depend on it. This reduces the amount of code needed to update the UI in response to data changes.
-   **Declarative Syntax**: Property bindings are expressed declaratively. You specify the relationship between properties directly in the QML code, which makes the dependencies clear and the code easier to maintain.

**Example of Property Bindings:**
```
import QtQuick 2.0

Rectangle {
    width: 200
    height: width / 2  // Binding height to be always half of width

    Text {
        text: "Width is " + parent.width  // Text updates automatically when rectangle's width changes
        anchors.centerIn: parent
    }
}
``` 

In this example, the `height` of the rectangle is bound to its `width`, ensuring that the height is always half the width, and the text displays the current width, updating automatically when the width changes.

#### JavaScript Integration

Qt Quick integrates JavaScript to handle complex logic that goes beyond simple property bindings. This allows for more sophisticated data processing, event handling, and interaction within QML applications, tapping into the full potential of a mature scripting language.
-   **Handling Complex Logic**: JavaScript can be used in QML to perform calculations, manipulate data, and handle complex decision-making processes within the UI.
-   **Event Handling**: JavaScript functions can be connected to signals in QML, providing a way to respond to user interactions or other events in a dynamic manner.

**Example of JavaScript Integration:**
```
import QtQuick 2.0

Rectangle {
    id: rect
    width: 200; height: 200
    color: "blue"

    MouseArea {
        anchors.fill: parent
        onClicked: {
            rect.color = (rect.color === "blue" ? "green" : "blue")  
            // Toggle color between blue and green
        }
    }
}
```

In this example, a `MouseArea` is used to handle mouse clicks on the rectangle. The `onClicked` handler contains JavaScript code that toggles the rectangle's color between blue and green.

**Example:** Creating a dynamic UI with property bindings.

```
import QtQuick 2.15 
 
Rectangle { 
    width: 200; height: 200 
    color: "blue" 
 
    Text { 
        text: "Click me!" 
        anchors.centerIn: parent 
        MouseArea { 
            anchors.fill: parent 
            onClicked: parent.color = "red" 
        } 

    } 
} 
```
```
#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
```
