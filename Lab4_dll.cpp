#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node()
    {
        data = 0;
        next = NULL;
        prev = NULL;
    }
};

class dll
{
private:
    node *head = NULL;

public:
    void insert(int x);

    node *delete_node(int n, node *ptr);

    void display(node *head)
    {
        node *temp1 = head;
        while (temp1 != NULL)
        {
            cout << temp1->data << " ";
            temp1 = temp1->next;
        }
    }

    node *merge(node *head1, node *head2);

    node *GetHead()
    {
        return head;
    }

    void SetData(node *x)
    {
        head = x;
    }
};

void dll ::insert(int x)
{
    if (head == NULL)
    {
        head = new node;
        head->data = x;
        head->next = NULL;
        head->prev = NULL;
    }

    else
    {
        node *temp = head;
        node *newnode = new node;
        node *prevnode = NULL;
        newnode->data = x;

        while (x > temp->data && temp->next != NULL)
        {
            prevnode = temp;
            // cout<<"prevnode = "<<prevnode->data;
            temp = temp->next;
        }

        // cout<< " current = "<<temp->data << " x = " <<x<<endl;

        if (prevnode == NULL)
        {
            if (x < head->data)
            {
                newnode->next = head;
                newnode->prev = NULL;
                head->prev = newnode;
                head = newnode;
                temp = head;
            }

            else
            {
                newnode->prev = head;
                head->next = newnode;
                newnode->next = NULL;
            }
        }

        else
        {
            if (temp->data < x)
            {

                newnode->prev = temp;
                temp->next = newnode;
            }

            else
            {
                newnode->next = temp;
                newnode->prev = prevnode;
                prevnode->next = newnode;
                temp->prev = newnode;
                // cout<<newnode->data<<" "<<newnode->prev->data<<" "<<newnode->next->data<<"x = "<<x<<endl;
            }
        }
    }
}

node *dll ::delete_node(int n, node *ptr)
{
    node *temp = ptr;
    node *temp1 = ptr;

    if (n == 1 && ptr->next != NULL)
    {
        ptr = temp->next;
        ptr->prev = NULL;
        delete temp;
    }

    else if (n == 1 && ptr->next == NULL)
    {
        ptr = NULL;
        delete temp;
    }

    else
    {
        for (int i = 0; i < n - 1; i++)
        {
            temp = temp->next;
        }

        if (temp->next != NULL)
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }

        else
        {
            temp->prev->next = NULL;
            delete temp;
        }
    }

    return ptr;
}

node *dll ::merge(node *head1, node *head2)
{
    dll list3;

    node *head3 = NULL;
    node *temp1 = head1;
    node *temp2 = head2;

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data <= temp2->data)
        {
            list3.insert(temp1->data);
            temp1 = temp1->next;
        }

        else if (temp1->data > temp2->data)
        {
            list3.insert(temp2->data);
            temp2 = temp2->next;
        }
    }

    while (temp2 != NULL)
    {
        list3.insert(temp2->data);
        temp2 = temp2->next;
    }

    while (temp1 != NULL)
    {
        list3.insert(temp1->data);
        temp1 = temp1->next;
    }

    head3 = list3.GetHead();

    return head3;
}

int main()
{
    int choice, ch, n;
    dll list1;
    dll list2;
    dll list3;
    node *head11;
    node *head12;

    for (int i = 0; choice != 5; i++)
    {
        cout << " Enter " << endl
             << " 1. To Insert an element into DLL " << endl
             << " 2. To delete an element from DLL " << endl
             << " 3. To Display the DLL " << endl
             << " 4. To Merge two DLL's " << endl
             << " 5. To EXIT " << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << " Enter " << endl
                 << " 1. To insert the element into first DLL " << endl
                 << " 2. To insert the element into second DLL " << endl;
            cin >> ch;

            if (ch == 1)
            {
                cout << " Enter the element to be inserted " << endl;
                cin >> n;

                list1.insert(n);
            }

            if (ch == 2)
            {
                cout << " Enter the element to be inserted " << endl;
                cin >> n;

                list2.insert(n);
            }
            break;

        case 2:
            cout << " Enter " << endl
                 << " 1. To delete an element from the first DLL " << endl
                 << " 2. To delete an element from the second DLL " << endl;
            cin >> ch;

            if (ch == 1)
            {
                cout << " Enter the position of the node to be deleted " << endl;
                cin >> n;

                node *head = list1.GetHead();

                if (head == NULL)
                {
                    cout << " Linked List is Empty " << endl;
                }

                else
                {
                    if (n > 0)
                    {
                        head11 = list1.delete_node(n, head);
                        list1.SetData(head11);
                    }

                    else
                    {
                        cout << " Invalid Input " << endl;
                    }
                }
            }

            if (ch == 2)
            {
                cout << " Enter the position of the node to be deleted " << endl;
                cin >> n;

                node *head_a = list2.GetHead();

                if (head_a == NULL)
                {
                    cout << " Linked List is Empty " << endl;
                }

                else
                {
                    if (n > 0)
                    {
                        head12 = list2.delete_node(n, head_a);
                        list2.SetData(head12);
                    }

                    else
                    {
                        cout << " Invalid Input " << endl;
                    }
                }
            }
            break;

        case 3:
            cout << " Enter " << endl
                 << " 1. To display the first DLL " << endl
                 << " 2. To display the second DLL " << endl;
            cin >> ch;

            if (ch == 1)
            {
                node *head = list1.GetHead();
                if (head == NULL)
                {
                    cout << " The list is empty " << endl;
                }
                list1.display(head);
                cout << endl;
            }

            if (ch == 2)
            {
                node *head = list2.GetHead();
                if (head == NULL)
                {
                    cout << " The list is empty " << endl;
                }
                list2.display(head);
                cout << endl;
            }
            break;

        case 4:
            node *head1 = list1.GetHead();
            node *head2 = list2.GetHead();
            node *ans = list3.merge(head1, head2);
            cout << "LIST 1 : ";
            list1.display(head1);
            cout << endl;
            cout << "LIST 2 : ";
            list2.display(head2);
            cout << endl;
            cout << "MERGED LIST : ";
            list3.display(ans);
            cout << endl;
            break;
        }
    }

    return (0);
}

/*node *ptr1 = head1;
    node *ptr2 = head2;
    node *res = new node;
    node *ptr3 = res;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->data < ptr2->data)
        {
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }

        else
        {
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }

        ptr3 = ptr3->next;
    }

    while (ptr1 != NULL)
    {
        ptr3->next = ptr1;
        ptr1 = ptr1->next;
        ptr3 = ptr3->next;
    }

    while (ptr2 != NULL)
    {
        ptr3->next = ptr2;
        ptr2 = ptr2->next;
        ptr3 = ptr3->next;
    }

    return res->next;*/