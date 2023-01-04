#include <iostream>
// #include <bits/stdc++.h>
using namespace std;
const int Max = 5;

class circularQ
{
    int qc[Max];
    int front;
    int rear;

public:
    circularQ() : front(-1), rear(0) {}
    void init()
    {
        for (int i = 0; i < Max; i++)
        {
            qc[i] = 0;
        }
    }
    void insert(int val)
    {
        if (front == (rear + 1) % Max)
        {
            cout << "Queue is full\n";
        }
        else
        {
            if (front == -1)
            {
                front = rear = 0;
            }
            else
            {
                rear = (rear + 1) % Max;
            }
            qc[rear] = val;
        }
    }
    int delet()
    {
        if (front == -1)
        {
            cout << "Queue is empty\n";
        }
        else
        {
            int item = qc[front]; //*item to be deleted
            if (front == rear)
            { //*when single ele. is present
                front = rear = -1;
            }
            else
            {
                front = (front + 1) % Max;
            }
            return item;
        }
    }
    void display()
    {
        int i = front;
        while (i != rear)
        {
            cout << qc[i] << " ";
            i = (i + 1) % Max;
        }
        cout << qc[i];
        cout << endl;
    }
};
int main()
{
    circularQ q;
    q.init();
    q.insert(3);
    q.insert(32);
    q.insert(344);
    q.insert(31);
    q.insert(6);
    q.delet();
    q.insert(10);
    q.display();

    return 0;
}