#include <iostream>
#include <string>
#include "stack.h"

#ifndef FINAL_CPP
#define FINAL_CPP

int prec(char input) {
	if (input == '/' || input == '*' || input == '%')
		return 2; // If input is /,*, or %, then return highest precedence
	else if (input == '+' || input == '-')
		return 1; // If input is + or -, then return 1 for precendce
	else 
		return 0;// Otherwise, return lowest precedence
}

std::string convert(std::string equ) {
	Stack stack;
	std::string output;					// Postfix output

	for (int i = 0; i < equ.length(); i++) { // For as long more input.
		char c = equ[i];
		if (c >= '0' && c <= '9')		// If the operand is valid
		{
			output += c;				// Set it to output
		}
		else if (c == '(')				// If char is left bracket
		{
			stack.push('(');			// Put left bracket in stack
		}
		else if (c == ')')				// If the char is right bracket
		{
			while (stack.top() != '(')	// and while the top of the stack is not the left bracket
			{
				output += stack.top();	// Set the output to whatever operator must be on top of the stack
				stack.pop();			// and pop the operator from the stack
			}
			stack.pop();				// If the top of the stack IS '(' then pop it
		}
		else
		{
			// While the stack precedence >= input precedence
			while (!stack.empty() && prec(stack.top()) >= prec(equ[i]))
			{
				output += stack.top();	// Add the top of the stack to the output
				stack.pop();			// Pop the stack
			}
			stack.push(c);				// Push input on to stack
		}
	}
	// Add all the remaining elements to the stack and delete them
	while (!stack.empty())		// While the stack isn't empty
	{
		output += stack.top();		// Add the stack to the output
		stack.pop();				// Pop remaining elements
	}
	return output;
}

int postfix(std::string equ) {
	Stack stack;
	// Using the postfix expression of user input
	std::string exp = convert(equ);
	for (int i = 0; i < exp.length(); i++) {// For as long more input.
		char c = exp[i];
		// If char is is a digit, convert to int and store it.
		if (isdigit(c))
			stack.push((int)(c-'0'));
		else { // If its an operator perform operation
			// Get the right operand stack
			int top1 = stack.top(); stack.pop();
			// Get the left operand stack
			int top2 = stack.top(); stack.pop();
			// Performing operation
			int result = 0;
			if (c == '+')
				result = top2 + top1;
			else if (c == '-')
				result = top2 - top1;
			else if (c == '*')
				result = top2 * top1;
			else if (c == '/')
				result = top2 / top1;
			stack.push(result);
		}
	}
	return stack.top();
}
#endif // !FINAL_CPP