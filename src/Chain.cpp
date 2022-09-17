#include "Chain.hpp"

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <sstream>

namespace CRYPTO_ {

    Chain::Chain() {

        this->local.append("/.local/.cryto__/");

        std::ifstream ifs((this->local + "CURRENT"));

        if(ifs.is_open()) {

            std::string current_ = "";

            while(std::getline(ifs, current_)) {

                this->CURRENT = this->local + "block/"+ current_;

            }

            this->load_Block();
        }
        else {

            printf("[ SYS | \033[31mERR\033[0m ]\t - Problem with the blockchain system. ( .exit )\n");
            exit(1);
        }
    }

    Chain::~Chain() {}

    void Chain::load_Block() {

        this->TICKET = this->CURRENT + "/MANIFEST";

        std::ifstream ifs((this->TICKET));

        std::string MANIFEST;
        ifs >> MANIFEST;

        if(MANIFEST.empty()) {

            std::string hash;

            bool stop = true;
            while(stop) {
                
                if(hash.substr(0,1) == "0") {
                    
                    std::ofstream ofs(this->TICKET);
                    
                    printf("\n[ SYS | \033[35mINFO\033[0m ]\t - Generation of first block.\n");
                    
                    ofs << hash << "\n";                    
                    ofs.close();
                    
                    this->index = hash;

                    std::string link  = ("mkdir " + this->CURRENT + "/" + hash);
                    std::system(link.c_str());

                    this->create_ticket_dir();

                    stop = false;
                } 
                else {
                    hash = sha256(std::to_string(rand()% 2096 + time(NULL)));
                }
            }
        }
    }

    void Chain::create_ticket_dir() {

        std::vector<std::string> file;

        file.push_back("INDEX");
        file.push_back("INFO");

        for(auto f : file) {

            std::string link = (this->CURRENT+"/"+this->index+"/"); 
            std::ofstream ofs((link+f));
            
            if(f == "INFO") {
                ofs << "DATE " << time(NULL) << std::endl;
                ofs << "SIZE " << 0 << std::endl;
                ofs << "NONCE " << 0 << std::endl;
                ofs << "DIFF " << 1 << std::endl;
                ofs << "HASH " << this->index << std::endl;
                ofs << "PREV " << nullptr;
            }

            ofs.close();
        }

    }

};