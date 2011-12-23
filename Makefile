CC=g++
CFLAGS=-c -g -Wall
CCFLAGS=-g -Wall 
begin : main.o begin.o args.o
	$(CC) -o begin $(CCFLAGS) main.o begin.o args.o
	
main.o: main.cxx begin.o
	$(CC) $(CFLAGS) main.cxx
	
begin.o: begin.cxx begin.hpp
	$(CC) $(CFLAGS) begin.cxx 
	
args.o: args.cxx args.hpp
	$(CC) $(CFLAGS) args.cxx 


clean:
	rm *.o begin
