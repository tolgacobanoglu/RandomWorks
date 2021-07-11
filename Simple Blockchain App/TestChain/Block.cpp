#include <ctime> // for current time
#include <sstream> //for stringstream ss variable in calculate hash function
#include "Block.h"
#include "sha256.h"

Block::Block(uint32_t nIndexIn, const string &sDataIn) : index(nIndexIn), data(sDataIn)  //constructor for Block object
{
    nonce = -1;
    tTime = time(nullptr);
}

string Block::getHash() const //get method for block's hash (private attribute)
{
    return hash;
}

// can be return std::string
void Block::MineBlock(unsigned int nDifficulty) //to find the valid hash
{
    char cstr[nDifficulty + 1];

    for (unsigned int i = 0; i < nDifficulty; ++i) //to make array 00000
    {
        cstr[i] = '0';
    }

    cstr[nDifficulty] = '\0';
    string str(cstr);

    do //proof of work
    {
        nonce+=1;
        hash = calculateHash();
    }
    while (hash.substr(0, nDifficulty) != str); //creating hash value

    cout << "Block mined: " << hash << endl;
}

// hashing for block's datas
inline const string Block::calculateHash() //inline function when using an array derivates it has less run speed normal function and more efficient
{
    stringstream ss;
    ss << index << tTime << data << nonce << previousHash; // index + time + data + unique number(nonce) + previousHash of block

    return sha256(ss.str());
}