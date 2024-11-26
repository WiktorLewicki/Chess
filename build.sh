#!/bin/bash
cd ~/Chess || exit 1
rm -rf ~/Chess/Makefile ~/Chess/*.o ~/Chess/*.pro.user ~/Chess/*.pro.*
/usr/bin/qmake ~/Chess/src/Szachy.pro -o Makefile
make
./szachy

