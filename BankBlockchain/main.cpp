#include <iostream>
#include "Bank.h"
#include "Block.h"
#include "BlockChain.h"

int main()
{

    Customer customer1("aa",1000);
    Customer customer2("bb",1000);
    BlockChain blockChain;

    blockChain.addBlock(Block(1,calculateHash(extractTransfer(customer1.withdraw(60)))));
    blockChain.addBlock(Block(2,calculateHash(extractTransfer(customer1.withdraw(30)))));
    blockChain.addBlock(Block(3,calculateHash(extractTransfer(customer1.withdraw(20)))));

//  std::cout<<currentDateTime();//verification of current time


    std::cout << calculateHash(extractTransfer(customer1.withdraw(60))) << std::endl; // this is the hashOfData
    std::cout<<customer1.getBalance()<<std::endl;


    return 0;
}