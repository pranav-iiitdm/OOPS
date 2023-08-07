#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *next;

    node()
    {
        data = 0;
        next = NULL;
    }
};

class circular_list
{
    node *head = NULL;
    node *tail = NULL;

public:
    void insert(int x);
    void insert(int x, int pos);
    void display(node *head1, node *tail1);
    void delete_node();
    void delete_node(node *head1);
    void delete_node(node *head1, int pos);
    int search(node *head1, int x);

    node *GetHead()
    {
        return head;
    }

    node *GetTail()
    {
        return tail;
    }
};

void circular_list ::insert(int x)
{
    if (head == NULL)
    {
        head = new node;
        head->data = x;
        head->next = head;

        tail = head;
    }

    else
    {
        node *newnode = new node;
        node *temp = head;
        newnode->data = x;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        newnode->next = head;
        temp->next = newnode;
        tail = newnode;
    }
}

void circular_list ::insert(int x, int pos)
{
    if (pos == 1)
    {
        node *newnode = new node;
        newnode->data = x;
        newnode->next = head;

        head = newnode;
        tail->next = head;
    }

    if (pos > 1)
    {
        node *temp = head;
        node *newnode = new node;

        newnode->data = x;

        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        if (head == tail)
        {
            head->next = newnode;
            tail = newnode;
            tail->next = head;
        }

        else
        {
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
}

void circular_list ::display(node *head1, node *tail1)
{
    node *temp = head1->next;
    cout << head1->data << " ";

    while (temp != head1)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void circular_list ::delete_node()
{
    if (tail == head)
    {
        tail = NULL;
        head = NULL;
    }

    else
    {
        node *temp = head;

        head = head->next;
        tail->next = head;

        delete temp;
    }
}

void circular_list ::delete_node(node *head1)
{
    if (tail == head)
    {
        tail = NULL;
        head = NULL;
    }

    else
    {
        node *temp = head1;
        node *prev;

        while (temp->next != head1)
        {
            prev = temp;
            temp = temp->next;
        }

        tail = prev;
        tail->next = head;

        delete temp;
    }
}

void circular_list ::delete_node(node *head1, int pos)
{
    if (tail == head)
    {
        tail = NULL;
        head = NULL;
    }

    else
    {
        node *temp = head1;
        node *prev = NULL;

        for (int i = 0; i < pos - 1; i++)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;

        delete temp;
    }
}

int circular_list ::search(node *head1, int x)
{
    node *temp = head1->next;

    if (x == head1->data)
    {
        return 1;
    }

    while (temp != head1)
    {
        if (temp->data == x)
            return 1;

        temp = temp->next;
    }

    return 0;
}

int main()
{
    int choice, ch, x, count = 0, pos, sech;

    circular_list cll;
    node *head1;

    for (int i = 0; choice != 5; i++)
    {
        cout << " Enter " << endl
             << " 1. To insert an element " << endl
             << " 2. To delete an element " << endl
             << " 3. To search for an element " << endl
             << " 4. To display the list " << endl
             << " 5. To EXIT " << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
            head1 = cll.GetHead();

            if (head1 == NULL)
            {
                cout << " Currently the list is empty " << endl;
                cout << " Enter the element to be inserted " << endl;
                cin >> x;

                cll.insert(x);

                count++;
            }

            else
            {
                cout << " Enter " << endl
                     << " 1. To insert at beginning " << endl
                     << " 2. To insert at end " << endl
                     << " 3. To insert at any middle position " << endl;

                cin >> ch;

                if (ch == 1)
                {
                    cout << " Enter the element to be inserted " << endl;
                    cin >> x;

                    cll.insert(x, 1);
                }

                if (ch == 2)
                {
                    cout << " Enter the element to be inserted " << endl;
                    cin >> x;
                    cll.insert(x);
                }

                if (ch == 3)
                {
                    cout << " Enter the element to be inserted " << endl;
                    cin >> x;

                    cout << " Enter the position at which the element has to be inserted " << endl;
                    cin >> pos;

                    if (pos == count + 1)
                    {
                        cll.insert(x);
                    }

                    else
                    {
                        if (pos < count)
                        {
                            cll.insert(x, pos);
                        }

                        if (pos > count || pos < 0)
                        {
                            cout << " Invalid Input " << endl;
                        }
                    }
                }

                count++;
                // cout << "count = " << count << endl;
            }
            break;

        case 2:
            head1 = cll.GetHead();

            if (head1 == NULL)
            {
                cout << " The list is empty " << endl;
            }

            else
            {
                cout << " Enter " << endl
                     << " 1. To delete from beginning " << endl
                     << " 2. To delete from end " << endl
                     << " 3. To delete from any middle position " << endl;

                cin >> ch;

                if (ch == 1)
                {
                    cll.delete_node();
                }

                if (ch == 2)
                {
                    node *head11 = cll.GetHead();
                    cll.delete_node(head11);
                }

                if (ch == 3)
                {
                    cout << " Enter the position of the element that has to be deleted " << endl;
                    cin >> pos;

                    if (pos > count)
                    {
                        cout << " Invalid Input " << endl;
                    }

                    else
                    {
                        node *head11 = cll.GetHead();
                        cll.delete_node(head11, pos);
                    }
                }

                count--;
            }
            break;

        case 3:
            head1 = cll.GetHead();

            if (head1 == NULL)
            {
                cout << " The list is empty " << endl;
            }

            else
            {
                cout << " Enter the element to be searched " << endl;
                cin >> sech;

                node *head2 = cll.GetHead();
                int z = cll.search(head2, sech);

                if (z == 1)
                {
                    cout << " Entered element is present in the list " << endl;
                }

                if (z == 0)
                {
                    cout << " Entered element is not present in the list " << endl;
                }
            }
            break;

        case 4:
            head1 = cll.GetHead();

            if (head1 == NULL)
            {
                cout << " The list is empty " << endl;
            }

            else
            {
                node *head2 = cll.GetHead();
                node *tail2 = cll.GetTail();
                cll.display(head2, tail2);
            }
            break;
        }
    }

    return 0;
}