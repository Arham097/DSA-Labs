// Q#1) Solve the following postfix expression via algorithm

// (i) 5, 6,2,+,*, 12,4,/,- 		(ii) 2,3,^,5,2,2,^,*,12,6,/,-,+

// int PerformOperation(char op, int op1, int op2){
//     switch(op){
//         case '+': 
//             return (op1+op2);
//          case '-':
//             return op1 - op2;
//         case '*':
//             return op1 * op2;
//         case '/':
//             return op1 / op2;
//         case '^':
//             return pow(op1, op2);
//         default:
//             cerr << "Invalid operator: " << op << endl;
//             exit(EXIT_FAILURE);
//     }
// }

// int PostfixEvaluation(vector<string> postfix){
//     stack<int> operands;

//     for(string op : postfix){
//         if(isdigit(op[0]) || (op[0] == '-' && isdigit(op[1]))){
//             operands.push(stoi(op));
//         }
//         else{
//             int operator2 = operands.top();
//             operands.pop();
//             int operator1 = operands.top();
//             operands.pop();
//             int result = PerformOperation(op[0],operator1,operator2);
//             operands.push(result);
//         }
//     }
//     return operands.top();

// }

// Q#2) (i)Implement the algorithm to convert  Infix Expression to equivalent postfix form.
// #include <iostream>
// #include<cmath>
// #include <stack>
// #include <unordered_map>
// #include<algorithm>

// using namespace std;

// bool isOperator(char ch) {
//     return (ch == '+' || ch == '-' || ch == '*' || ch == '/'|| ch =='^');
// }

// int getPrecedence(char op) {
//     unordered_map<char, int> precedence;
//     precedence['+'] = 1;
//     precedence['-'] = 1;
//     precedence['*'] = 2;
//     precedence['/'] = 2;
//     precedence['^'] = 3;
//     return precedence[op];
// }

// string infixToPostfix(string infix) {
//     stack<char> operatorStack;
//     string postfix;

//     for (char ch : infix) {
//         if (isalpha(ch)) {
//             postfix += ch;  // Output operand directly
//         } else if (ch == '(') {
//             operatorStack.push(ch);
//         } else if (ch == ')') {
//             while (!operatorStack.empty() && operatorStack.top() != '(') {
//                 postfix += operatorStack.top();
//                 operatorStack.pop();
//             }
//             operatorStack.pop();  // Discard '('
//         } else if (isOperator(ch)) {
//             while (!operatorStack.empty() && getPrecedence(ch) <= getPrecedence(operatorStack.top())) {
//                 postfix += operatorStack.top();
//                 operatorStack.pop();
//             }
//             operatorStack.push(ch);
//         }
//     }

//     // Pop remaining operators from the stack
//     while (!operatorStack.empty()) {
//         postfix += operatorStack.top();
//         operatorStack.pop();
//     }

//     return postfix;
// }


// Q # 3) Write algorithm to solve prefix expression also give implementation.

// #include <iostream>
// #include <stack>
// #include <cmath>
// #include <algorithm>
// using namespace std;

// int PerformOperation(char op, int op1, int op2) {
//     switch (op) {
//     case '+':
//         return (op1 + op2);
//     case '-':
//         return op1 - op2;
//     case '*':
//         return op1 * op2;
//     case '/':
//         return op1 / op2;
//     case '^':
//         return pow(op1, op2);
//     default:
//         cerr << "Invalid operator: " << op << endl;
//         exit(EXIT_FAILURE);
//     }
// }

// int PrefixEvaluation(string prefix) {
//     stack<int> operands;
//     reverse(prefix.begin(), prefix.end());

//     for (char op : prefix) {
//         if (isdigit(op)) {
//             operands.push(op - '0');
//         } else {
//             int operator1 = operands.top();
//             operands.pop();
//             int operator2 = operands.top();
//             operands.pop();
//             int result = PerformOperation(op, operator1, operator2);
//             operands.push(result);
//         }
//     }

//     return operands.top();
// }

// int main() {
//     string expression = "+2*35";
//     cout << "Result: " << PrefixEvaluation(expression) << endl;

//     return 0;
// }


// Extra Question
// string infixToPrefix(string infix){
//     stack<char> s;
//     string prefix;
    
//     reverse(infix.begin(), infix.end());
    
//     for(int i=0; i<infix.size(); i++){
//         if(infix[i]=='('){
//             infix[i] =')';
//         }
//         else if(infix[i]==')'){
//             infix[i] = '(';
//         }
//     }
//     for(char ch: infix){
//         if(isalnum(ch)){
//             prefix+=ch;
//         }
//         else if(ch=='('){
//             s.push(ch);
//         }
//         else if(ch==')'){
//             while(!s.empty() && s.top()!='('){
//                 prefix+=s.top();
//                 s.pop();
//             }
//             if(!s.empty()){
//                 s.pop();
//             }
//         }
//         else if(isOperator(ch)){
//             while(!s.empty()&& getPrecedence(ch)<=getPrecedence(s.top())){
//                 prefix+=s.top();
//                 s.pop();
//             }
//             s.push(ch);
//         }
//     }
//     while(!s.empty()){
//         prefix+=s.top();
//         s.pop();
//     }
//     reverse(prefix.begin(),prefix.end());
//     return prefix;
// }



// int main() {
    // string postfixExpression ;
    // cout << "Enter postfix expression: "<<endl;
    // // cin >> postfixExpression;
    // getline(cin,postfixExpression);
    // cout << "Result: " << getPostfix(postfixExpression) << endl;
    
    
    // string infixExpression;
    // cout << "Enter infix expression: ";
    // getline(cin, infixExpression);

    // // (i)
    // vector<string> expression = {"5", "6","2","+","*", "12","4","/","-"};
    // (ii)
    // vector<string> expression = {"2", "3", "^", "5", "2", "2", "^", "*", "12", "6", "/", "-", "+"};
    // int result = PostfixEvaluation(expression);
    // cout << "Result: " << result << endl;



//     return 0;
// }
