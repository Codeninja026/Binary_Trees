#include <stdio.h>
#include <stdlib.h>

struct node
{
 int key;
 struct node *lchild;
 struct node *rchild;
 int height;
};
struct node *root=NULL;

int height(struct node*);
int balanceFactor(struct node*);
int max(int,int);
struct node *leftRotate(struct node*);
struct node *rightRotate(struct node*);
struct node *createNode(int);
struct node *insert(struct node*,int);
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);


int main()
{
    int ch,key;
    while(1)
    {
        printf("\n");
        printf("1. insert node:\n");
        printf("2. inorder:\n");
        printf("3. preorder:\n");
        printf("4. postorder:\n");
        printf("6. exit: \n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {

            case 1:printf("Enter the item to be inserted: ");
                    scanf("%d",&key);
                    root=insert(root,key);
                    break;
            case 2:inorder(root);
                    break;
            case 3: preorder(root);
                    break;
            case 4: postorder(root);
                    break;
            case 6: printf(".......................program terminated.........................");
                    exit(0);

            default: printf("Invalid choise..");
            
        }
    }
    return 0; 
}

void inorder(struct node *root)
{
    struct node *ptr;
    ptr=root;
    if(ptr)
    {
        inorder(ptr->lchild);
        printf("%d ",ptr->key);
        inorder(ptr->rchild);
    }
}
void preorder(struct node* root)
{
    struct node *ptr;
    ptr=root;
    if(ptr)
    {
        printf("%d ",ptr->key);
        preorder(ptr->lchild);
        preorder(ptr->rchild);
    }
}

void postorder(struct node* root)
{
    struct node* ptr;
    ptr=root;
    if(ptr)
    {
        postorder(ptr->lchild);
        postorder(ptr->rchild);
        printf("%d ",ptr->key);
    }
     
}
int height(struct node *ptr)
{
 if(ptr==NULL)
 return 0;
 return ptr->height;
}
int max(int a, int b)
{
    return (a>b)?a:b;
}
int balanceFactor(struct node *n)
{
 if(n==NULL)
 {
    return 0;
 }
 return height(n->lchild) - height(n->rchild);
}
struct node* rightRotate(struct node* y)
{
 struct node *x = y->lchild;
 struct node *T2 = x->rchild;
 x->rchild = y;
 y->lchild = T2;
 y->height = max(height(y->lchild),
 height(y->rchild)) + 1;
 x->height = max(height(x->lchild),
 height(x->rchild)) + 1;
 return x;
}
struct node* leftRotate(struct node* x)
{
 struct node *y = x->rchild;
 struct node *T2 = y->lchild;
 y->lchild = x;
 x->rchild = T2;
 x->height = max(height(x->lchild),
 height(x->rchild)) + 1;
 y->height = max(height(y->lchild),
 height(y->rchild)) + 1;
 return y;
}
struct node *createNode(int key){
 struct node* newnode = (struct node *) malloc(sizeof(struct node));
 newnode->key = key;
 newnode->lchild = NULL;
 newnode->rchild = NULL;
 newnode->height = 1;
 return newnode;
}
struct node *insert(struct node* node, int key)
{
 if (node == NULL)
 return createNode(key);
 if (key < node->key)
 node->lchild = insert(node->lchild, key);
 else if (key > node->key)
 node->rchild = insert(node->rchild, key);
 node->height = 1 + max(height(node->lchild), height(node->rchild));
 int bf = balanceFactor(node);
 if(bf>1 && key < node->lchild->key)
 {
    return rightRotate(node);
 }
 if(bf<-1 && key > node->rchild->key)
 {
    return leftRotate(node);
 }
 if(bf>1 && key > node->lchild->key)
 {
 node->lchild = leftRotate(node->lchild);
    return rightRotate(node);
 }
 if(bf<-1 && key < node->rchild->key)
 {
    node->rchild = rightRotate(node->rchild);
    return leftRotate(node);
 }
 return node;
}

 
