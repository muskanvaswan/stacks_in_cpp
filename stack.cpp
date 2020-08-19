#include <iostream>
using namespace std;

struct node
{
  char city[25];
  int pincode;
  node *next;
}*top, *newptr, *save, *ptr;
node *new_node();
void push(node*);
void display(node*);
void pop();
int main()
{
  char ch;
  while(true)
  {
    newptr = new_node();
    push(newptr);
    cout<<"\ndo you want to add to the stack? (y/n)  ";
    cin>>ch;
    if(ch=='n')
       break;
  }
  do {
     cout<<"\nthe stack now is:\n";
     display(top);
     cout<<"\ndo you want to delete element? (y/n) ";
     cin>>ch;
     if(ch=='y')
      pop();
   } while(ch=='y');
}

node *new_node()
{
  ptr = new node;
  cout<<"adding element \n enter city: ";
  cin.ignore();
  cin.getline(ptr->city,25);
  cout<<"enter pincode: ";
  cin>>ptr->pincode;
  return ptr;
}
void push(node* np)
{
  if(top==NULL)
  {
    top=np;
  }
  else
  {
    save= top;
    top=np;
    np->next=save;
  }
}
void pop()
{
  if(top==NULL)
  {
    cout<<"UNDERFLOW!";
  }
  else
  {
    ptr= top;
    top= top->next;
    delete ptr;
  }
}
void display(node *np)
{
  while(np!=NULL)
  {
    cout<<np->city<<"_"<<np->pincode<<"->  ";
    np = np->next;
  }
  cout<<"stack ends here!";
}
