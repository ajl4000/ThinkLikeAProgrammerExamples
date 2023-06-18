#include <iostream>
#include <string>

using namespace std;

class automobileStorage {
    public:
        automobileStorage();
        automobileStorage(string newManufacturerName, string newModelName, int newModelYear);
        string automobileDescription(void);
        void setManufacturerName(string newName);
        string manufacturerName(void);
        void setModelName(string newName);
        string modelName(void);
        void setModelYear(int newYear);
        int modelYear(void);
    private:
        string _manufacturerName;
        string _modelName;
        int _modelYear;
};

automobileStorage::automobileStorage() {
    setManufacturerName("");
    setModelName("");
    setModelYear(-1);
}

automobileStorage::automobileStorage(string newManufacturerName, string newModelName, int newModelYear) {
    setManufacturerName(newManufacturerName);
    setModelName(newModelName);
    setModelYear(newModelYear);
}

string automobileStorage::automobileDescription(void) {
    return to_string(_modelYear) + " " + _modelName + " " + _manufacturerName;
}

void automobileStorage::setManufacturerName(string newName) {
    _manufacturerName = newName;
}

string automobileStorage::manufacturerName(void) {
    return _manufacturerName;
}

void automobileStorage::setModelName(string newName) {
    _modelName = newName;
}

string automobileStorage::modelName(void) {
    return _modelName;
}

void automobileStorage::setModelYear(int newYear) {
    _modelYear = newYear;
}

int automobileStorage::modelYear(void) {
    return _modelYear;
}

int main(void) {
    automobileStorage ibiza = automobileStorage("Seat", "Ibiza", 2018);
    cout << ibiza.automobileDescription() << '\n';
    return 1;
}