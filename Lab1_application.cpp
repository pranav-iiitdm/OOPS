#include <iostream>
#include <stdlib.h>
#include "stack.h"

using namespace std;

void digit_in_text(stack stk2)
{
	int dig;

	if (stk2.isempty())
	{
		cout << "THE STACK IS EMPTY" << endl;
	}

	else
	{
		cout << "THE ENTERED NUMBER IN TEXT IS " << endl;
		while (stk2.isempty() != true)
		{
			dig = stk2.pop();

			if (dig == 0)
				cout << " Zero ";
			if (dig == 1)
				cout << " One ";
			if (dig == 2)
				cout << " Two ";
			if (dig == 3)
				cout << " Three ";
			if (dig == 4)
				cout << " Four ";
			if (dig == 5)
				cout << " Five ";
			if (dig == 6)
				cout << " Six ";
			if (dig == 7)
				cout << " Seven ";
			if (dig == 8)
				cout << " Eight ";
			if (dig == 9)
				cout << " Nine ";
		}
	}
}

void reverse(stack stk2)
{
	stack stk3;

	if (stk2.isempty())
		cout << "THE STACK IS EMPTY " << endl;

	else
	{
		cout << "THE REVERSE OF THE ENETERED NUMBER IS " << endl;
		while (stk2.isempty() != true)
		{
			stk3.push(stk2.pop());
		}

		while (stk3.isempty() != true)
		{
			cout << stk3.pop();
		}
	}
}

void palindrome(stack stk2)
{
	int flag = 0;
	stack stk4, stk5;
	stk4 = stk2;

	if (stk2.isempty())
		cout << "STACK IS EMPTY " << endl;

	else
	{
		while (stk2.isempty() != true)
		{
			stk5.push(stk2.pop());
		}

		while (stk4.isempty() != true)
		{
			if (stk4.pop() != stk5.pop())
			{
				flag = 1;
			}
		}
		if (flag == 1)
			cout << "ENTERED NUMBER IS NOT PALINDROME" << endl;
		else
			cout << "ENTERED NUMBER IS PALINDROME" << endl;
	}
}

int main()
{
	int choice, num, popv, dig, k, input[k], num1;
	stack stk1;
	k = 0;

	for (int i = 0; choice != 5; i++)
	{
		cout << "Enter \n 1. To Get Number \n 2. To Digit in Text \n 3. To Reverse \n 4. To Palindrome \n 5. To EXIT " << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter the number" << endl;
			cin >> num;

			if (stk1.isempty() == true)
			{
				for (int i = num; i > 0; i = i / 10)
				{
					stk1.push(i % 10);
				}
			}
			else
			{
				while (stk1.isempty() != true)
				{
					popv = stk1.pop();
				}

				for (int i = num; i > 0; i = i / 10)
				{
					stk1.push(i % 10);
				}
			}

			break;
		case 2:
			digit_in_text(stk1);
			cout << endl;
			break;
		case 3:
			reverse(stk1);
			cout << endl;
			break;
		case 4:
			palindrome(stk1);
			break;
		}
	}

	return (0);
}
