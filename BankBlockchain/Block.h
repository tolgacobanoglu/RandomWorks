#ifndef BANKBLOCKCHAIN_BLOCK_H
#define BANKBLOCKCHAIN_BLOCK_H

#include <iostream>

class Block
{
    public:

    Block(unsigned int blockIndex,std::string hashOfData);//constructor for new Block
    std::string getHash();
    std::string previousHash;
    std::string infoBlock(); // to test program work or not

    private:

    unsigned int index; //index of block
    std::string dataHash;   //hash of withdraw transaction

};

#endif //BANKBLOCKCHAIN_BLOCK_H