#pragma once

#include "mainwindow.h"

QWidget* generate_form_line() {

	QWidget* widget = new QWidget();
	QHBoxLayout* layout = new QHBoxLayout();
	widget->setLayout(layout);

	QLineEdit* input_line = new QLineEdit();

	QLabel* title_label = new QLabel();
	title_label->setText("test");
	layout->addWidget(title_label);
	layout->addWidget(input_line);
	return widget;
};

QWidget* generate_ticket_view() {
	QWidget* widget = new QWidget();
	QVBoxLayout* layout = new QVBoxLayout();
	widget->setLayout(layout);

	return widget;

};

QWidget* generate_ticket_form() {
	QWidget* widget = new QWidget();
	QVBoxLayout* layout = new QVBoxLayout();
	widget->setLayout(layout);
	
	QWidget* test_line = generate_form_line();
	layout->addWidget(test_line);

	return widget;
};


int open_win(int argc, char* argv[])
{

	QApplication app(argc, argv);

	QWidget win;

	QPushButton* test = new QPushButton("hello world");
	test->setText("hello world");
	QVBoxLayout* layout = new QVBoxLayout();

	QWidget* line = generate_ticket_form();

	layout->addWidget(line);
	win.setLayout(layout);
	win.show();



	return app.exec();
}
