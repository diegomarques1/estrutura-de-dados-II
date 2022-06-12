// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gon�alves - TIA: 32074964

// Implementa��o da �rvore AVL

#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include "AVLTree.h"

using namespace std;

AVLTree::AVLTree()
{    
    root = nullptr;
}

void AVLTree::createTree(string archive_Name)
{
    ifstream file;
    string first_Line, name, state, city, language, area;
    file.open(archive_Name);
    std::getline(file, first_Line, '\n'); // pular a primeira linha (cabe�alho do arquivo)
    while (file.peek() != EOF) // enquanto n�o chegar no EOF (final do arquivo), insere os n�s com as informa��es de cada coluna
    {
        std::getline(file, name, ';'); // a divis�o de coluna no Excel se d� por meio de , ou ; (depende da linguagem)
        std::getline(file, state, ';');
        std::getline(file, city, ';');
        std::getline(file, language, ';');
        std::getline(file, area, '\n'); // pega toda informa��o at� o final da linha
        insert(name, state, city, language, area);
    }
    file.close();
}

AVLTree::~AVLTree()
{
 
}

void AVLTree::setRoot(AVLNode* N)
{
    root = N;
}

AVLNode* AVLTree::getRoot()
{
    return root;
}

int AVLTree::getBalance(AVLNode *N) 
{ 
    if (N == nullptr)
        return 0; 
    return height(N->getLeft()) - height(N->getRight()); 
}

bool AVLTree::isEmpty()
{
    return root==nullptr;
}

int AVLTree::height()
{
	return height(root); // a altura da �rvore � a altura do seu n� raiz
}

int AVLTree::height(AVLNode *no)
{	
	return no == nullptr ? -1 : no->getHeight();
}

AVLNode * AVLTree::minimo(AVLNode* no) 
{ 
    AVLNode* current = no;     
    while (current->getLeft() != nullptr)
        current = current->getLeft(); 
    return current;
}

int AVLTree::maximo(int lhs, int rhs)
{
    return lhs>rhs? lhs : rhs;
}

int AVLTree::qtNodes()
{
    return qtNodes(root);
}

int AVLTree::qtNodes(AVLNode* no)
{
    if (no == nullptr)
		return 0;
	int qtleft = qtNodes (no->getLeft());
	int qtright = qtNodes (no->getRight());
	return qtleft + qtright + 1;
}

void AVLTree::insert(string name, string state, string city, string language, string area) // sobrecarga para inserir e setar raiz
{
    root = insert(root, name, state, city, language, area);
}

AVLNode* AVLTree::insert(AVLNode* node, string name, string state, string city, string language, string area)
{
    if (node == nullptr) // caso chegue filho de uma folha ou a raiz seja nula, cria um novo n� com as informa��es passadas
       	return new AVLNode(name, state, city, language, area);
    if (name < node->getName()) // compara��o entre strings (< e > funcionam para ordem alfab�tica)
    {
        node->setLeft(insert(node->getLeft(), name, state, city, language, area)); // se o nome vier antes que o do pai alfabeticamente (menor), coloca na esquerda
        if(height(node->getRight()) - height(node->getLeft()) == -2) // fator de balanceamento desrespeitado, rota��es s�o necess�rias
        {
            if(name < node->getLeft()->getName()) node = rotateLL(node);

            else node = rotateLR(node);
        }
    }
    else
    {
        if (name > node->getName())
        {
            node->setRight(insert(node->getRight(), name, state, city, language, area)); // se o nome vier depois que o do pai alfabeticamente (maior), coloca na direita
            if(height(node->getRight()) - height(node->getLeft()) == 2) // fator de balanceamento desrespeitado, rota��es s�o necess�rias
            {
                if (name > node->getRight()->getName()) node = rotateRR(node);

                else node = rotateRL(node);

            }
        }
    }

    // a altura do n� � a maior entre a altura de sua sub�rvore esquerda e direita + 1, visto que � um n�vel a mais que seus filhos.
    node->setHeight(maximo( height(node->getLeft()), height(node->getRight()) ) + 1); 

    return node;
}

AVLNode* AVLTree::search(string name) // retorna o n� se encontrado na �rvore, ou nullptr caso contr�rio
{
    AVLNode* node_Atual = root; // come�a na raiz

    while (node_Atual != nullptr) // busca at� o final da �rvore (atual n�o ser nulo, isto �, filho de uma folha)
    {
        if (node_Atual->getName() == name) // se encontrar o n�, sai do loop
        {
            break;
        }
        node_Atual = (name > node_Atual->getName()) ? node_Atual->getRight() : node_Atual->getLeft(); // compara se o nome � "maior" ou "menor" que o pai e vai para o lado correspondente
        // se chegar em uma folha e o nome n�o for encontrado, ir� para o filho da esquerda (nulo) e sai do loop
    }
    return node_Atual; // retorna o n� encontrado ou um n� nulo caso contr�rio
}

AVLNode* AVLTree::rotateLL(AVLNode *node)
     {
         AVLNode *leftSubTree = node->getLeft();
         node->setLeft(leftSubTree->getRight());
         leftSubTree->setRight( node );
         node->setHeight( maximo(height(node->getLeft()), height(node->getRight())) + 1);
         leftSubTree->setHeight( maximo(height(leftSubTree->getLeft()), height(node) + 1));
         return leftSubTree;
     }

AVLNode* AVLTree::rotateRR(AVLNode *node)
     {
         AVLNode *rightSubTree = node->getRight();
         node->setRight(rightSubTree->getLeft());
         rightSubTree->setLeft( node );
         node->setHeight( maximo(height(node->getLeft()), height(node->getRight())) + 1);
         rightSubTree->setHeight( maximo(height(rightSubTree->getRight()), height(node) + 1));
         return rightSubTree;
     }


AVLNode* AVLTree::rotateLR(AVLNode *node)
{
    node->setLeft(rotateRR(node->getLeft()));
    return rotateLL(node);
}

AVLNode* AVLTree::rotateRL(AVLNode *node)
{
    node->setRight(rotateLL(node->getRight()));
    return rotateRR(node);
}

AVLNode * AVLTree::leftRotate(AVLNode *x) 
{ 
    AVLNode *y = x->getRight(); 
    AVLNode *T2 = y->getLeft(); 
  
    y->setLeft(x); 
    x->setRight(T2); 
   
    x->setHeight(maximo(height(x->getLeft()),height(x->getRight())) + 1); 
    y->setHeight(maximo(height(y->getLeft()),height(y->getRight())) + 1); 
     
    return y; 
}
AVLNode * AVLTree::rightRotate(AVLNode *y) 
{ 
    AVLNode *x = y->getLeft(); 
    AVLNode *T2 = x->getRight(); 
     
    x->setRight(y);
    y->setLeft(T2);
    
    y->setHeight(maximo(height(y->getLeft()),height(y->getRight())) + 1); 
    x->setHeight(maximo(height(x->getLeft()),height(x->getRight())) + 1); 

    return x; 
}

void AVLTree::preOrder()
{
    preOrder(root);
}

void AVLTree::inOrder()
{
    inOrder(root);
}

void AVLTree::posOrder()
{
    posOrder(root);
}

void AVLTree::reverseOrder()
{
    reverseOrder(root);
}

void AVLTree::generalInfo(AVLNode* no)
{
    if (no != nullptr) // se o n� tiver algo (n�o for nulo), mostra todas as informa��es do prestador e � chamada na fun��o inOrder
    {
        cout << "Nome do prestador(a): " << no->getName() << "\n"
            << "UF: " << no->getState() << "\n"
            << "Localidade: " << no->getCity() << "\n"
            << "Linguas: " << no->getLanguage() << "\n"
            << "Segmentos: " << no->getArea() << "\n" << endl;
    }
}

void AVLTree::inOrder(AVLNode *no) // percurso em-ordem da �rvore (E-R-D, ou seja, filho � esquerda -> raiz -> filho � direita) - ordem alfab�tica dos nomes
{
    if (no!= nullptr) 
    {
        inOrder(no->getLeft()); // filho � esquerda
        generalInfo(no); // raiz
        inOrder(no->getRight()); // filho � direita
    }
}

void AVLTree::preOrder(AVLNode* no)
{
    if (no != nullptr)
    {
        generalInfo(no);
        preOrder(no->getLeft());
        preOrder(no->getRight());
    }
}

void AVLTree::posOrder(AVLNode* no)
{
    if (no != nullptr)
    {
        posOrder(no->getLeft());
        posOrder(no->getRight());
        generalInfo(no);
    }
}


void AVLTree::reverseOrder(AVLNode *no)
{
    if (no!= nullptr)
    {
        reverseOrder(no->getRight());
        generalInfo(no);
        reverseOrder(no->getLeft());
    }
}