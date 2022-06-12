// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA: 32074964

// Implementação do nó da árvore

#include "AVLNode.h"

using namespace std;

AVLNode::AVLNode() // construtor padrão da classe
{
    left = nullptr;
    right = nullptr;
    m_Name = " ";
    m_State = " ";
    m_City = " ";
    m_Language = " ";
    m_Area = " ";
    height = 0;
}

AVLNode::AVLNode(string name, string state, string city, string language, string area) // construtor da classe com parâmetros fornecidos
{
    left = nullptr;
    right = nullptr;
    m_Name = name;
    m_State = state;
    m_City = city;
    m_Language = language;
    m_Area = area;
    height = 0;
}

AVLNode::~AVLNode() // destrutor da classe
{
}

string AVLNode::getName()
{
    return m_Name;
}

void AVLNode::setName(string name)
{
    m_Name = name;
}

string AVLNode::getState()
{
    return m_State;
}

void AVLNode::setState(string state)
{
    m_State = state;
}

string AVLNode::getCity()
{
    return m_City;
}

void AVLNode::setCity(string city)
{
    m_City = city;
}

string AVLNode::getLanguage()
{
    return m_Language;
}

void AVLNode::setLanguage(string language)
{
    m_Language = language;
}

string AVLNode::getArea()
{
    return m_Area;
}

void AVLNode::setArea(string area)
{
    m_Area = area;
}

void AVLNode::setLeft(AVLNode* n)
{
    left = n;
}

AVLNode* AVLNode::getLeft()
{
    return left;
}

void AVLNode::setRight(AVLNode* n)
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
