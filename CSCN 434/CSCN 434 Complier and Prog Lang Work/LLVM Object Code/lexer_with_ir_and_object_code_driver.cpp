// This is the implementation of the driver file
#include <iostream>

// Using the functions from the lexer files
extern "C" {
    double testLogicalOr(double x, double y);
    double testLogicalAnd(double x, double y);
    double testLogicalXor(double x, double y);
}

// Main output of truth table
int main() {
    printf("0 OR 0: %s\n", testLogicalOr(0, 0) ? "true" : "false");
    printf("0 OR 1: %s\n", testLogicalOr(0, 1) ? "true" : "false");
    printf("1 OR 0: %s\n", testLogicalOr(1, 0) ? "true" : "false");
    printf("1 OR 1: %s\n", testLogicalOr(1, 1) ? "true" : "false\n");
    printf("\n");
    printf("0 OR 0: %s\n", testLogicalAnd(0, 0) ? "true" : "false");
    printf("0 OR 1: %s\n", testLogicalAnd(0, 1) ? "true" : "false");
    printf("1 OR 0: %s\n", testLogicalAnd(1, 0) ? "true" : "false");
    printf("1 OR 1: %s\n", testLogicalAnd(1, 1) ? "true" : "false\n");
    printf("\n");
    printf("0 OR 0: %s\n", testLogicalXor(0, 0) ? "true" : "false");
    printf("0 OR 1: %s\n", testLogicalXor(0, 1) ? "true" : "false");
    printf("1 OR 0: %s\n", testLogicalXor(1, 0) ? "true" : "false");
    printf("1 OR 1: %s\n", testLogicalXor(1, 1) ? "true" : "false\n");
}