#include "paciente.h"
#include "funciones.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

Patient::Patient(string fullname, string address, string phone, string birthday, string insurance)
{
  fullname_=fullname;
  address_=address;
  phone_=phone;
  birthday_=birthday;
  insurance_=insurance;
}



void Patient::add_patient()
{
  ofstream fs("./ficheros/pacientes.txt", ios::app);

  fs<<normalize(fullname_)<<";"<<normalize(address_)<<";"<<phone_<<";"<<birthday_<<";"<<normalize(insurance_)<<"\n";

  fs.close();

}



void Patient::change_patient(string fullname_old)
{
  ifstream fe("./ficheros/pacientes.txt");
  ofstream fs("./ficheros/pacientes_aux.txt");

  string fullname_aux, address_aux, phone_aux, birthday_aux, insurance_aux, linea;
  //Read the file until there is no lines
  while(getline(fe, linea, ';'))
  {
    fullname_aux=linea;
    getline(fe, linea, ';');
    address_aux=linea;
    getline(fe, linea, ';');
    phone_aux=linea;
    getline(fe, linea, ';');
    birthday_aux=linea;
    getline(fe, linea, '\n');
    insurance_aux=linea;

    if(normalize(fullname_old)!=fullname_aux)
      fs<<fullname_aux<<";"<<address_aux<<";"<<phone_aux<<";"<<birthday_aux<<";"<<insurance_aux<<"\n";
    else
      fs<<fullname_<<";"<<address_<<";"<<phone_<<";"<<birthday_<<";"<<insurance_<<"\n";

  }

  fs.close();
  fe.close();
  remove("./ficheros/pacientes.txt");
  rename("./ficheros/pacientes_aux.txt", "./ficheros/pacientes.txt");
}


bool Patient::delete_patient()
{
  //Eliminando de ./ficheros/pacientes.txt
  ifstream fe("./ficheros/pacientes.txt");
  ofstream fs("./ficheros/pacientes_aux.txt");

  string fullname_aux, address_aux, phone_aux, birthday_aux, insurance_aux, linea;
  //Read the file until there is no lines
  while(getline(fe, linea, ';'))
  {
    fullname_aux=linea;
    getline(fe, linea, ';');
    address_aux=linea;
    getline(fe, linea, ';');
    phone_aux=linea;
    getline(fe, linea, ';');
    birthday_aux=linea;
    getline(fe, linea, '\n');
    insurance_aux=linea;

    if(normalize(fullname_)!=fullname_aux)
      fs<<fullname_aux<<";"<<address_aux<<";"<<phone_aux<<";"<<birthday_aux<<";"<<insurance_aux<<"\n";

  }

  fs.close();
  fe.close();
  remove("./ficheros/pacientes.txt");
  rename("./ficheros/pacientes_aux.txt", "./ficheros/pacientes.txt");


  //Eliminando de citas.txt
  ifstream inc("./ficheros/citas.txt");
  ofstream fsc("./ficheros/citasaux.txt");
  string cadaux;

  while(getline(inc,cadaux,';')){
    if (normalize(fullname_)!=cadaux){
      fsc<<cadaux<<";";
      getline(inc,cadaux,'\n');
      fsc<<cadaux<<"\n";
    }
    else
      getline(inc,cadaux,'\n');

  }
  inc.close();
  fsc.close();
  remove("./ficheros/citas.txt");
  rename("./ficheros/citasaux.txt","./ficheros/citas.txt");


  //Eliminando de historial.txt
  ifstream inh("./ficheros/historial.txt");
  ofstream fsh("./ficheros/historialaux.txt");

  while(getline(inh,cadaux,';')){
    if (normalize(fullname_)!=cadaux){
      fsh<<cadaux<<";";
      getline(inh,cadaux,'\n');
      fsh<<cadaux<<"\n";
    }
    else
      getline(inh,cadaux,'\n');

  }
  inh.close();
  fsh.close();
  remove("./ficheros/historial.txt");
  rename("./ficheros/historialaux.txt","./ficheros/historial.txt");



  //Eliminando de tratamiento.txt
  ifstream fet("./ficheros/tratamientos.txt");
  ofstream fst("./ficheros/tratamientosaux.txt");

  while(getline(fet,cadaux,';')){
    if (normalize(fullname_)!=cadaux){
      fst<<cadaux<<";";
      getline(fet,cadaux,'\n');
      fst<<cadaux<<"\n";
    }
    else
      getline(fet,cadaux,'\n');

  }

  fet.close();
  fst.close();
  remove("./ficheros/tratamientos.txt");
  rename("./ficheros/tratamientosaux.txt","./ficheros/tratamientos.txt");



  return true;
}




void Patient::show_patient()
{
  cout<<"\nNombre: "<<fullname_<<endl;
  cout<<"Dirección: "<<address_<<endl;
  cout<<"Número de teléfono: "<<phone_<<endl;
  cout<<"Fecha de nacimiento: "<<birthday_<<endl;
  cout<<"Seguro: "<<insurance_<<endl<<endl;
}
