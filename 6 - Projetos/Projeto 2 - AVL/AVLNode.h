// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA: 32074964

// Arquivo de cabeçalho do nó da árvore

#include <iostream>
#include <string>

#ifndef AVLNODE_H
#define AVLNODE_H

using namespace std;

class AVLNode
{
public:
    AVLNode();
    AVLNode(string, string, string, string, string);
    virtual ~AVLNode();
    // Getters e setters
    string getName();
    void setName(string name);
    string getState();
    void setState(string state);
    string getCity();
    void setCity(string city);
    string getLanguage();
    void setLanguage(string name);
    string getArea();
    void setArea(string name);
    int getHeight();
    void setHeight(int);
    AVLNode* getLeft();
    AVLNode* getRight();
    void setRight(AVLNode*);
    void setLeft(AVLNode*);
    int getBalance(AVLNode* N);

private:
    AVLNode* left, * right;
    string m_Name, m_State, m_City, m_Language, m_Area; // informações de cada prestador
    int height;
};

#endif // AVLNODE_H
