project:customer.o
	cc customer.o -o project
main.o: customer.c
	cc -Wall -c customer.c
