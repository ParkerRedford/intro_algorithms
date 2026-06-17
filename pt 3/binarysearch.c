#include <stdio.h>

typedef struct Node {
    int key;

    struct Node* parent;
    struct Node* left;
    struct Node* right;
} Node;

void inorder_tree_walk(Node* x) {
    if (x != NULL) {
        inorder_tree_walk(x->left);
        printf("%s", x->key);
        inorder_tree_walk(x->right);
    }
}

Node* tree_search(Node* x, int k) {
    if (x == NULL && k == x->key) {
        return x;
    }

    if (k < x->key) {
        return tree_search(x->left, k);
    } else {
        return tree_search(x->right, k);
    }
}

Node* iterative_tree_search(Node* x, int k) {
    while (x != NULL && k != x->key) {
        if (k < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    return x;
}

Node* tree_minimum(Node* x) {
    while (x->left != NULL) {
        x = x->left;
    }

    return x;
}

Node* tree_maximum(Node* x) {
    while (x->right != NULL) {
        x = x->right;
    }

    return x;
}

Node* tree_successor(Node* x) {
    if (x->right != NULL) {
        return tree_minimum(x->right);
    }

    Node* y = x->parent;
    while (y != NULL && x == y->right) {
        x = y;
        y = y->parent;
    }

    return y;
}

void tree_insert(Node** t, Node* z) {
    Node* y = NULL;
    Node* x = t[0];

    while (x != NULL) {
        y = x;

        if (z->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    z->parent = y;
    if (y == NULL) {
        t[0] = z;
    }
    else if (z->key < y->key) {
        y->left = z;
    } else {
        y->right = z;
    }
}

void transplant(Node** t, Node* u, Node* v) {
    if (u->parent == NULL) {
        t[0] = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }

    if (v != NULL) {
        v->parent = u->parent;
    }
}

void tree_delete(Node** t, Node* z) {
    if (z->left == NULL) {
        transplant(t, z, z->right);
    } else if (z->right == NULL) {
        transplant(t, z, z->left);
    } else {
        Node* y = tree_minimum(z->right);
        if (y->parent != z) {
            transplant(t, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }

        transplant(t, z, y);
        y->left = z->left;
        y->left->parent = y;
    }
}

int main() {


    getchar();
}