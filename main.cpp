/* Program name: main.cpp
 * Author: Sahar Musleh
 * Date last updated: 11/14/2025
 * Purpose: Allow the user to create a custom candy mix using Candy class.
 */

 #include <iostream>
 #include "candy.h"
 #include <vector>
 #include <limits>
 using namespace std;
 
 int main() {
    cout << "=========================================================================================\n";
    cout << "                              Welcome to The Cavity Factory!\n";
    cout << "=========================================================================================\n\n";
    cout << "- We allow our beloved Candy Connoisseurs (yes, that'd be you) to build their own candy!\n";
    cout << "There's only one catch: To ensure that our customers explore their palate,\n";
    cout << "we only allow unique candy to be ordered. Don't think of it as a limitation, but as an EXPERIENCE!\n\n";

    int numCandies;
    do {
        cout << "How many candies will you be ordering today? (range: 1-25) :";
        cin >> numCandies;

        if (cin.fail() || numCandies < 1 || numCandies > 25) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 25./n";
        }

        Candy** candyArray = new Candy*[numCandies];

        for (int i = 0; i < numCandies; i++) {
            cout << "\nCandy #" << (i + 1) << " of " << numCandies << "\n";

            int flavorChoice,colorChoice;

            // Flavor menu
            cout << "Choose a flavor:\n"
            << "[1] Cotton Candy\n[2] Watermelon Burst\n[3] Papaya Bliss\n[4] Citrus Splash\n[5] Cola\n";

            do {
                cin >> flavorChoice;
                if (cin.fail() || flavorChoice < 1 || flavorChoice > 5) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid choice. Please enter 1-5: ";
                }
            } while (flavorChoice < 1 || flavorChoice > 5);

            // Color menu
            cout << "Choose a color:\n"
            << "[1] Scarlet Blaze\n[2] Azure Sky\n[3] Emerald Mist\n[4] Goldenrod Glow\n[5] Amethyst Haze\n";

            do {
                cin >> colorChoice;
                if (cin.fail() || colorChoice < 1 || colorChoice > 5) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid choice. Please enter 1-5: ";
                }
            } while (colorChoice < 1 || colorChoice > 5);

            // Create candy
            Candy* newCandy = new Candy(static_cast<flavorType>(flavorChoice - 1),
        static_cast<colorType>(colorChoice - 1));

        // Check uniqueness
        bool duplicate = false;
        for (int j = 0; j < i; j++) {
            if (candyArray[j]->getFlavor() == newCandy->getFlavor() &&
        candyArray[j]->getColor() == newCandy->getColor()) {
            duplicate = true;
            break;
        }
    }

    if (duplicate) {
        cout << "Oops! That flavor-color combo already exists. Try again.\n";
        delete newCandy;
        i--; // repeat this candy
    } else {
        candyArray[i] = newCandy;
        cout << "Marvelous! Your candy was added to the order.\n";
    }
        }

        cout << "\nYour order:\n";
        for (int i = 0; i < numCandies; i++) {
            cout << "#" << (i + 1) << " " << candyArray[i]->colorToString()
            << " " << candyArray[i]->flavorToString() << "/n";
        }

        for (int i = 0; i < numCandies; i++) {
            delete candyArray[i];
        }
        delete[] candyArray;

        return 0;
    }