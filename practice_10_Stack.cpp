// #define Sarthak ios_base:: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include <iostream>
// #include <bits/stdc++.h>
#define ll long long
using namespace std;
// Implementing the Stack using the linked ist
// making class node
class Node
{
    char data;
    Node *next;
    friend class Stack;

public:
    Node(char d)
    {
        this->data = d;
        this->next = NULL;
    }
};
class Stack
{
    Node *top;
    Node *start;

public:
    Stack()
    {
        this->top = NULL;
        this->start = NULL;
    }
    bool isempty();
    void push(char val);
    char pop();
    char peek();
};
void Stack::push(char val)
{
    Node *temp = new Node(val);
    if (top == NULL)
    {
        start = temp;
        top = temp;
    }
    else
    {
        top->next = temp;
        top = temp;
    }
}
bool Stack::isempty()
{
    if (top == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
char Stack::pop()
{
    if (isempty())
    {
        cout << "Stack Underflow \n";
        return -1;
    }
    Node *temp = start;
    if (top == start)
    {
        char item = start->data;
        top = NULL;
        return item;
    }
    while (temp->next != top)
    {
        temp = temp->next;
    }

    char item = top->data;
    top = temp;
    return item;
}
char Stack::peek()
{
    if (!isempty())
    {
        return top->data;
    }
    else
    {
        cout << "Stack is empty\n";
        return -1;
    }
}

class Operation
{
    string ans;

public:
    Operation()
    {
        this->ans = "";
    }
    int pre(char x);
    bool isOperand(char x);
    bool isdigit(char y);
    void convert(string str);
    void display();
    void evaluation();
};
bool Operation::isdigit(char y)
{
    if (y >= '0' && y <= '9')
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Operation::isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '(' ||
        x == ')' || x == '^' || x == '[' || x == ']' || x == '{' || x == '}' || isdigit(x))
    {
        return false;
    }
    else
    {
        return true;
    }
}
int Operation::pre(char x)
{
    if (x == '+' || x == '-')
    {
        return 1;
    }
    else if (x == '/' || x == '*')
    {
        return 2;
    }
    else if (x == '^')
    {
        return 3;
    }
    else
    {
        return -1;
    }
}
void Operation::convert(string str)
{
    Stack st;
    ans = "";
    for (int i = 0; i < str.size(); i++)
    {
        if (isOperand(str[i]) || isdigit(str[i]))
        {
            ans = ans + str[i];
        }
        else if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            st.push(str[i]);
        }
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {

            while (((!st.isempty()) && st.peek() != '(' || st.peek() != '[' || st.peek() != '{'))
            {
                ans = ans + st.pop();
                if (st.peek() == '(' || st.peek() == '[' || st.peek() == '{')
                {
                    break;
                }
            }
            st.pop();
        }
        else if (isOperand(str[i]) == false && isdigit(str[i]) == false)
        {
            while (!st.isempty() && pre(str[i]) <= pre(st.peek()))
            {
                ans = ans + st.pop();
            }
            st.push(str[i]);
        }
    }
    while (!st.isempty())
    {
        ans = ans + st.pop();
    }
    cout << ans << " ";
}
void Operation::evaluation()
{
    Stack st;
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] >= 'a' && ans[i] <= 'z' || ans[i] >= 'A' && ans[i] <= 'Z')
        {
            cout << "Enter the value of " << ans[i] << " : \n";
            int t;
            cin >> t;
            st.push(t);
        }
        else if (isdigit(ans[i]))
        {
            int x, y, result;
            x = (int)(st.pop()-'0');
            y = (int)(st.pop()-'0');
            if (ans[i] == '+')
            {
                result = y + x;
                st.push(result);
            }
            else if (ans[i] == '-')
            {
                result = y - x;
                st.push(result);
            }
            else if (ans[i] == '*')
            {
                result = y * x;
                st.push(result);
            }
            else if (ans[i] == '/')
            {
                result = y / x;
                st.push(result);
            }
        }
        else
        {
            int x, y, result;
            x = st.pop();
            y = st.pop();
            switch (ans[i])
            {
            case '+':
                result = y + x;
                st.push(result);
                break;
            case '-':
                result = y - x;
                st.push(result);
                break;
            case '*':
                result = y * x;
                st.push(result);
                break;
            case '/':
                result = y / x;
                st.push(result);
                break;
            default:
                break;
            }
        }
    }
    cout << "Answer : " << (int)st.pop() << endl;
}
void Operation::display()
{
    cout << "After conversion :   " << ans << " \n";
}
int main()
{
    Stack st;
    Operation obj;
    // cout << "Enter your expression : " << endl;
    // string exp;
    // cin >> exp;
    // obj.convert(exp);
    // cout << endl;
    // obj.evaluation();
    while (true)
    {
        cout << "______________________: MENU :_________________________" << endl;
        cout << "Enter 1:Converting Infix into Postfix expression \nEnter 2:Evaluating the expression \nEnter 3:Exit\n";
        int op;
        cout << "Enter your choice : " << endl;
        cin >> op;
        if (op == 1)
        {
            cout << "Enter your Expression : ";
            string exp;
            cin >> exp;
            obj.convert(exp);
            cout << endl;
        }
        else if (op == 2)
        {
            cout << "Enter your expression : ";
            string exp;
            cin >> exp;  cout << endl;
            obj.convert(exp); cout << "\n";
            obj.evaluation();
        }
        else if (op == 3)
        {
            cout << "Thank you !\n";
            break;
        }
        else
        {
            cout << "Invalid Input\n";
        }
    }

    return 0;
}