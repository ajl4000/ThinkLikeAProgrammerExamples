#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void converter(string input, int iBase, int oBase);
void inputToDecimal(string input, int iBase, int* dPtr, int* index);
string decimalToOutput(int input, int oBase);
int charToInt(char c);
string returnString(int n);
string returnStringArr[16] = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};

int main(void) {
  converter("58904302A", 11, 4);
  return 0;
}

void converter(string input, int iBase, int oBase) {
  int dec = 0; //dec meaning decimal number
  int index = 0;
  inputToDecimal(input, iBase, &dec, &index);
  if(oBase == 10) {
    cout << "The output of base 10 is:" << dec << endl;
    return;
  }
  string output = decimalToOutput(dec, oBase);
  cout << "The output of number: " << input << "\nin base " << oBase << " is: " << output << endl;
}

void inputToDecimal(string input, int iBase, int* dPtr, int* index) {
  if(input.length() == 1) {
    *dPtr = charToInt(input.at(0));
    return;
  }
  int val = charToInt(input.at(0));
  input.erase(0, 1);
  inputToDecimal(input, iBase, dPtr, index);
  *dPtr += val * pow(iBase, ++(*index));
  return;
}

string decimalToOutput(int input, int oBase) {
  string output = "";
  while(input!=0) {
    string temp = returnStringArr[input%oBase];
    output = temp.append(output);
    input /= oBase;
  }
  return output;
}

int charToInt(char c) {
  switch(c) {
    case '0':
      return 0;
    case '1':
      return 1;
    case '2':
      return 2;
    case '3':
      return 3;
    case '4':
      return 4;
    case '5':
      return 5;
    case '6':
      return 6;
    case '7':
      return 7;
    case '8':
      return 8;
    case '9':
      return 9;
    case 'A':
      return 10;
    case 'B':
      return 11;
    case 'C':
      return 12;
    case 'D':
      return 13;
    case 'E':
      return 14;
    case 'F':
      return 15;
  }
}

string returnString(int n) {
  switch(n) {
    case 0:
      return "0";
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