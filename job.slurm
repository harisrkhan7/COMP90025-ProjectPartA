#!/bin/bash

#SBATCH --nodes=1
#SBATCH --ntasks=32
#SBATCH --time=0-00:5:00

module load GCC/8.1.0

gcc -fopenmp fw_in.cpp -o our_program

./our_program randograph-750.txt 2
./our_program randograph-750.txt 4
./our_program randograph-750.txt 8
./our_program randograph-750.txt 16
./our_program randograph-750.txt 32

./our_program randograph-1000.txt 2
./our_program randograph-1000.txt 4
./our_program randograph-1000.txt 8
./our_program randograph-1000.txt 16
./our_program randograph-1000.txt 32

./our_program randograph-1250.txt 2
./our_program randograph-1250.txt 4
./our_program randograph-1250.txt 8
./our_program randograph-1250.txt 16
./our_program randograph-1250.txt 32

./our_program randograph-1500.txt 2
./our_program randograph-1500.txt 4
./our_program randograph-1500.txt 8
./our_program randograph-1500.txt 16
./our_program randograph-1500.txt 32

./our_program randograph-1000.txt 2
./our_program randograph-1000.txt 4
./our_program randograph-1000.txt 8
./our_program randograph-1000.txt 16
./our_program randograph-1000.txt 32

./our_program randograph-2000.txt 2
./our_program randograph-2000.txt 4
./our_program randograph-2000.txt 8
./our_program randograph-2000.txt 16
./our_program randograph-2000.txt 32

./our_program randograph-3000.txt 2
./our_program randograph-3000.txt 4
./our_program randograph-3000.txt 8
./our_program randograph-3000.txt 16
./our_program randograph-3000.txt 32

./our_program randograph-5000.txt 2
./our_program randograph-5000.txt 4
./our_program randograph-5000.txt 8
./our_program randograph-5000.txt 16
./our_program randograph-5000.txt 32
