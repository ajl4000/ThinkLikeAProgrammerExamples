#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef struct{
  int grade;
  int studentID;
  string name;
} student;

bool compare(student a, student b) {
  return a.grade < b.grade;
}

int main(void) {
  student studentArray[20] = {
    {87, 10001, "Fred"},
    {28, 10002, "Tom"},
    {100, 10003, "Alistair"},
    {78, 10004, "Sasha"},
    {84, 10005, "Erin"},
    {98, 10006, "Belinda"},
    {75, 10007, "Leslie"},
    {70, 10008, "Candy"},
    {81, 10009, "Aretha"},
    {68, 10010, "Veronica"},
    {69, 10011, "Alex"},
    {58, 10012, "Fiona"},
    {92, 10013, "Rachel"},
    {37, 10014, "Yvonne"},
    {57, 10015, "Dobby"},
    {60, 10016, "Palpatine"},
    {88, 10017, "Aragorn"},
    {96, 10018, "Smeagol"},
    {91, 10019, "Shrek"},
    {42, 10020, "Billy"}
  };

  cout << "Before Sorting\n\n";
  for(student person : studentArray) {
    cout << "Grade: " << person.grade << ", Student ID: " << person.studentID << ", Name: " << person.name << endl;
  }

  sort(studentArray, studentArray+20, compare);

  cout << "\nAfter Sorting\n\n";
  for(const student& person : studentArray) {
    cout << "Grade: " << person.grade << ", Student ID: " << person.studentID << ", Name: " << person.name << endl;
  }
  return 0;
}