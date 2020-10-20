#include<iostream>
using namespace std;
class Node{
public:
  int data;
  Node *next;
};
class stacklinkedlist{
private:
  Node *top;
public:
  stacklinkedlist();
  void push(int x);
  int pop();
  int peek(int index);
  void display();
  bool isEmpty();
  bool isFull();
  int stackTop();

};
stacklinkedlist::stacklinkedlist(){
  top = nullptr;
}
void stacklinkedlist::push(int x){
  Node *p = new Node;
  if(p == nullptr){
    cout<<"StackOverFlow"<<endl;
  }
  else{
    p->data =x;
    p->next = top;
    top = p;

  }
}
int stacklinkedlist::pop(){
  int x = -1;
  Node *p   = top;
  if(top){
    x = top->data;

    top = p->next;
    p->next =NULL;
    return x;

  }
  else{
    return x;
  }

}
int stacklinkedlist::peek(int index){


    Node *p = top;
    for(int i=0;i<index-1;i++){
      p =p->next;
    }
    return p->data;



}
void stacklinkedlist::display(){
  cout<<"Stack is :";
  Node *p = top;
  while(p){
    cout<<p->data<<" ";
    p = p->next;

  }
}
int main(){
  stacklinkedlist stk;
  stk.push(10);
  stk.push(20);
  stk.push(30);
  stk.pop();
  stk.display();
}
