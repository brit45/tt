#include "Transaction.hpp"

namespace CRYPTO_ {

    Transaction::Transaction(u_long nonce, std::string prev, std::string to, std::string from, double amount) {

        this->Data_.Nonce        = nonce;
        this->Data_.Prev         = prev;
        this->Data_.To           = to;
        this->Data_.From         = from;
        this->Data_.Amount       = amount;
        this->Data_.Timestamp    = time(NULL);
        this->Data_.Hash         = sha256(std::to_string(nonce) + prev + to + from + std::to_string(amount) + std::to_string(this->Data_.Timestamp));
    }

    Transaction::~Transaction() {}

    Data const Transaction::getData() const {

        return this->Data_;
    }

};