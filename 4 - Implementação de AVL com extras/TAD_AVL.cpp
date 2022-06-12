// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA: 32074964

#include <iostream>
#include <stdlib.h>
#include <clocale>
#ifndef AVLNODE_H
#define AVLNODE_H
#ifndef AVLTREE_H
#define AVLTREE_H

using namespace std;

class AVLNode
{
    public:
        AVLNode();
        AVLNode(int);
        virtual ~AVLNode();
        int getData();
        int getHeight();
        void setData(int);
        void setHeight(int);
        AVLNode* getLeft();
        AVLNode* getRight();
        void setRight(AVLNode*);
        void setLeft(AVLNode*);
        int getBalance(AVLNode *N);

    private:
        AVLNode* left, *right;
        int data;
        int height;
};

#endif // AVLNODE_H

AVLNode::AVLNode()
{
    left = NULL;
    right = NULL;
    height = 0;
}

AVLNode::AVLNode(int valor)
{
    left = NULL;
    right = NULL;
    data = valor;
    height = 0;
}

AVLNode::~AVLNode()
{
}

void AVLNode::setData(int d)
{
    data = d;
}

int AVLNode::getData()
{
    return data;
}

void AVLNode::setLeft(AVLNode *n)
{
    left = n;
}

AVLNode* AVLNode::getLeft()
{
    return left;
}

void AVLNode::setRight(AVLNode *n)
{
    right = n;
}

AVLNode* AVLNode::getRight()
{
    return right;
}

void AVLNode::setHeight(int h)
{
    height = h;
}

int AVLNode::getHeight()
{
    return height;
}

class AVLTree
{
    public:
        AVLTree();
        virtual ~AVLTree();
        AVLNode* getRoot();
        bool isEmpty();
        int height();
        int qtNodes();
        void inserir (int valor);
        void remove(int valor);
        void preOrder();
        void posOrder();
        void inOrder();
        void reverseOrder();
        int getBalance(AVLNode *N);
        bool isAVL();
        void print();

    private:
        AVLNode *root;
        int height(AVLNode*);
        int qtNodes(AVLNode*);
        AVLNode* inserir(AVLNode*, int);
        AVLNode* remove(AVLNode*, int);
        void preOrder(AVLNode *no);
        void posOrder(AVLNode *no);
        void inOrder(AVLNode *no);
        AVLNode* rotateLL(AVLNode*);
        AVLNode* rotateRR(AVLNode*);
        AVLNode* rotateLR(AVLNode*);
        AVLNode* rotateRL(AVLNode*);
        AVLNode* leftRotate(AVLNode *x);
        AVLNode* rightRotate(AVLNode *y);
        void reverseOrder(AVLNode*);
        int maximo(int, int);
        AVLNode* minimo(AVLNode* no);
        bool isAVL(AVLNode* no);
        void print(AVLNode* no, int space);
};

#endif // AVLTREE_H

AVLTree::AVLTree()
{    
    root = NULL;
}

AVLTree::~AVLTree()
{
 
}

int AVLTree::getBalance(AVLNode *N) 
{ 
    if (N == NULL) 
        return 0; 
    return height(N->getLeft()) - height(N->getRight()); 
}

bool AVLTree::isEmpty()
{
    return root==NULL;
}

int AVLTree::height()
{
	return height(root); //altura da árvore é a altura do seu nó raiz
}

int AVLTree::height(AVLNode *no)
{	
	return no==NULL? -1 : no->getHeight();
}

AVLNode * AVLTree::minimo(AVLNode* no) 
{ 
    AVLNode* current = no;     
    while (current->getLeft() != NULL) 
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
    if (no == NULL)
		return 0;
	int qtleft = qtNodes (no->getLeft());
	int qtright = qtNodes (no->getRight());
	return qtleft + qtright + 1;
}

void AVLTree::inserir (int valor)
{
    root = inserir(root,valor);
}

AVLNode* AVLTree::inserir(AVLNode* node, int valor)
{
    if (node == NULL)
       	return new AVLNode(valor);
    if (valor < node->getData())
    {
            node->setLeft(inserir(node->getLeft(), valor));
            if( height( node->getRight() ) - height( node->getLeft() ) == -2 )
            {
                if(  valor< node->getLeft()->getData() )
                     {
                        node = rotateLL( node );
                     }
                 else{
                        node = rotateLR( node );
                     }
            }
    }
    else
    {
        if (valor > node->getData())
            {
                    node->setRight(inserir(node->getRight(),valor));
                    if( height( node->getRight() ) - height( node->getLeft() ) == 2 )
                    {
                        if( valor > node->getRight()->getData())
                            node = rotateRR( node );
                        else
                            node = rotateRL( node );

                    }

            }
    }
    node->setHeight(maximo( height(node->getLeft()), height(node->getRight()) ) + 1);

    return node;
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

void AVLTree::remove (int valor)
{
    root = remove(root,valor);
}

AVLNode* AVLTree::remove(AVLNode* root, int key) 
{ 
    if (root == NULL) 
        return new AVLNode(key);
  
    if ( key < root->getData() ) 
        root->setLeft(remove(root->getLeft(), key));    
    else if( key > root->getData()) 
        root->setRight(remove(root->getRight(), key)); 
    else
    { 
        if( (root->getLeft() == NULL) || (root->getRight() == NULL) ) 
        { 
            AVLNode *temp = root->getLeft() ? 
                        root->getLeft() : 
                        root->getRight(); 
            
            if (temp == NULL) 
            { 
                temp = root; 
                root = NULL; 
            } 
            else 
            *root = *temp;                         
            free(temp); 
        } 
        else
        {              
            AVLNode* temp = minimo(root->getRight());             
            root->setData(temp->getData());             
            root->setRight(remove(root->getRight(),temp->getData())); 
        } 
    }
 
    if (root == NULL) 
    return root; 
	    
    root->setHeight ( 1 + maximo(height(root->getLeft()),height(root->getRight()))); 

    int balance = getBalance(root); 

    // Left Left Case 
    if (balance > 1 && getBalance(root->getLeft()) >= 0) 
        return rightRotate(root); 

    // Left Right Case 
    if (balance > 1 && getBalance(root->getLeft()) < 0) 
    { 
        root->setLeft(leftRotate(root->getLeft())); 
        return rightRotate(root);  
    } 

    // Right Right Case 
    if (balance < -1 && getBalance(root->getRight()) <= 0) 
        return leftRotate(root); 

    // Right Left Case 
    if (balance < -1 && getBalance(root->getRight()) > 0) 
    { 
         root->setRight(rightRotate(root->getRight())); 
         return leftRotate(root); 
    } 

    return root; 
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

void AVLTree::preOrder(AVLNode *no)
{
    if (no!=NULL)
    {
        cout<<no->getData()<<endl;
        preOrder(no->getLeft());
        preOrder(no->getRight());
    }
}

void AVLTree::posOrder(AVLNode *no)
{
    if (no!=NULL)
    {
        posOrder(no->getLeft());
        posOrder(no->getRight());
        cout<<no->getData()<<endl;
    }
}

void AVLTree::inOrder(AVLNode *no)
{
    if (no!=NULL)
    {
        inOrder(no->getLeft());
        cout<<no->getData()<<endl;
        inOrder(no->getRight());
    }
}

void AVLTree::reverseOrder(AVLNode *no)
{
    if (no!=NULL)
    {
        reverseOrder(no->getRight());
		cout<<no->getData()<<endl;
        reverseOrder(no->getLeft());
    }
}

bool AVLTree::isAVL()
{
    return isAVL(root);
}

bool AVLTree::isAVL(AVLNode* no)
{
    if (root == NULL) return false;

    if (no == NULL) return true;
    
    if (getBalance(no) > 1 || getBalance(no) < -1) return false;
    
    if (no->getLeft() != NULL)
    {
        if (no->getLeft()->getData() > no->getData())
            return false;
    }
    if (no->getRight() != NULL)
    {
        if (no->getRight()->getData() < no->getData())
            return false;
    }

    bool x = isAVL(no->getLeft());
    bool y = isAVL(no->getRight());
    return x && y;
}

void AVLTree::print()
{
  print(root, 0);
}

void AVLTree::print(AVLNode *no, int space)
{
  if (no != NULL)
  {
    print(no->getRight(), space + 5);
    for (int k = 0; k < space; ++k) cout << " ";
    cout << no->getData() << "[" << getBalance(no) << "]\n";
    print(no->getLeft(), space + 5);
  }
}

int main(){
    setlocale(LC_ALL, "pt_BR");
	AVLTree arv;
	int opc;
	while (true){
	system("cls");
	cout<<"\n0 - sair do programa";
	cout<< "\n1 - inserir elemento na arvore";
	cout<< "\n2 - imprimir a arvore em ordem";
	cout<< "\n3 - imprimir a arvore em pre ordem";
	cout<< "\n4 - imprimir a arvore em pos ordem";
	cout<< "\n5 - imprimir a arvore em ordem reversa";
	cout<< "\n6 - altura da arvore";
	cout<< "\n7 - quantidade de nos da arvore";
	cout<< "\n8 - remover elemento da arvore";
	cout<< "\n9 - verificar se a arvore eh AVL";
	cout<< "\n10 - imprimir a arvore graficamente";
		
	cout<< "\n\nOpcao: ";
	
	cin >> opc;
	if (opc == 0) {
		break;
	} else if (opc == 1) {
		cout << "\nValor do novo elemento: ";
		int dado;
		cin >> dado;
		arv.inserir(dado);						
	} else if (opc == 2) {
		arv.inOrder();
		system("pause");						
	} else if (opc == 3) {
		arv.preOrder();
		system("pause");									
	} else if (opc == 4) {
		arv.posOrder();
		system("pause");				
	} else if (opc == 5) {
		arv.reverseOrder();
		system("pause");					
	} else if (opc == 6) {
		cout << "Altura: " << arv.height() << endl;;
		system("pause");					
	} else if (opc == 7) {
		cout << "Qde nos: " << arv.qtNodes() << endl;
		system("pause");						
	}else if (opc == 8){
		cout << "\nValor do elemento a ser removido: ";
		int dado;
		cin >> dado;
		arv.remove(dado);		
    }else if (opc == 9) {
      bool avl = arv.isAVL();
      (avl == false) ? cout << "\nA árvore não é AVL.\n" : cout << "\nA árvore é AVL.\n";
      system("pause");
    }else if (opc == 10) {
      cout << "\nImprimindo a árvore deitada com sua altura em colchetes: \n";
      arv.print();
      system("pause");
    }
	}
	return 0;
}
