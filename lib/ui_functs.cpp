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
    btnFuncCarac = CreateWindowEx(0,L"button",L"FuncionCaracteristica",WS_VISIBLE|WS_CHILD|0,660,0,150,25,mainWindow,(HMENU)BTN_funcCarac,0,0);
}

bool createFrame(HWND mainWindow){
    mainFrame = CreateWindowEx(0,L"static",L"",WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,10,mainFrame_size.y*0.45,(mainFrame_size.x-20),(mainFrame_size.y*0.535),mainWindow,NULL,NULL,NULL);  
}

bool createRecomendAutoScreen(HWND masterWindow, HWND mainWindow){
    frameCarros = CreateWindowEx(0,L"static",NULL,WS_VISIBLE|WS_CHILD|SS_CENTER|WS_BORDER,190,mainFrame_size.y*0.3,(mainFrame_size.x-400),(mainFrame_size.y*0.535),mainFrame,NULL,NULL,NULL);
    cout<<mainFrame_size.y*0.4<<endl;
    btnGenerate = CreateWindowEx(0,L"button",L"Generate",WS_VISIBLE|WS_CHILD,200,(mainFrame_size.y*0.42)-100,70,25,mainWindow,(HMENU)BTN_generate,NULL,NULL);
    btnPrev = CreateWindowEx(0,L"button",L"Prev",WS_VISIBLE|WS_CHILD,mainFrame_size.x*0.4,mainFrame_size.y*0.9,70,25,mainWindow,(HMENU)BTN_prev,NULL,NULL);
    btnNext = CreateWindowEx(0,L"button",L"Next",WS_VISIBLE|WS_CHILD,mainFrame_size.x*0.55,mainFrame_size.y*0.9,70,25,mainWindow,(HMENU)BTN_next,NULL,NULL);
    hIns = (HINSTANCE)GetWindowLong(mainWindow, GWL_HINSTANCE);
    createRbtnOptions(mainWindow);
}

void createRbtnOptions(HWND mainWindow){
    //MARCA
    marcaWoption = CreateWindowEx(0,L"static",L"Marcas",WS_VISIBLE|WS_CHILD,190,70,50,20,mainWindow,NULL,NULL,NULL);
    RbtnFord = CreateWindowEx(0,L"button",L"Ford",WS_VISIBLE|WS_CHILD|BS_RADIOBUTTON,200,100,50,20,mainWindow,(HMENU)BTN_ford,hIns,NULL);
    RbtnToyota = CreateWindowEx(0,L"button",L"Toyota",WS_VISIBLE|WS_CHILD|BS_RADIOBUTTON,200,120,100,20,mainWindow,(HMENU)BTN_toyota,hIns,NULL);
    RbtnBmw = CreateWindowEx(0,L"button",L"Bmw",WS_VISIBLE|WS_CHILD|BS_RADIOBUTTON,200,140,100,20,mainWindow,(HMENU)BTN_bmw,hIns,NULL);
    //TAMAÑO
    sizeWoption = CreateWindowEx(0,L"static",L"Tamaño",WS_VISIBLE|WS_CHILD,(mainFrame_size.x/2)-40,70,50,20,mainWindow,NULL,NULL,NULL);
    RbtnBig = CreateWindowEx(0,L"button",L"Grande",WS_VISIBLE|WS_CHILD|BS_RADIOBUTTON,(mainFrame_size.x/2)-40,100,70,20,mainWindow,(HMENU)BTN_big,hIns,NULL);
    RbtnMedium = CreateWindowEx(0,L"button",L"Mediano",WS_VISIBLE|WS_CHILD|BS_RADIOBUTTON,(mainFrame_size.x/2)-40,120,80,20,mainWindow,(HMENU)BTN_medium,hIns,NULL);
    RbtnSmall = CreateWindowEx(0,L"button",L"Pequeño",WS_VISIBLE|WS_CHILD|BS_RADIOBUTTON,(mainFrame_size.x/2)-40,140,80,20,mainWindow,(HMENU)BTN_small,hIns,NULL);
    //FUNCIONALIDAD
    funcWoption = CreateWindowEx(0,L"static",L"Funcionalidad",WS_VISIBLE|WS_CHILD,mainFrame_size.x-280,70,50,20,mainWindow,NULL,NULL,NULL);
    RbtnFamily = CreateWindowEx(0,L"button",L"Familiar",WS_VISIBLE|WS_CHILD|BS_RADIOBUTTON,mainFrame_size.x-280,100,80,20,mainWindow,(HMENU)BTN_family,hIns,NULL);
    RbtnComerce = CreateWindowEx(0,L"button",L"Comercio",WS_VISIBLE|WS_CHILD|BS_RADIOBUTTON,mainFrame_size.x-280,120,80,20,mainWindow,(HMENU)BTN_comerce,hIns,NULL);
    RbtnSport = CreateWindowEx(0,L"button",L"Deportivo",WS_VISIBLE|WS_CHILD|BS_RADIOBUTTON,mainFrame_size.x-280,140,81,20,mainWindow,(HMENU)BTN_sport,hIns,NULL);
}

bool createFrameConjuntos(HWND masterWindow){
    frameConjuto = CreateWindowEx(0,L"static",NULL,WS_VISIBLE|WS_CHILD|SS_CENTER,10,26,900,500,masterWindow,NULL,NULL,NULL);  
    frameConjuntosDef = CreateWindowEx(
        0,
        L"static",
        L"U={Grande, pequeño, mediano, comercial, familiar,deportivo}\nF={Familiar,mediano,pequeño}\nT={Comercial, Grande, mediano, pequeño}\nB={Deportivo, mediano}",
        WS_VISIBLE|WS_CHILD,
        10,550,
        500,50,
        masterWindow,
        NULL,
        NULL,
        NULL
    );
    FrameConjuntoOperaciones = CreateWindowEx(
        0,
        L"Static",
        L"Union : FUTUB={Grande, pequeño, mediano, Comercial, Familiar,Deportivo}\n \
          Intersección F∩B={}, F∩T={mediano}, T∩B={}, F∩T∩D={pequeño}\n \
Complemento relativo :\n \
          F-B={familiar, mediano}, F-T={familiar}, T-F={comercial, mediano},\n \
          T-B={comercial, grande, deportivo}, B-F={deportivo}, \n \
          B-T={deportivo}\n \
Diferencia Simetrica : \n \
          FΔB={familiar, deportivo}, FΔT={familiar,comercial,grande}, \n \\
          TΔB={comercial,grande,deportivo}, \n \\ 
          FΔTΔB={familiar,comercial,deportivo}",
          WS_VISIBLE|WS_CHILD,
          mainFrame_size.x*0.61,26,
          500,300,
          masterWindow,
          NULL,
          NULL,
          NULL
    );
}
bool createFrameMatris(HWND masterWindow){
    frameMatris = CreateWindowEx(0,L"static",NULL,WS_VISIBLE|WS_CHILD|SS_CENTER,mainFrame_size.x*0.05,26,1200,500,masterWindow,NULL,NULL,NULL);  
}
bool createFrameDigrafo(HWND masterWindow){
    frameDigrafo = CreateWindowEx(0,L"static",NULL,WS_VISIBLE|WS_CHILD|SS_CENTER,mainFrame_size.x*0.1,26,900,500,masterWindow,NULL,NULL,NULL);  
}
bool createFrameFuncion(HWND masterWindow){
    frameFuncion = CreateWindowEx(0,L"static",NULL,WS_VISIBLE|WS_CHILD|SS_CENTER,mainFrame_size.x*0.1,26,900,500,masterWindow,NULL,NULL,NULL);
}
bool createFrameSemiGrupo(HWND masterWindow){
    frameSemiGrupo = CreateWindowEx(0,L"static",NULL,WS_VISIBLE|WS_CHILD|SS_CENTER,mainFrame_size.x*0.1,26,900,500,masterWindow,NULL,NULL,NULL);
    frameSemiGrupoDef = CreateWindowEx(
        0,
        L"static",
        L"Conjunto vacio\n \
    U ≠ {}\n \
Aplicación de la operación binaria \n \
	a*b = b*a \n \
	F*M = M*F \n \
	0 = 0 \n \
Los resultados no existen dentro del conjunto \n \
    Propiedad Asociativa\n \
    a*(b*c) = (a*b)*c \n \
    F*(M*P) = (F*M)*P \n \
    F*(0) = (1)*P \n \
    1 = 1\n \
No es un semigrupo ya que no cumple con la segunda norma de los semigrupos.",
    WS_VISIBLE|WS_CHILD,
    mainFrame_size.x*0.1,400,
    300,400,
    masterWindow,
    NULL,
    NULL,
    NULL
    );
}
void createFrameFuncCarac(HWND masterWindow){
    frameFuncCarac = CreateWindowEx(0,L"static",NULL,WS_VISIBLE|WS_CHILD|SS_CENTER,mainFrame_size.x*0.2,26,900,500,masterWindow,NULL,NULL,NULL);
}

//REDIMENCIONAR VENTANAS
void reSizeWindows(){
    MoveWindow(frameCarros,190,mainFrame_size.y*0.3,(mainFrame_size.x-400),(mainFrame_size.y*0.535),TRUE);
    MoveWindow(mainFrame,10,26,mainFrame_size.x,mainFrame_size.y,TRUE);
    MoveWindow(frameDigrafo,mainFrame_size.x*0.1,26,frame_size.x,frame_size.y,TRUE);
    MoveWindow(frameConjuto,10,26,frame_size.x,frame_size.y,TRUE);
    MoveWindow(frameFuncion,mainFrame_size.x*0.1,26,frame_size.x,frame_size.y,TRUE);
    MoveWindow(frameMatris,mainFrame_size.x*0.05,26,frame_size.x,frame_size.y,TRUE);
    MoveWindow(frameSemiGrupo,mainFrame_size.x*0.1,26,frame_size.x,frame_size.y,TRUE);
    MoveWindow(frameFuncCarac,mainFrame_size.x*0.2,26,frame_size.x,frame_size.y,TRUE);
    MoveWindow(btnGenerate,200,(mainFrame_size.y*0.42)-100,70,25,TRUE);
    MoveWindow(btnNext,mainFrame_size.x*0.55,mainFrame_size.y*0.9,70,25,TRUE);
    MoveWindow(btnPrev,mainFrame_size.x*0.4,mainFrame_size.y*0.9,70,25,TRUE); 
    MoveWindow(RbtnBig,(mainFrame_size.x/2)-40,100,70,20,TRUE);
    MoveWindow(RbtnMedium,(mainFrame_size.x/2)-40,120,80,20,TRUE);
    MoveWindow(RbtnSmall,(mainFrame_size.x/2)-40,140,80,20,TRUE);
    MoveWindow(RbtnFamily,mainFrame_size.x-280,100,80,20,TRUE);
    MoveWindow(RbtnComerce,mainFrame_size.x-280,120,80,20,TRUE);
    MoveWindow(RbtnSport,mainFrame_size.x-280,140,81,20,TRUE); 
    MoveWindow(sizeWoption,(mainFrame_size.x/2)-40,70,50,20,TRUE);
    MoveWindow(funcWoption,mainFrame_size.x-280,70,50,20,TRUE);
    MoveWindow(frameDataCarros,mainFrame_size.x*0.2,mainFrame_size.y*0.51,mainFrame_size.x-400,15,TRUE);
    MoveWindow(frameConjuntosDef,10,550,500,50,TRUE);
    MoveWindow(frameSemiGrupoDef,mainFrame_size.x*0.1,400,300,400,TRUE);
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
    DestroyWindow(marcaWoption);
    DestroyWindow(sizeWoption);
    DestroyWindow(funcWoption);
    DestroyWindow(frameConjuntosDef);
    DestroyWindow(frameFuncCarac);
    DestroyWindow(FrameConjuntoOperaciones);
    DestroyWindow(frameSemiGrupoDef);
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

void actionBtn_funcCarac(HWND masterWindow){
    resetMainFrame();
    createFrameFuncCarac(masterWindow);
    setImage(imgFuncCarac,frameFuncCarac,1200,500,false);
}

void actionBtn_generate(bool resetCounter){
    DestroyWindow(frameImage);
    //lenAutos = autosData.readCarro();
    lenAutos = autosData.readCarroBy(brandCarOption,funcCarOption,sizeCarOption);
    _putws((autosData.carros+autosArrayPosition)->carroPath); 
    if(resetCounter)autosArrayPosition = 0;
    setImage((autosData.carros+autosArrayPosition)->carroPath,frameCarros,(mainFrame_size.x-400),(mainFrame_size.y*0.625),true);
    wcscpy(dataCarros,L"");
    wcscat(dataCarros,(autosData.carros+autosArrayPosition)->carroMarca);
    wcscat(dataCarros,L"  ");
    wcscat(dataCarros,(autosData.carros+autosArrayPosition)->carroModelo);
    wcscat(dataCarros,L"\n");
    frameDataCarros = CreateWindowEx(0,L"static",dataCarros,WS_VISIBLE|WS_CHILD|SS_CENTER,0,mainFrame_size.y*0.51,mainFrame_size.x-400,15,frameCarros,NULL,NULL,NULL);
}

void actionBtn_next(){
    if(autosArrayPosition < lenAutos-1){
        autosArrayPosition++;
        actionBtn_generate(false);
    }
    cout<<autosArrayPosition<<endl;
}

void actionBtn_prev(){
    if(autosArrayPosition > 0){
        autosArrayPosition--;
        actionBtn_generate(false);
    }
    cout<<autosArrayPosition<<endl;
}

//RADIO BUTTONS
void actionBtn_ford(WPARAM wParam,HWND mainWindow){
    if(HIWORD(wParam) == BN_CLICKED){
        cout<<"1"<<endl;
        if(SendDlgItemMessage(mainWindow,BTN_ford,BM_GETCHECK,0,0) == 0){
            SendDlgItemMessage(mainWindow,BTN_ford,BM_SETCHECK,1,0);
            SendDlgItemMessage(mainWindow,BTN_toyota,BM_SETCHECK,0,0);
            SendDlgItemMessage(mainWindow,BTN_bmw,BM_SETCHECK,0,0);
            wcscpy(brandCarOption,L"");
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
            wcscpy(brandCarOption,L"");
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
            wcscpy(brandCarOption,L"");
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
            wcscpy(sizeCarOption,L"");
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
            wcscpy(sizeCarOption,L"");
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
            wcscpy(sizeCarOption,L"");
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
            wcscpy(funcCarOption,L"");
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
            wcscpy(funcCarOption,L"");
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
            wcscpy(funcCarOption,L"");
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


