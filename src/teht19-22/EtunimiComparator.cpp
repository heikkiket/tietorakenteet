#include "matkakortti.h"

class EtuNimiJaSaldoComparator {
public:
  bool operator()(const Matkakortti &kortti1, const Matkakortti &kortti2) {
    if (kortti1.saldo == kortti2.saldo)
      return kortti1.etunimi < kortti2.etunimi;
    return kortti1.saldo < kortti2.saldo;
  }
};
