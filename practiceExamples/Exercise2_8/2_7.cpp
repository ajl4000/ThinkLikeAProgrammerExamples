#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void binaryToHexadecimal(string num);
void recursionB_H(string num, int numLength, string* result, int* stats);
string returnHex(int n);

int main(void) {
  binaryToHexadecimal("10101101001101");
  return 0;
}

void binaryToHexadecimal(string num) {
  string result = "";
  string* resultRef = &result;
  // the first value of stats is an accumulator and the second value
  // is the index
  int stats[2] = {0, 0};
  recursionB_H(num, num.length(), resultRef, stats);
  cout << result << endl;
}

void recursionB_H(string num, int numLength, string* result, int* stats) {
  if(num.length() == 1) {
    stats[0] = num.at(0) - 48;
    stats[1] += 1;
    return;
  }

  int val = num.at(0) - 48;
  num.erase(0, 1);
  recursionB_H(num, numLength, result, stats);
  stats[0] += val * pow(2, stats[1]);
  if(stats[1] == 3 || (num.length() + 1) == numLength) {
    *result = returnHex(stats[0]).append(*result);
    stats[1] = 0;
    stats[0] = 0;
    return;
  }
  stats[1] += 1;
  return;
}

string returnHex(int n) {
  switch(n) {
    case 1:
      return "1";
    case 2:
      return "2";
    case 3:
      return "3";
    case 4:
      return "4";
    case 5:
      return "5";
    case 6:
      return "6";
    case 7:
      return "7";
    case 8:
      return "8";
    case 9:
      return "9";
    case 10:
      return "A";
    case 11:
      return "B";
    case 12:
      return "C";
    case 13:
      return "D";
    case 14:
      return "E";
    case 15:
      return "F";
  }
}