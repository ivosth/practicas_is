#include "funciones.h"
#include <iostream>
#include <locale>
#include <stdio.h>
#include <iomanip>
#include <ctime>
#include <string>
using namespace std;

int main(void)
{
  //if(add_patient_menu()==false)
    //cout<<"Error"<<endl;

  if(change_patient_menu()==false)
    cout<<"Error"<<endl;

  string aux;
  getline(cin, aux);
  if(delete_patient_menu()==false)
    cout<<"El paciente no se ha eliminado"<<endl;


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
