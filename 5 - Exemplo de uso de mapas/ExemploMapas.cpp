#include <iostream>
#include <map>

using namespace std;

void displayInt(map<int, int> mapa)
{
    map <int, int> ::iterator it;
    for (it = mapa.begin(); it != mapa.end(); it++)
    {
        cout << "Chave: " << it->first << "; Valor: " << it->second << "\n";
    }
    cout << "\n";
}

void displayStr(map<int, string> mapa)
{
    map <int, string> ::iterator it;
    for (it = mapa.begin(); it != mapa.end(); it++)
    {
        cout << "Chave: " << it->first << "; Valor: " << it->second << "\n";
    }
    cout << "\n";
}

int main()
{
    // Mapa com chave int e valor int
    map<int, int> mp1 = { {1, 4}, {2, 6} };
    mp1.insert(pair<int, int>(3, 5));
    displayInt(mp1);

    // Mapa com chave int e valor string
    map<int, string> mp2;
    mp2[8] = "Diego";
    mp2[3] = "Lucas";
    mp2[10] = "Kaori";
    mp2.insert(pair<int, string>(6, "Rodolfo"));
    displayStr(mp2);

    // Removendo o elemento cuja chave é 3
    mp2.erase(3);
    displayStr(mp2);
}

