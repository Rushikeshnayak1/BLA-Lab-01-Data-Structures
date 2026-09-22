#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node* insertNode(Node* root, int value)
{
    if (root == nullptr)
    {
        cout << value << " inserted into the BST." << endl;
        return new Node(value);
    }

    if (value < root->data)
    {
        root->left = insertNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insertNode(root->right, value);
    }
    else
    {
        cout << value << " is a duplicate. Ignored." << endl;
    }

    return root;
}

void inorder(Node* root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void preorder(Node* root)
{
    if (root != nullptr)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root)
{
    if (root != nullptr)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main()
{
    Node* root = nullptr;

    int values[] =
    {
        52, 31, 74, 18, 43,
        63, 86, 27, 47, 59,
        68, 79, 92, 31, 74
    };

    int size = sizeof(values) / sizeof(values[0]);

    cout << "===== BINARY SEARCH TREE =====" << endl;
    cout << "\nBuilding the BST..." << endl;
    cout << "----------------------------" << endl;

    for (int i = 0; i < size; i++)
    {
        root = insertNode(root, values[i]);
    }

    cout << "\n\nInorder Traversal:" << endl;
    cout << "LEFT -> ROOT -> RIGHT" << endl;
    inorder(root);

    cout << "\n\nPreorder Traversal:" << endl;
    cout << "ROOT -> LEFT -> RIGHT" << endl;
    preorder(root);

    cout << "\n\nPostorder Traversal:" << endl;
    cout << "LEFT -> RIGHT -> ROOT" << endl;
    postorder(root);

    cout << "\n\nProgram completed." << endl;

    return 0;
}
