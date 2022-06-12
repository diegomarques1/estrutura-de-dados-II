// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA: 32074964

#include "BookInfo.h"

BookInfo::BookInfo()
{
	m_ISBN = 0;
	m_Year = 0;
	m_Price = 0.0;
	for (int i = 0; i < 50; i++)
	{
		m_Author[i] = ' ';
		m_Title[i] = ' ';
	}
	for (int k = 0; k < 15; k++) m_Publisher[k] = ' ';
}

BookInfo::BookInfo(long int key, char author[50], char title[50], char publisher[15], int year, float price)
{
	m_ISBN = key;
	m_Year = year;
	m_Price = price;
	int i = 0;
	while (i < 50)
	{
		m_Author[i] = author[i];
		m_Title[i] = title[i];
		i++;
	}
	i = 0;
	while (i < 15) m_Publisher[i] = 0;
}

BookInfo BookInfo::RegistrarLivro()
{
	BookInfo book = BookInfo();
	long int ISBN;
	char author[50], title[50], publisher[15];
	int year;
	float price;
	std::cout << "\nDigite o ISBN do livro: "; // não colocar número maior que 2147483647, limite do long int.
	std::cin >> ISBN;
	while (ISBN < 1000000000)
	{
		std::cout << "ISBN inválido! Por favor, digite um código de 10 dígitos: ";
		std::cin >> ISBN;
	}
	book.SetISBN(ISBN);
	std::cout << "\nDigite o autor do livro: ";
	std::cin >> author;
	book.SetAuthor(author);
	std::cout << "\nDigite o título do livro: ";
	std::cin >> title;
	book.SetTitle(title);
	std::cout << "\nDigite a editora do livro: ";
	std::cin >> publisher;
	book.SetPublisher(publisher);
	std::cout << "\nDigite o ano de publicação do livro: ";
	std::cin >> year;
	while (year < 0 || year > 2021)
	{
		std::cout << "Ano inválido! Por favor, digite novamente: ";
		std::cin >> year;
	}
	book.SetYear(year);
	std::cout << "\nDigite o preço do livro: ";
	std::cin >> price;
	while (price < 0.0)
	{
		std::cout << "Preço inválido! Por favor, digite novamente: ";
		std::cin >> price;
	}
	book.SetPrice(price);
	return book;
}

int BookInfo::GetISBN() const
{
	return m_ISBN;
}

void BookInfo::SetISBN(long int key)
{
	m_ISBN = key;
}

std::string BookInfo::GetAuthor() const
{
	std::string temp;
	for (char c : m_Author)
	{
		if (c != 'Ì')
		temp += c;
	}
	return temp;
}

void BookInfo::SetAuthor(char author[])
{
	int count = 0;
	while (count < 50)
	{
		m_Author[count] = author[count];
		count++;
	}
}

std::string BookInfo::GetTitle() const
{
	std::string temp;
	for (char c : m_Title)
	{
		if (c != 'Ì')
		temp += c;
	}
	return temp;
}

void BookInfo::SetTitle(char title[])
{
	int count = 0;
	while (count < 50)
	{
		m_Title[count] = title[count];
		count++;
	}
}

std::string BookInfo::GetPublisher() const
{
	std::string temp;
	for (char c : m_Publisher)
	{
		if (c != 'Ì')
		temp += c;
	}
	return temp;
}

void BookInfo::SetPublisher(char publisher[])
{
	int count = 0;
	while (count < 15)
	{
		m_Publisher[count] = publisher[count];
		count++;
	}
}

int BookInfo::GetYear() const
{
	return m_Year;
}

void BookInfo::SetYear(int year)
{
	m_Year = year;
}

float BookInfo::GetPrice() const
{
	return m_Price;
}

void BookInfo::SetPrice(float price)
{
	m_Price = price;
}