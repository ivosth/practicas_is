#include "citas.h"
#include "funciones.h"
#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;


Date::Date(string fullname, string date, string start, string end, string description)
{
  fullname_=fullname;
  date_=date;
  start_=start;
  end_=end;
  description_=description;
}


void Date::add_date(){
  ofstream fs("citas.txt", ios::app);
  fs<<normalize(fullname_)<<";"<<date_<<";"<<start_<<";"<<end_<<";"<<normalize(description_)<<"\n";
  fs.close();
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
        fs<<normalize(fullname_)<<";"<<date_<<";"<<start_<<";"<<end_<<";"<<normalize(description_)<<"\n";
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


bool Date::todays_dates(string date)
{
  bool result=false;
  string linea, fullname_aux, start_aux, end_aux, description_aux;
  ifstream in("citas.txt");

  while(getline(in,linea,';'))//string fullname
  {
    fullname_aux=linea;
    getline(in,linea,';'); //string date
    if(linea==date)
    {
      getline(in,linea,';'); //string start
      start_aux=linea;

      getline(in,linea,';'); //string end
      end_aux=linea;

      getline(in,linea,'\n'); //string description
      description_aux=linea;

      cout<<fullname_aux<<" "<<date<<" "<<start_aux<<" "<< end_aux<<" "<<description_aux<<endl;
      result=true;
    }
    else
      getline(in,linea,'\n');
  }

  return result;
}
