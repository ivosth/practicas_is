#include "funciones.h"
#include "paciente.h"
#include <iostream>
#include <ctime>
#include <string>
#include <locale>
#include <stdio.h>
#include <iomanip>
#include <fstream>

using namespace std;


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


bool find_pacient(string fullname)
{

    ifstream in("pacientes.txt");
    string cadaux;
    while(getline(in,cadaux,',')){
      if (fullname==cadaux)
      {
        in.close();
        return true;
      }
      else{getline(in,cadaux,'\n');}
    }
    in.close();
    return false;

    exit(-1);

  }


bool add_paciente_menu()
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
    return false;
  }

  cout<<"Introduce el seguro"<<endl;
  cin>>insurance;
  for(int unsigned i=0; i<insurance.size(); i++)
  {
    if((toupper(insurance[i])!=type1_insurance[i]) && (toupper(insurance[i])!=type2_insurance[i]))
    {
      cout<<"Error en el seguro, particular/mutua"<<endl;
      return false;
    }
  }

  Patient p(fullname, address, phone, birthday, insurance);
  p.add_pacient();
  return true;
}
