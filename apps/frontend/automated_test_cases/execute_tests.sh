#!/bin/bash

PATH_FOR_JAVA="/usr/bin/java"
PATH_FOR_JAVA_COMPILER="/usr/bin/javac"
PATH_FOR_JAR_PACKAGER="/usr/bin/jar"
PATH_FOR_SELENIUM_PACKAGE="./selenium-server-standalone-3.14.0.jar"

$PATH_FOR_JAVA_COMPILER -d ./test_case_a01/classes -classpath $PATH_FOR_SELENIUM_PACKAGE ./Helper.java ./test_case_a01/FrontendTest.java; cd ./test_case_a01/classes; $PATH_FOR_JAR_PACKAGER cfm ../../test_case_a01.jar ../../manifest.mf ./*.class; cd -
$PATH_FOR_JAVA_COMPILER -d ./test_case_a04/classes -classpath $PATH_FOR_SELENIUM_PACKAGE ./Helper.java ./test_case_a04/FrontendTest.java; cd ./test_case_a04/classes; $PATH_FOR_JAR_PACKAGER cfm ../../test_case_a04.jar ../../manifest.mf ./*.class; cd -
$PATH_FOR_JAVA_COMPILER -d ./test_case_a05/classes -classpath $PATH_FOR_SELENIUM_PACKAGE ./Helper.java ./test_case_a05/FrontendTest.java; cd ./test_case_a05/classes; $PATH_FOR_JAR_PACKAGER cfm ../../test_case_a05.jar ../../manifest.mf ./*.class; cd -

$PATH_FOR_JAVA -jar test_case_a01.jar
$PATH_FOR_JAVA -jar test_case_a04.jar
$PATH_FOR_JAVA -jar test_case_a05.jar

echo ""
echo "END OF TESTING:"
echo "All automated test cases were executed!"
