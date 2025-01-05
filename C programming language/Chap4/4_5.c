//Add access to library functions like sin, exp, and pow.

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>  // Include math library for sin, exp, pow

#define MAXOP 100
#define MAXVAL 100

// Stack for operands
double val[MAXVAL];
int sp = 0;

// Function prototypes
int getop(char []);
void push(double);
double pop(void);
void clear(void);
void duplicate(void);
void swap(void);
void print_top(void);
void handle_math_function(char s[]);

// Main calculator loop
int main() {
    int type;
    double op2;
    char s[MAXOP];
    
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case '0' ... '9': // Operand (number)
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':  // Modulus operator
                op2 = pop();
                if (op2 != 0.0)
                    push((int)pop() % (int)op2);  // Cast to int for modulus
                else
                    printf("error: zero divisor\n");
                break;
            case 'p':  // Print the top element of the stack
                print_top();
                break;
            case 'd':  // Duplicate the top element of the stack
                duplicate();
                break;
            case 's':  // Swap the top two elements of the stack
                swap();
                break;
            case 'c':  // Clear the stack
                clear();
                break;
            case 'e':  // Handle the exp() function
            case 's':  // Handle the sin() function
            case 'p':  // Handle the pow() function
                handle_math_function(s);
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    
    return 0;
}

// Pushes a value onto the stack
void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

// Pops and returns the top value from the stack
double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

// Clears the stack
void clear(void) {
    sp = 0;
}

// Prints the top element of the stack without popping it
void print_top(void) {
    if (sp > 0)
        printf("Top element: %.8g\n", val[sp-1]);
    else
        printf("error: stack empty\n");
}

// Duplicates the top element of the stack
void duplicate(void) {
    if (sp > 0)
        push(val[sp-1]);
    else
        printf("error: stack empty\n");
}

// Swaps the top two elements of the stack
void swap(void) {
    if (sp > 1) {
        double temp = val[sp-1];
        val[sp-1] = val[sp-2];
        val[sp-2] = temp;
    } else {
        printf("error: not enough elements to swap\n");
    }
}

// Handles mathematical functions like sin, exp, and pow
void handle_math_function(char s[]) {
    double op2, result;
    
    if (s[0] == 's') { // sin function
        if (sp > 0) {
            op2 = pop();
            result = sin(op2);
            push(result);
        } else {
            printf("error: stack empty\n");
        }
    }
    else if (s[0] == 'e') { // exp function
        if (sp > 0) {
            op2 = pop();
            result = exp(op2);
            push(result);
        } else {
            printf("error: stack empty\n");
        }
    }
    else if (s[0] == 'p') { // pow function
        if (sp > 1) {
            double op1 = pop();
            op2 = pop();
            result = pow(op1, op2);
            push(result);
        } else {
            printf("error: not enough operands for pow\n");
        }
    }
}

// Gets the next operator or operand from the input
int getop(char s[]) {
    int i, c;
    
    // Skip whitespaces
    while ((s[0] = c = getchar()) == ' ' || c == '\t')
        ;
    
    s[1] = '\0';
    
    // If it's a number or a negative sign, handle the number
    if (!isdigit(c) && c != '-' && c != '.')
        return c;  // Not a number
    
    i = 0;
    
    // Handle negative numbers (e.g., -5, -3.14)
    if (c == '-') {
        c = getchar();
        if (isdigit(c)) {
            s[++i] = '-';  // Include the negative sign
        } else {
            return '-';  // It is a minus operator, not a negative number
        }
    }
    
    // Read the integer part of the number
    if (isdigit(c)) {
        while (isdigit(s[++i] = c))
            c = getchar();
    }
    
    // Read the fractional part if any
    if (c == '.') {
        s[++i] = c;
        while (isdigit(c = getchar()))
            s[++i] = c;
    }
    
    s[i] = '\0';
    
    if (c != EOF)
        ungetc(c, stdin);
    
    return '0';  // Return '0' for a number
}
