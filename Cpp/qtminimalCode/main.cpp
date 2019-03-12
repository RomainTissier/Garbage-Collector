#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <iostream>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QWidget myWidget;

	myWidget.resize(75, 15);

	QLabel *hello = new QLabel(&myWidget);
	hello->setText("Hello world !");

	myWidget.show();

	return app.exec();
}
