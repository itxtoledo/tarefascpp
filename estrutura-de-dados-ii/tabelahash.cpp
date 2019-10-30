#include <iostream>

using namespace std;

int funcaoHash(int key, int size)
{
    float x = 0.59896787;
    float resp = key * x - (int)(key * x);
    return (int)(size * resp);
}

class node
{
    friend class table;

private:
    int key;
    string value;
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
    void insert(int key, string value);
    string get(int key);
    void change(int key, string value);
    void remove(int key);
    void show();
};

node::node()
{
    key = 0;
    value = "";
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

void table::insert(int key, string value)
{
    int hash = funcaoHash(key, size);
    if (get(key) == "NÂO ENCONTRADO")
    {
        if (elements[hash] == NULL)
        {
            elements[hash] = new node;
            elements[hash]->key = key;
            elements[hash]->value = value;
        }
        else
        {
            cout << "COLIDIU: " << key << endl;
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
        cout << "O ITEM JÁ ESTÁ NA TABELA" << endl;
    }
}

string table::get(int key)
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
            return "NÂO ENCONTRADO";
        }
    }
}

void table::change(int key, string value)
{
    int hash = funcaoHash(key, size);
    if (elements[hash] != NULL and elements[hash]->key == key)
    {
        elements[hash]->value = value;
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
            atual->value = value;
        }
        else
        {
            cerr << "ERRO NA ALTERAÇÃO" << endl;
        }
    }
}

void table::remove(int key)
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
    table th(10);
    th.insert(1, "value1");
    th.insert(2, "value2");
    th.insert(3, "teste");
    th.show();
    //th.remove(1);
    //th.show();
    return 0;
}