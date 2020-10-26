#pragma once

/** game_pieces.cpp
Author: Will LeVan
Purpose: definitions for functions to identify colors of a piece and create a struct for pieces to specify a piece's color, name, and display
**/

#include "game_pieces.h"

// STEP 8: given an enumerated type, this function takes a piece_color value and returns a string indicating a color corresponding to the enumerated type
string color_name(piece_color color) {
	if (color == piece_color::no_color) return "no color";
	else if (color == piece_color::black) return "black";
	else if (color == piece_color::red) return "red";
	else if (color == piece_color::white) return "white";
	else return "invalid color";
}

// STEP 9: essentially does the inverse of color_name() in Step 8 by taking a string (stating a color) and returns the piece_color element that corresponds that that color
piece_color color_enum(string color) {
	bool blank_input = true; // assumptive initialization of blank_input (string of spaces) to be true
	for (size_t i = 0; i < color.size(); ++i) { // for loop checking if any characters of a given string are not a space
		if (!isspace(color[i])) {
			blank_input = false; // if any elements of color are not a white space, then blank_input is changed to false
		}
	}
	if (blank_input) return piece_color::no_color; // if blank_input remains true, then the function returns a piece_color type representing a piece with no color
	else if (color == "black") return piece_color::black;
	else if (color == "red") return piece_color::red;
	else if (color == "white") return piece_color::white;
	else return piece_color::invalid_color; // if color isn't blank or black, red, or white, then the function returns a piece_color of invalid color
}

// STEP 10: a struct to represent a game piece with parameters of piece_color to identify the color of the piece, a string to identify the name of the piece, and another string to identify how the piece should be displayed 
game_piece::game_piece(piece_color a, string b, string c)
	: _this_piece(a), _piece_name(b), _piece_display(c) {}
