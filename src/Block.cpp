#include "Block.hpp"
#include <sys/stat.h>
#include "Config.hpp"

bool IsPathExist(const std::string &s) {
    struct stat buffer;
    return (stat (s. c_str(), &buffer) == 0);
}

namespace CRYPTO_ {

    Block::Block() {}

    Block::~Block() {

        printf("\n");

        this->Save();

        for(auto t: this->tx) {

            printf("-\tDelete Cache TX id : %s\n", t->getData().Hash.substr(0,11).c_str());
            delete t;
        }
    }

    void Block::Init() {

        if(this->tx.size() < 1) {
            
            this->Genesis();
        }

        for(u_int i = 0; i < 1000; i++) {

            this->addTransaction("marvin", "pierre", rand()%100);
        }
    }

    void Block::Genesis() {

        printf("Create Genesis ...");
        this->Prev = sha256("0x0");
        this->Hash = sha256("0x0");
        this->tx.push_back(new Transaction(0x0,this->Prev,"0x0","0x0",0x0));
        system("sleep 2");
        printf("\rCreate Genesis [ \033[32mOk\033[0m ]\n");
    }

    void Block::Save() {

        std::ofstream ofs("BLK_000.ldb");

        for(auto t : this->tx) {

            ofs << t->getData().Timestamp << " " << t->getData().Nonce << " " << t->getData().To << " " << t->getData().Amount << " " << t->getData().From << " " << t->getData().Prev << " " << t->getData().Hash << "\n";
        }

        ofs.close();
    }

    void Block::addTransaction(std::string to, std::string from, double ammount) {

        this->Nonce = time(NULL) * 1000 / rand()%3600;

        std::string h = this->tx[this->tx.size()-1]->getData().Hash;

        this->tx.push_back(new Transaction(this->Nonce,h,to,from,ammount));
    }

};