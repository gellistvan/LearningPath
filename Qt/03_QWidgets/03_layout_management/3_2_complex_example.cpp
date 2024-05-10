#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QCheckBox>
#include <QTextEdit>
#include <QDebug>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("User Details Form");

    // Create layouts
    QVBoxLayout *mainLayout = new QVBoxLayout();
    QFormLayout *formLayout = new QFormLayout();
    QHBoxLayout *checkboxLayout = new QHBoxLayout();
    QVBoxLayout *commentsLayout = new QVBoxLayout();
    QHBoxLayout *buttonLayout = new QHBoxLayout();

    // Form fields
    QLineEdit *nameLineEdit = new QLineEdit();
    QLineEdit *emailLineEdit = new QLineEdit();
    QLineEdit *ageLineEdit = new QLineEdit();
    formLayout->addRow("Name:", nameLineEdit);
    formLayout->addRow("Email:", emailLineEdit);
    formLayout->addRow("Age:", ageLineEdit);

    // Checkboxes
    QCheckBox *sportsCheckBox = new QCheckBox("Sports");
    QCheckBox *musicCheckBox = new QCheckBox("Music");
    checkboxLayout->addWidget(sportsCheckBox);
    checkboxLayout->addWidget(musicCheckBox);

    // Comments section
    QLabel *commentsLabel = new QLabel("Comments:");
    QTextEdit *commentsTextEdit = new QTextEdit();
    commentsLayout->addWidget(commentsLabel);
    commentsLayout->addWidget(commentsTextEdit);

    // Submit button
    QPushButton *submitButton = new QPushButton("Submit");
    buttonLayout->addWidget(submitButton);
    QObject::connect(submitButton, &QPushButton::clicked, [&](){
        qDebug() << "Name:" << nameLineEdit->text();
        qDebug() << "Email:" << emailLineEdit->text();
        qDebug() << "Age:" << ageLineEdit->text();
        qDebug() << "Interests:" << (sportsCheckBox->isChecked() ? "Sports" : "") << (musicCheckBox->isChecked() ? "Music" : "");
        qDebug() << "Comments:" << commentsTextEdit->toPlainText();
    });

    // Assemble the main layout
    mainLayout->addLayout(formLayout);
    mainLayout->addLayout(checkboxLayout);
    mainLayout->addLayout(commentsLayout);
    mainLayout->addLayout(buttonLayout);

    // Set the layout on the main window
    window.setLayout(mainLayout);
    window.show();

    return app.exec();
}
