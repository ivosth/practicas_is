#include "citas_menu.h"
#include "funciones.h"
#include "citas.h"
#include <iostream>
#include <ctime>
#include <string>
#include <list>
#include <fstream>


string check_date(string date, string start, string end)
{
  ifstream in("./ficheros/citas.txt");
  string linea;
  string same_date="false";
  int start_min, end_min,start_aux_min, end_aux_min;
  string start_aux, end_aux;

  start_min=(stoi(start.substr(0,2))*60) + stoi(start.substr(3,2));
  end_min=(stoi(end.substr(0,2))*60) + stoi(end.substr(3,2));

  //Comprobar que la hora de inicio es inferior a la de fin y que se tiene que poner una cita que empieze y acabe en el mismo dia
  if(start_min>=end_min)
    return "true";

  while(getline(in,linea,';'))
  {
    getline(in,linea,';');
    if(linea==date)
    {
      getline(in,linea,';'); //string start
      start_aux=linea;
      getline(in,linea,';'); //string end
      end_aux=linea;

      //Convertir start_aux a min
      start_aux_min=(stoi(start_aux.substr(0,2))*60) + stoi(start_aux.substr(3,2));
      //cout<<"start_aux_min "<<start_aux_min<<endl;
      //cout<<"start_min "<<start_min<<endl;

      //Convertir end_aux a min
      end_aux_min=(stoi(end_aux.substr(0,2))*60) + stoi(end_aux.substr(3,2));
      //cout<<"end_aux_min "<<end_aux_min<<endl;
      //cout<<"end_min "<<end_min<<endl;

      if( ((start_min>=start_aux_min) && (start_min<=end_aux_min)) || ((end_min>=start_aux_min) && (end_min<=end_aux_min)) || ((start_min<=start_aux_min) && (end_min>=end_aux_min)))
      {
          same_date=date+" " + start_aux + " " + end_aux;
          return same_date;
      }
      else
        getline(in,linea,'\n');

    }
    else
      getline(in,linea,'\n');
  }

  in.close();
  return same_date;
}




bool add_date_menu(){
  string fullname, day, ini, end, description;
  string condition;
  time_t now = time(0);
  tm ltm= *localtime(&now); //www.tutorialspoint.com/cplusplus/cpp_date_time.htm
  int current_year=1900 + ltm.tm_year;
  int current_month= ltm.tm_mon +1;
  int current_day= ltm.tm_mday;

  cout << "Inserte el nombre completo del paciente" << '\n';
  getline(cin,fullname);
  if(find_patient(normalize(fullname))==true){

    while((condition!="false") && (condition!="true"))
    {
      cout<<"Inserte el dia de la cita(DD/MM/20XX)"<<endl;
      getline(cin,day);

      if( (day[2]!='/') || (day[5]!='/') ||  (stoi(day.substr(6,4))<current_year) || (stoi(day.substr(0,2))>=32) || (stoi(day.substr(3,2))>=13)  || (day.size()!=10) )
      {
        cout<<"Error en la fecha. Ejemplo: 24/03/2020"<<endl;
        return false;
      }

      if((stoi(day.substr(6,4))==current_year)  &&  (stoi(day.substr(0,2))<current_day)  && (stoi(day.substr(3,2))<=current_month))
      {
        cout<<"Error en la fecha, no se puede poner citas en una fecha anterior a la actual "<<current_day<<"/"<<current_month<<"/"<<current_year<<endl;
        return false;
      }

      cout<<"Inserte la hora de inicio de la cita(HH:MM)"<<endl;
      getline(cin,ini);
      if( (ini[2]!=':') || (stoi(ini.substr(0,2))>23) || (stoi(ini.substr(3,2))>60) ){
        cout<<"Error en la hora. Ejemplo: 00:30"<<endl;
        return false;
      }

      cout<<"Inserte la hora de fin de la cita(HH:MM)"<<endl;
      getline(cin,end);
      if( (end[2]!=':') || (stoi(end.substr(0,2))>23) || (stoi(end.substr(3,2))>60) ){
        cout<<"Error en la hora. Ejemplo: 00:30"<<endl;
        return false;
      }

      condition=check_date(day, ini, end);
      if(condition=="false")
        cout<<"No hay problema con la fecha"<<endl;
      else
      {
        if(condition=="true")
          cout<<"La hora de inicio es inferior a la de fin y/o se tiene que poner una cita que empieze y acabe en el mismo dia"<<endl;
        else
          cout<<"Coincide con la cita "<<check_date(day, ini, end)<<endl;

        return false;
      }


    }

    cout << "Inserte una descripción de la cita" << '\n';
    getline(cin, description);

    Date d(fullname,day, ini, end, description);
    d.add_date();
    return true;
  }
  else{
    cout << "No se ha encontrado el paciente" << '\n';
    return false;
  }
}


bool update_date_menu(){
  string fullname, day, ini, end, description;
  int i=1;
  int opt;
  string condition;
  time_t now = time(0);
  tm ltm= *localtime(&now); //www.tutorialspoint.com/cplusplus/cpp_date_time.htm
  int current_year=1900 + ltm.tm_year;
  int current_month= ltm.tm_mon +1;
  int current_day= ltm.tm_mday;


  cout << "Inserte el nombre completo del paciente" << '\n';
  getline(cin,fullname);

  ifstream in("./ficheros/citas.txt");
  string cadaux;

  while(getline(in,cadaux,';')){
    if (normalize(fullname)==cadaux){
      getline(in, cadaux,';');
      cout<<i<<". "<<cadaux<<endl;
      i++;
    }
    else{getline(in,cadaux,'\n');}
  }

  if(i!=1){
    cout <<"Elija la cita que quiera modificar ("<<i<<" para salir)"<<'\n';
    cin>>opt;

    if (opt==i){return false;}
    cout<<"Inserte la fecha de la nueva cita(DD/MM/20XX)"<<endl;
    getline(cin,day);
    getline(cin,day);

    if( (day[2]!='/') || (day[5]!='/') ||  (stoi(day.substr(6,4))<current_year) || (stoi(day.substr(0,2))>=32) || (stoi(day.substr(3,2))>=13)  || (day.size()!=10) )
    {
      cout<<"Error en la fecha. Ejemplo: 24/03/2020"<<endl;
      return false;
    }

    if((stoi(day.substr(6,4))==current_year)  &&  (stoi(day.substr(0,2))<current_day)  && (stoi(day.substr(3,2))<=current_month))
    {
      cout<<"Error en la fecha, no se puede poner citas en una fecha anterior a la actual "<<current_day<<"/"<<current_month<<"/"<<current_year<<endl;
      return false;
    }

    cout<<"Inserte la nueva hora de inicio de la cita(HH:MM)"<<endl;
    getline(cin,ini);

    if( (ini[2]!=':') || (stoi(ini.substr(0,2))>23) || (stoi(ini.substr(3,2))>60) ){
      cout<<"Error en la hora. Ejemplo: 00:30"<<endl;
      return false;
    }


    cout<<"Inserte la nueva hora de fin de la cita(HH:MM)"<<endl;
    getline(cin,end);

    if( (end[2]!=':') || (stoi(end.substr(0,2))>23) || (stoi(end.substr(3,2))>60) ){
      cout<<"Error en la hora. Ejemplo: 00:30"<<endl;
      return false;
    }


    condition=check_date(day, ini, end);
    if(condition=="false")
      cout<<"No hay problema con la fecha"<<endl;
    else
    {
      if(condition=="true")
        cout<<"La hora de inicio es inferior a la de fin y/o se tiene que poner una cita que empieze y acabe en el mismo dia"<<endl;
      else
        cout<<"Coincide con la cita "<<check_date(day, ini, end)<<endl;

      return false;
    }

    cout << "Inserte la nueva descripción de la cita" << '\n';
    getline(cin, description);

    Date d(fullname, day, ini, end, description);
    d.update_date(opt);
    in.close();

    return true;
  }
  else{
    cout << "No se ha encontrado ninguna cita con el nombre dado" << '\n';
    return false;
  }

}


bool todays_dates()
{
  time_t now = time(0);
  tm ltm= *localtime(&now); //www.tutorialspoint.com/cplusplus/cpp_date_time.htm
  string date;

  date= to_string(ltm.tm_mday) + "/" + to_string(ltm.tm_mon + 1) + "/" + to_string(1900 +ltm.tm_year);

  //Añadir el 0 del dia
  if(ltm.tm_mday<10)
    date= "0" + to_string(ltm.tm_mday) + "/" + to_string(ltm.tm_mon + 1) + "/" + to_string(1900 +ltm.tm_year);

  //Añadir el 0 del mes
  if(ltm.tm_mon<10)
    date= to_string(ltm.tm_mday) + "/0" + to_string(ltm.tm_mon + 1) + "/" + to_string(1900 +ltm.tm_year);

  Date d("aux");
  if(d.todays_dates(date)==false)
    return false;
  else
    return true;

}

bool delete_date_menu(){
  string fullname;
  int i=1;
  int opt;
  cout << "Inserte el nombre completo del paciente" << '\n';
  getline(cin,fullname);

  ifstream in("./ficheros/citas.txt");
  string cadaux;

  while(getline(in,cadaux,';')){
    if (normalize(fullname)==cadaux){
      getline(in, cadaux,';');
      cout<<i<<". "<<cadaux<<endl;
      i++;
    }
    else{getline(in,cadaux,'\n');}
  }

  if(i!=1){
    cout <<"Elija la cita que quiera cancelar ("<<i<<" para salir)"<<'\n';
    cin>>opt;
    if (opt==i){return false;}
    Date d(fullname);
    d.delete_date(opt);
    in.close();
    return true;
  }
  else{
    cout << "No se ha encontrado ninguna cita con el nombre dado" << '\n';
    in.close();
    return false;
  }

}

  bool show_dates_menu(){
    string fullname, cadaux;
    cout << "Inserte el nombre completo del paciente" << '\n';
    getline(cin,fullname);
    ifstream in ("./ficheros/pacientes.txt");
    while(getline(in,cadaux,';')){
      if (normalize(fullname)==cadaux){
        Date d(fullname);
        d.show_dates();
        return true;
      }
      else{getline(in,cadaux,'\n');}
    }
    in.close();
    return false;
  }
