#ifndef CLASEFECHA_H_INCLUDED
#define CLASEFECHA_H_INCLUDED

class Fecha{
private:
    int dia, mes, anio;
public:
    void setDia(int d){dia=d;}
    void setMes(int d){mes=d;}
    void setAnio(int d){anio=d;}
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}

    bool fechaValida();
    bool compararFecha();

    void Cargar(){
        cout<<"DIA: ";
        cin>>dia;
        cout<<"MES: ";
        cin>>mes;
        cout<<"ANIO: ";
        cin>>anio;
    }
    void Mostrar(){
        cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
    }
};

bool Fecha::fechaValida(){
    bool bisiesto = false;

    if( ( anio%4==0 && anio%100!=0 ) || anio%400==0 )
        bisiesto = true;

    if( bisiesto==true && mes==2 && dia>0 && dia<30 )
        return true;
    if( bisiesto==false && mes==2 && dia>0 && dia<29 )
        return true;
    if( ( mes==1 || mes==3 || mes==5 || mes==7 || mes==10 || mes==12 ) && dia>0 && dia<32 )
        return true;
    if( ( mes==4 || mes==6 || mes==8 || mes==9 || mes==11 ) && dia>0 && dia<31 )
        return true;
    return false;
}


bool Fecha::compararFecha(){

    time_t fechaActual(0);
    tm *local;

    time(&fechaActual);
    local = localtime(&fechaActual);

    if( anio < local->tm_year+1900 ){
        return true;
    }
    if( (anio==local->tm_year+1900 && mes==local->tm_mon+1 && dia<=local->tm_mday) || (anio==local->tm_year+1900 && mes<local->tm_mon+1) ){
        return true;
    }
    return false;
}

#endif // CLASEFECHA_H_INCLUDED



/*
    if( anio == (local->tm_year+1900) ){
        if( mes==local->tm_mon+1){
            if( dia<=local->tm_mday){
                return true;
            }else{
                cout<<"..............fecha IN-Correcta............"<<endl<<endl;
                return false;
            }
        }else{
            if( mes<local->tm_mon+1){
                return true;
            }else{
                cout<<"..............fecha IN-Correcta............"<<endl<<endl;
                return false;
            }
        }
    }else{
        if( anioAux < (local->tm_year+1900) ){
            return true;
        }else{
            cout<<"..............fecha IN-Correcta............"<<endl<<endl;
            return false;
        }
    }
*/
