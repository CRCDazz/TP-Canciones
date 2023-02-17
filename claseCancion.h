#ifndef CLASECANCION_H_INCLUDED
#define CLASECANCION_H_INCLUDED


class Canciones
{
    private:
        int ID_cancion;
        char nombre[30];
        char autorCompositor[30];
        int ID_interprete;
        Fecha fechaDeEstreno;
        bool estado;
        float duracion;
        int genero;
    public:
        void setID_cancion(int idCancion){ID_cancion = idCancion;}
        void setNombre(const char *_nombre){strcpy(nombre, _nombre);}
        void setAutorCompositor(const char *autor){strcpy(autorCompositor, autor);}
        void setID_Interprete(int idInterprete){ID_interprete = idInterprete;}
        void setFechaDeEstreno(Fecha _fechaDeEstreno){fechaDeEstreno = _fechaDeEstreno;}
        void setEstado(bool _estado){estado = _estado;}
        void setDuracion(float _duracion){duracion = _duracion;}
        void setGenero(int _genero){genero = _genero;}

        int getID_cancion(){return ID_cancion;}
        const char *getNombre(){return nombre;}
        const char *getAutorCompositor(){return autorCompositor;}
        int getID_interprete(){return ID_interprete;}
        Fecha getFechaDeEstreno(){return fechaDeEstreno;}
        bool getEstado(){return estado;}
        float getDuracion(){return duracion;}
        int getGenero(){return genero;}

        bool generoValido();
        bool duracionValida();
        bool validarFecha();

        void Cargar();
        void Mostrar();
        bool leerDeDisco(int pos);
        bool grabarEnDisco();
        bool modificarEnDisco(int pos);


};

bool Canciones::leerDeDisco(int pos){ //pos es la posición que ocupa el registro en el archivo, empezando por 0
    FILE *p;
    p=fopen("canciones.dat","rb");
    if(p==NULL) return false;
    fseek(p, pos * sizeof (Canciones), 0);
    bool leyo = fread(this, sizeof (Canciones), 1, p);
    fclose(p);
    return leyo;
}

bool Canciones::grabarEnDisco(){
    FILE *p;
    p=fopen("canciones.dat","ab");
    if(p==NULL) return false;
    bool escribio = fwrite(this, sizeof (Canciones), 1, p);
    fclose(p);
    return escribio;
}

bool Canciones::modificarEnDisco(int pos){
    FILE *p;
    p=fopen("canciones.dat","rb+");
    if(p==NULL) return false;
    fseek(p, pos * sizeof(Canciones), 0);
    bool escribio=fwrite(this, sizeof (Canciones), 1, p);
    fclose(p);
    return escribio;
}

bool Canciones::validarFecha(){
    cout<<"Fecha de Estreno: "<<endl;
    fechaDeEstreno.Cargar();
    while( !cin.good() || !fechaDeEstreno.fechaValida() || !fechaDeEstreno.compararFecha() ){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        if( !menuContinuar() )
            return false;
        cout<<"Fecha de Estreno: ";
        fechaDeEstreno.Cargar();
    }
    return true;
}

bool Canciones::generoValido(){
    while( !cin.good() || genero<1 || genero>10  ){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        if(!menuContinuar())
            return false;
        cout<<"Genero: ";
        cin>>genero;
    }
    return true;
}
bool Canciones::duracionValida()
{
    while( !cin.good() || duracion<=0 ){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        if(!menuContinuar())
            return false;
        cout<<"Duracion de la Cancion: ";
        cin>>duracion;
        /*system("cls");
        cout<<"DATO FUERA DE RANGO"<<endl<<endl;
        cout<<"PRESIONE: \"Y\" para continuar - \"N\" para cancelar carga: ";
        cin>>tecla;
        if(tecla == 'n' || tecla == 'N')
            return false;
        if(tecla == 'y' || tecla == 'Y'){
            cout<<"Duracion de la Cancion: ";
            cin>>duracion;
        }*/
    }
    return true;
}

void Canciones::Cargar()
{
    estado = true;
    cout<<"Nombre: ";
    cargarCadena(nombre, 29);
    cout<<"Autor/Compositor: ";
    cargarCadena(autorCompositor, 29);
    cout<<"ID Inteprete: ";
    cin>>ID_interprete;
    //cout<<"Fecha de Estreno: ";
    //fechaDeEstreno.Cargar();
    if( validarFecha() == false ){
        estado = false;
        return;
    }
    cout<<"Duracion de la Cancion: ";
    cin>>duracion;
    if( duracionValida() == false ){
        estado = false;
        return;
    }
    cout<<"Genero: ";
    cin>>genero;
    if( generoValido() == false ){
        estado = false;
        return;
    }
    cout<<endl;
}

void Canciones::Mostrar()
{
    if(estado==true){
        cout<<"ID Cancion: ";
        cout<<ID_cancion<<endl;
        cout<<"NOMBRE: ";
        cout<<nombre<<endl;
        cout<<"Autor/Compositor: ";
        cout<<autorCompositor<<endl;
        cout<<"ID Interprete: ";
        cout<<ID_interprete<<endl;
        cout<<"Fecha de Estreno: ";
        fechaDeEstreno.Mostrar();
        cout<<"Duracion de la Cancion: ";
        cout<<duracion<<endl;
        cout<<"Genero: ";
        cout<<genero;
        cout<<endl;
    }
}

#endif // CLASECANCION_H_INCLUDED
