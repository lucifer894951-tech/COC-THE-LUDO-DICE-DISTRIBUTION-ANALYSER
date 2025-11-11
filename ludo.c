#include <stdio.h>
#include <stdlib.h> // random fuction comes under this library so isko import krte hai random function ko use krne ke liye 
#include <time.h> //current time ko use krne ke liye

int main() {
    int counts[13] = {0}; // To store counts for sums 2–12
    int die1, die2, sum;
    int rolls = 1000000;  // 1 million rolls

    srand(time(NULL)); // Seed random number generator2

    // Simulate rolling two dice 1 million times
    for (int i = 0; i < rolls; i++) {
        die1 = (rand() % 6) + 1; // random number 1–6
        die2 = (rand() % 6) + 1; // random number 1–6
        sum = die1 + die2;       // sum of both dice
        counts[sum]++;           // increase count for this sum
    }

    // Print probability distribution
    printf("Sum\tCount\tSimulated %%\tTheoretical %%\n");
    printf("---------------------------------------------\n");

    for (int s = 2; s <= 12; s++) {
        double simulated = (double)counts[s] / rolls * 100;
        double theoretical;

        // Theoretical probabilities for two dice
        switch (s) {
            case 2: case 12: theoretical = 1.0/36*100; break;
            case 3: case 11: theoretical = 2.0/36*100; break;
            case 4: case 10: theoretical = 3.0/36*100; break;
            case 5: case 9:  theoretical = 4.0/36*100; break;
            case 6: case 8:  theoretical = 5.0/36*100; break;
            case 7:          theoretical = 6.0/36*100; break;
        }

        printf("%2d\t%7d\t%10.4f\t%10.4f\n", s, counts[s], simulated, theoretical);
    }

    return 0;
}

