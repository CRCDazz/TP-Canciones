#ifndef FUNCIONESAUXILIARES_H_INCLUDED
#define FUNCIONESAUXILIARES_H_INCLUDED

bool menuContinuar()
{
    bool continua;
    unsigned char tecla;
    do{
        system("cls");
        cout<<"DATO FUERA DE RANGO"<<endl<<endl;
        cout<<"PRESIONE: \"Y\" para continuar - \"N\" para cancelar carga: ";
        cin>>tecla;
        if(tecla == 'n' || tecla == 'N')
            continua = false;
        if(tecla == 'y' || tecla == 'Y')
            continua = true;
    }while( tecla != 'y' && tecla != 'Y' && tecla != 'n' && tecla != 'N' );
    return continua;
}


#endif // FUNCIONESAUXILIARES_H_INCLUDED
