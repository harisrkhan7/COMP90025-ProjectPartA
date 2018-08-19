#!/bin/bash

#SBATCH --nodes=1
#SBATCH --ntasks=8
#SBATCH --time=0-00:05:00

module load GCC/8.1.0

gcc -fopenmp fw_in.cpp -o our_program

for nodes in 5 10 20 100 200 500 750 1000 1250 1500 2000 3000 5000
do
for threads in 1 2 3 4 6 8 12 16 24 32
do
./our_program randograph-${nodes}.txt ${threads}
done
done
