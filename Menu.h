#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "funcionesGlobales.h"


int menuPrincipal()
{
    unsigned char tecla;
    fflush(stdin);
    system("cls");
    cout<<"MENU PRINCIPAL"<<endl;
    cout<<"-------------------"<<endl<<endl;
    cout<<"1) MENU CANCIONES"<<endl;
    cout<<"2) MENU INTERPRETES"<<endl;
    cout<<"3) MENU GENEROS"<<endl;
    cout<<"4) REPORTES"<<endl;
    cout<<"5) CONFIGURACION"<<endl;
    cout<<"-------------------"<<endl;
    cout<<"0) FIN DEL PROGRAMA"<<endl<<endl;
    cout<<"SELECCIONE UNA DE LAS OPCIONES"<<endl<<endl;
    cin>>tecla;
    if(tecla>'5' || tecla<'0'){
        cout<<"OPCION INCORRECTA, REINTENTE"<<endl;
        system("pause");
        menuPrincipal();
    }
    return tecla;
}

void subMenuCanciones()
{
    unsigned char tecla;
    cin.clear();
    fflush(stdin);
    system("cls");
    cout<<"MENU CANCIONES"<<endl;
    cout<<"-------------------"<<endl<<endl;
    cout<<"1) AGREGAR CANCION"<<endl;
    cout<<"2) LISTAR CANCIONES POR ID"<<endl;
    cout<<"3) LISTAR TODAS LAS CANCIONES"<<endl;
    cout<<"4) MODIFICAR FECHA DE ESTRENO"<<endl;
    cout<<"5) ELIMINAR CANCION"<<endl;
    cout<<"-------------------"<<endl;
    cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl<<endl;
    cin>>tecla;
    if(tecla>'5' || tecla<'0'){
        cout<<"OPCION INCORRECTA, REINTENTE"<<endl;
        system("pause");
        subMenuCanciones();
    }
    else
    {
        switch(tecla)
        {
        case '1':   if(agregarCancion()==false){
                        cout<<"ERROR, no pudo cargarse el dato."<<endl;
                    }
                    else{
                        cout<<"REGISTRO AGREGADO"<<endl;
                    }
                    break;
        case '2':   listarCancion();

                    break;
        case '3':   mostrarCanciones();
                    break;
        case '4':   if(modificarFechaCancion())
                        cout<<"MODIFICACION EXITOSA"<<endl;
                    break;
        case '5':   if(eliminarCanciones()==true)
                        cout<<"REGISTRO ELIMINADO"<<endl;
                    break;
        case '0':   cin.clear();
                    return;
                    break;
        default:    cout<<"OPCION INCORRECTA"<<endl;
                    break;
        }
        system("pause");
        subMenuCanciones();
    }
}

void subMenuInterprete()
{
    unsigned char tecla;
    fflush(stdin);
    system("cls");
    cout<<"MENU INTERPRETES"<<endl;
    cout<<"-------------------"<<endl<<endl;
    cout<<"1) AGREGAR INTERPRETE"<<endl;
    cout<<"2) LISTAR INTERPRETE POR ID"<<endl;
    cout<<"3) LISTAR TODAS LOS INTERPRETES"<<endl;
    cout<<"4) MODIFICAR GENERO MUSICAL PRINCPAL"<<endl;
    cout<<"5) ELIMINAR INTERPRETE"<<endl;
    cout<<"-------------------"<<endl;
    cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl<<endl;
    cin>>tecla;
    if(tecla>'5' || tecla<'0'){
        cout<<"OPCION INCORRECTA, REINTENTE"<<endl;
        system("pause");
        subMenuInterprete();
    }
    else
    {
        switch(tecla)
        {
        case '1':   if(agregarInterprete()==false){
                        cout<<"ERROR, no pudo abrirse el archivo"<<endl;
                    }
                    else{
                        cout<<"REGISTRO AGREGADO"<<endl;
                    }
            break;
        case '2':   listarInterprete();
            break;
        case '3':   mostrarInterpretes();
            break;
        case '4':   if(modificarGeneroMusical())
                        cout<<"MODIFICACION EXITOSA"<<endl;
            break;
        case '5':   if(eliminarInterprete()==true)
                        cout<<"REGISTRO ELIMINADO"<<endl;
            break;
        case '0':   cin.clear();
                    return;
                    break;
        default:    cout<<"OPCION INCORRECTA"<<endl;
                    break;
        }
        system("pause");
        subMenuInterprete();
    }
}

void subMenuGenero()
{
    unsigned char tecla;
    fflush(stdin);
    system("cls");
    cout<<"MENU GENERO"<<endl;
    cout<<"-------------------"<<endl<<endl;
    cout<<"1) AGREGAR GENERO"<<endl;
    cout<<"2) LISTAR GENERO POR ID"<<endl;
    cout<<"3) LISTAR TODAS LOS GENEROS"<<endl;
    cout<<"4) MODIFICAR TIPO DE INSTRUMENTACION"<<endl;
    cout<<"-------------------"<<endl;
    cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl<<endl;
    cin>>tecla;
    if(tecla>'5' || tecla<'0'){
        cout<<"OPCION INCORRECTA, REINTENTE"<<endl;
        system("pause");
        subMenuGenero();
    }
    else
    {
        switch(tecla)
        {
        case '1':   if(agregarGenero()==false){
                        cout<<"ERROR, no pudo abrirse el archivo"<<endl;
                    }
                    else{
                        cout<<"REGISTRO AGREGADO"<<endl;
                    }
            break;
        case '2':   listarGenero();

            break;
        case '3':   mostrarGeneros();
            break;
        case '4':   if(modificarTipoInstrumentacion())
                        cout<<"MODIFICACION EXITOSA"<<endl;
            break;
        case '0':   cin.clear();
                    return;
                    break;
        default:    cout<<"OPCION INCORRECTA"<<endl;
                    break;
        }
        system("pause");
        subMenuGenero();
    }
}
void subMenuReportes()
{
    unsigned char tecla;
    fflush(stdin);
    system("cls");
    cout<<"MENU REPORTES"<<endl;
    cout<<"-------------------"<<endl<<endl;
    cout<<"1) CANTIDAD DE CANCIONES POR INTERPRETE."<<endl;
    cout<<"2) CANCIONES POR GENERO."<<endl;
    cout<<"-------------------"<<endl;
    cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl<<endl;
    cin>>tecla;
    if(tecla>'2' || tecla<'0'){
        cout<<"OPCION INCORRECTA, REINTENTE"<<endl;
        system("pause");
        subMenuReportes();
    }
    else
    {
        switch(tecla)
        {
        case '1':
                    break;
        case '2':
                    break;
            break;
        case '0':   cin.clear();
                    return;
                    break;
        default:    cout<<"OPCION INCORRECTA"<<endl;
                    break;
        }
        system("pause");
        subMenuReportes();
    }
}

void subMenuConfiguracion()
{
    unsigned char tecla;
    fflush(stdin);
    system("cls");
    cout<<"MENU CANCIONES"<<endl;
    cout<<"-------------------"<<endl<<endl;
    cout<<"1) COPIA DE SEGURIDAD DEL ARCHIVO DE CANCIONES."<<endl;
    cout<<"2) COPIA DE SEGURIDAD DEL ARCHIVO INTERPRETES."<<endl;
    cout<<"3) COPIA DE SEGURIDAD DEL ARCHIVO GENEROS"<<endl;
    cout<<"4) RESTAURAR EL ARCHIVO DE CANCIONES."<<endl;
    cout<<"5) RESTAURAR EL ARCHIVO DE INTERPRETES."<<endl;
    cout<<"6) RESTAURAR EL ARCHIVO DE GENEROS."<<endl;
    cout<<"7) ESTABLECER DATOS DE INICIO"<<endl;
    cout<<"-------------------"<<endl;
    cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl<<endl;
    cin>>tecla;
    if(tecla>'5' || tecla<'0'){
        cout<<"OPCION INCORRECTA, REINTENTE"<<endl;
        system("pause");
        subMenuConfiguracion();
    }
    else
    {
        switch(tecla)
        {
        case '1':
                    break;
        case '2':
                    break;
        case '3':
                    break;
        case '4':
                    break;
        case '5':
                    break;
        case '6':
                    break;
        case '7':
                    break;
        case '0':   cin.clear();
                    return;
                    break;
        default:    cout<<"OPCION INCORRECTA"<<endl;
                    break;
        }
        system("pause");
        subMenuConfiguracion();
    }
}

#endif // MENU_H_INCLUDED
