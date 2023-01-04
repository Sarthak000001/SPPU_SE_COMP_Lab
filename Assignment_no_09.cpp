#include <iostream>
using namespace std;
const int Max = 20;
class Stack
{
        char arr[Max];
        int top;

public:
        Stack()
        {
                top = -1;
        }
        void push(char val)
        {
                if (top < Max)
                {
                        top++;
                        arr[top] = val;
                }
                else
                {
                        cout << "StackOverflow\n";
                }
        }
        char pop()
        {

                char item = arr[top];
                top--;
                return item;
        }
        bool isempty()
        {
                if (top == -1)
                {
                        return true;
                }
                else
                {
                        return false;
                }
        }
        bool check(string str)
        {
                for (int i = 0; i <= str.length(); i++)
                {
                        char c = str[i];
                        if (c == '(' || c == '{' || c == '[')
                        {
                                push(c);
                                // cout << "INdise\n";
                        }
                        else
                        {
                                if (c == ')')
                                {
                                        char t = arr[top];
                                        if (t == '(')
                                        {
                                                pop();
                                        }
                                        else
                                        {
                                                return false;
                                        }
                                }
                                else if (c == '}')
                                {
                                        char t = arr[top];
                                        if (t == '{')
                                        {
                                                pop();
                                        }
                                        else
                                        {
                                                return false;
                                        }
                                }
                                else if (c == ']')
                                {
                                        char t = arr[top];
                                        if (t == '[')
                                        {
                                                pop();
                                        }
                                        else
                                        {
                                                return false;
                                        }
                                }
                                // if (c == ')' || c == '}' || c == ']')
                                // {

                                //         char t = arr[top];
                                //         if (t == '{' || t == '(' || t == '[')
                                //         {
                                //                 cout << "IfgdgNdise\n";
                                //                 pop();
                                //         }
                                // }
                                // else
                                // {
                                //         return false;
                                // }
                        }
                }

                if (top == -1)
                {
                        // cout << "INdfsfddise\n";
                        return true;
                }
                else
                {
                        return false;
                }
        }
};
// void sumn(int n){
//         int sum = 0;
//        for(int i=0;i <= n;i++){
//          sum += i;
//        }
//        cout << "Sum is : " << sum << endl;
// }
int main()
{ // cout << "Enter n : " << endl;
        // int n; cin >> n;
        //  sumn(n);

        while (true)
        {
                cout << "========================: MENU Bar :========================\n";
                cout << "Enter 1:To check the validity of the Expression\n";
                cout << "Enter 2:Exit\n\n";
                cout << "=============================================================\n";
                cout << "\nEnter your choice :\n";
                int n;
                cin >> n;
                if (n == 1)
                {
                        cout << "Enter the String\n";
                        string str;
                        cin >> str;
                        Stack s;
                        if (s.check(str))
                        {
                                cout << "Valid Expression\n";
                        }
                        else
                        {
                                cout << "Invalid Expression\n";
                        }
                }
                else if (n == 2)
                {
                        cout << "----->Thank you...!!<-----\n";
                        break;
                }
                else
                {
                        cout << "Invalid input\n";
                }
        }
        return 0;
}