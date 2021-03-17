#include"BST.h";
binarysearchtree::binarysearchtree()
{
    this->data=0;
    this->left=NULL;
    this->right=NULL;
}
binarysearchtree::binarysearchtree(int n)
{
    this->data=n;
    this->left=NULL;
    this->right=NULL;
}
binarysearchtree::~binarysearchtree()
{
}
int binarysearchtree::getdata()
{
    return this->data;
}
binarysearchtree* binarysearchtree::Max()
{
    if(this->right==NULL)
        return this;
    else
        return this->right->Max();
}
binarysearchtree* binarysearchtree::Min()
{
    if(this->left==NULL)
        return this;
    else
        return this->left->Min();
}
binarysearchtree::Insert(int n)
{
    if(n>this->data)
    {
        if(this->right==NULL)
        {
            binarysearchtree* tmp=new binarysearchtree;
            tmp->left=NULL;
            tmp->right=NULL;
            tmp->data=n;
        }
        else
            this->right->Insert(n);
    }
    else if(n<this->left)
    {
        if(this->left==NULL)
        {
            binarysearchtree* tmp=new binarysearchtree;
            tmp->left=NULL;
            tmp->right=NULL;
            tmp->data=n;
        }
        else
            this->left->Insert(n);
    }
}
binarysearchtree::Mirror()
void showpost(binarysearchtree* node,bool &first)
{
    if(node==NULL)
        return;
    showpost(node->left,first);
    showpost(node->right,first);
    //第一個數之前不用空格
    if(!first)cout<<" ";
    else first=false;

    cout<<node->data;
}
void showpre(binarysearchtree* node,first)
{
    if(node==NULL)
        return;
    if(!first)cout<<" ";
    else first=false;
    cout<<node->data;
    showpre(node->left,first);
    showpre(node->right,first);
}
int Height(binarysearchtree* node)
{
    if(node==NULL)
        return 0;
    int L=Height(node->left);
    int R=Height(node->right);
    (L>=R)?return (L+1):return (R+1);
}
int Size(binarysearchtree* node)
{
    if(node==NULL)
        return 0;
    else
        return Size(node->left)+Size(node->right)+1;
}
