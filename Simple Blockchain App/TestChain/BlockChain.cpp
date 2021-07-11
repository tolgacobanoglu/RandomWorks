#include "BlockChain.h"

BlockChain::BlockChain() // constructor
{
    chain.emplace_back(Block(0, "Genesis Block")); // add first block to chain (genesis)
    nDifficulty = 6;
}

void BlockChain::addBlock(Block block) //add method to chain
{
    block.previousHash = getLastBlock().getHash();
    block.MineBlock(nDifficulty);
    chain.push_back(block);
}

const Block BlockChain::getLastBlock()
{
    return chain.back();
}