#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


int Isdigit(char ch) {
    if(ch >= 48 && ch <= 57)
    return 1;
    else
    return 0;
}


int Isoperator(char op) {
    if(op == '+' || op == '-' || op == '*' || op == '/')
    return 1;
    else 
    return 0;
}


int perform_operation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return b != 0 ? a / b : 0; 
    }
    return 0;
}


int findprecedence(char op) {
    if (op == '*' || op == '/') 
    return 2;
    else if (op == '+' || op == '-') 
    return 1;
    else
    return 0;
}


int main() {
    char expression[100];
    printf("Enter the mathematical expression: ");
    fgets(expression, sizeof(expression), stdin);
    expression[strcspn(expression, "\n")] = 0; 
    // Exclude white spaces
    char exp[100];
    int j = 0;
    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] != ' ') {
            exp[j++] = expression[i];
        }
    }
    exp[j] = '\0';

    int values[100], top = -1; // Stack for values
    char operators[100], op_top = -1; // Stack for operators
    bool flag = true;
    int n = strlen(exp);
    bool expect_operand = true; 

    for (int i = 0; i < n; i++) {
        if (Isdigit(exp[i])) {
            int val = 0;
            while (i < n && Isdigit(exp[i])) {
                val = val * 10 + (exp[i] - '0');
                i++;
            }
            i--; 
            values[++top] = val;
            expect_operand = false; 
        } 
        else if(i==0 && exp[i]=='+'){
            continue;
        }
        else if (exp[i] == '-' && expect_operand) { 
            int val = 0;
            i++;
            while (i < n && Isdigit(exp[i])) {
                val = val * 10 + (exp[i] - '0');
                i++;
            }
            i--;
            values[++top] = -val;
            expect_operand = false; 
        } else if (Isoperator(exp[i])) {
            if (expect_operand) {
                printf("Error! Invalid expression.\n");
                return 0;
            }
            while (op_top != -1 && 
                   findprecedence(operators[op_top]) >= findprecedence(exp[i])) {
                int b = values[top--];
                int a = values[top--];
                char oper = operators[op_top--];

                if (oper == '/' && b == 0) {
                    printf("Division by zero Error.\n");
                    return 0;
                }
                values[++top] = perform_operation(a, b, oper);
            }
            operators[++op_top] = exp[i];
            expect_operand = true; 
        } 
        else {
            printf("Error! Invalid expression.\n");
            return 0;
        }
    }

    if (expect_operand) {
        printf("Error! Invalid expression.\n");
        return 0;
    }

    // Process remaining operators
    while (op_top != -1) {
        int b = values[top--];
        int a = values[top--];
        char oper = operators[op_top--];

        if (oper == '/' && b == 0) {
            printf("Division by zero Error.\n");
            return 0;
        }
        values[++top] = perform_operation(a, b, oper);
    }

    printf("The result is: %d\n", values[top]);
    return 0;
}