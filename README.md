This is a stripped down *libcod* version with only patches/fixes/protections for:

 - Call Of Duty 2 1.3

Requirements:
```
dpkg --add-architecture i386
apt-get update
apt-get install gcc-multilib g++-multilib
```

Starting the server:

```LD_PRELOAD=libcod2.so ./cod2_lnxded +set fs_game ...```

Some enviroments need LD_LIBRARY_PATH also:

```LD_LIBRARY_PATH=. LD_PRELOAD=libcod2.so ./cod2_lnxded +set fs_game ...```
	
Working with the source / Compiling:
```
To compile
./doit.sh

To clean
./doit.sh clean
 
```
