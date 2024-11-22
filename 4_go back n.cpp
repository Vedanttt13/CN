#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int Size = 4;          // Window size
int totalFrames = 10;  // Total number of frames to send

// Function to simulate receiving an acknowledgment
bool receiveAck(int& ack) {
    if (rand() % 5 == 0) { // Simulate ACK loss
        cout << "ACK " << ack << " lost" << endl;
        return false;
    }
    cout << "Received ACK for frame " << ack << endl;
    ack++;
    return true;
}

int main() {
    srand(time(0)); // Seed the random number generator
    int nxtframe = 0;  // Next frame to send
    int ack = 0;       // Acknowledged frame count

    while (ack < totalFrames) {
        for (int i = 0; i < Size && nxtframe < totalFrames; i++) {
            cout << "Sending frame " << nxtframe << endl;
            nxtframe++;
        }

        // Simulate receiving acknowledgments for sent frames
        for (int i = 0; i < Size && ack < nxtframe; i++) {
            if (!receiveAck(ack)) {
                // If an ACK is lost, resend from the lost frame
                nxtframe = ack;
                break;
            }
        }
    }

    cout << "All frames sent and acknowledged." << endl;
    return 0;
}

