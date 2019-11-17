#include "paciente.h"
#include <iostream>
#include <locale>
#include <stdio.h>
#include <iomanip>
#include <ctime>
#include <string>
using namespace std;

int main(void)
{
  setlocale(LC_ALL, "");
  string fullname, address, phone, birthday, insurance;

  auto t = time(nullptr);
  auto tm = *localtime(&t);
  int current_year=1900 + tm.tm_year;

  string type1_insurance="PARTICULAR";
  string type2_insurance="MUTUA";

  cout<<"Introduce el nombre completo"<<endl;
  getline(cin, fullname);

  cout<<"Introduce la dirección"<<endl;
  getline(cin, address);

  cout<<"Introduce el numero de telefono"<<endl;
  cin>>phone;

  cout<<"Introduce la fecha de nacimiento"<<endl;
  cin>>birthday;

  if((birthday[2]!='/') && (birthday[5]!='/') && (birthday[8]!='/') && (stoi(birthday.substr(6,4))<=current_year))
  {
    cout<<"Error en la fecha. Ejemplo: 04/06/2000"<<endl;
    return 0;
  }

  cout<<"Introduce el seguro"<<endl;
  cin>>insurance;
  for(int unsigned i=0; i<insurance.size(); i++)
  {
    if((toupper(insurance[i])!=type1_insurance[i]) && (toupper(insurance[i])!=type2_insurance[i]))
    {
      cout<<"Error en el seguro, particular/mutua"<<endl;
      return 0;
    }
  }

  Patient p(fullname, address, phone, birthday, insurance);
  p.add_pacient();

  //char cad[50]="Rafael Mancha DiéguezñÑÁáÉéÍíÓóÚú";
  //string str="Rafael Mancha DiéguezñÑÁáÉéÍíÓóÚú";
/*
  for(int i=0; i<50; i++)
  {
    printf("%i = ", cad[i]);
    cout<<str[i]<<endl;
  }
  */


  return 0;
}
