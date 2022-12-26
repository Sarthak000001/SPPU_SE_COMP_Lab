#include <iostream>
// #include <bits/stdc++.h>
using namespace std;

class Student
{
private:
    string name;
    string cls, division, dob, bloodgroup;
    int rollno;
    static int count; // declaring static member
public:
    friend class info; // making friend class
    Student()
    {
        string name = "";
         string cls = "";
         string division = "";
        string dob = "";
         string bloodgroup = "";
        rollno = count;
        count++;
    }

    //   static int getrollno()
    //     {
    //         cout << "Roll No : " << count << endl;
    //     }
    ~Student()
    {
    }
};

int Student::count = 1; // initializing the static member

class info
{
private:
    string telephone, address, drivinglicense;
    static string collage;

public:
    info()
    {
        string telephone = "";
        string address = "";
        string drivinglicense = "";
    }
    static string getcollage()
    {
        return collage;
    }
    void setdata(Student &s)
    {
        cout << "Enter the Name of the Student :" << endl;
        // cin >> s.name;
       // cin.ignore(1);
        getline(cin,s.name);
        cout << "Enter the Class of the Student : " << endl;
        // cin >> s.cls;
        getline(cin,s.cls);
        cout << "Enter the Division of the Student :" << endl;
        // cin >> s.division;
        getline(cin,s.division);
        cout << "Enter the Date of Birth the Student :" << endl;
        // cin >> s.dob;
        getline(cin,s.dob);
        cout << "Enter the Blood Group of the Student :" << endl;
        // cin >> s.bloodgroup;
        getline(cin,s.bloodgroup);
        cout << "Enter the telephone Number of the Student :" << endl;
        // cin >> this->telephone;
        getline(cin,this->telephone);
        cout << "Enter the Address of the Student :" << endl;
        // cin >> this->address;
        getline(cin,this->address);
        cout << "Enter the Driving License Number of the Student :" << endl;
        // cin >> this->drivinglicense;
        getline(cin,this->drivinglicense);
    }
    inline void getdata(Student &s)
    {

        cout << "The Roll NO :" << s.rollno << endl; //static member of student
        cout << "The Name of the Student : " << s.name << endl;
        cout << "The Class of the Student :" << s.cls << endl;
        cout << "The Division of the Student :" << s.division << endl;
        cout << "The Date of Birth of the Student :" << s.dob << endl;
        cout << "The Blood Group of the Student :" << s.bloodgroup << endl;
        cout << "The telephone Number of the Student :" << this->telephone << endl;
        cout << "The Address of the Student :" << this->address << endl;
        cout << "The Driving License Number of the Student :" << this->drivinglicense << endl;
    }
    ~info()
    {
    }
};
string info::collage = "PICT-Pune"; //initializing a static data member

int main()
{
    // info d,d1;
    // Student s,s1;
    // d.setdata(s);
    // d.getdata(s);
    // d1.setdata(s1);
    // d1.getdata(s1);
    int n;
    cout << endl << endl;
  
       cout << "Enter the Number of Student :" << endl;
       cin >> n;
       cin.ignore(1);
    
    try
    {
        if (n <= 0)
        {  
            throw 404;
        }
    }
    catch (int m)
    {
        cout << "Enter the Valid Number of Student " << endl;
        cout << "Error :" << m << endl;
        cout << "Enter the valid Number of Student :" << endl;
        cin >> n;
    }
   
    info *arr = new info[n];
    Student *stu = new Student[n];

    for (int i = 0; i < n; i++)
    {
        arr[i].setdata(stu[i]);
    }

    bool flag = true;
    while (flag)
    {
        cout << "Enter Your Choice : " << endl;
        cout << "Enter 1 : To see the Information of all the Student : " << endl;
        cout << "Enter 2 : To see the Information of individual the Student : " << endl;
        cout << "Enter 3:Exit " << endl;
        int a;
        cin >> a;
        if (a == 1)
        {
            for (int i = 0; i < n; i++)
            {
                cout << "--------------------------------------------------" << endl;
                cout << "Collage Name : " << info::getcollage() << endl;
                arr[i].getdata(stu[i]);
                cout << "--------------------------------------------------" << endl;
            }
            cout << "Do you want to contiue : (y/n)" << endl;
            char ans;
            cin >> ans;
            // (ans=='Y' || ans=='y')?flag = true:a=3;
            if (ans == 'Y' || ans == 'y')
            {
                flag == true;
            }
            else
            {
                flag == false;
                cout << "Thank you...!!" << endl;
                break;
            }
        }
        else if(a==2)
        {
            cout << "Enter Roll No. of that Student : " << endl;
            int s;
            cin >> s;
            cout << endl;
            cout << "------------------------------------------" << endl;
            cout << "Collage Name : " << info::getcollage() << endl;
            arr[s - 1].getdata(stu[s - 1]);
            cout << "-------------------------------------------" << endl;
            cout << "Do you want to contiue : (y/n)" << endl;
            char ans;
            cin >> ans;
            // (ans=='Y' || ans=='y')?flag = true:a=3;flag = false;
            if (ans == 'Y' || ans == 'y')
            {
                flag == true;
            }
            else
            {
                flag == false;
                cout << "Thank you...!!" << endl;
                break;
            }
        }
        else{
            flag =false;
            cout <<"Thank you !" << endl;
        }
    }
    delete[] arr;
    delete[] stu;
    return 0;
}
