#include <iostream>
#include <random>
#include <algorithm>
#include <signal.h>
#include <fstream>
#include <semaphore.h>
#include <unistd.h>

#include "misc/Array2D.h"
#include "misc/Generators.h"
#include "misc/SignalHandlers.h"

using namespace std;

static int PRISONERS_LIMIT;
static int GENERATIONS_LIMIT;
static int JUDGES_LIMIT;
static int SEM_TIMEOUT;
static std::pair<int,int> PAYOUT_TABLE[4];

static void setup_interface() {

    cout << "Hi, this is training facility for prisoners.\nWe train them to solve prisoners dilemma.\nSquid Game style :)\n\n ";

    prisoners:
        cout << "Enter max prisoners count (must be divisible by 2 and greater that 0): ";
    if (cin >> PRISONERS_LIMIT) {
        if (PRISONERS_LIMIT % 2 !=0  || PRISONERS_LIMIT <= 0) {
            cout << endl << PRISONERS_LIMIT << " is not a multiple of 2 on is not greater than 0\n";
            goto prisoners;
        }
    }else {
        cin.clear();
        cin.ignore();
        cout << endl << "Invalid character\n";
        goto prisoners;
    }

    judges:
            cout << "Enter max simultaneous games count (must be greater that 0): ";
    if (cin >> JUDGES_LIMIT) {
        if (JUDGES_LIMIT % 2 !=0  || JUDGES_LIMIT <= 0) {
            cout << endl << JUDGES_LIMIT << " is not a multiple of 2 on is not greater than 0\n";
            goto judges;
        }
    }else {
        cin.clear();
        cin.ignore();
        cout << endl << "Invalid character\n";
        goto judges;
    }

    generations:
        cout << "Enter max generations count: ";
    if (cin >> GENERATIONS_LIMIT){
        if (GENERATIONS_LIMIT <= 0) {
            cout << endl << "Generations limit must be greater than 0\n";
            goto generations;
        }
    }else {
        cin.clear();
        cin.ignore();
        cout << endl << "Invalid character\n";
        goto generations;
    }


    string response;
    weights:
        cout << "Do you want to load starting weights from \'./weights.nn\' file? ( Yy / Nn ): ";
    if (cin >> response && !response.empty()) {
        if (static_cast<char>(tolower(response[0])) == 'y') {
            //TODO: load weights from file
        } else if (static_cast<char>(tolower(response[0])) == 'n') {
            //TODO: generate weights
        }
        else
            goto weights;
    }else {
        cin.clear();
        cin.ignore();
        cout << endl << "Invalid character\n";
        goto weights;
    }
}

static void read_payout_table() {
    std::ifstream file("./config/payout_table.txt");

    cout << "f";
    if (!file.is_open()) {
        cout << "r";
        raise(SIGQUIT);
    }
}

static void set_errors_handlers() {
    SignalHandlers::setup(SIGQUIT, sigquit_handler);
    cout << "-";
}

int main() {
    cout << "s";
    set_errors_handlers();
    cout << "r";
    read_payout_table();
    cout << "e";
}