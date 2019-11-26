#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <string>
using namespace std;

string normalize(string chain);
bool find_patient(string fullname);
bool add_patient_menu();
bool change_patient_menu();
bool delete_patient_menu();
bool show_patient_menu();
bool add_history_entry_menu();

#endif
