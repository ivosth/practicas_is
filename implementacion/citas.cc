#include "citas.h"
#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

Date::Date(string fullname, string start, string end, string description)
{
  fullname_=fullname;
  start_=start;
  end_=end;
  description_=description;
}

string normalize(string chain)
{
  for(int unsigned i=0; i<chain.size(); i++)
  {
    if ((chain[i]==-87) || (chain[i]==-119))  chain.replace(i-1,2,"E");
    else
    {
      if (chain[i]==-79)  chain.replace(i-1,2,"Ñ");
      else
      {
        if ((chain[i]==-127) || (chain[i]==-95))  chain.replace(i-1,2,"A");
        else
        {
          if ((chain[i]==-115) || (chain[i]==-83))  chain.replace(i-1,2,"I");
          else
          {
            if ((chain[i]==-109) || (chain[i]==-77))  chain.replace(i-1,2,"O");
            else
            {
              if ((chain[i]==-102) || (chain[i]==-70))  chain.replace(i-1,2,"U");
            }
          }
        }
      }
    }

    //if (chain[i]=='\xC3\xB1')   ñ
      //chain[i]='\xc3\x91';    Ñ
    chain[i]=toupper(chain[i]);
  }

  return chain;

}


bool find_pacient(string fullname){

  ifstream in("pacientes.txt");
  string cadaux;
  while(getline(in,cadaux,',')){
    if (fullname==cadaux){
      in.close();
      return true;
    }
    else{getline(in,cadaux,'\n');}
  }
  in.close();
  return false;
  exit(-1);

}

void add_date_menu(){
  string fullname, ini, end, description;
  std::cout << "Inserte el nombre completo del paciente" << '\n';
  getline(cin,fullname);
  if(find_pacient(normalize(fullname))==true){
    cout<<"Inserte la fecha de la cita(DD/MM/20XX HH:MM)"<<endl;
    getline(cin,ini);
    if( (ini[2]!='/') && (ini[5]!='/') && (ini[13]!=':') ){
      cout<<"Error en la hora. Ejemplo: 24/03/2020 18:30";
      exit(-1);
    }
    cout<<"Inserte la hora de fin de la cita(HH:MM)"<<endl;
    getline(cin,end);
    if( (end[2]!=':') ){
      cout<<"Error en la hora. Ejemplo: 18:30";
      exit(-1);
    }
    std::cout << "Inserte una descripción de la cita" << '\n';
    getline(cin, description);
    Date d(fullname, ini, end, description);
    d.add_date();
  }
  else{
    std::cout << "No se ha encontrado el paciente" << '\n';
  }
}



void Date::add_date(){
  ofstream fs("citas.txt", ios::app);
  fs<<normalize(fullname_)<<";"<<normalize(start_)<<";"<<normalize(end_)<<";"<<normalize(description_)<<"\n";
  fs.close();
}

void update_date_menu(){
  string fullname, ini, end, description;
  int i=1;
  int opt;
  std::cout << "Inserte el nombre completo del paciente" << '\n';
  getline(cin,fullname);
  ifstream in("citas.txt");
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
    std::cout <<"Elija la cita que quiera modificar ("<<i<<" para salir)"<<'\n';
    cin>>opt;
    if (opt==i){exit(-1);}
    cout<<"Inserte la fecha de la nueva cita(DD/MM/20XX HH:MM)"<<endl;
    getline(cin,ini);
    getline(cin,ini);
    if( (ini[2]!='/') && (ini[5]!='/') && (ini[13]!=':') ){
          cout<<"Error en la fecha. Ejemplo: 24/03/2020 18:30"<<endl;
          exit(-1);
    }
    cout<<"Inserte la nueva hora de fin de la cita(HH:MM)"<<endl;
    getline(cin,end);
    if( (end[2]!=':') ){
      cout<<"Error en la hora. Ejemplo: 18:30"<<endl;
      exit(-1);
    }
    std::cout << "Inserte la nueva descripción de la cita" << '\n';
    getline(cin, description);
    Date d(fullname, ini, end, description);
    d.update_date(opt);
    in.close();
    std::cout << "Cita actualizada" << '\n';
    exit(-1);
  }
  else{
    std::cout << "No se ha encontrado ninguna cita con el nombre dado" << '\n';
  }

}

void Date::update_date(int n){
  ifstream in("citas.txt");
  ofstream fs("citasaux.txt");
  string cadaux;
  int i=1;
  while(getline(in,cadaux,';')){
    if (normalize(fullname_)!=cadaux){
      fs<<cadaux<<";";
      getline(in,cadaux,'\n');
      fs<<cadaux<<"\n";
    }
    else{
      if (i==n){
        fs<<normalize(fullname_)<<";"<<normalize(start_)<<";"<<normalize(end_)<<";"<<normalize(description_)<<"\n";
        getline(in,cadaux,'\n');
        i++;
      }
      else{
        i++;
        fs<<cadaux<<";";
        getline(in,cadaux,'\n');
        fs<<cadaux<<"\n";
      }
    }
  }
  in.close();
  fs.close();
  remove("citas.txt");
  rename("citasaux.txt","citas.txt");
}
