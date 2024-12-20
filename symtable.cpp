#include "symtable.h"

SymTable::SymTable() : prev(nullptr)
{
}

SymTable::SymTable(SymTable *t) : prev(t)
{
}

bool SymTable::Insert(string &name, Symblo &symbol)
{
  const auto &[it, success] = table.insert({name, symbol});
  return success;
}

Symblo *SymTable::Find(const string name)
{
  for (SymTable *st = this; st != nullptr; st = st->prev)
  {
    auto found = st->table.find(name);
    if (found != st->table.end())
    {
      return &found->second;
    }
  }

  return nullptr;
}