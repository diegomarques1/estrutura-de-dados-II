// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA: 32074964

#include <iostream>
#include "ArvoreBST.h"

Tree::Tree()
	: m_Root(nullptr)
{
}

Tree::Tree(Node* root)
	: m_Root(root)
{
}

Tree::~Tree()
{
	m_Root = nullptr;
}

Node* Tree::GetRoot()
{
	return m_Root;
}

void Tree::SetRoot(Node* node)
{
	m_Root = node;
}

bool Tree::Insert(int key, Node* nodeRef)
{
	Node* temp = Search(key, GetRoot());
	if (temp != nullptr)
	{
		return false;
	}
	else
	{
		if (GetRoot() == nullptr)
		{
			Node* root = new Node(key); // se a árvore estiver vazia, o nó inserido é a raiz
			SetRoot(root);
		}
		else
		{
			if (key < nodeRef->GetKey()) // subárvore da esquerda
			{
				if (nodeRef->GetLeft() == nullptr) 
				{
					Node* nodeAdd = new Node(key);
					nodeRef->SetLeft(nodeAdd);
				}
				else Insert(key, nodeRef->GetLeft()); // recursividade até chegar no menor nó folha necessário para adicionar
			}
			else if (key > nodeRef->GetKey()) // subárvore da direita
			{
				if (nodeRef->GetRight() == nullptr)
				{
					Node* nodeAdd = new Node(key);
					nodeRef->SetRight(nodeAdd);
				}
				else Insert(key, nodeRef->GetRight()); // recursividade até chegar no maior nó folha necessário para adicionar
			}
		}
		return true;
	}
}

Node* Tree::Search(int key, Node* nodeRef) // retorna o nó se encontrado na árvore, ou nullptr caso contrário
{
	if (nodeRef == nullptr) return nullptr;

	if (key == nodeRef->GetKey()) return nodeRef;

	if (key < nodeRef->GetKey()) Search(key, nodeRef->GetLeft());

	else Search(key, nodeRef->GetRight()); // (key > nodeRef->GetKey())
}

Node* Tree::SearchParent(int key, Node* nodeRef, Node* nodeParent) // quase o mesmo que o Search, mas retorna o pai do nó
{
	if (nodeRef == nullptr) return nullptr;

	if (key == nodeRef->GetKey()) return nodeParent;

	if (key < nodeRef->GetKey())
	{
		nodeParent = nodeRef;
		SearchParent(key, nodeRef->GetLeft(), nodeParent);
	}
	else // (key > nodeRef->GetKey())
	{
		nodeParent = nodeRef;
		SearchParent(key, nodeRef->GetRight(), nodeParent); 
	}	
}

void Tree::EmOrdem(Node* node) // percurso em-ordem (Esquerda-Raiz-Direita)
{
	if (node != nullptr)
	{
		EmOrdem(node->GetLeft());
		std::cout << node->GetKey() << " ";
		EmOrdem(node->GetRight());
	}
}

// void Print(Node* node);

int Tree::Remove(int key)
{
	Node* toRemove = Search(key, GetRoot());
	if (toRemove == nullptr) return -1;

	Node* parent = SearchParent(key, GetRoot(), nullptr);
	int temp = toRemove->GetKey();
	if (toRemove->GetLeft() == nullptr && toRemove->GetRight() == nullptr)
	{
		if (toRemove->GetKey() == GetRoot()->GetKey())
		{
			SetRoot(nullptr);
			delete toRemove;
			return temp;
		}

		if (toRemove->GetKey() < parent->GetKey())
		{
			parent->SetLeft(nullptr);
		}
		else if (toRemove->GetKey() > parent->GetKey())
		{
			parent->SetRight(nullptr);
		}
		delete toRemove;
		return temp;
	}
	else if (toRemove->GetLeft() == nullptr && toRemove->GetRight() != nullptr)
	{
		if (toRemove->GetKey() == GetRoot()->GetKey())
		{
			SetRoot(toRemove->GetRight());
			toRemove->SetRight(nullptr);
			delete toRemove;
			return temp;
		}

		if (toRemove->GetKey() < parent->GetKey())
		{
			parent->SetLeft(toRemove->GetRight());
		}
		else if (toRemove->GetKey() > parent->GetKey())
		{
			parent->SetRight(toRemove->GetRight());
		}
		toRemove->SetRight(nullptr);
		delete toRemove;
		return temp;
	}
	else if (toRemove->GetLeft() != nullptr && toRemove->GetRight() == nullptr)
	{
	if (toRemove->GetKey() == GetRoot()->GetKey())
	{
		SetRoot(toRemove->GetLeft());
		toRemove->SetLeft(nullptr);
		delete toRemove;
		return temp;
	}

	if (toRemove->GetKey() < parent->GetKey())
	{
		parent->SetLeft(toRemove->GetLeft());
	}
	else if (toRemove->GetKey() > parent->GetKey())
	{
		parent->SetRight(toRemove->GetLeft());
	}
	toRemove->SetLeft(nullptr);
	delete toRemove;
	return temp;
	}
	else // (toRemove->GetLeft() != nullptr && toRemove->GetRight() != nullptr)
	{
	Node* candidate = toRemove->GetRight();
	while (candidate->GetLeft() != nullptr)
	{
		candidate = candidate->GetLeft();
	}

	Node* candidateParent = SearchParent(candidate->GetKey(), GetRoot(), nullptr);
	if (toRemove != GetRoot())
	{
		if (candidate->GetKey() < parent->GetKey()) parent->SetLeft(candidate);
		else if (candidate->GetKey() > parent->GetKey()) parent->SetRight(candidate);
	}

	// condições: se o candidato é o GetRight do toRemove, se não tem filho, se tem filho pra direita
	if (candidate->GetRight() == nullptr && candidate->GetLeft() == nullptr)
	{
		if (candidate == toRemove->GetRight())
		{
			candidate->SetRight(nullptr);
			candidate->SetLeft(toRemove->GetLeft());
		}
		else
		{
			candidateParent->SetLeft(nullptr);
			candidate->SetLeft(toRemove->GetLeft());
			candidate->SetRight(toRemove->GetRight());
		}

	}
	else if (candidate->GetLeft() == nullptr && candidate->GetRight() != nullptr)
	{
		if (candidate == toRemove->GetRight())
		{
			// não precisa fazer nada no filho da direita nesse caso
			candidate->SetLeft(toRemove->GetLeft());
		}
		else
		{
			candidateParent->SetLeft(candidate->GetRight());
			candidate->SetLeft(toRemove->GetLeft());
			candidate->SetRight(toRemove->GetRight());
		}

	}
	if (toRemove == GetRoot())
	{
		SetRoot(candidate);
	}

	toRemove->SetLeft(nullptr);
	toRemove->SetRight(nullptr);
	delete toRemove;
	return temp;
	}
}

int Tree::Height(Node* nodeRef)
{

	if (nodeRef == nullptr)
	{
		return 0;
	}

	int leftH = Height(nodeRef->GetLeft());
	int rightH = Height(nodeRef->GetRight());

	if (nodeRef == GetRoot())
	{
		return (leftH > rightH) ? leftH : rightH;
	}
	else
	{
		return (leftH > rightH) ? leftH + 1 : rightH + 1;
	}
}

void Tree::Clear(Node* node)
{
	if (node != nullptr)
	{
		Clear(node->GetLeft()); // deletar a subárvore da esquerda
		Clear(node->GetRight()); // deletar a subárvore da direita
		delete node;
		node = nullptr;
	}
	SetRoot(nullptr);
}

int Tree::numFolhas(Node* nodeRef, int cont)
{
	if (nodeRef == nullptr) return -1;
	else
	{
		int temp;
		if (nodeRef->GetLeft() != nullptr)
		{
			temp = numFolhas(nodeRef->GetLeft(), cont);
			cont = temp;
		}
		if (nodeRef->GetRight() != nullptr)
		{
			temp = numFolhas(nodeRef->GetRight(), cont);
			cont = temp;
		}
		if (nodeRef->GetRight() == nullptr && nodeRef->GetLeft() == nullptr)
		{
			return cont + 1;
		}
		else return cont;
	}
}

int Tree::contaNos(Node* nodeRef, int cont)
{
	if (nodeRef == nullptr) return -1;
	else
	{
		int temp;
		if (nodeRef->GetLeft() != nullptr)
		{
			temp = contaNos(nodeRef->GetLeft(), cont);
			cont = temp;
		}
		if (nodeRef->GetRight() != nullptr)
		{
			temp = contaNos(nodeRef->GetRight(), cont);
			cont = temp;
		}
		return cont + 1;
	}
}

int Tree::menorValor(Node* nodeRef)
{
	if (nodeRef->GetLeft() != nullptr)
	{
		return menorValor(nodeRef->GetLeft());
	}
	// se chegou aqui, chegou no nó mais à esquerda, então só retornamos sua chave.
	return nodeRef->GetKey();
}

int Tree::maiorValor(Node* nodeRef)
{
	if (nodeRef->GetRight() != nullptr)
	{
		return maiorValor(nodeRef->GetRight());
	}
	// se chegou aqui, chegou no nó mais à direita, então só retornamos sua chave.
	return nodeRef->GetKey();
}