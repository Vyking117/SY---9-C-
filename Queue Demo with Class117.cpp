#include <iostream>
using namespace std;

class Queue
{
private:
    int queue[5];
    int front, rear;
    int size;

public:
    // Constructor
    Queue()
    {
        size = 5;
        front = -1;
        rear = -1;
    }

    // Insert an element
    void enqueue(int value)
    {
        if (rear == size - 1)
        {
            cout << "Queue Overflow! Queue is Full.\n";
            return;
        }

        if (front == -1)
            front = 0;

        rear++;
        queue[rear] = value;

        cout << "Element Inserted Successfully.\n";
    }

    // Delete an element
    void dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue Underflow! Queue is Empty.\n";
            front = rear = -1;
            return;
        }

        cout << "Deleted Element: " << queue[front] << endl;

        front++;

        if (front > rear)
        {
            front = rear = -1;
        }
    }

    // Display queue
    void display()
    {
        if (front == -1)
        {
            cout << "Queue is Empty.\n";
            return;
        }

        cout << "Queue Elements: ";

        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }

        cout << endl;
    }

    // Show front element
    void peek()
    {
        if (front == -1)
        {
            cout << "Queue is Empty.\n";
            return;
        }

        cout << "Front Element: " << queue[front] << endl;
    }
};

int main()
{
    Queue q;
    int choice, value;

    do
    {
        cout << "\n===== LINEAR QUEUE MENU =====";
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Display";
        cout << "\n4. Peek";
        cout << "\n5. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter element: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.display();
            break;

        case 4:
            q.peek();
            break;

        case 5:
            cout << "Program Terminated.\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}
