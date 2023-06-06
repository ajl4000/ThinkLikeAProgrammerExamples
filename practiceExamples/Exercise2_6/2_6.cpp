#include <iostream>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

void decimalToBinary(int num);
void binaryToDecimal(string num);
void recursion(string binaryNum, int* result);

int main(void) {
  cout << "would you like to convert from (D)ecimal to Binary or from (B)inary to Decimal? ";
  char choice;
  while(true) {
    cin >> choice;
    if(choice == 'D' || choice == 'B') {break;}
    else {
      cout << "Input not acceptable, please input your answer again\n";}
  }
  
  if(choice == 'D') {
    cout << "Please enter a decimal number: ";
    int input;
    cin >> input;
    decimalToBinary(input);
  }
  else {
    cout << "Please enter a binary number: ";
    string input;
    cin >> input;
    binaryToDecimal(input);
  }
}

void decimalToBinary(int num) {
  stack<int> stack;
  while(num!=0) {
    stack.push(num%2);
    num /= 2;
  }
  while(!stack.empty()) {
    cout << stack.top();
    stack.pop();
  }
  cout << endl;
}

void  binaryToDecimal(string num) {
  int result[2] = {0, 0};
  recursion(num, result);
  cout << result[0] << endl;
}

void recursion(string binaryNum, int* result) {
  if(binaryNum.length() == 1) {
    result[0] = (binaryNum.at(0) - 48);
    return;
  }

  int val = binaryNum.at(0) - 48;
  binaryNum.erase(0, 1);
  recursion(binaryNum, result);
  result[1] = result[1] + 1;
  result[0] = result[0] + val * pow(2, result[1]);
  return;
}