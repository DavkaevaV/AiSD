#!/bin/bash
g++ -c ./Source/bt_func.cpp
g++ -c ./Source/Source.cpp
g++ Source.o bt_func.o -o Lab4
rm Source.o
rm bt_func.o
echo -e '_______\nTest 1:'
cat ./Tests/1test.txt
echo -e '_______\nTesting:\n'
./Lab4 < ./Tests/1test.txt
echo -e ''
echo -e '_______\nTest 2:'
cat ./Tests/2test.txt
echo -e '_______\nTesting:\n'
./Lab4 < ./Tests/2test.txt
echo -e ''
echo -e '_______\nTest 3:'
cat ./Tests/3test.txt
echo -e '_______\nTesting:\n'
./Lab4 < ./Tests/3test.txt
echo -e ''
echo -e '_______\nTest 4:'
cat ./Tests/4test.txt
echo -e '_______\nTesting:\n'
./Lab4 < ./Tests/4test.txt
echo -e ''
echo -e '_______\nTest 5:'
cat ./Tests/5test.txt
echo -e '_______\nTesting:\n'
./Lab4 < ./Tests/5test.txt
echo -e ''

