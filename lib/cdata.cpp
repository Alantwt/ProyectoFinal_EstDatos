#include "../include/cdata.h"
#include "../include/funciones.h"

#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

Fcarros::Fcarros(char* _file){
    file = _file;
    carros = (Carro*)calloc(1,sizeof(Carro));
}

bool Fcarros::createFile(){
    if(verifyFileExist(file) != true){
        archivo = fopen(file,"ab");
        fclose(archivo);
        return true;
    }
    else return false;
}

int Fcarros::addCarro(char* Smarca, char* Stipo, char* Smodelo, char* Stam){
    archivo = fopen(file,"ab");
    Carro carro;
    if(archivo != NULL){
        strcpy(carro.carroMarca,Smarca);
        strcpy(carro.carroModelo,Smodelo);
        strcpy(carro.carroTam,Stam);
        strcpy(carro.carroTipo,Stipo);
        puts(carro.carroMarca);
        puts(carro.carroModelo);
        puts(carro.carroTam);
        puts(carro.carroTipo);
        int canElem = fwrite(&carro,sizeof(Carro),1,archivo);
        fclose(archivo);
        return canElem;
    }
}

int Fcarros::readCarro(){
    int i = 0;
    archivo  = fopen(file,"rb");

    fread((carros+i),sizeof(Carro),1,archivo);

    while(feof(archivo) == 0){
        i++;
        carros = (Carro*)realloc(carros,(i+1)*(sizeof(Carro)));
        fread((carros+i),sizeof(Carro),1,archivo);
    }

    fclose(archivo);
    return i;
}

bool Fcarros::verifyFileExist(char* _file){
    struct stat buffer;
    if(stat(_file,&buffer) == 0){
        return true;//el fichero esta creado
    }
    else return false;//el fichero no ah sido creado
}

bool Fcarros::deleteFile(){
    archivo = fopen(file,"wb+");
}