// Sarthak N.
#include <iostream>
using namespace std;
const int Max = 20;
const int limit = 5;

class Job
{
public:
    string job_title;
    int priority;
    Job()
    {
        job_title = "-";
        priority = -1;
    }
    Job(string j, int p)
    {
        this->job_title = j;
        this->priority = p;
    }
    // friend class Queue;
};
class Queue // priority queue
{
    Job arr[Max];
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
            cout << "Job not Availabe \n";
            return;
        }
        // Job val(name,p);
        Job *val = new Job(name, p);
        if (front == -1)
        {
            front++;
        }
        rear++;
        int j = rear - 1;
        while (j >= 0 && val->priority < arr[j].priority)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = *val;
    }
    void del()
    {
        
        if (front == -1)
        {
            cout << "No Job entries \n";
        }
        else
        {
            Job item = arr[front];
            front++;
            if (item.priority != -1)
            {
                cout << "___________: Deleted Successfully :___________\n";
                cout << "\t"
                     << "Job title :" << item.job_title << endl;
                cout << "\t"
                     << "Job Priority : " << item.priority << endl;
            }else{
                cout << "No Job entries \n";
            }
        }
    }

    void display_q()
    {
        if (arr[front].priority == -1 || front == -1)
        {
            cout << "\tNo Job entries " << endl;
        }
        else
        {

            cout << "____________________: Selected Job :____________________\n";
            for (int i = front; i <= rear; i++)
            {
                cout << "Job title : " << arr[i].job_title << " \n";
                cout << "Job Priority : " << arr[i].priority << "\n";
            }
        }
    }
};
int main()
{
    char ans;
    //   cout << "Enter Job title : " << endl; string str; cin >> str;
    //   cout << "Enter Job Priority : " << endl; int p; cin >> p;
    Queue q;
    do
    {
        cout << "\n____________: Welcome to Job24.com :____________\n";
        cout << "\n1.Add Job\n2.Delete Job\n3.Display Job\n";
        int o;
        cin >> o;
        if (o == 1)
        {
            cout << "\tApply for Jobs : \n";
            cout << "\t1.Software Enginer\n\t2.Teacher\n\t3.Doctor\n\t4.Web developer\n\t5.Lawyer\n";
            int ch;
            cin >> ch;
            if (ch == 1)
            {
                q.insert_q("Software Enginer", 1);
                cout << "\tApplied Successfully !\n";
            }
            else if (ch == 2)
            {
                q.insert_q("Teacher", 2);
                cout << "\tApplied Successfully !\n";
            }
            else if (ch == 3)
            {
                q.insert_q("Doctor", 3);
                cout << "\tApplied Successfully !\n";
            }
            else if (ch == 4)
            {
                q.insert_q("Web Developer", 4);
                cout << "\tApplied Successfully !\n";
            }
            else if (ch == 5)
            {
                q.insert_q("Lawyer", 5);
                cout << "\tApplied Successfully !\n";
            }
            else
            {
                cout << "Select valid Option\n";
            }
        }
        else if (o == 2)
        {
            q.del();
        }
        else if (o == 3)
        {
            q.display_q();
        }
        cout << "\nDo you want to contiue :(y/n) \n";
        cin >> ans;

    } while (ans == 'y');
    cout << "\tThank You !";
    return 0;
}