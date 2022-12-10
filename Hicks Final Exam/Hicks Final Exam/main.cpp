#include <iostream>
#include <string>

/*
	Citations
	1) https://stackoverflow.com/questions/4880447/how-to-check-if-a-linked-list-is-full-using-java#:~:text=There%27s%20no%20such%20concept%20as%20a%20%22full%22%20linked,personally%20keep%20a%20count%20with%20the%20linked%20list.
	2) https://stackoverflow.com/questions/3928935/size-of-linked-list-in-c-function
	3) https://www.geeksforgeeks.org/stack-set-4-evaluation-postfix-expression/
	4) https://www.geeksforgeeks.org/stack-set-2-infix-to-postfix/
*/

int prec(char input);					// Finds operator precendce (Modified code from geeksforgeeks.org)
std::string convert(std::string input);	// Converts Infix to postfix (First link in citation)
int postfix(std::string input);			// Postfix Expression Evaluation

int main() {
	std::string equ;	// Equation
	std::cout << "\n\tEnter mathematical expression: " << std::endl << "\t";
	std::cin >> equ;
	std::cout << "\t" << convert(equ) << " " << std::endl;
	std::cout << "\t" << postfix(equ)  << " " << std::endl;
	return 0;
}