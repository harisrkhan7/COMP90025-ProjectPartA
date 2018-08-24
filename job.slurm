#!/bin/bash

#SBATCH --nodes=1
#SBATCH --ntasks=8
#SBATCH --time=0-02:00:00

module load GCC/8.1.0

rm -f our_program

gcc -fopenmp fw_in.cpp -o our_program

echo "Threads,Nodes,Time,Diameter,DYNAMIC"

for nodes in 5 10 20 50 100 200 500 750 1000 1250 1500 2000 3000 5000 7500 
do
for threads in 1 2 3 4 5 6 7 8 12 16 24 32 64 128 256 512 1024
do
./our_program randograph-${nodes}.txt ${threads}
done
done
