#include "core.h"

#pragma region: ID
namespace id{

	unsigned int generate_unique_id()
	{
		unsigned int id;
		srand(time(0));

		for (int i = 0; i < 5; i++) {
			id << (1 + (rand() % 50));
		};
		std::cout << "ID Generated: " << id << std::endl;
		return id;
	};

	id::ID* create_id(
		unsigned int raw_id = NULL,
		workorder::WorkOrder* work_order = nullptr,
		customer::Customer* customer = nullptr,
		note::Note* note = nullptr
	)
	{
		id::ID* new_id;

		if (raw_id == NULL) {
			raw_id = id::generate_unique_id();
		};
		new_id->raw_id = raw_id;
		new_id->customer = customer;
		new_id->work_order = work_order;
		new_id->note = note;

		id::existing_ids.push_back(new_id);
		return new_id;
	};

	id::ID* from_raw_id(unsigned int raw_id) {
		for (id::ID* current_id : id::existing_ids) {
			if (current_id->raw_id == raw_id) {
				return current_id;
			}
		};
		return NULL;
	}

	nlohmann::json existing_as_json() {
		nlohmann::json j;


		std::vector<unsigned int> raw_ids;
		for (id::ID* id : id::existing_ids) {
			raw_ids.push_back(id->raw_id);
		};

		j = nlohmann::json{
			{"existing_ids", raw_ids}
		};
		return j;
	};

	int existing_from_json(nlohmann::json j) {
		for (unsigned int raw_id : j["existing_ids"]) {
			id::ID* current_id = id::create_id(static_cast<unsigned int>(raw_id), nullptr, nullptr, nullptr);
		};
		return 0;
	};
};

#pragma endregion

customer::Customer* customer::create_customer(std::string name, std::string phone_number, std::string email, unsigned int id )
{
	if (phone_number == "" && email == "") {
		return nullptr;
	};
	customer::Customer* cus = new customer::Customer;
	cus->name = name;
	cus->number = phone_number;
	cus->email = email;

	if (id == NULL) {
		id = id::generate_unique_id();
	};
	cus->id = id;

	return cus;
}

note::Note* note::create_note(
	std::string content, 
	workorder::WorkOrder* work_order, 
	customer::Customer* customer, 
	unsigned int id,
	std::string timestr
)
{
	if (work_order == nullptr && customer == nullptr) {
		return nullptr;
	};

	time_t t = time(NULL);
	struct tm* date;
	date = gmtime(&t);
	
	if (timestr.empty()) {
		timestr = asctime(date);
	};

	note::Note* n = new note::Note;
	n->timestr = timestr;
	n->content = content;

	if (work_order != nullptr) {
		work_order->notes.push_back(n);
	};
	if (customer != nullptr) {
		customer->notes.push_back(n);
	};

	if (id == NULL) {
		id = id::generate_unique_id();
	};
	n->id = id;
	return n;
}

workorder::WorkOrder* create_work_order(customer::Customer* customer, std::string device, std::string description, float price, unsigned int id)
{
	if (price < 0) {
		return nullptr;
	};
	workorder::WorkOrder* work_order = new workorder::WorkOrder;

	work_order->customer = customer;
	work_order->device = device;
	work_order->description = description;
	work_order->price = price;

	if (id == NULL) {
		id = id::generate_unique_id();
	};
	work_order->id = id;
	return work_order;
};


nlohmann::json note::to_json(note::Note* note) {
	nlohmann::json j;
	j = nlohmann::json{ {"asctime", note->asctime}, {"id", note->id}, {"content", note->content} };
	return j;
};

note::Note* note::from_json(nlohmann::json j) {
	note::Note* n = note::create_note(
		j["content"],
		nullptr,
		nullptr,
		j["id"],
		j["asctime"]
	)
	n->timestr = j["asctime"];
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
	workorder::Workorder* n = workorder::create_work_order(
	
	);
	n->asctime = j["asctime"];
	n->content = j["content"];
	return n;
};

