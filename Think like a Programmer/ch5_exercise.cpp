#include <iostream>
#include <string>
using namespace std;

class Automobile {
  string _manufacturer;
  string _model;
  int _model_year;

public:
  Automobile(string manu, string model, int model_year)
      : _manufacturer(manu), _model(model), _model_year(model_year) {
    ;
  }
  string manufacturer() { return _manufacturer; }
  void setManufacturer(string input) { _manufacturer = input; };
  string model() { return _model; }
  void setModel(string input) { _model = input; };
  int model_year() { return _model_year; }
  void setModelYear(int input) { _model_year = input; };
  void info() {
    cout << to_string(age()) + " " + manufacturer() + " " + model()
         << "\n";
  }
  int age();
};

int Automobile::age() {
#include <ctime>
  time_t timestamp;
  time(&timestamp);

  // Convert the timestamp to a tm structure
  struct tm *timeinfo = localtime(&timestamp);
  // (tm_year is the number of years since 1900, so we add 1900)
  return (1900 + timeinfo->tm_year) - _model_year;
}

int main() {
  Automobile v("volvo", "xfgt", 2024);
  v.info();
  return 0;
}