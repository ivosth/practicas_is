#ifndef HISTORIAL_H
#define HISTORIAL_H
#include <string>
using namespace std;

class History
{
  private:
    string fullname_;
    string description_;
    string date_;

  public:
    History(string fullname, string description, string date);
    void add_history_entry();
    void show_history();
};



#endif
