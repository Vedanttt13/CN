#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int windowSize = 4;
int totalFrames = 10;

// Function to simulate receiving an acknowledgment
bool receiveAck(int frame) {
    if (rand() % 5 == 0) { // Simulate ACK loss
        cout << "ACK for frame " << frame << " lost" << endl;
        return false;
    }
    cout << "Received ACK for frame " << frame << endl;
    return true;
}

int main() {
    srand(time(0)); // Seed the random number generator

    int frames[10];         // Array to store frame statuses
    bool ack[10] = {false}; // Array to store acknowledgment statuses

    int nextFrame = 0;       // Next frame to send
    int lastAckedFrame = 0;  // Last acknowledged frame index

    while (lastAckedFrame < totalFrames) {
        // Send frames within the window size
        for (int i = 0; i < windowSize && nextFrame < totalFrames; i++) {
            if (frames[nextFrame] == -1) { // Only send unsent frames
                cout << "Sending frame " << nextFrame << endl;
                frames[nextFrame] = nextFrame;
            }
            nextFrame++;
        }

        // Receive acknowledgments for sent frames
        for (int i = lastAckedFrame; i < nextFrame; i++) {
            if (!ack[i] && receiveAck(i)) {
                ack[i] = true;
            }
        }

        // Slide the window by updating last acknowledged frame
        while (lastAckedFrame < totalFrames && ack[lastAckedFrame]) {
            lastAckedFrame++;
        }

        // Resend frames that have not been acknowledged
        for (int i = lastAckedFrame; i < nextFrame; i++) {
            if (!ack[i]) {
                cout<<"Sending frame"<<i<<endl;
            }
        }
    }

    cout << "All frames sent and acknowledged." << endl;
    return 0;
}

