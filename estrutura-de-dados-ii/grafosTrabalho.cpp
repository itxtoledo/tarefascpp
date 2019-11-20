#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class Grafo
{
    int V;
    list<int> *adj;

public:
    Grafo(int V);
    void adicionarAresta(int v1, int v2);

    int obterGrauDeSaida(int v);

    bool existeVizinho(int v1, int v2);
};

Grafo::Grafo(int V)
{
    this->V = V;
    adj = new list<int>[V]; // cria as listas
}

void Grafo::adicionarAresta(int v1, int v2)
{
    adj[v1].push_back(v2);
}

int Grafo::obterGrauDeSaida(int v)
{
    return adj[v].size();
}

bool Grafo::existeVizinho(int v1, int v2)
{
    if (find(adj[v1].begin(), adj[v1].end(), v2) != adj[v1].end())
        return true;
    return false;
}

int main()
{
    Grafo *grafo;
    grafo = new Grafo(4);
    grafo->adicionarAresta(0, 1);
    grafo->adicionarAresta(0, 3);
    grafo->adicionarAresta(1, 2);
    grafo->adicionarAresta(3, 1);
    grafo->adicionarAresta(3, 2);

    cout << "Grau de saida do vertice 1: " << grafo->obterGrauDeSaida(1);
    cout << "\nGrau de saida do vertice 3: " << grafo->obterGrauDeSaida(3);

    if (grafo->existeVizinho(0, 1))
        cout << "\n\n1 eh vizinho de 0\n";
    else
        cout << "\n\n1 NAO eh vizinho de 0\n";

    if (grafo->existeVizinho(0, 2))
        cout << "2 eh vizinho de 0\n";
    else
        cout << "2 NAO eh vizinho de 0\n";

    return 0;
}