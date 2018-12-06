#!/bin/bash
g++ -c ./Source/ALG5.cpp
g++ -c ./Source/BTree.cpp
g++ ALG5.o BTree.o -o Lab5
rm ALG5.o
rm BTree.o
echo -e '_______\nTest 1:'
cat ./Tests/Test1.txt
echo -e '_______\nTesting:\n'
./Lab5 < ./Tests/Test1.txt
echo -e ''
echo -e '_______\nTest 2:'
cat ./Tests/Test2.txt
echo -e '_______\nTesting:\n'
./Lab5 < ./Tests/Test2.txt
echo -e ''
echo -e '_______\nTest 3:'
cat ./Tests/Test3.txt
echo -e '_______\nTesting:\n'
./Lab5 < ./Tests/Test3.txt
echo -e ''
echo -e '_______\nTest 4:'
cat ./Tests/Test4.txt
echo -e '_______\nTesting:\n'
./Lab5 < ./Tests/Test4.txt
echo -e ''


