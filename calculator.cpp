#include <iostream>
#include <vector>
#include <sstream>
#include <bitset>

using namespace std;

// Function to parse an IP address or subnet mask string into a vector of integers
vector<int> parseIP(const string& ip) {
    vector<int> parts;
    stringstream ss(ip);
    string segment;

    while (getline(ss, segment, '.')) {
        parts.push_back(stoi(segment));
    }

    return parts;
}

// Function to calculate the network address
vector<int> calculateNetworkAddress(const vector<int>& ip, const vector<int>& mask) {
    vector<int> network(4);
    for (int i = 0; i < 4; i++) {
        network[i] = ip[i] & mask[i];
    }
    return network;
}

// Function to calculate the broadcast address
vector<int> calculateBroadcastAddress(const vector<int>& network, const vector<int>& mask) {
    vector<int> broadcast(4);
    for (int i = 0; i < 4; i++) {
        broadcast[i] = network[i] | (~mask[i] & 0xFF);
    }
    return broadcast;
}

// Function to display an IP address or other calculated addresses
void displayAddress(const string& label, const vector<int>& address) {
    cout << label << ": ";
    for (int i = 0; i < 4; i++) {
        cout << address[i];
        if (i < 3) cout << ".";
    }
    cout << endl;
}

int main() {
    string ipAddress, subnetMask;

    // Input: IP address and subnet mask
    cout << "Enter IP Address (e.g., 192.168.1.1): ";
    cin >> ipAddress;
    cout << "Enter Subnet Mask (e.g., 255.255.255.0): ";
    cin >> subnetMask;

    // Parse the inputs
    vector<int> ip = parseIP(ipAddress);
    vector<int> mask = parseIP(subnetMask);

    // Calculate network and broadcast addresses
    vector<int> networkAddress = calculateNetworkAddress(ip, mask);
    vector<int> broadcastAddress = calculateBroadcastAddress(networkAddress, mask);

    // Display the results
    displayAddress("Network Address", networkAddress);
    displayAddress("Broadcast Address", broadcastAddress);

    // Calculate and display the usable IP range
    cout << "Usable IP Range: ";
    for (int i = 0; i < 3; i++) cout << networkAddress[i] << ".";
    cout << networkAddress[3] + 1 << " - ";
    for (int i = 0; i < 3; i++) cout << broadcastAddress[i] << ".";
    cout << broadcastAddress[3] - 1 << endl;

    return 0;
}

