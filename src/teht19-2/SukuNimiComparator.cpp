#include "matkakortti.h"

class SukuNimiComparator
{
public:
  bool operator ()(const Matkakortti &kortti1, const Matkakortti &kortti2){
    if(kortti1.sukunimi == kortti2.sukunimi)
      return kortti1 < kortti2;
    return kortti1.sukunimi < kortti2.sukunimi;
  }
};

