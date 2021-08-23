gcc -c simInputLib.dll.c -Os -o simInputLib.dll.o
gcc -s -shared -o simInputLib.dll simInputLib.dll.o
del simInputLib.dll.o