#include <iostream>
#include <cstddef>

using namespace std;

class Node {
private:
    Node* root;
    Node* left;
    Node* right;
    int key;
public:

    Node()
    {
        this->root = this->left = this->right = nullptr;
        this->key = 0;
        cout << this->root;
    }
    Node(int key)
    {
        this->root = this->left = this->right = nullptr;
        this->key = key;
    }
    ~Node()
    {
        if (this->getLeft() != nullptr)
            delete this->left;
        if (this->getRight() != nullptr)
            delete this->right;
    }
    int getKey()
    {
        return this->key;
    }
    Node* getLeft()
    {
        return this->left;
    }
    Node* getRight()
    {
        return this->right;
    }
    Node* getRoot()
    {
        return this->root;
    }
    void setKey(int key)
    {
        this->key = key;
    }
    void setLeft(Node* nd)
    {
        this->left = nd;
    }
    void setRight(Node* nd)
    {
        this->right = nd;
    }
    void setRoot(Node* nd)
    {
        this->root = nd;
    }
};

class Tree {
private:
    Node* root;

    void Transplant(Node* u,Node* v)
    {
        if(u->getRoot()==nullptr)
            setRoot(v);
        else if(u==u->getRoot()->getLeft())
            u->getRoot()->setLeft(v);
        else
            u->getRoot()->setRight(v);
        if(v!=nullptr)
            v->setRoot(u->getRoot());
    }

public:
    Tree()
    {
        this->root = nullptr;
    }

    Node* getRoot(){
        return this->root;
    }

    void setRoot(Node* v)
    {
        root=v;
    }
    void inserir(int valor)
    {
        if (this->root == nullptr) {
            this->root = new Node(valor);
        }
        else {
            Node* novo = new Node(valor);
            inserir(this->root, novo);
        }
    }

    void inserir(Node* tree, Node* novo)
    {
        if (novo->getKey() > tree->getKey()) {
            if (tree->getRight() == nullptr) {
                tree->setRight(novo);
            }
            else {
                inserir(tree->getRight(), novo);
            }
        }
        else {
            if (tree->getLeft() == nullptr) {
                tree->setLeft(novo);
            }
            else {
                inserir(tree->getLeft(), novo);
            }
        }
    }

    
    Node* minimo(Node* x)
    {
        while(x->getLeft()!=nullptr)
            x=x->getLeft();
        return x;
    }
    Node* maximo(Node* x)
    {
        while(x->getRight()!=nullptr)
            x=x->getRight();
        return x;
    }



    Node* Buscar(Node* x , int k)
    {
        while(k!=x->getKey())
        {
            if(k<x->getKey()){
                if (x->getLeft() == nullptr)
                    return nullptr;
                x=x->getLeft();
            }else{
                if (x->getRight() == nullptr)
                    return nullptr;
                x=x->getRight();
            }
        }
        return x;
    }



    void deleta(Node* z)
    {
        Node* aux ;
        if(z->getLeft()==nullptr)
            Transplant(z,z->getRight());
        else if(z->getRight()==nullptr)
            Transplant(z,z->getLeft());
        else
        {   aux = minimo(z->getRight());
            if(aux->getRoot()!=z)
            {
                Transplant(aux,aux->getRight());
                aux->setRight(z->getRight());
                aux->getRight()->setRoot(aux);
            }
            Transplant(z,aux);
            aux->setLeft(z->getLeft());
            aux->getLeft()->setRoot(aux);
        }
    }


    void order(int opt){
        order(this->root, opt);
    }

    void order(Node* tr, int opt)
    {
        if (tr != nullptr) {
            switch (opt) {
            case 1:
                cout << "[" << tr->getKey() << "]";
                order(tr->getLeft(), opt);
                order(tr->getRight(), opt);

                break;
            case 2:
                order(tr->getLeft(), opt);
                cout << "[" << tr->getKey() << "]";
                order(tr->getRight(), opt);
                break;
            case 3:
                order(tr->getLeft(), opt);
                order(tr->getRight(), opt);
                cout << "[" << tr->getKey() << "]";
                break;
            }
        }
    }
};

int main()
{
    Tree* tree;

    int x,i=0;
    tree = new Tree();
    while(i<10)
    {
        cin>>x;
        tree->inserir(x);
        i++;
    }

    cout<<"Minimo :"<<tree->minimo(tree->getRoot())->getKey()<<endl;
    cout<<"Maximo :"<<tree->maximo(tree->getRoot())->getKey()<<endl;

    cout << "Pre-order: " << endl;
    tree->order(1);
    cout << endl << "In-order: " << endl;
    tree->order(2);
    cout << endl << "Pos-order: " << endl;
    tree->order(3);
    cout<<endl <<"BUSCAR : ("<<tree->Buscar(tree->getRoot(),5)<<") - "<<tree->Buscar(tree->getRoot(),5)->getKey() << endl;

}