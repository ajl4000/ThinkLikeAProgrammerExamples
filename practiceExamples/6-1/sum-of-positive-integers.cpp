#include <iostream>

int sumArray(int* array, int arraySize) {
    int result;
    for(int i = 0; i < arraySize; i++) {
        if(array[i] > -1) result++;
    }
    return result;
}

int sumArrayRecursive(int* array, int arraySize) {
    if(arraySize == 0)
    {
        return 0;
    }
    int restOfArray = sumArrayRecursive(array, arraySize - 1);
    if(array[arraySize - 1] >= 0) restOfArray++;
    return restOfArray;
}

int main(void) {
    int array[14] = {2,6,-1,-6,5,-7,5,18,-38,5,-7,-65,5,-5};
    std::cout << sumArray(array, 14) << std::endl;
    std::cout << sumArrayRecursive(array, 14);
    return 1;
}