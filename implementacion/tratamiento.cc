#include "tratamiento.h"
#include "funciones.h"
#include <string>
#include <fstream>
#include <ctime>
#include <iostream>
#include <list>
#include <stdio.h>


using namespace std;

Treatment::Treatment(string fullname, string start, string end, string regularity, string concentration, string dose){
  fullname_=fullname;
  start_=start;
  end_=end;
  regularity_=regularity;
  concentration_=concentration;
  dose_=dose;
}

void Treatment::add_treatment(){
  ofstream fs("./ficheros/tratamientos.txt", ios::app);

  fs<<normalize(fullname_)<<";"<<start_<<";"<<end_<<";"<<normalize(regularity_)<<";"<<normalize(concentration_)<<";"<<normalize(dose_)<<endl;

  fs.close();
}

void Treatment::show_treatment(list<Treatment> entries){
  list<Treatment>::iterator it;

  for(it=entries.begin(); it!=entries.end(); ++it){
    cout<<endl<<"Inicio: "<<it->getStart()<<endl;
    cout<<"Fin: "<<it->getEnd()<<endl;
    cout<<"Regularidad: "<<it->getRegularity()<<endl;
    cout<<"Concentracion: "<<it->getConcentration()<<endl;
    cout<<"Dosis: "<<it->getDose()<<endl<<endl;
  }
}

void Treatment::modify_treatment(int n){
  ifstream in("./ficheros/tratamientos.txt");
  ofstream fs("./ficheros/tratamientos_aux.txt");
  string cad;
  int i=1;
  while(getline(in,cad,';')){
    if (normalize(fullname_)!=cad){
      fs<<cad<<";";
      getline(in,cad,'\n');
      fs<<cad<<"\n";
    }
    else{
      if (i==n){
        fs<<normalize(fullname_)<<";"<<start_<<";"<<end_<<";"<<normalize(regularity_)<<";"<<normalize(concentration_)<<";"<<normalize(dose_)<<"\n";
        getline(in,cad,'\n');
        i++;
      }
      else{
        i++;
        fs<<cad<<";";
        getline(in,cad,'\n');
        fs<<cad<<"\n";
      }
    }
  }
  in.close();
  fs.close();
  remove("./ficheros/tratamientos.txt");
  rename("./ficheros/tratamientos_aux.txt","./ficheros/tratamientos.txt");
}
