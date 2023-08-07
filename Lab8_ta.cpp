#include <iostream>
#include <string>

using namespace std;

class student
{
protected:
    string name;
    string roll_number;

public:
    virtual void display() = 0;

    string GetRoll()
    {
        return roll_number;
    }
};

class pg_student : virtual public student
{
protected:
    string course1;
    string course2;
    string course3;

public:
    void display()
    {
        cout << " Name : " << name << endl;
        cout << " Roll Number : " << roll_number << endl;
        cout << " Course 1 : " << course1 << endl;
        cout << " Course 2 : " << course2 << endl;
        cout << " Course 3 : " << course3 << endl;
    }
};

class research_student : virtual public student
{
protected:
    string course;
    string research_area;

public:
    void display()
    {
        cout << " Name : " << name << endl;
        cout << " Roll Number : " << roll_number << endl;
        cout << " Course 1 : " << course << endl;
        cout << " Research Area : " << research_area << endl;
    }
};

class TA : public pg_student, research_student
{
protected:
    string course_assigned;
    string role;

public:
    void SetDetails(string n, string rn, string r, string ca, string c1, string c2, string c3)
    {
        name = n;
        roll_number = rn;
        role = r;
        course_assigned = ca;
        course1 = c1;
        course2 = c2;
        course3 = c3;
    }

    void SetDetails(string n, string rn, string r, string ca, string c, string ra)
    {
        name = n;
        roll_number = rn;
        role = r;
        course_assigned = ca;
        course = c;
        research_area = ra;
    }

    void display()
    {
        cout << " Course Assigned : " << course_assigned << endl;

        if (role == "pg")
        {
            cout << " Role : PG Student " << endl;
            pg_student ::display();
        }

        if (role == "research")
        {
            cout << " Role : Research Student " << endl;
            research_student ::display();
        }
    }
};

int main()
{
    int choice, ch,flag=0;
    string name, roll_number, course1, course2, course3, course_assigned, course, research_area;
    string get;

    TA ta[150];
    int a = 0;

    for (int i = 0; choice != 3; i++)
    {

        cout << " Enter " << endl
             << " 1. To Set Details " << endl
             << " 2. To Display " << endl
             << " 3. To Exit " << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << " Enter name " << endl;
            getline(cin >> ws, name);

            cout << " Enter Roll Number " << endl;
            getline(cin >> ws, roll_number);

            cout << " Enter role " << endl
                 << " 1. If PG student " << endl
                 << " 2. If research student " << endl;

            cin >> ch;

            if (ch == 1)
            {
                cout << " Enter Course Assigned " << endl;
                getline(cin >> ws, course_assigned);

                cout << " Enter Course 1 " << endl;
                getline(cin >> ws, course1);

                cout << " Enter Course 2 " << endl;
                getline(cin >> ws, course2);

                cout << " Enter Course 3 " << endl;
                getline(cin >> ws, course3);

                if (course1 == course2 || course2 == course3 || course3 == course1)
                {
                    cout << " All the three courses must be different " << endl;
                }

                else if (course_assigned == course1 || course_assigned == course2 || course_assigned == course3)
                {
                    cout << " Course Assigned cannot be same as the given 3 courses " << endl;
                }

                else
                {
                    flag=0;

                    for (int i = 0; i < a; i++)
                    {
                        get = ta[i].GetRoll();

                        if (get == roll_number)
                        {
                            flag = 1;
                            break;
                        }
                    }

                    if (flag == 1)
                    {
                        cout << " Entered Roll Number exists " << endl;
                        break;
                    }

                    else
                    {
                        ta[a].SetDetails(name, roll_number, "pg", course_assigned, course1, course2, course3);
                        a++;
                    }

                    // cout<<" a = "<<a<<endl;
                }
            }

            if (ch == 2)
            {
                cout << " Enter Course Assigned " << endl;
                getline(cin >> ws, course_assigned);

                cout << " Enter Course " << endl;
                getline(cin >> ws, course);

                cout << " Enter Research Area " << endl;
                getline(cin >> ws, research_area);

                if (course == course_assigned)
                {
                    cout << " Course Assigned cannot be same as the given course " << endl;
                }

                else
                {
                    flag=0;

                    for (int i = 0; i < a; i++)
                    {
                        get = ta[i].GetRoll();

                        if (get == roll_number)
                        {
                            flag = 1;
                            break;
                        }
                    }

                    if (flag == 1)
                    {
                        cout << " Entered Roll Number exists " << endl;
                        break;
                    }

                    else
                    {
                        ta[a].SetDetails(name, roll_number, "research", course_assigned, course, research_area);
                        a++;
                    }
                    // cout<<" a = "<<a<<endl;
                }
            }
            break;

        case 2:
            cout << " Enter the roll number " << endl;
            getline(cin >> ws, roll_number);

            flag=0;

            for (int i = 0; i < a; i++)
            {
                get = ta[i].GetRoll();

                if (get == roll_number)
                {
                    flag = 1;
                    ta[i].display();
                    break;
                }
            }

            if (flag == 0)
            {
                cout << " Invalid Roll Number " << endl;
            }
            break;
        }
    }
    return 0;
}