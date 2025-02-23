#include "nlohmann/json.hpp"
#include <datetimeapi.h>
#include <ctime>
#include <chrono>




std::string write_json(nlohmann::json j, std::string filepath);


nlohmann::json read_json(std::string filepath);


struct Note {
	std::string asctime;
	std::string content;
};

struct Customer {
	std::string name;
	std::string number="";
	std::string email = "";
	std::vector<Note*> notes = {};
};

struct WorkOrder {
	Customer* customer;
	std::string device;
	std::string description;
	float price;
	std::vector<Note*> notes = {};

};

Customer* create_customer(std::string name, std::string phone_number, std::string email = "");

Note* create_note(std::string content, WorkOrder* work_order= nullptr, Customer* customer=nullptr);

WorkOrder* create_work_order(Customer* customer, std::string device, std::string description, float price);
