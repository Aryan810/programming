// C Program to Take Multiple Inputs from User

#include <stdio.h>

int main()
{

    // Declare variables to hold the number of integers and
    // loop index
    int n, i;

    // Prompt the user to enter the number of inputs they
    // want to enter
    printf(
        "Enter the number of integers you want to input: ");
    scanf("%d", &n);

    // Declare an array of size n to hold the integers
    int arr[n];
    printf("Enter %d integers:\n", n);

    // Loop to read n integers from the user
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the integers entered by the user
    printf("You entered:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}