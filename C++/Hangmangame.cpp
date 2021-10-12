#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;
string choosing_secret_word();
void display_game_instructions(int maxt);
void inserting_letters(char guess_word[], int lengthOfWord);
void display_letters(string guess_, int lengthOfWord);
int is_guess_true(string secret_word, char guess_word[], char letter);
void displayman(int remainingGuess);


int main()
{
    int maxtries = 5;
    int remaining_tries = 5;
    string secretword;
    char guess_letter;

    display_game_instructions(maxtries);
    secretword = choosing_secret_word();
    int length_of_secret_word = secretword.length();
    char guess_word[length_of_secret_word];
    inserting_letters(guess_word, length_of_secret_word);
    cout << "The guess letter is : " << endl;
    display_letters(guess_word, length_of_secret_word);
    while (remaining_tries != 0)
    {
        cout << "Enter any letter of secret word :" << endl;
        cin >> guess_letter;
        int guess = is_guess_true(secretword, guess_word, guess_letter);
        if (guess == 0)
        {
            remaining_tries--;
            cout << "\nWhoops! that letter is not present in the word" << endl;
            displayman(remaining_tries);
        }
         if (guess == 1)
        {
            cout << "\nYay! You have found the letter" << endl;
        }
        if (guess == 2)
        {
            cout << "\nYou have already guessed this letter. Try something else!" << endl;
        }
        cout << "You can have " << remaining_tries << " more wrong attempts" << endl;
        cout << "Your guess word is:";
        display_letters(guess_word, length_of_secret_word);
        cout << endl;
        if (secretword == guess_word) {

            cout << "\n THRIFTY \n Congratulation! You won." << endl;
            return 0;
        }
        
    }
    if (secretword != guess_word)
    {
        cout << "\nToo many Guesses! You have been hanged." << endl;
        cout << "\nThe secret word was: ";
        display_letters(secretword, length_of_secret_word);
    }
    
}
string choosing_secret_word()
{
    srand(time(NULL));
    string agents[] = {"yoru", "skye", "sova", "viper", "jett", "brimstone", "breach", "reyna", "cypher", "omen", "phoenix", "astra", "raze", "killjoy", "sage"};

    int random_index = rand() % 15;
    string word = agents[random_index];
    return word;
}
void display_game_instructions(int maxt)
{
    cout << "\n"
            "        .-------------------------------------------------------------------------------.\n"
            "        |      _      _                                                                  |\n"
            "        |     | |    | |   __ _    _ __      __ _        /\\/\\      __ _    _ __          |\n"
            "        |     | |----| |  / _  |  |  _ \\    / _` |      /    \\    / _  |  |  _  \\        |\n"
            "        |     | |----| | | (_| |  | | | |  | (_| |     / /\\/\\ |  | (_| |  | | | |        |\n"
            "        |     |_|    |_|  \\_ _ |  |_| |_|   \\__, |     \\/    \\/   \\_ _ |  |_| |_|        |\n"
            "        |                                    |___/                                       |\n"
            "        .--------------------------------------------------------------------------------.\n";
    cout << "\n"
            "        .____________________________________________________________.\n"
            "        |                                                             | \n"
            "        |                            .___________.                    | \n "
            "       |                             \\   \\     /                     | \n"
            "        |                              \\  \\  \\ /                      |   \n"
            "        |                               \\  \\  /                       |     \n"
            "        |                                \\___/                        |       \n"
            "       .______________________________________________________________|       \n" ;                                                             

    cout << "The purpose of this game is to guess an valorant Agents name, secretly chosen by the application\n\n";
    cout << "You have to guess one letter at a time and you can have " << maxt << " wrong attempts\n\n";
    cout << "Enter a lower-case letter and don't forget to enter key after each guess\n\n";
    cout << "Let's play the game!\n\n";
}
void inserting_letters(char guess_word[], int length)
{
    for (int i = 0; i < length; i++)
    {
        guess_word[i] = '_';
        guess_word[length] = '\0';
    }
}
void display_letters(string guess_, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << guess_[i];
    }
    cout << endl;
}
int is_guess_true(string secretword, char guess_word[], char guess_letter)
{
    int flag = 0;
    for (int i = 0; i < secretword.length(); i++)
    {
        if (secretword[i] == guess_letter)
        {
            if (guess_word[i] == secretword[i])
            {
                flag = 2;
            }
            else
            {
                guess_word[i] = secretword[i];
                flag = 1;
            }
        }
    }

    return flag;
}
void displayman(int remainingGuess)
{

    string part[4];
    switch (remainingGuess)
    {
    case 0:
        part[3] = "|";
    case 1:
        part[2] = "/|\\";
    case 2:
        part[1] = "/|\\";
    case 3:
        part[0] = "( )";
        break;
    }

    cout << "--------------\n";
    cout << "  |       " << part[3] << endl;
    cout << "  |       " << part[3] << endl;
    cout << "  |      " << part[0] << endl;
    cout << "  |      " << part[1] << endl;
    cout << "  |      " << part[2] << endl;
    cout << "  |\n";
    cout << "  |\n";
    cout << "--------------\n";
}
