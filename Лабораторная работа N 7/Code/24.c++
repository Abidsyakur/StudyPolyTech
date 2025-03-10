#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;
    int height;
};

Node* createNode(int key) {
    Node* newNode = new Node;
    newNode->key = key;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->height = 1;
    return newNode;
}

int height(Node* n) { return n ? n->height : 0; }
int balanceFactor(Node* n) { return n ? height(n->left) - height(n->right) : 0; }

Node* rotateRight(Node* y) {
    Node* x = y->left;
    y->left = x->right;
    x->right = y;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

Node* rotateLeft(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

Node* balance(Node* node) {
    node->height = max(height(node->left), height(node->right)) + 1;
    int balance = balanceFactor(node);
    
    if (balance > 1 && balanceFactor(node->left) >= 0)
        return rotateRight(node);
    if (balance > 1 && balanceFactor(node->left) < 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balance < -1 && balanceFactor(node->right) <= 0)
        return rotateLeft(node);
    if (balance < -1 && balanceFactor(node->right) > 0) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

Node* insert(Node* node, int key) {
    if (!node) return createNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return balance(node);
}

void inOrder(Node* node) {
    if (node) {
        inOrder(node->left);
        cout << node->key << " ";
        inOrder(node->right);
    }
}
void preOrder(Node* node) {
    if (node) {
        cout << node->key << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}
void postOrder(Node* node) {
    if (node) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->key << " ";
    }
}

vector<vector<int>> generateMatrix(int rows, int cols) {
    vector<vector<int>> matrix(rows, vector<int>(cols));
    srand(time(0));
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = rand() % 100;
    return matrix;
}

int sequentialSearch(const vector<int>& row, int key, int& comparisons) {
    comparisons = 0;
    for (int i = 0; i < row.size(); i++) {
        comparisons++;
        if (row[i] == key)
            return i;
    }
    return -1;
}

int binarySearch(const vector<int>& row, int key, int& comparisons) {
    int left = 0, right = row.size() - 1;
    comparisons = 0;
    while (left <= right) {
        comparisons++;
        int mid = left + (right - left) / 2;
        if (row[mid] == key)
            return mid;
        else if (row[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int rows, cols;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;
    
    if (rows <= 0 || cols <= 0) {
        cout << "Invalid matrix size. Exiting...\n";
        return 0;
    }
    
    vector<vector<int>> matrix = generateMatrix(rows, cols);
    Node* root = nullptr;
    
    cout << "Generated Matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
            if (i % 2 == 0)
                root = insert(root, matrix[i][j]);
        }
        cout << endl;
    }
    
    int key;
    cout << "\nEnter a number to search: ";
    cin >> key;
    
    cout << "\nSearching for " << key << " in even rows:\n";
    for (int i = 0; i < rows; i += 2) {
        vector<int> row = matrix[i];
        int seqComp = 0, binComp = 0;
        
        int seqIndex = sequentialSearch(row, key, seqComp);
        sort(row.begin(), row.end());
        int binIndex = binarySearch(row, key, binComp);
        
        cout << "Row " << i << " - Sequential: " << (seqIndex != -1 ? "Found" : "Not Found") << ", Comparisons: " << seqComp;
        cout << ", Binary: " << (binIndex != -1 ? "Found" : "Not Found") << ", Comparisons: " << binComp << endl;
    }
    
    cout << "\nAVL Tree Traversals:\n";
    cout << "InOrder: "; inOrder(root); cout << endl;
    cout << "PreOrder: "; preOrder(root); cout << endl;
    cout << "PostOrder: "; postOrder(root); cout << endl;
    
    return 0;
}
