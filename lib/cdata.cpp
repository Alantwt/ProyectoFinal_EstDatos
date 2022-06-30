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
    return i+1;
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

int Fcarros::searchBy(char* carroTam, char* carroTipo, char* carroMarca){
    int lenCarros = readCarro();
    free(carrosF);
    carrosF = (Carro*)calloc(1,sizeof(Carro));
    int i = 0;
    
    for(int j = 0; j <= lenCarros-1; j++){
        if((strcmp((carros+j)->carroMarca,carroMarca) == 0)&&(strcmp((carros+j)->carroTam,carroTam) == 0)&&(strcmp((carros+j)->carroTipo,carroTipo)== 0)){
            // printf("\n----------------------\n");
            // puts((carros+j)->carroMarca);
            // puts((carros+j)->carroTam);
            // puts((carros+j)->carroModelo);
            // puts((carros+j)->carroTipo);
            
            strcpy((carrosF+i)->carroMarca,(carros+j)->carroMarca);
            strcpy((carrosF+i)->carroTam,(carros+j)->carroTam);
            strcpy((carrosF+i)->carroTipo,(carros+j)->carroTipo);
            strcpy((carrosF+i)->carroModelo,(carros+j)->carroModelo);
            
            // printf("\n___________________________\n");
            // puts((carrosF+i)->carroMarca);
            // puts((carrosF+i)->carroTam);
            // puts((carrosF+i)->carroModelo);
            // puts((carrosF+i)->carroTipo);
            i++;
            carrosF = (Carro*)realloc(carrosF,(i+1)*(sizeof(Carro)));
        }
    }
    if(carrosF == NULL)return 0;
    return i;
}   