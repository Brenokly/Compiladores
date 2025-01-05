#include <unordered_map>
#include <string>
using std::string;
using std::unordered_map;

struct Symblo
{
  string type;
  string value;
};

class SymTable
{
private:
  unordered_map<string, Symblo> table;
  SymTable * prev;

public:
  SymTable();
  SymTable(SymTable * t);

  bool Insert(string & name, Symblo & symbol);
  Symblo *Find(const string name);
  bool exists(const string name);
};