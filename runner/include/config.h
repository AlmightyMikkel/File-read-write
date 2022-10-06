#include <fstream>
#include <string>
#include <unordered_map>


class Config {
public:
	Config() = default;
	bool load(const std::string& filename);
	bool contains(const std::string& key) const;
	bool as_int(const std::string& key, int& value) const;
	bool as_float(const std::string& key, float& value) const;
	bool as_string(const std::string& key, std::string& value) const;
private:
	std::ifstream config_stream;
	std::unordered_map<std::string, std::string> config_container;
};