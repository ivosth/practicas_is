#include "historial_menu.h"
#include "funciones.h"
#include "historial.h"
#include <iostream>
#include <ctime>
#include <string>
#include <list>
#include <fstream>


bool add_history_entry_menu()
{
  string fullname, description, date;
  cout<<"Introduzca el nombre del paciente a añadir una entrada en el historial"<<endl;
  getline(cin, fullname);

  if(find_patient(normalize(fullname))==false)
  {
    cout<<"El paciente con el nombre "<<fullname<<" no se encuentra registrado"<<endl;
    return false;
  }

  cout<<"Introduzca la descripción"<<endl;
  getline(cin, description);

  time_t now = time(0);
  date=ctime(&now);

  History h(fullname, description, date);
  h.add_history_entry();

  return true;

}



bool show_history_menu()
{
  string fullname;
  cout<<"Introduzca el nombre del paciente a mostrar su historial"<<endl;
  getline(cin, fullname);

  if(find_patient(normalize(fullname))==false)
  {
    cout<<"El paciente con el nombre "<<fullname<<" no se encuentra registrado"<<endl;
    return false;
  }

  list <History> entries;
  History aux("fullname_aux", "description_aux", "date_aux");

  string fullname_aux, description_aux, date_aux, linea;
  ifstream fe("./ficheros/historial.txt");

  while(getline(fe, linea, ';'))
  {
    fullname_aux=linea;
    if(normalize(fullname)==fullname_aux)
    {
      getline(fe, linea, ';');
      description_aux=linea;
      getline(fe, linea, '\n');
      date_aux=linea;

      History entry(fullname_aux, description_aux, date_aux);
      entries.push_back(entry);

    }
    else
      getline(fe, linea, '\n');

  }

  fe.close();
  aux.show_history(entries);

  return true;
}
