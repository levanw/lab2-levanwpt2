// lab2-levanwpt2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/* lab2-levanwpt2.cpp
Author: Will LeVan
Purpose: this file contains the 'main' function where program execution begins and ends
*/

#include <iostream>
#include "declarations.h"
#include "game_board.h"

// STEP 14
int main(int argc, char* argv[]) {
	if (argc == static_cast<int>(relevant_indices::expected_argc)) { // if the arg input has the expected number of commands
		ifstream file;
		file.open(argv[static_cast<int>(relevant_indices::input_file_name)]); // open the input file with an input file stream
		if (file.is_open()) {
			// cout << "file opened" << endl;
			unsigned int width;
			unsigned int height;
			int board = dimensions(file, width, height);
			while (board == static_cast<int>(return_values::dimension_extract_failed)) { // continued calls of dimensions allows the program to account for poorly formed lines or blank lines until we can acquire the dimensions of the board
				board = dimensions(file, width, height);
			}
			if (board == (static_cast<int>(return_values::success))) {
				vector<game_piece> pieces;
				for (size_t i = 0; i < width * height; i++) {
					game_piece p = game_piece(piece_color::no_color, "", " ");
					pieces.push_back(p); // push back an empty game piece on every place on the board
				}
				int piece = game_pieces(file, pieces, width, height);
				if (piece == static_cast<int>(return_values::success)) { // if pieces exist/are formed, procede to print out the board with these pieces
					file.close();
					return print_board(pieces, width, height);
				}
				else {
					cout << "Pieces cannot be read" << endl;
					file.close();
					return static_cast<int>(return_values::no_formed_pieces); // pieces are not formed, so the user is alerted to that and then the function returns the appropriate error message
				}
			}
			else {
				cout << "Cannot get board dimensions" << endl;
				file.close();
				return static_cast<int>(return_values::dimension_extract_failed); // dimensions can't be extracted from the file, so the user is alerted to that and then the function returns the appropriate error message
			}
		}
		else {
			cout << "File cannot be read" << endl;
			return static_cast<int>(return_values::file_unread); // file couldn't be opened, so the user is alerted to that and then the function returns the appropriate error message
		}
	}
	else { // if the incorrect amount of arguments are passed into the program, then the user is alerted and told how they should implement the function within the command window
		char message[] = "<input-file-name>";
		return usage_message(argv[static_cast<int>(relevant_indices::program_name)], message);
	}
}

// STEP 5: called if the user runs the program incorrectly, displays how to correctly use the program
int usage_message(char program_name[], char arg_suggestion[]) {
	cout << "to use, provide the following command argument: " << program_name << " " << arg_suggestion << endl;
	return static_cast<int>(return_values::incorrect_usage);
};

// STEP 6: this function takes a reference to a C++ style string and then modifies that string, making all letters in the string lowercase
void lowercaser(string& word) {
	for (size_t i = 0; i < word.size(); ++i) { // for loop to traverse the string
		if (word[i] >= 65 && word[i] <= 91) word[i] = word[i] + 32; // if a character is uppercase, make it become lowercase by changing its ASCII value
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
