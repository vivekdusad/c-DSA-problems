#include<iostream>
#include <cstring>
using namespace std;
class Node{
public:
  char data;
  Node* next;

};
class stack{
private:
  Node *top;
public:
  stack();

  void push(char x);
  char pop();
  void display();
  char peek(int index);
  bool isEmpty();

};
stack::stack(){
  top = nullptr;
}
void stack::push(char x){
  Node *p = new Node;


    p->data =x;
    p->next = top;
    top = p;


}
bool stack::isEmpty() {
    if(!top){
        return true;
    }
    else{
        return false;
    }
}
char stack::pop(){
  char x;
  Node *p   = top;
  if(top){
    x = top->data;

    top = p->next;
    p->next =NULL;
    return x;

  }
  else{
    return 'a';
  }

}
char stack::peek(int index){


    Node *p = top;
    for(int i=0;i<index-1;i++){
      p =p->next;
    }
    return p->data;



}
void stack::display(){
  cout<<"Stack is :";
  Node *p = top;
  while(p){
    cout<<p->data<<" ";
    p = p->next;

  }
}
bool paranthesisMatch(char *s){
  stack stk;
  int len = strlen(s);
  if(s == NULL){
    cout<<"given string is null"<<endl;
    return false;
  }
  else{
    for(int i=0;i<len;i++){
      if(s[i] == '('){
        stk.push('(');

      }
      else if(s[i] == ')'){
        if(stk.isEmpty()){
          return false;
        }
        else{
          stk.pop();

        }
      }


      }

    }
    if(stk.isEmpty()){
      cout<<"Balanced"<<endl;
      return true;
    }
    else{
      cout<<"not balanced"<<endl;
      return false;
  }

}
int main(){


  char exp[] = "((a+b)*(c-d))";
  cout<<paranthesisMatch(exp);
  char e[] = "((a+b)*(c-d)";
  paranthesisMatch(e);



}
