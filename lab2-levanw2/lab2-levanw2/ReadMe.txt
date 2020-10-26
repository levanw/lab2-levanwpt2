Author: Will LeVan

CSE 332S - Lab 2

Using an input file provided by the user, this program reads the file to determine the dimensions of a game board and then reads in information about a piece, including its color, name, display, and horizontal and vertical location on the game board.
After reading all this information, the program is able to resolve some inconsistencies with input information, like blank spacing and capitalization. Finally, the function prints out a game board with the pieces included based on the input file.

Possible program return values:
enum for these can be found in declarations.h
0 - success
1 - incorrect_usage
2 - dimension_extract_failed
3 - read_line_failed
4 - no_formed_pieces
5 - file_unread
6 - dimensions_incorrect

Different array indices that are relevant to this program:
enum for these can be found in declarations.h
0 - program_name
1 - input_file_name
2 - expected_argc

Difficulties encountered:

1. A really big issue I faced for a while was experiencing 50-150 post-build errors about undeclared identifiers. Feedback from students on Piazza and TAs during Office Hours helped me resolve this issue by being more critical and selective with what I #include in each file.
2. Another error I faced was within my lowercasing function. I initially used functions such as isalpha() and tolower() to make the conversion, but after realizing that wasn't sufficient, I resolved to making the changes based on ASCII values.
3. After printing my board, I would get stuck in an infinite loop because as I descended the rows, I would eventually get to zero but would then call row-- and since row was an unsigned int, that would mess up the loop. Accounting for this in my for-loop declaration and in the for-loop block resolved the issue.

Input Trials

Running the program with mogoku.txt performed as expected, and so did tic-tac-toe.txt. Initially, only the X's in tic-tac-toe were printed out but that occurred because the O's were of color blue, which my program doesn't print. After changing blue to black in the text file, both X's and O's were printed.
Next, I tried running the program where the color names were not all uppercase (such as rEd and Black). This behaved as expected because these changes in capitalization was accounted for in my code and the program printed out the complete board still.
Another trial I did was removing an element of a piece, such as its display, color, or coordinates. As expected, the function still printed out the complete boare except for these pieces that were altered.
Next, I edited the text file by adding more and more spaces between elements, which because of the use of input string streams in the function, had no effect on the final result, which was expected.
