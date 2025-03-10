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
	cout << "K�rem az aut� rendsz�m�t:";
	cin >> splate;

	Car* fcar = kereses(cars, splate);
	if (fcar) {
		cout << "Auto megtal�lva." << endl;
		cout << "Brand: " << fcar->brand << " Plate: " << fcar->plate << " Model: " << fcar->model << " Year: " << fcar->year;

	}
	else
	{
		cout << "Nincs ilyen rendsz�m� auto.";
	}
	return 0;
	}
