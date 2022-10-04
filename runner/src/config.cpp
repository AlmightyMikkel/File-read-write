#include "config.h"

bool Config::load(const std::string& filename) {
	config_stream.open(filename);
	if (!config_stream.is_open()) {
		return false;
	} 
	return true;
}


bool Config::contains(const std::string& key) const
{

	return false;
}

bool Config::as_int(const std::string& key, int& value) const {
	int file_value;
	
	return false;
}

bool Config::as_float(const std::string& key, float& value) const {
	float file_value;
	
	return false;
}

bool Config::as_string(const std::string& key, std::string& value) const {
	std::string file_value;
	
	return false;
}

