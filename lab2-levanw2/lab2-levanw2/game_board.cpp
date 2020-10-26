#pragma once

/** game_board.cpp
Author: Will LeVan
Purpose: definitions for functions to extract the dimensions of a game board from an input file, read in and store game pieces from an input file, and print out the resulting pieces on a game board
**/

#include "game_board.h"
#include <sstream>
#include "declarations.h"
#include <iostream>

// STEP 11: this function reads in the dimensions (# of rows and # of columns) from an input file
int dimensions(ifstream& file, unsigned int& width, unsigned int& height) {
	string local;
	if (getline(file, local)) { // reads the first line of the file into the local string
		istringstream iss(local); // local wrapped in an input string stream
		if (iss >> width) {
			if (iss >> height) return static_cast<int>(return_values::success); // success is declared if a value is able to be extracted into bother width and height from the input string stream
			else return static_cast<int>(return_values::dimension_extract_failed); // failure of dimension extract returned if no height is able to be extracted from the input string stream
		}
		else return static_cast<int>(return_values::dimension_extract_failed); // failure of dimension extract returned if no width is able to be extracted from the input string stream
	}
	else return static_cast<int>(return_values::read_line_failed); // if line is unable to be read from the file, this failure value is returned
}

// STEP 12: this function reads in game pieces from an input file stream and then stores them in a vector based on their location on the board
int game_pieces(ifstream& file, vector<game_piece>& positions, unsigned int& width, unsigned int& height) {
	bool read_one = false; // initializes a bool variable read_one as false, will be changed to true if the function is able to read one piece from the file
	string nextstring;
	while (getline(file, nextstring)) { // reads in a string from a file until it is unable to do so
		istringstream iss(nextstring); // wraps the string read from the file into an input string stream
		string color;
		string name;
		string display;
		unsigned int column;
		unsigned int row;
		if (iss >> color) { // following if statements are all to see if piece information can be read from the input file's line
			if (iss >> name) {
				if (iss >> display) {
					if (iss >> column) {
						if (iss >> row) {
							lowercaser(color); // ensures the color of the piece is lowercase so we can call color_enum on the string, as we do below
							piece_color this_color = color_enum(color);
							if (column <= width && row <= height) { // ensures that the pieces coordinates are on the board
								if (this_color != piece_color::invalid_color) { // able to get all info and piece (which has a color) can be placed on the board
									positions[width * row + column] = game_piece(this_color, name, display); // places the piece in the positions array based on its coordinates
									read_one = true; // a piece has been fully read and formed, so read_one is changed to true
								}

							}


						}
					}
				}
			}
		}
	}
	if (read_one) return static_cast<int>(return_values::success); // if a piece has been formed, then the function returns the return_values enum value for success
	else return static_cast<int>(return_values::no_formed_pieces); // if no pieces can be formed, then the function returns the return_values enum value no_formed_pieces

}

// STEP 13
int print_board(const vector<game_piece>& pieces, unsigned int width, unsigned int height) { // how to make a part to check if it can fail?
	if (pieces.size() != width * height) return static_cast<int>(return_values::dimensions_incorrect);
	else {
		for (size_t row = height; row > 0; row--) {
			for (size_t column = 0; column < width; column++) {
				cout << pieces[width * (row - 1) + column]._piece_display;
			}
			cout << " " << endl;
		}
		return static_cast<int>(return_values::success);
	}
}
