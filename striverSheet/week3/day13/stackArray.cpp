#include <iostream>
using namespace std;

int arr[5], nax = 5, top = -1;

void push(int ele)
{
    top++;
    arr[top] = ele;
}

void pop()
{
    cout << endl
         << "Popped element is: " << arr[top] << endl;
    top--;
}

void peek()
{
    cout << endl
         << "Top element is: " << arr[top] << endl;
}

void display()
{

    if (top == -1)
    {
        cout << endl
             << "Stack is empty!!" << endl;
    }
    else
    {
        cout << endl
             << "Stack: ";
        for (int i = top; i > -1; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

int main()
{

    int choice;
    
    while (1)
    {
        cout << endl
             << "Press--> "
             << "1.Push "
             << "2.Pop "
             << "3.Peek "
             << "4.isEmpty "
             << "5.isFull "
             << "6.Display "
             << "0.Exit "
             << endl;
        cout << endl
             << "Enter Your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            if (top < nax - 1)
            {
                cout << endl
                     << "Enter the element to push: ";
                int ele;
                cin >> ele;
                push(ele);
            }
            else
            {
                cout << endl
                     << "Overflow conditio!!" << endl;
            }
        }
        break;
        case 2:
        {
            if (top == -1)
            {
                cout << endl
                     << "underflow conditio!!" << endl;
            }
            else
            {
                pop();
            }
        }
        break;
        case 3:
        {
            if (top == -1)
            {
                cout << endl
                     << "stack is empty!!" << endl;
            }
            else
            {
                peek();
            }
        }
        break;
        case 4:
        {
            if (top == -1)
            {
                cout << endl
                     << "Yes" << endl;
            }
            else
            {
                cout << endl
                     << "No" << endl;
            }
        }
        break;
        case 5:
        {
            if (top == nax - 1)
            {
                cout << endl
                     << "Yes" << endl;
            }
            else
            {
                cout << endl
                     << "No" << endl;
            }
        }
        break;
        case 6:
        {
            display();
        }
        break;
        case 7:
            exit(0);
        default:
            cout << endl
                 << "Entered invalid choice" << endl;
        }
    }
}