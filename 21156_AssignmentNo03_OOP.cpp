//21156_Sarthak_Nirgude
//Batch : G1
#include <iostream>
using namespace std;
class Publication
{
    string title;
    float price;

public:
    void set_data()
    {
        cout << "Enter the Title : " << endl;
        //   getline(cin,title);
        cin >> title;
        cout << "Enter the Price : " << endl;
        cin >> price;
        //   this->title = title;
        //   this->price = price;
    }
    void get_data()
    {
        cout << "The Title : " << title << endl;
        cout << "The Price : " << price << endl;
    }
};
class Book : public Publication
{
    int pagecount;

public:
    void set_data()
    {
        Publication::set_data();
        cout << "Enter the Page count : " << endl;
        cin >> pagecount;
    }
    void get_data()
    {
        Publication::get_data();
        cout << "The Page count : " << pagecount << endl;
    }
};
class Tape : public Publication
{
    float play_time;

public:
    void set_data()
    {
        Publication::set_data();
        cout << "Enter the Play time : " << endl;
        cin >> play_time;
    }
    void get_data()
    {
        Publication::get_data();
        cout << "The Play time :" << play_time << endl;
    }
};
int main()
{
    Book b;
    Tape t;
    t.set_data();
    b.set_data();
    b.get_data();
    t.get_data();

    return 0;
}
