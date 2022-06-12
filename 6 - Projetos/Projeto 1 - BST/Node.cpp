// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA: 32074964

#include "Node.h"

Node::Node()
{
	BookInfo nullBook = BookInfo();
	m_Book = nullBook;
	m_Left = m_Right = nullptr;
}

Node::Node(BookInfo book)
{
	m_Book = book;
	m_Left = m_Right = nullptr;
}

Node::~Node()
{
	m_Left = nullptr;
	m_Right = nullptr;
}

BookInfo Node::GetBook() const
{
	return m_Book;
}

void Node::SetBook(BookInfo book)
{
	m_Book = book;
}

Node* Node::GetLeft() const
{
	return m_Left;
}

void Node::SetLeft(Node* left)
{
	m_Left = left;
}

Node* Node::GetRight() const
{
	return m_Right;
}

void Node::SetRight(Node* right)
{
	m_Right = right;
}