//21156_Sarthak_Nirgude
//Batch : G1
#include <iostream>
#include <fstream> //including the fstream header file for performing the file i/o Operation
using namespace std;

class myclass
{
public:
	int roll;
	string name;

	void accept()
	{
		cout << "Enter Roll Number : ";
		cin >> roll;
		cout << "Enter Name : ";
		cin >> name;
	}

	void display()
	{
		cout << "'n-------------------\n";
		cout << "Name : " << name << endl;
		cout << "Roll : " << roll << endl;
		cout << "'n-------------------\n";
	}
};

int main()
{

	myclass s1;
	fstream f1;

	f1.open("myfile.txt", ios::out);

	int n;
	cout << "How many record you want to add ? ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		s1.accept();
		f1 << s1.roll << " : " << s1.name << endl;
	}

	f1.close();

	string line;

	ifstream f2;
	f2.open("myfile.txt", ios::in);
	//	while(f2) // This is also correct
	while (!f2.eof())
	{
		cout << "-------------\n";
		getline(f2, line);
		cout << line;
		cout << endl;
	}

	f2.close();

	return 0;
}
