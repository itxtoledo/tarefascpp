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

Hash *newHash(int tam)
{
    Hash *newH = (Hash *)calloc(1, sizeof(Hash));
    newH->size = tam;
    newH->amount = 0;
    newH->vector = (Node **)calloc(tam, sizeof(Node *));

    int i = 0;
    for (i = 0; i < newH->size; i++)
    {
        newH->vector[i] = NULL;
    }

    return newH;
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