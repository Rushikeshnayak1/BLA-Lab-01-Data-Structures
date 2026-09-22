#include <iostream>
using namespace std;

const int MAX_SIZE = 5;
int stack[MAX_SIZE];
int top = -1;

void push(int value)
{
    if (top == MAX_SIZE - 1)
    {
        cout << "Stack Overflow! Cannot push " << value << endl;
        return;
    }

    top++;
    stack[top] = value;
    cout << value << " pushed into the stack." << endl;
}

void pop()
{
    if (top == -1)
    {
        cout << "Stack Underflow! Stack is empty." << endl;
        return;
    }

    cout << stack[top] << " popped from the stack." << endl;
    top--;
}

void peek()
{
    if (top == -1)
    {
        cout << "Stack is empty." << endl;
        return;
    }

    cout << "Top element is: " << stack[top] << endl;
}

void display()
{
    if (top == -1)
    {
        cout << "Stack is empty." << endl;
        return;
    }

    cout << "\nStack elements from TOP to BOTTOM:" << endl;

    for (int i = top; i >= 0; i--)
    {
        cout << stack[i] << endl;
    }
}

int main()
{
    int choice;
    int value;

    do
    {
        cout << "\n===== STACK MENU =====" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(value);
                break;

            case 2:
                pop();
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
