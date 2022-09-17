#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include "Chain.hpp"
#include <random>

bool isDir_exist(std::string dir) {

    DIR* dirs = opendir(dir.c_str());
    
    if (dirs) {

        closedir(dirs);
        return true;
    } 

    return false;
}


void initStockage() {

    std::vector<std::string> list_file, list_dir;

    list_file.push_back(".cryto__/CURRENT");
    list_file.push_back(".cryto__/keyid");
    list_file.push_back(".cryto__/block/mainnet/MANIFEST");
    list_file.push_back(".cryto__/block/testnet/MANIFEST");
    list_file.push_back(".cryto__/block/devnet/MANIFEST");

    list_dir.push_back(".cryto__");
    list_dir.push_back(".cryto__/block");
    list_dir.push_back(".cryto__/block/mainnet");
    list_dir.push_back(".cryto__/block/testnet");
    list_dir.push_back(".cryto__/block/devnet");

    std::string local = getenv("HOME");
    local.append("/.local");

    for(auto dir : list_dir) {

        if(!isDir_exist(local + "/" + dir)) {

            std::string directory = "mkdir ";
            directory.append(local + "/" + dir);

            std::system(directory.c_str());
            printf("[ SYS | \033[32mMK\033[0m ]\t - Creation Directory ~> '\033[34m%s/%s\033[0m'\n", local.c_str(), dir.c_str());
        }
    }

    for(auto file : list_file) {

        std::ifstream ifs((local+"/"+file));

        if(!ifs.is_open()) {

            std::ofstream ofs(local+"/"+file);

            if(file == ".cryto__/CURRENT") {
                
                ofs << "mainnet";
            }

            ofs.close();
            printf("[ SYS | \033[32mMK\033[0m ]\t - Creation File ~> '\033[33m%s/%s\033[0m'\n", local.c_str(),file.c_str());
        }

        ifs.close();
    }



}

int main(void) {

    initStockage();
    srand(time(NULL));  

    CRYPTO_::Chain chain;
    
    return 0;
}