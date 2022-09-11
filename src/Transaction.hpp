#ifndef __CRYPTO_TRANSACTION_HPP__
#define __CRYPTO_TRANSACTION_HPP__

#include <string>
#include <time.h>
#include "Sha256.hpp"
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/access.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

namespace CRYPTO_ {

    struct Data {
                
        u_long Nonce;

        double Amount;

        std::string To, From;

        std::string Prev, Hash;

        time_t Timestamp;
    };

    class Transaction {

        public:

            Transaction(u_long nonce, std::string prev, std::string to, std::string from, double amount);
            ~Transaction();

            Data const getData() const;
        
        private:

        Data Data_;           
    };

};

#endif //! __CRYPTO_TRANSACTION_HPP__