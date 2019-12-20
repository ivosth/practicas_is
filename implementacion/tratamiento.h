#ifndef TRATAMIENTO_H
#define TRATAMIENTO_H

#include <string>
#include <list>

using namespace std;

class Treatment{
private:
  string fullname_;
  string start_;
  string end_;
  string regularity_;
  string concentration_;
  string dose_;
public:
  Treatment(string fullname, string start="", string end="", string regularity="", string concentration="", string dose="");
  inline string getStart() const {return start_;};
  inline string getEnd() const {return end_;};
  inline string getRegularity() const {return regularity_;};
  inline string getConcentration() const {return concentration_;};
  inline string getDose() const {return dose_;};
  void add_treatment();
  void show_treatment(list<Treatment> t);
  void modify_treatment(int);




};



#endif
