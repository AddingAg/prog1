#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Dog {
    string name;
    int age;
    string breed;
    string color;
};

vector<Dog> loadDogs(const string& filename) {
    vector<Dog> dogs;
    ifstream file(filename);

    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return dogs;
    }

    Dog dog;
    while (file >> dog.name >> dog.age >> dog.breed>>dog.color) {
        dogs.push_back(dog);
    }

    return dogs;
}

void searchDog(const vector<Dog>& dogs, const string& searchName) {
    bool found = false;
    for (const auto& dog : dogs) {
        if (dog.name == searchName) {
            cout << "Found Dog: " << dog.name << ", Age: " << dog.age << ", Breed: " << dog.breed <<
                ", Color:"<<dog.color <<endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No dog named " << searchName << " found." << endl;
    }
}

int main() {
    vector<Dog> dogs = loadDogs("menhely.txt");

    string searchName;
    cout << "Enter dog name to search: ";
    cin >> searchName;

    searchDog(dogs, searchName);

    return 0;
}
