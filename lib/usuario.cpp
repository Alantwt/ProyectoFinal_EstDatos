
#include "../include/funciones.h"
#include "../include/usuario.h"
#include "../include/cdata.h"

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void UserMain(){
    char carroTipo[20] = " ", carroTam[20] = " ", carroMarca[20] = " ";
    
    menuTipo(carroTipo);
    if(strcmp(carroTipo," ") != 0){
        menuMarca(carroMarca);
        if(strcmp(carroMarca," ") != 0){
            menuTam(carroTam);
            if(strcmp(carroTam," "))consultarBdatos(carroTam,carroTipo,carroMarca);
        }
    }
    system("cls");
}

void menuTipo(char* carroTipo){
    system("cls");
    char keypressed;
    int option = 2;
    printf("Escoja una  opcion:\n");
    printf("tipo de Carro\n");
    printf("Uso  Personal\n");
    printf("Uso Comercial\n");
    printf("Uso de Construccion\n");
    printf("Salir");

    while(true){
        keypressed = getch();
        movePointer(30,option);
        printf(" ");
        if(keypressed == T_DOWN && option <= 4){
            option++;
        } 
        else if(keypressed == T_UP && option > 2){
            option--;
        }
        else if(keypressed == ENTER){
            movePointer(10,10);
            if(option == 2){
                strcpy(carroTipo,"personal");
                break;
            }
            else if(option == 3){
                strcpy(carroTipo,"comercial");
                break;
            }
            else if(option == 4){
                strcpy(carroTipo,"construccion");
                break;
            }
            else{
                break;
            }
        }
        movePointer(30,option);
        printf("%c",17);
    }
}

void menuTam(char* carroTam){
    system("cls");
    char keypressed;
    int option = 2;
    printf("Escoja una  opcion:\n");
    printf("Tamaño del Carro\n");
    printf("Grande\n");
    printf("Mediano\n");
    printf("Pequeño\n");
    printf("Salir");

    while(true){
        keypressed = getch();
        movePointer(30,option);
        printf(" ");
        if(keypressed == T_DOWN && option <= 4){
            option++;
        } 
        else if(keypressed == T_UP && option > 2){
            option--;
        }
        else if(keypressed == ENTER){
            movePointer(10,10);
            if(option == 2){
                strcpy(carroTam,"grande");
                break;
            }
            else if(option == 3){
                strcpy(carroTam,"mediano");
                break;
            }
            else if(option == 4){
                strcpy(carroTam,"pequeño");
                break;
            }
            else{
                break;
            }
        }
        movePointer(30,option);
        printf("%c",17);
    }
}

void menuMarca(char* carroMarca){
    system("cls");
    char keypressed;
    int option = 2;
    printf("Escoja una  opcion:\n");
    printf("Marca de Carro\n");
    printf("Toyota\n");
    printf("Nissan\n");
    printf("GMC\n");
    printf("CAT\n");
    printf("Salir");

    while(true){
        keypressed = getch();
        movePointer(30,option);
        printf(" ");
        if(keypressed == T_DOWN && option <= 5){
            option++;
        } 
        else if(keypressed == T_UP && option > 2){
            option--;
        }
        else if(keypressed == ENTER){
            movePointer(10,10);
            if(option == 2){
                strcpy(carroMarca,"toyota");
                break;
            }
            else if(option == 3){
                strcpy(carroMarca,"nissan");
                break;
            }
            else if(option == 4){
                strcpy(carroMarca,"gmc");
                break;
            }
            else if(option == 5){
                strcpy(carroMarca,"cat");
                break;
            }
            else{
                break;
            }
        }
        movePointer(30,option);
        printf("%c",17);
    }
}

void consultarBdatos(char* carroTam,char* carrotipo, char* carroMarca){
    Fcarros carrosData(CARROS_FILE);
    int lenCarros = carrosData.searchBy(carroTam,carrotipo,carroMarca);
    movePointer(0,7);
    printf("________________________________________________________________\n");
    if(lenCarros == 0){
        printf("Sin Autos Disponibles\n");
        printf("________________________________________________________________\n");
    }
    else if( lenCarros > 0){
        for(int i = 0; i <= lenCarros-1; i++){
        puts(carrosData.carrosF[i].carroMarca);
        puts(carrosData.carrosF[i].carroModelo);
        puts(carrosData.carrosF[i].carroTam);
        puts(carrosData.carrosF[i].carroTipo);
        printf("________________________________________________________________\n");
    }
    }

    getch();
}