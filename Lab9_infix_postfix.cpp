#include <iostream>
#include <string>

using namespace std;

class node
{
public:
    char data;
    node *next = NULL;
};

class queue
{
    node *front;
    node *rear;

public:
    queue()
    {
        front = NULL;
        rear = NULL;
    }

    void enqueue(char x);
    void dequeue();
    char peek();

    int IsEmpty()
    {
        if (front == NULL)
        {
            return 1;
        }

        return 0;
    }

    node *GetHead()
    {
        return front;
    }
};

void queue ::enqueue(char x)
{
    node *newnode = new node;

    newnode->data = x;
    newnode->next = NULL;

    if (front)
    {
        rear->next = newnode;
        rear = newnode;
    }

    else
    {
        front = newnode;
        rear = newnode;
    }
}

void queue ::dequeue()
{
    node *newnode = front;

    try
    {
        if (front == NULL)
        {
            throw front;
        }
        front = front->next;
        delete newnode;
        newnode = NULL;
    }

    catch (...)
    {
        cout << " Queue Is Empty [ UNDERFLOW ] " << endl;
    }
}

char queue ::peek()
{
    if (front != NULL)
    {
        return front->data;
    }
    else
    {
        return '0';
    }
}

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

queue que1, que2;

void push(char x)
{
    // cout<<"l132 = "<<x<<endl;
    if (que1.IsEmpty() == 1)
    {
        que1.enqueue(x);

        while (que2.IsEmpty() != 1)
        {
            que1.enqueue(que2.peek());
            que2.dequeue();
        }
    }

    else if (que2.IsEmpty() == 1)
    {
        que2.enqueue(x);

        while (que1.IsEmpty() != 1)
        {
            que2.enqueue(que1.peek());
            que1.dequeue();
        }
    }
}

void pop()
{
    if (que1.IsEmpty() == 1)
    {
        que2.dequeue();
    }

    else if (que2.IsEmpty() == 1)
    {
        que1.dequeue();
    }
}

void infix_to_postfix(string infix)
{
    string postfix;

    for (int i = 0; i < infix.size(); i++)
    {
        if (IsOperator(infix[i]) == 1)
        {
            if (que1.IsEmpty() == 1)
            {
                if (que2.IsEmpty() == 1)
                {
                    push(infix[i]);
                }

                else if (Higher_Rank(infix[i], que2.peek()))
                {
                    push(infix[i]);
                }

                else
                {
                    while (!Higher_Rank(infix[i], que2.peek()))
                    {
                        postfix = postfix + que2.peek();
                        pop();
                    }

                    push(infix[i]);
                }
            }

            else if (que2.IsEmpty() == 1)
            {
                if (que1.IsEmpty() == 1)
                {
                    push(infix[i]);
                }

                else if (Higher_Rank(infix[i], que1.peek()))
                {
                    push(infix[i]);
                }

                else
                {
                    while (!Higher_Rank(infix[i], que1.peek()))
                    {
                        postfix = postfix + que1.peek();
                        pop();
                    }

                    push(infix[i]);
                }
            }
        }

        else
        {
            postfix = postfix + infix[i];
        }
    }

    while (que1.IsEmpty() != 1)
    {
        postfix = postfix + que1.peek();
        pop();
    }

    while (que2.IsEmpty() != 1)
    {
        postfix = postfix + que2.peek();
        pop();
    }

    cout << "Postfix Expression is : " << postfix << endl;
}

int main()
{
    int choice;

    string infix;

    queue que1;

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