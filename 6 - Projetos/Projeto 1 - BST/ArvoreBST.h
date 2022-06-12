// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA: 32074964

#include "Node.h"

#ifndef __BINARY_SEARCH_TREE__
#define __BINARY_SEARCH_TREE__

class Tree
{
public:
	Tree(); // construtor padrão da classe
	Tree(Node* root);
	~Tree(); // destrutor padrão da classe

	Node* GetRoot();
	void SetRoot(Node* node);

	bool CadastrarLivro(Node* root, BookInfo book); // insert
	Node* ProcurarLivro(Node* root, long int ISBN); // search
	void ExibirLivro(Node* root); 
	void RemoverLivro(Node* root, long int ISBN); // Remove (SearchParent)
	void ListarAcervo(Node* root); // EmOrdem

	Node* SearchParent(long int ISBN, Node* nodeRef, Node* nodeParent);
	void Clear(Node* node);

private:
	Node* m_Root; // raiz da árvore binária
};

#endif // __BINARY_SEARCH_TREE__