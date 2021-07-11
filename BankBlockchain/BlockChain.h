#ifndef BANKBLOCKCHAIN_BLOCKCHAIN_H
#define BANKBLOCKCHAIN_BLOCKCHAIN_H

#include <cstdint>
#include <vector>
#include "Block.h"

class BlockChain
{
    public:
    BlockChain();
    void addBlock(Block);

    private:
    std::vector<Block> chain;
    std::string getLastBlockHash();

};

#endif //BANKBLOCKCHAIN_BLOCKCHAIN_H