#pragma once

#include <QObject>
#include <QDebug>

class Worker : public QObject {
Q_OBJECT
public slots:
    void process() {
        qDebug() << "Processing...";
        emit finished();
    }
signals:
    void finished();
};
