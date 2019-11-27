#include <fstream>
#include <string>
#include <string.h>
#include <iostream>
#include <iostream>

using namespace std;

int funcaoHash(const string &key, int tableSize)
{
    int hashVal = 0;

    for (int i = 0; i < key.length(); i++)
        hashVal = 37 * hashVal + key[i];

    hashVal %= tableSize;

    if (hashVal < 0)
        hashVal += tableSize;

    return hashVal;
}

class node
{
    friend class table;

private:
    string key;
    int value;
    node *next;

public:
    node();
};

class table
{
private:
    node **elements;
    int size;

public:
    table(int cap);
    ~table();
    void insert(string key, int value);
    int get(string key);
    void change(string key, int value);
    void remove(string key);
    void show();
};

node::node()
{
    key = "";
    value = 0;
    next = NULL;
}

table::table(int sizeTable = 100)
{
    elements = new node *[sizeTable];
    size = sizeTable;
    for (int i = 0; i < sizeTable; i++)
    {
        elements[i] = NULL;
    }
}

table::~table()
{
    for (int i = 0; i < size; ++i)
    {
        node *atual = elements[i];
        while (atual != NULL)
        {
            node *aux = atual;
            atual = atual->next;
            delete aux;
        }
    }
    delete[] elements;
}

void table::insert(string key, int value)
{
    int hash = funcaoHash(key, size);
    if (get(key) == 0)
    {
        if (elements[hash] == NULL)
        {
            elements[hash] = new node;
            elements[hash]->key = key;
            elements[hash]->value = value;
        }
        else
        {
            // cout << "COLIDIU: " << key << endl;
            node *atual = elements[hash];
            while (atual->next != NULL)
            {
                atual = atual->next;
            }
            node *newNode = new node;
            newNode->key = key;
            newNode->value = value;
            atual->next = newNode;
        }
    }
    else
    {
        // cout << "O ITEM JÁ ESTÁ NA TABELA" << endl;
    }
}

int table::get(string key)
{
    int hash = funcaoHash(key, size);
    if (elements[hash] != NULL and elements[hash]->key == key)
    {
        return elements[hash]->value;
    }
    else
    {
        node *atual = elements[hash];

        while (atual != NULL and atual->key != key)
        {
            atual = atual->next;
        }

        if (atual != NULL and atual->key == key)
        {
            return atual->value;
        }
        else
        {
            return 0;
        }
    }
}

// void table::change(int key, string value)
// {
//     int hash = funcaoHash(key, size);
//     if (elements[hash] != NULL and elements[hash]->key == key)
//     {
//         elements[hash]->value = value;
//     }
//     else
//     {
//         node *atual = elements[hash];
//         while (atual != NULL and atual->key != key)
//         {
//             atual = atual->next;
//         }
//         if (atual != NULL and atual->key == key)
//         {
//             atual->value = value;
//         }
//         else
//         {
//             cerr << "ERRO NA ALTERAÇÃO" << endl;
//         }
//     }
// }

void table::remove(string key)
{
    int hash = funcaoHash(key, size);
    if (elements[hash] != NULL and elements[hash]->key == key)
    {
        node *aux = elements[hash];
        elements[hash] = elements[hash]->next;
        delete aux;
    }
    else
    {
        node *atual = elements[hash];
        node *anterior;
        while (atual != NULL and atual->key != key)
        {
            anterior = atual;
            atual = atual->next;
        }
        if (atual != NULL and atual->key == key)
        {
            anterior->next = atual->next;
            delete atual;
        }
        else
        {
            cerr << "ERRO NA REMOÇÃO" << endl;
        }
    }
}

void table::show()
{
    node *atual;
    cout << "!--------------------!" << endl;
    for (int i = 0; i < size; ++i)
    {
        cout << i << ":";
        atual = elements[i];
        while (atual != NULL)
        {
            cout << " {key:[" << atual->key << "] value:[" << atual->value << "]} -->";
            atual = atual->next;
        }
        cout << "NULL" << endl;
    }
    cout << "!--------------------!" << endl;
}

int main()
{

    table th(1000);
    th.show();
    std::ifstream is("sus.csv");

    std::string line;
    while (std::getline(is, line))
    {

        std::cout << line << std::endl;

        int temp = th.get(line);
        if (temp != 0)
        {
            th.remove(line);
            th.insert(line, temp++);
        }
        else
        {
            th.insert(line, 1);
        }

        th.show();
    }
    return 0;
}