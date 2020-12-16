#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>

using namespace std;

class HashTable
{
private:
  string elements[1000];
  int size = 0;
public:
  HashTable();
  virtual ~HashTable();

  int maxSize = 31;

  bool isEmpty();
  bool isFull();
  int hashStr(string str);
  int hashCode(string str);
  int hashCode(string str, int times);

  void add(string key);
  bool search(string key);
  void debugPrintTable();
};


#endif /* HASHTABLE_H */
