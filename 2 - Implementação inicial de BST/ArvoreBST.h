// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA: 32074964

#ifndef __BINARY_SEARCH_TREE__
#define __BINARY_SEARCH_TREE__

#include "Node.h"

class Tree
{
public:
	Tree(); // construtor padrão da classe
	Tree(Node* root);
	~Tree(); // destrutor padrão da classe

	Node* GetRoot();
	void SetRoot(Node* node);

	bool Insert(int key, Node* nodeRef);
	Node* Search(int key, Node* nodeRef);
	Node* SearchParent(int key, Node* nodeRef, Node* nodeParent);
	void EmOrdem(Node* node);
	// void Print(Node* node);
	int Remove(int key);
	int Height(Node* nodeRef);
	void Clear(Node* node);

private:
	Node* m_Root; // raiz da árvore binária
};

#endif // __BINARY_SEARCH_TREE__