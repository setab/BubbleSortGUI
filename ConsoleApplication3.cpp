#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

// Function to print a visual representation of the array numbers
void printGUI(int* arr, int len) {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < arr[i]; j++) {
			cout << "#";
		}
		cout << endl;
	}
}

// Bubble sort algorithm to sort the array in ascending order
int bubbleSort(int* arr, int len) {
	chrono::seconds oneSecond(1);
	int counter = 0;
	bool swapped = true;
	for (int i = 0; i < len && swapped == true; i++) {
		swapped = false;
		for (int j = 0; j < len - i - 1; j++) {
			// Swap adjacent elements if they are in the wrong order
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}
		// Display the current state of the array
		printGUI(arr, len);

		// Pause execution for 1 second
		this_thread::sleep_for(oneSecond);

		// Clear the terminal screen
		system("cls");

		counter++;
	}
	return counter;
}

int main() {
	int arr[] = { 12,13,17,20,22,24,26,29,15,2,30,3,11,28,21,23,7,14,6,16,25,5,9,27,4,1,8,19,18,10 };
	int len = size(arr); // Initialize the value to the size of the array

	printGUI(arr, len);

	system("cls");
	cout << endl;
	 
	int counter = bubbleSort(arr, len);

	printGUI(arr, len);

	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	// Print the total number of iterations the loop has run
	cout << "Total loop iterations: " << counter << endl;
}
