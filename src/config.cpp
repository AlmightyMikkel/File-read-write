#include "config.h"

//Add Const to all the for auto!

bool Config::load(const std::string& filename) {
	config_stream.open(filename);
	std::string content;
	size_t delimPos{};

	if (!config_stream.is_open()) {
		return false;
	} 

	while (!config_stream.eof()) {
		std::string key, value;
		std::getline(config_stream, content);
		
		delimPos = content.find(":");
		key = content.substr(0, delimPos);
		value = content.substr(delimPos + 1);
		
		config_container.insert({ key, value });
	}
	
	return true;

}

bool Config::contains(const std::string& key) const
{

	for (auto& pair : config_container) {

		if (pair.first == key) return true;
	}

	return false;
}

bool Config::as_int(const std::string& key, int& value) const {
		
	for (const auto& [_key, _value] : config_container) {

		if (_key == key) {
			value = std::stoi(_value);
			return true;
		}

	}

	return false;
}

bool Config::as_float(const std::string& key, float& value) const {


	for (const auto& [_key, _value] : config_container) {

		if (_key == key) {
			value = std::stof(_value);
			return true;
		}
	}

	return false;
	
}

bool Config::as_string(const std::string& key, std::string& value) const {


	for (const auto& [_key, _value] :config_container) {


		if (_key == key) {
			value = _value;
			return true;
		}

	}

	return false;
}

