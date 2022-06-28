#include<windows.h>
#include<stdio.h>

#include "../include/funciones.h"

void movePointer(int x, int y){
    //Handle es el identificador  de la pantalla en curso del programa
    HANDLE hCon;
    //LA FUNCION GetStdHandle me me da el identificador de la ventana en curso y el parametro STD_OUTPUT_HANDLE hace referencia
    //al tipo de control que se va a usar, tambien puede ser STD_INPUT_HANDLE
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    
    //La estructura COORD tiene dos parametros que son las posiciones
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;

    //La funcion Hcon me permite mover el puntero por la pantalla y como Parametros tiene el Handle y una structura de datos que es la posicion
    SetConsoleCursorPosition(hCon,dwPos);
}