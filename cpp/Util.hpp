#ifndef UTIL_HPP
#define UTIL_HPP

#include <array>
#include <memory>
#include <random>
// normally I use C style but want to make this "cpp style"
//  https://www.learncpp.com/cpp-tutorial/multidimensional-stdarray/
//  An alias template for a two-dimensional std::array
template <typename T, std::size_t Row, std::size_t Col>
using matrix = std::array<std::array<T, Col>, Row>;

template <typename T, std::size_t Row, std::size_t Col>
void fillMat(matrix<T, Row, Col> &arr) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<T> distrib(1.0, 99.9);
    for (auto& row : arr) 
    {
      for (auto& elem : row) 
      {
            elem = distrib(gen);
      }
    }
}

#endif
