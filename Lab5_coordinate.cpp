#include <iostream>
#include <math.h>

using namespace std;

class coordinate
{
    float xnum;
    float ynum;

public:
    coordinate()
    {
        xnum = 0;
        ynum = 0;
    }

    void SetData(float xnum, float ynum)
    {
        this->xnum = xnum;
        this->ynum = ynum;
    }

    float GetX();
    float GetY();

    coordinate operator-(coordinate cor)
    {
        coordinate ans;

        ans.xnum = xnum - cor.xnum;
        ans.ynum = ynum - cor.ynum;

        return ans;
    }

    coordinate operator+(coordinate cor)
    {
        coordinate ans;

        ans.xnum = xnum + cor.ynum;

        return ans;
    }

    coordinate operator*(coordinate cor)
    {
        coordinate ans;

        ans.xnum = xnum * cor.xnum;
        ans.ynum = ynum * cor.ynum;

        return ans;
    }

    void operator!()
    {
        if (xnum < 0)
        {
            this->xnum = -xnum;
        }

        if (ynum < 0)
        {
            this->ynum = -ynum;
        }
    }

    float DisplayLength(coordinate a, coordinate b, int flag);
    int CheckRight(float a, float b, float c);
};

inline float coordinate ::GetX()
{
    return xnum;
}

inline float coordinate ::GetY()
{
    return ynum;
}

float coordinate ::DisplayLength(coordinate a, coordinate b, int flag)
{
    coordinate ans;

    ans = a - b;
    ans = ans * ans;
    ans = ans + ans;

    float x = ans.xnum;

    float side = x;
    x = sqrt(x);

    if (flag == 1)
    {
        cout << " Distance between ( " << a.xnum << " , " << a.ynum << " ) and ( " << b.xnum << " , " << b.ynum << " ) is " << x << endl;
    }

    return side;
}

int coordinate ::CheckRight(float a, float b, float c)
{
    float x, y, z;

    x = max(a, max(b, c));

    if (x == a)
    {
        y = b;
        z = c;
    }

    else if (x == b)
    {
        y = a;
        z = c;
    }

    else
    {
        y = b;
        z = a;
    }

    if (x == (y + z))
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

int main()
{
    int choice, check, flag = 1;
    float xco, yco;
    coordinate cor1, cor2, cor3;

    for (int i = 0; choice != 5; i++)
    {
        cout << " Enter " << endl
             << " 1. To Set Point " << endl
             << " 2. To Display Point " << endl
             << " 3. To Display Length Between Two Points " << endl
             << " 4. To Check if the entered three pointss form a Right Triangle " << endl
             << " 5. To Exit " << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << " Enter the coordinates for the first point " << endl;
            cin >> xco >> yco;

            cor1.SetData(xco, yco);
            !cor1;

            cout << " Enter the coordinates for the second point " << endl;
            cin >> xco >> yco;

            cor2.SetData(xco, yco);
            !cor2;

            cout << " Enter the coordinates for the third point " << endl;
            cin >> xco >> yco;

            cor3.SetData(xco, yco);
            !cor3;
            break;

        case 2:
            float x, y;
            x = cor1.GetX();
            y = cor1.GetY();

            cout << " The coordinates of first point are ( " << x << " , " << y << " ) " << endl;

            x = cor2.GetX();
            y = cor2.GetY();

            cout << " The coordinates of second point are ( " << x << " , " << y << " ) " << endl;

            x = cor3.GetX();
            y = cor3.GetY();

            cout << " The coordinates of third point are ( " << x << " , " << y << " ) " << endl;
            break;

        case 3:
            cor1.DisplayLength(cor1, cor2, 1);
            cor2.DisplayLength(cor2, cor3, 1);
            cor3.DisplayLength(cor3, cor1, 1);
            break;

        case 4:
            float a = cor1.DisplayLength(cor1, cor2, 0);
            float b = cor2.DisplayLength(cor2, cor3, 0);
            float c = cor3.DisplayLength(cor3, cor1, 0);
            // cout<<a<<b<<c;

            if (a == b && b == c && a == c)
            {
                cout << " It is NOT a Right Angled Triangle " << endl;
            }

            else
            {
                check = cor1.CheckRight(a, b, c);

                if (check == 1)
                {
                    cout << " It is a Right Angled Triangle " << endl;
                }

                else if (check == 0)
                {
                    cout << " It is NOT a Right Angled Triangle " << endl;
                }
            }
            break;
        }
    }

    return 0;
}