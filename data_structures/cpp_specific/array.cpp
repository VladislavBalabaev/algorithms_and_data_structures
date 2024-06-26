#include <iostream>


class some {
public:
    int data;

    some() {};                      // without it ERROR - can't initialize: some a[2]

    some(int data) {
        this->data = data;
    };
};


class stores {
public:
    // int array[];                        // Error: array of indeterminate length.

    // int n;
    // int array[n];                       // Error: nonstatic member reference must be relative to a specific object

    int* array;                         // Bad design: no real ownership of array, class has no knowledge of the length

    // Solution: use std::vector<>

    stores(int array[]) {
        this->array = array;
    };
};


int main() {
    int x[3] = { 1, 2, 3 };             // is a static array, gets automatically deleted
    int* y = new int[3]{ 1, 2, 3 };     // is a dynamic array, needs to be delete by hand explicitly
    int* z = new int[3]{ 1, 2, 3 };     // is a dynamic array, needs to be delete by hand implicitly
    free(y);
    delete y;


    some a[2];
    a[0] = some(5);
    a[1] = some(10);

    // array itself - one pointer to the first element.
    std::cout << "Array: " << a << " is the same as " << &a[0] << '\n';


    // array[n] is simply a syntactic sugar for *(array + n).
    std::cout << a[0].data << " equal to "<< (*a).data << '\n';
    std::cout << a[1].data << " equal to "<< (*(a + 1)).data << '\n';


    // elements of arrays are always allocated contiguously in memory
    std::cout << "An int is " << sizeof(some) << " bytes: " << &(a[0]) << " -> " << &(a[1]) << '\n';  // 00DBF720 -> 00DBF724


    // multidimensional array:
    int b[2][2] = { { 0, 1 }, { 2, 3 } };


    // giving array to functions
    int array[3] = { 1, 2, 3 };
    stores c(array);
    std::cout << c.array[1] << '\n';


    return 0;
};
