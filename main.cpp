#include <iostream>
using namespace std;

int BinarySearch(int[], int, int);
int RecursiveBinarySearch(int[], int, int);
int RBS(int[], int, int, int);

int main() {
    int numbers[] = {2, 3, 4, 10, 15, 18, 19, 40 , 70};
    const int NUMBERS_SIZE = 9;
    int i, key, keyIndex;
    
    cout << "Numbers: ";
    
    for (int i = 0; i < NUMBERS_SIZE; i++) {
        cout << numbers[i] << ' ';
    }
    cout << endl;
    
    cout << "Enter a value for BinarySearch(): ";
    cin >> key;
    
    keyIndex = BinarySearch(numbers, NUMBERS_SIZE, key);
    
    if (keyIndex == -1) {
        cout << key << " was not found." << endl;
    }
    else {
        cout << "Found " << key << " at index " << keyIndex << "." << endl;
    }

    cout << "Enter a value for RecursiveBinarySearch(): ";
    cin >> key;
    
    keyIndex = RecursiveBinarySearch(numbers, NUMBERS_SIZE, key);
    
    if (keyIndex == -1) {
        cout << key << " was not found." << endl;
    }
    else {
        cout << "Found " << key << " at index " << keyIndex << "." << endl;
    }
    
    return 0;
}

int BinarySearch(int numbers[], int numbersSize, int key) {
    int mid, high, low;

    low = 0;
    high = numbersSize - 1;

    while(low <= high) {
        mid = (high + low) / 2;
        if (key > numbers[mid]) {
            low = mid + 1;
        }
        else if (key < numbers[mid]) {
            high = mid - 1;
        }
        else {
            return mid;
        }
    }
    return -1;
}

int RecursiveBinarySearch(int numbers[], int numbersSize, int key) {
    int high, low;

    low = 0;
    high = numbersSize - 1;
    return RBS(numbers, high, low, key);
}

int RBS(int numbers[], int high, int low, int key) {
    int mid = (high + low) / 2;
    if (numbers[mid] == key) {
        return mid;
    }
    else if (low > high) {
        return -1;
    }
    else {
        if (key > numbers[mid]) {
            return RBS(numbers, high, mid + 1, key);
        }
        else {
            return RBS(numbers, mid - 1, low, key);
        }
    }
}