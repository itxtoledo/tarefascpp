#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node;
struct Hash;
bool release_hash(Hash *oldHash);
Hash *new_hash(int size);
int generate_hash(string input, int size);

int main()
{
    Hash* hash = new_hash(10);
    cout << hash;
}

struct Node
{
    char data[101];
    struct Node *next;
};

struct Hash
{
    int amount, size;
    Hash **vector;
};

Hash *new_hash(int size)
{
    Hash *newHash = (Hash *)calloc(1, sizeof(Hash));
    newHash->size = size;
    newHash->amount = 0;
    newHash->vector = (Node **)calloc(size, sizeof(Node *));

    int i = 0;
    for (i = 0; i < newHash->size; i++)
    {
        newHash->vector[i] = NULL;
    }

    return newHash;
}

bool release_hash(Hash *oldHash)
{
    if (oldHash == NULL)
        return false;
    else
    {
        int i;
        for (i = 0; i < oldHash->size; i++)
            if (oldHash->vector[i] != NULL)
                free(oldHash->vector[i]);

        free(oldHash->vector);
        free(oldHash);
        return true;
    }
}

int generate_hash(string input, int size)
{
    int hash = 0;
    for (unsigned i = 0; i < sizeof(input); i++)
        hash = (11 * hash + input[i]) % size;
    return hash;
}