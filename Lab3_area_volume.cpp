#include <iostream>
#include <math.h>

using namespace std;

class volume;

class area
{
    int side;
    int length;
    int breadth;
    int radius;

public:
    area()
    {
        side = 1;
        length = 1;
        breadth = 1;
        radius = 1;
    }

    void SetDataSquare(int side = 1)
    {
        this->side = side;
    }

    void SetDataRectangle(int length = 1, int breadth = 1)
    {
        this->length = length;
        this->breadth = breadth;
    }

    void SetDataCircle(float radius = 1)
    {
        this->radius = radius;
    }

    int getData()
    {
        return (side);
    }

    int square();
    int rectangle();
    float circle();

    friend int cube(area, volume);
    friend int cuboid(area, volume);

    friend void CompareCube(int, area);
    friend void CompareCuboid(int, area, volume);
    friend void CompareSphere(int, area);
};

class volume
{
    int height;

public:
    volume()
    {
        height = 1;
    }

    void SetData(int height = 1)
    {
        this->height = height;
    }

    friend int cube(area, volume);
    friend int cuboid(area, volume);
    float sphere();

    friend void CompareCube(int, area);
    friend void CompareCuboid(int, area, volume);
    friend void CompareSphere(int, area);
};

inline int area ::square()
{
    return side * side;
}

inline int area ::rectangle()
{
    return length * breadth;
}

inline float area ::circle()
{
    return (3.14 * pow((radius), 2));
}

inline int cube(area a, volume v)
{
    if (a.side != 1)
        return (v.height * v.height * v.height);

    else
        return (a.side * a.side * a.side);
}

inline int cuboid(area a, volume v)
{
    return (a.breadth * a.length * v.height);
}

inline float volume ::sphere()
{
    return ((1.33) * 3.14 * pow(height, 3));
}

void CompareCube(int a, area obj)
{
    int vol = obj.side * obj.side * obj.side;

    if (a < vol)
    {
        cout << "The volume of first cube is greater than second cube " << endl;
    }

    if (a == vol)
    {
        cout << "The volume of first and second cube are same " << endl;
    }

    if (a > vol)
    {
        cout << "The volume of the second cube is greater than first cube " << endl;
    }
}

void CompareCuboid(int a, area obj, volume obj1)
{
    int vol = obj.length * obj.breadth * obj1.height;

    if (a < vol)
    {
        cout << "The volume of first cuboid is greater than second cube " << endl;
    }

    if (a > vol)
    {
        cout << "The volume of second cuboid is greater than first cube " << endl;
    }

    if (a == vol)
    {
        cout << "The volume of both cuboids are same " << endl;
    }
}

void CompareSphere(int a, area obj)
{
    int vol = 1.33 * 3.14 * pow(obj.radius, 3);

    if (a < vol)
    {
        cout << "The volume of first sphere is greater than second sphere " << endl;
    }

    if (a == vol)
    {
        cout << "The volume of first and second sphere is same " << endl;
    }

    if (a > vol)
    {
        cout << "The volume of the second sphere is greater than first sphere " << endl;
    }
}

int main()
{
    area a1, a2, a3;
    volume v1, v2, v3;
    int choice;
    int sd, l, b, r;
    int sdv, h, vr;
    int as, ar, vcube, vcubo;
    float ac, vsph;
    int ch;
    int a, b1, c;

    for (int i = 0; choice != 10; i++)
    {
        cout << "Enter " << endl
             << "1. To Calculate Area of Square " << endl
             << "2. To Calculate Area of Rectangle " << endl
             << "3. To Calculate Area of Circle " << endl
             << "4. To Calculate Volume of Cube " << endl
             << "5. To Calculate Volume of Cuboid " << endl
             << "6. To Calculate Volume of Sphere " << endl
             << "7. To Compare Cubes " << endl
             << "8. To Compare Cuboids " << endl
             << "9. To Compare Spheres " << endl
             << "10.To EXIT" << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter 0 to give the input or 1 to go with the default input " << endl;
            cin >> ch;

            if (ch == 0)
            {
                cout << "Enter the side of the square " << endl;
                cin >> sd;

                if (sd > 0)
                {
                    a1.SetDataSquare(sd);

                    as = a1.square();
                    cout << "The Area of Square is " << as << endl;
                }

                else
                {
                    cout << "INVALID INPUT " << endl;
                    break;
                }
            }

            if (ch == 1)
            {
                a1.SetDataSquare();
                as = a1.square();
                cout << "The Area of Square is " << as << endl;
            }
            break;

        case 2:
            cout << "Enter 0 to give the input or 1 to go with the default input " << endl;
            cin >> ch;

            if (ch == 0)
            {
                cout << "Enter the length and breadth of the rectangle " << endl;
                cin >> l;
                cin >> b;

                if (l > 0 && b > 0)
                {
                    a2.SetDataRectangle(l, b);

                    ar = a2.rectangle();
                    cout << "The Area of Rectangle is " << ar << endl;
                }

                else
                {
                    cout << "INVALID INPUT " << endl;
                    break;
                }
            }

            if (ch == 1)
            {
                a2.SetDataSquare();
                ar = a2.rectangle();
                cout << "The Area of Rectangle is " << ar << endl;
            }
            break;

        case 3:
            cout << "Enter 0 to give the input or 1 to go with the default input " << endl;
            cin >> ch;

            if (ch == 0)
            {
                cout << "Enter the radius of the circle " << endl;
                cin >> r;

                if (r > 0)
                {
                    a3.SetDataCircle(r);

                    ac = a3.circle();
                    cout << "The Area of Circle is " << ac << endl;
                }

                else
                {
                    cout << "INVALID INPUT " << endl;
                    break;
                }
            }

            if (ch == 1)
            {
                a3.SetDataCircle();
                ac = a3.circle();
                cout << "The Area of Circle is " << ac << endl;
            }
            break;

        case 4:
            cout << "Enter 0 to give the input or 1 to go with the default input " << endl;
            cin >> ch;

            if (ch == 0)
            {
                cout << "Enter the side of the cube " << endl;
                cin >> sdv;

                if (sdv > 0)
                {
                    v1.SetData(sdv);
                    vcube = cube(a1, v1);
                    cout << "The volume of the cube is " << vcube << endl;
                }

                else
                {
                    cout << "INVALID INPUT " << endl;
                    break;
                }
            }

            if (ch == 1)
            {
                v1.SetData();
                vcube = cube(a1, v1);
                cout << "The volume of the cube is " << vcube << endl;
            }
            break;

        case 5:
            cout << "Enter 0 to give the input or 1 to go with the default input " << endl;
            cin >> ch;

            if (ch == 0)
            {
                cout << "Enter the height of the cuboid " << endl;
                cin >> h;

                if (h > 0)
                {
                    v2.SetData(h);
                    vcubo = cuboid(a2, v2);

                    cout << "The volume of the cuboid is " << vcubo << endl;
                }

                else
                {
                    cout << "INVALID INPUT " << endl;
                    break;
                }
            }

            if (ch == 1)
            {
                v2.SetData();
                vcubo = cuboid(a2, v2);

                cout << "The volume of the cuboid is " << vcubo << endl;
            }
            break;

        case 6:
            cout << "Enter 0 to give the input or 1 to go with the default input " << endl;
            cin >> ch;

            if (ch == 0)
            {
                cout << "Enter the radius of the sphere " << endl;
                cin >> vr;

                if (vr > 0)
                {
                    v3.SetData(vr);
                    vsph = v3.sphere();

                    cout << "The volume of the sphere is " << vsph << endl;
                }

                else
                {
                    cout << "INVALID INPUT " << endl;
                    break;
                }
            }

            if (ch == 1)
            {
                v3.SetData();
                vsph = v3.sphere();

                cout << "The volume of the sphere is " << vsph << endl;
            }
            break;

        case 7:
            cout << "Enter the side of the cube " << endl;
            cin >> a;

            if (a > 0)
            {
                CompareCube(a * a * a, a1);
            }

            else
            {
                cout << "INVALID INPUT " << endl;
                break;
            }
            break;

        case 8:
            cout << "Enter the dimension of the cuboid " << endl;
            cin >> a >> b1 >> c;

            if (a > 0 && b1 > 0 && c > 0)
            {
                CompareCuboid(a * b1 * c, a2, v2);
            }

            else
            {
                cout << "INVALID INPUT " << endl;
                break;
            }
            break;

        case 9:
            cout << "Enter the radius of the first sphere " << endl;
            cin >> a;

            if (a > 0)
            {
                CompareSphere((1.33 * 3.14 * pow(a, 3)), a3);
            }

            else
            {
                cout << "INVALID INPUT " << endl;
                break;
            }
            break;
        }
    }
    return 0;
}