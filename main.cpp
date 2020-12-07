/*
#include <iostream>
#include <time.h>
#include <fstream>

using namespace std;

int len = 3;

char *vowels[6] = {"a", "e", "i", "o", "y", "u"};
char *consonants[21] = {"b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y","z"};
char *syllable[2];

ofstream file("Nicks.txt");

int main()
{
    srand(time(0));

    for(int i = 0; i < 50; i++)
    {

        for(int i = 0; i < len; i++)
        {

            if(rand()%10 <= 7)
            {
                syllable[0] = consonants[rand()%20];
                syllable[1] = vowels[rand()%6];
            }

            else
            {
                syllable[0] = consonants[rand()%20];
                syllable[1] = consonants[rand()%20];

            }

            for(int i = 0; i < 2; i++)
            {
                cout << syllable[i];
                file << syllable[i];
            }
        }
        cout << endl;
        file << endl;
    }
    file.close();
}
*/

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
