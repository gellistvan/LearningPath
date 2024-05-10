### 4.4: Using Standard Components

QML's standard components cover a wide range of UI elements:
-   **Interactive Elements**: Such as `Button`, `CheckBox`, `RadioButton`, and `Slider`, which allow users to perform actions and make selections.
-   **Input Fields**: Including `TextField`, `TextArea`, which are used for entering and editing text.
-   **Display Containers**: Such as `ListView`, `GridView`, and `StackView`, which organize content in various layouts.

Among these, `ListView`, `GridView`, and `Repeater` are particularly important for handling dynamic data sets.

**Model-View-Delegate Architecture**
This architecture is a cornerstone of QML's approach to displaying collections of data:
-   **Model**: This is the data source that holds the data items to be displayed. In QML, models can be simple list models provided in QML itself, or more complex models backed by C++.
-   **View**: The view presents the data from the model to the user. The view itself does not contain logic for item layout or how the data should be formatted; it merely uses the delegate to create a visual representation of each item. `ListView` and `GridView` are examples of views.
-   **Delegate**: This is a template for creating items in the view. Each item in the view is instantiated from the delegate, which defines how each data item should be displayed.

#### Example: Using ListView with a Model and Delegate
Let's consider an example where we use a `ListView` to display a list of names. We'll use a simple ListModel as our data source, and a Component to define how each item should look.

```
import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 300
    title: "ListView Example"

    ListView {
        width: 200; height: 250
        anchors.centerIn: parent

        model: ListModel {
            ListElement { name: "Alice" }
            ListElement { name: "Bob" }
            ListElement { name: "Carol" }
            ListElement { name: "Dave" }
        }

        delegate: Rectangle {
            width: 180; height: 40
            color: "lightblue"
            radius: 5
            margin: 5
            Text {
                text: name
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 10
            }
        }
    }
}
``` 

**How It Works:**
-   **ListView**: The `ListView` is set up with a fixed size and centered in the application window.
-   **Model**: The `ListModel` contains several `ListElement` items, each with a `name` property.
-   **Delegate**: The delegate is a `Rectangle` that represents each item. Inside the rectangle, a `Text` element displays the name. The delegate is styled with a light blue background and rounded corners.
