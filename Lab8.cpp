// Q#1) Write Down Factorial and Fibonacci Program Recursively
// #include<iostream>
// using namespace std;

// int factorial(int n){
//     if(n==0){
//         return 1;
//     }
//     return n*factorial(n-1);
// }

// int fibonacci(int n){
//     if(n==0) return 0;
//     if(n==1) return 1;
//     return fibonacci(n-1) + fibonacci(n-2);
// }

// int main(){
//     int n = 5;
//     int fact = factorial(n);
//     cout<<"The factorial of "<<n<<" is: "<<fact<<endl;

//     int fib = fibonacci(n);
//     // I consider indexing of fibbonacci series from 0th index
//     cout<<"The "<<n<<"th term of fibbonacci series is: "<<fib<<endl;

// }

//Q#2) Write Down Factorial and Fibonacci Program Iteratively
// #include<iostream>
// using namespace std;

// int factorial(int n){
//     int fact = 1;
//     for(int i=1; i<=n; i++){
//         fact *=i;
//     }
//     return fact;
// }
// int fibonacci(int n){
//     int a = 0;
//     int b = 1;
//     int c = 0;
//     for(int i=0; i<=n-2; i++){
//         c = a+b;
//         a = b;
//         b = c;
//     }
//     return c;
// }
//  int main(){
//     int n = 5;
//     int fact = factorial(n);
//     cout<<"The factorial of "<<n<<" is: "<<fact<<endl;

//     int fib = fibonacci(n);
//     // I consider indexing of fibbonacci series from 0th index
//     cout<<"The "<<n<<"th term of fibbonacci series is: "<<fib<<endl;
//     return 0;
//  }

// Q#3) Implement Tower of Hanoi Recursively

// #include<iostream>
// using namespace std;

// void towerOfHanoi(int n,char source, char auxiliary, char destination){
//     if(n>0){
//         towerOfHanoi(n-1,source, destination, auxiliary);
//         cout<<"Move Disk "<<n<<" from "<<source<<" to "<<destination<<endl;
//         towerOfHanoi(n-1,auxiliary,source,destination);
//     }
// }
// int main(){
//     int n =3;
//     towerOfHanoi(n,'A','B','C');
//     return 0;
// }

// Q#4) Implement Tower of Hanoi Iteratively

// #include <iostream>
// #include <stack>

// using namespace std;

// // Function to perform iterative Tower of Hanoi
// void towerOfHanoi(int n, char source, char auxiliary, char destination) {
//     // Create three stacks for each tower
//     stack<int> sourceStack, auxiliaryStack, destinationStack;
    
//     // Initialize the source tower
//     for (int i = n; i > 0; --i) {
//         sourceStack.push(i);
//     }

//     char temp;
//     if (n % 2 == 0) {
//         // If the number of disks is even, swap auxiliary and destination towers
//         temp = auxiliary;
//         auxiliary = destination;
//         destination = temp;
//     }

//     int totalMoves = (1 << n) - 1; // Total number of moves required

//     // Perform the Tower of Hanoi iteratively
//     for (int move = 1; move <= totalMoves; ++move) {
//         if (move % 3 == 1) {
//             // Move disk from source to destination
//             if (!sourceStack.empty() && (destinationStack.empty() || sourceStack.top() < destinationStack.top())) {
//                 destinationStack.push(sourceStack.top());
//                 sourceStack.pop();
//                 cout << "Move disk from " << source << " to " << destination << endl;
//             } else {
//                 destinationStack.push(auxiliaryStack.top());
//                 auxiliaryStack.pop();
//                 cout << "Move disk from " << auxiliary << " to " << destination << endl;
//             }
//         } else if (move % 3 == 2) {
//             // Move disk from source to auxiliary
//             if (!sourceStack.empty() && (auxiliaryStack.empty() || sourceStack.top() < auxiliaryStack.top())) {
//                 auxiliaryStack.push(sourceStack.top());
//                 sourceStack.pop();
//                 cout << "Move disk from " << source << " to " << auxiliary << endl;
//             } else {
//                 auxiliaryStack.push(destinationStack.top());
//                 destinationStack.pop();
//                 cout << "Move disk from " << destination << " to " << auxiliary << endl;
//             }
//         } else {
//             // Move disk from auxiliary to destination
//             if (!auxiliaryStack.empty() && (destinationStack.empty() || auxiliaryStack.top() < destinationStack.top())) {
//                 destinationStack.push(auxiliaryStack.top());
//                 auxiliaryStack.pop();
//                 cout << "Move disk from " << auxiliary << " to " << destination << endl;
//             } else {
//                 destinationStack.push(sourceStack.top());
//                 sourceStack.pop();
//                 cout << "Move disk from " << source << " to " << destination << endl;
//             }
//         }
//     }
// }

// int main() {
//     int n;
//     cout << "Enter the number of disks: ";
//     cin >> n;

//     towerOfHanoi(n, 'A', 'B', 'C');

//     return 0;
// }
