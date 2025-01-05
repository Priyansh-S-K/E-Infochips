/*Extend atof to handle scientific notation of the form  
   123.45e-6 
where a floating-point number may be followed by e or E and an optionally signed exponent. 
*/

#include <ctype.h>
#include <stdio.h>

/* atof: convert string s to double, supporting scientific notation */
double atof(char s[]) {
    double val, power;
    int i, sign, exponent, exp_sign;

    // Skip whitespace
    for (i = 0; isspace(s[i]); i++) ;
    
    // Handle sign of the number
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') 
        i++;

    // Parse the integer part of the number
    for (val = 0.0; isdigit(s[i]); i++) 
        val = 10.0 * val + (s[i] - '0');

    // Parse the fractional part, if any
    if (s[i] == '.') 
        i++;
    for (power = 1.0; isdigit(s[i]); i++) { 
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }

    // Apply the sign to the value
    val = sign * val / power;

    // Check for scientific notation (e or E)
    if (s[i] == 'e' || s[i] == 'E') {
        i++; // Skip the 'e' or 'E'
        
        // Handle the sign of the exponent
        exp_sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-') 
            i++;

        // Parse the exponent
        for (exponent = 0; isdigit(s[i]); i++) {
            exponent = 10 * exponent + (s[i] - '0');
        }

        // Apply the exponent to the value (multiply or divide by 10^exponent)
        while (exponent-- > 0)
            val *= (exp_sign == 1) ? 10.0 : 0.1;
    }

    return val;
}

int main() {
    // Test cases for the updated atof function
    char s1[] = "123.45";
    char s2[] = "123.45e2";
    char s3[] = "123.45e-2";
    char s4[] = "-123.45e-2";
    char s5[] = "1.23E-3";
    char s6[] = "0.00123E3";

    printf("Result 1: %f\n", atof(s1));  // Expected: 123.450000
    printf("Result 2: %f\n", atof(s2));  // Expected: 12345.000000
    printf("Result 3: %f\n", atof(s3));  // Expected: 1.234500
    printf("Result 4: %f\n", atof(s4));  // Expected: -1.234500
    printf("Result 5: %f\n", atof(s5));  // Expected: 0.001230
    printf("Result 6: %f\n", atof(s6));  // Expected: 1.230000

    return 0;
}
