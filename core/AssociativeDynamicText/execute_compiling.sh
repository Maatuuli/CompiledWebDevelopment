#!/bin/bash

PARAMETERS_WITHOUT_ADDRESS_SANITIZER="-O0 -g -Wall -Werror -Wpedantic -Winline -fprofile-arcs -ftest-coverage -lgcov"
PARAMETERS="${PARAMETERS_WITHOUT_ADDRESS_SANITIZER} -fsanitize=address -fsanitize=undefined -fsanitize=leak -fsanitize-address-use-after-scope"

PATH_FOR_GCC="/usr/bin/gcc"

$PATH_FOR_GCC $PARAMETERS DynamicTextTests.c --output tests_for_DynamicText.out
# ./tests_for_DynamicText.out
