// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA: 32074964

#include "Node.h"

Node::Node()
	: m_Key(0)
	, m_Left(nullptr)
	, m_Right(nullptr)
{
}

Node::Node(int key)
	: m_Key(key)
	, m_Left(nullptr)
	, m_Right(nullptr)
{
}

Node::~Node()
{
	m_Left = nullptr;
	m_Right = nullptr;
}

int Node::GetKey() const
{
	return m_Key;
}

void Node::SetKey(int key)
{
	m_Key = key;
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