
### 3.5: Model-View Programming

**Overview**
Model-View programming separates the data (model) from the user interface (view), with an optional controller (delegate) to manage interaction between the model and view.

**Key Concepts**
* **QModel:** Deﬁnes the data to be displayed.
* **QView:** Presents the model's data to the user.
* **QDelegate:** Handles rendering and editing of the view's items.

**Example:** Using `QListView` and `QStringListModel`.

```
#include <QApplication>
#include <QStringListModel>
#include <QListView> 
 
int main(int argc, char *argv[]) { 
    QApplication app(argc, argv); 
    QStringList data; 
    data << "Item 1" << "Item 2" << "Item 3"; 
 
    QStringListModel model; 
    model.setStringList(data); 
 
    QListView view; 
    view.setModel(&model); 
    view.show(); 
 
    return app.exec(); 
} 
```
Each section of Chapter 3 provides a thorough exploration of the key components of GUI programming with QtWidgets, incorporating detailed examples that showcase practical application and eﬀective design patterns in Qt. This structure not only educates but also empowers students to build their own sophisticated Qt applications.
