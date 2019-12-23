#include "paciente_menu.h"
#include "funciones.h"
#include "paciente.h"
#include <iostream>
#include <ctime>
#include <string>
#include <fstream>


bool add_patient_menu()
{
  //setlocale(LC_ALL, "");
  string fullname, address, phone, birthday, insurance;
  time_t now = time(0);
  tm ltm= *localtime(&now); //www.tutorialspoint.com/cplusplus/cpp_date_time.htm
  int current_year=1900 + ltm.tm_year;

  cout<<"Introduce el nombre completo"<<endl;
  getline(cin, fullname);

  if(find_patient(normalize(fullname))==true)
  {
    cout<<"El paciente con el nombre "<<fullname<<" ya se encuentra registrado"<<endl;
    cout<<"No se puede haber dos pacientes con el mismo nombre"<<endl;
    return false;
  }

  cout<<"Introduce la dirección"<<endl;
  getline(cin, address);

  cout<<"Introduce el numero de telefono"<<endl;
  cin>>phone;

  cout<<"Introduce la fecha de nacimiento"<<endl;
  cin>>birthday;

  if((birthday[2]!='/') || (birthday[5]!='/') || (stoi(birthday.substr(6,4))>current_year) || (stoi(birthday.substr(0,2))>=32) || (stoi(birthday.substr(3,2))>=13)  || (birthday.size()!=10))
  {
    cout<<"Error en la fecha. Ejemplo: 04/06/2000"<<endl;
    return false;
  }

  cout<<"Introduce el seguro"<<endl;
  cin>>insurance;

  if((normalize(insurance)!="PARTICULAR") && (normalize(insurance)!="MUTUA"))
  {
    cout<<"Error en el seguro, particular/mutua"<<endl;
    return false;
  }


  Patient p(fullname, address, phone, birthday, insurance);
  p.add_patient();
  return true;
}





bool change_patient_menu()
{
  time_t now = time(0);
  tm ltm= *localtime(&now); //www.tutorialspoint.com/cplusplus/cpp_date_time.htm
  int current_year=1900 + ltm.tm_year;

  string fullname, fullname_aux, fullname_old, address_aux, phone_aux, birthday_aux, insurance_aux, linea;
  cout<<"Introduzca el nombre del paciente a modificar"<<endl;
  getline(cin, fullname);

  //comprobación del paciente
  if(find_patient(normalize(fullname))==false)
  {
    cout<<"El paciente con el nombre "<<fullname<<" no se encuentra registrado"<<endl;
    return false;
  }

  //El sistema muestra los datos personales de ese paciente
  ifstream fe("./ficheros/pacientes.txt");
  bool aux=true;

  while(getline(fe, linea, ';') && (aux==true))
  {
    fullname_aux=linea;
    if(normalize(fullname)==fullname_aux)
    {
      getline(fe, linea, ';');
      address_aux=linea;
      getline(fe, linea, ';');
      phone_aux=linea;
      getline(fe, linea, ';');
      birthday_aux=linea;
      getline(fe, linea, '\n');
      insurance_aux=linea;

      cout<<"\nNombre: "<<fullname_aux<<endl;
      cout<<"Dirección: "<<address_aux<<endl;
      cout<<"Número de teléfono: "<<phone_aux<<endl;
      cout<<"Fecha de nacimiento: "<<birthday_aux<<endl;
      cout<<"Seguro: "<<insurance_aux<<endl<<endl;

      fullname_old=fullname_aux;  //fullname_old es para el caso de cambiar de nombre


      aux=false;
    }
    else
      getline(fe, linea, '\n');

  }

  //Submenu para escoger el campo que se modifica
  cout<<"Introduzca que desea modificar"<<endl;
  cout<<"1.Nombre"<<endl;
  cout<<"2.Dirección"<<endl;
  cout<<"3.Número de teléfono"<<endl;
  cout<<"4.Fecha de nacimiento"<<endl;
  cout<<"5.Seguro"<<endl;

  int option;
  cin>>option;
  switch (option)
  {
    case 1:
    {
      cout<<"Introduce el nuevo nombre"<<endl;
      getline(cin, fullname_aux); //para quitar el /n que esta en el buffer
      getline(cin, fullname_aux);
      if(find_patient(normalize(fullname_aux))==true)
      {
        cout<<"El paciente con el nombre "<<fullname_aux<<" ya se encuentra registrado"<<endl;
        cout<<"No se puede haber dos pacientes con el mismo nombre"<<endl;
        return false;
      }
    }break;

    case 2:
    {
      cout<<"Introduce la nueva dirección"<<endl;
      getline(cin, address_aux);  //para quitar el /n que esta en el buffer
      getline(cin, address_aux);
    }break;

    case 3:
    {
      cout<<"Introduce el nuevo número de teléfono"<<endl;
      cin>>phone_aux;
    }break;

    case 4:
    {
      cout<<"Introduce la nueva fecha de nacimiento"<<endl;
      cin>>birthday_aux;

      if((birthday_aux[2]!='/') || (birthday_aux[5]!='/') || (stoi(birthday_aux.substr(6,4))>current_year) || (stoi(birthday_aux.substr(0,2))>=32) || (stoi(birthday_aux.substr(3,2))>=13)  || (birthday_aux.size()!=10))
      {
        cout<<"Error en la fecha. Ejemplo: 04/06/2000"<<endl;
        //cout<<"stoi(birthday.substr(6,4)) = "<<stoi(birthday.substr(6,4))<<endl;
        //cout<<"(stoi(birthday.substr(0,2)) = "<<stoi(birthday.substr(0,2))<<endl;
        //cout<<"(stoi(birthday.substr(3,2)) = "<<stoi(birthday.substr(3,2))<<endl;
        //cout<<"current_year = "<<current_year<<endl;
        //cout<<"birthday[2] = "<<birthday[2]<<endl;
        //cout<<"birthday[5] = "<<birthday[5]<<endl;

        return false;
      }
    }break;

    case 5:
    {
      cout<<"Introduce el nuevo tipo de seguro"<<endl;
      cin>>insurance_aux;
      if((normalize(insurance_aux)!="PARTICULAR") && (normalize(insurance_aux)!="MUTUA"))
      {
        cout<<"Error en el seguro, particular/mutua"<<endl;
        return false;
      }
    }break;
  }

  Patient p(normalize(fullname_aux), normalize(address_aux), normalize(phone_aux), normalize(birthday_aux), normalize(insurance_aux));
  p.change_patient(fullname_old);
  return true;
}



bool delete_patient_menu()
{
  string option, fullname;

  cout<<"Introduzca el nombre del paciente a eliminar"<<endl;
  getline(cin, fullname);

  //comprobación del paciente
  if(find_patient(normalize(fullname))==false)
  {
    cout<<"El paciente con el nombre "<<fullname<<" no se encuentra registrado"<<endl;
    return false;
  }

  string fullname_aux, address_aux, phone_aux, birthday_aux, insurance_aux, linea;
  ifstream fe("./ficheros/pacientes.txt");

  bool aux=true;
  while(getline(fe, linea, ';') && (aux==true))
  {
    fullname_aux=linea;
    if(normalize(fullname)==fullname_aux)
    {
      getline(fe, linea, ';');
      address_aux=linea;
      getline(fe, linea, ';');
      phone_aux=linea;
      getline(fe, linea, ';');
      birthday_aux=linea;
      getline(fe, linea, '\n');
      insurance_aux=linea;

      cout<<"\nNombre: "<<fullname_aux<<endl;
      cout<<"Dirección: "<<address_aux<<endl;
      cout<<"Número de teléfono: "<<phone_aux<<endl;
      cout<<"Fecha de nacimiento: "<<birthday_aux<<endl;
      cout<<"Seguro: "<<insurance_aux<<endl<<endl;

      aux=false;
    }
    else
      getline(fe, linea, '\n');

  }

  fe.close();

  cout<<"¿Está seguro de que desea borrarlo? Se borrarán todos los registros asociados a él (s/n)"<<endl;
  cin>>option;

  if(normalize(option)=="S")
  {
      Patient p(normalize(fullname_aux), normalize(address_aux), normalize(phone_aux), normalize(birthday_aux), normalize(insurance_aux));
      if(p.delete_patient()==false)
        return false;
      else
        return true;

  }

  else
  {
    if(normalize(option)=="N")
      return false;

    else
    {
      cout<<"No se ha introducido ninguna de las opciones"<<endl;
      return false;
    }
  }
  fe.close();
  return false;
}


bool show_patient_menu()
{
  string fullname;
  cout<<"Introduzca el nombre del paciente a consultar sus datos personales"<<endl;
  getline(cin, fullname);

  if(find_patient(normalize(fullname))==false)
  {
    cout<<"El paciente con el nombre "<<fullname<<" no se encuentra registrado"<<endl;
    return false;
  }

  string fullname_aux, address_aux, phone_aux, birthday_aux, insurance_aux, linea;
  ifstream fe("./ficheros/pacientes.txt");

  bool aux=true;
  while(getline(fe, linea, ';') && (aux==true))
  {
    fullname_aux=linea;
    if(normalize(fullname)==fullname_aux)
    {
      getline(fe, linea, ';');
      address_aux=linea;
      getline(fe, linea, ';');
      phone_aux=linea;
      getline(fe, linea, ';');
      birthday_aux=linea;
      getline(fe, linea, '\n');
      insurance_aux=linea;

      Patient p(fullname_aux, address_aux,phone_aux, birthday_aux, insurance_aux);
      p.show_patient();
      aux=false;
    }
    else
      getline(fe, linea, '\n');

  }

  fe.close();
  return true;
}
