#include "Config.hpp"

Config::Config() {}

Config::~Config() {}

void Config::add(std::string key, int val) {

    this->registre[key] = "map_int";
    this->map_int[key]  = val;
}

void Config::add(std::string key, std::string val) {

    this->registre[key] = "map_string";
    this->map_string[key] = val;
}

void Config::add(std::string key, bool val) {

    this->registre[key] = "map_bool";
    this->map_bool[key]  = val;
}

template<typename T>
T Config::get(std::string key) {

    if(this->registre[key] == "map_int") {
        
        return (T) this->map_int[key];
    }
    else if(this->registre[key] == "map_bool") {
        
        return (T) this->map_bool[key];
    }
    else if(this->registre[key] == "map_string") {
        
        return (T) this->map_string[key];
    }

    return 0;
}