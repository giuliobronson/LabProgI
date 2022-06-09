#include <iostream>

template<typename T>
class BST;

template<typename T>
struct Node 
{
friend class BST<T>;

private:
    T key;
    Node *left;
    Node *right;

public:
    Node(T key) : key(key), left(NULL), right(NULL) {
    }
};

template<typename T>
class BST
{
private:
    Node<T> *root;

    Node<T> *search(Node<T> *root, T key) {
        if(!root) return NULL;
        else if(root->key == key) return root;
        else if(key < root->key && root->left) return search(root->left, key);
        else if(key > root->key && root->right) return search(root->right, key);
        return root;
    }

public:
    BST() : root(NULL) {
    }

    bool find(T key) {
        return search(this->root, key) != NULL;
    }

    BST &insert(T key) {
        Node<T> *aux = search(this->root, key);
        if(!aux) {
            Node<T> *node = new Node(key);
            this->root = node;
        }
        else if(aux->key == key) return *this;
        else {
            Node<T> *bst = new Node(key);
            if(key < aux->key) aux->left = bst;
            else aux->right = bst;
        }
        return *this;
    }
};

int main() {
    BST<int> b;

    b.insert(50);
    b.insert(20);
    b.insert(30);
    b.insert(60);
    b.insert(70);
    b.insert(40);

    return 0;
}