#include "config.h"

//I want to implement throw expections

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
		

		delimPos = content.find(':');
		pair.key = content.substr(0, delimPos);
		pair.value = content.substr(delimPos + 1);
		
		config_container.insert({pair.key, pair.value});
		
	}
	
	//Should I check the size of the stream and compare it to the container? Would the size be the same if everything got correctly "transfered"?
	return true;
}


bool Config::contains(const std::string& key) const {
	for (auto& pair : config_container) {
		if(pair.first == key) return true;
	}
	return false;
}

bool Config::as_int(const std::string& key, int& value) const {
	
	for (auto& pair : config_container){
		if(pair.first == key){
			value = std::stoi(pair.second);
			return true;
		}
	}
	
	return false;
}

bool Config::as_float(const std::string& key, float& value) const {
	for (auto& pair : config_container){
		if(pair.first == key){
			value = std::stof(pair.second);
			return true;
		}
	}
	return false;
}

bool Config::as_string(const std::string& key, std::string& value) const {
	for (auto& pair : config_container){
		if(pair.first == key){
			value = spair.second;
			return true;
		}
	}
	return false;
}

