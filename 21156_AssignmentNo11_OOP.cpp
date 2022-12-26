//21156_Sarthak_Nirgude
//Batch : G1
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#define ll long long
using namespace std;

class Info
{
public:
    string name, dob;
    int rollno;
    friend class database;
};

bool compare(Info obj1, Info obj2)
{
    return obj1.rollno < obj2.rollno;
}

class database
{
public:
    vector<Info> arr;

    void create()
    {
        Info s;
        cout << "Enter the Name :\n";
        cin >> s.name;
        cout << "Enter the Date of birth :\n";
        cin >> s.dob;
        cout << "Enter the Roll No. : \n";
        cin >> s.rollno;
        arr.push_back(s);
    }
    void display()
    {
        vector<Info>::iterator ptr;
        cout << "Name \t Date of Birth \t Roll No.\t\n";
        for (ptr = arr.begin(); ptr != arr.end(); ptr++)
        {
            cout << ptr->name << "\t\t" << ptr->dob << "\t   " << ptr->rollno << "\n";
        }
        cout << endl;
    }

    void Sort_data()
    {

        sort(arr.begin(), arr.end(), compare);
    }
    void Search()
    {
        cout << "Enter the Name to Search : \n";
        string x;
        cin >> x;
        vector<Info>::iterator ptr;
        bool flag = false;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i].name == x)
            {
                flag = true;
            }
        }
        if (flag)
        {
            cout << "The " << x << " is present in the data base\n";
        }
        else
        {
            cout << "The " << x << " is not register in the record "
                 << " \n";
        }
    }
};
int main()
{
    database obj;

    while (true)
    {
        cout << "Enter 1:Insert\nEnter 2:Display \nEnter 3:Sort \nEnter 4:Search \nEnter 5:Exit\n";
        int c;
        cin >> c;
        if (c == 1)
        {
            cout << "Enter the Number of Student :\n";
            int n;
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                obj.create();
            }
        }
        else if (c == 2)
        {
            obj.display();
        }
        else if (c == 3)
        {
            obj.Sort_data();
            cout << "Data After Sorting....\n";
            obj.display();
        }
        else if (c == 4)
        {
            obj.Search();
        }
        else if (c == 5)
        {
            cout << "Thank You...!!\n";
            break;
        }
        else
        {
            cout << "Invalid Input\n";
        }
    }

    return 0;
}