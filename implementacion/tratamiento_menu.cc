#include "tratamiento.h"
#include "tratamiento_menu.h"
#include "funciones.h"
#include <iostream>
#include <string>
#include <list>
#include <fstream>

bool add_treatment_menu(){
  string fullname, start, end, regularity, concentration, dose;
  time_t now = time(0);
  tm ltm= *localtime(&now); //www.tutorialspoint.com/cplusplus/cpp_date_time.htm
  int current_year=1900 + ltm.tm_year;
  int current_month= ltm.tm_mon +1;
  int current_day= ltm.tm_mday;

  cout<<"Introduzca el nombre del paciente a añadir tratamiento"<<endl;
  getline(cin, fullname);

  /* Búsqueda del paciente*/
  if(find_patient(normalize(fullname))==false)
  {
    cout<<"El paciente con el nombre "<<fullname<<" no se encuentra registrado"<<endl;
    return false;
  }
  /* Fecha de inicio */
    cout<<"Introduzca la fecha de inicio del tratamiento con formato DD/MM/20XX"<<endl;
    getline(cin, start);

    if( (start[2]!='/') || (start[5]!='/') ||  (stoi(start.substr(6,4))<current_year) || (stoi(start.substr(0,2))>=32) || (stoi(start.substr(3,2))>=13)  || (start.size()!=10) )
    {
      cout<<"Error en la fecha. Ejemplo: 24/03/2020"<<endl;
      return false;
    }

    if((stoi(start.substr(6,4))==current_year)  &&  (stoi(start.substr(0,2))<current_day)  && (stoi(start.substr(3,2))<=current_month))
    {
      cout<<"Error en la fecha, no se puede añadir tratamiento en una fecha anterior a la actual "<<current_day<<"/"<<current_month<<"/"<<current_year<<endl;
      return false;
    }

    /* Fecha de fin */
    cout<<"Introduzca la fecha de fin del tratamiento con formato DD/MM/20XX"<<endl;
    getline(cin, end);

    if( (end[2]!='/') || (end[5]!='/') ||  (stoi(end.substr(6,4))<current_year) || (stoi(end.substr(0,2))>=32) || (stoi(end.substr(3,2))>=13)  || (end.size()!=10) )
    {
      cout<<"Error en la fecha. Ejemplo: 24/03/2020"<<endl;
      return false;
    }

    if((stoi(end.substr(6,4))==current_year)  &&  (stoi(end.substr(0,2))<current_day)  && (stoi(end.substr(3,2))<=current_month))
    {
      cout<<"Error en la fecha, no se puede añadir tratamiento en una fecha anterior a la actual "<<current_day<<"/"<<current_month<<"/"<<current_year<<endl;
      return false;
    }

    /* Regularidad */
    cout << "Inserte la regularidad del tratamiento" << '\n';
    getline(cin, regularity);

    /* Concentracion */
    cout << "Inserte la concentracion del tratamiento" << '\n';
    getline(cin, concentration);

    /* Dosis */
    cout << "Inserte la dosis del tratamiento" << '\n';
    getline(cin, dose);

    Treatment t(fullname, start, end, regularity, concentration, dose);
    t.add_treatment();

  return true;
}

bool show_treatment_menu(){
  string fullname;
  cout<<"Introduzca el nombre del paciente a mostrar su tratamiento"<<endl;
  getline(cin, fullname);

  if(find_patient(normalize(fullname))==false)
  {
    cout<<"El paciente con el nombre "<<fullname<<" no se encuentra registrado"<<endl;
    return false;
  }

  list<Treatment> entries;
  Treatment aux("fullname_aux", "start_aux", "end_aux", "regularity_aux", "concentration_aux", "dose_aux");

  string fullname_aux, start_aux, end_aux, regularity_aux, concentration_aux, dose_aux, linea;
  ifstream fe("tratamientos.txt");

  while(getline(fe, linea, ';'))
  {
    fullname_aux=linea;
    if(normalize(fullname)==fullname_aux)
    {
      getline(fe, linea, ';');
      start_aux=linea;
      getline(fe, linea, ';');
      end_aux=linea;
      getline(fe, linea, ';');
      regularity_aux=linea;
      getline(fe, linea, ';');
      concentration_aux=linea;
      getline(fe, linea, '\n');
      dose_aux=linea;

      Treatment entry(fullname_aux, start_aux, end_aux, regularity_aux, concentration_aux, dose_aux);
      entries.push_back(entry);

    }
    else
      getline(fe, linea, '\n');

  }

  fe.close();
  aux.show_treatment(entries);

  return true;
}


bool modify_treatment_menu(){
  string fullname, start, end, regularity, concentration, dose;
  int i=1;
  int opt;
  time_t now = time(0);
  tm ltm= *localtime(&now); //www.tutorialspoint.com/cplusplus/cpp_date_time.htm
  int current_year=1900 + ltm.tm_year;
  int current_month= ltm.tm_mon +1;
  int current_day= ltm.tm_mday;


  cout << "Inserte el nombre completo del paciente" << '\n';
  getline(cin,fullname);

  ifstream in("tratamientos.txt");
  string cad;

  while(getline(in,cad,';')){
    if (normalize(fullname)==cad){
      getline(in, cad,';');
      cout<<i<<". "<<cad<<endl;
      ++i;
    }
    else{getline(in,cad,'\n');}
  }

  if(i!=1){
    cout <<"Elija el tratamiento que desea modificar ("<<i<<" para salir)"<<'\n';
    cin>>opt;

    if (opt==i){return false;}
    /* Fecha de inico */
    cout<<"Inserte la nueva fecha de inicio con formato DD/MM/20XX"<<'\n';
    getline(cin,start);
    getline(cin,start);

    if( (start[2]!='/') || (start[5]!='/') ||  (stoi(start.substr(6,4))<current_year) || (stoi(start.substr(0,2))>=32) || (stoi(start.substr(3,2))>=13)  || (start.size()!=10) )
    {
      cout<<"Error en la fecha. Ejemplo: 24/03/2020"<<endl;
      return false;
    }

    if((stoi(start.substr(6,4))==current_year)  &&  (stoi(start.substr(0,2))<current_day)  && (stoi(start.substr(3,2))<=current_month))
    {
      cout<<"Error en la fecha, no se puede añadir tratamiento en una fecha anterior a la actual "<<current_day<<"/"<<current_month<<"/"<<current_year<<endl;
      return false;
    }

    /* Fecha de fin */
    cout<<"Introduzca la fecha de fin del tratamiento con formato DD/MM/20XX"<<endl;
    getline(cin, end);

    if( (end[2]!='/') || (end[5]!='/') ||  (stoi(end.substr(6,4))<current_year) || (stoi(end.substr(0,2))>=32) || (stoi(end.substr(3,2))>=13)  || (end.size()!=10) )
    {
      cout<<"Error en la fecha. Ejemplo: 24/03/2020"<<endl;
      return false;
    }

    if((stoi(end.substr(6,4))==current_year)  &&  (stoi(end.substr(0,2))<current_day)  && (stoi(end.substr(3,2))<=current_month))
    {
      cout<<"Error en la fecha, no se puede añadir tratamiento en una fecha anterior a la actual "<<current_day<<"/"<<current_month<<"/"<<current_year<<endl;
      return false;
    }

    /* Regularidad */
    cout << "Inserte la nueva regularidad del tratamiento" << '\n';
    getline(cin, regularity);

    /* Concentracion */
    cout << "Inserte la nueva concentracion del tratamiento" << '\n';
    getline(cin, concentration);

    /* Dosis */
    cout << "Inserte la nueva dosis del tratamiento" << '\n';
    getline(cin, dose);

    Treatment t(fullname, start, end, regularity, concentration, dose);
    t.modify_treatment(opt);
    in.close();

    cout << "Tratamiento actualizado" << '\n';
    return true;
  }
  else{
    cout << "No se ha encontrado ningun tratamiento con el nombre dado" << '\n';
    return false;
  }
}
