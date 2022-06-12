// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA: 32074964

#include <iostream>
#include "BookInfo.h"

#ifndef __NODE_H__
#define __NODE_H__

class Node
{
public:
	Node();
	Node(BookInfo book);
	~Node();

	// Getters e Setters

	BookInfo GetBook() const;
	void SetBook(BookInfo book);

	Node* GetLeft() const;
	void SetLeft(Node* left);
	
	Node* GetRight() const;
	void SetRight(Node* right);

private:
	BookInfo m_Book;
	Node* m_Left;
	Node* m_Right;
};

#endif // __NODE_H__