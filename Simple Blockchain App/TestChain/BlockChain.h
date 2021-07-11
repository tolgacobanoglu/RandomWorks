#ifndef TESTCHAIN_BLOCKCHAIN_H
#define TESTCHAIN_BLOCKCHAIN_H

#include <cstdint>
#include <vector>
#include "Block.h"

using namespace std;

class BlockChain
{
    public:
    BlockChain();
    void addBlock(Block block); // add new block function to chain(to vector)

    private:
    unsigned int nDifficulty;
    vector<Block> chain; // to link blocks each other

    const Block getLastBlock(); //const because want to be unconvertible
};

#endif //TESTCHAIN_BLOCKCHAIN_H
