#include <iostream>
#include <string>

using namespace std;

#include "matkakortti.h"

int main()
{
  Matkakortti kortti1 ("Heikki", "Ketoharju");
  Matkalippu sisainen_lippu(2.80);
  Matkalippu seutulippu(4.20);

  kortti1.tulostaKortinTiedot();

  Matkakortti kortti2("Herkko", "Kerkkonen");
  kortti2.tulostaKortinTiedot();


  if(kortti1 < kortti2)
    cout << "Herkon kortti on suurempi.\n";
  else
    cout << "Heikin kortti on suurempi.\n";

  return 0;
}
