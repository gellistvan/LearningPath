#pragma once
#include <QString>
#include <QObject>
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