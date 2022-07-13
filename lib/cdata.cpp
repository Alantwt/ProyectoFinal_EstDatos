#include "../include/cdata.h"



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

int Fcarros::addCarro(wchar_t* Smarca, wchar_t* Stipo, wchar_t* Smodelo, wchar_t* Stam, wchar_t* Spath){
    archivo = fopen(file,"ab");
    Carro carro;
    if(archivo != NULL){
        wcscpy(carro.carroMarca,Smarca);
        wcscpy(carro.carroModelo,Smodelo);
        wcscpy(carro.carroTam,Stam);
        wcscpy(carro.carroTipo,Stipo);
        wcscpy(carro.carroPath,Spath);
        _putws(carro.carroMarca);
        _putws(carro.carroModelo);
        _putws(carro.carroTam);
        _putws(carro.carroTipo);
        _putws(carro.carroPath);
        int canElem = fwrite(&carro,sizeof(Carro),1,archivo);
        fclose(archivo);
        return canElem;
    }
}

int Fcarros::readCarro(){
    int i = 0;
    if(verifyFileExist(file)){
        archivo  = fopen(file,"rb");
        
        fread((carros+i),sizeof(Carro),1,archivo);
        _putws((carros+i)->carroPath);
        printf("Entra\n");
        while(feof(archivo) == 0){
            i++;
            carros = (Carro*)realloc(carros,(i+1)*(sizeof(Carro)));
            fread((carros+i),sizeof(Carro),1,archivo);
        }

        fclose(archivo);
        return i;
    }
    else return 0;
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