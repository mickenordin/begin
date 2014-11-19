/*
 * main.cxx
 * 
 * Copyright 2011 Micke Nordin <mik@elnord.in>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */


#include <iostream>
#include <string>
#include <unistd.h>
#include "begin.hpp"
using namespace std;

int main(int argc, char **argv) {

	int c;
	string usage = "Usage: begin [-z|-j] <regex> [filename] \n";
	bool gzip = false;
	bool bzip2 = false;
	while((c =  getopt(argc, argv, "jhz?")) != EOF) {
		switch (c) {
			case 'j':
				bzip2 = true;
				break;
			case 'h':
				cout << usage;
				return 1;
			case 'z':
				gzip = true;
				break;
			case '?':
				cout << usage;
				return 1;
		}
	}

	if(gzip and bzip2) {
		cerr << "Please choose only one compression method\n";
		return 1;
	}

	int works = 1; //default return value
	
	if( argc == 2) { //assume the argument is a regex and to read from std in
		works = begin(argv[1], cin); //try the search
	} else if( argc == 3) { //assume the first argument is a regex and second is a filename
		ifstream in(argv[2]);
		works = begin(argv[1], in); //try the search
	} else if(gzip) { // gzip flag is set so we will try to decompress and try the search
		cout << "Decompressing\n";
	} else if(bzip2){ // bzip2 flag is set so we will try to decompress and try the search
		cout << "Decompressing\n";
	} else { //Wrong number of command line args
		cout <<  usage;
	}

	return works;

}

