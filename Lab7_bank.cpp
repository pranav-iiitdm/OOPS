#include <iostream>
#include <string>

using namespace std;

class bank
{
protected:
    int acc_no;
    int acc;
    string name;
    float amount;

public:
    bank()
    {
        amount = 0.0;
        acc = 0;
    }

    void SetAmount(float amo)
    {
        amount = amo;
    }

    void open_acc(int acc_no, string name)
    {
        this->acc_no = acc_no;
        this->name = name;
    }

    void acc_type(int acc)
    {
        this->acc = acc;
    }

    void credit(float amo)
    {
        amount += amo;
    }

    int GetAccType()
    {
        return acc;
    }

    void debit(float amo)
    {
        amount -= amo;
    }

    int GetAmount()
    {
        return amount;
    }

    int GetAccount()
    {
        return acc_no;
    }

    string GetName()
    {
        return name;
    }
};

class savings : public bank
{
    float interest_rate;

public:
    savings()
    {
        interest_rate = 2.5;
    }

    void update_rate(float rate)
    {
        interest_rate = rate;
    }

    float GetRate()
    {
        return interest_rate;
    }
};

class checking : public bank
{
    float charge_per_transact;

public:
    checking()
    {
        charge_per_transact = 100.0;
    }

    void update_charge(float charge_per_transact)
    {
        this->charge_per_transact = charge_per_transact;
    }

    float GetFee()
    {
        return charge_per_transact;
    }
};

int search_acc(int x, int c, int a[])
{
    for (int i = 0; i < c; i++)
    {
        if (x == a[i])
        {
            return 1;
        }
    }

    return 0;
}

int main()
{
    int choice, ch, a = 0, b = 0, c = 0, d = 0, e = 0, get, j, k;

    int acc[200];
    int accs[200];
    int accc[200];
    savings acc_a[100];
    checking acc_b[100];

    string name;
    int acc_no, acco;
    float cdt, dbt, rate, fee, amo;

    for (int i = 0; i < 200; i++)
    {
        acc[i] = 0;
    }

    for (int i = 0; choice != 10; i++)
    {
        cout << " Enter " << endl
             << " 1. To Open Account " << endl
             << " 2. To Credit " << endl
             << " 3. To Debit " << endl
             << " 4. To Change / Update Interest Rate " << endl
             << " 5. To Calculate Interest " << endl
             << " 6. To Calculate and Update Interest " << endl
             << " 7. To Change / Update Fee Amount " << endl
             << " 8. To Print Checking Fee " << endl
             << " 9. To Search Customer Details " << endl
             << " 10. To Exit " << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << " Enter name " << endl;
            getline(cin >> ws, name);

            cout << " Enter unique ID number " << endl;
            cin >> acc_no;

            /*if(search_acc(acc_no,c,acc)==1)
            {
                cout<<" Entered account number already exists "<<endl;
                break;
            }*/

            acc[c] = acc_no;
            acc_a[a].open_acc(acc_no, name);
            acc_b[b].open_acc(acc_no, name);

            a++;
            b++;
            c++;

            cout << " Enter " << endl
                 << " 1. For savings account (Account number should start with '1') " << endl
                 << " 2. For checkings account (Account number should start with '2') " << endl;
            cin >> ch;

            if (ch == 1)
            {
                cout << " Enter unique ID number " << endl;
                cin >> acc_no;

                if (acc_no > 0)
                {
                    for (j = 0; j < a; j++)
                    {
                        get = acc_a[j].GetAccount();

                        if (get == acc_no)
                        {
                            break;
                        }
                    }

                    if (search_acc(acc_no, c, acc) == 1 && acc_a[j].GetAccType() != 0)
                    {
                        cout << " Account already exists " << endl;
                        break;
                    }

                    if (search_acc(acc_no, c, acc) == 0 && acc_a[j].GetAccType() == 0)
                    {
                        cout << " Invalid ID " << endl;
                        break;
                    }

                    cout << " Enter account number " << endl;
                    cin >> acco;

                    if (acco > 0)
                    {
                        if (acco / 100 != 1 || acco / 1000 != 0)
                        {
                            cout << " Enter valid account number " << endl;
                        }

                        else if (search_acc(acco, d, accs) == 1)
                        {
                            cout << " Entered account number already exists " << endl;
                        }

                        else //(acc_no/100==1 && search_acc(acc_no,c,acc)==0)
                        {
                            for (j = 0; j < a; j++)
                            {
                                get = acc_a[j].GetAccount();

                                if (get == acc_no)
                                {
                                    break;
                                }
                            }

                            acc_a[j].acc_type(acco);
                            accs[d] = acco;

                            d++;
                        }
                    }

                    else
                    {
                        cout << " Invalid Input " << endl;
                    }
                }

                else
                {
                    cout << " Invalid Input " << endl;
                }
            }

            if (ch == 2)
            {
                cout << " Enter unique ID number " << endl;
                cin >> acc_no;

                if (acc_no > 0)
                {
                    for (k = 0; k < b; k++)
                    {
                        get = acc_b[k].GetAccount();

                        if (get == acc_no)
                        {
                            break;
                        }
                    }

                    if (search_acc(acc_no, c, acc) == 1 && acc_b[k].GetAccType() != 0)
                    {
                        cout << " Account already exists " << endl;
                        break;
                    }

                    if (search_acc(acc_no, c, acc) == 0 && acc_b[k].GetAccType() == 0)
                    {
                        cout << " Invalid ID " << endl;
                        break;
                    }

                    cout << " Enter account number " << endl;
                    cin >> acco;

                    if (acco > 0)
                    {
                        if (acco / 100 != 2 || acco / 1000 != 0)
                        {
                            cout << " Enter valid account number " << endl;
                        }

                        else if (search_acc(acco, e, accc) == 1)
                        {
                            cout << " Entered account number already exists " << endl;
                        }

                        else //(acc_no/100==1 && search_acc(acc_no,c,acc)==0)
                        {
                            for (k = 0; k < b; k++)
                            {
                                get = acc_b[k].GetAccount();

                                if (get == acc_no)
                                {
                                    break;
                                }
                            }

                            acc_b[k].acc_type(acco);
                            accc[e] = acco;

                            e++;
                        }
                    }

                    else
                    {
                        cout << " Invalid Input " << endl;
                    }
                }

                else
                {
                    cout << " Invalid Input " << endl;
                }
            }
            break;

        case 2:
            cout << " Enter unique ID number " << endl;
            cin >> acc_no;

            if (acc_no > 0)
            {
                if (search_acc(acc_no, c, acc) == 0)
                {
                    cout << " Entered ID is invalid " << endl;
                }

                else
                {
                    cout << " Enter " << endl
                         << " 1. For savings account " << endl
                         << " 2. For checkings account " << endl;
                    cin >> ch;

                    if (ch == 1)
                    {
                        for (j = 0; j < a; j++)
                        {
                            get = acc_a[j].GetAccount();

                            if (get == acc_no)
                            {
                                break;
                            }
                        }

                        cout << " Enter the amount to be deposited " << endl;
                        cin >> cdt;

                        if (acc_a[j].GetAccType() != 0)
                        {
                            acc_a[j].credit(cdt);
                        }

                        else
                        {
                            cout << " Invalid Account " << endl;
                        }
                    }

                    if (ch == 2)
                    {
                        for (k = 0; k < b; j++)
                        {
                            get = acc_b[k].GetAccount();

                            if (get == acc_no)
                            {
                                break;
                            }
                        }

                        cout << " Enter the amount to be deposited " << endl;
                        cin >> cdt;

                        if (acc_b[k].GetAccType() != 0)
                        {
                            acc_b[k].credit(cdt - acc_b[k].GetFee());
                        }

                        else
                        {
                            cout << " Invalid Account " << endl;
                        }
                    }
                }
            }

            else
            {
                cout << " Invalid Input " << endl;
            }
            break;

        case 3:
            cout << " Enter unique ID number " << endl;
            cin >> acc_no;

            if (acc_no > 0)
            {
                if (search_acc(acc_no, c, acc) == 0)
                {
                    cout << " Entered ID is invalid " << endl;
                }

                else
                {
                    cout << " Enter " << endl
                         << " 1. For savings account " << endl
                         << " 2. For checkings account " << endl;
                    cin >> ch;

                    if (ch == 1)
                    {
                        for (j = 0; j < a; j++)
                        {
                            get = acc_a[j].GetAccount();

                            if (get == acc_no)
                            {
                                break;
                            }
                        }

                        cout << " Enter the amount to be debited " << endl;
                        cin >> dbt;

                        if (acc_a[j].GetAmount() >= dbt && acc_a[j].GetAccType() != 0)
                        {
                            acc_a[j].debit(dbt);
                        }

                        if (acc_a[j].GetAmount() < dbt)
                        {
                            cout << " Insuffiecient balance " << endl;
                        }

                        if (acc_a[j].GetAccType() == 0)
                        {
                            cout << " Invalid Account " << endl;
                        }
                    }

                    if (ch == 2)
                    {
                        for (k = 0; k < b; k++)
                        {
                            get = acc_b[k].GetAccount();

                            if (get == acc_no)
                            {
                                break;
                            }
                        }

                        cout << " Enter the amount to be debited " << endl;
                        cin >> dbt;

                        if (acc_b[k].GetAmount() >= dbt && acc_b[k].GetAccType() != 0)
                        {
                            acc_b[k].debit(dbt + acc_b[k].GetFee());
                        }

                        if (acc_b[k].GetAmount() < dbt)
                        {
                            cout << " Insufficient Balance " << endl;
                        }

                        if (acc_b[k].GetAccType() == 0)
                        {
                            cout << " Invalid Account " << endl;
                        }
                    }
                }
            }

            else
            {
                cout << " Invalid Input " << endl;
            }
            break;

        case 4:
            cout << " Current interest rate is  : " << acc_a[0].GetRate() << endl;

            cout << " Enter the new interest rate " << endl;
            cin >> rate;

            if (rate > 0)
            {
                for (j = 0; j < a; j++)
                {
                    acc_a[j].update_rate(rate);
                }
            }

            else
            {
                cout << " Invalid input " << endl;
            }
            break;

        case 5:
            cout << " Enter unique ID number " << endl;
            cin >> acc_no;

            if (acc_no > 0)
            {
                if (search_acc(acc_no, c, acc) == 0)
                {
                    cout << " Entered ID is invalid " << endl;
                }

                else
                {
                    for (j = 0; j < a; j++)
                    {
                        get = acc_a[j].GetAccount();

                        if (get == acc_no)
                        {
                            break;
                        }
                    }

                    if (acc_a[j].GetAccType() != 0)
                    {
                        amo = acc_a[j].GetAmount();
                        rate = acc_a[j].GetRate();

                        cout << " Account Balance is : " << amo << endl;
                        cout << " Interest for that amount is : " << (amo * rate) / 100 << endl;
                    }

                    else
                    {
                        cout << " Invalid Account " << endl;
                    }
                }
            }

            else
            {
                cout << " Invalid Input " << endl;
            }
            break;

        case 6:
            cout << " Enter unique ID number " << endl;
            cin >> acc_no;

            if (acc_no > 0)
            {
                if (search_acc(acc_no, c, acc) == 0)
                {
                    cout << " Entered ID is invalid " << endl;
                }

                else
                {
                    for (j = 0; j < a; j++)
                    {
                        get = acc_a[j].GetAccount();

                        if (get == acc_no)
                        {
                            break;
                        }
                    }

                    if (acc_a[j].GetAccType() != 0)
                    {
                        amo = acc_a[j].GetAmount();
                        rate = acc_a[j].GetRate();
                        cdt = (amo * rate) / 100;
                        acc_a[j].credit(cdt);

                        cout << " Account Balance is : " << amo << endl;
                        cout << " Interest for that amount is : " << (amo * rate) / 100 << endl;
                        cout << " Account Balance after crediting interest : " << acc_a[j].GetAmount() << endl;
                    }

                    else
                    {
                        cout << " Invalid Account " << endl;
                    }
                }
            }

            else
            {
                cout << " Invalid Input " << endl;
            }
            break;

        case 7:
            cout << " Current fee per transaction is : " << acc_b[0].GetFee() << endl;
            cout << " Enter the new fee amount " << endl;
            cin >> fee;

            if (fee > 0)
            {
                for (k = 0; k < b; k++)
                {
                    acc_b[k].update_charge(fee);
                }
            }

            else
            {
                cout << " Invalid input " << endl;
            }
            break;

        case 8:
            cout << " Enter unique ID number " << endl;
            cin >> acc_no;

            if (acc_no > 0)
            {
                if (search_acc(acc_no, c, acc) == 0)
                {
                    cout << " Entered ID is invalid " << endl;
                }

                else
                {
                    for (k = 0; k < b; k++)
                    {
                        get = acc_b[k].GetAccount();

                        if (get == acc_no)
                        {
                            break;
                        }
                    }

                    if (acc_b[k].GetAccType() != 0)
                    {
                        cout << " Checking Fee per Transaction is : " << acc_b[k].GetFee() << endl;
                    }

                    else
                    {
                        cout << " Invalid Account " << endl;
                    }
                }
            }

            else
            {
                cout << " Invalid Input " << endl;
            }
            break;

        case 9:
            cout << " Enter unique ID number " << endl;
            cin >> acc_no;

            if (search_acc(acc_no, c, acc) == 0)
            {
                cout << " Entered ID is invalid " << endl;
            }

            else
            {
                for (j = 0; j < a; j++)
                {
                    get = acc_a[j].GetAccount();

                    if (get == acc_no)
                    {
                        break;
                    }
                }

                if (acc_a[j].GetAccType() != 0)
                {
                    cout << " Name : " << acc_a[j].GetName() << endl;
                    cout << " Account type : Savings" << endl;
                    cout << " Account balance : " << acc_a[j].GetAmount() << endl;
                    cout << " Interest rate : " << acc_a[j].GetRate() << endl;
                }

                for (k = 0; k < b; k++)
                {
                    get = acc_b[k].GetAccount();

                    if (get == acc_no)
                    {
                        break;
                    }
                }

                if (acc_b[k].GetAccType() != 0)
                {
                    cout << " Name : " << acc_b[k].GetName() << endl;
                    cout << " Account type : Checkings" << endl;
                    cout << " Account balance : " << acc_b[k].GetAmount() << endl;
                    cout << " Fee per transaction : " << acc_b[k].GetFee() << endl;
                }
            }
            break;
        }
    }
    return 0;
}

/*int search_acc(int x,int c,int a[c])
{
    for(int i=0;i<c;i++)
    {
        if(x==a[i])
        {
            return 1;
        }
    }

    return 0;
}*/