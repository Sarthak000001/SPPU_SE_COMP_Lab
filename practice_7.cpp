// Sarthak N.
#include <iostream>
// #include <bits/stdc++.h>
#define ll long long
using namespace std;

class Node
{
    Node *next;
    Node *pre;
    int seatno;
    string status, name;

public:
    Node()
    {
        this->next = NULL;
        this->pre = NULL;
        seatno = 0;
        status = "_";
        name = "";
    }
    friend class LL;
};
class LL
{
    Node *header[10];

public:
    LL()
    {
        for (int i = 0; i < 10; i++)
        {
            header[i] = NULL;
        }
    }
    void creat();
    void display();
    void booked(int seatnumber,string name);
    void cancel(int seatnumber);
};
void LL::creat()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j <= 7; j++)
        {
            Node *temp = new Node();
            if (header[i] == NULL)
            {
                temp->seatno = 7 * i + j + 1;
                header[i] = temp;
                temp->next = temp;
                temp->pre = temp;
            }
            else
            {
                temp->seatno = 7 * i + j + 1;
                Node *it = header[i]->pre;
                it->next = temp;
                temp->pre = it;
                header[i]->pre = temp;
                temp->next = header[i];
            }
        }
    }
}
void LL::display()
{
    for (int i = 0; i < 10; i++)
    {
        if (i == 9)
        {

            cout << "Row :" << i + 1 << "| ";
        }
        else
        {

            cout << "Row : " << i + 1 << "| ";
        }
        Node *temp = header[i];
        while (temp->next != header[i])
        {
            if (temp->seatno <= 9)
            {

                cout << "  0" << temp->seatno << ":_" << temp->status << "_";
            }
            else
            {

                cout << "  " << temp->seatno << ":_" << temp->status << "_";
            }
            temp = temp->next;
        }
        cout << endl;
    }
}
void LL::booked(int seatnumber,string name){
    if(seatnumber > 70){
         cout << "Enter the valid seat number \n";
         return ;
    }
    int row = (seatnumber-1)/7;
    int col = (seatnumber-1)%7;
    Node* row_no = header[row];
    for(int i=0;i <= col;i++){
        if(row_no->seatno == seatnumber){
            if(row_no->status == "B"){
                cout << "Seat is already Booked \n";
            }
            else{
                row_no->status = "B";
                cout << "Seat booked successfully \n";
                return ;
            }
        }
        row_no = row_no->next;
    }

}
void LL::cancel(int seatnumber){
    if(seatnumber > 70){
         cout << "Enter the valid seat number \n";
         return ;
    }
    int row = (seatnumber-1)/7;
    int col = (seatnumber-1)%7;
    Node* row_no = header[row];
    for(int i=0;i <= col;i++){
        if(row_no->seatno == seatnumber){
            if(row_no->status == "_"){
                cout << "Seat is already  vacant\n";
            }
            else{
                row_no->status = "_";
                cout << "Seat cancel successfully \n";
                return ;
            }
        }
        row_no = row_no->next;
    }

}
int main()
{
    LL obj;
    obj.creat();
    obj.display();

    while(true){
        cout << "Enter the seatno your want to booked \n";
        int n; cin >> n; cin.ignore(1);
        cout << "Enter your Name : " << endl;
        string str; 
        getline(cin,str);
        obj.booked(n,str); 
        int a; cin >> a;
        if(a == 1){
            obj.display();
        }
        if(a == 0){
            break;
        }
        cout << "Enter seatno to cancel \n" << endl; int m; cin >> m;
        obj.cancel(m);
    }
    return 0;
}