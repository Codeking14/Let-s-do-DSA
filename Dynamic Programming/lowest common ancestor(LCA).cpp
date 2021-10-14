#include<bits/stdc++.h>
using namespace std;

class node
{
   public:
      int data;
      node* left;
      node* right;

   node(int d)
   {
      data = d;
      left = NULL;
      right = NULL;
   }
};

node* buildTree()
{
   int d;
   cin>>d;

   if(d==-1)
   {
      return NULL;
   }

   node* root = new node(d);
   root->left = buildTree();
   root->right = buildTree();
   return root;
}

void printBFS(node* root)
{
   queue<node*> q;
   q.push(root);
   q.push(NULL);
   while(!q.empty())
   {
      node* temp = q.front();
      q.pop();
      if(temp == NULL)
      {
         cout<<endl;
         if(!q.empty())
         {
            q.push(NULL);
         }
      }
      else
      {
         cout<<temp->data<<" ";
         if(temp->left)
         {
            q.push(temp->left);
         }
         if(temp->right)
         {
            q.push(temp->right);
         }
      }
   }
}

void operator>> (istream &is,node*& root) // input operator overloading
{
   root = buildTree();
   return;
}

void operator<< (ostream &os , node* root) // output operator overloading
{
   printBFS(root);
   return;
}

node* LCA(node* root,int a,int b)
{
   if(root == NULL)
      return NULL;
   if(root->data == a || root->data == b)
   {
      return root;
   }
   node* left = LCA(root->left,a,b);
   node* right = LCA(root->right,a,b);
   if(left!=NULL && right!=NULL)
   {
      return root;
   }
   if(left!=NULL)
      return left;

   return right;
}

int main()
{
   node* root = NULL;
   cin>>root;
   int A;
   int B;
   cin>>A>>B;
   cout<<LCA(root,A,B)->data;
   cout<<endl;
}
