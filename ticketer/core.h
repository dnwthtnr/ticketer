#include "nlohmann/json.hpp"
#include <datetimeapi.h>
#include <ctime>
#include <chrono>




std::string write_json(nlohmann::json j, std::string filepath);


nlohmann::json read_json(std::string filepath);








namespace data {

	std::vector<Note*> notes;
	std::vector<WorkOrder*> workorders;
	std::vector<Customer*> customers;

};




namespace note {

	struct Note {
		std::string asctime;
		std::string content;
		unsigned int id;
	};
	Note* create_note(std::string content, WorkOrder* work_order = nullptr, Customer* customer = nullptr);

	nlohmann::json to_json(Note* note);
	Note* from_json(nlohmann::json j);
};

namespace customer {

	struct Customer {
		std::string name;
		std::string number = "";
		std::string email = "";
		std::vector<Note*> notes = {};
		unsigned int id;
	};
	Customer* create_customer(std::string name, std::string phone_number, std::string email = "");

	nlohmann::json to_json(Customer* note);
	Customer* from_json(nlohmann::json j);
};

namespace workorder {

	struct WorkOrder {
		Customer* customer;
		std::string device;
		std::string description;
		float price;
		std::vector<Note*> notes = {};
		unsigned int id;

	};
	WorkOrder* create_work_order(Customer* customer, std::string device, std::string description, float price);

	nlohmann::json to_json(WorkOrder* workorder);
	WorkOrder* from_json(nlohmann::json j);
}
