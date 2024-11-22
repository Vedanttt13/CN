#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int totalFrames = 10;

bool receiveAck(int frame) {
    if (rand() % 5 == 0) {
        cout << "ACK for frame " << frame << " lost" << endl;
        return false;
    }
    cout << "Received ACK for frame " << frame << endl;
    return true;
}

int main() {

    int frame = 0;

    while (frame < totalFrames) {
        cout<<"Sending frame : "<<frame<<endl;

        if (receiveAck(frame)) {

            frame++;
        } else {
            cout << "Resending frame " << frame << endl;
        }
    }

    cout << "All frames sent and acknowledged." << endl;
    return 0;
}

