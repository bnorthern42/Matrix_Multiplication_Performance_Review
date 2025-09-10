#include <iostream>
#include <omp.h>
#include <iomanip>
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

    // get times to max threads on machine, mine has 8C/16T *(AMD 3700X)  
    for(int THREADS = 1; THREADS <= omp_get_max_threads(); ++THREADS)
    {
			double startTime = omp_get_wtime();
			#pragma omp parallel for shared(max,  mbx, mcx) schedule(static) num_threads(THREADS)
			for (size_t i = 0; i < (*max).size(); ++i) {        // Loop over rows of A
					for (size_t j = 0; j < (*mbx)[0].size(); ++j) {    // Loop over columns of B
							for (size_t k = 0; k < (*max)[0].size(); ++k) { // Dot product calculation
									(*mcx)[i][j] += (*max)[i][k] * (*mbx)[k][j];
							}
					}
			}
			double time = omp_get_wtime() - startTime;
			std::cout.precision(5);
			std::cout << "Took: " << std::fixed <<  time << " with Cores: " << THREADS << std::endl; 
    }
//idc about result just time
    std::cout << "DONE" << std::endl;
    return 0;
}
