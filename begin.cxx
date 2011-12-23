/*
 * begin.cxx
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
#include <boost/xpressive/xpressive.hpp>
#include <fstream>

using namespace std;

void begin(string needle, istream &in)
{
	string input;
	boost::xpressive::sregex regex = boost::xpressive::sregex::compile( needle, boost::xpressive::regex_constants::icase );

	while(in) {
		getline(in, input);
		if ( boost::xpressive::regex_search(input, regex) ) {
			cout << input << endl;
			while(in) {
				getline(in,input);
				cout << input << endl;
			}
		}
	}

}


