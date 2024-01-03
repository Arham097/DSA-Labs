// Q#1) 
// #include<iostream>
// using namespace std;

// class circularQueue{
//     public:
//     int *arr;
//     int front;
//     int rear;
//     int size;

//     circularQueue(int s){
//         size = s;
//         front = rear = -1;
//         arr = new int[size];
//     }
//     void enqueue(int x){
//         //check overflow condition
//         if((front==0 && rear==size-1)|| (rear == (front -1) % (size-1))){
//             cout<<"Queue Oveflow"<<endl;
//         }
//         // put front and rear to 0th position
//         else if(front==-1){
//             rear = front = 0;
//         }
//         // To maintain cyclic nature
//         else if(rear ==size -1 && front!=0){
//             rear = 0;
//         }
//         // normal flow
//         else {
//             rear ++;
//         }
//         arr[rear] = x;
//     }
//     int dequeue(){
//         // check underflow condition
//         if(front==-1){
//             cout<<"Queue Underflow"<<endl;
//         }
//         int ans = arr[front];
//         arr[front] = -1;

//         //to check ther is only one element
//         if(front==rear){
//             front=rear=-1;
//         }
//         //to maintain cyclic nature
//         else if(front == size -1){
//             front =0;
//         }
//         // normal flow
//         else{
//             front++;
//         }
//         return ans;

//     }
// };

// int main(){
//     circularQueue cq(5);
//     cq.enqueue(10);
//     cq.enqueue(20);
//     cout<<cq.dequeue()<<endl;
//     cout<<cq.dequeue()<<endl;
//     cq.dequeue();
//     return 0;
// }

// Q#2) 

#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int> q;

    q.push(10);
    q.push(5);
    q.push(11);
    q.push(12);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    
    return 0;
}