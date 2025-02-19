#include "nlohmann/json.hpp"




std::string write_json(nlohmann::json j, std::string filepath);


nlohmann::json read_json(std::string filepath);
