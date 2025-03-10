#include <iostream>
#include <vector>
#include <string>
using namespace::std;

struct Car
{
	string brand;
	string plate;
	string model;
	int year;
};

Car* kereses(vector<Car>& cars, const string& plate) {
	for (auto& car : cars) {
		if (car.plate == plate) {
			return &car;
		}
	}
	return nullptr;
}

int main() {

	vector<Car> cars;

	cars.push_back({ "Toyota", "ABC-123", "Camry", 2020 });
	cars.push_back({ "Honda", "XYZ-987", "Civic", 2018 });
	cars.push_back({ "Ford", "LMN-456", "Mustang", 2022 });

	string splate;
	cout << "Kérem az autó rendszámát:";
	cin >> splate;

	Car* fcar = kereses(cars, splate);
	if (fcar) {
		cout << "Auto megtalálva." << endl;
		cout << "Brand: " << fcar->brand << " Plate: " << fcar->plate << " Model: " << fcar->model << " Year: " << fcar->year;

	}
	else
	{
		cout << "Nincs ilyen rendszámú auto.";
	}
	return 0;
	}
