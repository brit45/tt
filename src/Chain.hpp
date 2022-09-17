#ifndef __CRYPTO_CHAIN_HPP__
#define __CRYPTO_CHAIN_HPP__

#include <iostream>
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

            void load_Block();

            void create_ticket_dir();
            
        private:
        
           

            // LISTE DES BLOCKS DE TRANSACTIONS
            std::vector<Block> block;

            // LISTE DES NOMS DE BLOCK PAR ORDRE NUMÉRIQUE 
            std::string index;
            std::string CURRENT;
            std::string TICKET;
            std::string local = std::getenv("HOME");
    };

    // BOOST_CLASS_VERSION(Chain, 1)
    // BOOST_CLASS_VERSION(Chain::load, 1)
};

#endif //! __CRYPTO_CHAIN_HPP__