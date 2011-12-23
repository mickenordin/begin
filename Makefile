CC=g++
CFLAGS=-c -g -Wall
CCFLAGS=-g -Wall 
prefix=/usr/local

begin : main.o begin.o
	$(CC) -o begin $(CCFLAGS) main.o begin.o
	
main.o: main.cxx begin.o 
	$(CC) $(CFLAGS) main.cxx
	
begin.o: begin.cxx begin.hpp
	$(CC) $(CFLAGS) begin.cxx
	
install: begin
	install -m 0755 begin $(prefix)/bin

uninstall: begin
	rm $(prefix)/bin/begin
clean:
	rm *.o begin

.PHONY: install
.PHONY: uninstall
.PHONY: clean 

