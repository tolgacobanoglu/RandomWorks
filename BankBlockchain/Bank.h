#ifndef BANKBLOCKCHAIN_BANK_H
#define BANKBLOCKCHAIN_BANK_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include "Customer.h"
#include "sha256.h"

const std::string currentDateTime()
{
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}

std::string extractTransfer(std::string data) // data of withdraw
{
    return data + currentDateTime() +")";
}

std::string calculateHash(std::string data)
{
    return sha256(data);
}

#endif //BANKBLOCKCHAIN_BANK_H