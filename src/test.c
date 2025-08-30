#include "stdlib.h"
#include "printf.h"
#include "main.h"

struct TestCase
{
    int num_elements;
    int input[100];
    int expected_output[100];
};

int compare_arrays(int *arr1, int *arr2, int num_elements)
{
    for (int i = 0; i < num_elements; i++)
    {
        if (*(arr1 + i) != *(arr2 + i))
        {
            return 0;
        }
    }
    return 1;
}

int run_test(struct TestCase test)
{
    quicksort(test.input, 0, test.num_elements - 1);
    return compare_arrays(test.input, test.expected_output, test.num_elements);
}

void print_array(int *arr, int num_elements)
{
    printf("[");
    for (int i = 0; i < num_elements; i++)
    {
        printf("%d", i);
        if (i != num_elements - 1)
        {
            printf(",");
        }
    }
    printf("]");
}

int main()
{

    struct TestCase cases[] = {
        {.num_elements = 4,
         .input = {1, 4, 3, 4},
         .expected_output = {1, 3, 4, 4}},

        {.num_elements = 9,
         .input = {1, 4, 3, 4, 4, 12, 3, 1, 7},
         .expected_output = {1, 1, 3, 3, 4, 4, 4, 7, 12}},

        {.num_elements = 5,
         .input = {1, 4, 3, 4, 20},
         .expected_output = {1, 3, 4, 4, 20}}

    };

    int num_cases = sizeof(cases) / sizeof(cases[0]);

    for (int i = 0; i < num_cases; i++)
    {
        printf("test %d - ", i);

        int result = run_test(cases[i]);
        if (!result)
        {
            printf("failed!");
        }
        else
        {
            printf("passed!");
        }
        printf("\n");
    }
}