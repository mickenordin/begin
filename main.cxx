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
#include "begin.hpp"
using namespace std;

int main(int argc, char **argv)
{
	int works = 1; //default return value
	
	if( argc == 2) { //assume the argument is a regex and to read from std in
		works = begin(argv[1], cin); //try the search
	} else if( argc == 3) { //assume the first argument is a regex and second is a filename
		ifstream in(argv[2]);
		works = begin(argv[1], in); //try the search
	} else { //Wrong number of command line args
		cout <<  "Usage: begin <regex> [filename] \n";
	}

	return works;

}

