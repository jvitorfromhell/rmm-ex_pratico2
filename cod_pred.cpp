#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include "bib.h"

using namespace std;

bool predificar(string filename) {
    ifstream entrada(filename);
    ofstream residuo("residuo.raw");

    unsigned char file[512][512], data[512][512];

    for (int i = 0; i < 512; ++i) {
        for (int j = 0; j < 512; ++j) {
            entrada >> file[i][j];
        }
    }

    entrada.close();

    for (int i = 0; i < 512; ++i) {
        data[0][i] = file[0][i];
        data[i][0] = file[i][0];
    }

    for (int i = 1; i < 512; ++i) {
        for (int j = 1; j < 512; ++j) {
            data[i][j] = max(0, max(file[i][j] - file[0][j], file[i][j] - file[i][0]));
        }
    }

    for (int i = 0; i < 512; ++i) {
        for (int i = 0; i < 512; ++i) {
            residuo << file[i][j] - data[i][j];
        }   
    }

    residuo.close();

    jo_write_jpg("lena.jpg", data, 512, 512, 1, 90);

    return true;
}

int main() {
    predificar("lena.raw");
    return 0;
}