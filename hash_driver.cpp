/**
 * @file hash_driver.cpp
 * @author Ashdeep Singh (ashdeep.singh98@myhunter.cuny.edu)
 * @brief Tests a extendible hashing data structure.
 * @version 0.1
 * @date 2022-04-14
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include "extendible_hash.h"

using namespace std;

int main()
{

    ExtendHash hashTable;

    //for 30 iterations.
    for (int i = 0; i < 30; i++)
    {
        //Insert the value i * 8 into the table.
        hashTable.insert(i*8);
    }

    //Output the table to standard output.
    cout << hashTable;

    return 0;
}