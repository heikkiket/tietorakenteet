#include <iostream>
#include <math.h>
#include "SortedArray.h"

SortedArray::SortedArray() {}

SortedArray::~SortedArray() {}

void SortedArray::add(string str)
{
  if(size == MAX_SIZE) {
    cout << "Array full!";
    return;
  }

  pos = 0;
  while(pos < size && binlist[pos] < str) {
    pos++;
  }

  string tmp = binlist[pos];

  for(int i = size; i > pos+1; i--) {
    binlist[i] = binlist[i-1];
  }

  binlist[pos] = str;
  binlist[++pos] = tmp;

  size++;
}

void SortedArray::printContents()
{
  for(int i = 0; i < size; i++) {
    cout << binlist[i] <<", ";
  }
}

int SortedArray::search(string key)
{
  return search(key, 0, size-1);
}

int SortedArray::search(string key, int min, int max)
{
  int index = floor((max + min) / 2);
  string word = binlist[index];
  if(min > max) {
    return -1;
  } else if(key < word) {
    return search(key, min, index-1);
  } else if(key > word) {
    return search(key, index+1, max);
 } else {
   return index;
 }
}
