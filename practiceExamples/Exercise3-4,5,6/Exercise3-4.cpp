#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

typedef struct{
  char plaintextChar;
  char ciphertextChar;
} textCharacter;

/*void generateTextCharacterArray(textCharacter array[], char cipherArray[]) {
  for(int i = 0; i < 26; i++) {
    array[i] = {(char)(i + 65), cipherArray[i]};
  }
}*/

int myrandom(int i) {return rand()%i;}

void generateTextCharacterArray() {
  int intArray[26];
  for(int i = 0; i < 26; i++) {
    intArray[i] = i;
  }

  random_shuffle(begin(intArray), end(intArray), myrandom);
  vector<int> tempVector;
  vector<int> tempValueVector;
  for(int i = 0; i < 26; i++) {
    intArray[i] == i ? cout << "|" : cout << "_";
    if(intArray[i] == i) {
      tempVector.push_back(i);
      tempValueVector.push_back(intArray[i]);
    }
  }
  /*cout << endl;
  for(int i = 0; i < (int)tempVector.size(); i++) {
    cout << "(" << tempVector[i] << ", " << tempValueVector[i] << ") ";
  }
  cout << endl;
  for(const int& i : intArray) {
    cout << i << " ";
  }
  cout << endl;*/

  // if there is only one matching plaintext-ciphertext pair then swap that
  // ciphertext character with the character from the first index. Unless
  // the matching pair is the first index, in which case the first and second
  // index ciphertext characters will swap.
  if(tempVector.size() == 1) {
    if(tempVector[0] == 0) {
      intArray[0] = intArray[1];
      intArray[1] = tempValueVector[0];
    }
    intArray[tempVector[0]] = intArray[0];
    intArray[0] = tempValueVector[0];
  }
  // else rotate the ciphertext characters between the indexes that have
  // matching plaintext-ciphertext pairs.
  else if(tempVector.size() > 1) {
    for(int i = 0; i < (int)tempVector.size(); i++) {
      intArray[tempVector[i]] = tempValueVector[(i+1)%tempVector.size()];
    }
  }

  /*for(int i = 0; i < 26; i++) {
    intArray[i] == i ? cout << "|" : cout << "_";
  }
  cout << endl;
  for(const int& i : intArray) {
    cout << i << " ";
  }
  cout << endl;*/
  
  /*for(int i = 0; i < 26; i++) {
    array[i] = {(char)(i + 65), cipherArray[i]};
  }*/
}

void printTextCharacterArray(textCharacter array[]) {
  for(int i = 0; i < 26; i++) {
    cout << array[i].plaintextChar << " : " << array[i].ciphertextChar << endl;
  }
}

bool comparePlaintext(textCharacter a, textCharacter b) {
  return a.plaintextChar < b.plaintextChar;
}

bool compareCyphertext(textCharacter a, textCharacter b) {
  return a.ciphertextChar < b.ciphertextChar;
}

int getPlaintextSize(char plaintext[]) {
  for(int i = 0; i < 256; i++) {
    if(plaintext[i] == '\0') return i + 1;
  }
  return 0;
}
void encryptText(char *plaintext, const int plaintextSize, char *ciphertext, textCharacter *charArray) {
  for(int i = 0; i < plaintextSize; i++) {
    if(plaintext[i] > 64 && plaintext[i] < 91) {
      ciphertext[i] = charArray[plaintext[i] - 65].ciphertextChar;
    }
    else {
      ciphertext[i] = plaintext[i];
    }
  }
}

void decryptText(char *ciphertext, const int ciphertextSize, char *decryptedText, textCharacter *charArray) {
  for(int i = 0; i < ciphertextSize; i++) {
    if(ciphertext[i] > 64 && ciphertext[i] < 91) {
      decryptedText[i] = charArray[ciphertext[i] - 65].plaintextChar;
    }
    else {
      decryptedText[i] = ciphertext[i];
    }
  }
}

int main(void) {
  /*char cipherArray[26] {
    'T','Y','U','C','K','P','A','S','H','Z','E','B','X',
    'D','N','F','W','R','Q','J','O','I','M','G','L','V'
  };
  textCharacter charArray[26];
  generateTextCharacterArray(charArray, cipherArray);*/

  srand(unsigned(time(0)));
  //textCharacter charArray[26];
  generateTextCharacterArray(/*charArray*/);
   
  /*char plaintext[256];
  cout << "Plaintext: ";
  cin.getline(plaintext, 256);

  const int plaintextSize = getPlaintextSize(plaintext);
  char ciphertext[plaintextSize];
  encryptText(plaintext, plaintextSize, ciphertext, charArray);
  cout << "Ciphertext: " << ciphertext << endl;

  sort(charArray, charArray + 26, compareCyphertext);
  char decryptedText[plaintextSize];
  decryptText(ciphertext, plaintextSize, decryptedText, charArray);
  cout << "Decrypted Text: " << decryptedText << endl;*/
}