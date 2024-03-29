#ifndef PACIENTE_H
#define PACIENTE_H
#include <string>
using namespace std;

class Patient
{
  private:
    string fullname_;
    string address_;
    string phone_;
    string birthday_;
    string insurance_;
  public:
    Patient(string fullname, string address="", string phone="", string birthday="", string insurance="");
    void add_patient();
    void change_patient(string fullname_old);
    bool delete_patient();
    void show_patient();
};



#endif
