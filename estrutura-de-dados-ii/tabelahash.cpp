#include <iostream>

using namespace std;

struct Node;
struct Hash;
bool release_hash(Hash *oldHash);

int main()
{
    // null
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