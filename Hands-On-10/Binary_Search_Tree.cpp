#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST
{
public:
    Node *root;

    BST() : root(nullptr) {}

    Node *insert(Node *node, int value)
    {
        if (!node)
            return new Node(value);
        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);
        return node;
    }

    Node *search(Node *node, int value)
    {
        if (!node || node->data == value)
            return node;
        if (value < node->data)
            return search(node->left, value);
        return search(node->right, value);
    }

    Node *findMin(Node *node)
    {
        while (node && node->left)
            node = node->left;
        return node;
    }

    Node *remove(Node *node, int value)
    {
        if (!node)
            return node;
        if (value < node->data)
        {
            node->left = remove(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = remove(node->right, value);
        }
        else
        {
            if (!node->left)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }
            Node *temp = findMin(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
        return node;
    }

    void inOrder(Node *node)
    {
        if (node)
        {
            inOrder(node->left);
            cout << node->data << " ";
            inOrder(node->right);
        }
    }
};

void testBST()
{
    BST tree;
    tree.root = tree.insert(tree.root, 90);
    tree.insert(tree.root, 35);
    tree.insert(tree.root, 43);
    tree.insert(tree.root, 76);
    tree.insert(tree.root, 54);
    tree.insert(tree.root, 63);
    tree.insert(tree.root, 39);

    cout << "In-order traversal: ";
    tree.inOrder(tree.root);
    cout << endl;

    tree.remove(tree.root, 76);
    cout << "In-order after deleting 76: ";
    tree.inOrder(tree.root);
    cout << endl;

    tree.insert(tree.root, 22);
    cout << "In-order traversal After Adding 22: ";
    tree.inOrder(tree.root);
    cout << endl;

    tree.remove(tree.root, 43);
    cout << "In-order after deleting 43: ";
    tree.inOrder(tree.root);
    cout << endl;

    cout << "Search For Value 30:";
    if (tree.search(tree.root, 30) == 0)
    {
        cout << "Value Not Found" << endl;
    }
    cout << "Search For Value 39:";
    if (tree.search(tree.root, 39) == 0)
    {
        cout << "Value Not Found" << endl;
    }
    else
    {
        cout << "Value Found" << endl;
    }

}

int main()
{
    testBST();
    return 0;
}
