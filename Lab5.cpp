// Q#1) Give implementations of Push & Pop Algorithms with underflow & Overflow exceptions.

// #include<iostream>
// using namespace std;

// class Stack{
//     int *arr;
//     int size;
//     int top;

//     public:
//     Stack(int s){
//         size = s;
//         top = -1;
//         arr = new int[size];
//     }
//     void push(int x){
//         if(size-top>1){
//             top++;
//             arr[top] = x;
//         }
//         else{
//             cout<<"Stack is overflow"<<endl;
//         }
//     }
//     void pop(){
//         if(top>0){
//             top--;
//         }
//         else{
//             cout<<"Stack is underflow"<<endl;
//         }
//     }

// };
// int main(){
//     Stack s1(3);
//     s1.push(1);
//     s1.push(2);
//     s1.push(3);
//     // when try to push 4th element in size = 3 stack so it throws exception
//     s1.push(4);

//     cout<<endl;

//     Stack s2(3);
//     //when try to pop before push any element so it throw exception
//     s2.pop();

//     return 0;
// }


// Q#3) Use Stack ADT and implement logic to get same string that was provided by user  
// Hint : Use two stacks(Stack1 & Stack2)

// #include<iostream>
// #include<stack>
// using namespace std;

// string getOriginalString(string input){
//     stack<int> Stack1,Stack2;

//     // Step 1: Push Element of string in Stack 1
//     for(char ch : input){
//         Stack1.push(ch);
//     }

//     // Step 2: Push Stack1 element to Stack 2
//     while(!Stack1.empty()){
//         Stack2.push(Stack1.top());
//         Stack1.pop();
//     }
//     string original;
//     while(!Stack2.empty()){
//         original+=Stack2.top();
//         Stack2.pop();
//     }
//     return original;

// }
// int main(){
//     string userInput;
//     cout<<"Enter String: ";
//     getline(cin,userInput);

//     string result = getOriginalString(userInput);

//     cout<<"Result string is: "<< result<<endl;


//     return 0;
// }

// Q#4) Write an algorithm to implement two stacks in a single array
// #include<iostream>
// using namespace std;

// class TwoStacks{
//     int *arr;
//     int top1;
//     int top2;
//     int size;

//     TwoStacks(int s){
//         size =  s;
//         arr = new int[size];
//         top1 = -1;
//         top2 = size; 
//     }
//     //Push in Stack 1
//     void push1(int x){
//         if((top2-top1)>1){
//             top1++;
//             arr[top1] = x;
//         }
//         else{
//             cout<<"Stack Overflow"<<endl;
//         }
//     }
//     //Push in Stack 2
//     void push2(int x){
//         if((top2-top1)>1){
//             top2--;
//             arr[top2] = x;
//         }
//         else{
//             cout<<"Stack Overflow"<<endl;
//         }
//     }
//     //Pop from stack 1
//     void pop1(){
//         if(top1>0){
//             top1--;
//         }
//         else{
//             cout<<"Stack Underflow"<<endl;
//         }
//     }
//     void pop2(){
//         if(top2<size){
//             top2++;
//         }
//         else{
//             cout<<"Stack Underflow"<<endl;
//         }
//     }

// }



