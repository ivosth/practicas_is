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



void Patient::add_pacient()
{
  ofstream fs("pacientes.txt", ios::app);

  fs<<normalize(fullname_)<<","<<normalize(address_)<<","<<phone_<<","<<birthday_<<","<<normalize(insurance_)<<"\n";

  fs.close();

}
