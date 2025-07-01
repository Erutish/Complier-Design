#!/bin/bash
flex 23241132.l
bison -d -y 23241132.y
g++ -w lex.yy.c y.tab.c -o 23241132.exe
./23241132.exe input.txt