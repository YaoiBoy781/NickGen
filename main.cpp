#include <iostream> // For output in console
#include <time.h> // For random numbers
#include <fstream> // For output in file

using namespace std; // To save time :D

#define len 6 // World len

char *vowels[6] = {"a", "e", "i", "o", "y", "u"};
char *consonants[21] = {"b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y","z"};
char nick[len];

char *generateRandomSymbol(int decide, int probability = 0)
{
    switch (decide)
    {
        case 0:
            return vowels[rand()%6];

        case 1:
            return consonants[rand()%21];
        case 2:
            int i = rand()%100;

            if (i >= probability)
            {
                return vowels[rand()%6];
            }

            else if (i <= probability)
            {
                return consonants[rand()%21];
            }
            return 0;

    }
}

bool checkVowels(char symbol)
{
    for(char *i : vowels)
    {
        if(*i == symbol)
        {
            return true;
        }
    }

    return false;
}

char generateNextSymbol(char lastSymbol)
{
    if(checkVowels(lastSymbol))
    {
        return *generateRandomSymbol(2, 87);
    }

    else
    {
        return *generateRandomSymbol(2, 5);
    }
}

int main() // Main function
{
    srand(time(0)); // For random numbers

    nick[0] = *generateRandomSymbol(2, 93); // Set start symbol

    // Generate symbols
    for(int i = 1; i < len; i++)
    {
        nick[i] = generateNextSymbol(nick[i - 1]);
    }

    // Output nick
    for(char i : nick)
    {
        cout << i;
    }
}




























































































































































































/*
⣿⣿⣿⣵⣿⣿⣿⠿⡟⣛⣧⣿⣯⣿⣝⡻⢿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⠋⠁⣴⣶⣿⣿⣿⣿⣿⣿⣿⣦⣍⢿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⢷⠄⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣏⢼⣿⣿⣿⣿
⢹⣿⣿⢻⠎⠔⣛⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡏⣿⣿⣿⣿
⢸⣿⣿⠇⡶⠄⣿⣿⠿⠟⡛⠛⠻⣿⡿⠿⠿⣿⣗⢣⣿⣿⣿⣿
⠐⣿⣿⡿⣷⣾⣿⣿⣿⣾⣶⣶⣶⣿⣁⣔⣤⣀⣼⢲⣿⣿⣿⣿
⠄⣿⣿⣿⣿⣾⣟⣿⣿⣿⣿⣿⣿⣿⡿⣿⣿⣿⢟⣾⣿⣿⣿⣿
⠄⣟⣿⣿⣿⡷⣿⣿⣿⣿⣿⣮⣽⠛⢻⣽⣿⡇⣾⣿⣿⣿⣿⣿
⠄⢻⣿⣿⣿⡷⠻⢻⡻⣯⣝⢿⣟⣛⣛⣛⠝⢻⣿⣿⣿⣿⣿⣿
⠄⠸⣿⣿⡟⣹⣦⠄⠋⠻⢿⣶⣶⣶⡾⠃⡂⢾⣿⣿⣿⣿⣿⣿
⠄⠄⠟⠋⠄⢻⣿⣧⣲⡀⡀⠄⠉⠱⣠⣾⡇⠄⠉⠛⢿⣿⣿⣿
⠄⠄⠄⠄⠄⠈⣿⣿⣿⣷⣿⣿⢾⣾⣿⣿⣇⠄⠄⠄⠄⠄⠉⠉
⠄⠄⠄⠄⠄⠄⠸⣿⣿⠟⠃⠄⠄⢈⣻⣿⣿⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⢿⣿⣾⣷⡄⠄⢾⣿⣿⣿⡄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⠸⣿⣿⣿⠃⠄⠈⢿⣿⣿⠄⠄⠄⠄⠄⠄⠄.
*/
