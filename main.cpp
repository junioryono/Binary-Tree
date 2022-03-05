// Name: Amer Yono
// Student ID: 200711334
// Email: yono004@cougars.csusm.edu
#include <iostream>
using namespace std;

class BinaryTree {
    private:
        struct Node {
            int data;
            struct Node *left;
            struct Node *right;
        };
        struct Node *root;

    public:
        BinaryTree() {
            root = NULL;
        }
   
        bool isEmpty() {
            return root == NULL;
        }

        void insert(int data) {
            root = insertNode(root, data);
        }
      
        struct Node *insertNode(struct Node *tree, int data) {
            if (!tree) {
                Node *newNode = new Node;
                newNode->data = data;
                newNode->left = NULL;
                newNode->right = NULL;
                return newNode;
            }
            if (tree->data < data) tree->right = insertNode(tree->right, data);
            else if (tree->data > data) tree->left = insertNode(tree->left, data);
            return tree;
        }

        void printTree(string type) {
            if (type == "inorderTraversal") {
                cout << "Inorder Traversal:\n";
                inorderTraversal(root);
            } else if (type == "preorderTraversal") {
                cout << "Preorder Traversal:\n";
                preorderTraversal(root);
            } else if (type == "postorderTraversal") {
                cout << "Postorder Traversal:\n";
                postorderTraversal(root);
            }
        }

        void inorderTraversal(struct Node *root) {
            if (!root) return;
            inorderTraversal(root->left);
            cout << root->data << " ";
            inorderTraversal(root->right);  
        }

        void preorderTraversal(struct Node *root) {
            if (!root) return;
            cout << root->data << " ";
            preorderTraversal(root->left);
            preorderTraversal(root->right);  
        }

        void postorderTraversal(struct Node *root) {
            if (!root) return;
            postorderTraversal(root->left);
            postorderTraversal(root->right); 
            cout << root->data << " "; 
        }

        struct Node *searchNode(struct Node *root, int data) {
            if (root == NULL || root->data == data) return root;
            if (root->data < data) return searchNode(root->right, data);
            return searchNode(root->left, data);
        }

        void search(int key) {
            if (searchNode(root, key)) cout << key << " found\n\n";
            else cout << key << " not found\n\n";
        }
        
        void remove(int key) {
            root = remove(root, key);
        }

        struct Node *mininumNode(struct Node *tree) {
            while (tree->left) tree = tree->left;
            return tree;
        }

        struct Node *remove(struct Node *tree, int key) {
            Node *temp;
            if (!tree) return NULL;
            else if (tree->data < key) tree->right = remove(tree->right, key);
            else if (tree->data > key) tree->left = remove(tree->left, key);
            else if (tree->data == key) {
                if (!tree->left) {
                    temp = tree->right;
                    delete(tree);
                    return temp;
                }
                if (!tree->right) {
                    temp = tree->left;
                    delete(tree);
                    return temp;
                }
                temp = mininumNode(tree->right);
                tree->data = temp->data;
                remove(tree->right, temp->data);
            } else cout << "Node not found\n";
            return tree;
        }
};

int main() {
    int menuNumber;
    int menuData;
    BinaryTree BST;
    do {
        cout << "Choose a menu number:\n";
        cout << "1) Insert Node\n2) Traversal Preorder\n3) Traversal Inorder\n4) Traversal Postorder\n5) Search Node\n6) Delete Node\n7) Quit\n\n";
        cout << "Menu Number: ";
        cin >> menuNumber;
        switch (menuNumber) {
            case 1: {
                cout << "Enter Node Data: ";
                cin >> menuData;
                BST.insert(menuData);
                system("CLS");
                break;
            }
            case 2: {
                system("CLS");
                BST.printTree("inorderTraversal");
                cout << "\n\n";
                break;
            }
            case 3: {
                system("CLS");
                BST.printTree("preorderTraversal");
                cout << "\n\n";
                break;
            }
            case 4: {
                system("CLS");
                BST.printTree("postorderTraversal");
                cout << "\n\n";
                break;
            }
            case 5: {
                cout << "Search: ";
                cin >> menuData;
                system("CLS");
                BST.search(menuData);
                break;
            }
            case 6: {
                cout << "Remove: ";
                cin >> menuData;
                
                BST.remove(menuData);
                break;
            }
            case 7: {
                break;
            }
            default: {
                system("CLS");
                cout << "Bad Input!\n\n";
                break;
            }
        }
    } while (menuNumber != 7);
    return 0;
}