#include "citas.h"
#include "funciones.h"
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


void Date::add_date(){
  ofstream fs("citas.txt", ios::app);
  fs<<normalize(fullname_)<<";"<<normalize(start_)<<";"<<normalize(end_)<<";"<<normalize(description_)<<"\n";
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
