#include "../include/cdata.h"



Fcarros::Fcarros(char* _file){
    file = _file;
    carrosTotal = (Carro*)calloc(1,sizeof(Carro));
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
        
        fread((carrosTotal+i),sizeof(Carro),1,archivo);
        _putws((carrosTotal+i)->carroPath);
        printf("Entra\n");
        while(feof(archivo) == 0){
            i++;
            carrosTotal = (Carro*)realloc(carrosTotal,(i+1)*(sizeof(Carro)));
            fread((carrosTotal+i),sizeof(Carro),1,archivo);
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

int Fcarros::readCarroBy(wchar_t* Smarca, wchar_t* Stipo, wchar_t* Stam){
    free(carros);
    int lenCarrosT = readCarro();
    int lenCarros = 0;
    carros = (Carro*)calloc(1,sizeof(Carro));
    for(int i = 0; i <= lenCarrosT; i++){
        if((wcscmp((carrosTotal+i)->carroMarca, Smarca) == 0)&&(wcscmp((carrosTotal+i)->carroTam, Stam) == 0)&&(wcscmp((carrosTotal+i)->carroTipo, Stipo) == 0)){
            wcscpy((carros+lenCarros)->carroMarca,(carrosTotal+i)->carroMarca);
            wcscpy((carros+lenCarros)->carroModelo,(carrosTotal+i)->carroModelo);
            wcscpy((carros+lenCarros)->carroTam,(carrosTotal+i)->carroTam);
            wcscpy((carros+lenCarros)->carroTipo,(carrosTotal+i)->carroTipo);
            wcscpy((carros+lenCarros)->carroPath,(carrosTotal+i)->carroPath);
            lenCarros++;
            carros = (Carro*)realloc(carros,(lenCarros+1)*(sizeof(Carro)));
        }
    }
    printf("len carros: %d\n",lenCarros);
    return lenCarros;
}