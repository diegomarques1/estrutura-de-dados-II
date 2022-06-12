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

bool Tree::CadastrarLivro(Node* root, BookInfo book) // Insert
{
	Node* temp = ProcurarLivro(GetRoot(), book.GetISBN());
	if (temp != nullptr)
	{
		return false;
	}
	else
	{
		if (GetRoot() == nullptr)
		{
			Node* root = new Node(book); // se a árvore estiver vazia, o nó inserido é a raiz
			SetRoot(root);
		}
		else
		{
			if (book.GetISBN() < root->GetBook().GetISBN()) // subárvore da esquerda
			{
				if (root->GetLeft() == nullptr)
				{
					Node* nodeAdd = new Node(book);
					root->SetLeft(nodeAdd);
				}
				else CadastrarLivro(root->GetLeft(), book); // recursividade até chegar no menor nó folha necessário para adicionar
			}
			else if (book.GetISBN() > root->GetBook().GetISBN()) // subárvore da direita
			{
				if (root->GetRight() == nullptr)
				{
					Node* nodeAdd = new Node(book);
					root->SetRight(nodeAdd);
				}
				else CadastrarLivro(root->GetRight(), book); // recursividade até chegar no maior nó folha necessário para adicionar
			}
		}
		return true;
	}

}

Node* Tree::ProcurarLivro(Node* root, long int ISBN) // Search
{
	if (root == nullptr) return nullptr;

	if (ISBN == root->GetBook().GetISBN()) return root;

	if (ISBN < root->GetBook().GetISBN()) ProcurarLivro(root->GetLeft(), ISBN);

	else ProcurarLivro(root->GetRight(), ISBN);; // (key > nodeRef->GetKey())
}

void Tree::ExibirLivro(Node* root)
{
	std::cout << "\n*************INFORMAÇÕES GERAIS SOBRE O LIVRO*************\n";
	std::cout << "ISBN: " << root->GetBook().GetISBN() << "\n";
	std::cout << "Autor: " << root->GetBook().GetAuthor() << "\n";
	std::cout << "Título: " << root->GetBook().GetTitle() << "\n";
	std::cout << "Editora: " << root->GetBook().GetPublisher() << "\n";
	std::cout << "Ano: " << root->GetBook().GetYear() << "\n";
	std::cout << "Preço: R$ " << root->GetBook().GetPrice() << "\n";
}

Node* Tree::SearchParent(long int ISBN, Node* nodeRef, Node* nodeParent) // Search do pai
{
	if (nodeRef == nullptr) return nullptr;

	if (ISBN == nodeRef->GetBook().GetISBN()) return nodeParent;

	if (ISBN < nodeRef->GetBook().GetISBN())
	{
		nodeParent = nodeRef;
		SearchParent(ISBN, nodeRef->GetLeft(), nodeParent);
	}
	else // (key > nodeRef->GetKey())
	{
		nodeParent = nodeRef;
		SearchParent(ISBN, nodeRef->GetRight(), nodeParent); 
	}	
}

void Tree::RemoverLivro(Node* root, long int ISBN) // Remove
{
	Node* toRemove = ProcurarLivro(root, ISBN);
	if (toRemove == nullptr) return;

	Node* parent = SearchParent(ISBN, GetRoot(), nullptr);
	int temp = toRemove->GetBook().GetISBN();
	if (toRemove->GetLeft() == nullptr && toRemove->GetRight() == nullptr)
	{
		if (toRemove->GetBook().GetISBN() == GetRoot()->GetBook().GetISBN())
		{
			SetRoot(nullptr);
			delete toRemove;
			return;
		}

		if (toRemove->GetBook().GetISBN() < parent->GetBook().GetISBN())
		{
			parent->SetLeft(nullptr);
		}
		else if (toRemove->GetBook().GetISBN() > parent->GetBook().GetISBN())
		{
			parent->SetRight(nullptr);
		}
		delete toRemove;
		return;
	}
	else if (toRemove->GetLeft() == nullptr && toRemove->GetRight() != nullptr)
	{
		if (toRemove->GetBook().GetISBN() == GetRoot()->GetBook().GetISBN())
		{
			SetRoot(toRemove->GetRight());
			toRemove->SetRight(nullptr);
			delete toRemove;
			return;
		}

		if (toRemove->GetBook().GetISBN() < parent->GetBook().GetISBN())
		{
			parent->SetLeft(toRemove->GetRight());
		}
		else if (toRemove->GetBook().GetISBN() > parent->GetBook().GetISBN())
		{
			parent->SetRight(toRemove->GetRight());
		}
		toRemove->SetRight(nullptr);
		delete toRemove;
		return;
	}
	else if (toRemove->GetLeft() != nullptr && toRemove->GetRight() == nullptr)
	{
		if (toRemove->GetBook().GetISBN() == GetRoot()->GetBook().GetISBN())
		{
			SetRoot(toRemove->GetLeft());
			toRemove->SetLeft(nullptr);
			delete toRemove;
			return;
		}

		if (toRemove->GetBook().GetISBN() < parent->GetBook().GetISBN())
		{
			parent->SetLeft(toRemove->GetLeft());
		}
		else if (toRemove->GetBook().GetISBN() > parent->GetBook().GetISBN())
		{
			parent->SetRight(toRemove->GetLeft());
		}
		toRemove->SetLeft(nullptr);
		delete toRemove;
		return;
	}
	else // (toRemove->GetLeft() != nullptr && toRemove->GetRight() != nullptr)
	{
		Node* candidate = toRemove->GetRight();
		while (candidate->GetLeft() != nullptr)
		{
			candidate = candidate->GetLeft();
		}

		Node* candidateParent = SearchParent(candidate->GetBook().GetISBN(), GetRoot(), nullptr);
		if (toRemove != GetRoot())
		{
			if (candidate->GetBook().GetISBN() < parent->GetBook().GetISBN()) parent->SetLeft(candidate);
			else if (candidate->GetBook().GetISBN() > parent->GetBook().GetISBN()) parent->SetRight(candidate);
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
		return;
	}
}

void Tree::ListarAcervo(Node* root) // percurso em-ordem (Esquerda-Raiz-Direita)
{
	if (root != nullptr)
	{
		ListarAcervo(root->GetLeft());
		std::cout << "ISBN: " << root->GetBook().GetISBN() << "; Título: " << root->GetBook().GetTitle() << "\n";
		ListarAcervo(root->GetRight());
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