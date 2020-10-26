#include <iostream>
#include "Queue.h"

int main()
{
  Queue q = Queue();
  q.enqueue("Keskiviikko");
  q.enqueue("on");
  q.enqueue("tänään");
  q.printQueue();

  std::cout << "Poistetaan kaksi alkiota:\n";
  std::string str;
  str = q.dequeue();
  std::cout << "Poistettu: " << str << std::endl;
  str = q.dequeue();
  std::cout << "Poistettu: " << str << std::endl;

  std::cout << "Suoritetaan automaattisesti jonon destruktori\n";
  return 0;
}
