// Sarthak N.
#include <iostream>
using namespace std;
const int Max = 20;
const int limit = 5;

template <class T, class S>
class item
{
public:
    S item_title;
    T priority;
    item()
    {                 
        item_title = " - ";
        priority = -1;
    }
    item(S j, T p)
    {
        this->item_title = j;
        this->priority = p;
    }
    friend class Queue;
    bool operator<=(item &obj)
    {
        //overloading the operator <= 
        if (obj.priority > priority)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

class Queue
{
    item<int, string> arr[Max];
    int front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }
    void insert_q(string name, int p)
    {
        if (rear == Max - 1)
        {
            cout << "overflow...! \n";
            return;
        }
        // item val(name,p);
        item<int, string> val(name, p);
        if (front == -1)
        {
            front++;
        }
        rear++;

        int j = rear - 1;
        while (j >= 0 && val <= arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = val;
    }
    void del()
    {
        if (front == -1)
        {
            cout << "No item entries \n";
            return;
        }
        item item = arr[front];
        front++;
        cout << "___________: Deleted Successfully :___________\n";
        cout << "\t"
             << "item title :" << item.item_title << endl;
        cout << "\t"
             << "item Priority : " << item.priority << endl;
    }
    void display_q()
    {
        if (arr[front].priority == -1 || front == -1)
        {
            cout << "\tNo item entries " << endl;
        }
        else
        {

            cout << "____________________: Selected item :____________________\n";
            cout << endl;
            cout << " item title  \t"
                 << "item Priority : "
                 << "\n";
            for (int i = front; i <= rear; i++)
            {
                cout << " " << arr[i].item_title << "             " << arr[i].priority << "\n";
            }
        }
    }
};
int main()
{
    Queue q;
    while (true)
    {
        cout << "\n____________: Welcome to item24.com :____________\n";
        cout << "\n\t\t1.Add the item \n\t\t2.Delete item\n\t\t3.Display item\n\t\t4.EXIT...\n";
        int o;
        cout << "Enter Choice : \n";
        cin >> o;
        if (o == 1)
        {
            string s;
            cout << "Enter the name of item : " << endl;
            // cin >> s;
            cin.ignore();
            getline(cin,s);
            int n;
            cout << "Enter its priority : " << endl;
            cin >> n;
            q.insert_q(s, n);
            cout << "\nSelected Successfully !\n";
            //     cout << "\nSelect the Brand : \n";
            //     cout << "\t1.Apple\n\t2.Black Berry\n\t3.Redmi\n\t4.Realme\n\t5.Nokia\n";
            //     int ch;
            //     cin >> ch;
            //     if (ch == 1)
            //     {
            //         q.insert_q("Apple", 1);
            //         cout << "\nSelected Successfully !\n";
            //     }
            //     else if (ch == 2)
            //     {
            //         q.insert_q("Black Berry", 2);
            //         cout << "\nSelected Successfully !\n";
            //     }
            //     else if (ch == 30)
            //     {
            //         q.insert_q("Redmi", 3);
            //         cout << "\nSelected Successfully !\n";
            //     }
            //     else if (ch == 4)
            //     {
            //         q.insert_q("Realme", 4);
            //         cout << "\nSelected Successfully !\n";
            //     }
            //     else if (ch == 5)
            //     {
            //         q.insert_q("Nokia", 5);
            //         cout << "\nSelected Successfully !\n";
            //     }
            //     else
            //     {
            //         cout << "Select valid Option\n";
            //     }
        }
        else if (o == 2)
        {
            q.del();
        }
        else if (o == 3)
        {
            q.display_q();
        }
        else if (o == 4)
        {
            cout << "\t--->Thanks for using program <---\n\n" << endl;
            break;
        }
        else
        {
            cout << "\t\tINVALID CHOICE...!\n" << endl;
        }
    }

    return 0;
}