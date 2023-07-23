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

bool findBinaryParityRecursive(int* array, int arraySize)
{
    if(arraySize == 0) return 
}

int main()
{
    int array[] = {0,1,0,1,1,0,1,0,1,1,0,1,0,1,0,1,0};
    std::cout << findBinaryParity(array, 17);
    return 1;
}