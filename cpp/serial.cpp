#include <iostream>

#include "Util.hpp"


// An alias template for a two-dimensional std::array
template <typename T, std::size_t Row, std::size_t Col>
using Matrix = std::array<std::array<T, Col>, Row>;

int main(int argv, char** argc)
{

    auto max = std::make_unique<Matrix<double, 2000, 1000>>();
    auto mbx = std::make_unique<Matrix<double, 2000, 1000>>();
    auto mcx = std::make_unique<Matrix<double, 2000, 1000>>();
    fillMat(*max);
    fillMat(*mbx);
    std::cout <<"filled matrices" <<std::endl;
    //Serial Multiply

        // Perform the multiplication using three nested loops
    for (size_t i = 0; i < (*max).size(); ++i) {        // Loop over rows of A
        for (size_t j = 0; j < (*mbx)[0].size(); ++j) {    // Loop over columns of B
            for (size_t k = 0; k < (*max)[0].size(); ++k) { // Dot product calculation
                (*mcx)[i][j] += (*max)[i][k] * (*mbx)[k][j];
            }
        }
    }
//idc about result just time
    std::cout << "DONE" << std::endl;
    return 0;
}
