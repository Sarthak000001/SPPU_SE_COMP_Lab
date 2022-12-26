#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Student{
private:
string name;
static int student_count; //Student Count creating statically
int rollno;
string division;
string dateofbirth;
char bloodgroup;
long long int contactno;  
string address;
int drivinglicenseno;
public:
 friend class studentinfo;
  Student(string name,string division,int dateofbirth,char bloodgroup,long long int contactno,string address,int drivinglicenseno,int rollno){
    this->name = name;
    this->division = division;
    this->dateofbirth = dateofbirth;
    this->bloodgroup = bloodgroup;
    this->contactno = contactno;
    this->address = address;
    this->drivinglicenseno = drivinglicenseno;
    this->rollno = rollno;
    student_count++;
  }
  Student(){
    // this->name ="";
    // this->division = "";
    // this->dateofbirth = "";
    // this->bloodgroup =0;
    // this->contactno = 0;
    // this->address = "";
    // this->drivinglicenseno = 0;
    // this->rollno = 0;
    student_count++;
  }
 
   friend istream& operator>>(istream &input , Student &obj)
  {
    cout << "Enter the Name :" << endl;
    input >> obj.name;
    cout << "Enter the division : " << endl;
    input >> obj.division;
    cout << "Enter Date of Birth of the Student : " << endl;
    input >> obj.dateofbirth;
    cout << "Enter the Blood Group of the Student : " << endl;
    input >> obj.bloodgroup;
    cout << "Enter the Contact Number of the Student : " << endl;
    input >> obj.contactno;
    cout << "Enter the Address of the Student : " << endl;
    input >> obj.address;
    cout << "Enter the Driving License Number of the Student : " << endl;
    input >> obj.drivinglicenseno;
    cout << "Enter the Roll Number of the Student : " << endl;
    input >> obj.rollno;
    return input;
  }
 friend ostream& operator<<(ostream &output , Student &obj)
  {   cout << endl; 
      cout << "---------------------------------------------------" << endl;
      output << "The Name of the Student : " << obj.name << endl;
      output << "The division of the Student : " << obj.division << endl;
      output << "The Date of Birth of the Student : " << obj.dateofbirth << endl;
      output << "The Blood group of the Student : " << obj.bloodgroup << endl;
      output << "The Contact Number of the Student : " << obj.contactno << endl;
      output << "The Address of the Student : " << obj.address << endl;
      output << "The Driving License Number of the Student : " << endl;
      output << "The Roll Number of the Student : " << obj.rollno <<endl;
      cout << "------------------------------------------------------------" << endl;
  
      cout << endl;
      return output;
      
  }
  inline static int getstudentcount()
 {  //making static function inline
     return student_count;    
  }
  ~Student()
  {
    cout << "Destructor" << endl;
  }
};
int Student::student_count = 0; //initializing the count 
int main()
 {
int noofstudent; cout << "Enter the Number of Student : " << endl;
cin >> noofstudent;
cout << endl;
try{    //Exception Handling 
  if(noofstudent <= 0) 
  {
      throw 404;
  }  
    cout << "Hello...!!" << endl;
}
catch(int n)
{     //catching the exception
  cout << "Enter the valid Number of Students " << endl;
  cout << "Error " << n << endl;
}
// Student arr[noofstudent];
Student *arr = new Student[noofstudent]; //creating in heap
//created array of student dynamically in heap
 for(int i=0 ; i < noofstudent ; i++)
{
   cin >> arr[i];
}
bool flag = true;
while(flag==true){
  cout << "Do you want to see the information of the Student " << endl;
  char ch; cout << "Enter your choose (y/n)" << endl; cin >> ch;
  if(ch=='y')
  {
      cout << "Do you want to see the Information of all the Student or type the Roll no. of that Student : " << endl;
      cout << "Enter 1 : To see the Information of all the Student :" << endl;
      cout << "Enter (Roll NO.) : To see the Information of that Student :" << endl;
      int a; cin >> a;
      if(a==1){
          for (int i = 0; i < noofstudent; i++){
                   cout << arr[i];
             }
      }
      else{
        cout << arr[a];
      }
  }


}

cout << "-----------------------------------------------------------------------" << endl;
cout << "The total Number of the Student : " << Student::getstudentcount() << endl;
//deleting the dynamically allocated memory form heap
delete [] arr; //deleting the array
return 0;
}