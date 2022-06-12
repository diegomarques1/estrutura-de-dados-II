// Faça um programa que leia a quantidade de elementos n e crie dinamicamente um vetor de n elementos
// e passe esse vetor para uma função que irá ler os elementos desse vetor. Depois, no programa
// principal, o vetor preenchido deve ser impresso.

#include <iostream>

using namespace std;

int* popularVetor(int* vet, int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << "\nDigite o elemento " << i + 1 << " do vetor: ";
        cin >> vet[i];
    }
    return vet;
}

int main()
{
    int n;
    cout << "Digite a quantidade de elementos: ";
    cin >> n;
    int* vet = new int[n];
    popularVetor(vet, n);
    cout << "\nVetor = [";
    for (int i = 0; i < n - 1; ++i)
    {
        cout << vet[i] << ", ";
    }
    cout << vet[n - 1] << "]";
    delete[] vet;
}
