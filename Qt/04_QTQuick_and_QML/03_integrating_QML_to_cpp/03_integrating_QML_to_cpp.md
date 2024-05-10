### 4.3: Integrating C++ with QML

**Overview**
Combining QML with C++ enables leveraging the power of C++ for backend logic while using QML for the frontend.
- **Exposing C++ Objects to QML:** Use `QQmlContext` to make C++ objects available in QML. 
- **Calling C++ Functions from QML:** Enhance interaction capabilities.

**Key Concepts and Usage**
- **Registering Types:** Use `qmlRegisterType()` to make custom C++ types available in QML.

#### 1. Exposing C++ Objects to QML

To make C++ objects available in QML, you can use the `QQmlContext` class. This class provides the environment in which QML expressions are evaluated. By setting properties on the `QQmlContext`, you can expose C++ objects to QML, allowing QML code to interact with them.
**Example:**
Here's how you might expose a C++ object to QML:
```
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>

class MyObject : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged)
public:
    explicit MyObject(QObject *parent = nullptr) : QObject(parent), m_message("Hello from C++!") {}

    QString message() const { return m_message; }
    void setMessage(const QString &message) {
        if (m_message != message) {
            m_message = message;
            emit messageChanged();
        }
    }

signals:
    void messageChanged();

private:
    QString m_message;
};

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    MyObject myObject;

    // Expose the MyObject instance to QML
    engine.rootContext()->setContextProperty("myObject", &myObject);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
``` 

In your QML file, you can now access `myObject`:
```
import QtQuick 2.0
import QtQuick.Controls 2.0

ApplicationWindow {
    visible: true
    width: 400
    height: 300
    title: qsTr("Hello World")

    Text {
        text: myObject.message
        anchors.centerIn: parent
    }
}
```

#### 2. Calling C++ Functions from QML
You can enhance the interaction capabilities of your QML UI by calling C++ functions directly from QML. This is typically done by exposing C++ methods as public slots or Q_INVOKABLE functions.

#### Example:
Modify the `MyObject` class to include a callable function:
```
class MyObject : public QObject {
    Q_OBJECT
public:
    Q_INVOKABLE void updateMessage(const QString &newMessage) {
        setMessage(newMessage);
    }
    // Existing code...
};
```
Now, you can call this method from QML:
```
Button {
    text: "Update Message"
    onClicked: myObject.updateMessage("Updated from QML!")
}
``` 

#### 3. Registering Custom C++ Types in QML
To use custom C++ types as QML types, you can register them using `qmlRegisterType()`. This allows you to instantiate your C++ classes as QML objects.
**Example:**
Here's how you might register a custom type and use it directly in QML:
```
#include <QtQuick>

class MyCustomType : public QObject {
    Q_OBJECT
public:
    MyCustomType() {}
};

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    qmlRegisterType<MyCustomType>("com.mycompany", 1, 0, "MyCustomType");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}
``` 
In your QML file, you can instantiate `MyCustomType`:
```
import QtQuick 2.0
import com.mycompany 1.0

MyCustomType {
    // Properties and methods of MyCustomType can be used here
}
```

**Example:** Exposing a C++ class to QML.

```
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext> 
 
class Backend : public QObject { 
    Q_OBJECT 
    Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged)
public: 
    QString userName() const { return m_userName; } 
    void setUserName(const QString &userName) { 
        if (m_userName == userName) 
            return; 
        m_userName = userName; 
        emit userNameChanged(); 
    } 
signals: 
    void userNameChanged(); 
private: 
    QString m_userName; 
}; 
 
int main(int argc, char *argv[]) { 
    QGuiApplication app(argc, argv); 
    QQmlApplicationEngine engine; 
 
    Backend backend; 
    engine.rootContext()->setContextProperty("backend", &backend); 
 
    const QUrl url(QStringLiteral("qrc:/main.qml")); 
    engine.load(url); 
 
    return app.exec(); 
} 
```
