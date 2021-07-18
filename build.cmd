gcc -c input.dll.c -o input.dll.o
gcc -shared -o input.dll input.dll.o -Wl,--out-implib,input.dll.a
del input.dll.o
del input.dll.a