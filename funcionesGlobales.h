#ifndef FUNCIONESGLOBALES_H_INCLUDED
#define FUNCIONESGLOBALES_H_INCLUDED

int buscarInterprete(int );
int buscarIDcancion(int );
bool agregarCancion();
int buscarGeneroMusical(int );
int cantidadCanciones();
int cantidadInterpretes();
int cantidadGeneros();

/******** CANCIONES *********/
bool agregarCancion(){
    Canciones objCanciones,aux;
    objCanciones.Cargar();
    if(objCanciones.getEstado() == false)
        return false;
    if( buscarInterprete(objCanciones.getID_interprete()) == -1 )
        return false;
    if(cantidadCanciones() <= 0){
        objCanciones.setID_cancion(1);
        return objCanciones.grabarEnDisco();
    }else{
        aux.leerDeDisco(cantidadCanciones()-1);
        int ultimoID = aux.getID_cancion();
        objCanciones.setID_cancion(ultimoID+1);
        return objCanciones.grabarEnDisco();
    }
}
void listarCancion(){
    Canciones obj;
    int id,pos;
    cout<<"Ingrese ID de la Cancion: ";
    cin>>id;
    pos=buscarIDcancion(id);
    if(pos!=-1){
        obj.leerDeDisco(pos);
        obj.Mostrar();
    }else
        cout<<"ID Inexistente."<<endl;
}
void mostrarCanciones(){
    Canciones obj;
    int pos=0;
    while(obj.leerDeDisco(pos++))
    {
        obj.Mostrar();
    }
}
bool modificarFechaCancion(){
    Canciones obj;
    Fecha nuevaFecha;
    int id,pos;
    cout<<"Ingrese ID de la Cancion: ";
    cin>>id;
    pos=buscarIDcancion(id-1);
    if( !(pos==-1) ){
        obj.leerDeDisco(pos);
        nuevaFecha.Cargar();
        obj.setFechaDeEstreno(nuevaFecha);
        obj.modificarEnDisco(pos);
        return true;
    }else{
        cout<<"ID Inexistente."<<endl;
        return false;
    }
}
bool eliminarCanciones(){
    Canciones obj;
    int id,pos;
    cout<<"Ingrese ID de la Cancion: ";
    cin>>id;
    pos=buscarIDcancion(id);
    if( !(pos==-1) ){
        obj.leerDeDisco(pos);
        obj.setEstado(false);
        obj.modificarEnDisco(pos);
        return true;
    }else{
        cout<<"ID Inexistente."<<endl;
        return false;
    }

}

/******** INTERPRETES *********/
bool agregarInterprete(){
    Interpretes obj,aux;
    obj.Cargar();
    if(obj.getEstado() == false)
        return false;
    if(cantidadInterpretes() <= 0){
        obj.setInterpreteID(1);
        return obj.grabarEnDisco();
    }else{
        aux.leerDeDisco(cantidadInterpretes()-1);
        int ultimoID = aux.getInterpreteID();
        obj.setInterpreteID(ultimoID+1);
        return obj.grabarEnDisco();
    }
}
void listarInterprete()
{
    Interpretes obj;
    int id, pos;
    cout<<"Ingrese ID del Interprete: ";
    cin>>id;
    pos = buscarInterprete(id);
    if( pos != -1 ){
        obj.leerDeDisco(pos);
        obj.Mostrar();
    }else
        cout<<"ID Inexistente."<<endl;
}
void mostrarInterpretes()
{
    Interpretes obj;
    int pos=0;
    while(obj.leerDeDisco(pos)){
        obj.Mostrar();
        pos++;
    }
}
bool modificarGeneroMusical()
{
    Interpretes obj;
    int id, valGenMusical, pos;
    cout<<"Ingrese ID del Interprete: ";
    cin>>id;
    pos = buscarInterprete(id);
    if( pos != -1 ){
        obj.leerDeDisco(pos);
        cout<<"Ingrese Genero Musical Principal: ";
        cin>>valGenMusical;
        obj.setGeneroMusical(valGenMusical);
        obj.modificarEnDisco(pos);
        return true;
    }else{
        cout<<"ID Inexistente."<<endl;
        return false;
    }
}
bool eliminarInterprete()
{
    Interpretes obj;
    int id, pos;
    cout<<"Ingrese ID del Interprete: ";
    cin>>id;
    pos = buscarInterprete(id);
    if( pos != -1){
        obj.leerDeDisco(pos);
        obj.setEstado(false);
        obj.modificarEnDisco(pos);
        return true;
    }else{
        cout<<"ID Inexistente."<<endl;
        return false;
    }
}

/******** GENEROS *********/
bool agregarGenero()
{
    Generos obj,aux;
    obj.Cargar();
    if(obj.getEstado() == false)
        return false;
    if(cantidadGeneros() <= 0){
        obj.setGeneroID(1);
        return obj.grabarEnDisco();
    }else{
        aux.leerDeDisco(cantidadGeneros()-1);
        int ultimoID = aux.getGeneroID();
        obj.setGeneroID(ultimoID+1);
        return obj.grabarEnDisco();
    }

}
void listarGenero()
{
    Generos obj;
    int id,pos;
    cout<<"Ingrese ID del Genero Musical: ";
    cin>>id;
    pos = buscarGeneroMusical(id);
    if( pos != -1 /*&& (obj.getEstado() != false)*/ ){
        obj.leerDeDisco(pos);
        obj.Mostrar();
    }else{
        cout<<"ID Inexistente."<<endl;
    }
}
void mostrarGeneros()
{
    Generos obj;
    int pos=0;
    while(obj.leerDeDisco(pos++)){
        obj.Mostrar();
    }
}
bool modificarTipoInstrumentacion()
{
    Generos obj;
    int tipoInstr,id,pos;
    cout<<"Ingrese ID del Genero Musical: ";
    cin>>id;
    pos = buscarGeneroMusical(id);
    if( pos != -1 ){
        cout<<"Ingrese Nuevo TIPO de INSTRUMENTACION: ";
        cin>>tipoInstr;
        obj.leerDeDisco(pos);
        obj.setTipoDeInstrumento(tipoInstr);
        obj.modificarEnDisco(pos);
        return true;
    }else{
        cout<<"ID Inexistente."<<endl;
        return false;
    }
}

/*******************************/
int cantidadCanciones()
{
    FILE *archivo;
    int cantidad=0;
    archivo=fopen("canciones.dat","rb");
    if(archivo==NULL){return -1;}
    fseek(archivo,0,SEEK_END);
    if(ftell(archivo) == 0){
        fclose(archivo);
        return cantidad;
    }
    cantidad=(ftell(archivo)/sizeof(Canciones));
    fclose(archivo);
    return cantidad;
}
int cantidadInterpretes()
{
    FILE *archivo;
    int cantidad;
    archivo=fopen("interpretes.dat","rb");
    if(archivo==NULL){return -1;}
    fseek(archivo,0,SEEK_END);
    if(ftell(archivo) == 0){
        fclose(archivo);
        return 0;
    }
    cantidad=(ftell(archivo)/sizeof(Interpretes));
    fclose(archivo);
    return cantidad;
}
int cantidadGeneros()
{
    FILE *archivo;
    int cantidad;
    archivo=fopen("generos.dat","rb");
    if(archivo==NULL){return -1;}
    fseek(archivo,0,SEEK_END);
    if(ftell(archivo) == 0){
        fclose(archivo);
        return 0;
    }
    cantidad=(ftell(archivo)/sizeof(Generos));
    fclose(archivo);
    return cantidad;
    /**
    if(archivo==NULL){return -1;}
    while(fread(&obj,sizeof(Genero),1,archivo)==1){
        pos++;
    }
    fclose(archivo);
    return pos;
    **/
}
int buscarIDcancion(int id){
    Canciones obj;
    int pos=0;
    while(obj.leerDeDisco(pos)){
        if( (id == obj.getID_cancion()) && (obj.getEstado() == true) )
            return pos;
        pos++;
    }
    return -1;
}
int buscarInterprete(int id){
    Interpretes obj;
    int pos=0;
    while(obj.leerDeDisco(pos)){
        if( (id == obj.getInterpreteID()) && (obj.getEstado() == true) )
            return pos;
        pos++;
    }
    return -1;
}
int buscarGeneroMusical(int id)
{
    Generos obj;
    int pos=0;
    while( obj.leerDeDisco(pos) ){
        if((obj.getEstado() == false))
            return -1;
        if( id == obj.getGeneroID() )
            return pos;
        pos++;
    }
    return -2;
}
#endif // FUNCIONESGLOBALES_H_INCLUDED
