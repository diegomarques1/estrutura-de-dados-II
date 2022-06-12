// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA: 32074964

// Arquivo para teste com menu de operações

#include <iostream>
#include <fstream>
#include "AVLTree.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "pt_BR"); // dependendo do arquivo, colocar "" ou "pt_BR.UTF-8" para acentuação
	AVLTree* arv = new AVLTree();
	string op = " "; // opção como string por causa do getline e para validar dados mais amplamente
	cout << "\n--------------- Projeto 02 - Estrutura de Dados II ---------------\n";
	cout << "\nCriacao de cadastro de prestadores de servicos turisticos do Brasil\n";
	cout << "Para comecar, digite o nome do arquivo Excel a partir do qual a arvore sera construida: ";
	string archive_Name;
	getline(cin, archive_Name);
	arv->createTree(archive_Name);
	while (arv->isEmpty() == true) // validação de dados possíveis (se a árvore está vazia, o arquivo digitado não existe na pasta)
	{
		cout << "Arquivo vazio ou invalido! Por favor, digite novamente o nome do arquivo .csv: ";
		getline(cin, archive_Name);
		arv->createTree(archive_Name);
	}
	cout << "\nArvore criada com sucesso!\n";
	do
	{
		cout << "\n------------------------------ MENU ------------------------------\n";
		cout << "\nOperacoes validas:\n";
		cout << "\n0 - Sair do programa\n";
		cout << "\n1 - Pesquisar prestador no cadastro da arvore\n";
		cout << "\n2 - Imprimir a arvore em ordem alfabetica\n";
		cout << "\nOpcao: ";
		getline(cin, op);
		while (op != "0" && op != "1" && op != "2") // validação de dados da operação
		{
			cout << "\nOperacao invalida! Por favor, digite novamente: ";
			getline(cin, op);
		}
		if (op == "1") 
		{
			string name;
			cout << "\nDigite o nome completo do(a) prestador(a) a ser buscado na arvore: ";
			getline(cin, name); // armazena o nome completo (linha inteira, e não só até o primeiro espaço, como no cin)
			int i = 0;
			for (char c : name)
			{
				name[i] = toupper(name[i]); // coloca a string digitada em letra maiúscula (toupper)
				i++;
			}
			i = 0;
			AVLNode* temp = arv->search(name);
			if (temp == nullptr) cout << "\nO(A) prestador(a) nao foi encontrado(a) na arvore.\n";
			else
			{
				cout << "\nPrestador(a) encontrado(a)! Exibindo suas informacoes gerais: \n\n";
				arv->generalInfo(temp);
			}
		}
		else if (op == "2") 
		{
			if (arv->isEmpty() == false) // se a árvore não está vazia, imprime em ordem alfabética
			{
				cout << "\nImprimindo a arvore em ordem alfabetica: \n\n";
				arv->inOrder();
			}
			else cout << "\nArvore vazia!";
		}
	} while (op != "0"); // se a operação for 0, sai do menu e encerra o programa
	cout << "\nEncerrando o programa...\n";
}