#include "funciones.h"
#include "historial.h"
#include <iostream>
#include <ctime>
#include <string>
#include <list>
//#include <stdio.h>
#include <fstream>
//#include <stdlib.h>

using namespace std;


History::History(string fullname, string description, string date)
{
  fullname_=fullname;
  description_=description;
  date_=date;
}

void History::add_history_entry()
{
  ofstream fs("historial.txt", ios::app);
  fs<<normalize(fullname_)<<";"<<normalize(description_)<<";"<<date_;
  //no acaba en /n porque ya lo pone date_

  fs.close();
}



void History::show_history(list <History> entries)
{
  list<History>::iterator i;
  for(i=entries.begin(); i != entries.end(); ++i)
  {
    cout<<"\nFecha: "<<i->getDate()<<endl;
    cout<<"Descripción: "<<i->getDescription()<<endl<<endl;
  }
}
