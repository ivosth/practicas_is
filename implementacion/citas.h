#ifndef CITAS_H
#define CITAS_H

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
    //void delete_date_menu();
};



#endif
