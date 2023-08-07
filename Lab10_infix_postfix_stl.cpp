#include <iostream>
#include <string>
#include<queue>

using namespace std;

int rank_(char x)
{
    if (x == '+' || x == '-')
    {
        return 0;
    }

    if (x == '*' || x == '/')
    {
        return 1;
    }

    if (x == '^')
    {
        return 2;
    }

    return -1;
}

int IsOperator(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^')
    {
        return 1;
    }

    return 0;
}

int IsOperand(char x)
{
    if(x>=65 && x<=90)
    {
        return 1;
    }

    if(x>=97 && x<=122)
    {
        return 1;
    }

    if(x>=49 && x<=57)
    {
        return 1;
    }

    return 0;
}

int IsInfix(string infix)
{
    int count=0,i=0;

    while(i<infix.size())
    {
        if(IsOperand(infix[i])==1 && IsOperator(infix[i+1])==1 && IsOperand(infix[i+2])==1)
        {
            count++;
        }

        i=i+2;
    }

    //cout<<count<<endl;

    if(count==infix.size()/2)
    return 1;

    else
    return 0;
}

bool Higher_Rank(char x1, char x2)
{
    if (rank_(x1) > rank_(x2))
    {
        return true;
    }

    else
    {
        return false;
    }
}

queue <char> que1, que2;

void Push(char x)
{
    // cout<<"l132 = "<<x<<endl;
    if (que1.empty())
    {
        que1.push(x);

        while (!que2.empty())
        {
            que1.push(que2.front());
            que2.pop();
        }
    }

    else if (que2.empty())
    {
        que2.push(x);

        while (!que1.empty())
        {
            que2.push(que1.front());
            que1.pop();
        }
    }
}

void Pop()
{
    if (que1.empty())
    {
        que2.pop();
    }

    else if (que2.empty())
    {
        que1.pop();
    }
}

void infix_to_postfix(string infix)
{
    string postfix;

    for (int i = 0; i < infix.size(); i++)
    {
        if (IsOperator(infix[i]) == 1)
        {
            if (que1.empty())
            {
                if (que2.empty())
                {
                    Push(infix[i]);
                }

                else if (Higher_Rank(infix[i], que2.front()))
                {
                    Push(infix[i]);
                }

                else
                {
                    while (!Higher_Rank(infix[i], que2.front()))
                    {
                        postfix = postfix + que2.front();
                        Pop();
                    }

                    Push(infix[i]);
                }
            }

            else if (que2.empty())
            {
                if (que1.empty())
                {
                    Push(infix[i]);
                }

                else if (Higher_Rank(infix[i], que1.front()))
                {
                    Push(infix[i]);
                }

                else
                {
                    while (!Higher_Rank(infix[i], que1.front()))
                    {
                        postfix = postfix + que1.front();
                        Pop();
                    }

                    Push(infix[i]);
                }
            }
        }

        else
        {
            postfix = postfix + infix[i];
        }
    }

    while (!que1.empty())
    {
        postfix = postfix + que1.front();
        Pop();
    }

    while (!que2.empty())
    {
        postfix = postfix + que2.front();
        Pop();
    }

    cout << "Postfix Expression is : " << postfix << endl;
}

int main()
{
    int choice;

    string infix;

    for (int i = 0; choice != 4; i++)
    {

        cout << " Enter " << endl
             << " 1. To Enter Infix Expression " << endl
             << " 2. To Print Infix Expression " << endl
             << " 3. To Print Postfix Expression " << endl
             << " 4. To Exit " << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:

            cout << " Enter the Infix Expression " << endl;
            cin >> infix;

            try
            {
                if(IsInfix(infix)==0)
                {
                    throw infix;
                }
            }

            catch(...)
            {
                cout<<" Invalid Infix Expression "<<endl;
            }
            break;

        case 2:
            cout << " Infix Expression is : " << infix << endl;
            break;

        case 3:
            try
            {
                if(IsInfix(infix)==0)
                {
                    throw infix;
                }
                infix_to_postfix(infix);
            }

            catch(...)
            {
                cout<<"Entered Infix Expression is INVALID "<<endl;
            }
            break;
        }
    }

    return 0;
}