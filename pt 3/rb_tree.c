#include <stdio.h>

enum color {red, black};

typedef struct Node {
    int key;
    enum color color;

    struct Node* p;
    struct Node* left;
    struct Node* right;
} Node;

Node* tree_minimum(Node* x) {
    while (x->left != NULL) {
        x = x->left;
    }

    return x;
}

void left_rotate(Node** t, Node* x) {
    Node* y = x->right;
    x->right = y->left;

    if (y->left != NULL) {
        y->left->p = x;
    }

    y->p = x->p;

    if (x->p == NULL) {
        t[0] = y;
    } else if (x == x->p->left) {
        x->p->left = y;
    } else {
        x->p->right = y;
    }

    y->left = x;
    x->p = y;
}

void right_rotate(Node** t, Node* x) {
    Node* y = x->left;
    x->left = y->right;

    if (y->right != NULL) {
        y->right->p = x;
    }

    y->p = x->p;

    if (x->p == NULL) {
        t[0] = y;
    } else if (x == x->p->right) {
        x->p->right = y;
    } else {
        x->p->left = y;
    }

    y->right = x;
    x->p = y;
}

void rb_insert_fixup(Node** t, Node* z) {
    Node* y = NULL;

    while (z->p->color == red) {
        if (z->p == z->p->p->left) {
            y = z->p->p->right;

            if (y->color == red) {
                z->p->color = black;
                y->color = black;
                z->p->p->color = red;
                z = z->p->p;
            } else if (z == z->p->right) {
                z = z->p;
                left_rotate(t, z);
            }

            z->p->color = black;
            z->p->p->color = red;
            right_rotate(t, z->p->p);
        } else {
            y = z->p->p->left;

            if (y->color == red) {
                z->p->color = black;
                y->color = black;
                z->p->p->color = red;
                z = z->p->p;
            } else if (z == z->p->left) {
                z = z->p;
                right_rotate(t, z);
            }

            z->p->color = black;
            z->p->p->color = red;
            left_rotate(t, z->p->p);
        }
    }

    t[0]->color = black;
}

void rb_insert(Node** t, Node* z) {
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

    z->p = y;

    if (y == NULL) {
        t[0] = z;
    } else if (z->key < y->key) {
        y->left = z;
    } else {
        y->right = z;
    }

    z->left = NULL;
    z->right = NULL;
    z->color = red;

    rb_insert_fixup(t, z);
}

void rb_transplant(Node** t, Node* u, Node* v) {
    if (u->p == NULL) {
        t[0] = v;
    } else if (u == u->p->left) {
        u->p->left = v;
    } else {
        u->p->right = v;
    }

    v->p = u->p;

    free(u);
}

void rb_delete(Node** t, Node* z) {
    Node* y = z;
    Node* x;
    enum color yc = y->color;

    if (z->left == NULL) {
        x = z->right;
        rb_transplant(t, z, z->left);
    } else if (z->right == NULL) {
        x = z->left;
        rb_transplant(t, z, z->left);
    } else {
        Node* y = tree_minimum(z->right);
        yc = y->color;
        x = y->right;

        if (y->p == z) {
            x->p = y;
        } else {
            rb_transplant(t, y, y->right);
            y->right = z->right;
            y->right->p = y;
        }

        rb_transplant(t, z, y);
        y->left = z->left;
        y->left->p = y;
        y->color = z->color;
    }

    free(z);

    if (yc == black) {
        rb_delete_fixup(t, x);
    }
}

void rb_delete_fixup(Node** t, Node* x) {
    while (x != t[0] && x->color == black) {
        if (x == x->p->left) {
            Node* w = x->p->right;
            if (w->color == red) {
                w->color = black;
                x->p->color = red;
                left_rotate(t, x->p);
                w = x->p->right;
            }
            if (w->left->color == black && w->right->color == black) {
                w->color = red;
                x = x->p;
            } else if (w->right->color == black) {
                w->left->color = black;
                w->color = red;
                right_rotate(t, w);
                w = x->p->right;
            }

            w->color = x->p->color;
            x->p->color = black;
            w->right->color = black;
            left_rotate(t, x->p);
            x = t[0];
        } else {
            Node* w = x->p->left;
            if (w->color == red) {
                w->color = black;
                x->p->color = red;
                right_rotate(t, x->p);
                w = x->p->left;
            }
            if (w->right->color == black && w->left->color == black) {
                w->color = red;
                x = x->p;
            } else if (w->left->color == black) {
                w->right->color = black;
                w->color = red;
                left_rotate(t, w);
                w = x->p->left;
            }

            w->color = x->p->color;
            x->p->color = black;
            w->left->color = black;
            right_rotate(t, x->p);
            x = t[0];
        }
    }

    x->color = black;
}

int main() {

    getchar();
}