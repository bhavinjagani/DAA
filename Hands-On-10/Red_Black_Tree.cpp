#include <iostream>
using namespace std;

enum Color {RED, BLACK};

class RBNode {
public:
    int data;
    bool color; // 0 for BLACK, 1 for RED
    RBNode *left, *right, *parent;

    RBNode(int value) : data(value), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RBTree {
private:
    RBNode *root;

    void rotateLeft(RBNode *&node) {
        RBNode *rightChild = node->right;
        node->right = rightChild->left;

        if (node->right)
            node->right->parent = node;

        rightChild->parent = node->parent;

        if (!node->parent)
            root = rightChild;
        else if (node == node->parent->left)
            node->parent->left = rightChild;
        else
            node->parent->right = rightChild;

        rightChild->left = node;
        node->parent = rightChild;
    }

    void rotateRight(RBNode *&node) {
        RBNode *leftChild = node->left;
        node->left = leftChild->right;

        if (node->left)
            node->left->parent = node;

        leftChild->parent = node->parent;

        if (!node->parent)
            root = leftChild;
        else if (node == node->parent->left)
            node->parent->left = leftChild;
        else
            node->parent->right = leftChild;

        leftChild->right = node;
        node->parent = leftChild;
    }

    void fixInsertion(RBNode *&node) {
        RBNode *parent = nullptr;
        RBNode *grandparent = nullptr;

        while (node != root && node->color == RED && node->parent->color == RED) {
            parent = node->parent;
            grandparent = parent->parent;

            if (parent == grandparent->left) {
                RBNode *uncle = grandparent->right;
                if (uncle && uncle->color == RED) {
                    grandparent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    node = grandparent;
                } else {
                    if (node == parent->right) {
                        rotateLeft(parent);
                        node = parent;
                        parent = node->parent;
                    }
                    rotateRight(grandparent);
                    swap(parent->color, grandparent->color);
                    node = parent;
                }
            } else {
                RBNode *uncle = grandparent->left;
                if (uncle && uncle->color == RED) {
                    grandparent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    node = grandparent;
                } else {
                    if (node == parent->left) {
                        rotateRight(parent);
                        node = parent;
                        parent = node->parent;
                    }
                    rotateLeft(grandparent);
                    swap(parent->color, grandparent->color);
                    node = parent;
                }
            }
        }
        root->color = BLACK;
    }

    RBNode* minNode(RBNode* node) {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    void fixDeletion(RBNode *&node) {
        while (node != root && node->color == BLACK) {
            if (node == node->parent->left) {
                RBNode *sibling = node->parent->right;

                if (sibling->color == RED) {
                    sibling->color = BLACK;
                    node->parent->color = RED;
                    rotateLeft(node->parent);
                    sibling = node->parent->right;
                }

                if (sibling->left->color == BLACK && sibling->right->color == BLACK) {
                    sibling->color = RED;
                    node = node->parent;
                } else {
                    if (sibling->right->color == BLACK) {
                        sibling->left->color = BLACK;
                        sibling->color = RED;
                        rotateRight(sibling);
                        sibling = node->parent->right;
                    }

                    sibling->color = node->parent->color;
                    node->parent->color = BLACK;
                    sibling->right->color = BLACK;
                    rotateLeft(node->parent);
                    node = root;
                }
            } else {
                RBNode *sibling = node->parent->left;

                if (sibling->color == RED) {
                    sibling->color = BLACK;
                    node->parent->color = RED;
                    rotateRight(node->parent);
                    sibling = node->parent->left;
                }

                if (sibling->right->color == BLACK && sibling->left->color == BLACK) {
                    sibling->color = RED;
                    node = node->parent;
                } else {
                    if (sibling->left->color == BLACK) {
                        sibling->right->color = BLACK;
                        sibling->color = RED;
                        rotateLeft(sibling);
                        sibling = node->parent->left;
                    }

                    sibling->color = node->parent->color;
                    node->parent->color = BLACK;
                    sibling->left->color = BLACK;
                    rotateRight(node->parent);
                    node = root;
                }
            }
        }
        node->color = BLACK;
    }

    RBNode* deleteNode(RBNode* root, int value) {
        if (!root) return root;

        if (value < root->data) {
            root->left = deleteNode(root->left, value);
        } else if (value > root->data) {
            root->right = deleteNode(root->right, value);
        } else { 
            if (!root->left || !root->right) { 
                RBNode *temp = root->left ? root->left : root->right;

                if (!temp) {
                    temp = root;
                    root = nullptr;
                } else { 
                    *root = *temp; 
                }
                delete temp; 
            } else {
                RBNode* temp = minNode(root->right); 
                root->data = temp->data; 
                root->right = deleteNode(root->right, temp->data); 
            }
        }

        if (!root) return root; 

        if (root->color == BLACK) {
            fixDeletion(root);
        }

        return root; 
    }

public:
    RBTree() : root(nullptr) {}

    void insert(int value) {
        RBNode *node = new RBNode(value);
        root = bstInsert(root, node);
        fixInsertion(node);
    }

    RBNode* bstInsert(RBNode *root, RBNode *node) {
        if (!root) return node;

        if (node->data < root->data) {
            root->left = bstInsert(root->left, node);
            root->left->parent = root;
        } else if (node->data > root->data) {
            root->right = bstInsert(root->right, node);
            root->right->parent = root;
        }
        return root;
    }

    bool search(RBNode* node, int value) {
        if (!node)
            return false;
        if (node->data == value)
            return true;
        else if (value < node->data)
            return search(node->left, value);
        else
            return search(node->right, value);
    }

    void inOrder(RBNode *node) {
        if (node) {
            inOrder(node->left);
            cout << node->data << (node->color == RED ? "(R) " : "(B) ");
            inOrder(node->right);
        }
    }

    RBNode* getRoot() {
        return root;
    }

    void deleteValue(int value) {
        root = deleteNode(root, value);
    }

    bool searchValue(int value) {
        return search(root, value);
    }
};

void testRBTree() {
    RBTree tree;
    tree.insert(13);
    tree.insert(67);
    tree.insert(28);
    tree.insert(32);
    tree.insert(90);
    tree.insert(55);
    tree.insert(72);

    cout << "In-order traversal of the Red-Black Tree with colors: ";
    tree.inOrder(tree.getRoot());
    cout << endl;

    int searchValue = 28;
    cout << "Searching for " << searchValue << ": " << (tree.searchValue(searchValue) ? "Found" : "Not Found") << endl;

    tree.deleteValue(90);
    cout << "In-order traversal after deleting 90: ";
    tree.inOrder(tree.getRoot());
    cout << endl;

}

int main()
{
    testRBTree();
    return 0;
}
