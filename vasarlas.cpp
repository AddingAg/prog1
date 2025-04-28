#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iomanip>
#include <fstream>
#include <set>

using namespace std;



int main() {
	ifstream file("lista.txt");
	ofstream output("listaki.txt");
	if (!file) {
		cerr << "File cannot be opened." << endl;
		return 1;
	}

	map < string, set<int> > itemDays;
	set<int> uniqueDays;
	int day;
	string item;

	while (file >> day >> item) {
		itemDays[item].insert(day);
		uniqueDays.insert(day);

	}

	int totalUniqueDays = uniqueDays.size();


	output << fixed << setprecision(2);
	map<string, set<int>>::iterator it;
	for ( it = itemDays.begin(); it != itemDays.end(); ++it) {
		string currentItem = it->first;
		set<int>& daysSet = it->second;

		double percentage = (static_cast<double>(daysSet.size()) / totalUniqueDays) * 100.0;
		output << currentItem << " " << percentage << "%" << endl;
	}
	cout << "Eredmények ki lettek irva a listaki.txt fileba." << endl;
	return 0;
}