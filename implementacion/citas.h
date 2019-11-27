#ifndef CITAS_H
#define CITAS_H
#include <iostream>
#include <locale>
#include <stdio.h>
#include <iomanip>
#include <ctime>
#include <string>
using namespace std;

class Date
{
  private:
    string fullname_;
    string start_;
    string end_;
    string description_;
  public:
    Date(string fullname, string start="", string end="", string description="");
    void add_date();
    void update_date(int n);
    void delete_date_menu();
};

string normalize(string chain);
void add_date_menu();
void update_date_menu();
void delete_date_menu();
#endif
