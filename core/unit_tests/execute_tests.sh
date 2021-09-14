#!/bin/bash

PARAMETERS_WITHOUT_ADDRESS_SANITIZER="-O0 -g -Wall -Wpedantic -Winline -fprofile-arcs -ftest-coverage -lgcov"
PARAMETERS="${PARAMETERS_WITHOUT_ADDRESS_SANITIZER} -fsanitize=address -fsanitize=undefined -fsanitize=leak -fsanitize-address-use-after-scope"

PATH_FOR_GCC="/usr/bin/gcc"

# Using subshells in Bash to compile all unit tests with a "wait" command at the end in parallel!

$PATH_FOR_GCC $PARAMETERS tests_for_associativeDynamicText.c --output tests_for_associativeDynamicText.out &
$PATH_FOR_GCC $PARAMETERS tests_for_associativeDynamicText_exit1.c --output tests_for_associativeDynamicText_exit1.out &
$PATH_FOR_GCC $PARAMETERS tests_for_associativeDynamicText_exit2.c --output tests_for_associativeDynamicText_exit2.out &
$PATH_FOR_GCC $PARAMETERS tests_for_associativeDynamicText_exit3.c --output tests_for_associativeDynamicText_exit3.out &
$PATH_FOR_GCC $PARAMETERS tests_for_associativeDynamicText_exit4.c --output tests_for_associativeDynamicText_exit4.out &
$PATH_FOR_GCC $PARAMETERS tests_for_associativeDynamicText_exit5.c --output tests_for_associativeDynamicText_exit5.out &
$PATH_FOR_GCC $PARAMETERS tests_for_associativeDynamicText_exit6.c --output tests_for_associativeDynamicText_exit6.out &
$PATH_FOR_GCC $PARAMETERS tests_for_associativeDynamicText_exit7.c --output tests_for_associativeDynamicText_exit7.out &
$PATH_FOR_GCC $PARAMETERS tests_for_associativeDynamicTextList.c --output tests_for_associativeDynamicTextList.out &
$PATH_FOR_GCC $PARAMETERS tests_for_associativeDynamicTextList_exit1.c --output tests_for_associativeDynamicTextList_exit1.out &
$PATH_FOR_GCC $PARAMETERS tests_for_associativeDynamicTextList_exit2.c --output tests_for_associativeDynamicTextList_exit2.out &
$PATH_FOR_GCC $PARAMETERS tests_for_associativeDynamicTextList_exit3.c --output tests_for_associativeDynamicTextList_exit3.out &
$PATH_FOR_GCC $PARAMETERS tests_for_associativeDynamicTextList_exit4.c --output tests_for_associativeDynamicTextList_exit4.out &
$PATH_FOR_GCC $PARAMETERS tests_for_associativeDynamicTextList_exit5.c --output tests_for_associativeDynamicTextList_exit5.out &
$PATH_FOR_GCC $PARAMETERS tests_for_associativeDynamicTextList_exit6.c --output tests_for_associativeDynamicTextList_exit6.out &
$PATH_FOR_GCC $PARAMETERS tests_for_associativeDynamicTextList_exit7.c --output tests_for_associativeDynamicTextList_exit7.out &
$PATH_FOR_GCC $PARAMETERS tests_for_associativeDynamicTextList_exit8.c --output tests_for_associativeDynamicTextList_exit8.out &
$PATH_FOR_GCC $PARAMETERS tests_for_associativeDynamicTextList_exit9.c --output tests_for_associativeDynamicTextList_exit9.out &
$PATH_FOR_GCC $PARAMETERS tests_for_associativeDynamicTextList_exit10.c --output tests_for_associativeDynamicTextList_exit10.out &
$PATH_FOR_GCC $PARAMETERS tests_for_associativeDynamicTextList_exit11.c --output tests_for_associativeDynamicTextList_exit11.out &
$PATH_FOR_GCC $PARAMETERS tests_for_associativeDynamicTextList_exit12.c --output tests_for_associativeDynamicTextList_exit12.out &
$PATH_FOR_GCC $PARAMETERS tests_for_associativeDynamicTextList_exit13.c --output tests_for_associativeDynamicTextList_exit13.out &
$PATH_FOR_GCC $PARAMETERS tests_for_associativeDynamicTextList_exit14.c --output tests_for_associativeDynamicTextList_exit14.out &
$PATH_FOR_GCC $PARAMETERS tests_for_associativeDynamicTextList_exit15.c --output tests_for_associativeDynamicTextList_exit15.out &
$PATH_FOR_GCC $PARAMETERS tests_for_associativeDynamicTextList_exit16.c --output tests_for_associativeDynamicTextList_exit16.out &
$PATH_FOR_GCC $PARAMETERS tests_for_associativeDynamicTextList_exit17.c --output tests_for_associativeDynamicTextList_exit17.out &
$PATH_FOR_GCC $PARAMETERS tests_for_dynamicText.c --output tests_for_dynamicText.out &
$PATH_FOR_GCC $PARAMETERS tests_for_dynamicText_exit1.c --output tests_for_dynamicText_exit1.out &
$PATH_FOR_GCC $PARAMETERS tests_for_dynamicText_exit2.c --output tests_for_dynamicText_exit2.out &
$PATH_FOR_GCC $PARAMETERS tests_for_dynamicText_exit3.c --output tests_for_dynamicText_exit3.out &
$PATH_FOR_GCC $PARAMETERS tests_for_dynamicText_exit4.c --output tests_for_dynamicText_exit4.out &
$PATH_FOR_GCC $PARAMETERS tests_for_dynamicText_exit5.c --output tests_for_dynamicText_exit5.out &
$PATH_FOR_GCC $PARAMETERS tests_for_dynamicText_exit6.c --output tests_for_dynamicText_exit6.out &
$PATH_FOR_GCC $PARAMETERS tests_for_dynamicText_exit7.c --output tests_for_dynamicText_exit7.out &
$PATH_FOR_GCC $PARAMETERS tests_for_dynamicText_exit8.c --output tests_for_dynamicText_exit8.out &
$PATH_FOR_GCC $PARAMETERS tests_for_dynamicText_exit9.c --output tests_for_dynamicText_exit9.out &
$PATH_FOR_GCC $PARAMETERS tests_for_dynamicText_exit10.c --output tests_for_dynamicText_exit10.out &
$PATH_FOR_GCC $PARAMETERS tests_for_dynamicText_exit11.c --output tests_for_dynamicText_exit11.out &
$PATH_FOR_GCC $PARAMETERS tests_for_dynamicText_exit12.c --output tests_for_dynamicText_exit12.out &
$PATH_FOR_GCC $PARAMETERS tests_for_dynamicText_exit13.c --output tests_for_dynamicText_exit13.out &
$PATH_FOR_GCC $PARAMETERS_WITHOUT_ADDRESS_SANITIZER tests_for_dynamicText_exit14.c --output tests_for_dynamicText_exit14.out &
$PATH_FOR_GCC $PARAMETERS tests_for_dynamicTextList.c --output tests_for_dynamicTextList.out &
$PATH_FOR_GCC $PARAMETERS tests_for_dynamicTextList_exit1.c --output tests_for_dynamicTextList_exit1.out &
$PATH_FOR_GCC $PARAMETERS tests_for_dynamicTextList_exit2.c --output tests_for_dynamicTextList_exit2.out &
$PATH_FOR_GCC $PARAMETERS_WITHOUT_ADDRESS_SANITIZER tests_for_dynamicTextList_exit3.c --output tests_for_dynamicTextList_exit3.out &
$PATH_FOR_GCC $PARAMETERS tests_for_dynamicTextList_exit4.c --output tests_for_dynamicTextList_exit4.out &
$PATH_FOR_GCC $PARAMETERS tests_for_dynamicTextList_exit5.c --output tests_for_dynamicTextList_exit5.out &
$PATH_FOR_GCC $PARAMETERS tests_for_dynamicTextList_exit6.c --output tests_for_dynamicTextList_exit6.out &
$PATH_FOR_GCC $PARAMETERS tests_for_dynamicTextList_exit7.c --output tests_for_dynamicTextList_exit7.out &
$PATH_FOR_GCC $PARAMETERS tests_for_dynamicTextList_exit8.c --output tests_for_dynamicTextList_exit8.out &
$PATH_FOR_GCC $PARAMETERS tests_for_dynamicTextList_exit9.c --output tests_for_dynamicTextList_exit9.out &
$PATH_FOR_GCC $PARAMETERS tests_for_dynamicTextList_exit10.c --output tests_for_dynamicTextList_exit10.out &
$PATH_FOR_GCC $PARAMETERS tests_for_dynamicTextList_exit11.c --output tests_for_dynamicTextList_exit11.out &
$PATH_FOR_GCC $PARAMETERS tests_for_dynamicTextList_exit12.c --output tests_for_dynamicTextList_exit12.out &
$PATH_FOR_GCC $PARAMETERS tests_for_explodeDynamicText.c --output tests_for_explodeDynamicText.out &
$PATH_FOR_GCC $PARAMETERS tests_for_explodeDynamicText_exit1.c --output tests_for_explodeDynamicText_exit1.out &
$PATH_FOR_GCC $PARAMETERS tests_for_explodeDynamicText_exit2.c --output tests_for_explodeDynamicText_exit2.out &
$PATH_FOR_GCC $PARAMETERS tests_for_findPositionInDynamicText.c --output tests_for_findPositionInDynamicText.out &
$PATH_FOR_GCC $PARAMETERS tests_for_findPositionInDynamicText_exit1.c --output tests_for_findPositionInDynamicText_exit1.out &
$PATH_FOR_GCC $PARAMETERS tests_for_findPositionInDynamicText_exit2.c --output tests_for_findPositionInDynamicText_exit2.out &
$PATH_FOR_GCC $PARAMETERS tests_for_findPositionInDynamicText_exit3.c --output tests_for_findPositionInDynamicText_exit3.out &
$PATH_FOR_GCC $PARAMETERS tests_for_findPositionInDynamicText_exit4.c --output tests_for_findPositionInDynamicText_exit4.out &
$PATH_FOR_GCC $PARAMETERS tests_for_findPositionInDynamicText_exit5.c --output tests_for_findPositionInDynamicText_exit5.out &
$PATH_FOR_GCC $PARAMETERS tests_for_findPositionInDynamicText_exit6.c --output tests_for_findPositionInDynamicText_exit6.out &
$PATH_FOR_GCC $PARAMETERS tests_for_functions_for_cgi.c --output tests_for_functions_for_cgi.out &
$PATH_FOR_GCC $PARAMETERS tests_for_getSubstringInBytesFromDynamicText.c --output tests_for_getSubstringInBytesFromDynamicText.out &
$PATH_FOR_GCC $PARAMETERS tests_for_getSubstringInBytesFromDynamicText_exit1.c --output tests_for_getSubstringInBytesFromDynamicText_exit1.out &
$PATH_FOR_GCC $PARAMETERS tests_for_getSubstringInBytesFromDynamicText_exit2.c --output tests_for_getSubstringInBytesFromDynamicText_exit2.out &
$PATH_FOR_GCC $PARAMETERS tests_for_getSubstringInBytesFromDynamicText_exit3.c --output tests_for_getSubstringInBytesFromDynamicText_exit3.out &
$PATH_FOR_GCC $PARAMETERS tests_for_getSubstringInBytesFromDynamicText_exit4.c --output tests_for_getSubstringInBytesFromDynamicText_exit4.out &
$PATH_FOR_GCC $PARAMETERS tests_for_getSubstringInBytesFromDynamicText_exit5.c --output tests_for_getSubstringInBytesFromDynamicText_exit5.out &
$PATH_FOR_GCC $PARAMETERS tests_for_getSubstringInBytesFromDynamicText_exit6.c --output tests_for_getSubstringInBytesFromDynamicText_exit6.out &
$PATH_FOR_GCC $PARAMETERS tests_for_getSubstringInBytesFromDynamicText_exit7.c --output tests_for_getSubstringInBytesFromDynamicText_exit7.out &
$PATH_FOR_GCC $PARAMETERS tests_for_getSubstringInBytesFromDynamicText_exit8.c --output tests_for_getSubstringInBytesFromDynamicText_exit8.out &
$PATH_FOR_GCC $PARAMETERS tests_for_implodeListForDynamicText.c --output tests_for_implodeListForDynamicText.out &
$PATH_FOR_GCC $PARAMETERS tests_for_replaceDynamicText.c --output tests_for_replaceDynamicText.out &
$PATH_FOR_GCC $PARAMETERS tests_for_stripTagsInDynamicText.c --output tests_for_stripTagsInDynamicText.out &

# Wait until all subshells are ready with compilation!
wait

echo ""
echo "### TEST SUITES:"

./tests_for_associativeDynamicText.out
./tests_for_associativeDynamicTextList.out
./tests_for_dynamicText.out
./tests_for_dynamicTextList.out
./tests_for_explodeDynamicText.out
./tests_for_findPositionInDynamicText.out
./tests_for_functions_for_cgi.out
./tests_for_getSubstringInBytesFromDynamicText.out
./tests_for_implodeListForDynamicText.out
./tests_for_replaceDynamicText.out
./tests_for_stripTagsInDynamicText.out
./tests_for_associativeDynamicText_exit1.out
./tests_for_associativeDynamicText_exit2.out
./tests_for_associativeDynamicText_exit3.out
./tests_for_associativeDynamicText_exit4.out
./tests_for_associativeDynamicText_exit5.out
./tests_for_associativeDynamicText_exit6.out
./tests_for_associativeDynamicText_exit7.out
./tests_for_associativeDynamicTextList_exit1.out
./tests_for_associativeDynamicTextList_exit2.out
./tests_for_associativeDynamicTextList_exit3.out
./tests_for_associativeDynamicTextList_exit4.out
./tests_for_associativeDynamicTextList_exit5.out
./tests_for_associativeDynamicTextList_exit6.out
./tests_for_associativeDynamicTextList_exit7.out
./tests_for_associativeDynamicTextList_exit8.out
./tests_for_associativeDynamicTextList_exit9.out
./tests_for_associativeDynamicTextList_exit10.out
./tests_for_associativeDynamicTextList_exit11.out
./tests_for_associativeDynamicTextList_exit12.out
./tests_for_associativeDynamicTextList_exit13.out
./tests_for_associativeDynamicTextList_exit14.out
./tests_for_associativeDynamicTextList_exit15.out
./tests_for_associativeDynamicTextList_exit16.out
./tests_for_associativeDynamicTextList_exit17.out
./tests_for_dynamicText_exit1.out
./tests_for_dynamicText_exit2.out
./tests_for_dynamicText_exit3.out
./tests_for_dynamicText_exit4.out
./tests_for_dynamicText_exit5.out
./tests_for_dynamicText_exit6.out
./tests_for_dynamicText_exit7.out
./tests_for_dynamicText_exit8.out
./tests_for_dynamicText_exit9.out
./tests_for_dynamicText_exit10.out
./tests_for_dynamicText_exit11.out
./tests_for_dynamicText_exit12.out
./tests_for_dynamicText_exit13.out
./tests_for_dynamicText_exit14.out
./tests_for_dynamicTextList_exit1.out
./tests_for_dynamicTextList_exit2.out
./tests_for_dynamicTextList_exit3.out
./tests_for_dynamicTextList_exit4.out
./tests_for_dynamicTextList_exit5.out
./tests_for_dynamicTextList_exit6.out
./tests_for_dynamicTextList_exit7.out
./tests_for_dynamicTextList_exit8.out
./tests_for_dynamicTextList_exit9.out
./tests_for_dynamicTextList_exit10.out
./tests_for_dynamicTextList_exit11.out
./tests_for_dynamicTextList_exit12.out
./tests_for_explodeDynamicText_exit1.out
./tests_for_explodeDynamicText_exit2.out
./tests_for_findPositionInDynamicText_exit1.out
./tests_for_findPositionInDynamicText_exit2.out
./tests_for_findPositionInDynamicText_exit3.out
./tests_for_findPositionInDynamicText_exit4.out
./tests_for_findPositionInDynamicText_exit5.out
./tests_for_findPositionInDynamicText_exit6.out
./tests_for_getSubstringInBytesFromDynamicText_exit1.out
./tests_for_getSubstringInBytesFromDynamicText_exit2.out
./tests_for_getSubstringInBytesFromDynamicText_exit3.out
./tests_for_getSubstringInBytesFromDynamicText_exit4.out
./tests_for_getSubstringInBytesFromDynamicText_exit5.out
./tests_for_getSubstringInBytesFromDynamicText_exit6.out
./tests_for_getSubstringInBytesFromDynamicText_exit7.out
./tests_for_getSubstringInBytesFromDynamicText_exit8.out

echo ""
echo "END OF TESTING:"
echo "All tests were executed!"
