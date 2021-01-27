#include <stdio.h>
#include <stdlib.h>

struct node {

    int data;
    struct node* left;
    struct node* right;
    int height;
};

struct node* create_node(int d)
{
    struct node *newnode =(struct node*)malloc(sizeof(struct node));
    newnode->data=d;
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->height=1;
    return newnode;
}

int  Max(int a,int b)
{
    return (a>b) ? a : b;
}

int height(struct node* ptr)
{
    if(ptr==NULL)
        return 0;
    else return ptr->height;
}

int getBalance(struct node *ptr)
{
    if(ptr==NULL)
        return 0;
    else return height(ptr->left)-height(ptr->right);
}

struct node* left_rotate(struct node* x)
{
    struct node* y=x->right;
    struct node* b=y->left;

    y->left=x;
    x->right=b;

    x->height=Max(height(x->left),height(x->right))+1;
    y->height=Max(height(y->left),height(y->right))+1;
    return y;
}

struct node*right_rotate(struct node* y)
{
    struct node* x=y->left;
    struct node* b=x->right;

    x->right=y;
    y->left=b;

    x->height=Max(height(x->left),height(x->right))+1;
    y->height=Max(height(y->left),height(y->right))+1;

    return x;
}

struct node* insertNode(struct node *head,int d)
{
    if(head == NULL)
    return create_node(d);
    
    if(d < head->data)
        head->left=insertNode(head->left,d);
    else if(d > head->data)
        head->right=insertNode(head->right,d);
    else return head;

    head->height=1+ Max(height(head->left),height(head->right));
    int balance=getBalance(head);

    if(balance>1 && d < head->left->data)
    {
        return right_rotate(head);
    }
    else if (balance>1 && d > head->left->data)
    {
        head->left=left_rotate(head->left);
        return right_rotate(head);
    }
    else if(balance <-1 && d>head->right->data)
    {
        return left_rotate(head);
    }  
    else if(balance <-1 && d<head->right->data)
    {
        head->right=right_rotate(head->right);
        return left_rotate(head);
    }

    return head;

}

void printPreOrder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

int main() {
     struct node *root = NULL;

    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 25);
    //root = insertNode(root, 8);

    printPreOrder(root);


   // printf("\nAfter deletion: ");
    //printPreOrder(root);

    return 0;
}

