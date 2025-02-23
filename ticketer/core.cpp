#include "core.h"

Customer* create_customer(std::string name, std::string phone_number, std::string email)
{
	if (phone_number == "" && email == "") {
		return nullptr;
	};
	Customer* cus = new Customer(name, phone_number, email);
	return cus;
}

Note* create_note(std::string content, WorkOrder* work_order, Customer* customer)
{
	if (work_order == nullptr && customer == nullptr) {
		return nullptr;
	};

	time_t t = time(NULL);
	struct tm* date;
	date = gmtime(&t);

	std::string timestr = asctime(date);
	Note* note = new Note(timestr, content);
	return note;
}

WorkOrder* create_work_order(Customer* customer, std::string device, std::string description, float price)
{
	if (price < 0) {
		return nullptr;
	};
	WorkOrder* work_order = new WorkOrder(
		customer,
		device,
		description,
		price
	);
	return work_order;
}


nlohmann::json struct_to_json(auto data) {
	// way to agnostically serialize struct as json dict -- maybe go based off termination bits or something
}
