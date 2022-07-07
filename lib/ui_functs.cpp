#include "../include/ui_functs.h"
#include <iostream>
using namespace std;

//CREAR VENTANAS
bool createButtons(HWND mainWindow){
    btnRecomendAuto = CreateWindowEx(0,L"button",L"RecomendarAuto",WS_VISIBLE|WS_CHILD|0,10,0,150,25,mainWindow,(HMENU)BTN_recomendAuto,0,0);
    btnConjunto = CreateWindowEx(0,L"button",L"Conjuntos",WS_VISIBLE|WS_CHILD|0,160,0,100,25,mainWindow,(HMENU)BTN_conjunto,0,0);
    btnDigrafoBtn = CreateWindowEx(0,L"button",L"Digrafos",WS_VISIBLE|WS_CHILD|0,260,0,100,25,mainWindow,(HMENU)BTN_digrafo,0,0);
    btnFuncionBtn = CreateWindowEx(0,L"button",L"Funcion",WS_VISIBLE|WS_CHILD|0,360,0,100,25,mainWindow,(HMENU)BTN_funcion,0,0);
    btnSemiGrupoBtn = CreateWindowEx(0,L"button",L"SemiGrupo",WS_VISIBLE|WS_CHILD|0,460,0,100,25,mainWindow,(HMENU)BTN_semiGrupo,0,0);
}

bool createFrame(HWND mainWindow){
    mainFrame = CreateWindowEx(0,L"static",L"",WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,10,26,900,500,mainWindow,NULL,NULL,NULL);  
}

bool createFrameRecomendAuto(HWND masterWindow){
    frameRecomedAuto= CreateWindowEx(0,L"static",L"xdxd",WS_VISIBLE|WS_CHILD|SS_CENTER,10,26,900,500,masterWindow,NULL,NULL,NULL);  
}

bool createFrameConjuntos(HWND masterWindow){
    frameConjuto = CreateWindowEx(0,L"static",L"",WS_VISIBLE|WS_CHILD|SS_CENTER,10,26,900,500,masterWindow,NULL,NULL,NULL);  
}
bool createFrameMatris(HWND masterWindow){
    frameMatris = CreateWindowEx(0,L"static",L"kjsfavh",WS_VISIBLE|WS_CHILD|SS_CENTER,10,26,900,500,masterWindow,NULL,NULL,NULL);  
}
bool createFrameDigrafo(HWND masterWindow){
    frameDigrafo = CreateWindowEx(0,L"static",L"kjahsvd",WS_VISIBLE|WS_CHILD|SS_CENTER,10,26,900,500,masterWindow,NULL,NULL,NULL);  
}
bool createFrameFuncion(HWND masterWindow){
    frameFuncion = CreateWindowEx(0,L"static",L"akjhfbv",WS_VISIBLE|WS_CHILD|SS_CENTER,10,26,900,500,masterWindow,NULL,NULL,NULL);
}
bool createFrameSemiGrupo(HWND masterWindow){
    frameSemiGrupo = CreateWindowEx(0,L"static",L"akafvsafkjv",WS_VISIBLE|WS_CHILD|SS_CENTER,10,26,900,500,masterWindow,NULL,NULL,NULL);
}


//ACCION DE BOTONES
bool actionBTN_recomendarAuto(HWND masterWindow){
    DestroyWindow(frameMatris);
    DestroyWindow(frameFuncion);
    DestroyWindow(frameDigrafo);
    DestroyWindow(frameConjuto);
    DestroyWindow(frameSemiGrupo);
    createFrameRecomendAuto(masterWindow);
}

bool actionBTN_conjunto(HWND masterWindow){
    DestroyWindow(frameRecomedAuto);
    DestroyWindow(frameFuncion);
    DestroyWindow(frameFuncion);
    DestroyWindow(frameDigrafo);
    DestroyWindow(frameSemiGrupo);
    createFrameConjuntos(masterWindow);
    setImage(imgConjuntos,frameConjuto);
}

bool actionBTN_matris(HWND masterWindow){
    DestroyWindow(frameRecomedAuto);
    DestroyWindow(frameFuncion);
    DestroyWindow(frameDigrafo);
    DestroyWindow(frameConjuto);
    DestroyWindow(frameSemiGrupo);
    createFrameMatris(masterWindow);
    setImage(imgMatris,frameMatris);
}

bool actionBTN_digrafo(HWND masterWindow){
    DestroyWindow(frameRecomedAuto);
    DestroyWindow(frameConjuto);
    DestroyWindow(frameMatris);
    DestroyWindow(frameFuncion);
    DestroyWindow(frameSemiGrupo);
    createFrameDigrafo(masterWindow);
    setImage(imgDigrafo,frameDigrafo);
}

bool actionBTN_funcion(HWND masterWindow){
    DestroyWindow(frameRecomedAuto);
    DestroyWindow(frameConjuto);
    DestroyWindow(frameMatris);
    DestroyWindow(frameDigrafo);
    DestroyWindow(frameSemiGrupo);
    createFrameFuncion(masterWindow); 
    setImage(imgFuncion,frameFuncion); 
}

bool actionBtn_semiGrupo(HWND masterWindow){
    DestroyWindow(frameRecomedAuto);
    DestroyWindow(frameConjuto);
    DestroyWindow(frameMatris);
    DestroyWindow(frameDigrafo);
    DestroyWindow(frameFuncion);
    createFrameSemiGrupo(masterWindow);
    setImage(imgSemiGrupo,frameSemiGrupo);
}

//IMAGEN
void loadImage(wchar_t path[]){
    image = (HBITMAP)LoadImageW(
        NULL,
        path,
        IMAGE_BITMAP,
        0,0,
        LR_LOADFROMFILE
    );
}

void setImage(wchar_t path[], HWND masterWindow){
    //Crear una ventana para poner la imagen
    loadImage(path);
    frameImage = CreateWindowEx(
        0,
        L"static",
        NULL,
        WS_VISIBLE|WS_CHILD|SS_BITMAP,
        0,0,
        800,500,
        masterWindow,
        NULL,
        NULL,
        NULL
    );
    //Cargar La imagen en la ventana
    SendMessageW(
        frameImage,
        STM_SETIMAGE,
        IMAGE_BITMAP,
        (LPARAM)image
        );
}


