#include "funciones.h"
#include <string>
#include <fstream>
#include <iostream>

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


bool find_patient(string fullname)
{

    ifstream in("pacientes.txt");
    string cadaux;
    while(getline(in,cadaux,';')){
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
