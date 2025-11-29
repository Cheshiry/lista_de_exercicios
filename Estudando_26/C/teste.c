#include <stdio.h>
// Create a structure called myStructure
struct myStructure {
    int myNum;
    char myLetter;
};

int main() {
    // Create a structure variable of myStructure called s1
    struct myStructure teste;

    // Assign values to members of s1
    teste.myNum = 13;
    teste.myLetter = 'B';

    // Print values
    printf("My number: %d\n", teste.myNum);
    printf("My letter: %c\n", teste.myLetter);

    return 0;
}