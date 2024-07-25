
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Seed the random number generator
    srand(time(0));

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;
    int guess;

    cout << "Guessing Game!" << endl;

    while (true) {
        cout << "Enter your guess (1-100): ";
        cin >> guess;

        if (guess == secretNumber) {
            cout << "Congratulations! You guessed the number." << endl;
            break;
        } else if (guess < secretNumber) {
            cout << "Too low!" << endl;
        } else {
            cout << "Too high!" << endl;
        }
    }

    return 0;
}