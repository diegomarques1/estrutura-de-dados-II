// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA: 32074964

#ifndef __NODE_H__
#define __NODE_H__

class Node
{
public:
	Node();
	Node(int key);
	~Node();

	// Getters e Setters

	int GetKey() const;
	void SetKey(int key);

	Node* GetLeft() const;
	void SetLeft(Node* left);
	
	Node* GetRight() const;
	void SetRight(Node* right);

private:
	int m_Key; // nessa implementação, colocamos a chave e o valor do nó com o mesmo conteúdo
	Node* m_Left;
	Node* m_Right;
};

#endif // __NODE_H__