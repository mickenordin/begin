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
#include "begin.hpp"
using namespace std;

int main(int argc, char **argv)
{
	
	if( argc == 2) { //assume the argument is a regex and to read from std in
		begin(argv[1], cin);
	} else if( argc == 3) { //assume the first argument is a regex and second is a filename
		ifstream in(argv[2]);
		begin(argv[1], in);
	} else {
		cout << "Usage: begin <regex> [filename] \n";
	}
	return 0;
}

