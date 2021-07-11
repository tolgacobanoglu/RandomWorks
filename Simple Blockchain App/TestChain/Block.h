#ifndef TESTCHAIN_BLOCK_H  //control to does it exist or not
#define TESTCHAIN_BLOCK_H

//#include <cstdint> // library for ' uint32_t '
#include <iostream>

using namespace std;

class Block
{
    public:

    Block(unsigned int nIndexIn,const string &dataIn); // const and & are to improve efficiency and save memory
    std::string previousHash; // n'th block must include the n-1'the block hash
    string getHash() const;
    void MineBlock(unsigned int nDifficulty);


    private:

    unsigned int index;
    long long int nonce; //number only used once,to generate leading 0s
    string data;  //transaction data will be hashed
    string hash;  //hash of data
    time_t tTime; //data time
    const string calculateHash(); //const because want to be unconvertible

};

#endif //TESTCHAIN_BLOCK_H
