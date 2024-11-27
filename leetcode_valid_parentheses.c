#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 10


bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}


bool isValid(char *s) {
    char stack[MAX];
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];


        if (c == '(' || c == '{' || c == '[') {
            if (top == MAX - 1) {
                return false;
            }
            stack[++top] = c;
        }

        else if (c == ')' || c == '}' || c == ']') {
            if (top == -1 || !isMatchingPair(stack[top], c)) {
                return false;
            }
            top--;
        }
    }


    return top == -1;
}

int main() {
    char input[MAX];
    printf("Enter a string of brackets: ");
    scanf("%s", input);

    if (isValid(input)) {
        printf("The string is valid.\n");
    } else {
        printf("The string is invalid.\n");
    }

    return 0;
}
