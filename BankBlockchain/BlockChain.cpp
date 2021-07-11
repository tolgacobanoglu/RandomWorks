#include "BlockChain.h"

BlockChain::BlockChain()
{
    chain.emplace_back(Block(0,"00000000000000000000000000000000")); // add genesis block
}

void BlockChain::addBlock(Block block) //add new block to chain
{
    block.previousHash=getLastBlockHash(); //to set to block's previous hash of last block of chai
    chain.push_back(block); //add to chain
}

std::string BlockChain::getLastBlockHash() //to take last block's of chain's hash
{
    return chain.back().getHash();
}