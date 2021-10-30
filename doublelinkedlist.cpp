#include <iostream>

using namespace std;

struct node
{
   int n;
   node *next;
   node *prev;
};
void traverse(node *);
void searchl(node *start);
node* deletep(node *start);
node* inserto(node *start);
void revtrav(node *start);
void menu(node *);
int main()
{
     node *start=NULL;
     menu(start);
     return 0;
}
void menu(node *start)
{
   int ch;
   do
   {
	cout<<"Enter your choice"<<endl;
	cout<<"1. To Insert Data in Ordered form"<<endl;
	cout<<"2. To Delete any data"<<endl;
	cout<<"3. To search a data"<<endl;
	cout<<"4. To traverse"<<endl;
	cout<<"5. To traverse the given list from the end"<<endl;
	cout<<"6. To Exit"<<endl;
	cin>>ch;
	switch(ch)
	{
		case 1:
            start=inserto(start);
            break;
        case 2:
            start=deletep(start);
            break;
        case 3:
			searchl(start);
			break;
		case 4:
		    cout<<endl;
			traverse(start);
			break;
        case 5:
            cout<<endl;
            revtrav(start);
            break;
       case 6:
            break;
        default:
            cout<<"Wrong Input"<<endl;
     }
   }
   while(ch!=6);
}
node* inserto(node *start)
{
    node *cnew,*p,*p1;
    cnew=new node;
    cout<<"Enter The Data You want to insert"<<endl;
    cin>>cnew->n;
    if(start==NULL)
    {
       start=cnew;
       start->prev=NULL;
       cnew->next=NULL;
    }
    else
    {
        p=NULL;
        p1=start;
        while(p1!=NULL && p1->n<cnew->n)
        {

           p=p1;
           p1=p1->next;
        }
        if(p==NULL)
        {
            cnew->prev=NULL;
            cnew->next=p1;
            p1->prev=cnew;
            start=cnew;
        }
        else
        {
            cnew->prev=p;
            p->next=cnew;
            cnew->next=p1;
            if(p1!=NULL)
                p1->prev=cnew;
        }
    }
    return start;
}
void traverse(node *start)
{
    if(start==NULL)
        cout<<"List is Empty"<<endl;
    else
    {
        node *p;
		p=start;
		while(p!=NULL)
		{
		       cout<<p->n<<endl;
		       p=p->next;
		}
    }
}
node* deletep(node *start)
{
  if(start==NULL)
     cout<<"List is Empty"<<endl;
  else
  {
    int num;
    node *p,*p1;
    p=NULL;
    p1=start;
    cout<<"Enter the Data you want to delete"<<endl;
    cin>>num;
    while(p1!=NULL && p1->n!=num)
    {
        p=p1;
        p1=p1->next;

    }
    if(p==NULL)
    {
        start=start->next;
        start->prev=NULL;
        p1->next=NULL;
        delete(p1);
    }
    else if(p1==NULL)
        cout<<"The Data you want to delete is not present in the list"<<endl;
    else
    {
        p->next=p1->next;
        p1->next->prev=p1->prev;
        p1->next=NULL;
        delete(p1);
    }
  }
  return start;
}
void searchl(node *start)
{
    int a,f=0;
    if(start==NULL)
        cout<<"List is Empty"<<endl;
    else
    {
        cout<<"Enter the data you want to search if its present or not"<<endl;
        cin>>a;
        node *p;
        p=start;
        while(p!=NULL)
        {

            if(a==p->n)
            {
                f=1;
                break;
            }
            else
                p=p->next;
        }
        if(f==0)
            cout<<"The data you're searching is not present in the list"<<endl;
        else
            cout<<"The data you're searching is present in the list"<<endl;
    }
}
void revtrav(node *start)
{
    if(start==NULL)
        cout<<"List is Empty"<<endl;
    else
    {
        node *p;
		p=start;
		while(p->next!=NULL)
            p=p->next;
		while(p!=NULL)
		{
		       cout<<p->n<<endl;
		       p=p->prev;
		}
    }
}
