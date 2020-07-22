#include "Table.hpp"

TTable::TTable(const std::string& _name = "") : TObject(_name) {
  properties.insert(
      {std::string("Coordinate"),
       new TProperties(
           std::map<std::string, double>{{"X", 0}, {"Y", 0}, {"Z", 0}}, false,
           "Coordinate")});
  properties.insert({std::string("Dimensions"),
                     new TProperties(
                         std::map<std::string, double>{
                             {"Width", 1}, {"Length", 1}, {"Height", 1}},
                         false, "Dimensions")});
}