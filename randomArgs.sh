#!/bin/zsh

#ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`;
make clean
make ps
./checker "9 0 8 6 7"
