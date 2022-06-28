#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

#include "../include/funciones.h"
#include "../include/matriz.h"
#include "../include/conjuntos.h"

void menu();

int main(){
    menu();
}

void menu(){
    system("cls");
    char keypressed;
    int option = 1;

    printf("Escoja una opcion: \n");
    printf("Ayudar a escojer un carron\n");
    printf("Mostrar Conjuntos\n");
    printf("Mostrar Matris Relacion\n");
    printf("Mostrar Los digrafos:\n");
    printf("Mostrar La funcion\n");
    printf("Exit");

    while(true){
        
        keypressed = getch();
        movePointer(30,option);
        printf(" ");
        if(keypressed == T_DOWN && option <= 5){
            option++;
        } 
        else if(keypressed == T_UP && option > 1){
            option--;
        }
        else if(keypressed == ENTER){
            movePointer(10,10);
            if(option == 1){
                printf("1");
            }
            else if(option == 2){
                printf("2");
                conjuntos();
            }
            else if(option == 3){
                printf("3");
                matriz();
            }
            else if(option == 4){
                printf("4");
            }
            else if(option == 5){
                printf("5");
            }
            else{
                break;
            }
        }
        movePointer(30,option);
        printf("%c",17);
    }
}
