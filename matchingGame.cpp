#include "matchingGame.h"

//main menu for matching game program
void mainMenu()
{
    int count = 0;

    do
    {
        do 
        {
            cout << ("Welcome to the Linux Terms Matching Game!\n") << endl;
            cout << ("Menu:") << endl;
            cout << ("1. Game Rules") << endl;
            cout << ("2. Play New Game") << endl;
            cout << ("3. Load Previous Game") << endl;
            cout << ("4. Add Command") << endl;
            cout << ("5. Remove Command") << endl;
            cout << ("6. Display All Commands") << endl;
            cout << ("7. Save and Exit") << endl;

            cout << ("Please enter a number to go to: ");
            cin >> count;
        } while (count > 7 || count < 1);

        switch (count)
        {
            case 1: 
                printRules();
                break;

            case 2:
                playGame();
                break;
                
            case 3:
            case 4:
            case 5:
            case 6:
            case 7: 
                cout << ("Exiting...\n");
                break;

            default:
                break;
        }
    } while (count != 7);
}

//prints out rules of linux terms matching game to console
void printRules()
{
    cout << ("\nHere are the rules!\n") << endl;
    cout << ();
}