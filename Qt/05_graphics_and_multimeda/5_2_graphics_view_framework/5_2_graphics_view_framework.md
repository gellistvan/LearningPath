

### 5.2: Graphics View Framework
**Overview**
The Graphics View Framework is designed to manage and interact with a large number of custom 2D graphical items within a scrollable and scalable view.
* **QGraphicsScene:** Manages a collection of graphical items. It is an invisible container that can be viewed through one or more views.
* **QGraphicsView:** Provides a widget for displaying the contents of a QGraphicsScene.
* **QGraphicsItem:** Base class for all graphics items in a scene.

**Example:** Creating a simple scene with a rectangle and ellipse.

```
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem> 
 
int main(int argc, char *argv[]) { 
    QApplication app(argc, argv); 
 
    QGraphicsScene scene; 
    scene.addItem(new QGraphicsRectItem(0, 0, 100, 100)); 
    scene.addItem(new QGraphicsEllipseItem(100, 100, 50, 50)); 
 
    QGraphicsView view(&scene); 
    view.setRenderHint(QPainter::Antialiasing); 
    view.show(); 
 

    return app.exec(); 
} 
```