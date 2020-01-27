#include <string>
#include <stack>

using namespace std;

//Calculates a postfix expression with integer operands using a stack
//The expression is represented using an array of strings
//Each string is either an operand or operator symbol
//Operator symbols:
//"+" addition
//"-" subtraction
//"*" multiplication
//"/" divison
//"%" remainder
//Example expression: "8", "5", "-" evaluates to a result of 3:
//1: push 8, 2: push 5,
//3: "-"-> pop top two values, earlier value is the left-side operand: 8 - 5
//The result of the operation (8-5) is 3, push 3 onto stack
//After evaluation of the expression, the final result should be
//the only value on the stack, return 0 if the stack is
//non-empty after popping the result
//Return 0 if expression is zero-length or if there are insufficient operands
//for an operation
//The STL Stack class can be used
//To easily convert a numeric string to an int you may use the stoi() function
//which takes a string as a parameter and returns a string
bool validOpsCheck( string check[], int length )	{
	
	int numCount = 0;
	int opCount = 0;
	for(int i = 0; i < length; i++)	{
		if(check[i].find_first_of("1234567890") != string::npos)
			numCount++;
		else
			opCount++;
	}

	if(opCount != (numCount - 1))
		return false;
	else
		return true;
}

int calculatePostfixExpression(string expression[], int length)
{
	if(length == 0)
		return 0;
	
	if(!validOpsCheck(expression, length))
		return 0;
	
	stack<int> calc;

	for(int i = 0; i < length; i++)	{
		if(expression[i].find_first_of("1234567890") != string::npos)
			calc.push( stoi(expression[i] ));
		
		else {
			int num1 = calc.top();
			calc.pop();
			int num2 = calc.top();
			calc.pop();

			string op = expression[i];
			
			if(op.compare("+") == 0)
				calc.push( num2 + num1 );
			else if(op.compare("-") == 0)
				calc.push( num2 - num1 );
			else if(op.compare("*") == 0)
				calc.push( num2 * num1 );
			else if(op.compare("/") == 0)
				calc.push( num2 / num1 );
			else
				calc.push( num2 % num1 );
		}
	}
	return calc.top();
}
