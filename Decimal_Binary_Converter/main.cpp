#include <iostream>
#include <stack>

using namespace std;

int main(void) {
    /*cout << "Please enter a Decimal Number: ";
    int num;
    cin >> num;
    stack<int> stack;
    while(num!=0) {
        stack.push(num%2);
        num /= 2;
    }
    while(!stack.empty()) {
        cout << stack.top();
        stack.pop();
    }
    cout << endl;*/
    cout << "Please enter a binary number of maximum 31 characters: ";
    char num[32] = "";
    cin.get(num, 32);
    int numLength = 0;
    for(int i = 0; i < 32; i++) {
        if(num[i] == '\0') {
            numLength = i;
            break;
        }
    }
    cout << numLength << endl;
    for(int i = numLength - 1; i >= 0; i--) {
        cout << num[i] << endl;
    }
    return 1;
}