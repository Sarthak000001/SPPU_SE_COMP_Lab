#include <iostream>
using namespace std;

class Mystruct
{
    int slot_no;
    float start_time;
    float end_time;
    int status = 0;
    friend class LL;
};

class Node
{
    Node *next;

public:
    Node()
    {
        next = NULL;
    }
    friend class Info;
    class Info
    {
    public:
        string name;
        int slot;
        float starttime;
        float endtime;
    };
    Info info_obj;
    friend class LL;
};

class LL
{
    Mystruct *arr = new Mystruct[8];
    float cnt = 9;
    Node *tail;
    Node *start;

public:
    LL()
    {
        this->tail = NULL;
        this->start = NULL;
    }
    void creatsystem()
    {

        for (int i = 0; i < 8; i++)
        {
            arr[i].slot_no = i + 1;
            arr[i].status = 0;
            if (i % 2 == 0)
            {
                arr[i].start_time = cnt;
                cnt += 0.30;
                arr[i].end_time = cnt;
            }
            else
            {
                arr[i].start_time = cnt;
                cnt += 0.70;
                arr[i].end_time = cnt;
            }
        }
    }
    void display()
    {
        cout << "\tSlot No.    start time       End time       Status\n";
        for (int i = 0; i < 8; i++)
        {
            cout << "\t" << arr[i].slot_no << "\t";
            // cout <<"\t" <<arr[i].start_time << "\t";
            cout << "\t";
            printf("%.2f", (float)arr[i].start_time);
            cout << "\t\t";
            // cout << "\t"<<arr[i].end_time << "\t";
            printf("%.2f", (float)arr[i].end_time);
            cout << "\t\t" << arr[i].status << "\t";
            cout << endl;
        }
        cout << endl;
    }
    void creat_LL(string name, int slotno)
    {
        Node *temp = new Node;

        for (int i = 0; i < 8; i++)
        {
            if (arr[i].slot_no == slotno)
            {
                if (arr[i].status == 0)
                {
                    temp->info_obj.starttime = arr[i].start_time;
                    temp->info_obj.endtime = arr[i].end_time;
                    arr[i].status = 1;
                }
                else
                {
                    cout << "Slot is already Booked \n";
                    return;
                }
            }
        }

        temp->info_obj.name = name;
        temp->info_obj.slot = slotno;

        if (tail == NULL)
        {
            start = temp;
            tail = temp;
            temp->next = NULL;
        }
        else
        {
            tail->next = temp;
            tail = temp;
            temp->next = NULL;
        }
    }
    void cancel(int slotno)
    {
        for (int i = 0; i < 8; i++)
        {
            if (arr[i].slot_no == slotno)
            {
                if (arr[i].status == 1)
                {
                    arr[i].status = 0;
                    cout << "Slot is Cancel is Successfully \n";
                    Node *curr = start;
                    Node *prev = start;
                    while (curr->info_obj.slot != slotno)
                    {
                        prev = curr;
                        curr = curr->next;
                    }
                    if (start == tail)
                    {
                        start = tail = NULL;
                        delete curr;
                        return;
                    }
                    if (curr == start)
                    {
                        start = start->next;
                        delete curr;
                        return;
                    }
                    else if (curr->next == NULL)
                    {  
                        tail = prev;
                        tail->next = NULL;
                        delete curr;
                        return;
                    }
                    prev->next = curr->next;
                    curr->next = NULL;
                    delete curr;
                    return;
                }
                else
                {
                    cout << "Slot is already free \n";
                    return;
                }
            }
        }
    }

    void display_LL()
    {

        Node *p = start;
        while (p != NULL) //Sorting the Linked list
        {
            Node *q = p->next;

            while (q != NULL)
            {
                if (p->info_obj.starttime > q->info_obj.starttime)
                {
                    swap(p->info_obj, q->info_obj);
                }
                q = q->next;
            }
            p = p->next;
        }

        Node *temp = start;
        cout << "\t_________________:Appointment Status:__________________\t\n";
        cout << "\t---\t\t---\t\t---\t\t---";
        while (temp != NULL)
        {
            cout << "\n";
            cout << "\tName : " << temp->info_obj.name << "\n";
            cout << "\tSlot No. : " << temp->info_obj.slot << "\n";
            // cout << "\tStart time : " << temp->info_obj.starttime << "\n";
            cout << "\tStart time :";
            printf("%.2f", (float)temp->info_obj.starttime);
            cout << "\t";
            // cout << "\tEnd time : " << temp->info_obj.endtime << "\n";
            cout << "\tEnd time :";
            printf("%.2f", temp->info_obj.endtime);
            cout << "\n";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    cout << "\n";
    LL obj;
    obj.creatsystem();
    obj.display();

    // obj.creat_LL("Sarthak", 4);
    // obj.display();

    // // obj.cancel(4);
    // // obj.display();
    // obj.creat_LL("Samarth", 3);
    // obj.creat_LL("Samarth", 6);
    // obj.creat_LL("Samarth", 1);
    // obj.creat_LL("Samarth", 2);
    // obj.display_LL();
    while (true)
    {
        cout << "\t______________________:Appointment________________________\t\n";
        cout << "\n\tEnter 1:Display Slot Detail\n\tEnter 2:Booked Slot\n\tEnter 3:Cancel Booked Slot\n\tEnter 4:To check the Booked Slot Status\n\tEnter 5:Exit\n";
        int ch;
        cin >> ch;
        if (ch == 1)
        {
            obj.display();
        }
        else if (ch == 2)
        {
            cout << "Enter your Name : \n";
            cin.ignore(1);
            string name; getline(cin,name);
            // cin >> name;
            cout << "Enter the Slot Number :\n";
            int slot;
            cin >> slot;
            if (slot >= 1 && slot <= 8)
            {

                obj.creat_LL(name, slot);
            }
            else
            {
                cout << "Enter the valid Slot Number \n";
            }
        }
        else if (ch == 3)
        {
            cout << "Enter the Slot Number : \n";
            int s;
            cin >> s;
            obj.cancel(s);
        }
        else if (ch == 4)
        {
            obj.display_LL();
        }
        else if (ch == 5)
        {
            break;
        }
    }
    cout << "\t\tThank You !\t\n";
    return 0;
}