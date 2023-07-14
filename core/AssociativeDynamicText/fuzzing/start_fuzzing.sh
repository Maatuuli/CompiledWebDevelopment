#!/bin/bash

PARAMETERS_WITHOUT_ADDRESS_SANITIZER="-g -Werror -O3 -s -Wall -Wstrict-prototypes -Wshadow -Wextra -Wno-unused-parameter -Wno-overlength-strings -Wpedantic -Winline"
PARAMETERS="${PARAMETERS_WITHOUT_ADDRESS_SANITIZER} -fsanitize=address,undefined,leak -fsanitize-address-use-after-scope"

PATH_FOR_GCC="/usr/bin/gcc"

$PATH_FOR_GCC $PARAMETERS AssociativeDynamicTextFuzzing.c --output AssociativeDynamicTextFuzzing.out && ./AssociativeDynamicTextFuzzing.out
