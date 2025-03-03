#include "core.h"

customer::Customer* customer::create_customer(std::string name, std::string phone_number, std::string email)
{
	if (phone_number == "" && email == "") {
		return nullptr;
	};
	customer::Customer* cus = new customer::Customer*(name, phone_number, email);
	return cus;
}

note::Note* create_note(std::string content, workorder::WorkOrder* work_order, customer::Customer* customer)
{
	if (work_order == nullptr && customer == nullptr) {
		return nullptr;
	};

	time_t t = time(NULL);
	struct tm* date;
	date = gmtime(&t);

	std::string timestr = asctime(date);
	note::Note* note = new Note(timestr, content);
	return note;
}

workorder::WorkOrder* create_work_order(customer::Customer* customer, std::string device, std::string description, float price)
{
	if (price < 0) {
		return nullptr;
	};
	workorder::WorkOrder* work_order = new WorkOrder(
		customer,
		device,
		description,
		price
	);
	return work_order;
}


nlohmann::json note::to_json(note::Note* note) {
	nlohmann::json j;
	j = nlohmann::json{ {"asctime", note->asctime}, {"id", note->id}, {"content", note->content} };
	return j;
};

note::Note* note::from_json(nlohmann::json j) {
	note::Note* n;
	n->asctime = j["asctime"];
	n->content = j["content"];
	n->id = j["id"];
	return n;
};



nlohmann::json workorder::to_json(workorder::WorkOrder* workorder) {

	std::vector<unsigned int> noteids;
	for (note::Note* n : workorder->notes) {
		noteids.push_back(n->id);
	};

	nlohmann::json j;
	j = nlohmann::json{ 
		{"customer", workorder->customer->id}, 
		{"device", workorder->device}, 
		{"description", workorder->description}, 
		{"price", workorder->price},
		{"notes", noteids},
		{"id", workorder->id}
	};
	return j;
};

workorder::WorkOrder* workorder::from_json(nlohmann::json j) {
	note::Note* n;
	n->asctime = j["asctime"];
	n->content = j["content"];
	return n;
};

