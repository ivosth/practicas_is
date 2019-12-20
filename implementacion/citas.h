#ifndef CITAS_H
#define CITAS_H

#include <string>
using namespace std;

class Date
{
  private:
    string fullname_;
    string date_;
    string start_;
    string end_;
    string description_;
  public:
    Date(string fullname, string date="", string start="", string end="", string description="");
    void add_date();
    void update_date(int n);
    bool todays_dates(string date);   
    void delete_date(int n);
    void show_dates();
};



#endif
