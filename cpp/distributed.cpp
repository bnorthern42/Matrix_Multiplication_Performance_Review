#include <iostream>
#include <mpi.h> // Include the MPI header
/*

Ok. listen up, ive done the 'breakage' several ways over the years
i'm going to show row based here just to show people a "general"
approach. Normally nowadays i do a cartesion communicator and split
up 2D arrays by quadrants... but it may be confusing for someone
new to the distributed world

*/
int main(int argc, char* argv[]) {
    // Initialize the MPI environment
    MPI_Init(&argc, &argv);

    // Get the number of processes
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Get the rank of the process
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // Get the name of the processor
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);

    // Print off a hello world message
    std::cout << "--- Running Distributed (OpenMPI) Version ---" << std::endl;
    std::cout << "Hello from processor " << processor_name 
              << ", rank " << world_rank 
              << " out of " << world_size << " processes." << std::endl;

    // Finalize the MPI environment.
    MPI_Finalize();

    return 0;
}
