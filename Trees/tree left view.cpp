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

node* buildtree()
{
	int d;
	cin>>d;
	if(d == -1)
	{
		return NULL;
	}
	node* root = new node(d);
	queue<node*> q;
	q.push(root);
	while(!q.empty())
   {
      node* temp = q.front();
      q.pop();
      cin>>d;
      if(d == -1)
      {
         temp->left = NULL;
      }
      else
      {
         temp->left = new node(d);
         q.push(temp->left);
      }
      cin>>d;
      if(d == -1)
      {
         temp->right = NULL;
      }
      else
      {
         temp->right = new node(d);
         q.push(temp->right);
      }
   }
   return root;
}

void leftview(node* root,int curr,map<int,int> &m)
{
   if(root == NULL)
   {
      return;
   }
   if(m.find(curr) == m.end())
   {
      m[curr] = root->data;
   }
   leftview(root->left,curr+1,m);
   leftview(root->right,curr+1,m);
}

int main()
{
	node* root = buildtree();
	//pre(root);
	map <int,int> m;
	leftview(root,0,m);
	for(auto it:m)
      {
            cout<<it.second<<" ";
      }
}
