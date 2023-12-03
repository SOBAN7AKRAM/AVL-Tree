#include <iostream> 
using namespace std;
struct Node
{
    int val;
    Node* left;
    Node* right;
    int height;
    Node(int val)
    {
        left = nullptr;
        right = nullptr;
        this -> val = val;
        height = 1;
    }
};
int getHeight(Node* root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return root -> height;
}
int getBalanceFactor(Node* root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return getHeight(root -> left) - getHeight(root -> right);
}
Node* leftRotate(Node* x)
{
    Node* y = x -> right;
    Node* T2 = y -> left;

    x -> right = T2;
    y -> left = x;

    x -> height = max(getHeight(x -> right), getHeight(x -> left));
    y -> height = max(getHeight(y -> right), getHeight(y -> left));

    return y;
}
Node* rightRotate(Node* y)
{
    Node* x = y -> left;
    Node* T2 = x -> right;
    x -> right = y;
    y -> left = T2;
    x -> height = max(getHeight(x -> right), getHeight(x -> left));
    y -> height = max(getHeight(y -> right), getHeight(y -> left));
    return x;
}
Node* insert(Node* root, int key)
{
    if (root == nullptr)
    {
        Node* temp = new Node(key);
        return temp;
    }
    if (key > root -> val)
    {
        root -> right = insert(root -> right, key);
    }
    else if (key < root -> val)
    {
        root -> left = insert(root -> left, key);
    }
    root -> height = 1 + max(getHeight(root -> left), getHeight(root -> right));
    int bf = getBalanceFactor(root);

    // Left Left Case
    if (bf > 1 && key < root -> left -> val)
    {
        return rightRotate(root);
    }
    // Right Right Case
    if (bf < -1 && key > root -> right -> val)
    {
        return leftRotate(root);
    }
    // Left Right Case
    if (bf > 1 && key > root -> left -> val)
    {
        root -> left = leftRotate(root -> left);
        return rightRotate(root);
    }
    // Right Left Case
    if (bf < -1 && key < root -> right -> val)
    {
        root -> right = rightRotate(root -> right);
        return leftRotate(root);
    }
    return root;
}
Node* deletion(Node* root, int key)
{
    
}
void preOrder(Node* root)
{
    if (root != nullptr)
    {
        cout << root -> val << " ";
        preOrder(root -> left);
        preOrder(root -> right);
    }
}




int main()
{
    Node* root = new Node(9);
    root = insert(root, 8);
    root = insert(root, 15);
    root = insert(root, 11);
    root = insert(root, 20);
    root = insert(root, 17);
    preOrder(root);

}