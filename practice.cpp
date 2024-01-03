#include <iostream>
#include <stack>
#include <cmath>
#include<vector>
#include <cctype> // for isdigit function

using namespace std;

int performOperation(int operand1, int operand2, char op) {
    switch(op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
        case '^':
            return pow(operand1, operand2);
        default:
            cerr << "Invalid operator: " << op << endl;
            exit(EXIT_FAILURE);
    }
}

int postfixEvaluation(vector<string> expression) {
    stack<int> operands;

    for (string token : expression) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            operands.push(stoi(token));
        } else {
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();
            int result = performOperation(operand1, operand2, token[0]);
            operands.push(result);
        }
    }

    return operands.top();
}

int main() {
    vector<string> expression = {"2", "3", "^", "5", "2", "2", "^", "*", "12", "6", "/", "-", "+"};
    int result = postfixEvaluation(expression);
    cout << "Result: " << result << endl;

    return 0;
}
