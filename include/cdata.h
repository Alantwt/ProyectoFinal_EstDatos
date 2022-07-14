#ifndef _CDATA
#define _CDATA
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#include "../include/funciones.h"

struct Carro{
    wchar_t carroTam[20];
    wchar_t carroTipo[20];
    wchar_t carroMarca[20];
    wchar_t carroModelo[20];
    wchar_t carroPath[30];
};

class Fcarros{
    FILE* archivo;
    char* file;
    
public:
    Carro* carrosTotal;
    Carro* carros;
    Fcarros(char* _file);
    bool createFile();
    int addCarro(wchar_t* Smarca, wchar_t* Stipo, wchar_t* Smodelo, wchar_t* Stam, wchar_t* Spath);
    int readCarro();
    int readCarroBy(wchar_t* Smarca, wchar_t* Stipo, wchar_t* Stam);
    bool verifyFileExist(char* file);
    bool deleteFile();
};

#include "../lib/cdata.cpp"

#endif