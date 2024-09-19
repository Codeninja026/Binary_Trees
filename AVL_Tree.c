#include<stdio.h>
#include<stdlib.h>
struct node{
    int key;
    struct node *rchild;
    struct node *lchild;   
    int height;
};
struct node *root=NULL;

void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);

struct node *createNode(int);
struct node *insert_node(struct node*,int);

struct node *binarysearchtree(struct node*,int);//same as bst

struct node *leftRotate(struct node*);
struct node *rightRotate(struct node*);
int height (struct node*);
int balanceFactor(struct node*);
int max(int,int);
struct node *deleteNode(struct node*,int);
struct node *successor(struct node *ptr);
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
        printf("5. search of avl:\n");
        printf("6. exit: \n");
        printf("7. delete node.\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {

            case 1:printf("Enter the item to be inserted: ");
                    scanf("%d",&key);
                    root=insert_node(root,key);
                    break;
            case 2:inorder(root);
                    break;
            case 3: preorder(root);
                    break;
            case 4: postorder(root);
                    break;
           case 5: printf("Enter the key to search in avl: ");
                   scanf("%d",&key);
                   binarysearchtree(root,key);
                   break;
            case 6: printf(".......................program terminated.........................");
                    exit(0);
            case 7: printf("Enter the node to  delete: ");
                    scanf("%d",&key);
                    deleteNode(root,key);
                    printf("deleted element: %d\n",key);
                    break;

            default: printf("Invalid choise..");
            
        }
    }
    return 0; 
}
struct node *createNode(int key)
{
    struct node* newnode = (struct node *) malloc(sizeof(struct node));
    newnode->key = key;
    newnode->lchild = NULL;
    newnode->rchild = NULL;
    newnode->height = 1;
    return newnode;
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
struct node *insert_node(struct node *node,int key)
{
    
    if (node == NULL)
        return createNode(key);
    if (key < node->key)
        node->lchild = insert_node(node->lchild, key);
    else if (key > node->key)
        node->rchild = insert_node(node->rchild, key);
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
struct node* successor(struct node *ptr)
{
    struct node *ptr1;
    ptr1=ptr->rchild;
    if(ptr1!=NULL)
    {  
        while(ptr1->lchild!=NULL)
        {
            ptr1=ptr1->lchild;
        }
    }
    return ptr1;
}
struct node* deleteNode(struct node* root, int k)
{
    if (root == NULL)
        return root;
    if ( k < root->key )
        root->lchild = deleteNode(root->lchild, k);
    else if( k > root->key )
    root->rchild = deleteNode(root->rchild, k);
    else
    {
        if( (root->lchild == NULL) || (root->rchild == NULL) )
        {
            struct node *temp = root->lchild ? root->lchild :root->rchild;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
                free(temp);
        }  
        else
        {
             struct node* temp = successor(root);
             root->key = temp->key;
             root->rchild = deleteNode(root->rchild, temp->key);
        }
    }
 if (root == NULL)
    return root;
    root->height = 1 + max(height(root->lchild),
    height(root->rchild));
    int balance = balanceFactor(root);
    if (balance > 1 && balanceFactor(root->lchild) >= 0)
        return rightRotate(root);
    if (balance > 1 && balanceFactor(root->lchild) < 0)
    {
        root->lchild = leftRotate(root->lchild);
        return rightRotate(root);
    }
    if (balance < -1 && balanceFactor(root->rchild) <= 0)
        return leftRotate(root);
    if (balance < -1 && balanceFactor(root->rchild) > 0)
    {
        root->rchild = rightRotate(root->rchild);
        return leftRotate(root);
    }
 return root;
}
struct node* binarysearchtree(struct node *ptr,int key)
{
    if(ptr==NULL)
    {
        return ptr;
    }
    else if(ptr->key==key)
    {
        printf("node found.");
        return ptr;
    }
    else if(key<ptr->key)
    {
        return binarysearchtree(ptr->lchild,key);
    }
    else if(key>ptr->key)
    {
        return binarysearchtree(ptr->rchild,key);
    }
    return ptr;
}
