#!/bin/bash

PARAMETERS="-std=c11 -O0 -g -Wall -Wstrict-prototypes -Wshadow -Wextra -Wno-unused-parameter -Wno-overlength-strings -Wpedantic -Winline -fprofile-arcs -ftest-coverage -lgcov -fsanitize=address -fsanitize=undefined -fsanitize=leak -fsanitize-address-use-after-scope"
PATH_FOR_GCC="/usr/bin/gcc"

# Using subshells in Bash to compile all unit tests with a "wait" command at the end in parallel!

$PATH_FOR_GCC $PARAMETERS tests_for_startApplication.c --output tests_for_startApplication.out `mariadb_config --cflags --libs` &

# Wait until all subshells are ready with compilation!
wait

echo ""
echo "### TEST SUITES:"

./tests_for_startApplication.out

echo ""
echo "END OF TESTING:"
echo "All tests were executed!"
