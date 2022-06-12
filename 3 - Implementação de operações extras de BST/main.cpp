// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gon�alves - TIA: 32074964

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
    cout << "\n\nOBS: A �rvore aceita apenas inteiros diferentes de -1\n";
    do
    {
        cout << "\n ------------------- MENU -------------------\n";
        cout << "\nOp��es:\n";
        cout << "0 - Sair do programa\n";
        cout << "1 - Verificar raiz da �rvore\n";
        cout << "2 - Inserir n� na �rvore\n";
        cout << "3 - Procurar elemento na �rvore\n";
        cout << "4 - Busca do pai de um elemento na �rvore\n";
        cout << "5 - Imprimir a �rvore com o percurso em-ordem\n";
        cout << "6 - Remover n� da �rvore\n";
        cout << "7 - Esvaziar a �rvore\n";
        cout << "8 - Altura da �rvore\n";
        cout << "9 - Menor valor da �rvore\n";
        cout << "10 - Maior valor da �rvore\n";
        cout << "11 - N�mero de n�s folhas na �rvore\n";
        cout << "12 - N�mero de n�s na �rvore\n";
        cout << "\nOp��o selecionada: ";
        cin >> op;
        while (op > 12|| op < 0)
        {
            cout << "\nOpera��o inv�lida! Por favor, digite novamente: ";
            cin >> op;
        }
        switch (op)
        {
        case 1:
            cout << "\nRaiz atual da �rvore: ";
            (bst->GetRoot() == nullptr) ? cout << "�rvore vazia!\n" : cout << bst->GetRoot()->GetKey() << "\n";
            break;
        case 2:
            int addKey;
            cout << "\nDigite a chave do n� que deseja inserir na �rvore: ";
            cin >> addKey;
            bool flag;
            flag = bst->Insert(addKey, bst->GetRoot());
            (flag == true) ? cout << "\nN� inserido com sucesso!\n" : 
                cout << "N�o foi poss�vel inserir o n� na �rvore pois este j� est� localizado na �rvore.\n";
            break;
        case 3:
            int searchKeyA;
            cout << "\nDigite a chave do n� que deseja procurar na �rvore: ";
            cin >> searchKeyA;
            Node* temp;
            temp = bst->Search(searchKeyA, bst->GetRoot());
            (temp == nullptr) ? cout << "\nN� n�o encontrado na �rvore!\n" : cout << "\nO n� " << temp->GetKey() << " foi encontrado na �rvore!\n";
            break;
        case 4:
            int searchKeyB;
            cout << "\nDigite a chave do n� cujo pai deseja procurar na �rvore: ";
            cin >> searchKeyB;
            Node* temp2;
            temp2 = bst->SearchParent(searchKeyB, bst->GetRoot(), nullptr);
            (temp2 == nullptr) ? cout << "\nN� pai n�o encontrado na �rvore!\n" : cout << "\nN� pai: " << temp2->GetKey() << "\n";
            break;
        case 5:
            (bst->GetRoot() == nullptr) ? cout << "\n�rvore vazia!\n" : cout << "\nImprimindo a �rvore no percurso E-R-D (em-ordem)...\n";
            bst->EmOrdem(bst->GetRoot());
            cout << "\n";
            break;
        case 6:
            int removeKey;
            cout << "\nDigite a chave do n� que quer remover da �rvore: ";
            cin >> removeKey;
            int removed;
            removed = bst->Remove(removeKey);
            if (removed == -1) cout << "\nN�o foi poss�vel remover o n�, pois este n�o se encontra na �rvore.\n";
            else cout << "\nO elemento de chave " << removed << " foi removido com sucesso!\n";
            break;
        case 7:
            cout << "\nEsvaziando a �rvore...\n";
            bst->Clear(bst->GetRoot());
            break;
        case 8:
            cout << "\nA altura da �rvore �: " << bst->Height(bst->GetRoot()) << "\n";
            break;
        case 9:
            cout << "\nO menor valor da �rvore �: " << bst->menorValor(bst->GetRoot()) << "\n";
            break;
        case 10:
            cout << "\nO maior valor da �rvore �: " << bst->maiorValor(bst->GetRoot()) << "\n";
            break;
        case 11:
            int countLeaf;
            countLeaf = bst->numFolhas(bst->GetRoot(), 0);
            (countLeaf == -1) ? cout << "\n�rvore vazia!\n" : cout << "\nN�mero de n� folhas: " << countLeaf << "\n";
            break;
        case 12:
            int countNode;
            countNode = bst->contaNos(bst->GetRoot(), 0);
            (countNode == -1) ? cout << "\n�rvore vazia!\n" : cout << "\nN�mero de n�s na �rvore: " << countNode << "\n";
            break;
        }
    } while (op != 0);
    cout << "\nEncerrando o programa...\n";
    bst->Clear(bst->GetRoot());
}

