#include <iostream>
#include <fstream>
#include "bib.h"

using namespace std;

bool despredificar(string res) {
    ifstream entrada(res);
    ofstream resultado("novaLena.raw");

    unsigned char residuo[512][512], predita[512];

    // Le arquivo de residuo e gera vetor de predicao
    for (int i = 0; i < 512; ++i) {
        for (int j = 0; j < 512; ++j) {
            entrada >> residuo[i][j];
        }
        predita[i] = residuo[i][0];
    }

    entrada.close();

    // Restaura imagem original atraves da soma do vetor de predicao com a imagem de residuo
    for (int i = 0; i < 512; ++i) {
        for (int j = 0; j < 512; ++j) {
            if (j == 0) {
                resultado << predita[i];
            }
            else {
                resultado << min(255, predita[i] + residuo[i][j]);
            }
        }
    }

    resultado.close();

    return true;
}

int main() {
    despredificar("residuo.raw");
    return 0;
}