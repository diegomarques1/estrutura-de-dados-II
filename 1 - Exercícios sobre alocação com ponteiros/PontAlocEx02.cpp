// Crie uma função que receba como parâmetros dois vetores de inteiros: x1 e x2 e 
// as suas respectivas quantidades de elementos: n1 e n2. A função deverá retornar
// um ponteiro para um terceiro vetor, x3, alocado dinamicamente, contendo a intersecção
// de x1 e x2 e usar o ponteiro qtd para retornar o tamanho de x3.
// Sendo x1 = {1, 3, 5, 6, 7} e x2 = {1, 3, 4, 6, 8}, x3 irá conter {1, 3, 6}
// Assinatura da função: 
// int* interseccao(int *x1, int *x2, int n1, int n2, int *qtd);

#include <iostream>

using namespace std;

int* interseccao(int* x1, int* x2, int n1, int n2, int* qtd) // Não consegui pensar em uma solução que não fosse O(n^2)
{
    *qtd = 0;
    bool flag = false;
    for (int i = 0; i < n1; ++i)
    {
        for (int k = 0; k < n2; ++k)
        {
            if (x2[k] == x1[i])
            {
                flag = true;
            }
        }
        if (flag == true) ++*qtd;
        flag = false;
    }
    int* x3 = new int[*qtd];
    flag = false;
    int temp = 0;
    for (int i = 0; i < n1; ++i)
    {
        for (int k = 0; k < n2; ++k)
        {
            if (x1[i] == x2[k])
            {
                flag = true;
            }
        }
        if (flag == true)
        {
            x3[temp++] = x1[i];
        }
        flag = false;
    }
    return x3;
}

int main()
{
	int x1[] = { 1, 3, 5, 6, 7 };
	int x2[] = { 1, 3, 4, 6, 8 };
	int n3 = 0;
	int* qtd = &n3;
	int* x3 = interseccao(x1, x2, 5, 5, qtd);
    cout << "Quantidade = " << n3 << "\n";
    cout << "Vet = [";
    for (int i = 0; i < n3 - 1; i++)
    {
        cout << x3[i] << ", ";
    }
    cout << x3[n3 - 1] << "]\n";
    delete[] x3;
}