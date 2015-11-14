project:CustomerM.o
	cc CustomerM.o -o project
main.o: CustomerM.c
	cc -Wall -c CustomerM.c

