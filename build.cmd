gcc -c simInputLib.dll.c -o simInputLib.dll.o
gcc -shared -o simInputLib.dll simInputLib.dll.o -Wl,--out-implib,simInputLib.dll.a
del simInputLib.dll.o
del simInputLib.dll.a