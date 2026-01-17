#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string modName;
string startMap;
string trainMap;
int typeMod;
char anniv;

int main()
{

    ofstream File("liblist.gam");

    //Grab Mod Name
    cout << "What do you wan't your mod name to be?(How it will appear on Steam):";
    getline( cin, modName );
    cout << modName << "\n";
    // Grab Start Map
    cout << "What do you wan't the start map to be?(MUST BE EXACT TO MAP NAME, EXCLUDE .BSP):";
    getline( cin, startMap );
    cout << startMap << "\n";
    // Grab Training Map
    cout << "What do you wan't your training map to be?(MUST BE EXACT TO MAP NAME, EXCLUDE .BSP):";
    getline( cin, trainMap );
    cout << trainMap << "\n";

    while (true) {
        cout << "Is your mod made on the 25th anniversary update? y/n: \nIf you're not sure just pick yes." << endl;
        cin >> anniv;

        if (anniv == 'y' || anniv == 'Y' || anniv == 'n' || anniv == 'N')
        {
            break;
        }
        else
        {
            cout << "Invalid input. Please enter y or n.\n";
        }
    }

    while (true) {
        cout << "What type of mod is it? \n1: Singleplayer \n2: Multiplayer" << endl;
        cin >> typeMod;

        if (!cin.fail() && typeMod <= 2 && typeMod >= 1)
        {
            break;  // valid integer entered
        } else
        {
            cout << "Invalid input. Try again.\n";
            cin.clear();              // clear error flag
            cin.ignore(10000, '\n');  // discard bad input
        }
    }

    cout << "\nWriting..." << endl;

    File << "game \"" << modName << "\"" << endl;
    File << "startmap \"" << startMap << "\"" << endl;
    File << "trainmap \"" << trainMap << "\"" << endl;

    File << "mpentity \"info_player_deathmatch\"" << endl;
    File << "gamedll \"dlls/hl.dll\"" << endl;
    File << "gamedll_osx \"dlls/hl.dylib\"" << endl;
    File << "gamedll_linux \"dlls/hl.so\"" << endl;
    File << "secure \"1\"" << endl;

    if (typeMod = 1)
    {
        File << "type \"singleplayer_only\"" << endl;
    }
    else
    {
        File << "type \"multiplayer_only\"" << endl;
    }

    if (anniv == 'y' || anniv == 'Y')
    {
        File << "hd_background \"1\"" << endl;
        File << "animated_title \"1\"" << endl;
    }

    cout << "Done!";
    return 0;
}
