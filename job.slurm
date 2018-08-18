#!/bin/bash

#SBATCH --nodes=1
#SBATCH --ntasks=8
#SBATCH --time=0-00:5:00

module load GCC/8.1.0

gcc -fopenmp fw_in.cpp -o our_program

./our_program randograph-5000.txt
