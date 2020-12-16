#include <iostream>

#include "HashTable.h"

int main()
{
  HashTable test {};
  test.add("test");
  test.add("asd");
  test.add("123");
  test.add("456");
  test.add("joulupukki");
  test.add("tonttu");
  test.add("poro");
  test.add("glögi");
  test.add("Kolmen sanan avain");
  test.debugPrintTable();

  try{ test.add("test"); }
  catch (const char *msg) {
    cout << "Got exception:" << msg << "\n";
  }

  try {
    for (int i = 0; i < 32; i++) {
      test.add(to_string(i));
    }
  } catch (const char *msg) {
    cout << "Got exception:" << msg << "\n";
  }

  return 0;
}
