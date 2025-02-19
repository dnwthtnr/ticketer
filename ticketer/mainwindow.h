#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "QtWidgets/qapplication.h"
#include "QtWidgets/qwidget.h"
#include "QtWidgets/qlayout.h"
#include "QtWidgets/qpushbutton.h"
#include "QtWidgets/qlabel.h"
#include "QtWidgets/qlineedit.h"





struct Customer {
	std::string name;
	std::string number;
	std::string email;
};


struct Note {
	std::string content;
};

struct WorkOrder {
	Customer* customer;
	std::string device;
	std::string description;
	float price;
	std::vector<Note> notes = {};

};

QWidget* generate_form_line();

QWidget* generate_ticket_form();

QWidget* generate_ticket_view();

int open_win(int argc, char* argv[]);
