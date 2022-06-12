// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA: 32074964

#include <iostream>
#include <clocale>
#include "ArvoreBST.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "pt_BR");
    cout << "TAD BST - Binary Search Tree\n";
    int op = 0;
    Tree* bst = new Tree();
    cout << "\n --------- Teste do programa TAD BST ---------";
    cout << "\n\nOBS: A árvore aceita apenas inteiros diferentes de -1\n";
    do
    {
        cout << "\n ------------------- MENU -------------------\n";
        cout << "\nOpções:\n";
        cout << "0 - Sair do programa\n";
        cout << "1 - Verificar raiz da árvore\n";
        cout << "2 - Inserir nó na árvore\n";
        cout << "3 - Procurar elemento na árvore\n";
        cout << "4 - Busca do pai de um elemento na árvore\n";
        cout << "5 - Imprimir a árvore com o percurso em-ordem\n";
        cout << "6 - Remover nó da árvore\n";
        cout << "7 - Esvaziar a árvore\n";
        cout << "8 - Altura da árvore\n";
        cout << "9 - Menor valor da árvore\n";
        cout << "10 - Maior valor da árvore\n";
        cout << "11 - Número de nós folhas na árvore\n";
        cout << "12 - Número de nós na árvore\n";
        cout << "\nOpção selecionada: ";
        cin >> op;
        while (op > 12|| op < 0)
        {
            cout << "\nOperação inválida! Por favor, digite novamente: ";
            cin >> op;
        }
        switch (op)
        {
        case 1:
            cout << "\nRaiz atual da árvore: ";
            (bst->GetRoot() == nullptr) ? cout << "árvore vazia!\n" : cout << bst->GetRoot()->GetKey() << "\n";
            break;
        case 2:
            int addKey;
            cout << "\nDigite a chave do nó que deseja inserir na árvore: ";
            cin >> addKey;
            bool flag;
            flag = bst->Insert(addKey, bst->GetRoot());
            (flag == true) ? cout << "\nNó inserido com sucesso!\n" : 
                cout << "Não foi possível inserir o nó na árvore pois este já está localizado na árvore.\n";
            break;
        case 3:
            int searchKeyA;
            cout << "\nDigite a chave do nó que deseja procurar na árvore: ";
            cin >> searchKeyA;
            Node* temp;
            temp = bst->Search(searchKeyA, bst->GetRoot());
            (temp == nullptr) ? cout << "\nNó não encontrado na árvore!\n" : cout << "\nO nó " << temp->GetKey() << " foi encontrado na árvore!\n";
            break;
        case 4:
            int searchKeyB;
            cout << "\nDigite a chave do nó cujo pai deseja procurar na árvore: ";
            cin >> searchKeyB;
            Node* temp2;
            temp2 = bst->SearchParent(searchKeyB, bst->GetRoot(), nullptr);
            (temp2 == nullptr) ? cout << "\nNó pai não encontrado na árvore!\n" : cout << "\nNó pai: " << temp2->GetKey() << "\n";
            break;
        case 5:
            (bst->GetRoot() == nullptr) ? cout << "\nÁrvore vazia!\n" : cout << "\nImprimindo a árvore no percurso E-R-D (em-ordem)...\n";
            bst->EmOrdem(bst->GetRoot());
            cout << "\n";
            break;
        case 6:
            int removeKey;
            cout << "\nDigite a chave do nó que quer remover da árvore: ";
            cin >> removeKey;
            int removed;
            removed = bst->Remove(removeKey);
            if (removed == -1) cout << "\nNão foi possível remover o nó, pois este não se encontra na árvore.\n";
            else cout << "\nO elemento de chave " << removed << " foi removido com sucesso!\n";
            break;
        case 7:
            cout << "\nEsvaziando a árvore...\n";
            bst->Clear(bst->GetRoot());
            break;
        case 8:
            cout << "\nA altura da árvore é: " << bst->Height(bst->GetRoot()) << "\n";
            break;
        case 9:
            cout << "\nO menor valor da árvore é: " << bst->menorValor(bst->GetRoot()) << "\n";
            break;
        case 10:
            cout << "\nO maior valor da árvore é: " << bst->maiorValor(bst->GetRoot()) << "\n";
            break;
        case 11:
            int countLeaf;
            countLeaf = bst->numFolhas(bst->GetRoot(), 0);
            (countLeaf == -1) ? cout << "\nÁrvore vazia!\n" : cout << "\nNúmero de nó folhas: " << countLeaf << "\n";
            break;
        case 12:
            int countNode;
            countNode = bst->contaNos(bst->GetRoot(), 0);
            (countNode == -1) ? cout << "\nÁrvore vazia!\n" : cout << "\nNúmero de nós na árvore: " << countNode << "\n";
            break;
        }
    } while (op != 0);
    cout << "\nEncerrando o programa...\n";
    bst->Clear(bst->GetRoot());
}

