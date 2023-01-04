// #include <iostream>
// using namespace std;

// class Node
// {
// public:
// 	int data;
// 	Node *next;

// 	Node(int data)
// 	{
// 		this->data = data;
// 		this->next = NULL;
// 	}
// 	// ~Node(){
// 	//     int val = data;
// 	//     if(next == NULL){
// 	//         delete next;
// 	//         next = NULL;
// 	//     }
// 	//     cout << "Node with value "<<val<< " is deleted" << endl;
// 	// }
// 	friend class LL;
// };

// class LL
// {
// public:
// 	Node *start;

// 	LL()
// 	{
// 		start = NULL;
// 	}
// 	int length()
// 	{
// 		int cnt = 0;
// 		Node *temp = start;
// 		while (temp != NULL)
// 		{
// 			temp = temp->next;
// 			cnt++;
// 		}

// 		return cnt;
// 	}
// 	void insert_start(int d)
// 	{
// 		Node *temp = new Node(d);
// 		if (start == NULL)
// 		{
// 			start = temp;
// 		}
// 		else
// 		{
// 			temp->next = start;
// 			start = temp;
// 		}
// 	}
// 	void insert_end(int d)
// 	{
// 		Node *temp = new Node(d);
// 		if (start == NULL)
// 		{
// 			start = temp;
// 		}
// 		else
// 		{
// 			Node *tail = start;
// 			while (tail->next != NULL)
// 			{
// 				tail = tail->next;
// 			}
// 			tail->next = temp;
// 		}
// 	}
// 	void insert_at_position(int p, int d)
// 	{
// 		int position = p - 1;
// 		if (position == 0)
// 		{
// 			insert_start(d);
// 			return;
// 		}
// 		else if (position > length())
// 		{
// 			cout << endl;
// 			cout << "Position doesn't exit " << endl;
// 			cout << "The length of list is " << length() << endl;
// 			return;
// 		}
// 		else
// 		{
// 			Node *temp = start;
// 			int cnt = 0;
// 			while (cnt < position - 1)
// 			{
// 				temp = temp->next;
// 				cnt++;
// 			}
// 			if (temp == NULL)
// 			{
// 				insert_end(d);
// 				return;
// 			}

// 			Node *newNode = new Node(d);
// 			newNode->next = temp->next;
// 			temp->next = newNode;
// 		}
// 	}
// 	void delete_at_start()
// 	{
// 		Node *temp = start;
// 		if (start != NULL)
// 		{
// 			start = start->next;
// 			temp->next = NULL;
// 			delete temp;
// 		}
// 		else
// 		{
// 			start = NULL;
// 			delete temp;
// 		}
// 	}
// 	void delete_at_end()
// 	{

// 		if (start == NULL)
// 		{
// 			cout << "List is empty" << endl;
// 			return;
// 		}
// 		else if (start->next == NULL)
// 		{
// 			delete start;
// 			start = NULL;
// 			return;
// 		}
// 		else
// 		{
// 			Node *temp = start;
// 			Node *pre = start;
// 			while (temp->next != NULL)
// 			{
// 				pre = temp;
// 				temp = temp->next;
// 			}
// 			pre->next = NULL;
// 			delete temp;
// 		}
// 	}
// 	void delete_at_position(int p)
// 	{
// 		if (start == NULL)
// 		{
// 			cout << "List is empty " << endl;
// 			return;
// 		}
// 		else if (p == 1)
// 		{
// 			delete_at_start();
// 			return;
// 		}
// 		else if (p == length())
// 		{
// 			delete_at_end();
// 			return;
// 		}
// 		else if (p > length())
// 		{
// 			cout << endl;
// 			cout << "Position doesn't exit " << endl;
// 			cout << "The length of list is " << length() << endl;
// 			return;
// 		}
// 		else
// 		{
// 			Node *temp = start;
// 			Node *pre = start;
// 			int count = 0;
// 			while (temp != NULL && count < p - 1)
// 			{
// 				pre = temp;
// 				temp = temp->next;
// 				count++;
// 			}
// 			pre->next = temp->next;
// 			temp->next = NULL;
// 			delete temp;
// 		}
// 	}
// 	void display()
// 	{

// 		Node *temp = start;
// 		if (start == NULL)
// 		{
// 			cout << "List is empty " << endl;
// 		}
// 		else
// 		{

// 			while (temp != NULL)
// 			{

// 				cout << temp->data << " ";
// 				temp = temp->next;
// 			}
// 		}
// 		cout << endl;
// 	}
// 	void swap_LL()
// 	{
// 		if (start == NULL || start->next == NULL)
// 		{
// 			return;
// 		}
// 		else
// 		{
// 			Node *curr = start->next;
// 			Node *prev = start;
// 			start = curr;
// 			Node *temp = curr->next;
// 			while (true)
// 			{
// 				cout << "sfls";
// 				curr->next = prev;
// 				if (temp == NULL || temp->next == NULL)
// 				{
// 					cout << "sfls";
// 					return;
// 				}
// 				prev->next = temp;
// 				temp = curr->next;
// 				curr = temp->next;
// 				prev = temp;
// 				temp = curr->next;
// 			}
// 			cout << "sfls";
// 		}
// 	}
// };

// int main()
// {
// 	LL l1;
// 	l1.insert_start(6);
// 	l1.insert_start(5);
// 	l1.insert_start(4);
// 	l1.insert_start(3);
// 	l1.insert_start(2);
// 	l1.insert_start(1);
// 	l1.display();

// 	l1.swap_LL();

// 	l1.display();
// 	return 0;
// }


#include<iostream>
#include <bits/stdc++.h>
// #ifndef frl(m,n,val)
#define frl(m,n,val) for(int i=m;i < n;i++){cout << val << "\n";}
// #endif
using namespace std;
	 
int main()
{     int k = 10;
//       frl(0,10,k--);
 //a->97 A->65
// l to u ---> -32
// u to l ---> +32
string str = "LeveL";
string ans = "";
for(int i=0;i < str.length();i++){
      if('a' <= str[i] && str[i] <= 'z'){
            ans.push_back(str[i]-32);
      }else{
            ans.push_back(str[i]);
      }
}
cout << ans << endl;
return 0;
}