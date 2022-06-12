// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA: 32074964

#include <iostream>

#ifndef __BOOK_INFO_H__
#define __BOOK_INFO_H__

class BookInfo
{
public:
	BookInfo();
	BookInfo(long int key, char author[50], char title[50], char publisher[15], int year, float price);

	BookInfo RegistrarLivro();

	// Getters e Setters

	int GetISBN() const;
	void SetISBN(long int key);

	std::string GetAuthor() const;
	void SetAuthor(char author[]);

	std::string GetTitle() const;
	void SetTitle(char title[]);

	std::string GetPublisher() const;
	void SetPublisher(char publisher[]);

	int GetYear() const;
	void SetYear(int year);

	float GetPrice() const;
	void SetPrice(float price);

private:
	long int m_ISBN; // chave do node
	char m_Author[50];
	char m_Title[50];
	char m_Publisher[15];
	int m_Year;
	float m_Price;
};

#endif 