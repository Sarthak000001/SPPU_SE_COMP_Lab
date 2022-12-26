// // Author : Sarthak Nirgude
// // Language :C++
// // Topic : Ticket Booking System
// #include <iostream>
// using namespace std;

// class Node
// {
//     Node *pre;
//     Node *next;
//     string status;
//     int seatno;
//     string pin;
//     string name;

// public:
//     Node()
//     {
//         next = pre = NULL;
//         status = "_";
//         seatno = 0;
//         pin = "";
//         name = "";
//         // seatcount = count;
//         // count++;
//     }
//     friend class LL;
// };
// // int Node::count = 1;
// class LL
// {
//     Node *header[10];
//     int seatcount;

// public:
//     LL()
//     {
//         for (int i = 0; i < 10; i++)
//         {
//             header[i] = NULL;
//         }
//         seatcount = -10;
//     }
//     void creat()
//     {
//         for (int i = 0; i < 10; i++)
//         {

//             for (int j = 0; j <= 7; j++)
//             {
//                 seatcount++;
//                 if (header[i] == NULL)
//                 {
//                     Node *temp = new Node();
//                     header[i] = temp;
//                     temp->next = temp;
//                     temp->pre = temp;
//                     temp->seatno = 7 * i + j + 1;
//                 }
//                 else
//                 {
//                     Node *temp = new Node();
//                     temp->seatno = 7 * i + j + 1;
//                     Node *start = header[i]->pre;
//                     start->next = temp;
//                     temp->pre = start;
//                     temp->next = header[i];
//                     header[i]->pre = temp;
//                 }
//             }
//         }
//     }
//     void display()
//     {
//         cout << "_______________________________________________Availabel Seats : " << seatcount << "" << endl;
//         for (int i = 0; i < 10; i++)
//         {
//             if ((i + 1) == 10)
//             {
//                 cout << "Row" << i + 1 << "| ";
//             }
//             else
//             {
//                 cout << "Row " << i + 1 << "| ";
//             }

//             Node *temp = header[i];

//             while (temp->next != header[i])
//             {
//                 if (temp->seatno < 10)
//                 {
//                     cout << "0" << temp->seatno << ":_" << temp->status << "_   ";
//                 }
//                 else
//                 {

//                     cout << temp->seatno << ":_" << temp->status << "_   ";
//                 }
//                 temp = temp->next;
//             }
//             cout << endl;
//         }
//     }

//     void Booked(int num, string s, string p)
//     {
//         if (num > 70)
//         {
//             cout << "Enter the Valid Seat Number " << endl;
//             return;
//         }
//         int row = (num - 1) / 7;
//         int col = (num - 1) % 7;
//         Node *row_no = header[row];
//         for (int i = 0; i <= col; i++)
//         {
//             if (row_no->seatno == num)
//             {
//                 if (row_no->status == "B")
//                 {
//                     cout << "Seat is already Booked " << endl;
//                     break;
//                 }
//                 else
//                 {
//                     row_no->name = s; // assigning name
//                     row_no->pin = p;  // assigning pin
//                     seatcount--;
//                     row_no->status = "B";
//                     break;
//                 }
//             }
//             row_no = row_no->next;
//         }
//     }

//     void cancel_booking(int num, string p)
//     {
//         if (num > 70)
//         {
//             cout << "Enter the Valid Seat Number " << endl;
//             return;
//         }
//         int row = (num - 1) / 7;
//         int col = (num - 1) % 7;
//         Node *row_no = header[row];
//         for (int i = 0; i <= col; i++)
//         {
//             if (row_no->seatno == num && row_no->status != "_")
//             {
//                 if (row_no->pin == p)
//                 {

//                     seatcount++;
//                     row_no->status = "_";
//                     return;
//                 }
//                 else
//                 {
//                     cout << "Enter the valid Pin " << endl;
//                     return;
//                 }
//             }
//             row_no = row_no->next;
//         }
//         cout << "Seat is already vacant " << endl;
//         return;
//     }

//     void check_status()
//     {
//         cout << "\n________________________: Booking Status :________________________\n"
//              << endl;
//         cout << "\tTotal Number of Seats are " << 70 << endl;
//         cout << "\tNumber of Booked Seats are " << 70 - seatcount << endl;
//         cout << "\tNumber of Available Seats are " << seatcount << endl;
//         cout << "\n\tBooked Seat's\t\t\n";
//         // cout <<"\tName\t\tSeat No.\t\t\n";
//         cout << "\t---\t\t--\t\t\n";
//         for (int i = 0; i < 10; i++)
//         {

//             Node *p = header[i];

//             while (p->next != header[i])
//             {
//                 if (p->status == "B")
//                 {
//                     cout << "\tName : " << p->name << endl;
//                     cout << "\tSeat No. :" << p->seatno << endl;
//                     cout << "\t------------------------\n";
//                 }
//                 p = p->next;
//             }
//         }
//     }
// };
// int main()
// {
//     cout << endl;

//     LL s1;
//     s1.creat();

//     for (int i = 0; i < 70; i++)
//     {
//         if (i & 1)
//         {
//             if (i % 3 == 0)
//             {
//                 string s = "xyz";
//                 string p = "1";
//                 s1.Booked(i, s, p);
//             }
//         }
//     }
//     s1.display();
//     while (true)
//     {

//         cout << "\n________________________: Ticket Booking :________________________\n"
//              << endl;
//         cout << "\tEnter 1:To Booked Ticket\n\tEnter 2:To Cancel the booking\n\tEnter 3:Display\n\tEnter 4:To check BooKing Status\n\tEnter 5:To Exit" << endl;
//         int n;
//         cin >> n;
//         if (n == 1)
//         {
//             cin.ignore(1);
//             cout << "Enter your Name : " << endl;
//             string s;
//             getline(cin, s);
//             cout << "Enter your Security : " << endl;
//             string p;
//             getline(cin, p);
            
//             int n;
//             cout << "Enter the Number of Seat you want to book \n";
//             cin >> n;
//             while (n--)
//             {

//                 cout << "Enter the Seat Number " << endl;
//                 int seat_no;
//                 cin >> seat_no;
//                 s1.Booked(seat_no, s, p);
//             }
//         }
//         else if (n == 2)
//         {
//             cin.ignore(1);
//             cout << "Enter your Security Pin " << endl;
//             string p;
//             getline(cin, p);
//             cout << "Enter the Seat Number " << endl;
//             int seat_no;
//             cin >> seat_no;
//             s1.cancel_booking(seat_no, p);
//         }
//         else if (n == 3)
//         {
//             s1.display();
//         }
//         else if (n == 4)
//         {
//             s1.check_status();
//         }
//         else if (n == 5)
//         {

//             cout << "\t\tThank you !\t\t" << endl;
//             break;
//         }
//         else
//         {
//             cout << "\tEnter the valid Option " << endl;
//         }
//     }

//     cout << endl;
//     return 0;
// }

#include <iostream>
using namespace std;

class node{
    node *next;
    node *pre;
    string status;
    int seatno;

    public:

    node(){
        next = pre = NULL;
        status = "A";
        seatno = 0;
    } 

    friend class LL;
};

class LL{

    node *header[10];

    public:

    LL(){
        for(int i=0; i<10; i++){
            header[i] = NULL;
        }
    }

    void create(){
        for(int i=0; i<10; i++){
            for(int j=0; j<7; j++){
                
                node *temp = new node;
                temp->seatno = 7*i+j+1;
                if(header[i]==NULL){
                    header[i] = temp;
                    temp->next = temp;
                    temp->pre = temp;
                }
                else{
                    header[i]->pre->next = temp;
                    temp->pre = header[i]->pre;
                    header[i]->pre = temp;
                    temp->next = header[i];
                }
            }
        }
    }

    void display(){
        node *q;
        for(int i=0; i<10; i++){
            cout<<char(65+i)<<" : ";
            q = header[i];
            for(int j = 0; j<7; j++){
                cout<<q->seatno<<" : "<<q->status<<" | ";
                q = q->next;
            }
            cout<<endl<<endl; 
        }
    }
};

int main()
{
    LL l;
    l.create();
    l.display();
    return 0;
}