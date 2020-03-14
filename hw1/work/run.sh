#!/bin/bash

g++ hw01.cpp VEC.cpp MAT.cpp -o hw01
# rm time.txt

echo $'-----------------\nAlgo 1 < m3.dat'
time ./hw01 1 < m3.dat
echo $'-----------------\nAlgo 1 < m4.dat'
time ./hw01 1 < m4.dat
echo $'-----------------\nAlgo 1 < m5.dat'
time ./hw01 1 < m5.dat
echo $'-----------------\nAlgo 1 < m6.dat'
time ./hw01 1 < m6.dat
echo $'-----------------\nAlgo 1 < m7.dat'
time ./hw01 1 < m7.dat
echo $'-----------------\nAlgo 1 < m8.dat'
time ./hw01 1 < m8.dat
echo $'-----------------\nAlgo 1 < m9.dat'
time ./hw01 1 < m9.dat

echo $'-----------------\nAlgo 2 < m3.dat'
time ./hw01 2 < m3.dat
echo $'-----------------\nAlgo 2 < m4.dat'
time ./hw01 2 < m4.dat
echo $'-----------------\nAlgo 2 < m5.dat'
time ./hw01 2 < m5.dat
echo $'-----------------\nAlgo 2 < m6.dat'
time ./hw01 2 < m6.dat
echo $'-----------------\nAlgo 2 < m7.dat'
time ./hw01 2 < m7.dat
echo $'-----------------\nAlgo 2 < m8.dat'
time ./hw01 2 < m8.dat
echo $'-----------------\nAlgo 2 < m9.dat'
time ./hw01 2 < m9.dat

echo $'-----------------\nAlgo 3 < m3.dat'
time ./hw01 3 < m3.dat
echo $'-----------------\nAlgo 3 < m4.dat'
time ./hw01 3 < m4.dat
echo $'-----------------\nAlgo 3 < m5.dat'
time ./hw01 3 < m5.dat
echo $'-----------------\nAlgo 3 < m6.dat'
time ./hw01 3 < m6.dat
echo $'-----------------\nAlgo 3 < m7.dat'
time ./hw01 3 < m7.dat
echo $'-----------------\nAlgo 3 < m8.dat'
time ./hw01 3 < m8.dat
echo $'-----------------\nAlgo 3 < m9.dat'
time ./hw01 3 < m9.dat

echo $'-----------------\nAlgo 4 < m3.dat'
time ./hw01 4 < m3.dat
echo $'-----------------\nAlgo 4 < m4.dat'
time ./hw01 4 < m4.dat
echo $'-----------------\nAlgo 4 < m5.dat'
time ./hw01 4 < m5.dat
echo $'-----------------\nAlgo 4 < m6.dat'
time ./hw01 4 < m6.dat
echo $'-----------------\nAlgo 4 < m7.dat'
time ./hw01 4 < m7.dat
echo $'-----------------\nAlgo 4 < m8.dat'
time ./hw01 4 < m8.dat
echo $'-----------------\nAlgo 4 < m9.dat'
time ./hw01 4 < m9.dat