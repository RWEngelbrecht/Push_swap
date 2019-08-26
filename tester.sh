make re

{ sleep 5; echo 3 int test in 3 seconds; } &
{ sleep 1; echo 3 int test in 1 second; } &
wait
ARG=`ruby -e "puts (1..3).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG

{ sleep 3; echo 5 int test in 3 seconds; } &
{ sleep 1; echo 5 int test in 1 second; } &
wait
ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG

{ sleep 3; echo 100 int test in 3 seconds; } &
{ sleep 1; echo 100 int test in 1 second; } &
wait
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG

{ sleep 3; echo 500 int test in 3 seconds; } &
{ sleep 1; echo 500 int test in 1 second; } &
wait
ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG
