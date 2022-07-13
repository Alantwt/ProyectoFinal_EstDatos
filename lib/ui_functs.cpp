#include "../include/ui_functs.h"
#include <iostream>
using namespace std;

//CREAR VENTANAS
bool createButtons(HWND mainWindow){
    btnRecomendAuto = CreateWindowEx(0,L"button",L"RecomendarAuto",WS_VISIBLE|WS_CHILD|0,10,0,150,25,mainWindow,(HMENU)BTN_recomendAuto,0,0);
    btnConjunto = CreateWindowEx(0,L"button",L"Conjuntos",WS_VISIBLE|WS_CHILD|0,160,0,100,25,mainWindow,(HMENU)BTN_conjunto,0,0);
    btnDigrafo = CreateWindowEx(0,L"button",L"Digrafos",WS_VISIBLE|WS_CHILD|0,260,0,100,25,mainWindow,(HMENU)BTN_digrafo,0,0);
    btnFuncion = CreateWindowEx(0,L"button",L"Funcion",WS_VISIBLE|WS_CHILD|0,360,0,100,25,mainWindow,(HMENU)BTN_funcion,0,0);
    btnSemiGrupo = CreateWindowEx(0,L"button",L"SemiGrupo",WS_VISIBLE|WS_CHILD|0,460,0,100,25,mainWindow,(HMENU)BTN_semiGrupo,0,0);
    btnMatris = CreateWindowEx(0,L"button",L"Matris",WS_VISIBLE|WS_CHILD|0,560,0,100,25,mainWindow,(HMENU)BTN_matris,0,0);  
}

bool createFrame(HWND mainWindow){
    mainFrame = CreateWindowEx(0,L"static",L"",WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,10,mainFrame_size.y*0.45,(mainFrame_size.x-20),(mainFrame_size.y*0.535),mainWindow,NULL,NULL,NULL);  
}

bool createRecomendAutoScreen(HWND masterWindow, HWND mainWindow){
    frameCarros = CreateWindowEx(0,L"static",NULL,WS_VISIBLE|WS_CHILD|SS_CENTER|WS_BORDER,200,mainFrame_size.y*0.3,(mainFrame_size.x-400),(mainFrame_size.y*0.535),mainFrame,NULL,NULL,NULL);
    cout<<mainFrame_size.y*0.4<<endl;
    btnGenerate = CreateWindowEx(0,L"button",L"Generate",WS_VISIBLE|WS_CHILD,200,(mainFrame_size.y*0.42)-100,70,25,mainWindow,(HMENU)BTN_generate,NULL,NULL);
    btnPrev = CreateWindowEx(0,L"button",L"Prev",WS_VISIBLE|WS_CHILD,mainFrame_size.x*0.4,mainFrame_size.y*0.9,70,25,mainWindow,(HMENU)BTN_prev,NULL,NULL);
    btnNext = CreateWindowEx(0,L"button",L"Next",WS_VISIBLE|WS_CHILD,mainFrame_size.x*0.55,mainFrame_size.y*0.9,70,25,mainWindow,(HMENU)BTN_next,NULL,NULL);
    hIns = (HINSTANCE)GetWindowLong(mainWindow, GWL_HINSTANCE);
    createRbtnOptions(mainWindow);
}

void createRbtnOptions(HWND mainWindow){
    //MARCA
    RbtnFord = CreateWindowEx(0,L"button",L"Ford",WS_VISIBLE|WS_CHILD|BS_RADIOBUTTON,200,100,50,20,mainWindow,(HMENU)BTN_ford,hIns,NULL);
    RbtnToyota = CreateWindowEx(0,L"button",L"Toyota",WS_VISIBLE|WS_CHILD|BS_RADIOBUTTON,200,120,100,20,mainWindow,(HMENU)BTN_toyota,hIns,NULL);
    RbtnBmw = CreateWindowEx(0,L"button",L"Bmw",WS_VISIBLE|WS_CHILD|BS_RADIOBUTTON,200,140,100,20,mainWindow,(HMENU)BTN_bmw,hIns,NULL);
    //TAMAÑO
    RbtnBig = CreateWindowEx(0,L"button",L"Grande",WS_VISIBLE|WS_CHILD|BS_RADIOBUTTON,(mainFrame_size.x/2)-40,100,70,20,mainWindow,(HMENU)BTN_big,hIns,NULL);
    RbtnMedium = CreateWindowEx(0,L"button",L"Mediano",WS_VISIBLE|WS_CHILD|BS_RADIOBUTTON,(mainFrame_size.x/2)-40,120,80,20,mainWindow,(HMENU)BTN_medium,hIns,NULL);
    RbtnSmall = CreateWindowEx(0,L"button",L"Pequeño",WS_VISIBLE|WS_CHILD|BS_RADIOBUTTON,(mainFrame_size.x/2)-40,140,80,20,mainWindow,(HMENU)BTN_small,hIns,NULL);
    //FUNCIONALIDAD
    RbtnFamily = CreateWindowEx(0,L"button",L"Familiar",WS_VISIBLE|WS_CHILD|BS_RADIOBUTTON,mainFrame_size.x-280,100,80,20,mainWindow,(HMENU)BTN_family,hIns,NULL);
    RbtnComerce = CreateWindowEx(0,L"button",L"Comercio",WS_VISIBLE|WS_CHILD|BS_RADIOBUTTON,mainFrame_size.x-280,120,80,20,mainWindow,(HMENU)BTN_comerce,hIns,NULL);
    RbtnSport = CreateWindowEx(0,L"button",L"Deportivo",WS_VISIBLE|WS_CHILD|BS_RADIOBUTTON,mainFrame_size.x-280,140,81,20,mainWindow,(HMENU)BTN_sport,hIns,NULL);
}

bool createFrameConjuntos(HWND masterWindow){
    frameConjuto = CreateWindowEx(0,L"static",NULL,WS_VISIBLE|WS_CHILD|SS_CENTER,10,26,900,500,masterWindow,NULL,NULL,NULL);  
}
bool createFrameMatris(HWND masterWindow){
    frameMatris = CreateWindowEx(0,L"static",NULL,WS_VISIBLE|WS_CHILD|SS_CENTER,10,26,1200,500,masterWindow,NULL,NULL,NULL);  
}
bool createFrameDigrafo(HWND masterWindow){
    frameDigrafo = CreateWindowEx(0,L"static",NULL,WS_VISIBLE|WS_CHILD|SS_CENTER,10,26,900,500,masterWindow,NULL,NULL,NULL);  
}
bool createFrameFuncion(HWND masterWindow){
    frameFuncion = CreateWindowEx(0,L"static",NULL,WS_VISIBLE|WS_CHILD|SS_CENTER,10,26,900,500,masterWindow,NULL,NULL,NULL);
}
bool createFrameSemiGrupo(HWND masterWindow){
    frameSemiGrupo = CreateWindowEx(0,L"static",NULL,WS_VISIBLE|WS_CHILD|SS_CENTER,10,26,900,500,masterWindow,NULL,NULL,NULL);
}

//REDIMENCIONAR VENTANAS
void reSizeWindows(){
    MoveWindow(frameCarros,200,mainFrame_size.y*0.3,(mainFrame_size.x-400),(mainFrame_size.y*0.535),TRUE);
    MoveWindow(mainFrame,10,26,mainFrame_size.x,mainFrame_size.y,TRUE);
    MoveWindow(frameDigrafo,10,10,frame_size.x,frame_size.y,TRUE);
    MoveWindow(frameConjuto,10,10,frame_size.x,frame_size.y,TRUE);
    MoveWindow(frameFuncion,10,10,frame_size.x,frame_size.y,TRUE);
    MoveWindow(frameMatris,10,10,frame_size.x,frame_size.y,TRUE);
    MoveWindow(frameSemiGrupo,10,10,frame_size.x,frame_size.y,TRUE);
    MoveWindow(btnGenerate,200,(mainFrame_size.y*0.42)-100,70,25,TRUE);
    MoveWindow(btnNext,mainFrame_size.x*0.55,mainFrame_size.y*0.9,70,25,TRUE);
    MoveWindow(btnPrev,mainFrame_size.x*0.4,mainFrame_size.y*0.9,70,25,TRUE); 
    MoveWindow(RbtnBig,(mainFrame_size.x/2)-40,100,70,20,TRUE);
    MoveWindow(RbtnMedium,(mainFrame_size.x/2)-40,120,80,20,TRUE);
    MoveWindow(RbtnSmall,(mainFrame_size.x/2)-40,140,80,20,TRUE);
    MoveWindow(RbtnFamily,mainFrame_size.x-280,100,80,20,TRUE);
    MoveWindow(RbtnComerce,mainFrame_size.x-280,120,80,20,TRUE);
    MoveWindow(RbtnSport,mainFrame_size.x-280,140,81,20,TRUE); 
}

//RESETEAR VENTANAS
void resetMainFrame(){
    DestroyWindow(frameMatris);
    DestroyWindow(frameFuncion);
    DestroyWindow(frameDigrafo);
    DestroyWindow(frameConjuto);
    DestroyWindow(frameSemiGrupo);
    DestroyWindow(frameCarros);
    DestroyWindow(btnGenerate);
    DestroyWindow(btnNext);
    DestroyWindow(btnPrev);
    DestroyWindow(RbtnBig);
    DestroyWindow(RbtnBmw);
    DestroyWindow(RbtnComerce);
    DestroyWindow(RbtnFamily);
    DestroyWindow(RbtnFord);
    DestroyWindow(RbtnMedium);
    DestroyWindow(RbtnSmall);
    DestroyWindow(RbtnSport);
    DestroyWindow(RbtnToyota);
}


//ACCION DE BOTONES
bool actionBTN_recomendarAuto(HWND masterWindow, HWND mainWindow){
    resetMainFrame();
    createRecomendAutoScreen(masterWindow, mainWindow);
}

bool actionBTN_conjunto(HWND masterWindow){
    resetMainFrame();
    createFrameConjuntos(masterWindow);
    setImage(imgConjuntos,frameConjuto,1200,500,false);
}

bool actionBTN_matris(HWND masterWindow){
    resetMainFrame();
    createFrameMatris(masterWindow);
    setImage(imgMatris,frameMatris,1200,500,false);
}

bool actionBTN_digrafo(HWND masterWindow){
    resetMainFrame();
    createFrameDigrafo(masterWindow);
    setImage(imgDigrafo,frameDigrafo,1200,500,false);
}

bool actionBTN_funcion(HWND masterWindow){
    resetMainFrame();
    createFrameFuncion(masterWindow); 
    setImage(imgFuncion,frameFuncion,1200,500,false); 
}

bool actionBtn_semiGrupo(HWND masterWindow){
    resetMainFrame();
    createFrameSemiGrupo(masterWindow);
    setImage(imgSemiGrupo,frameSemiGrupo,1200,500,false);
}

void actionBtn_generate(){
    DestroyWindow(frameImage);
    lenAutos = autosData.readCarro();
    _putws((autosData.carros+autosArrayPosition)->carroPath); 
    setImage((autosData.carros+autosArrayPosition)->carroPath,frameCarros,(mainFrame_size.x-400),(mainFrame_size.y*0.625),true);
}

void actionBtn_next(){
    if(autosArrayPosition < lenAutos){
        autosArrayPosition++;
        actionBtn_generate();
    }
}

void actionBtn_prev(){
    if(autosArrayPosition > 0){
        autosArrayPosition--;
        actionBtn_generate();
    }
}

//RADIO BUTTONS
void actionBtn_ford(WPARAM wParam,HWND mainWindow){
    if(HIWORD(wParam) == BN_CLICKED){
        cout<<"1"<<endl;
        if(SendDlgItemMessage(mainWindow,BTN_ford,BM_GETCHECK,0,0) == 0){
            SendDlgItemMessage(mainWindow,BTN_ford,BM_SETCHECK,1,0);
            SendDlgItemMessage(mainWindow,BTN_toyota,BM_SETCHECK,0,0);
            SendDlgItemMessage(mainWindow,BTN_bmw,BM_SETCHECK,0,0);
            wcscat(brandCarOption,L"ford");
        }
    }
}
void actionBtn_toyota(WPARAM wParam, HWND mainWindow){
    if(HIWORD(wParam) == BN_CLICKED){
        cout<<"2"<<endl;
        if(SendDlgItemMessage(mainWindow,BTN_toyota,BM_GETCHECK,0,0) == 0){
            SendDlgItemMessage(mainWindow,BTN_ford,BM_SETCHECK,0,0);
            SendDlgItemMessage(mainWindow,BTN_toyota,BM_SETCHECK,1,0);
            SendDlgItemMessage(mainWindow,BTN_bmw,BM_SETCHECK,0,0);
            wcscat(brandCarOption,L"toyota");
        }
    }
}
void actionBtn_bmw(WPARAM wParam, HWND mainWindow){
    if(HIWORD(wParam) == BN_CLICKED){
        cout<<"3"<<endl;
        if(SendDlgItemMessage(mainWindow,BTN_bmw,BM_GETCHECK,0,0) == 0){
            SendDlgItemMessage(mainWindow,BTN_ford,BM_SETCHECK,0,0);
            SendDlgItemMessage(mainWindow,BTN_toyota,BM_SETCHECK,0,0);
            SendDlgItemMessage(mainWindow,BTN_bmw,BM_SETCHECK,1,0);
            wcscat(brandCarOption,L"bmw");
        }
    }
}

void actionBtn_big(WPARAM wParam, HWND mainWindow){
    if(HIWORD(wParam) == BN_CLICKED){
        cout<<"4"<<endl;
        if(SendDlgItemMessage(mainWindow,BTN_big,BM_GETCHECK,0,0) == 0){
            SendDlgItemMessage(mainWindow,BTN_big,BM_SETCHECK,1,0);
            SendDlgItemMessage(mainWindow,BTN_medium,BM_SETCHECK,0,0);
            SendDlgItemMessage(mainWindow,BTN_small,BM_SETCHECK,0,0);
            wcscat(sizeCarOption,L"grande");
        }
    }
}
void actionBtn_medium(WPARAM wParam, HWND mainWindow){
    if(HIWORD(wParam) == BN_CLICKED){
        cout<<"5"<<endl;
        if(SendDlgItemMessage(mainWindow,BTN_medium,BM_GETCHECK,0,0) == 0){
            SendDlgItemMessage(mainWindow,BTN_big,BM_SETCHECK,0,0);
            SendDlgItemMessage(mainWindow,BTN_medium,BM_SETCHECK,1,0);
            SendDlgItemMessage(mainWindow,BTN_small,BM_SETCHECK,0,0);
            wcscat(sizeCarOption,L"mediano");
        }
    }
}
void actionBtn_small(WPARAM wParam, HWND mainWindow){
    if(HIWORD(wParam) == BN_CLICKED){
        cout<<"6"<<endl;
        if(SendDlgItemMessage(mainWindow,BTN_small,BM_GETCHECK,0,0) == 0){
            SendDlgItemMessage(mainWindow,BTN_big,BM_SETCHECK,0,0);
            SendDlgItemMessage(mainWindow,BTN_medium,BM_SETCHECK,0,0);
            SendDlgItemMessage(mainWindow,BTN_small,BM_SETCHECK,1,0);
            wcscat(sizeCarOption,L"pequeño");
        }
    }
}

void actionBtn_family(WPARAM wParam, HWND mainWindow){
    if(HIWORD(wParam) == BN_CLICKED){
        cout<<"7"<<endl;
        if(SendDlgItemMessage(mainWindow,BTN_family,BM_GETCHECK,0,0) == 0){
            SendDlgItemMessage(mainWindow,BTN_family,BM_SETCHECK,1,0);
            SendDlgItemMessage(mainWindow,BTN_comerce,BM_SETCHECK,0,0);
            SendDlgItemMessage(mainWindow,BTN_sport,BM_SETCHECK,0,0);
            wcscat(funcCarOption,L"familiar");
        }
    }
}
void actionBtn_comerce(WPARAM wParam, HWND mainWindow){
    if(HIWORD(wParam) == BN_CLICKED){
        cout<<"8"<<endl;
        if(SendDlgItemMessage(mainWindow,BTN_comerce,BM_GETCHECK,0,0) == 0){
            SendDlgItemMessage(mainWindow,BTN_family,BM_SETCHECK,0,0);
            SendDlgItemMessage(mainWindow,BTN_comerce,BM_SETCHECK,1,0);
            SendDlgItemMessage(mainWindow,BTN_sport,BM_SETCHECK,0,0);
            wcscat(funcCarOption,L"comercial");
        }
    }
}
void actionBtn_sport(WPARAM wParam, HWND mainWindow){
    if(HIWORD(wParam) == BN_CLICKED){
        cout<<"9"<<endl;
        if(SendDlgItemMessage(mainWindow,BTN_sport,BM_GETCHECK,0,0) == 0){
            SendDlgItemMessage(mainWindow,BTN_family,BM_SETCHECK,0,0);
            SendDlgItemMessage(mainWindow,BTN_comerce,BM_SETCHECK,0,0);
            SendDlgItemMessage(mainWindow,BTN_sport,BM_SETCHECK,1,0);
            wcscat(funcCarOption,L"deportivo");
        }
    }
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

void setImage(wchar_t path[], HWND masterWindow, int sizeX, int sizeY, bool centrar){
    //Crear una ventana para poner la imagen
    loadImage(path);
    if(centrar == true){
        frameImage = CreateWindowEx(
            0,
            L"static",
            NULL,
            WS_VISIBLE|WS_CHILD|SS_BITMAP|SS_CENTERIMAGE|SS_REALSIZEIMAGE,
            0,0,
            sizeX,sizeY,
            masterWindow,
            NULL,
            NULL,
            NULL
        );
    }
    else{
        frameImage = CreateWindowEx(
            0,
            L"static",
            NULL,
            WS_VISIBLE|WS_CHILD|SS_BITMAP|SS_REALSIZEIMAGE,
            0,0,
            sizeX,sizeY,
            masterWindow,
            NULL,
            NULL,
            NULL
        );
    }
    //Cargar La imagen en la ventana
    SendMessageW(
        frameImage,
        STM_SETIMAGE,
        IMAGE_BITMAP,
        (LPARAM)image
        );
}


