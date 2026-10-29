#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QGraphicsScene scene(0, 0, 800, 400);
    QGraphicsView view(&scene);
    view.setWindowTitle("Practica 5 - Parte 2");
    view.show();

    return app.exec();
}
