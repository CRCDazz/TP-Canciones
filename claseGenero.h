#ifndef CLASEGENERO_H_INCLUDED
#define CLASEGENERO_H_INCLUDED

class Generos{

    private:
            int generoID;
            char nombre[40];
            int paisDeOrigen;
            int tipoDeInstrumento;
            bool estado;
    public:
            void setGeneroID(int _generoID){generoID = _generoID;}
            void setNombre(const char *_nombre){strcpy(nombre, _nombre);}
            void setpaisDeOrigen(int _paisDeOrigen){paisDeOrigen = _paisDeOrigen;}
            void setTipoDeInstrumento(int _tipoDeInstrumento){tipoDeInstrumento = _tipoDeInstrumento;}
            void setEstado(bool _estado){estado = _estado;}

            int getGeneroID(){return generoID;}
            const char *getNombre(){return nombre;}
            int getPaisDeOrigen(){return paisDeOrigen;}
            int getTipoDeInstrumento(){return tipoDeInstrumento;}
            bool getEstado(){return estado;}

            bool paisDeOrigenValido();
            bool tipoDeInstrumentoValido();

            void Mostrar();
            void Cargar();
            bool leerDeDisco(int pos);
            bool grabarEnDisco();
            bool modificarEnDisco(int pos);

};

bool Generos::leerDeDisco(int pos){ //pos es la posición que ocupa el registro en el archivo, empezando por 0
    FILE *p;
    p=fopen("generos.dat","rb");
    if(p==NULL) return false;
    fseek(p, pos * sizeof (Generos), 0);
    bool leyo = fread(this, sizeof (Generos), 1, p);
    fclose(p);
    return leyo;
}

bool Generos::grabarEnDisco(){
    FILE *p;
    p=fopen("generos.dat","ab");
    if(p==NULL) return false;
    bool escribio = fwrite(this, sizeof (Generos), 1, p);
    fclose(p);
    return escribio;
}

bool Generos::modificarEnDisco(int pos){
    FILE *p;
    p=fopen("generos.dat","rb+");
    if(p==NULL) return false;
    fseek(p, pos * sizeof(Generos), 0);
    bool escribio=fwrite(this, sizeof (Generos), 1, p);
    fclose(p);
    return escribio;
}

bool Generos::paisDeOrigenValido(){
    while( !cin.good() || paisDeOrigen <= 0 || paisDeOrigen > 100 ){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        if(!menuContinuar())
            return false;
        cout<<"Pais De Origen: ";
        cin>>paisDeOrigen;
    }
    return true;
}
bool Generos::tipoDeInstrumentoValido(){
    while( !cin.good() || tipoDeInstrumento <= 0 || tipoDeInstrumento > 5 ){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        if(!menuContinuar())
            return false;
        cout<<"Tipo De Instrumentacion: ";
        cin>>tipoDeInstrumento;
    }
    return true;
}

void Generos::Mostrar(){
    if(estado == true){
        cout<<"ID genero: "<<generoID<<endl;
        cout<<"Nombre: "<<nombre<<endl;
        cout<<"Pais de Origen: "<<paisDeOrigen<<endl;
        cout<<"Tipo de instrumentacion: "<<tipoDeInstrumento<<endl;
    }
}
void Generos::Cargar(){
    cout<<"Ingrese Nombre: ";
    cargarCadena(nombre,39);
    cout<<"Pais De Origen: ";
    cin>>paisDeOrigen;
    if( !paisDeOrigenValido() ){
        estado = false;
        return;
    }
    cout<<"Tipo De Instrumentacion: ";
    cin>>tipoDeInstrumento;
    if( !tipoDeInstrumentoValido() ){
        estado = false;
        return;
    }
    estado = true;
}

#endif // CLASEGENERO_H_INCLUDED
