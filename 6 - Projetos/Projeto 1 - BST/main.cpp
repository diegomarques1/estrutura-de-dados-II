// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA: 32074964

#include <iostream>
#include <clocale>
#include "ArvoreBST.h"

int main()
{
    setlocale(LC_ALL, "pt_BR");
    std::cout << "Projeto 1 - Estrutura de Dados II\n";
    int op = 0;
    Tree* bst = new Tree();
    std::cout << "\n -------------- BANCO DE DADOS DE LIVROS --------------\n";
    std::cout << "\nObservações:\n";
    std::cout << "A árvore aceita apenas inteiros diferentes de - 1\n";
    std::cout << "Não utilizar acentos ou espaços para autores, títulos e editoras\n";
    do
    {
        std::cout << "\n ------------------- MENU -------------------\n";
        std::cout << "\nOpções:\n";
        std::cout << "0 - Sair do programa\n";
        std::cout << "1 - Registrar livro\n";
        std::cout << "2 - Procurar livro\n";
        std::cout << "3 - Remover livro\n";
        std::cout << "4 - Listar acervo\n";
        std::cout << "\nOpção escolhida: \n";
        std::cin >> op;
        while (op > 4 || op < 0)
        {
            std::cout << "\nOperação inválida! Por favor, digite novamente: ";
            std::cin >> op;
        }
        if (op == 1)
        {
            BookInfo book = book.RegistrarLivro();
            std::cout << "Livro registrado!\n";
            char cad;
            std::cout << "Deseja cadastrar o livro registrado? (S/N)\n";
            std::cin >> cad;
            while (toupper(cad) != 'S' && toupper(cad) != 'N')
            {
                std::cout << "Escolha inválida! Por favor, digite S (sim) ou N (não): ";
                std::cin >> cad;
            }
            if (toupper(cad) == 'S')
            {
                bool flag;
                flag = bst->CadastrarLivro(bst->GetRoot(), book);
                (flag == false) ? std::cout << "Um livro com esse ISBN já existe. Não foi possível cadastrar o livro no catálogo.\n"
                    : std::cout << "Livro cadastro com sucesso!\n";
            }
        }
        else if (op == 2)
        {
            long int ISBN;
            std::cout << "Digite o ISBN do livro que deseja procurar: ";
            std::cin >> ISBN;
            Node* temp = bst->ProcurarLivro(bst->GetRoot(), ISBN);
            if (temp == nullptr) std::cout << "Livro não localizado!\n";
            else
            {
                std::cout << "Livro localizado com sucesso!\n";
                char info;
                std::cout << "Deseja exibir as informações do livro? (S/N)\n";
                std::cin >> info;
                while (toupper(info) != 'S' && toupper(info) != 'N')
                {
                    std::cout << "Escolha inválida! Por favor, digite S (sim) ou N (não): ";
                    std::cin >> info;
                }
                if (toupper(info) == 'S') bst->ExibirLivro(temp);
            }
        }
        else if (op == 3)
        {
            long int remove;
            std::cout << "Digite o ISBN do livro que deseja remover: ";
            std::cin >> remove;
            Node* temp = bst->ProcurarLivro(bst->GetRoot(), remove);
            if (temp == nullptr) std::cout << "O livro não foi removido, pois não se encontra no catálogo.\n";
            else
            {
                bst->RemoverLivro(bst->GetRoot(), remove);
                std::cout << "Livro removido com sucesso!\n";
            }
        }
        else if (op == 4)
        {
            if (bst->GetRoot() == nullptr) std::cout << "Sem livros no catálogo!\n";
            else
            {
                std::cout << "Listando os livros presentes no catálogo...\n\n";
                bst->ListarAcervo(bst->GetRoot());
            }
        }
    } while (op != 0);
    std::cout << "\nEncerrando o programa...\n";
    bst->Clear(bst->GetRoot());
}

