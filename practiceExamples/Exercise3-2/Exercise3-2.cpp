#include <iostream>
#include <algorithm>

using namespace std;

void printArray(int intArray[], int ARRAY_SIZE) {
  cout << intArray[0];
  for(int i = 1; i < ARRAY_SIZE; i++) {
    cout << " " << intArray[i];
  }
  cout << endl;
}

int arrayMedian(int intArray[], int ARRAY_SIZE) {
  sort(intArray, intArray + ARRAY_SIZE);
  printArray(intArray, ARRAY_SIZE);
  if(ARRAY_SIZE % 2 == 0) {
    return (intArray[ARRAY_SIZE / 2] + intArray[ARRAY_SIZE / 2 - 1]) / 2;
  }
  return intArray[ARRAY_SIZE / 2];
}

int main(void) {
  const int NUM_AGENTS = 3;
  const int NUM_MONTHS = 12;
  int sales[NUM_AGENTS][NUM_MONTHS] = {
    {1856, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32},
    {5865, 5456, 3983, 6464, 9957, 4785, 3857, 3838, 4959, 1122, 7766, 2534},
    {23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434}
  };

  printArray(sales[0], NUM_MONTHS);
  cout << arrayMedian(sales[0], NUM_MONTHS) << endl;

  return 1;
}