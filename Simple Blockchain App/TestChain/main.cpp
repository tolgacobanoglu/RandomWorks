#include <iostream>
#include "BlockChain.h"

int main()
{
    BlockChain blockChain;

    blockChain.addBlock(Block(1,"data1"));
    blockChain.addBlock(Block(2,"data2"));
    blockChain.addBlock(Block(3,"data3"));

    return 0;
}
