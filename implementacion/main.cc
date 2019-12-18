#include "paciente_menu.h"
#include "citas_menu.h"
#include "historial_menu.h"
#include "tratamiento_menu.h"
#include <iostream>

using namespace std;

int main(void)
{
  int option;
  string buffer;
  do
  {
    cout<<"1.Mostrar paciente"<<endl;
    cout<<"2.Añadir paciente"<<endl;
    cout<<"3.Modificar paciente"<<endl;
    cout<<"4.Eliminar paciente"<<endl;
    cout<<"5.Mostrar cita diarias"<<endl;
    cout<<"6.Mostrar citas"<<endl;
    cout<<"7.Añadir cita"<<endl;
    cout<<"8.Modificar cita"<<endl;
    cout<<"9.Cancelar cita"<<endl;
    cout<<"10.Añadir tratamiento"<<endl;
    cout<<"11.Modificar tratamiento"<<endl;
    cout<<"12.Mostrar tratamiento"<<endl;
    cout<<"13.Añadir entrada del historial"<<endl;
    cout<<"14.Mostrar historial"<<endl;
    cout<<"15.Salir"<<endl;

    cin>>option;
    getline(cin, buffer);

    switch(option)
    {
      case 1:
      {
        if(show_patient_menu()==false)
          cout<<"Error al mostrar el paciente"<<endl;
      }break;

      case 2:
      {
        if(add_patient_menu()==false)
          cout<<"No se ha añadido al paciente"<<endl;
      }break;

      case 3:
      {
        if(change_patient_menu()==false)
          cout<<"No se ha modificado el paciente"<<endl;
      }break;

      case 4:
      {
        if(delete_patient_menu()==false)
          cout<<"El paciente no se ha eliminado"<<endl;
      }break;

      case 5:
      {
        if(todays_dates()==false)
          cout<<"No hay citas programadas para hoy"<<endl;
      }break;

      case 6:
      {
        if(show_dates_menu()==false){
          cout<<"No se ha encontrado el paciente"<<endl;
        }
      }break;

      case 7:
      {
        if(add_date_menu()==false)
          cout<<"La cita no se ha añadido"<<endl;
      }break;

      case 8:
      {
        if(update_date_menu()==false)
          cout<<"La cita no se ha modificado"<<endl;
      }break;

      case 9:
      {
        if(delete_date_menu()==false)
          cout<<"La cita no se ha cancelado"<<endl;
      }break;

      case 10:
      {
        if(add_treatment_menu()==false)
          cout<<"El tratamiento no se ha añadido"<<endl;
      }break;

      case 11:
      {
        if(modify_treatment_menu()==false)
          cout<<"El tratamiento no se ha modificado"<<endl;
      }break;

      case 12:
      {
        if(show_treatment_menu()==false)
          cout<<"Error al mostrar tratamiento"<<endl;
      }break;

      case 13:
      {
        if(add_history_entry_menu()==false)
          cout<<"No se ha añadido la entrada al historial"<<endl;
      }break;

      case 14:
      {
        if(show_history_menu()==false)
          cout<<"No se ha podido mostrar el historial del paciente"<<endl;
      }break;
    }

  } while(option!=15);



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
