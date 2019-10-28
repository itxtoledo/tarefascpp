#include <iostream>

using namespace std;

const int UMPRIMO = 37;

int funcaoHash(int chave, int size)
{
    float x = 0.59896787;
    float resp = chave * x - (int)(chave * x);
    return (int)(size * resp);
}

class noh
{
    friend class tabelaHash;

private:
    int chave;
    string valor;
    noh *proximo;

public:
    noh();
};

class tabelaHash
{
private:
    noh **elementos;
    int capacidade;

public:
    tabelaHash(int cap);
    ~tabelaHash();
    void insere(int chave, string valor);
    string recupera(int chave);
    void altera(int chave, string valor);
    void remove(int chave);
    void percorre();
};

noh::noh()
{
    chave = 0;
    valor = "";
    proximo = NULL;
}

tabelaHash::tabelaHash(int cap = 100)
{
    elementos = new noh *[cap];
    capacidade = cap;
    for (int i = 0; i < cap; i++)
    {
        elementos[i] = NULL;
    }
}

tabelaHash::~tabelaHash()
{
    for (int i = 0; i < capacidade; ++i)
    {
        noh *atual = elementos[i];
        while (atual != NULL)
        {
            noh *aux = atual;
            atual = atual->proximo;
            delete aux;
        }
    }
    delete[] elementos;
}

void tabelaHash::insere(int chave, string valor)
{
    int hash = funcaoHash(chave, capacidade);
    if (recupera(chave) == "NÂO ENCONTRADO")
    {
        if (elementos[hash] == NULL)
        {
            elementos[hash] = new noh;
            elementos[hash]->chave = chave;
            elementos[hash]->valor = valor;
        }
        else
        {
            cout << "COLIDIU: " << chave << endl;
            noh *atual = elementos[hash];
            while (atual->proximo != NULL)
            {
                atual = atual->proximo;
            }
            noh *novo = new noh;
            novo->chave = chave;
            novo->valor = valor;
            atual->proximo = novo;
        }
    }
    else
    {
        cout << "O ITEM JÁ ESTÁ NA TABELA" << endl;
    }
}

string tabelaHash::recupera(int chave)
{
    int hash = funcaoHash(chave, capacidade);
    if (elementos[hash] != NULL and elementos[hash]->chave == chave)
    {
        return elementos[hash]->valor;
    }
    else
    {
        noh *atual = elementos[hash];

        while (atual != NULL and atual->chave != chave)
        {
            atual = atual->proximo;
        }

        if (atual != NULL and atual->chave == chave)
        {
            return atual->valor;
        }
        else
        {
            return "NÂO ENCONTRADO";
        }
    }
}

void tabelaHash::altera(int chave, string valor)
{
    int hash = funcaoHash(chave, capacidade);
    if (elementos[hash] != NULL and elementos[hash]->chave == chave)
    {
        elementos[hash]->valor = valor;
    }
    else
    {
        noh *atual = elementos[hash];
        while (atual != NULL and atual->chave != chave)
        {
            atual = atual->proximo;
        }
        if (atual != NULL and atual->chave == chave)
        {
            atual->valor = valor;
        }
        else
        {
            cerr << "ERRO NA ALTERAÇÃO" << endl;
        }
    }
}

void tabelaHash::remove(int chave)
{
    int hash = funcaoHash(chave, capacidade);
    if (elementos[hash] != NULL and elementos[hash]->chave == chave)
    {
        noh *aux = elementos[hash];
        elementos[hash] = elementos[hash]->proximo;
        delete aux;
    }
    else
    {
        noh *atual = elementos[hash];
        noh *anterior;
        while (atual != NULL and atual->chave != chave)
        {
            anterior = atual;
            atual = atual->proximo;
        }
        if (atual != NULL and atual->chave == chave)
        {
            anterior->proximo = atual->proximo;
            delete atual;
        }
        else
        {
            cerr << "ERRO NA REMOÇÃO" << endl;
        }
    }
}

void tabelaHash::percorre()
{
    noh *atual;
    cout << "!--------------------!" << endl;
    for (int i = 0; i < capacidade; ++i)
    {
        cout << i << ":";
        atual = elementos[i];
        while (atual != NULL)
        {
            cout << " {CHAVE:[" << atual->chave << "] VALOR:[" << atual->valor << "]} -->";
            atual = atual->proximo;
        }
        cout << "NULL" << endl;
    }
    cout << "!--------------------!" << endl;
}

int main()
{
    tabelaHash th(10);
    th.insere(1, "Valor1");
    th.insere(2, "Valor2");
    th.insere(3, "teste");
    th.percorre();
    //th.remove ("Chave");
    //th.percorre();
    return 0;
}