// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gon�alves - TIA: 32074964

#include "AVLNode.h"

// Arquivo de cabe�alho para a �rvore AVL

using namespace std;

#ifndef AVLTREE_H
#define AVLTREE_H

class AVLTree
{
public:
    AVLTree();
    virtual ~AVLTree();
    void setRoot(AVLNode* N);
    AVLNode* getRoot();
    void createTree(string archive_Name); // m�todo para cria��o da �rvore via arquivo .csv
    bool isEmpty();
    int height();
    int qtNodes();
    void insert(string name, string state, string city, string language, string area); // m�todo para inser��o de um n� com tais informa��es
    AVLNode* search(string name); // m�todo para buscar um prestador na �rvore
    void generalInfo(AVLNode* no); // m�todo para mostrar as informa��es gerais de um n�
    // M�todos para impress�o da �rvore
    void inOrder();
    void preOrder();
    void posOrder();
    void reverseOrder();
    int getBalance(AVLNode* N);

private:
    AVLNode* root;
    int height(AVLNode*);
    int qtNodes(AVLNode*);
    AVLNode* insert(AVLNode* node, string name, string state, string city, string language, string area);
    void preOrder(AVLNode* no);
    void posOrder(AVLNode* no);
    void inOrder(AVLNode* no);
    // M�todos para as rota��es na �rvore
    AVLNode* rotateLL(AVLNode*);
    AVLNode* rotateRR(AVLNode*);
    AVLNode* rotateLR(AVLNode*);
    AVLNode* rotateRL(AVLNode*);
    AVLNode* leftRotate(AVLNode* x);
    AVLNode* rightRotate(AVLNode* y);
    void reverseOrder(AVLNode*);
    int maximo(int, int);
    AVLNode* minimo(AVLNode* no);
};


#endif // AVLTREE_H

