#pragma once

/* game_pieces.h
Author: Will LeVan
Purpose: declarations for functionality of the game_pieces.cpp functions
*/

#include <string>
using namespace std;

// STEP 7: enumeration for the different color values that a piece can have

enum struct piece_color { no_color = 1, black = 2, red = 3, white = 4, invalid_color = 5 };

// STEP 8: given an enumerated type, this function takes a piece_color value and returns a string indicating the given color
// parameters: the enumerated type piece_color by value which provides the color identity of the piece
// return value: piece_color's color value expressed in a string

string color_name(piece_color color);

// STEP 9: essentially does the inverse of color_name() in Step 8 by taking a string (stating a color) and returns the piece_color element that corresponds that that color
// parameters: a color expressed as a C++ style string
// return value: a piece_color enumerated type which corresponds to the provided string value

piece_color color_enum(string color);

// STEP 10: a struct to represent a game piece which includes a piece_color type to symbolize a piece's color and two C++ style strings to represent the piece's name and how it should be displayed

struct game_piece {
	game_piece(piece_color this_piece, string piece_name, string piece_display);
	piece_color _this_piece;
	string _piece_name;
	string _piece_display;
};
