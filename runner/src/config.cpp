#include "config.h"

bool Config::load(const std::string& filename) {
	config_file.open(filename);
	if (!config_file.is_open()) {
		return false;
	} 
	return true;
}
//Testing if std::getline messes up because of function const; Answer: it does!
void Config::test() {
	if (!config_file.is_open())
	{

	}
	std::string content;
	while (!config_file.eof()) {
		std::getline(config_file, content);

	}
}

bool Config::contains(const std::string& key) const
{
	if (!config_file.is_open()) return false;
	std::string content;
	while (!config_file.eof()) {

		std::getline(&config_file, content); //Not sure if I can just dereference the file and it would work?

		if (content == key) {
			return true;
		}
	}
	return false;
}

bool Config::as_int(const std::string& key, int& value) const {
	int file_value;
	//find the key
	
	if(!config_file.is_open()) return false;
	std::string content;
	
	while (!config_file.eof()){
		
		std::getline(&config_file, content);
		if(content.find(key)){ //Do I have to dereference key?
			
			//Edit value in here
			value = file_value; //Overwrite where the reference "points" to
		}	
	}
	
	return false;
}

bool Config::as_float(const std::string& key, float& value) const {
	float file_value;
	//find the key
	
	if(!config_file.is_open()) return false;
	std::string content;
	
	while (!config_file.eof()){
		
		std::getline(&config_file, content);
		if(content.find(key)){ //Do I have to dereference key?
			
			//Edit value in here
			value = file_value; //Overwrite where the reference "points" to
		}	
	}
	
	return false;
}

bool Config::as_string(const std::string& key, std::string& value) const {
	std::string file_value;
	//find the key
	
	if(!config_file.is_open()) return false;
	std::string content;
	
	while (!config_file.eof()){
		
		std::getline(&config_file, content);
		if(content.find(key)){ //Do I have to dereference key?
			
			//Edit value in here
			value = file_value; //Overwrite where the reference "points" to
		}	
	}
	
	return false;
}

