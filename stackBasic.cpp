#include<iostream>
using namespace std;
class stack{
private:
  int size;
  int top;
  int *s;
public:
  stack(int st);
  ~stack();
  void push(int x);
  int pop();
  int peek(int index);
  bool isFull();
  bool isEmpty();
  void display();
  int stackTop();
};
stack::stack(int st){
  size = st;
  top = -1;
  s = new int[size];
}
stack::~stack(){
  delete[] s;
}
void stack::push(int x){
  if(isFull()){
    cout<<"Stack OverFlow"<<endl;
  }
  else{
    top++;
    s[top] = x;
  }
}
int stack::pop(){
  int x = -1;
  if(isEmpty()){
    cout<<"stack underFlow"<<endl;
  }
  else{
    x = s[top];
    top--;
  }
  return x;
}
bool stack::isEmpty(){
  if(top == -1){
    cout<<"stack is Empty"<<endl;
    return 1;
  }
  else{
    cout<<"stack is not  empty"<<endl;
    return 0;
  }
}
bool stack::isFull(){
  if(top == size-1){
    cout<<"stackOverflow"<<endl;
    return 1;
  }
  else{
    return 0;

  }
}
int stack::peek(int index){
  if(top<index){
    cout<<"invalid index"<<endl;
    return -1;

  }
  else{

    return s[top-index+1];
  }
}
void stack::display(){
  for(int i=top;i>=0;i--){
    cout<<s[i]<<" ";
  }
}
int stack:: stackTop(){
  if(top == -1){
    cout<<"stack is empty"<<endl;
    return -1;
  }
  else{
    return s[top];
  }
}
int main(){
  int A[] = {1,3,5,7,9};
  stack stk(sizeof(A)/sizeof(A[0]));
  for(int i=0;i<5;i++){
    stk.push(A[i]);
  }
  cout<<"Stack: ";
  stk.display();

}
