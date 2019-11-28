#ifndef HISTORIAL_H
#define HISTORIAL_H
#include <string>
#include <list>
using namespace std;

class History
{
  private:
    string fullname_;
    string description_;
    string date_;

  public:
    History(string fullname, string description, string date);
    inline string getDate() const {return date_;}
    inline string getDescription() const {return description_;}
    void add_history_entry();
    void show_history(list <History> v);
};



#endif
