#ifndef UNICODE
#define UNICODE//Esto es para utilizar caracteres latinos mas facil
#endif

#define _WIN32_WINNT 0x0500 // Es necesaria esta definicion para esconder ventana de consola; 0x0500 son las versiones de windows con las que es compatible


#include "../include/ui_functs.h"
using namespace std;


//DECLARACION DE FUNCIONES
LRESULT CALLBACK WindowProcedure(HWND mainWindow,UINT messageW,WPARAM wParam,LPARAM lParam) ;



int WINAPI WinMain (HINSTANCE hThisInstance,

                     HINSTANCE hPrevInstance,

                     LPSTR lpszArgument,

                     int nCmdShow)

{

    //ESTILO DE LA VENTANA
    wClass.hInstance = hThisInstance;
    wClass.lpszClassName = className;
    wClass.lpfnWndProc = WindowProcedure;
    wClass.style = CS_DBLCLKS;                      //Hace que la ventana diferencie entre un click y doble click
    wClass.cbSize = sizeof (WNDCLASSEX);            //Indica a la ventana cual es el tamaño en bit que ocupara la ventana de estilos

    wClass.hIconSm = LoadIcon (NULL, IDI_WINLOGO);  //modifica el icono de la aplicacion en la ventana y tambien en el escritorio
    wClass.hCursor = LoadCursor (NULL, IDC_ARROW);  //Cambia el estilo del cursor
    wClass.lpszMenuName = NULL;                     //Se crea un Menu
    wClass.cbClsExtra = 0;
    wClass.cbWndExtra = 0;
    wClass.hbrBackground = (HBRUSH) COLOR_WINDOWFRAME; //Cambia el color de fondo de la ventana
    


    //SE VALIDA LA CLASE VENTANA
    if (!RegisterClassEx(&wClass))return 0;


    //CREAR LA VENTANA
    mainW = CreateWindowEx(
        0,
        className,                      //Tipo de la ventana
        L"Concecionario De Autos",      //Titulo de la ventana
        WS_OVERLAPPEDWINDOW|WS_BORDER, 
        200,30,                         //Posicion 'x' y 'y' de la ventana  
        1000,700,                       //Tamaño de la ventana en 'x' y 'y'    
        HWND_DESKTOP,                   //Ventana Padre
        NULL,                           //Sin Menu
        hThisInstance,                  
        NULL                 
    );



    //HACER LA VENTANA VISIBLE
    ShowWindow (mainW, nCmdShow);

    //ESCONDER LA VENTANA DEL CMD
    //ShowWindow(GetConsoleWindow(), SW_HIDE );


    //BUCLE DE LA VENTANA, SE EJECUTA HASTA QUE SEA 0
    while (GetMessage (&msgW, NULL, 0, 0)){

        //Traduce mensajes virtual-key 
        TranslateMessage(&msgW);

        //Envia mensajes a WindowProcedure 
        DispatchMessage(&msgW);

    }



    return msgW.wParam;

}



LRESULT CALLBACK WindowProcedure (HWND mainWindow, //VENTANA PRINCIPAL
                                  UINT messageW, //EVENTO DE LA VENTANA
                                  WPARAM wParam, //identificador del evento producido
                                  LPARAM lParam){


                                    
    //MANEJO DE LOS MENSAJES RECIBIDOS
    switch (messageW){

        case WM_CLOSE: //MENSAJE DE CERRAR LA VENTANA
            DestroyWindow(mainWindow);
            break;

        case WM_DESTROY://MENSAJE PARA DESTRUIR LA VENTANA 
            PostQuitMessage(0);
            break;
        
        case WM_CREATE:
            mainFrame_size.x = 900;
            mainFrame_size.y = 500;
            frame_size.x = mainFrame_size.x-20;
            frame_size.y = mainFrame_size.y-36;
            frameCarros_size.x = 0.99*frame_size.x;
            frameCarros_size.y = 0.495*frame_size.y;

            createButtons(mainWindow);
            createFrame(mainWindow);
            actionBTN_recomendarAuto(mainFrame,mainWindow);
            break;

        case WM_COMMAND:
            //ACCIONES DE LOS BOTONES
            if(LOWORD(BTN_recomendAuto) == wParam)actionBTN_recomendarAuto(mainFrame,mainWindow);
            else if(LOWORD(BTN_conjunto) == wParam)actionBTN_conjunto(mainFrame);
            else if(LOWORD(BTN_digrafo) == wParam)actionBTN_digrafo(mainFrame);
            else if(LOWORD(BTN_funcion) == wParam)actionBTN_funcion(mainFrame);
            else if(LOWORD(BTN_semiGrupo) == wParam)actionBtn_semiGrupo(mainFrame);
            else if(LOWORD(BTN_matris) == wParam)actionBTN_matris(mainFrame);
            else if(LOWORD(BTN_generate) == wParam)actionBtn_generate();
            else if(LOWORD(BTN_next) == wParam)actionBtn_next();
            else if(LOWORD(BTN_prev) == wParam)actionBtn_prev();
            else if(LOWORD(BTN_ford) == wParam)actionBtn_ford(wParam,mainWindow);
            else if(LOWORD(BTN_toyota) == wParam)actionBtn_toyota(wParam,mainWindow);
            else if(LOWORD(BTN_bmw) == wParam)actionBtn_bmw(wParam,mainWindow);
            else if(LOWORD(BTN_big) == wParam)actionBtn_big(wParam,mainWindow);
            else if(LOWORD(BTN_medium) == wParam)actionBtn_medium(wParam,mainWindow);
            else if(LOWORD(BTN_small) == wParam)actionBtn_small(wParam,mainWindow);
            else if(LOWORD(BTN_family) == wParam)actionBtn_family(wParam,mainWindow);
            else if(LOWORD(BTN_comerce) == wParam)actionBtn_comerce(wParam,mainWindow);
            else if(LOWORD(BTN_sport) == wParam)actionBtn_sport(wParam,mainWindow);
            cout<<wParam<<endl;
            break;


        case WM_PAINT://Repinta la ventana
            hdc = BeginPaint(mainWindow, &ps);

            // All painting occurs here, between BeginPaint and EndPaint.

            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_BACKGROUND));

            EndPaint(mainWindow, &ps);

            hdc1 = BeginPaint(frameImage, &ps1);

            // All painting occurs here, between BeginPaint and EndPaint.

            FillRect(hdc1, &ps1.rcPaint, (HBRUSH) (COLOR_WINDOWFRAME));

            EndPaint(frameImage, &ps1);

            break;

        case WM_SIZE:
            //Redimencionar el MainFrame
            mainFrame_size.x = LOWORD(lParam)-20;
            mainFrame_size.y = HIWORD(lParam)-36;
            frame_size.x = mainFrame_size.x-20;
            frame_size.y = mainFrame_size.y-20;
            frameCarros_size.x = 0.99*frame_size.x;
            frameCarros_size.y = 0.495*frame_size.y;
            
            reSizeWindows();
            
            break;


        case WM_CHAR:
            cout<<(wchar_t)wParam<<endl;
            if((wchar_t)wParam == 13){
                actionBtn_generate();
            }
            break;
        

        default:  

            return DefWindowProc (mainWindow, messageW, wParam, lParam);

    }

return 0;

}
