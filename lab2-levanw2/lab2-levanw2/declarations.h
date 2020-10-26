#pragma once
/* declarations.h
Author: Will LeVan
Purpose: declarations for functionality of the main program
*/

#include <string>
using namespace std;

// enumeration for the different argument array indices that are relevant to the program

enum struct relevant_indices { program_name = 0, input_file_name = 1, expected_argc = 2 };

// enumeration for the different return values (successes and failures) that are occur in this program

enum struct return_values { success = 0, incorrect_usage = 1, dimension_extract_failed = 2, read_line_failed = 3, no_formed_pieces = 4, file_unread = 5, dimensions_incorrect = 6 };

// STEP 5: called if the user runs the program incorrectly, displays how to correctly use the program
// parameters: string giving the name of the program and a string conveying information to the user about how to correctly run the program
// return value: return a non-zero integer to indicate incorrect usage of the function

int usage_message(char program_name[], char arg_suggestion[]);

// STEP 6: this function takes a reference to a C++ style string and then modifies that string, making all letters in the string lowercase
// parameters: reference to a C++ style string, containing uppercase and lowercase values
// return value: void

void lowercaser(string& word);

