// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA: 32074964

#include "AVLNode.h"

// Arquivo de cabeçalho para a árvore AVL

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
    void createTree(string archive_Name); // método para criação da árvore via arquivo .csv
    bool isEmpty();
    int height();
    int qtNodes();
    void insert(string name, string state, string city, string language, string area); // método para inserção de um nó com tais informações
    AVLNode* search(string name); // método para buscar um prestador na árvore
    void generalInfo(AVLNode* no); // método para mostrar as informações gerais de um nó
    // Métodos para impressão da árvore
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
    // Métodos para as rotações na árvore
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

