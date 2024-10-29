#include <iostream>
using namespace std;

class AVLNode
{
public:
    int data;
    AVLNode *left, *right;
    int height;

    AVLNode(int value) : data(value), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree
{
public:
    AVLNode *root;

    AVLTree() : root(nullptr) {}

    int getHeight(AVLNode *node)
    {
        return node ? node->height : 0;
    }

    int getBalance(AVLNode *node)
    {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    AVLNode *rotateRight(AVLNode *y)
    {
        AVLNode *x = y->left;
        AVLNode *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    AVLNode *rotateLeft(AVLNode *x)
    {
        AVLNode *y = x->right;
        AVLNode *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    AVLNode *insert(AVLNode *node, int value)
    {
        if (!node)
            return new AVLNode(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);
        else
            return node;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        int balance = getBalance(node);

        if (balance > 1 && value < node->left->data)
            return rotateRight(node);
        if (balance < -1 && value > node->right->data)
            return rotateLeft(node);
        if (balance > 1 && value > node->left->data)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        if (balance < -1 && value < node->right->data)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    AVLNode *minNode(AVLNode *node)
    {
        AVLNode *current = node;
        while (current && current->left)
            current = current->left;
        return current;
    }

    AVLNode *deleteNode(AVLNode *root, int value)
    {
        if (!root)
            return root;

        if (value < root->data)
            root->left = deleteNode(root->left, value);
        else if (value > root->data)
            root->right = deleteNode(root->right, value);
        else
        {
            if (!root->left)
            {
                AVLNode *temp = root->right;
                delete root;
                return temp;
            }
            else if (!root->right)
            {
                AVLNode *temp = root->left;
                delete root;
                return temp;
            }
            AVLNode *temp = minNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));
        int balance = getBalance(root);

        if (balance > 1 && getBalance(root->left) >= 0)
            return rotateRight(root);
        if (balance < -1 && getBalance(root->right) <= 0)
            return rotateLeft(root);
        if (balance > 1 && getBalance(root->left) < 0)
        {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
        if (balance < -1 && getBalance(root->right) > 0)
        {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }

        return root;
    }

    bool search(AVLNode *node, int value)
    {
        if (!node)
            return false;
        if (node->data == value)
            return true;
        else if (value < node->data)
            return search(node->left, value);
        else
            return search(node->right, value);
    }

    void inOrder(AVLNode *node)
    {
        if (node)
        {
            inOrder(node->left);
            cout << node->data << " ";
            inOrder(node->right);
        }
    }
};

void testAVLTree()
{
    AVLTree tree;
    tree.root = tree.insert(tree.root, 12);
    tree.root = tree.insert(tree.root, 45);
    tree.root = tree.insert(tree.root, 24);
    tree.root = tree.insert(tree.root, 73);
    tree.root = tree.insert(tree.root, 59);
    tree.root = tree.insert(tree.root, 90);
    tree.root = tree.insert(tree.root, 65);

    cout << "In-order traversal of the AVL tree: ";
    tree.inOrder(tree.root);
    cout << endl;

    int searchValue = 24;
    cout << "Searching for " << searchValue << ": " << (tree.search(tree.root, searchValue) ? "Found" : "Not Found") << endl;

    tree.insert(tree.root, 33);
    cout << "In-order traversal After Adding 33: ";
    tree.inOrder(tree.root);
    cout << endl;

    tree.root = tree.deleteNode(tree.root, 73);
    cout << "In-order traversal after deleting 73: ";
    tree.inOrder(tree.root);
    cout << endl;

    tree.root = tree.deleteNode(tree.root, 65);
    cout << "In-order traversal after deleting 65: ";
    tree.inOrder(tree.root);
    cout << endl;

    tree.root = tree.deleteNode(tree.root, 45);
    cout << "In-order traversal after deleting 45: ";
    tree.inOrder(tree.root);
    cout << endl;

    searchValue = 59;
    cout << "Searching for " << searchValue << ": " << (tree.search(tree.root, searchValue) ? "Found" : "Not Found") << endl;
}

int main()
{
    testAVLTree();
    return 0;
}
