#include <iostream> // For output in console
#include <time.h> // For random numbers
#include <fstream> // For output in file
#include <string>
#include <sstream>

using namespace std; // To save time :D

int len; // World len
int quantity; // Word quantity
char firstSymbol; // First symbol in the word

char *vowels[6] = {"a", "e", "i", "o", "y", "u"};
char *consonants[21] = {"b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y","z"};

ofstream file("file.txt"); // Create new file

// Set Options to generate
void setOptions(int *len, int *quantity, char *firstSymbol)
{
    string inputString; // Create input var for input

    // Set options
    cout << "Input length of nick:";
    getline(cin, inputString); // Get line and put to the input var
    stringstream(inputString) >> *len; // From var to work var
    cout << "Input first symbol(optional):";
    getline(cin, inputString);
    stringstream(inputString) >> *firstSymbol;
    *firstSymbol = tolower(*firstSymbol);
    cout << "Input quantity of generate nicks:";
    getline(cin, inputString);
    stringstream(inputString) >> *quantity;
}
char *generateRandomSymbol(int decide, int probability = 0) // Func for generate random symbols
{
    switch (decide)
    {
        case 0: // Only vowels
            return vowels[rand()%6];
        case 1: // Only consonants
            return consonants[rand()%21];
        case 2: // Herniation with probability
            int i = rand()%100; // Generate number range

            if (i >= probability)
            {
                return vowels[rand()%6];
            }

            else if (i <= probability)
            {
                return consonants[rand()%21];
            }

    }
}

bool checkVowels(char symbol) // Func for check vowels
{
    for(char *i : vowels) // Iterating over the list of vowels
    {
        if(*i == symbol)
        {
            return true;
        }
    }
    return false;
}

char generateNextSymbol(char lastSymbol) // Generate next symbol
{
    // If vowels
    if(checkVowels(lastSymbol))
    {
        return *generateRandomSymbol(2, 87);
    }

    // Else
    else
    {
        return *generateRandomSymbol(2, 5);
    }
}

int main() // Main function
{

    srand(time(0)); // For random numbers

    setOptions(&len, &quantity, &firstSymbol); // Set start options
    char nick[len]; // Create nick array

    for(int i = 0; i < quantity; i++)
    {
        if(firstSymbol == *"") // If empty get random start symbol
        {
            nick[0] = *generateRandomSymbol(2, 93); // Set first symbol
        }

        else
        {
            nick[0] = firstSymbol;
        }
        // Generate symbols
        for (int i = 1; i < len; i++)
        {
            nick[i] = generateNextSymbol(nick[i - 1]); // Generate next symbol
        }

        // Output nick
        for (char i : nick)
        {
            cout << i;
            file << i; // Write symbol nick
        }
        cout << endl;
        file << endl; // Down to next line
    }
    file.close(); // Close file
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
