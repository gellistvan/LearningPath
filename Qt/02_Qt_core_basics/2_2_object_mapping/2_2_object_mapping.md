### 2.2: Object Model (QObject and QCoreApplication)

`QObject` is the base class of all Qt objects and the core of the object model. It enables object communication via signals and slots, dynamic property system, and more.

**Key Properties and Usage:**

* `setParent()`, `parent()`: Manages object hierarchy and ownership.
* `setProperty()`, `property()`: Accesses properties deﬁned via the Q_PROPERTY macro.

`QCoreApplication` manages the application's control ﬂow and main settings, and it's necessary for applications that do not use the GUI.

**Example 1**: Deeper use of `QObject` and `QCoreApplication`:

```
#include <QCoreApplication>
#include <QObject> 
 
class Application : public QObject { 
    Q_OBJECT 
public: 
    Application(QObject *parent = nullptr) : QObject(parent) { 
        setProperty("Version", "1.0"); 
    } 
    void printVersion() { 

        qDebug() << "Application version:" << property("Version").toString(); 
    } 
}; 
 
int main(int argc, char *argv[]) { 
    QCoreApplication app(argc, argv); 
    Application myApp; 
    myApp.printVersion(); 
    return app.exec(); 
} 
```

**Example 2**: Creating a simple application with `QCoreApplication` and connecting a `QObject`'s signal to a
slot.

```
#include <QCoreApplication>
#include <QObject> 
 
class MyObject : public QObject { 
    Q_OBJECT 
public: 
    MyObject(QObject *parent = nullptr) : QObject(parent) {} 
signals: 
    void mySignal(); 
public slots: 
    void mySlot() { qDebug() << "Slot called"; } 
}; 
 
int main(int argc, char *argv[]) { 
    QCoreApplication app(argc, argv); 
    MyObject obj; 
    QObject::connect(&obj, &MyObject::mySignal, &obj, &MyObject::mySlot); 
    emit obj.mySignal(); 
    return app.exec(); 
}
```