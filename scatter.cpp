#include <limits>
#include <stdio.h>
#include <iostream>
#include <mpi.h>


void scatter(int* global, int* local, const int chunk_size, MPI_Comm comm)
{
    int rank;
    MPI_Comm_rank(comm, &rank);
    std::cout << "chunk_size mpi.h- :    " << chunk_size << "rank:" << rank <<std::endl;

    MPI_Scatter(global, chunk_size, MPI_INT, // send buffer
            local, chunk_size, MPI_INT,  // receive buffer
            0, comm);

}

int main(int argc, char* argv[]){

        MPI_Init(&argc, &argv);
        int size, rank;

        MPI_Comm_size(MPI_COMM_WORLD, &size);
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);

        printf("Size: %d, rank: %d\n", size, rank);

        int chunk_size = 1380000;
        int n__anchor_nodes = size*chunk_size;
        int * local; int * global;

        cudaMalloc(&local,chunk_size*sizeof(int));
        printf("local=%p\n", local);

        if(rank == 0){
            std::cout << "chunk_size - :    " << chunk_size << std::endl;
            std::cout << "n__anchor_nodes size:: - :    " <<n__anchor_nodes << std::endl;

            cudaMalloc(&global, n__anchor_nodes*sizeof(int));

            cudaMemset(global, 0, n__anchor_nodes*sizeof(int));
            printf("global=%p\n", global);
        }

        printf("scattering with -10000\n");
        scatter(global, local, chunk_size-10000, MPI_COMM_WORLD);
        printf("scattering with -5000\n");
        scatter(global, local, chunk_size-5000, MPI_COMM_WORLD);
        printf("scattering with -2500\n");
        scatter(global, local, chunk_size-2500, MPI_COMM_WORLD);
        printf("scattering with -1250\n");
        scatter(global, local, chunk_size-1250, MPI_COMM_WORLD);
        printf("scattering with -600\n");
        scatter(global, local, chunk_size-600, MPI_COMM_WORLD);
        printf("scattering with -300\n");
        scatter(global, local, chunk_size-300, MPI_COMM_WORLD);
        printf("scattering with -150\n");
        scatter(global, local, chunk_size-150, MPI_COMM_WORLD);
        printf("scattering with -80\n");
        scatter(global, local, chunk_size-80, MPI_COMM_WORLD);
        printf("scattering with -40\n");
        scatter(global, local, chunk_size-40, MPI_COMM_WORLD);
        printf("scattering with -20\n");
        scatter(global, local, chunk_size-20, MPI_COMM_WORLD);
        printf("scattering with -10\n");
        scatter(global, local, chunk_size-10, MPI_COMM_WORLD);



        MPI_Finalize();

    return 0;
}
