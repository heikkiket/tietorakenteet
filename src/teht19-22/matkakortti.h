#ifndef MATKAKORTTI_H
#define MATKAKORTTI_H

#include <string>

#include "matkalippu.h"

class Matkakortti
{

private:
  int matkustajanumero;
  bool veloitaLippu(Matkalippu lippu);

public:
  Matkakortti(std::string etunimi, std::string sukunimi);
  void matkusta(Matkalippu lippu);
  void vaihdaNimi(std::string etunimi, std::string sukunimi);
  void lataaSaldoa(float saldo);
  void tulostaKortinTiedot();
  float saldo;
  std::string etunimi;
  std::string sukunimi;
  static int matkustajaNumeroIndex;

  friend bool operator<(const Matkakortti &kortti1,
                         const Matkakortti &kortti2);
  friend bool operator>(const Matkakortti &kortti1,
                         const Matkakortti &kortti2);
};

#endif

