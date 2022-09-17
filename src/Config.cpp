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

auto Config::get(std::string key) const {

    if(this->registre[key] == "map_int") {
        
        return this->map_int[key];
    }
    else if(this->registre[key] == "map_bool") {
        
        return this->map_bool[key];
    }
    else if(this->registre[key] == "map_string") {
        
        return this->map_string[key];
    }

    return  false;
}