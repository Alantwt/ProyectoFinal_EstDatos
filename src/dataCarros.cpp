#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#include "../include/funciones.h"
#include "../include/cdata.h"

//Archivo donde se alacenan los datos
char CARROS_FILE[] = "../data/CarroData.alan";

Fcarros carrosFile(CARROS_FILE);

void insertarDatos();
void leerData();


int main(){
    system("cls");
    char keypressed;
    int option = 1;


    //MENU
    printf("Escoja una opcion: \n");
    printf("Crear el archivo binario\n");
    printf("Isertar Datos al archivo\n");
    printf("Leer Datos del archivo\n");
    printf("Borrar todos los datos\n");
    printf("Exit");

    while(true){
        
        keypressed = getch();
        movePointer(30,option);
        printf(" ");
        if(keypressed == T_DOWN && option <= 4){
            option++;
        } 
        else if(keypressed == T_UP && option > 1){
            movePointer(20,21);
            option--;
        }
        else if(keypressed == ENTER){
            movePointer(10,10);
            if(option == 1){
                bool fileExist = carrosFile.createFile();
                movePointer(5,7);
                printf("                                             ");
                if(fileExist == true){
                    movePointer(5,7);
                    printf("Creado con exito");
                }
                else{
                    movePointer(5,7);
                    printf("El archivo ya existe o ocurrion un error");
                }
            }
            else if(option == 2){
                insertarDatos();
            }
            else if(option == 3){
                leerData();
            }
            else if(option == 4){
                carrosFile.deleteFile();
            }
            else if(option == 5){
                exit(1);
            }
        }
        movePointer(30,option);
        printf("%c",17);
    }
}

void insertarDatos(){
    system("cls");
    printf("Presione Enter para agregar autos o presione ESC para terminar de agregarlos\n");
    char keypressed = ' ';
    char Smarca[20],Stam[20],Stipo[20],Smodelo[20];
    int var, len = 0;

    while(true){
        len++;
        keypressed = getch();
        if(keypressed == ESC)break;
        else if(keypressed = ENTER){
            //Marca del carro
            printf("Escoja una Marca:\n1.Toyota\n2.Nissan\n3.GMC\n4.Cat\n");
            scanf("%d",&var);
            if(var == 1)strcpy(Smarca,"toyota");
            else if(var == 2)strcpy(Smarca,"nissan");
            else if(var == 3)strcpy(Smarca,"gmc");
            else if(var == 4)strcpy(Smarca,"cat");

            //Tamaño del carro
            printf("Escoja el Tama%co del carro:\n1Grande\n2.Mediano\n3.Peque%co\n",164,164);
            scanf("%d",&var);
            if(var == 1)strcpy(Stam,"grande");
            else if(var == 2)strcpy(Stam,"mediano");
            else if(var == 3)strcpy(Stam,"pequeño");

            //Tipo de Carro
            printf("Escoja el tipo del carro:\n1.Personal\n2.Comercial\n3.Construccion\n");
            scanf("%d",&var);
            if(var == 1)strcpy(Stipo,"personal");
            else if(var == 2)strcpy(Stipo,"comercial");
            else if(var == 3)strcpy(Stipo,"construccion");

            //Modelo del carro
            printf("Introdusca el modelo del carro: ");
            fflush(stdin);
            gets(Smodelo);

            movePointer(0,20);
            printf("                                             ");
            movePointer(0,20);
            printf("Elementos Agregados: %d",carrosFile.addCarro(Smarca,Stipo,Smodelo,Stam));
        }
    }

    main();
}

void leerData(){
    int lenFile = carrosFile.readCarro();

    for(int u = 0; u <= lenFile-1; u++){
        puts((carrosFile.carros+u)->carroMarca);
        puts((carrosFile.carros+u)->carroModelo);
        puts((carrosFile.carros+u)->carroTam);
        puts((carrosFile.carros+u)->carroTipo);
    }
}