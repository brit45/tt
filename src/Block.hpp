#ifndef __CRYPTO_BLOCK_HPP__
#define __CRYPTO_BLOCK_HPP__

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <cmath>
#include <map>
#include "Transaction.hpp"

namespace CRYPTO_ {

    

    class Block {

        public:

            Block();
            ~Block();

            void Init();

            void Genesis();
            void Save();

            void addTransaction(std::string to, std::string from, double ammount);

        private:

            std::vector<Transaction*> tx;

            std::string Hash, Prev;

            u_long Nonce = 320;
    };

};


#endif //! __CRYPTO_BLOCK_HPP__