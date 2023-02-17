#include <iostream>
#include <cstring>
#include <iomanip>
#include <time.h>
#include <limits>
#include <conio.h>
#include <string>

using namespace std;
#include "funcionesAuxiliares.h"
#include "claseFecha.h"
#include "cargarCadena.h"
#include "claseCancion.h"
#include "claseInterprete.h"
#include "claseGenero.h"
#include "Menu.h"
#include "funcionesGlobales.h"

int main()
{
    //setlocale(LC_CTYPE, "Spanish");

    bool salir = false;
    system("color 57");
    do{
        fflush(stdin);
        switch(menuPrincipal())
        {
        case '1':   subMenuCanciones();
                    break;
        case '2':   subMenuInterprete();
                    break;
        case '3':   subMenuGenero();
                    break;
        case '4':   subMenuReportes();
                    break;
        case '5':   subMenuConfiguracion();
                    break;
        case '0':   salir = true;
                    cout<<"FIN DEL PROGRAMA"<<endl<<endl;
                    break;
        default:
                    break;
        }
    }while(!salir);
}



/**
int main()
{
  int var;

  while( true )
  {
    std::cin >> var;
    if( !std::cin.good() )
    {
      std::cout << "ERROR\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    else
      break;
  }

  std::cout << var;


  std::cout <<numeric_limits<std::streamsize>::max();
}

**/

/**

void clearBuf(void);
int validFormat(const char*, void*);

int main(void)
{

    float a;
    int result;
    do
    {
        printf("Ingresa tu calificacion de matematicas (1.00 - 10.00):\n");
        //Si la funci�n retorna 1 fue porque el usuario no respet� el formato.
        if(validFormat("%f", &a))
        {
            printf("Error: No puedes ingresar letras!\n");
            //La sentencia continue hace que pasemos a la pr�xima iteraci�n.
            continue;
        }
        //Guardamos el resultado de la condici�n en la variable.
        result = a < 1.00 || a > 10.00;
        if (result) //Equivalente a (result != 0)
            printf("Error: Ingrese una calificacion valida!\n");
    } while(result); //Equivalente a (result != 0)
    return 0;
}

int validFormat(const char* fm, void* a)
{
    //Si la funci�n scanf retorna 0, fue porque hubo una falla en la lectura..
    if(!scanf(fm, a))
    {
        //Limpiamos el b�fer del teclado para que la pr�xima lectura se lleve a cabo.
        clearBuf();
        return 1;
    }
    //Si no encontramos un salto de l�nea en el b�fer, es porque el usuario no cumpli� con el formato.
    if(getchar() != '\n')
    {
        //Volvemos a limpiar el b�fer para la pr�xima lectura.
        clearBuf();
        return 1;
    }
    return 0;
}

void clearBuf()
{
    int ch;
    //Limpia el b�fer del teclado hasta encontrar un salto de l�nea o fin del archivo
    while((ch = getchar()) != '\n' && ch != EOF);
}
**/
