#include "funciones.h"
#include <iostream>
//#include <locale>
//#include <stdio.h>
//#include <iomanip>
//#include <ctime>
//#include <string>
using namespace std;

int main(void)
{
  int option;
  string buffer;
  do
  {
    cout<<"1.Mostrar paciente"<<endl;
    cout<<"2.Añadir paciente"<<endl;
    cout<<"3.Cambiar paciente"<<endl;
    cout<<"4.Eliminar paciente"<<endl;
    cout<<"14.Añadir entrada del historial"<<endl;
    cin>>option;
    getline(cin, buffer);

    switch(option)
    {
      case 1:
      {
        if(show_patient_menu()==false)
          cout<<"Error"<<endl;
      }break;

      case 2:
      {
        if(add_patient_menu()==false)
          cout<<"Error"<<endl;
      }break;

      case 3:
      {
        if(change_patient_menu()==false)
          cout<<"Error"<<endl;
      }break;

      case 4:
      {
        if(delete_patient_menu()==false)
          cout<<"El paciente no se ha eliminado"<<endl;
      }break;

      case 14:
      {
        if(add_history_entry_menu()==false)
          cout<<"No se ha añadido la entrada al historial"<<endl;
      }break;
    }

  } while(option!=16);



  //char cad[50]="Rafael Mancha DiéguezñÑÁáÉéÍíÓóÚú";
  //string str="Rafael Mancha DiéguezñÑÁáÉéÍíÓóÚú";
/*
  for(int i=0; i<50; i++)
  {
    printf("%i = ", cad[i]);
    cout<<str[i]<<endl;
  }
  */


  return 0;
}
