/*
    Name : Sarthak Nirgude
    Class: SE1
    Batch: G1
    Roll Number : 21156
    Subject : OOP Lab
*/

#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;

class india
{
public:
    map<string, float> mp;

    void display()
    {

        mp["Maharashtra"] = 12.3;
        mp["Uttar-Pradhesh"] = 23.5;
        mp["Bihar"] = 13.4;
        mp["Rajasthan"] = 5.4;
        mp["Gujarat"] = 11;
        mp["Odisha"] = 6.7;
        mp["Kerala"] = 5.4;
        map<string, float>::iterator ptr;
        for (ptr = mp.begin(); ptr != mp.end(); ptr++)
        {
            cout << "The Population of " << ptr->first << " is " << ptr->second << " Millions\n";
        }
        cout << "\n";
    }
    void display_single()
    {
        string str;
        cout << "Enter the name of the state : ";
        cin >> str;
        if (mp.find(str) != mp.end())
        {
            cout << "The Population of " << str << " is " << mp[str] << " Millions \n";
        }
        else
        {
            cout << "The " << str << " is not present data base \n";
        }
    }
};

int main()
{

    int t;
    india obj;
    while (true)
    {
        cout << "Enter 1:To get the Population of all states\n";
        cout << "Enter 2:To get the Population of the state\n";
        cout << "Enter 3:EXIT\n";
        cout << "Enter your choice :\n";
        cin >> t;
        if (t == 1)
        {
            obj.display();
        }
        else if (t == 2)
        {
            obj.display_single();
        }
        else if (t == 3)
        {
            break;
        }
        else
        {
            cout << "Invalid Input\n";
        }
    }

    return 0;
}