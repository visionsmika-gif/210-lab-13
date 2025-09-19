// COMSC-210 | Lab 12 | Mika Aquino
// IDE used: Visual Studio 2022

#include <iostream>
#include <array>
#include <fstream>
#include <iomanip>
#include <algorithm> // For sort() and find()
#include <numeric> // For accumulate()

using namespace std;

int main() {
	const int SIZE = 30;
	array<double, SIZE> prices;
	const string FILE_NAME = "prices.txt";
	ifstream inputFile(FILE_NAME);
	const int CENT_DIGITS = 2; // Used for setprecision() to display cents properly

	// Ensure that the file is open
	if (!inputFile) {
		cout << "ERROR: Unable to open " << FILE_NAME << ". Please ensure that the file is in the same directory as the program.\n";
		return 1;
	}
	// Read the file into the array
	for (int i = 0; i < SIZE; ++i) {
		if (!(inputFile >> prices[i])) {
			cout << "ERROR: There was an error reading " << FILE_NAME << ". Please check that the file is in the proper format.\n";
			return 1;
		}
	}
	inputFile.close();

	cout << fixed << setprecision(CENT_DIGITS);

	// Use size() member function
	cout << "The inventory contains a list of " << prices.size() << " prices.\n\n";

	// Use empty() member function
	cout << "The list of prices is " << (prices.empty() ? "empty" : "not empty") << ".\n\n";

	// Use front() and back() member functions
	cout << "The price of the first item is $" << prices.front() << ".\n\n";
	cout << "The price of the last item is $" << prices.back() << ".\n\n";

	// Find the maximum and minimum of the array
	cout << "The most expensive item costs $" << *max_element(prices.begin(), prices.end()) << ".\n\n";
	cout << "The cheapest item costs $" << *min_element(prices.begin(), prices.end()) << ".\n\n";

	// Find the sum of the array
	cout << "The sum of the prices is $" << accumulate(prices.begin(), prices.end(), 0.0) << ".\n\n";

	// Use iterators to sort
	cout << "Prices sorted from lowest to highest:\n";
	sort(prices.begin(), prices.end());
	for (double val : prices) {
		cout << "$" << val << "  ";
	}
	cout << "\n\n";

	// Use reverse iterators to sort in reverse
	cout << "Prices sorted from highest to lowest:\n";
	sort(prices.rbegin(), prices.rend());
	for (double val : prices) {
		cout << "$" << val << "  ";
	}
	cout << "\n\n";

	// Find an element
	double target = 81.20;
	cout << "Finding an item with a price of $" << target << "...\n";
	array<double, SIZE>::iterator it; // Iterator for found element
	it = find(prices.begin(), prices.end(), target);

	if (it != prices.end()) {
		cout << "An item with a price of $" << target << " was found at index " << it - prices.begin() << ".\n\n";
	}
	else {
		cout << "An item with a price of $" << target << " was not found.\n\n";
	}

	// Create a new array to swap with
	array<double, SIZE> otherArray;
	for (int i = 0; i < SIZE; ++i) {
		otherArray[i] = i;
	}

	// Swap the arrays
	prices.swap(otherArray);
	cout << "After swapping with another array, the prices are now:\n";
	for (double val : prices) {
		cout << "$" << val << "  ";
	}
	cout << "\n";

	return 0;
}