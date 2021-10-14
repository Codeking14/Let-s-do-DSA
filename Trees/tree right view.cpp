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

void printrightview(node* root,int level)
{
   static int maxlevel = -1;
   if(root == NULL)
   {
      return;
   }
   if(level>maxlevel)
   {
      cout<<root->data<<endl;
      maxlevel=level;
   }
   printrightview(root->right,level+1);
   printrightview(root->left,level+1);
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

int main()
{
   node* root = NULL;
   cin>>root;
   cout<<root;
   cout<<endl;
   printrightview(root,0);
}
