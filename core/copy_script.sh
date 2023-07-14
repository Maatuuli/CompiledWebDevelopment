#!/bin/bash

d=`date +%H-%M-%S`

for index in $(seq 1 150)
do
    {
    mutationRootDirectory="DynamicTextMutationMutation$index/"
    /usr/bin/mkdir $mutationRootDirectory

    mutationUnitTestsDirectory="$mutationRootDirectory/unit_tests"
    /usr/bin/mkdir $mutationUnitTestsDirectory

    /usr/bin/cp DynamicText/DynamicText.class.c $mutationRootDirectory
    /usr/bin/cp DynamicText/unit_tests/DynamicTextTests.c $mutationUnitTestsDirectory
    /usr/bin/cp DynamicText/unit_tests/error.log $mutationUnitTestsDirectory
    /usr/bin/cp DynamicText/unit_tests/execute_compiling.sh $mutationUnitTestsDirectory
    
    cd $mutationUnitTestsDirectory
    /usr/bin/sh ./execute_compiling.sh && echo "Compiling #$index was fine!"
    ./tests_for_DynamicText.out > /dev/null && echo "Tests #$index were fine!"

    cd ..

    cd ..
    
    rm -rf ./$mutationRootDirectory

    } &
done

wait


# 150 iterations
# real	0m17,083s
# user	1m54,768s
# sys   0m15,352s

# 426 iterations
# real	0m52,762s
# user	6m0,072s
# sys	0m45,657s

