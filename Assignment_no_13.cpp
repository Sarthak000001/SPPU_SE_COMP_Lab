// Sarthak N.
#include <iostream>
// #include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 10;

class Deque
{
    int front;
    int rear;
    int dq[N];

public:
    Deque()
    {
        front = -1;
        rear = -1;
    }
    void insert_rear(int val)
    {
        if (rear == N - 1)
        {
            cout << "Deque is overflow\n";
            return;
        }
        if (front == -1)
        {
            front++;
        }
        rear++;
        dq[rear] = val;
    }
    int delete_front()
    {

        if (front == -1)
        {
            cout << "Deque is Underflow\n";
            return 0;
        }
        int item = dq[front];
        front++;
        return item;
    }
    void insert_front(int val)
    {
        if (front == -1)
        {
            rear++;
            front++;
            dq[front] = val;
            return;
        }
        if (front <= 0)
        {
            cout << "Deque is unable to accept value from front\n";
            return;
        }
        dq[--front] = val;
    }
    int delete_rear()
    {
        if (front == -1)
        {
            cout << "Deque is underflow \n";
            return 0;
        }
        int item = dq[rear];
        rear--;
        return item;
    }
    void display()
    {
        cout << endl;
        for (int i = front; i <= rear; i++)
        {

            cout << dq[i] << " ";
        }
        cout << endl
             << endl;
    }
};
int main()
{
    cout << "\n";
    Deque s1;
    while (true)
    {
        cout << "\n1.insert at rear \n2.insert at front\n3.delete from front\n4.delete from rear\n5.Display\n6.Exit\n";
        int n;
        cin >> n;
        cout << "\n";
        if (n == 1)
        {
            cout << "Enter the value : \n";
            int val;
            cin >> val;
            s1.insert_rear(val);
        }
        else if (n == 2)
        {
            cout << "Enter the value :\n";
            int val;
            cin >> val;
            s1.insert_front(val);
        }
        else if (n == 3)
        {
            s1.delete_front();
        }
        else if (n == 4)
        {
            s1.delete_rear();
        }
        else if (n == 5)
        {
            s1.display();
        }
        else
        {
            break;
        }
    }
    cout << "Thank you ! \n";
    return 0;
}