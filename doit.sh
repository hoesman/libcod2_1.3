#!/bin/bash

# ./doit.sh 
# ./doit.sh clean

cc="g++"
options="-I. -m32 -fPIC -Wall"

pthread_link=""

if [ "$1" == "clean" ]; then
	echo "##### CLEAN OBJECTS #####"
	rm objects_* -rf
	rm bin -rf
	exit 1	

elif [ "$1" == "" ]; then
	constants="-D COD_VERSION=COD2_1_3"

else
	echo "##### Unrecognized command line option $1 #####"
	exit 0
fi

mkdir -p bin
mkdir -p objects_"cod2"

echo "##### COMPILE cod2 CRACKING.CPP #####"
$cc $options $constants -c cracking.cpp -o objects_"cod2"/cracking.opp

echo "##### COMPILE cod2 GSC.CPP #####"
$cc $options $constants -c gsc.cpp -o objects_"cod2"/gsc.opp

echo "##### COMPILE cod2 LIBCOD.CPP #####"
$cc $options $constants -c libcod.cpp -o objects_"cod2"/libcod.opp

echo "##### LINKING libcod2.so #####"
objects="$(ls objects_cod2/*.opp)"
$cc -m32 -shared -L/lib32 -o bin/lib"cod2".so -ldl $objects
rm objects_"cod2" -r
