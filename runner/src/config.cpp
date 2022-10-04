#include "config.h"

bool Config::load(const std::string& filename) {
	
	size_t delimPos{};
	std::string content;
	
	
	config_stream.open(filename);
	if (!config_stream.is_open()) {
		return false;
	} 
	
	while (!config_stream.eof()){
		
		Config_pair pair;
		
		std::getline(config_stream, content);
		

		delimPos = std::string.find(':');
		pair.key = content.substr(0, delimPos);
		pair.value = content.substr(delimPos + 1);
		
		config_container.insert({pair.key, pair.value});
		
		
	}
	
	
	return true;
}


bool Config::contains(const std::string& key) const
{

	return false;
}

bool Config::as_int(const std::string& key, int& value) const {
	
	for (auto& pair : config_container){
		if(pair.key == key){
			value = std::stoi(pair.value);
			return true;
		}
	}
	
	return false;
}

bool Config::as_float(const std::string& key, float& value) const {
	for (auto& pair : config_container){
		if(pair.key == key){
			value = std::stof(pair.value);
			return true;
		}
	}
	return false;
}

bool Config::as_string(const std::string& key, std::string& value) const {
	for (auto& pair : config_container){
		if(pair.key == key){
			value = spair.value;
			return true;
		}
	}
	return false;
}

