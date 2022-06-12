// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA: 32074964

// Implementação da árvore AVL

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
    std::getline(file, first_Line, '\n'); // pular a primeira linha (cabeçalho do arquivo)
    while (file.peek() != EOF) // enquanto não chegar no EOF (final do arquivo), insere os nós com as informações de cada coluna
    {
        std::getline(file, name, ';'); // a divisão de coluna no Excel se dá por meio de , ou ; (depende da linguagem)
        std::getline(file, state, ';');
        std::getline(file, city, ';');
        std::getline(file, language, ';');
        std::getline(file, area, '\n'); // pega toda informação até o final da linha
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
	return height(root); // a altura da árvore é a altura do seu nó raiz
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
    if (node == nullptr) // caso chegue filho de uma folha ou a raiz seja nula, cria um novo nó com as informações passadas
       	return new AVLNode(name, state, city, language, area);
    if (name < node->getName()) // comparação entre strings (< e > funcionam para ordem alfabética)
    {
        node->setLeft(insert(node->getLeft(), name, state, city, language, area)); // se o nome vier antes que o do pai alfabeticamente (menor), coloca na esquerda
        if(height(node->getRight()) - height(node->getLeft()) == -2) // fator de balanceamento desrespeitado, rotações são necessárias
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
            if(height(node->getRight()) - height(node->getLeft()) == 2) // fator de balanceamento desrespeitado, rotações são necessárias
            {
                if (name > node->getRight()->getName()) node = rotateRR(node);

                else node = rotateRL(node);

            }
        }
    }

    // a altura do nó é a maior entre a altura de sua subárvore esquerda e direita + 1, visto que é um nível a mais que seus filhos.
    node->setHeight(maximo( height(node->getLeft()), height(node->getRight()) ) + 1); 

    return node;
}

AVLNode* AVLTree::search(string name) // retorna o nó se encontrado na árvore, ou nullptr caso contrário
{
    AVLNode* node_Atual = root; // começa na raiz

    while (node_Atual != nullptr) // busca até o final da árvore (atual não ser nulo, isto é, filho de uma folha)
    {
        if (node_Atual->getName() == name) // se encontrar o nó, sai do loop
        {
            break;
        }
        node_Atual = (name > node_Atual->getName()) ? node_Atual->getRight() : node_Atual->getLeft(); // compara se o nome é "maior" ou "menor" que o pai e vai para o lado correspondente
        // se chegar em uma folha e o nome não for encontrado, irá para o filho da esquerda (nulo) e sai do loop
    }
    return node_Atual; // retorna o nó encontrado ou um nó nulo caso contrário
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
    if (no != nullptr) // se o nó tiver algo (não for nulo), mostra todas as informações do prestador e é chamada na função inOrder
    {
        cout << "Nome do prestador(a): " << no->getName() << "\n"
            << "UF: " << no->getState() << "\n"
            << "Localidade: " << no->getCity() << "\n"
            << "Linguas: " << no->getLanguage() << "\n"
            << "Segmentos: " << no->getArea() << "\n" << endl;
    }
}

void AVLTree::inOrder(AVLNode *no) // percurso em-ordem da árvore (E-R-D, ou seja, filho à esquerda -> raiz -> filho à direita) - ordem alfabética dos nomes
{
    if (no!= nullptr) 
    {
        inOrder(no->getLeft()); // filho à esquerda
        generalInfo(no); // raiz
        inOrder(no->getRight()); // filho à direita
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