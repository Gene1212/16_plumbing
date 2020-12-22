all: file0 file1

file0: file0.c
	gcc -o file0 file0.c
	
file1: file1.c
	gcc -o file1 file1.c

