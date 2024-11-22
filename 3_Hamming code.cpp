#include <iostream>
using namespace std;

// Function to calculate parity bits
void calculateParityBits(int data[], int code[]) {
    // Assigning data bits
    code[2] = data[0];
    code[4] = data[1];
    code[5] = data[2];
    code[6] = data[3];

    // Calculating parity bits
    code[0] = code[2] ^ code[4] ^ code[6]; // P1
    code[1] = code[2] ^ code[5] ^ code[6]; // P2
    code[3] = code[4] ^ code[5] ^ code[6]; // P4
}

// Function to check and correct errors
void checkAndCorrect(int code[]) {
    int p1 = code[0] ^ code[2] ^ code[4] ^ code[6];
    int p2 = code[1] ^ code[2] ^ code[5] ^ code[6];
    int p4 = code[3] ^ code[4] ^ code[5] ^ code[6];

    int errorPosition = p1 + (p2 << 1) + (p4 << 2);

    if (errorPosition != 0) {
        cout << "Error detected at position: " << errorPosition << endl;
        code[errorPosition - 1] ^= 1; // Correct the bit
    } else {
        cout << "No error detected." << endl;
    }
}

int main() {
    int data[4], code[7];

    cout << "Enter 4 data bits (0 or 1): ";
    for (int i = 0; i < 4; i++) {
        cin >> data[i];
    }

    calculateParityBits(data, code);

    cout << "Encoded Hamming code: ";
    for (int i = 0; i < 7; i++) {
        cout << code[i];
    }
    cout << endl;

    // Simulate receiving a code (with or without error)
    cout << "Enter received 7-bit code: ";
    for (int i = 0; i < 7; i++) {
        cin >> code[i];
    }

    checkAndCorrect(code);

    cout << "Corrected code: ";
    for (int i = 0; i < 7; i++) {
        cout << code[i];
    }
    cout << endl;

    return 0;
}

