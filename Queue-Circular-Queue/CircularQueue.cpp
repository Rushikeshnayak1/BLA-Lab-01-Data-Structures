#include <iostream>
using namespace std;

const int MAX_SIZE = 5;
int queue[MAX_SIZE];
int front = -1;
int rear = -1;

bool isEmpty()
{
    return front == -1;
}

bool isFull()
{
    return (rear + 1) % MAX_SIZE == front;
}

void enqueue(int value)
{
    if (isFull())
    {
        cout << "Queue is full! Cannot add " << value << endl;
        return;
    }

    if (isEmpty())
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX_SIZE;
    }

    queue[rear] = value;
    cout << value << " added to the Circular Queue." << endl;
}

void dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty! Nothing to remove." << endl;
        return;
    }

    cout << queue[front] << " removed from the Circular Queue." << endl;

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % MAX_SIZE;
    }
}

void peek()
{
    if (isEmpty())
    {
        cout << "Queue is empty." << endl;
        return;
    }

    cout << "Front element is: " << queue[front] << endl;
}

void display()
{
    if (isEmpty())
    {
        cout << "Queue is empty." << endl;
        return;
    }

    cout << "\nCircular Queue elements:" << endl;

    int i = front;

    while (true)
    {
        cout << queue[i] << " ";

        if (i == rear)
            break;

        i = (i + 1) % MAX_SIZE;
    }

    cout << endl;
    cout << "Front index: " << front << endl;
    cout << "Rear index: " << rear << endl;
}

int main()
{
    int choice;
    int value;

    do
    {
        cout << "\n===== CIRCULAR QUEUE MENU =====" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                cout << "Program ended." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 5);

    return 0;
}
