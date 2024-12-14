#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int isDigit(char ch) {
    if(ch >= 48 && ch <= 57)
    return 1;
    else
    return 0;
}

int isOperator(char op) {
    if(op == '+' || op == '-' || op == '*' || op == '/')
    return 1;
    else    
    return 0;
}

int performOperation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return b != 0 ? a / b : 0;
    }
    return 0;
}

int findPrecedence(char op) {
    if (op == '*' || op == '/') 
        return 2;
    else if (op == '+' || op == '-') 
        return 1;
    else
        return 0;
}

int main() {
    char *expression = (char *)malloc(100 * sizeof(char));
    if (expression==NULL) {
        printf("Memory is not allocated.\n");
        exit(1);
    }

    printf("Enter the mathematical expression: ");
    fgets(expression, 100, stdin);
    expression[strcspn(expression, "\n")] = 0; 

    char *exp = (char *)malloc(100 * sizeof(char));
    if (exp==NULL) {
        printf("Memory is not allocated.\n");
        free(expression);
        exit(1);
    }

    int j = 0;
    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] != ' ') {
            exp[j++] = expression[i];
        }
    }
    exp[j] = '\0';

    int *operands = (int *)malloc(100 * sizeof(int));    //stack for operands
    if (operands==NULL) {
        printf("Memory is not allocated.\n");
        free(expression);
        free(exp);
        exit(1);
    }

    char *operators = (char *)malloc(100 * sizeof(char));     //stack for operators
    if (operators==NULL) {
        printf("Memory is not allocated.\n");
        free(expression);
        free(exp);
        free(operands);
        exit(1);
    }

    int top = -1; 
    int opTop = -1; 
    int n = strlen(exp);
    bool expectOperand = true;

    for (int i = 0; i < n; i++) {
        if (isDigit(exp[i])) {
            int val = 0;
            while (i < n && isDigit(exp[i])) {
                val = val * 10 + (exp[i] - '0');
                i++;
            }
            i--;
            operands[++top] = val;
            expectOperand = false;
        } 
        else if (i == 0 && exp[i] == '+') {
            continue;
        } 
        else if (exp[i] == '-' && expectOperand) {
            int val = 0;
            i++;
            while (i < n && isDigit(exp[i])) {
                val = val * 10 + (exp[i] - '0');
                i++;
            }
            i--;
            operands[++top] = -val;
            expectOperand = false;
        } else if (isOperator(exp[i])) {
            if (expectOperand) {
                printf("Error! Invalid expression.\n");
                free(expression);
                free(exp);
                free(operands);
                free(operators);
                return 0;
            }
            while (opTop != -1 && 
                   findPrecedence(operators[opTop]) >= findPrecedence(exp[i])) {
                int b = operands[top--];
                int a = operands[top--];
                char oper = operators[opTop--];

                if (oper == '/' && b == 0) {
                    printf("Division by zero Error.\n");
                    free(expression);
                    free(exp);
                    free(operands);
                    free(operators);
                    return 0;
                }
                operands[++top] = performOperation(a, b, oper);
            }
            operators[++opTop] = exp[i];
            expectOperand = true;
        } else {
            printf("Error! Invalid expression.\n");
            free(expression);
            free(exp);
            free(operands);
            free(operators);
            return 0;
        }
    }

    if (expectOperand) {
        printf("Error! Invalid expression.\n");
        free(expression);
        free(exp);
        free(operands);
        free(operators);
        return 0;
    }

    while (opTop != -1) {
        int b = operands[top--];
        int a = operands[top--];
        char oper = operators[opTop--];

        if (oper == '/' && b == 0) {
            printf("Division by zero Error.\n");
            free(expression);
            free(exp);
            free(operands);
            free(operators);
            return 0;
        }
        operands[++top] = performOperation(a, b, oper);
    }

    printf("The result is: %d\n", operands[top]);

    free(expression);
    free(exp);
    free(operands);
    free(operators);

    return 0;
}
