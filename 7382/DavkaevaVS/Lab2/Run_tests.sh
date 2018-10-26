#!/bin/bash
g++ ./Source/main.cpp -o Lab
echo 'Test 1:____________________________'
cat ./Tests/Test1.txt
./Lab < ./Tests/Test1.txt
echo 'Test 2:____________________________'
cat ./Tests/Test2.txt
./Lab < ./Tests/Test2.txt
echo 'Test 3:____________________________'
cat ./Tests/Test3.txt
./Lab < ./Tests/Test3.txt
echo 'Test 4:____________________________'
cat ./Tests/Test4.txt
./Lab < ./Tests/Test4.txt

