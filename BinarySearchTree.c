#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *rchild;
    struct node *lchild;   
};
struct node *root=NULL;

void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);
struct node *create(int);
struct node *insert_node(struct node*,int);
struct node *binarysearchtree(struct node*,int);
void delete_node(struct node*root,int item) ;
struct node *successor(struct node*);

int main()
{
    int ch,key;
    while(1)
    {
        printf("1. insert node\n");
        printf("2. inorder\n");
        printf("3. preorder\n");
        printf("4. postorder\n");
        printf("5. binarysearchtree\n");
        printf("6.delete a node\n") ;
        printf("7. exit \n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {

            case 1:printf("Enter the item to be inserted: ");
                    scanf("%d",&key);
                    root=insert_node(root,key);
                    break;
            case 2:inorder(root);
                    printf("\n") ;
                    break;
            case 3: preorder(root);
                    printf("\n") ;
                    break;
            case 4: postorder(root);
                    printf("\n") ;
                    break;
            case 5: printf("Enter the key in binarysearchtreee: ");
                    scanf("%d",&key);
                    binarysearchtree(root,key);
                    break;
            case 6: printf("Enter the node you want to delete: ") ;
                    scanf("%d",&key) ;
                    delete_node(root,key) ;
                    break ; 
            case 7: printf(".....program terminated.......");
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
struct node *insert_node(struct node *ptr,int key)
{
    if(ptr==NULL)
    {
        ptr=create(key);

    }
    else if(ptr->data==key)
    {
        printf("data already exist.\n");
        return ptr;

    }
    else if(key<ptr->data)
    {
        ptr->lchild=insert_node(ptr->lchild,key);
    }
    else if(key>ptr->data)
    {
        ptr->rchild=insert_node(ptr->rchild,key);
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
    struct node* ptr;
    ptr=root;
    if(ptr)
    {
        postorder(ptr->lchild);
        postorder(ptr->rchild);
        printf("%d ",ptr->data);
    }
     
}
struct node* binarysearchtree(struct node *ptr,int key)
 {
     if(ptr==NULL)
     {
         return ptr;
     }
     else if(ptr->data==key)
     {
         printf("node found.");
         return ptr;
     }
     else if(key<ptr->data)
     {
         return binarysearchtree(ptr->lchild,key);
     }
     else if(key>ptr->data)
     {
         return binarysearchtree(ptr->rchild,key);
     }
     return ptr;
 }

struct node*successor(struct node *ptr)
{
    struct node*ptr1 = ptr->rchild ;
    if(ptr1!=NULL)
    {
        while(ptr1->lchild!=NULL)
        {
            ptr1 = ptr1->lchild ;
        
        }
    }
    return ptr1 ;
}

void delete_node(struct node*root,int item)
{
    struct node*ptr,*ptr1,*parent ;
    int flag=0 ;
    ptr = root ;

    while(flag==0 && ptr!=NULL)
    {
        if(ptr->data>item)
        {
            parent = ptr ; 
            ptr = ptr->lchild ;
        }
        else if(ptr->data<item)
        {
            parent = ptr ;
            ptr = ptr->rchild ;
        }
        else
        {
            flag = 1 ;
            break ;
        }
    }
    if(flag==0)
    {
        printf("Node node found\n") ;
        return ; 
    }
    int option ;
    if(ptr->lchild==NULL && ptr->rchild==NULL)
    {
        option =1 ;
    }
    else if(ptr->lchild!=NULL && ptr->rchild!=NULL)
    {
        option =3 ;
    }
    else
    {
        option =2 ;
    }

    if(option==1)
    {
        if(parent->lchild==ptr)
        {
            parent->lchild = NULL ; 
        }
        else{
            parent->rchild = NULL ; 
        }
        free(ptr) ;
    }
    else if(option==2)
    {
        if(parent->lchild==ptr)
        {
            if(ptr->lchild==NULL)
            {
                parent->lchild = ptr->rchild ;
            }
            else{
                parent->lchild = ptr-> lchild ;
            }
        }
        else
        {
            if(ptr->lchild==NULL)
            {
                parent->rchild = ptr->rchild ;
            }
            else
            {
                parent->rchild = ptr->lchild ;
            }
        }
        free(ptr) ;
    }
    else //option 3
    {
        ptr1 = successor(ptr) ;
        int item1  = ptr1->data ;
        delete_node(root,item1) ;
        ptr->data = item1 ;
    }
}
