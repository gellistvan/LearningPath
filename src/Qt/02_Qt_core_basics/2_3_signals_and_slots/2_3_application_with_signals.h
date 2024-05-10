#pragma once

#include <QObject>
#include <QDebug>

class MyObject : public QObject {
Q_OBJECT  // Required for any class that defines signals or slots
public:
    MyObject(QObject *parent = nullptr) : QObject(parent) {}
signals:
    void mySignal();
public slots:
    void mySlot() { qDebug() << "Slot called"; }
};
