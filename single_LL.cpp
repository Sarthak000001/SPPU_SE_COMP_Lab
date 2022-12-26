#include <iostream>
using namespace std;

class Node
{
	int data;
	Node *next;

public:
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
	// ~Node(){
	//     int val = data;
	//     if(next == NULL){
	//         delete next;
	//         next = NULL;
	//     }
	//     cout << "Node with value "<<val<< " is deleted" << endl;
	// }
	friend class LL;
};

class LL
{
public:
	Node *start;

	LL()
	{
		start = NULL;
	}
	int length()
	{
		int cnt = 0;
		Node *temp = start;
		while (temp != NULL)
		{
			temp = temp->next;
			cnt++;
		}

		return cnt;
	}
	void insert_start(int d)
	{
		Node *temp = new Node(d);
		if (start == NULL)
		{
			start = temp;
		}
		else
		{
			temp->next = start;
			start = temp;
		}
	}
	void insert_end(int d)
	{
		Node *temp = new Node(d);
		if (start == NULL)
		{
			start = temp;
		}
		else
		{
			Node *tail = start;
			while (tail->next != NULL)
			{
				tail = tail->next;
			}
			tail->next = temp;
		}
	}
	void insert_at_position(int p, int d)
	{
		int position = p - 1;
		if (position == 0)
		{
			insert_start(d);
			return;
		}
		else if (position > length())
		{
			cout << endl;
			cout << "Position doesn't exit " << endl;
			cout << "The length of list is " << length() << endl;
			return;
		}
		else
		{
			Node *temp = start;
			int cnt = 0;
			while (cnt < position - 1)
			{
				temp = temp->next;
				cnt++;
			}
			if (temp == NULL)
			{
				insert_end(d);
				return;
			}

			Node *newNode = new Node(d);
			newNode->next = temp->next;
			temp->next = newNode;
		}
	}
	void delete_at_start()
	{
		Node *temp = start;
		if (start != NULL)
		{
			start = start->next;
			temp->next = NULL;
			delete temp;
		}
		else
		{
			start = NULL;
			delete temp;
		}
	}
	void delete_at_end()
	{

		if (start == NULL)
		{
			cout << "List is empty" << endl;
			return;
		}
		else if (start->next == NULL)
		{
			delete start;
			start = NULL;
			return;
		}
		else
		{
			Node *temp = start;
			Node *pre = start;
			while (temp->next != NULL)
			{
				pre = temp;
				temp = temp->next;
			}
			pre->next = NULL;
			delete temp;
		}
	}
	void delete_at_position(int p)
	{
		if (start == NULL)
		{
			cout << "List is empty " << endl;
			return;
		}
		else if (p == 1)
		{
			delete_at_start();
			return;
		}
		else if (p == length())
		{
			delete_at_end();
			return;
		}
		else if (p > length())
		{
			cout << endl;
			cout << "Position doesn't exit " << endl;
			cout << "The length of list is " << length() << endl;
			return;
		}
		else
		{
			Node *temp = start;
			Node *pre = start;
			int count = 0;
			while (temp != NULL && count < p - 1)
			{
				pre = temp;
				temp = temp->next;
				count++;
			}
			pre->next = temp->next;
			temp->next = NULL;
			delete temp;
		}
	}
	void display()
	{

		Node *temp = start;
		if (start == NULL)
		{
			cout << "List is empty " << endl;
		}
		else
		{

			while (temp != NULL)
			{

				cout << temp->data << " ";
				temp = temp->next;
			}
		}
		cout << endl;
	}
};
int main()
{
	LL l1;
	cout << endl;
	// l1.insert_start(10);
	// l1.insert_start(5);
	// l1.insert_start(7);
	// l1.insert_end(1);
	// l1.insert_end(8);
	// l1.display();
	////cout << "Length of Linked list : " << l1.length() << endl;
	//
	// cout << "Start " << l1.start->data << endl;
	////l1.delete_node(5);
	////l1.delete_at_start();
	////l1.delete_at_start();
	////l1.delete_at_end();
	////l1.delete_at_end();
	////l1.insert_at_position(3,14);
	// l1.delete_at_position(4);
	// cout << endl;
	// l1.display();
	// cout << "Start " << l1.start->data << endl;
	bool flag = true;
	while (flag)
	{
		cout << endl;
		cout << "Enter 0:To Display " << endl;
		cout << "Enter 1:To insert at Start " << endl;
		cout << "Enter 2:To insert at End " << endl;
		cout << "Enter 3:To insert at Any Position " << endl;
		cout << "Enter 4:To Delete at Start " << endl;
		cout << "Enter 5:To delete at End " << endl;
		cout << "Enter 6:To delete at Particular Position " << endl;
		cout << "Enter 7:Exit " << endl;
		int c;
		cout << "Enter your Choice : " << endl;
		cin >> c;
		if (c == 0)
		{
			l1.display();
			char x;
			cout << "Do you want to continue (y/n): " << endl;
			cin >> x;
			if (x == 'y' || x == 'Y')
			{
				flag = true;
			}
			else
			{
				flag = false;
			}
		}
		else if (c == 1)
		{
			cout << "Enter the value you want to Insert : " << endl;
			int val;
			cin >> val;
			l1.insert_start(val);
			char x;
			cout << "Do you want to continue (y/n): " << endl;
			cin >> x;
			if (x == 'y' || x == 'Y')
			{
				flag = true;
			}
			else
			{
				flag = false;
			}
		}
		else if (c == 2)
		{
			cout << "Enter the value you want to Insert : " << endl;
			int val;
			cin >> val;
			l1.insert_end(val);
			char x;
			cout << "Do you want to continue (y/n): " << endl;
			cin >> x;
			if (x == 'y' || x == 'Y')
			{
				flag = true;
			}
			else
			{
				flag = false;
			}
		}
		else if (c == 3)
		{
			int val;
			cout << "Enter the value you want to Insert : " << endl;
			cin >> val;
			int p;
			cout << "Enter the Position : " << endl;
			cin >> p;
			l1.insert_at_position(p, val);
			char x;
			cout << "Do you want to continue (y/n): " << endl;
			cin >> x;
			if (x == 'y' || x == 'Y')
			{
				flag = true;
			}
			else
			{
				flag = false;
			}
		}
		else if (c == 4)
		{
			l1.delete_at_start();
			char x;
			cout << "Do you want to continue (y/n): " << endl;
			cin >> x;
			if (x == 'y' || x == 'Y')
			{
				flag = true;
			}
			else
			{
				flag = false;
			}
		}
		else if (c == 5)
		{
			l1.delete_at_end();
			char x;
			cout << "Do you want to continue (y/n): " << endl;
			cin >> x;
			if (x == 'y' || x == 'Y')
			{
				flag = true;
			}
			else
			{
				flag = false;
			}
		}
		else if (c == 6)
		{
			cout << "Enter the Position : " << endl;
			int p;
			cin >> p;
			l1.delete_at_position(p);
			char x;
			cout << "Do you want to continue (y/n): " << endl;
			cin >> x;
			if (x == 'y' || x == 'Y')
			{
				flag = true;
			}
			else
			{
				flag = false;
			}
		}
		else
		{
			flag = false;
		}
	}
	cout << "Thank You..!!!!" << endl;

	return 0;
}
