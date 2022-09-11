#ifndef __CRYPTO_CHAIN_HPP__
#define __CRYPTO_CHAIN_HPP__

#include <iostream>
#include <boost/serialization/base_object.hpp>

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "Block.hpp"

namespace CRYPTO_ {

    class Chain {

        public:

            Chain();
            ~Chain();

            void addTransaction(std::string to, std::string from, double ammount);
            
        private:
        
           

            // LISTE DES BLOCKS DE TRANSACTIONS
            std::vector<Block> block;

            // LISTE DES NOMS DE BLOCK PAR ORDRE NUMÉRIQUE 
            std::string index;
    };

    // BOOST_CLASS_VERSION(Chain, 1)
    // BOOST_CLASS_VERSION(Chain::load, 1)
};

#endif //! __CRYPTO_CHAIN_HPP__