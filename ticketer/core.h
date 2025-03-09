#include "nlohmann/json.hpp"
#include <datetimeapi.h>
#include <ctime>
#include <chrono>
#include <iostream>




std::string write_json(nlohmann::json j, std::string filepath);


nlohmann::json read_json(std::string filepath);







namespace data {

	std::vector<note::Note*> notes;
	std::vector<workorder::WorkOrder*> workorders;
	std::vector<customer::Customer*> customers;

};


namespace id {

	unsigned int generate_unique_id();

	std::vector<id::ID*> existing_ids;

	struct ID {
		unsigned int raw_id;
		workorder::WorkOrder* work_order = nullptr;
		customer::Customer* customer = nullptr;
		note::Note* note = nullptr;
	};

	id::ID* create_id(
		unsigned int raw_id = NULL,
		workorder::WorkOrder* work_order = nullptr,
		customer::Customer* customer = nullptr,
		note::Note* note = nullptr
	);

	id::ID* from_raw_id(unsigned int raw_id);
	int existing_from_json(nlohmann::json j);
	nlohmann::json existing_as_json();
}


namespace note {

	struct Note {
		std::string timestr;
		std::string content;
		unsigned int id;
	};
	Note* create_note(
		std::string content, 
		workorder::WorkOrder* work_order = nullptr,
		customer::Customer* customer = nullptr,
		unsigned int id = NULL,
		std::string timestr = NULL
	);

	nlohmann::json to_json(Note* note);
	Note* from_json(nlohmann::json j);
};

namespace customer {

	struct Customer {
		std::string name;
		std::string number = "";
		std::string email = "";
		std::vector<note::Note*> notes = {};
		unsigned int id;
	};
	Customer* create_customer(
		std::string name, 
		std::string phone_number, 
		std::string email = "", 
		unsigned int id=NULL
	);

	nlohmann::json to_json(Customer* note);
	Customer* from_json(nlohmann::json j);
};

namespace workorder {

	struct WorkOrder {
		customer::Customer* customer;
		std::string device;
		std::string description;
		float price;
		std::vector<note::Note*> notes = {};
		unsigned int id;

	};
	WorkOrder* create_work_order(
		customer::Customer* c,
		std::string device,
		std::string description,
		float price,
		unsigned int id = NULL
	);

	nlohmann::json to_json(WorkOrder* workorder);
	WorkOrder* from_json(nlohmann::json j);
}
