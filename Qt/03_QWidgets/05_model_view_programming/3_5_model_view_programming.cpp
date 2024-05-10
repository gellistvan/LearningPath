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