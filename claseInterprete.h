#ifndef CLASEINTERPRETE_H_INCLUDED
#define CLASEINTERPRETE_H_INCLUDED

class Interpretes{

    private:
            int interpreteID;
            char nombre[40];
            int nacionalidad;
            int tipoDeInterprete;
            int generoMusical;
            Fecha fechaInicio;
            bool estado;
    public:
            void setInterpreteID(int _interpreteID){interpreteID = _interpreteID;}
            void setNombre(const char *_nombre){strcpy(nombre,_nombre);}
            void setNacionalidad(int _nacionalidad){nacionalidad = _nacionalidad;}
            void setTipoDeInterprete(int _tipoInterprete){tipoDeInterprete=_tipoInterprete;}
            void setGeneroMusical(int _generoMusical){generoMusical=_generoMusical;}
            void setFechaInicio(Fecha _fechaInicio){fechaInicio=_fechaInicio;}
            void setEstado(bool _estado){estado = _estado;}

            int getInterpreteID(){return interpreteID;}
            const char *getNombre(){return nombre;}
            int getNacionalidad(){return nacionalidad;}
            int getTipoDeInterprete(){return tipoDeInterprete;}
            int getGeneroMusical(){return generoMusical;}
            Fecha getFecha(){return fechaInicio;}
            bool getEstado(){return estado;}

            bool nacionalidadValida();
            bool tipoDeInterpreteValido();
            bool generoMusicalValido();

            void Cargar();
            void Mostrar();
            bool leerDeDisco(int pos);
            bool grabarEnDisco();
            bool modificarEnDisco(int pos);
};

bool Interpretes::leerDeDisco(int pos){ //pos es la posición que ocupa el registro en el archivo, empezando por 0
    FILE *p;
    p=fopen("interpretes.dat","rb");
    if(p==NULL) return false;
    fseek(p, pos * sizeof (Interpretes), 0);
    bool leyo = fread(this, sizeof (Interpretes), 1, p);
    fclose(p);
    return leyo;
}

bool Interpretes::grabarEnDisco(){
    FILE *p;
    p=fopen("interpretes.dat","ab");
    if(p==NULL) return false;
    bool escribio = fwrite(this, sizeof (Interpretes), 1, p);
    fclose(p);
    return escribio;
}

bool Interpretes::modificarEnDisco(int pos){
    FILE *p;
    p=fopen("interpretes.dat","rb+");
    if(p==NULL) return false;
    fseek(p, pos * sizeof(Interpretes), 0);
    bool escribio=fwrite(this, sizeof (Interpretes), 1, p);
    fclose(p);
    return escribio;
}


bool Interpretes::nacionalidadValida(){
    while( !cin.good() || nacionalidad <= 0 || nacionalidad > 100 ){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        if( !menuContinuar() )
            return false;
        cout<<"Nacionalidad: ";
        cin>>nacionalidad;
    }
    return true;
}

bool Interpretes::tipoDeInterpreteValido(){
    while( !cin.good() || tipoDeInterprete <= 0 || tipoDeInterprete > 5 ){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        if( !menuContinuar() )
            return false;
        cout<<"Tipo de Interprete: ";
        cin>>tipoDeInterprete;
    }
    return true;
}
bool Interpretes::generoMusicalValido(){
    while( !cin.good() || generoMusical <= 0 || generoMusical > 10 ){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        if( !menuContinuar() )
            return false;
        cout<<"Genero Musical: ";
        cin>>generoMusical;
    }
    return true;
}


void Interpretes::Cargar()
{
    estado = true;
    cout<<"Nombre Artista: ";
    cargarCadena(nombre,39);
    cout<<"Nacionalidad: ";
    cin>>nacionalidad;
    if( !nacionalidadValida() ){
        estado = false;
        return;
    }
    cout<<"Tipo de Interprete: ";
    cin>>tipoDeInterprete;
    if( tipoDeInterpreteValido() == false ){
        estado = false;
        return;
    }
    cout<<"Genero Musical: ";
    cin>>generoMusical;
    if( generoMusicalValido() == false ){
        estado = false;
        return;
    }
    cout<<"Fecha de Inicio: ";
    fechaInicio.Cargar();
}
void Interpretes::Mostrar()
{
    if(estado == true){
        cout<<"ID Interprete: ";
        cout<<interpreteID<<endl;
        cout<<"Nombre Artista: ";
        cout<<nombre<<endl;
        cout<<"Nacionalidad: ";
        cout<<nacionalidad<<endl;
        cout<<"Tipo de Interprete: ";
        cout<<tipoDeInterprete<<endl;
        cout<<"Genero Musical: ";
        cout<<generoMusical<<endl;
        cout<<"Fecha de Inicio: ";
        fechaInicio.Mostrar();
        cout<<endl;
    }
}

#endif // CLASEINTERPRETE_H_INCLUDED
