#ifndef __CRYPTO_CONFIG_HPP__
#define __CRYPTO_CONFIG_HPP__

#include <map>
#include <string>

class Config {

    public:
        Config();
        virtual ~Config();

        void add(std::string key, int val);
        void add(std::string key, std::string val);
        void add(std::string key, bool val);

        auto get(std::string key) const;
    
    protected:

        std::map<std::string, int> map_int;

        std::map<std::string, std::string> map_string;

        std::map<std::string, bool> map_bool;

        std::map<std::string, std::string> registre;


};

#endif //! __CRYPTO_CONFIG_HPP__