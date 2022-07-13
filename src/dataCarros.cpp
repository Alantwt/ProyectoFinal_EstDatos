

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
    printf("Exit");

    while(true){
        
        keypressed = getch();
        movePointer(30,option);
        printf(" ");
        if(keypressed == T_DOWN && option <= 3){
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
    wchar_t Smarca[20],Stam[20],Stipo[20],Smodelo[20],Spath[30];
    int var, len = 0;

    while(true){
        len++;
        keypressed = getch();
        if(keypressed == ESC)break;
        else if(keypressed = ENTER){
            //Marca del carro
            printf("Escoja una Marca:\n1.Toyota\n2.BMW\n3.Ford\n");
            scanf("%d",&var);
            if(var == 1)wcscpy(Smarca,L"toyota");
            else if(var == 2)wcscpy(Smarca,L"bmw");
            else if(var == 3)wcscpy(Smarca,L"ford");

            //Tamaño del carro
            printf("Escoja el Tama%co del carro:\n1Grande\n2.Mediano\n3.Peque%co\n",164,164);
            scanf("%d",&var);
            if(var == 1)wcscpy(Stam,L"grande");
            else if(var == 2)wcscpy(Stam,L"mediano");
            else if(var == 3)wcscpy(Stam,L"pequeño");

            //Tipo de Carro
            printf("Escoja el tipo del carro:\n1.Familiar\n2.Comercial\n3.Deportivo\n");
            scanf("%d",&var);
            if(var == 1)wcscpy(Stipo,L"familiar");
            else if(var == 2)wcscpy(Stipo,L"comercial");
            else if(var == 3)wcscpy(Stipo,L"deportivo");

            //Modelo del carro
            printf("Introdusca el modelo del carro: ");
            fflush(stdin);
            _getws(Smodelo);

            //path
            wchar_t path[30] = L"..\\images\\Autos\\";
            wcscat(path,Smodelo);
            wcscat(path,L".bmp");
            wcscpy(Spath,path);

            _putws(path);

            movePointer(0,20);
            printf("                                             ");
            movePointer(0,20);
            printf("Elementos Agregados: %d",carrosFile.addCarro(Smarca,Stipo,Smodelo,Stam,Spath));
            Sleep(1000);
            system("cls");
        }
    }

    main();
}

void leerData(){
    int lenFile = carrosFile.readCarro();
    printf("***%d***",lenFile);

    for(int u = 0; u <= lenFile-1; u++){
        _putws((carrosFile.carros+u)->carroMarca);
        _putws((carrosFile.carros+u)->carroModelo);
        _putws((carrosFile.carros+u)->carroTam);
        _putws((carrosFile.carros+u)->carroTipo);
        _putws((carrosFile.carros+u)->carroPath);
    }
}