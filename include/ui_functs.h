#ifndef _UIFUNCTS
#define _UIFUNCTS

//DECLARACION DE MACROS
#define BTN_recomendAuto 101
#define BTN_conjunto 102
#define BTN_matris 103
#define BTN_digrafo 104
#define BTN_funcion 105
#define BTN_semiGrupo 106

#include <windows.h>
//VARIABLES GLOBALES
HWND mainW;     //VentanaPrincipal
MSG msgW;       //Mensajes de la ventana
WNDCLASSEX wClass;   //Estilos de la ventana principal
wchar_t className[] = L"Estilos"; 
HDC hdc,hdc1;
PAINTSTRUCT ps,ps1;
HWND btnRecomendAuto,btnConjunto,btnMatrisBtn,btnDigrafoBtn,btnFuncionBtn,btnSemiGrupoBtn;//BUTTONS
HWND mainFrame;//Frame Principal
HWND frameRecomedAuto,frameConjuto,frameMatris,frameDigrafo,frameFuncion,frameSemiGrupo;

//IMAGENES
HWND frameImage;
HBITMAP image;
wchar_t imgConjuntos[] = L"../images/Conjuntos.bmp";
wchar_t imgDigrafo[] = L"../images/Digrafo.bmp";
wchar_t imgFuncion[] = L"../images/Funcion.bmp";
wchar_t imgMatris[] = L"../images/Matris.bmp";
wchar_t imgSemiGrupo[] = L"../images/SemiGrupo.bmp";


//CREACION DE VENTANAS
bool createButtons(HWND mainWindow);
bool createFrame(HWND mainWindow);
bool createFrameRecomendAuto(HWND masterWindow);
bool createFrameConjuntos(HWND masterWindow);
bool createFrameMatris(HWND masterWindow);
bool createFrameDigrafo(HWND masterWindow);
bool createFrameFuncion(HWND masterWindow);
bool createFrameSemiGrupo(HWND masterWindow);

//ACCION DE BOTONES
bool actionBTN_recomendarAuto(HWND masterWindow);
bool actionBTN_conjunto(HWND masterWindow);
bool actionBTN_matris(HWND masterWindow);
bool actionBTN_digrafo(HWND masterWindow);
bool actionBTN_funcion(HWND masterWindow);
bool actionBtn_semiGrupo(HWND masterWindow);

//IMAGEN
void loadImage(wchar_t path[]);
void setImage(wchar_t path[], HWND masterWindow);

#include "../lib/ui_functs.cpp"

#endif