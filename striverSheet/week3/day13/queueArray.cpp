#include <iostream>
using namespace std;

int queue[5], n = 5, front = -1, rear = -1;

void enqueue(int element)
{
    if (front == -1 && rear == -1)
    {
        front++;
        rear++;
    }
    else
    {
        rear = ((rear + 1) % n);
    }
    queue[rear] = element;
}

void dequeue(){
    cout<<endl<<"Dequeued element: "<<queue[front]<< endl;
    if(front==rear){
        front=rear= -1;
    }
    else{
        front= ((front+1)%n);
    }
}

void peek(){
    cout<<endl<<"Peek element: "<<queue[front]<< endl;
}

void display(){
    if(front== -1 && rear== -1){
        cout<<endl<<"Queue is empty!!"<<endl;
    }
    else{
        int i= front;
        cout<<endl<<"Queue is: ";
        while(i != rear){
            cout<<queue[i]<<" ";
            i = (i+1)%n;
        }
        cout<<queue[i]<<endl;
    }
}

int main()
{

    int choice;

    while (1)
    {
        cout << endl
             << "Press--> "
             << "1.Enqueue "
             << "2.Dequeue "
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
            int element;
            if (front == ((rear + 1) % n))
            {
                cout << endl
                     << "Overflow condition!! " << endl;
            }
            else
            {
                cout << endl
                     << "Enter the element to insert: ";
                cin >> element;
                enqueue(element);
            }
        }
        break;
        case 2:
        {
            if (front== -1 && rear == -1)
            {
                cout << endl
                     << "Underflow condition!!" << endl;
            }
            else
            {
                dequeue();
            }
        }
        break;
        case 3:
        {
            if (front== -1 && rear == -1)
            {
                cout << endl
                     << "Queue is empty!!" << endl;
            }
            else
            {
                peek();
            }
        }
        break;
        case 4:
        {
           if (front== -1 && rear == -1)
            {
                cout << endl
                     << "Yes: Queue is empty!!" << endl;
            }
            else
            {
                cout << endl
                     << "No: Queue is not empty!!" << endl;
            }
        }
        break;
        case 5:
        {
            if (front == ((rear+1)%n))
            {
                cout << endl
                     << "Yes: Queue is full!!" << endl;
            }
            else
            {
                cout << endl
                     << "No: Queue is not full!!" << endl;
            }
        }
        break;
        case 6:
        {
            display();
        }
        break;
        case 0:
            exit(0);
        default:
            cout << endl
                 << "Entered invalid choice" << endl;
        }
    }
}