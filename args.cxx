/*
 * args.cxx
 * 
 * Copyright 2011 Micke Nordin <micke@hal>
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
#include <fstream>
#include "args.hpp"
using namespace std;

args::args(int argc, char **argv) {
	iscaseinsence = false;
	isregex = false;
	havefile = false;
	filename = "";
	int c;
	
	while ((c = getopt (argc, argv, "efi:")) != -1) {
		switch (c)   {
			case 'e':
				isregex = true;
				break;
			case 'f':
			    filename = optarg;
				havefile = true;
				break;
			case 'i':
				iscaseinsence = true;
				break;
			case '?':
				if (optopt == 'f') {
					cerr << "Option -" << optopt << " requires an argument.\n";
				}
				else if (isprint (optopt)) {
					cerr << "Unknown option `-" << optopt << ".\n";
				}
				else {
					cerr << "Unknown option character `\\x" << optopt << ".\n";
				}
//			default:
//				abort ();
		}
	}
}

void args::print() {
	cout << "Case inscensitive: " << iscaseinsence << " Regex: " << isregex << " Have a file: " << havefile << " filename: " << filename;
}
