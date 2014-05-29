#!/bin/sh

cd modules/source/Asylia_$1/
make clean && make
cd ../../../

