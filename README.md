# mpi-cuda-scatter-reproducer

git clone https://github.com/dganellari/mpi-cuda-scatter-reproducer.git

module swap PrgEnv-cray PrgEnv-gnu

module load cudatoolkit

salloc -N4 -Cgpu

export MPICH_RDMA_ENABLED_CUDA=1

srun -n4 ./scatter 

Description:

The issue only happens for cuda aware mpi  and only for certain confgurations as illustrated in the scatter.cpp file.
