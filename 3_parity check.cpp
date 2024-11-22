#include <iostream>
using namespace std;

// Function to simulate channel and modify the array
void channel(int arr[], int size) {
    // Introduce an error by flipping one bit (for demonstration)
    // For example, flipping the first bit
    arr[0] = arr[0] == 0 ? 1 : 0;
}

// Function to check parity and detect errors
bool checkParity(int arr[], int size) {
    int parity = 0;

    // Calculate parity
    for (int i = 0; i < size; i++) {
        parity ^= arr[i];
    }

    // If parity is 0, no error; otherwise, error detected
    return parity == 0;
}

int main() {
    int size;

    // Take input for array size
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];

    // Take input for the array
    cout << "Enter the array elements (0s and 1s): ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Display original array
    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Pass the array through the channel
    channel(arr, size);

    // Display modified array
    cout << "Modified array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Check parity and detect errors
    if (checkParity(arr, size)) {
        cout << "No error detected." << endl;
    } else {
        cout << "Error detected in the array!" << endl;
    }

    return 0;
}

