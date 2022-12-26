//============================================================================
// Name        : 21156_AssignmentNo_01.cpp
// Author      :Sarthak Nirgude
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//21156_Sarthak_Nirgude
//Batch : G1
#include <iostream>
using namespace std;

class Complex{
private:
	int real;
	int img;
public:
	Complex()
	{
		real=0;
		img=0;
	}
	Complex(int r,int i)
	{
		this->real=r;
		this->img=i;
	}
	void display(){
		cout << real << " + " << img <<"i"<<endl;
	}
	Complex operator +( Complex c2 )
	{
		Complex temp;
		temp.real= real + c2.real;
		temp.img= img + c2.img;
		return temp;
    }
	Complex operator*(Complex c2)
	{
		Complex temp;
		temp.real=(real*c2.real)-(img*c2.img);
		temp.img=(real*c2.img)+(c2.real*img);
		return temp;
	}
   friend ostream &operator<<(ostream &os,Complex &c)
   {  //don't forget to write the & (Pass by reference)
	   os << c.real << "+ " << (c.img) << "i" << endl;
	   return os;
   }
   friend istream &operator>>(istream &input , Complex &c)
   {    cout << "Real Part :" << endl;
	   input >> c.real ;
	   cout << "img part :" << endl;
	   input >> c.img;
	   return input ;
   }
};
int main() {
   Complex c1,c2;
  
   cout << "Enter First Complex No : " << endl;
   cin >> c1;
   cout << "Enter Second Complex NO : " << endl;
   cin >> c2;

   char ch;
   cout << "Enter the Operation : "<< endl;
   cin >> ch;
   Complex c3;

   switch(ch)
   {
   case '+':
	   c3=c1+c2;
	   cout << "Complex No. : " <<  c3;
	   break;
   case '*':
	   c3=c1*c2;
	   cout << "Complex No. : " << c3;
	   break;
   default:
	   cout << "Enter the valid Operation " << endl;
   }
	return 0;
}