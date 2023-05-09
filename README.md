# Assignment 3

Extendible Hashing is an alternative to probing hashing or separate chaining hashing. It is often utilized when we want to minimize the number of disk accesses required to retrieve data. Collisions in probing hashing or separate chaining could result in several blocks to be examined during a search, which just isn't viable. Extendible hashing allows a search to be formed in two disk accesses. Along with this, insertions also require little disk access.

Extendible Hashing utilizes a directory of buckets. In our case, the directory is a vector of pointers, and the buckets are Node structs which contain the data vectors. Instead of binary, our directory consists of base 10 integers. The hash function determines the size of the directory, and the block size determines the size of the blocks. 

The task of this assignment was to construct a Hash Table which is able to successfully insert a data item into the correct bucket. 

To insert a data item:
We pass the data item via an insert function call. This function determines the hash value of the item in the directory and inserts it into the associated bucket. If the calculate hash value is larger than the values in the directory, double the size of the directory and try to insert again. 

To Split a bucket:
If we try to insert a data item into a bucket, and the bucket is full, we must perform a split. If the bucket has two pointers, create a new bucket and set one of the pointers to point to it. Then, call insert on the data item again. Else, if the bucket has one pointer, the directory must be doubled. Once doubled, call insert on the data item again. 

To Double a bucket:
Simply create a directory double the size of the old, and copy over the old directory contents. New directory's "blank" values/indexes' should be set to pre-existing values (double up pointers on buckets). 

Bugs Encountered:
* While doubling the size of the directory, the resulting directory would be 4x the size of the old. Error: I had two for loops running over the new directory, once to assign the old values and one to assign the "blank" ones. As a result, the resulting directory was 4x. Solution: have one for loop, set the contents in the new directory = old directory contents at position x / 2.
* Linker Error: CPP File contained incorrect function declaration.

## Files

```bash
extendible_hash.cpp
extendible_hash.h
hash_driver.cpp
```

## To Compile

The command:

```bash
make
```

will produce the library file `extendible_hash.o` and executable `hash_driver`.


## To Run

```bash
./hash_driver
```

[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-f059dc9a6f8d3a56e377f745f24479a46679e63a5d9fe6f495e02850cd0d8118.svg)](https://classroom.github.com/online_ide?assignment_repo_id=7503337&assignment_repo_type=AssignmentRepo)
