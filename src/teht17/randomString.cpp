#include <string>
#include <random>

std::minstd_rand0 generator(1);

std::string random_string(std::size_t length) {
  // const std::string CHARACTERS =
  //     "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

  // std::random_device random_device;
  // std::mt19937 generator(random_device());
  // std::uniform_int_distribution<> distribution(0, CHARACTERS.size() - 1);

  // std::string random_string;

  // for (std::size_t i = 0; i < length; ++i) {
  //   random_string += CHARACTERS[distribution(generator)];
  // }


  int rand = generator() % SIZE;

  return std::to_string(rand);
}
