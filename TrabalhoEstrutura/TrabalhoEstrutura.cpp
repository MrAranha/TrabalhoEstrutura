// TrabalhoEstrutura.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<random>
#include <chrono>
#include "SortingMethods.h";

using namespace std;
using namespace std::chrono;
int main()
{
    const int vetorSize = 10000;
    unsigned int vetor[vetorSize];
    //Random random = new Random();
    
    for (int i = 0; i < vetorSize; i++)
    {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_real_distribution<double> dist(0.0f, 1.0f);
        vetor[i] = (int)(vetorSize * dist(mt));
    }

    nanoseconds timeIni = duration_cast<nanoseconds>(
        system_clock::now().time_since_epoch()
    );

    //ALTERARAQUI
    SortingMethods::BucketSort(vetor, vetorSize);

    nanoseconds timeEnd = duration_cast<nanoseconds>(
        system_clock::now().time_since_epoch()
    );
    auto totalNanoseconds = timeEnd - timeIni;
    double ms = totalNanoseconds.count() / 1e6;

    
    cout << "Vetor ordenado:\n";
    for (int i = 0; i < vetorSize; i++) {
        cout << vetor[i] << "\n";
    }
    //O timer para de contar antes de escrever a array no terminal, mas eu coloquei no final para facilitar a leitura :D
    cout << "Tempo para conclusao: " << ms << " milissegundos";
}