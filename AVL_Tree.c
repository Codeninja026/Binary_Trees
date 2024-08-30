#include <stdio.h>
#include <stdlib.h>
struct node
{
 int key;
 struct node *lchild;
 struct node *rchild;
 int height;
};
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
struct node* succ(struct node *ptr)
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
 struct node* temp = succ(root);
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
void preorder(struct node *root)
{
 if(root != NULL)
 {
 printf("%d ", root->key);
 preorder(root->lchild);
 preorder(root->rchild);
 }
}
 int main(){
 struct node * root = NULL;
 root = insert(root, 10);
 root = insert(root, 20);
 root = insert(root, 40);
 preorder(root);
 printf("\n");
 root = insert(root, 50);
 root = insert(root, 60);
 root = insert(root, 30);
 preorder(root);
 root=deleteNode(root,30);
 printf("\n");
 preorder(root);
 return 0;
} 
