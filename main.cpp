#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;

struct Node
{
    int id, quantity, height;
    string name;
    Node *left, *right;

    Node(int i, string n, int q) 
{
        id = i;
        name = n;
        quantity = q;
        height = 1;
        left = right = nullptr;
    }
};

int height(Node* n)
{
    return n ? n->height : 0;
}

int balance(Node* n)
{
    return n ? height(n->left) - height(n->right) : 0;
}

void updateHeight(Node* n) 
{
    n->height = 1 + max(height(n->left), height(n->right));
}

Node* rightRotate(Node* y)
{
    Node* x = y->left;
    Node* t = x->right;

    x->right = y;
    y->left = t;

    updateHeight(y);
    updateHeight(x);

    cout << "LL Rotation applied\n";
    return x;
}

Node* leftRotate(Node* x) 
{
    Node* y = x->right;
    Node* t = y->left;

    y->left = x;
    x->right = t;

    updateHeight(x);
    updateHeight(y);

    cout << "RR Rotation applied\n";
    return y;
}

Node* insert(Node* root, int id, string name, int qty)
{
    if (!root)
        return new Node(id, name, qty);

    if (id < root->id)
        root->left = insert(root->left, id, name, qty);
    else if (id > root->id)
        root->right = insert(root->right, id, name, qty);
    else
{
        cout << "Duplicate Product ID!\n";
        return root;
    }

    updateHeight(root);
    int bf = balance(root);

    // LL case
    if (bf > 1 && id < root->left->id)
        return rightRotate(root);

    // RR case
    if (bf < -1 && id > root->right->id)
        return leftRotate(root);

    // LR case
    if (bf > 1 && id > root->left->id) 
{
        cout << "LR Rotation applied\n";
        root->left = leftRotateSilent(root->left);
        return rightRotateSilent(root);
    }

    // RL case
    if (bf < -1 && id < root->right->id) 
{
        cout << "RL Rotation applied\n";
        root->right = rightRotateSilent(root->right);
        return leftRotateSilent(root);
    }

    return root;
}

// Rotation helpers for double rotations
Node* leftRotateSilent(Node* x)
{
    Node* y = x->right;
    Node* t = y->left;
    y->left = x;
    x->right = t;
    updateHeight(x);
    updateHeight(y);
    return y;
}

Node* rightRotateSilent(Node* y) 
{
    Node* x = y->left;
    Node* t = x->right;
    x->right = y;
    y->left = t;
    updateHeight(y);
    updateHeight(x);
    return x;
}

void display(Node* root) 
{
    if (!root) return;

    display(root->left);

    cout << left << setw(12) << root->id
         << setw(20) << root->name
         << setw(12) << root->quantity
         << setw(10) << balance(root) << '\n';

    display(root->right);
}

Node* search(Node* root, int id) 
{
    if (!root || root->id == id)
        return root;

    if (id < root->id)
        return search(root->left, id);

    return search(root->right, id);
}

int main() 
{
    Node* root = nullptr;
    int choice, id, qty;
    string name;

    do {
        cout << "\n--- AVL Inventory Management ---\n";
        cout << "1. Insert Product\n";
        cout << "2. Display Inventory and Balance Factors\n";
        cout << "3. Search Product\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) 
{
        case 1:
            cout << "Enter Product ID: ";
            cin >> id;

            cout << "Enter Product Name: ";
            cin >> ws;
            getline(cin, name);

            cout << "Enter Quantity: ";
            cin >> qty;

            if (qty < 0)
{
                cout << "Quantity cannot be negative!\n";
                break;
            }

            root = insert(root, id, name, qty);
            break;

        case 2:
            if (!root)
{
                cout << "Inventory is empty!\n";
                break;
            }

            cout << "\nProduct ID  Product Name       "
                 << "Quantity    Balance\n";
            cout << "---------------------------------------------\n";
            display(root);
            cout << "\nBalance Factor = Height(left) - Height(right)\n";
            break;

        case 3:
            cout << "Enter Product ID to search: ";
            cin >> id;

            {
                Node* result = search(root, id);
                if (result)
                    cout << "Found: " << result->name
                         << ", Quantity: " << result->quantity
                         << ", Balance Factor: "
                         << balance(result) << '\n';
                else
                    cout << "Product not found!\n";
            }
            break;

        case 4:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
