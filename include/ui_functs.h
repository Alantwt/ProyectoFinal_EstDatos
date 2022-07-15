#ifndef _UIFUNCTS
#define _UIFUNCTS

//DECLARACION DE MACROS
#define BTN_recomendAuto 101
#define BTN_conjunto 102
#define BTN_matris 103
#define BTN_digrafo 104
#define BTN_funcion 105
#define BTN_semiGrupo 106
#define BTN_generate 107
#define BTN_next 108
#define BTN_prev 109
#define BTN_ford 110
#define BTN_toyota 111
#define BTN_bmw 112
#define BTN_big 113
#define BTN_medium 114
#define BTN_small 115
#define BTN_family 116
#define BTN_comerce 117
#define BTN_sport 118
#define BTN_funcCarac 119

//Sizes
struct Size{
    int x;
    int y;
};

Size mainFrame_size;
Size frame_size;
Size frameCarros_size;


#include <windows.h>

#include <iostream>
#include <windef.h>
#include <winuser.h>

#include "../include/cdata.h"

//VARIABLES GLOBALES
//VentanaPrincipal
HWND mainW;     
//Mensajes de la ventana
MSG msgW;       
//Estilos de la ventana principal
WNDCLASSEX wClass;   
wchar_t className[] = L"Estilos"; 
//
HDC hdc,hdc1;
PAINTSTRUCT ps,ps1;
//BUTTONS
HWND btnRecomendAuto,btnConjunto,btnMatris,btnDigrafo,btnFuncion,btnSemiGrupo,btnGenerate,btnNext,btnPrev,btnFuncCarac;
//RADIO BUTTONS
HINSTANCE hIns;
wchar_t brandCarOption[20] = L"";
HWND marcaWoption;
HWND RbtnFord,RbtnToyota,RbtnBmw;//OPCION MARCA
wchar_t sizeCarOption[20] = L"";
HWND sizeWoption;
HWND RbtnBig,RbtnMedium,RbtnSmall;//OPCION TAMAÑO
wchar_t funcCarOption[20] = L"";
HWND funcWoption;
HWND RbtnFamily,RbtnComerce,RbtnSport;//OPCION FUNCIONALIDAD

//Frame Principal
HWND mainFrame;
//Frames
wchar_t dataCarros[40] = L"";
HWND frameRecomedAuto,frameConjuto,frameMatris,frameDigrafo,frameFuncion,frameSemiGrupo,frameCarros,frameTemp,frameDataCarros,frameConjuntosDef,frameFuncCarac;
HWND frameSemiGrupoDef, FrameConjuntoOperaciones;
//BASE DE DATOS
char autosFilePath[] = "..\\data\\CarroData.alan";
Fcarros autosData(autosFilePath);
int autosArrayPosition = 0;
int lenAutos;


//IMAGENES
HWND frameImage;
HBITMAP image;
wchar_t imgConjuntos[] = L"../images/Conjuntos.bmp";
wchar_t imgDigrafo[] = L"../images/Digrafo.bmp";
wchar_t imgFuncion[] = L"../images/Funcion.bmp";
wchar_t imgMatris[] = L"../images/Matris.bmp";
wchar_t imgSemiGrupo[] = L"../images/SemiGrupo.bmp";
wchar_t imgFuncCarac[] = L"..\\images\\FuncionCaracteristica.bmp";



//CREACION DE VENTANAS
bool createButtons(HWND mainWindow);
bool createFrame(HWND mainWindow);
bool createRecomendAutoScreen(HWND masterWindow, HWND mainWindow);
void createRbtnOptions(HWND mainWindow);
bool createFrameConjuntos(HWND masterWindow);
bool createFrameMatris(HWND masterWindow);
bool createFrameDigrafo(HWND masterWindow);
bool createFrameFuncion(HWND masterWindow);
bool createFrameSemiGrupo(HWND masterWindow);
void createFrameFuncCarac(HWND masterWindow);
//REDIMENCIONAR VENTANAS
void reSizeWindows();
//RESETEAR VENTANAS
void resetMainFrame();

//ACCION DE BOTONES
bool actionBTN_recomendarAuto(HWND masterWindow, HWND mainWindow);
bool actionBTN_conjunto(HWND masterWindow);
bool actionBTN_matris(HWND masterWindow);
bool actionBTN_digrafo(HWND masterWindow);
bool actionBTN_funcion(HWND masterWindow);
bool actionBtn_semiGrupo(HWND masterWindow);
void actionBtn_generate(bool resetCounter);;
void actionBtn_next();
void actionBtn_prev();
void actionBtn_ford(WPARAM wParam, HWND mainWindow);
void actionBtn_bmw(WPARAM wParam, HWND mainWindow);
void actionBtn_toyota(WPARAM wParam, HWND mainWindow);
void actionBtn_big(WPARAM wParam, HWND mainWindow);
void actionBtn_medium(WPARAM wParam, HWND mainWindow);
void actionBtn_small(WPARAM wParam, HWND mainWindow);
void actionBtn_family(WPARAM wParam, HWND mainWindow);
void actionBtn_comerce(WPARAM wParam, HWND mainWindow);
void actionBtn_sport(WPARAM wParam, HWND mainWindow);
void actionBtn_funcCarac(HWND masterWindow);

//IMAGEN
void loadImage(wchar_t path[]);
void setImage(wchar_t path[], HWND masterWindow, int sizeX, int sizeY, bool centrar);

#include "../lib/ui_functs.cpp"

#endif