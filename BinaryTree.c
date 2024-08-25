#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *rchild;
    struct node *lchild;   
};
struct node *root=NULL;
struct node *create(int);
struct node *createtree(struct node*,int);
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);
int searchbinarytree(struct node*,int);
int main()
{
    int ch,key,result;
    while(1)
    {

        printf("\n");
        printf("1. createtree\n");
        printf("2. inorder:\n");
        printf("3. preorder:\n");
        printf("4. postorder:\n");
        printf("5. searchbinarytree:\n");
        printf("6. exit: \n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {

            case 1:
                    root=createtree(root,key);
                    break;
            case 2:inorder(root);
                    break;
            case 3: preorder(root);
                    break;
            case 4: postorder(root);
                    break;
            case 5: printf("Enter the key in searchbinarytree: ");
                    scanf("%d",&key);
                    result=searchbinarytree(root,key);
                    if(result==1)
                    {
                        printf("value found:%d ",key);
                    }
                    else if(result==0)
                    {
                        printf("key not found.");
                    }
                    break;
            case 6: printf(".......................program terminated.........................");
                    exit(0);

            default: printf("Invalid choise..");
            
        }
    }
    return 0; 
}
struct node *create(int data)
{
    
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));

    newnode->data=data;

     newnode->lchild=NULL;
     newnode->rchild=NULL;
    return newnode;
    
}
struct node *createtree(struct node *root,int key)
{
    int ch;
    struct node *ptr;
    ptr=root;
     
    if(ptr==NULL)
    {
        printf("Enter the key value:");
        scanf("%d",&key);
        ptr=create(key);
    }
    printf("do you want to insert left child of %d press 1 else 0\n",ptr->data);
    scanf("%d",&ch);
    if(ch)
    {
        ptr->lchild=createtree(ptr->lchild,key);
    }
    printf("do want to insert right child of %d press 1 else 0\n",ptr->data);
    scanf("%d",&ch);
    if(ch)
    {
        ptr->rchild=createtree(ptr->rchild,key);
    }
    return ptr;
}
void inorder(struct node *root)
{
    struct node *ptr;
    ptr=root;
    if(ptr)
    {
        inorder(ptr->lchild);
        printf("%d ",ptr->data);
        inorder(ptr->rchild);
    }
}
void preorder(struct node* root)
{
    struct node *ptr;
    ptr=root;
    if(ptr)
    {
        printf("%d ",ptr->data);
        preorder(ptr->lchild);
        preorder(ptr->rchild);
    }
}
void postorder(struct node* root)
{
    struct node *ptr;
    ptr=root;
    if(ptr)
    {
        postorder(ptr->lchild);
        postorder(ptr->rchild);
        printf("%d ",ptr->data);
    }
}
//search binary tree
int searchbinarytree(struct node *ptr,int key)
{
    int flag1,flag2;
    if(ptr==NULL)
    {
        return 0;
    }
    else if(ptr->data==key)
    {
        return 1;
    }
   flag1=searchbinarytree(ptr->lchild,key);
   if(flag1)
       return flag1;
   flag2=searchbinarytree(ptr->rchild,key);
       return flag2;

}
