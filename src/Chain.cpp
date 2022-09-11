#include "Chain.hpp"

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <sstream>

namespace CRYPTO_ {

    Chain::Chain() {

        std::ifstream ifs("index");

        if(ifs.is_open()) {

            std::string index_ = "";

            while(std::getline(ifs, index_)) {
                
                this->index = index_;
            }
        }
    }

    Chain::~Chain() {}

};