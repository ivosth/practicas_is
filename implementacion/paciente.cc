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
  ofstream fs("pacientes.txt", ios::app);

  fs<<normalize(fullname_)<<","<<normalize(address_)<<","<<phone_<<","<<birthday_<<","<<normalize(insurance_)<<"\n";

  fs.close();

}



void Patient::change_patient(string fullname, string fullname_new, string address, string phone, string birthday, string insurance)
{
  ifstream fe("pacientes.txt");
  ofstream fs("pacientes_aux.txt");

  string fullname_aux, address_aux, phone_aux, birthday_aux, insurance_aux, linea;
  //Read the file until there is no lines
  while(getline(fe, linea, ','))
  {
    fullname_aux=linea;
    getline(fe, linea, ',');
    address_aux=linea;
    getline(fe, linea, ',');
    phone_aux=linea;
    getline(fe, linea, ',');
    birthday_aux=linea;
    getline(fe, linea, '\n');
    insurance_aux=linea;

    if(normalize(fullname)!=fullname_aux)
      fs<<fullname_aux<<","<<address_aux<<","<<phone_aux<<","<<birthday_aux<<","<<insurance_aux<<"\n";
    else
      fs<<normalize(fullname_new)<<","<<normalize(address)<<","<<phone<<","<<birthday<<","<<normalize(insurance)<<"\n";

  }

  fs.close();
  fe.close();
  remove("pacientes.txt");
  rename("pacientes_aux.txt", "pacientes.txt");
}
