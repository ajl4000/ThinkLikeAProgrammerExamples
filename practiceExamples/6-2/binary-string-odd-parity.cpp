#include <iostream>

bool findBinaryParity(int* array, int arraySize)
{
    int oneCount = 0;
    for(int i = 0; i < arraySize; i++)
    {
        if(array[i] == 1) oneCount++;
    }
    if(oneCount % 2) return true;
    return false;
}

int recursiveInnerFunction(int* array, int arraySize)
{
    if(arraySize == 0) return 0;
    int restOfArray = recursiveInnerFunction(array, arraySize - 1);
    if(array[arraySize - 1] == 1) restOfArray++;
    return restOfArray;
}

bool isParityOdd(int* array, int arraySize)
{
    int parity = recursiveInnerFunction(array, arraySize);
    if(parity % 2) return true;
    return false;
}

int main()
{
    int array[] = {0,1,0,1,0,0,1,0,1,1,0,1,0,1,0,1,0};
    int arraySize = 17;
    std::cout << findBinaryParity(array, arraySize) << std::endl;
    std::cout << isParityOdd(array, arraySize);
    return 1;
}