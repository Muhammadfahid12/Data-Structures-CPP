#include <iostream>
using namespace std;

int main()
{

    int a[3] = {11, 23, 3};
    int *p = &a[1]; // Make p point to the second element

    cout << p[-1]; // Prints the first element of a, equal to *(p - 1)
    cout << p[0];  // Prints the second element of a, equal to *p
    cout << p[1];

    return 0;
}