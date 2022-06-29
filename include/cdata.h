#ifndef _CDATA
#define _CDATA
#include <stdio.h>

struct Carro{
    char carroTam[20];
    char carroTipo[20];
    char carroMarca[20];
    char carroModelo[20];
};

class Fcarros{
    FILE* archivo;
    char* file;
    
public:
    Carro* carros;
    Fcarros(char* _file);
    bool createFile();
    int addCarro(char* Smarca, char* Stipo, char* Smodelo, char* Stam);
    int readCarro();
    bool verifyFileExist(char* file);
    bool deleteFile();
};

#include "../lib/cdata.cpp"

#endif