#include <unordered_map>
#include <string>
using std::string;
using std::unordered_map;

struct Symblo
{
  string type;
};

class SymTable
{
private:
  unordered_map<string, Symblo> table;
  SymTable *prev;
  string className = "";

public:
  SymTable();
  SymTable(const string & name);
  SymTable(SymTable *t);

  bool Insert(string &name, Symblo &symbol);
  Symblo *Find(const string name);
  bool exists(const string name);

  const string &getClassName() { return className; }
  void setClassName(string &name) { className = name; }
};