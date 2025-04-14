#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0)); // Seed random number generator
    int number = rand() % 100 + 1; // Random number between 1 and 100
    int guess;

    cout << "Guess a number between 1 and 100: ";

    while (true) {
        cin >> guess;

        if (guess > number) {
            cout << "Too high! Try again: ";
        }
        else if (guess < number) {
            cout << "Too low! Try again: ";
        }
        else {
            cout << "Congratulations! You guessed the correct number: " << number << endl;
            break;
        }
    }

    return 0;
}