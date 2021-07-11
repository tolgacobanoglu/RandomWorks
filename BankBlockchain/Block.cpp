#include "Block.h"

Block::Block(unsigned int blockIndex, std::string hashOfData) : index(blockIndex) , dataHash(hashOfData)
{
}

std::string Block::getHash()
{
    return dataHash;
}

std::string Block::infoBlock()
{
    return getHash()+","+previousHash+","+std::to_string(index);
}