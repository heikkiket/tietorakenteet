#include <iostream>
#include <exception>

#include "HashTable.h"

HashTable::HashTable() {}

HashTable::~HashTable() {}

bool HashTable::isEmpty()
{
  return size == 0;
}

int HashTable::hashStr(string str)
{
  int ret {};
  int i = 1;
  for(auto tok : str) {
    ret += tok * i;
    i++;
  }

  return ret;
}

int HashTable::hashCode(string str)
{
  return hashCode(str, 0);
}

int HashTable::hashCode(string str, int times) {
  return hashStr(str) % maxSize + times;
}

void HashTable::add(string key)
{
  if(key == "")
    throw "empty key not allowed";

  if(search(key))
    throw "duplicate key";

  if(isFull())
    throw "table full";

  int times = 0;
  while(elements[hashCode(key, times)] != "") {
    times++;
  }

  size++;
  elements[hashCode(key, times)] = key;
}

bool HashTable::search(string key)
{
  if(isEmpty())
    return false;

  int times = 0;
  int index = hashCode(key, times);
  while ((elements[index]) != ""){
    if(elements[index] == key)
      break;
    times++;
    index = hashCode(key, times);
  }
  return elements[index] == key;
}

void HashTable::debugPrintTable()
{
  int i = 0;
  for(auto el : elements) {
    if(el != "")
      std::cout << "elements[" << i << "]: " << el << "\n";

    i++;
  }
}

bool HashTable::isFull()
{
  return size == maxSize;
}
