#pragma once

/* game_board.h
Author: Will LeVan
Purpose: declarations for functionality of the game_board.cpp functions
*/

#include <fstream>
#include <vector>
#include "game_pieces.h"

// STEP 11: this function reads in the dimensions (# of rows and # of columns) from an input file
// parameters: reference to an input file stream for the file containing the game board/piece information and two unsigned ints representing the width and height
// return value: int to represent the success or failure of the program in reading board dimensions, these success or failure values are taken from the return_values enum in declarations.h (success, dimensions_extract_failed, and read_line_failed)

int dimensions(ifstream& file, unsigned int& width, unsigned int& height);

// STEP 12: this function reads in game pieces from an input file stream and then stores them in a vector based on their location on the board
// parameters: reference to an input file stream for the file containing the game board/piece information, a referene to a vector of game_piece elements to represent piece locations, and two unsigned ints representing the width and height
// return value: int to represent the success or failure of the program in reading board dimensions, these success or failure values are taken from the return_values enum in declarations.h (success and no_formed_pieces))

int game_pieces(ifstream& file, vector<game_piece>& positions, unsigned int& width, unsigned int& height);

// STEP 13: this function prints out the pieces on a game board by using the locations of pieces (provided by the first parameters) and the size of the board (given by remaining two parameters)
// parameters: a reference to a vector of game_piece elements to represent piece locations and two unsigned ints representing the width and height
// return value: int to represent the success or failure of the program in printing the board, these success or failure values are taken from the return_values enum in declarations.h

int print_board(const vector<game_piece>& pieces, unsigned int width, unsigned int height);
