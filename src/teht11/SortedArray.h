#ifndef SORTEDARRAY_H
#define SORTEDARRAY_H

#include <string>

using namespace std;

#define MAX_SIZE 1000

class SortedArray
{
private:
  int size = 0;
  int pos = 0;

  string binlist[MAX_SIZE];

  int search(string key, int min, int max);

public:
  SortedArray();
  virtual ~SortedArray();
  void add(string str);
  void printContents();
  int search(string key);
};


#endif /* SORTEDARRAY_H */
