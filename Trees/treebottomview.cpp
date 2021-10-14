#include<bits/stdc++.h>
using namespace std;

struct node
{
    // data of the node
    int data;

    // horizontal distance of the node
    int hd;

    //left and right references
    node * left, * right;

    // Constructor of tree node
    node(int key)
    {
        data = key;
        hd = INT_MAX;
        left = right = NULL;
    }
};

void printBottomViewUtil(node * root, int curr, int hd, map <int, pair <int, int>> & m)
{
    // Base case
    if (root == NULL)
        return;

    // If node for a particular
    // horizontal distance is not
    // present, add to the map.
    if (m.find(hd) == m.end())
    {
        m[hd] = make_pair(root -> data, curr);
    }
    // Compare height for already
    // present node at similar horizontal
    // distance
    else
    {
        pair < int, int > p = m[hd];
        if (p.second <= curr)
        {
            m[hd].second = curr;
            m[hd].first = root -> data;
        }
    }

    // Recur for left subtree
    printBottomViewUtil(root -> left, curr + 1, hd - 1, m);

    // Recur for right subtree
    printBottomViewUtil(root -> right, curr + 1, hd + 1, m);
}

void printBottomView(node * root)
{

    // Map to store Horizontal Distance,
    // Height and Data.
    map < int, pair < int, int > > m;

    printBottomViewUtil(root, 0, 0, m);

     // Prints the values stored by printBottomViewUtil()
    map < int, pair < int, int > > ::iterator it;
    for (it = m.begin(); it != m.end(); ++it)
    {
        pair < int, int > p = it -> second;
        cout << p.first << " ";
    }
}


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

void pre(node* root)
{
   if(root == NULL)
   {
      return;
   }
   cout<<root->data<<" ";
   pre(root->left);
   pre(root->right);
}

int main()
{
	node* root = buildtree();
	//pre(root);
	printBottomView(root);
}
