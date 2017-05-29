#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include "bib.h"

using namespace std;

// Codificacao preditiva + compressao jpg
bool predificar(string filename) {
    ifstream entrada(filename);
    ofstream residuo("residuo.raw");

    unsigned char file[512][512], data[512][512];

    // Le entrada
    for (int i = 0; i < 512; ++i) {
        for (int j = 0; j < 512; ++j) {
            entrada >> file[i][j];
        }
    }

    entrada.close();

    // Imagem predita : cada linha eh a copia do primeiro pixel daquela linha na imagem original
    for (int i = 0; i < 512; ++i) {
        for (int j = 0; j < 512; ++j) {
            data[i][j] = file[i][0];
        }
    }

    // Residuo : imagem original - predicao
    for (int i = 0; i < 512; ++i) {
        for (int j = 1; j < 512; ++j) {
            data[i][j] = max(0, file[i][j] - data[i][j]);
        }
    }

    // Arquivo de residuo
    for (int i = 0; i < 512; ++i) {
        for (int j = 0; j < 512; ++j) {
            residuo << data[i][j];
        }   
    }

    residuo.close();

    // Compressao jpg
    jo_write_jpg("lena.jpg", data, 512, 512, 1, 90);

    return true;
}

int main() {
    predificar("lena.raw");
    return 0;
}