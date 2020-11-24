#include <iostream>
#include <time.h>

using namespace std;

int len = 6;

char *vowels[6] = {"a", "e", "i", "o", "y", "u"};
char *consonants[20] = {"b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y" "z"};

char *syllable[2];

int main()
{
    srand(time(0));

    for(int i = 0; i < 3; i++)
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


        }
    }
}
