#include <iostream>

using namespace std;

class time1
{
    int hours;
    int minutes;
    int seconds;

public:
    time1()
    {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }

    time1(int hrs, int min, int secs)
    {
        hours = hrs;
        minutes = min;
        seconds = secs;
    }

    ~time1() {}

    void Set(int hrs, int min, int secs)
    {
        hours = hrs;
        minutes = min;
        seconds = secs;
    }

    void get(int *hour, int *mins, int *sec)
    {
        *hour = hours;
        *mins = minutes;
        *sec = seconds;
    }
};

void menu(time1 t1);
void standard_time(int hour, int mins, int sec);
void universal_time(int hour, int mins, int sec);
void IST(int hour, int mins, int sec);
void PST(int hour, int mins, int sec);

int main()
{
    int cho, hrs, min, secs;

    cout << "Enter" << endl
         << "0 to create a clock " << endl
         << "1 to create a clock and set time" << endl;
    cin >> cho;

    if (cho == 0)
    {
        time1 time;
        menu(time);
    }

    else if (cho == 1)
    {
        cout << "Enter the time in hours , minutes , seconds in 24 HOUR FORMAT " << endl;
        cin >> hrs;
        cin >> min;
        cin >> secs;
        time1 time(hrs, min, secs);
        menu(time);
    }

    else
    {
        cout << "INVALID INPUT" << endl;
    }

    return (0);
}

void menu(time1 t1)
{
    int hrs, min, secs, choice;
    for (int i = 0; choice != 6; i++)
    {
        cout << "Enter" << endl
             << "1. To Set Time" << endl
             << "2. To Print Standard Time (AM or PM)" << endl
             << "3. To Print Universal Time (24 hours)" << endl
             << "4. To Print Indian Standard Time (24 hours)" << endl
             << "5. To Print Pacific Standard Time (AM or PM)" << endl
             << "6. To EXIT" << endl;

        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter the time in hours , minutes , seconds in 24 HOUR FORMAT " << endl;
            cin >> hrs;
            cin >> min;
            cin >> secs;
            if (hrs == 24)
                hrs = 0;
            else if (hrs > 24 || min > 60 || secs > 60)
            {
                cout << "INVALID INPUT" << endl;
                break;
            }
            else if (hrs < 0 || min < 0 || secs < 0)
            {
                cout << "INVALID INPUT" << endl;
                break;
            }

            else
            {
                t1.Set(hrs, min, secs);
            }
        }

        if (choice == 2)
        {
            t1.get(&hrs, &min, &secs);
            standard_time(hrs, min, secs);
        }

        if (choice == 3)
        {
            t1.get(&hrs, &min, &secs);
            universal_time(hrs, min, secs);
        }

        if (choice == 4)
        {
            t1.get(&hrs, &min, &secs);
            IST(hrs, min, secs);
        }

        if (choice == 5)
        {
            t1.get(&hrs, &min, &secs);
            PST(hrs, min, secs);
        }
    }
}

void standard_time(int hour, int mins, int sec)
{
    if (hour > 12)
    {
        hour = hour - 12;
        cout << "THE STANDARD TIME FOR THE ENTERED TIME IS " << endl;
        cout << hour << " : " << mins << " : " << sec << " PM " << endl;
    }
    else
    {
        cout << "THE STANDARD TIME FOR THE ENTERED TIME IS " << endl;
        cout << hour << " : " << mins << " : " << sec << " AM " << endl;
    }
}

void universal_time(int hour, int mins, int sec)
{
    cout << "THE UNIVERSAL TIME FOR THE ENTERED TIME IS " << endl;
    cout << hour << " : " << mins << " : " << sec << " hours " << endl;
}

void IST(int hour, int mins, int sec)
{
    hour = hour + 5;
    hour = hour % 24;

    if (mins >= 30)
    {
        hour = hour + 1;
    }

    mins = mins + 30;
    mins = mins % 60;

    cout << "THE INDIAN STANDARD TIME FOR THE ENTERED TIME IS " << endl;
    cout << hour << " : " << mins << " : " << sec << " hours " << endl;
}

void PST(int hour, int mins, int sec)
{
    hour = hour - 8;
    hour = hour % 24;

    if (hour > 12)
    {
        hour = hour - 12;
        cout << "THE PACIFIC STANDARD TIME FOR THE ENTERED TIME IS " << endl;
        cout << hour << " : " << mins << " : " << sec << " PM " << endl;
    }
    else
    {
        cout << "THE PACIFIC STANDARD TIME FOR THE ENTERED TIME IS " << endl;
        cout << hour << " : " << mins << " : " << sec << " AM " << endl;
    }
}
