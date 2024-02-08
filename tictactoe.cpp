#include <iostream>
#include <windows.h>
#include <ctime>
#include <conio.h>
#include "widgets.hpp"

//Global variables/arrays
int PVP_1Wins = 0;
int PVP_1Loss = 0;
int PVP_2Wins = 0;
int PVP_2Loss = 0;

int PVC_PWins = 0;
int PVC_PLoss = 0;
int PVC_CWins = 0;
int PVC_CLoss = 0;

int PVC_LevelIndex;

char PVP_Player1;
char PVP_Player2;
char PVC_Player;

std::string PVC_LevelStar1[] = {"_","_","_","_","_","_","_","_","_"};
std::string PVC_LevelStar2[] = {"_","_","_","_","_","_","_","_","_"};
std::string PVC_LevelStar3[] = {"_","_","_","_","_","_","_","_","_"};

//Called functions
void mainAfter();
void gamemodes();
void guide2();
void pvplayer();
void pvcomputer();
void pvcLevels();
void pvcLevelStart();

//Inner Widget functions
void movesDecider(int moves) {                        //Decides # of stars              (Status: COMPLETE)
    if(moves == 3) {
        //PERFECT
        PVC_LevelStar1[PVC_LevelIndex-1] = '#';
        PVC_LevelStar2[PVC_LevelIndex-1] = '#';
        PVC_LevelStar3[PVC_LevelIndex-1] = '#';
        PVC_PWins = PVC_PWins + 1;
        PVC_CLoss = PVC_CLoss + 1;
        pvcLevelStart();
    }
    if(moves == 4) {
        //ALRIGHT
        PVC_LevelStar1[PVC_LevelIndex-1] = '#';
        PVC_LevelStar2[PVC_LevelIndex-1] = '#';
        PVC_LevelStar3[PVC_LevelIndex-1] = '_';
        PVC_PWins = PVC_PWins + 1;
        PVC_CLoss = PVC_CLoss + 1;
        pvcLevelStart();
    }
    if(moves == 5) {
        //BAD
        PVC_LevelStar1[PVC_LevelIndex-1] = '#';
        PVC_LevelStar2[PVC_LevelIndex-1] = '_';
        PVC_LevelStar3[PVC_LevelIndex-1] = '_';
        PVC_PWins = PVC_PWins + 1;
        PVC_CLoss = PVC_CLoss + 1;
        pvcLevelStart();
    }
}
void pvcCWin(char character) {                        //PVC computer win                (Status: COMPLETE)
    setpos(32,5);
    std::cout << character << " wins!";
    Sleep(1000);
    PVC_PLoss = PVC_PLoss + 1;
    PVC_CWins = PVC_CWins + 1;
}
void pvcPWin(int moves) {                             //PVC player win                  (Status: COMPLETE)
    setpos(32,5);
    std::cout << PVC_Player << " wins!";
    Sleep(1000);
    movesDecider(moves);
}

//Main Functions
void pvpGame() {                                      //PvP main game                   (Status: COMPLETE)          (Optimized: TRUE)
    system("MODE 69,11");
    setcolor( 0x07 );
    int c;

    std::string input = " ";
    char places[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int freeSpaces = 0;

    char turn = PVP_Player1;

    int seqw[8][3] = {
        {0,1,2},
        {3,4,5},
        {6,7,8},
        {0,3,6},
        {1,4,7},
        {2,5,8},
        {0,4,8},
        {2,4,6}
    };

    while(1) {
        setpos(0,0);
        std::cout << "#==========================# TIC TAC TOE #==========================#";
        setpos(0,1);
        std::cout << "|   Player1  vs  Player2   |              |        |       |        #";
        setpos(0,2);
        std::cout << "|  " << turn << " turn                  |             G|   " << places[0] << "    |   " << places[1] << "   |    " << places[2] << "   #";
        setpos(0,3);
        std::cout << "#==========================#              | _______|_______|_______ #";
        setpos(0,4);
        std::cout << "#__________Choose__________#             A|        |       |        #";
        setpos(0,5);
        std::cout << "#                          #              |   " << places[3] << "    |   " << places[4] << "   |    " << places[5] << "   #";
        setpos(0,6);
        std::cout << "#   __A1__|__A2__|__A3__   #             M| _______|_______|_______ #";
        setpos(0,7);
        std::cout << "#   __B1__|__B2__|__B3__   #              |        |       |        #";
        setpos(0,8);
        std::cout << "#     C1  |  C2  |  C3     #             E|   " << places[6] << "    |   " << places[7] << "   |    " << places[8] << "   #";
        setpos(0,9);
        std::cout << "#                          #              |        |       |        #";
        setpos(0,10);
        std::cout << "#=============== Return(R) #---{     }---#==========================#";

        if(1) { //Player1 win checker
            for(int i = 0; i < 8; i++) {
                if(places[seqw[i][0]] == PVP_Player1 &&
                places[seqw[i][1]] == PVP_Player1 &&
                places[seqw[i][2]] == PVP_Player1) {
                    setpos(32,5);
                    std::cout << PVP_Player1 << " wins!";
                    Sleep(1000);
                    PVP_2Loss = PVP_2Loss + 1;
                    PVP_1Wins = PVP_1Wins + 1;
                    pvplayer();
                    break;
                }
            }
        }
        if(1) { //Player2 win checker
            for(int j = 0; j < 8; j++) {
                if(places[seqw[j][0]] == PVP_Player2 &&
                places[seqw[j][1]] == PVP_Player2 &&
                places[seqw[j][2]] == PVP_Player2) {
                    setpos(32,5);
                    std::cout << PVP_Player2 << " wins!";
                    Sleep(1000);
                    PVP_1Loss = PVP_1Loss + 1;
                    PVP_2Wins = PVP_2Wins + 1;
                    pvplayer();
                    break;
                }
            }
        }
        if(1) { //Tie checker
            freeSpaces = 0;
            for(int i = 0; i < 9; i++) {
                if(places[i] == ' ') {
                    freeSpaces = freeSpaces + 1;
                }
            }
            if(freeSpaces == 0) {
                setpos(30,5);
                std::cout << "Its a tie!";
                Sleep(1000);
                pvplayer();
                break;
            }
        }

        mainGoto:
        while(1){
            c = getch();
            if(c == CHAR_A || c == CHAR_A_CA) { //Choice A
                setpos(33,10);
                std::cout << "A";
                stGoto:
                while(1) {
                    c = getch();
                    if(c == CHAR1) { //Choice 1
                        setpos(35,10);
                        std::cout << "1";
                        while(1) {
                            c = getch();
                            if(c == KEY_ENTER) {
                                input = "A";
                                input.insert(1, "1");
                                goto nextStep;
                            }
                            if(c == BACKSPACE) {
                                setpos(35,10);
                                std::cout << " ";
                                goto stGoto;
                            }
                        }
                    }
                    if(c == CHAR2) { //Choice 2
                        setpos(35,10);
                        std::cout << "2";
                        while(1) {
                            c = getch();
                            if(c == KEY_ENTER) {
                                input = "A";
                                input.insert(1, "2");
                                goto nextStep;
                            }
                            if(c == BACKSPACE) {
                                setpos(35,10);
                                std::cout << " ";
                                goto stGoto;
                            }
                        }
                    }
                    if(c == CHAR3) { //Choice 3
                        setpos(35,10);
                        std::cout << "3";
                        while(1) {
                            c = getch();
                            if(c == KEY_ENTER) {
                                input = "A";
                                input.insert(1, "3");
                                goto nextStep;
                            }
                            if(c == BACKSPACE) {
                                setpos(35,10);
                                std::cout << " ";
                                goto stGoto;
                            }
                        }
                    }
                    if(c == BACKSPACE) { //Choice return
                        setpos(33,10);
                        std::cout << " ";
                        goto mainGoto;
                    }
                }
                break;
            }
            if(c == CHAR_B || c == CHAR_B_CA) { //Choice B
                setpos(33,10);
                std::cout << "B";
                ndGoto:
                while(1) {
                    c = getch();
                    if(c == CHAR1) { //Choice 1
                        setpos(35,10);
                        std::cout << "1";
                        while(1) {
                            c = getch();
                            if(c == KEY_ENTER) {
                                input = "B";
                                input.insert(1, "1");
                                goto nextStep;
                            }
                            if(c == BACKSPACE) {
                                setpos(35,10);
                                std::cout << " ";
                                goto ndGoto;
                            }
                        }
                    }
                    if(c == CHAR2) { //Choice 2
                        setpos(35,10);
                        std::cout << "2";
                        while(1) {
                            c = getch();
                            if(c == KEY_ENTER) {
                                input = "B";
                                input.insert(1, "2");
                                goto nextStep;
                            }
                            if(c == BACKSPACE) {
                                setpos(35,10);
                                std::cout << " ";
                                goto ndGoto;
                            }
                        }
                    }
                    if(c == CHAR3) { //Choice 3
                        setpos(35,10);
                        std::cout << "3";
                        while(1) {
                            c = getch();
                            if(c == KEY_ENTER) {
                                input = "B";
                                input.insert(1, "3");
                                goto nextStep;
                            }
                            if(c == BACKSPACE) {
                                setpos(35,10);
                                std::cout << " ";
                                goto ndGoto;
                            }
                        }
                    }
                    if(c == BACKSPACE) { //Choice return
                        setpos(33,10);
                        std::cout << " ";
                        goto mainGoto;
                    }
                }
                break;
            }
            if(c == CHAR_C || c == CHAR_C_CA) { //Choice C
                setpos(33,10);
                std::cout << "C";
                rdGoto:
                while(1) {
                    c = getch();
                    if(c == CHAR1) { //Choice 1
                        setpos(35,10);
                        std::cout << "1";
                        while(1) {
                            c = getch();
                            if(c == KEY_ENTER) {
                                input = "C";
                                input.insert(1, "1");
                                goto nextStep;
                            }
                            if(c == BACKSPACE) {
                                setpos(35,10);
                                std::cout << " ";
                                goto rdGoto;
                            }
                        }
                    }
                    if(c == CHAR2) { //Choice 2
                        setpos(35,10);
                        std::cout << "2";
                        while(1) {
                            c = getch();
                            if(c == KEY_ENTER) {
                                input = "C";
                                input.insert(1, "2");
                                goto nextStep;
                            }
                            if(c == BACKSPACE) {
                                setpos(35,10);
                                std::cout << " ";
                                goto rdGoto;
                            }
                        }
                    }
                    if(c == CHAR3) { //Choice 3
                        setpos(35,10);
                        std::cout << "3";
                        while(1) {
                            c = getch();
                            if(c == KEY_ENTER) {
                                input = "C";
                                input.insert(1, "3");
                                goto nextStep;
                            }
                            if(c == BACKSPACE) {
                                setpos(35,10);
                                std::cout << " ";
                                goto rdGoto;
                            }
                        }
                    }
                    if(c == BACKSPACE) { //Choice return
                        setpos(33,10);
                        std::cout << " ";
                        goto mainGoto;
                    }
                }
                break;
            }

            if(c == CHAR_R || c == CHAR_R_CA) { //Choice return
                setpos(34,10);
                std::cout << "R";
                while(1) {
                    c = getch();
                    if(c == KEY_ENTER) {
                        pvplayer();
                    }
                    if(c == BACKSPACE) {
                        setpos(34,10);
                        std::cout << " ";
                        goto mainGoto;
                    }
                }
            }
        }

        nextStep:
        if(1) {
            if(input == "A1") {
                if(places[0] == ' ') {
                    places[0] = turn;
                }
                else {
                    takenSpot();
                    goto mainGoto;
                }
            }
            else if(input == "A2") {
                if(places[1] == ' ') {
                    places[1] = turn;
                }
                else {
                    takenSpot();
                    goto mainGoto;
                }
            }
            else if(input == "A3") {
                if(places[2] == ' ') {
                    places[2] = turn;
                }
                else {
                    takenSpot();
                    goto mainGoto;
                }
            }
            else if(input == "B1") {
                if(places[3] == ' ') {
                    places[3] = turn;
                }
                else {
                    takenSpot();
                    goto mainGoto;
                }
            }
            else if(input == "B2") {
                if(places[4] == ' ') {
                    places[4] = turn;
                }
                else {
                    takenSpot();
                    goto mainGoto;
                }
            }
            else if(input == "B3") {
                if(places[5] == ' ') {
                    places[5] = turn;
                }
                else {
                    takenSpot();
                    goto mainGoto;
                }
            }
            else if(input == "C1") {
                if(places[6] == ' ') {
                    places[6] = turn;
                }
                else {
                    takenSpot();
                    goto mainGoto;
                }
            }
            else if(input == "C2") {
                if(places[7] == ' ') {
                    places[7] = turn;
                }
                else {
                    takenSpot();
                    goto mainGoto;
                }
            }
            else if(input == "C3") {
                if(places[8] == ' ') {
                    places[8] = turn;
                }
                else {
                    takenSpot();
                    goto mainGoto;
                }
            }
        }

        if(turn == 'X') {
            turn = 'O';
        }
        else if(turn == 'O') {
            turn = 'X';
        }
        setpos(4,9);
        std::cout << " ";
    }
}
void pvcGame() {                                      //PvC main game                   (Status: COMPLETE)          (Optimized: TRUE)
    system("MODE 69,11");
    setcolor( 0x07 );
    int c;

    std::string input = " ";
    char places[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int computerChoice;
    int freeSpaces = 0;
    int moves = 0;
    char cChar;

    int seqw[8][3] = {
        {0,1,2},
        {3,4,5},
        {6,7,8},
        {0,3,6},
        {1,4,7},
        {2,5,8},
        {0,4,8},
        {2,4,6}
    };

    if(PVC_Player == 'X') {
        cChar = 'O';
    }
    if(PVC_Player == 'O') {
        cChar = 'X';
    }

    while(1) {
        setpos(0,0);
        std::cout << "#==========================# TIC TAC TOE #==========================#";
        setpos(0,1);
        std::cout << "| Level " << PVC_LevelIndex << "       _   _   _  |              |        |       |        #";
        setpos(0,2);
        std::cout << "|--------------|" << PVC_LevelStar1[PVC_LevelIndex-1] << "| |" << PVC_LevelStar2[PVC_LevelIndex-1] << "| |" << PVC_LevelStar3[PVC_LevelIndex-1] << "|-|             G|   " << places[0] << "    |   " << places[1] << "   |    " << places[2] << "   #";
        setpos(0,3);
        std::cout << "#==========================#              | _______|_______|_______ #";
        setpos(0,4);
        std::cout << "#__________Choose__________#             A|        |       |        #";
        setpos(0,5);
        std::cout << "#                          #              |   " << places[3] << "    |   " << places[4] << "   |    " << places[5] << "   #";
        setpos(0,6);
        std::cout << "#   __A1__|__A2__|__A3__   #             M| _______|_______|_______ #";
        setpos(0,7);
        std::cout << "#   __B1__|__B2__|__B3__   #              |        |       |        #";
        setpos(0,8);
        std::cout << "#     C1  |  C2  |  C3     #             E|   " << places[6] << "    |   " << places[7] << "   |    " << places[8] << "   #";
        setpos(0,9);
        std::cout << "#                          #              |        |       |        #";
        setpos(0,10);
        std::cout << "#=============== Return(R) #---{     }---#==========================#";

        if(1) { //Computer win checker
            for(int i = 0; i < 8; i++) {
                if(places[seqw[i][0]] == cChar &&
                places[seqw[i][1]] == cChar &&
                places[seqw[i][2]] == cChar) {
                    pvcCWin(cChar);
                    pvcLevelStart();
                    break;
                }
            }
        }

        mainGoto:
        while(1){
            c = getch();
            if(c == CHAR_A || c == CHAR_A_CA) { //Choice A
                setpos(33,10);
                std::cout << "A";
                stGoto:
                while(1) {
                    c = getch();
                    if(c == CHAR1) { //Choice 1
                        setpos(35,10);
                        std::cout << "1";
                        while(1) {
                            c = getch();
                            if(c == KEY_ENTER) {
                                input = "A";
                                input.insert(1, "1");
                                goto nextStep;
                            }
                            if(c == BACKSPACE) {
                                setpos(35,10);
                                std::cout << " ";
                                goto stGoto;
                            }
                        }
                    }
                    if(c == CHAR2) { //Choice 2
                        setpos(35,10);
                        std::cout << "2";
                        while(1) {
                            c = getch();
                            if(c == KEY_ENTER) {
                                input = "A";
                                input.insert(1, "2");
                                goto nextStep;
                            }
                            if(c == BACKSPACE) {
                                setpos(35,10);
                                std::cout << " ";
                                goto stGoto;
                            }
                        }
                    }
                    if(c == CHAR3) { //Choice 3
                        setpos(35,10);
                        std::cout << "3";
                        while(1) {
                            c = getch();
                            if(c == KEY_ENTER) {
                                input = "A";
                                input.insert(1, "3");
                                goto nextStep;
                            }
                            if(c == BACKSPACE) {
                                setpos(35,10);
                                std::cout << " ";
                                goto stGoto;
                            }
                        }
                    }
                    if(c == BACKSPACE) { //Choice return
                        setpos(33,10);
                        std::cout << " ";
                        goto mainGoto;
                    }
                }
                break;
            }
            if(c == CHAR_B || c == CHAR_B_CA) { //Choice B
                setpos(33,10);
                std::cout << "B";
                ndGoto:
                while(1) {
                    c = getch();
                    if(c == CHAR1) { //Choice 1
                        setpos(35,10);
                        std::cout << "1";
                        while(1) {
                            c = getch();
                            if(c == KEY_ENTER) {
                                input = "B";
                                input.insert(1, "1");
                                goto nextStep;
                            }
                            if(c == BACKSPACE) {
                                setpos(35,10);
                                std::cout << " ";
                                goto ndGoto;
                            }
                        }
                    }
                    if(c == CHAR2) { //Choice 2
                        setpos(35,10);
                        std::cout << "2";
                        while(1) {
                            c = getch();
                            if(c == KEY_ENTER) {
                                input = "B";
                                input.insert(1, "2");
                                goto nextStep;
                            }
                            if(c == BACKSPACE) {
                                setpos(35,10);
                                std::cout << " ";
                                goto ndGoto;
                            }
                        }
                    }
                    if(c == CHAR3) { //Choice 3
                        setpos(35,10);
                        std::cout << "3";
                        while(1) {
                            c = getch();
                            if(c == KEY_ENTER) {
                                input = "B";
                                input.insert(1, "3");
                                goto nextStep;
                            }
                            if(c == BACKSPACE) {
                                setpos(35,10);
                                std::cout << " ";
                                goto ndGoto;
                            }
                        }
                    }
                    if(c == BACKSPACE) { //Choice return
                        setpos(33,10);
                        std::cout << " ";
                        goto mainGoto;
                    }
                }
                break;
            }
            if(c == CHAR_C || c == CHAR_C_CA) { //Choice C
                setpos(33,10);
                std::cout << "C";
                rdGoto:
                while(1) {
                    c = getch();
                    if(c == CHAR1) { //Choice 1
                        setpos(35,10);
                        std::cout << "1";
                        while(1) {
                            c = getch();
                            if(c == KEY_ENTER) {
                                input = "C";
                                input.insert(1, "1");
                                goto nextStep;
                            }
                            if(c == BACKSPACE) {
                                setpos(35,10);
                                std::cout << " ";
                                goto rdGoto;
                            }
                        }
                    }
                    if(c == CHAR2) { //Choice 2
                        setpos(35,10);
                        std::cout << "2";
                        while(1) {
                            c = getch();
                            if(c == KEY_ENTER) {
                                input = "C";
                                input.insert(1, "2");
                                goto nextStep;
                            }
                            if(c == BACKSPACE) {
                                setpos(35,10);
                                std::cout << " ";
                                goto rdGoto;
                            }
                        }
                    }
                    if(c == CHAR3) { //Choice 3
                        setpos(35,10);
                        std::cout << "3";
                        while(1) {
                            c = getch();
                            if(c == KEY_ENTER) {
                                input = "C";
                                input.insert(1, "3");
                                goto nextStep;
                            }
                            if(c == BACKSPACE) {
                                setpos(35,10);
                                std::cout << " ";
                                goto rdGoto;
                            }
                        }
                    }
                    if(c == BACKSPACE) { //Choice return
                        setpos(33,10);
                        std::cout << " ";
                        goto mainGoto;
                    }
                }
                ///
                break;
            }

            if(c == CHAR_R || c == CHAR_R_CA) { //Choice return
                setpos(34,10);
                std::cout << "R";
                while(1) {
                    c = getch();
                    if(c == KEY_ENTER) {
                        pvcLevelStart();
                    }
                    if(c == BACKSPACE) {
                        setpos(34,10);
                        std::cout << " ";
                        goto mainGoto;
                    }
                }
            }
        }

        nextStep:
        moves = moves + 1;
        if(1) {
            if(input == "A1") {
                if(places[0] == ' ') {
                    places[0] = PVC_Player;
                }
                else {
                    takenSpot();
                    goto mainGoto;
                }
            }
            if(input == "A2") {
                if(places[1] == ' ') {
                    places[1] = PVC_Player;
                }
                else {
                    takenSpot();
                    goto mainGoto;
                }
            }
            if(input == "A3") {
                if(places[2] == ' ') {
                    places[2] = PVC_Player;
                }
                else {
                    takenSpot();
                    goto mainGoto;
                }
            }
            if(input == "B1") {
                if(places[3] == ' ') {
                    places[3] = PVC_Player;
                }
                else {
                    takenSpot();
                    goto mainGoto;
                }
            }
            if(input == "B2") {
                if(places[4] == ' ') {
                    places[4] = PVC_Player;
                }
                else {
                    takenSpot();
                    goto mainGoto;
                }
            }
            if(input == "B3") {
                if(places[5] == ' ') {
                    places[5] = PVC_Player;
                }
                else {
                    takenSpot();
                    goto mainGoto;
                }
            }
            if(input == "C1") {
                if(places[6] == ' ') {
                    places[6] = PVC_Player;
                }
                else {
                    takenSpot();
                    goto mainGoto;
                }
            }
            if(input == "C2") {
                if(places[7] == ' ') {
                    places[7] = PVC_Player;
                }
                else {
                    takenSpot();
                    goto mainGoto;
                }
            }
            if(input == "C3") {
                if(places[8] == ' ') {
                    places[8] = PVC_Player;
                }
                else {
                    takenSpot();
                    goto mainGoto;
                }
            }
        }
        
        if(1) {
            setpos(0,0);
            std::cout << "#==========================# TIC TAC TOE #==========================#";
            setpos(0,1);
            std::cout << "| Level " << PVC_LevelIndex << "       _   _   _  |              |        |       |        #";
            setpos(0,2);
            std::cout << "|--------------|" << PVC_LevelStar1[PVC_LevelIndex-1] << "| |" << PVC_LevelStar2[PVC_LevelIndex-1] << "| |" << PVC_LevelStar3[PVC_LevelIndex-1] << "|-|             G|   " << places[0] << "    |   " << places[1] << "   |    " << places[2] << "   #";
            setpos(0,3);
            std::cout << "#==========================#              | _______|_______|_______ #";
            setpos(0,4);
            std::cout << "#__________Choose__________#             A|        |       |        #";
            setpos(0,5);
            std::cout << "#                          #              |   " << places[3] << "    |   " << places[4] << "   |    " << places[5] << "   #";
            setpos(0,6);
            std::cout << "#   __A1__|__A2__|__A3__   #             M| _______|_______|_______ #";
            setpos(0,7);
            std::cout << "#   __B1__|__B2__|__B3__   #              |        |       |        #";
            setpos(0,8);
            std::cout << "#     C1  |  C2  |  C3     #             E|   " << places[6] << "    |   " << places[7] << "   |    " << places[8] << "   #";
            setpos(0,9);
            std::cout << "#                          #              |        |       |        #";
            setpos(0,10);
            std::cout << "#=============== Return(R) #---{     }---#==========================#";
        
            if(1) { //Player win checker
                for(int i = 0; i < 8; i++) {
                    if(places[seqw[i][0]] == PVC_Player &&
                    places[seqw[i][1]] == PVC_Player &&
                    places[seqw[i][2]] == PVC_Player) {
                        pvcPWin(moves);
                        break;
                    }
                }
            }
            if(1) { //Tie checker
                freeSpaces = 0;
                for(int i = 0; i < 9; i++) {
                    if(places[i] == ' ') {
                        freeSpaces = freeSpaces + 1;
                    }
                }
                if(freeSpaces == 0) {
                    setpos(30,5);
                    std::cout << "Its a tie!";
                    Sleep(1000);
                    pvcLevelStart();
                    break;
                }
            }

            //COMPUTER
            computerChoice = (rand() % 9) + 1;
            while(1) {
                if(places[computerChoice] == ' ') {
                    if(PVC_Player == 'X') {
                        places[computerChoice] = cChar;
                        break;
                    }
                    if(PVC_Player == 'O') {
                        places[computerChoice] = cChar;
                        break;  
                    }
                }
                else{
                    computerChoice = (rand() % 9) + 1;
                }
            }
        }
    }
}
void pvcChar() {                                      //PvC char screen                 (Status: COMPLETE)          (Optimized: TRUE)
    setcolor( 0x07 );
    int position = 0;
    int c;

    setpos(0,0);
    std::cout << "#======# TIC TAC TOE #======#";
    setpos(0,1);
    std::cout << "#_________Character_________#";
    setpos(0,2);
    std::cout << "#               /           #";
    setpos(0,3);
    std::cout << "#              /            #";
    setpos(0,4);
    std::cout << "#           X / O           #";
    setpos(0,5);
    std::cout << "#            /              #";
    setpos(0,6);
    std::cout << "#           /               #";
    setpos(0,7);
    std::cout << "#===========================#";

    setpos(11,4);
    setcolor( 0x30 );
    std::cout << " X ";

    while(1) { //Positioning
        c = getch();
        if(c == KEY_RIGHT) { //Position right
            position++;
        }
        if(c == KEY_LEFT) { //Position left
            position--;
        }

        if(position > 1) { //Position equalizer
            position = 0;
        }
        if(position < 0) { //Position equalizer
            position = 1;
        }

        if(position == 1) { //Position: O
            pvcCharColor(0x30, 0x07);
            if(c == KEY_ENTER) { //Goes to pvcGame()
                PVC_Player = 'O';
                pvcGame();
                break;
            }
        }
        if(position == 0) { //Position: X
            pvcCharColor(0x07, 0x30);
            if(c == KEY_ENTER) { //Goes to pvcGame()
                PVC_Player = 'X';
                pvcGame();
                break;
            }
        }
    }
}
void pvpChar() {                                      //PvP char screen                 (Status: COMPLETE)          (Optimized: TRUE)
    setcolor( 0x07 );
    int position = 0;
    int c;
    bool isPlayerSpot = 1;

    PVP_Player1 = ' ';
    PVP_Player2 = ' ';

    setpos(0,0);
    std::cout << "#======# TIC TAC TOE #======#";
    setpos(0,1);
    std::cout << "#_________Character_________#";
    setpos(0,2);
    std::cout << "#  Player 1   |  Player 2   #";
    setpos(0,3);
    std::cout << "#             |             #";
    setpos(0,4);
    std::cout << "#    [ " << PVP_Player1 << " ]    |    [ " << PVP_Player2 << " ]    #";
    setpos(0,5);
    std::cout << "#    *****    |    *****    #";
    setpos(0,6);
    std::cout << "#             |             #";
    setpos(0,7);
    std::cout << "#===========================#";

    setpos(6,4);
    setcolor( 0x30 );
    std::cout << "   ";

    while(1){
        c = getch();
        position = 1;
        firstgoto:
        if(c == CHARX) { //Character X
            setpos(7,4);
            std::cout << "X";
            while(1) {
                c = getch();
                if(c == KEY_ENTER) {
                    setpos(6,4);
                    setcolor( 0x07 );
                    std::cout << " X ";
                    isPlayerSpot = 0;
                    PVP_Player1 = 'X';
                    goto secondgoto;
                }
                if(c == BACKSPACE) {
                    setpos(6,4);
                    setcolor( 0x30 );
                    std::cout << "   ";
                    goto firstgoto;
                }
            }
        }
        if(c == CHARO || c == CHAR0) { //Character O
            setpos(7,4);
            std::cout << "O";
            while(1) {
                c = getch();
                if(c == KEY_ENTER) {
                    setpos(6,4);
                    setcolor( 0x07 );
                    std::cout << " O ";
                    isPlayerSpot = 0;
                    PVP_Player1 = 'O';
                    goto secondgoto;
                }
                if(c == BACKSPACE) {
                    setpos(6,4);
                    setcolor( 0x30 );
                    std::cout << "   ";
                    goto firstgoto;
                }
            }
        }
    }
    if(isPlayerSpot == 0) {
        position = 1;
        secondgoto:
        setpos(20,4);
        setcolor( 0x30 );
        std::cout << "   ";
        while(1){
            c = getch();
            thirdgoto:
            if(c == CHARX) { //Character X
                if(PVP_Player1 != 'X') {
                    setpos(21,4);
                    std::cout << "X";
                    while(1) {
                        c = getch();
                        if(c == KEY_ENTER) {
                            setpos(20,4);
                            setcolor( 0x07 );
                            std::cout << " X ";
                            PVP_Player2 = 'X';
                            pvpGame();
                            break;
                        }
                        if(c == BACKSPACE) {
                            setpos(20,4);
                            setcolor( 0x30 );
                            std::cout << "   ";
                            goto thirdgoto;
                        }
                    }
                }
            }
            if(c == CHARO || c == CHAR0) { //Character O
                if(PVP_Player1 != 'O') {
                    setpos(21,4);
                    std::cout << "O";
                    while(1) {
                        c = getch();
                        if(c == KEY_ENTER) {
                            setpos(20,4);
                            setcolor( 0x07 );
                            std::cout << " O ";
                            PVP_Player2 = 'O';
                            pvpGame();
                            break;
                        }
                        if(c == BACKSPACE) {
                            setpos(20,4);
                            setcolor( 0x30 );
                            std::cout << "   ";
                            goto thirdgoto;
                        }
                    }
                }
            }
        }
    }
}
void pvcLevelStart() {                                //PvC level start screen          (Status: COMPLETE)          (Optimized: TRUE)
    system("MODE 29,8");
    setcolor( 0x07 );
    int position = 0;
    int c;

    setpos(0,0);
    std::cout << "#======# TIC TAC TOE #======#";
    setpos(0,1);
    std::cout << "#__________Level " << PVC_LevelIndex << "__________#";
    setpos(0,2);
    std::cout << "#         _   _   _         #";
    setpos(0,3);
    std::cout << "#- - - - |" << PVC_LevelStar1[PVC_LevelIndex-1] << "| |" << PVC_LevelStar2[PVC_LevelIndex-1] << "| |" << PVC_LevelStar3[PVC_LevelIndex-1] << "| - - - -#";
    setpos(0,4);
    std::cout << "#                           #";
    setpos(0,5);
    std::cout << "#           Start           #";
    setpos(0,6);
    std::cout << "#                           #";
    setpos(0,7);
    std::cout << "#=================== Return #";


    if(1) { //Starting position: Start
        pvcLevelColor(0x03, 0x07);
        position = 1;
    }
    while(1) { //Positioning
        c = getch();
        if(c == KEY_UP) { //Position up
            position++;
        }
        if(c == KEY_DOWN) { //Position down
            position--;
        }

        if(position > 1) { //Position equalizer
            position = 0;
        }
        if(position < 0) { //Position equalizer
            position = 1;
        }

        if(position == 1) { //Position: Start
            pvcLevelColor(0x03, 0x07);
            if(c == KEY_ENTER) { //Goes to pvcChar()
                pvcChar();
                break;
            }
        }
        if(position == 0) { //Position: Return
            pvcLevelColor(0x07, 0x03);
            if(c == KEY_ENTER) { //Goes to gamemodes()
                pvcLevels();
                break;
            }
        }
    }
}
void pvcLevels() {                                    //PvC levels screen               (Status: COMPLETE)          (Optimized: TRUE)
    int position = 0;
    int c;

    setpos(0,0);
    std::cout << "#======# TIC TAC TOE #======#";
    setpos(0,1);
    std::cout << "#______Computer Levels______#";
    setpos(0,2);
    std::cout << "#                           #";
    setpos(0,3);
    std::cout << "#     1   2   3   4   5     #";
    setpos(0,4);
    std::cout << "#                           #";
    setpos(0,5);
    std::cout << "#      6    7   8    9      #";
    setpos(0,6);
    std::cout << "#                           #";
    setpos(0,7);
    std::cout << "#=================== Return #";

    if(1) { //Starting position: 1
        levelColor("1");
        position = 0;
    }
    while(1) { //Positioning
        c = getch();
        if(c == KEY_RIGHT) { //Position up
            position++;
        }
        if(c == KEY_LEFT) { //Position down
            position--;
        }

        if(position > 9) { //Position equalizer
            position = 0;
        }
        if(position < 0) { //Position equalizer
            position = 9;
        }

        switch (position) {
            case 0: //Level 1
                levelColor("1");
                if(c == KEY_ENTER) { //Goes to pvcLevelStart()
                    PVC_LevelIndex = 1;
                    pvcLevelStart();
                    break;
                }
            break;

            case 1: //Level 2
                levelColor("2");
                if(c == KEY_ENTER) { //Goes to pvcLevelStart()
                    PVC_LevelIndex = 2;
                    pvcLevelStart();
                    break;
                }
            break;

            case 2: //Level 3
                levelColor("3");
                if(c == KEY_ENTER) { //Goes to pvcLevelStart()
                    PVC_LevelIndex = 3;
                    pvcLevelStart();
                    break;
                }
            break;

            case 3: //Level 4
                levelColor("4");
                if(c == KEY_ENTER) { //Goes to pvcLevelStart()
                    PVC_LevelIndex = 4;
                    pvcLevelStart();
                    break;
                }
            break;

            case 4: //Level 5
                levelColor("5");
                if(c == KEY_ENTER) { //Goes to pvcLevelStart()
                    PVC_LevelIndex = 5;
                    pvcLevelStart();
                    break;
                }
            break;

            case 5: //Level 6
                levelColor("6");
                if(c == KEY_ENTER) { //Goes to pvcLevelStart()
                    PVC_LevelIndex = 6;
                    pvcLevelStart();
                    break;
                }
            break;

            case 6: //Level 7
                levelColor("7");
                if(c == KEY_ENTER) { //Goes to pvcLevelStart()
                    PVC_LevelIndex = 7;
                    pvcLevelStart();
                    break;
                }
            break;

            case 7: //Level 8
                levelColor("8");
                if(c == KEY_ENTER) { //Goes to pvcLevelStart()
                    PVC_LevelIndex = 8;
                    pvcLevelStart();
                    break;
                }
            break;

            case 8: //Level 9
                levelColor("9");
                if(c == KEY_ENTER) { //Goes to pvcLevelStart()
                    PVC_LevelIndex = 9;
                    pvcLevelStart();
                    break;
                }
            break;

            case 9: //Return
                setpos(0,3);
                setcolor( 0x07 );
                std::cout << "#     1   2   3   4   5     #";

                setpos(0,5);
                setcolor( 0x07 );
                std::cout << "#      6    7   8    9      #";

                setpos(0,7);
                std::cout << '\r' << "#=================== ";
                setcolor( 0x03 );
                std::cout << "Return";
                setcolor( 0x07 );
                std::cout << " #";

                if(c == KEY_ENTER) { //Goes to pvcomputer()
                    pvcomputer();
                    break;
                }
            break;
        }
    }
}
void pvcScore() {                                     //PvC score screen                (Status: COMPLETE)          (Optimized: TRUE)
    int position = 0;
    int c;

    setpos(0,0);
    std::cout << "#======# TIC TAC TOE #======#";
    setpos(0,1);
    std::cout << "#___________Score___________#";
    setpos(0,2);
    std::cout << "#   Player   | |  Computer  #";
    setpos(0,3);
    std::cout << "#            | |            #";
    setpos(0,4);
    std::cout << "#  Wins:  " << PVC_PWins << "  | |  Wins:  " << PVC_CWins << "  #";
    setpos(0,5);
    std::cout << "#  Loses: " << PVC_PLoss << "  | |  Loses: " << PVC_CLoss << "  #";
    setpos(0,6);
    std::cout << "#            | |            #";
    setpos(0,7);
    std::cout << "#=================== Return #";

    if(1) { //Starting position: Return
        setpos(0,7);
        std::cout << '\r' << "#=================== ";
        setcolor( 0x03 );
        std::cout << "Return";
        setcolor( 0x07 );
        std::cout << " #";
        position = 0;
    }
    while(1) { //Positioning
        c = getch();
        if(c == KEY_ENTER) { //Goes to pvcomputer()
            pvcomputer();
            break;
        }
    }
}
void pvpScore() {                                     //PvP score screen                (Status: COMPLETE)          (Optimized: TRUE)
    int position = 0;
    int c;

    setpos(0,0);
    std::cout << "#======# TIC TAC TOE #======#";
    setpos(0,1);
    std::cout << "#___________Score___________#";
    setpos(0,2);
    std::cout << "#  Player 1  | |  Player 2  #";
    setpos(0,3);
    std::cout << "#            | |            #";
    setpos(0,4);
    std::cout << "#  Wins:  " << PVP_1Wins << "  | |  Wins:  " << PVP_2Wins << "  #";
    setpos(0,5);
    std::cout << "#  Loses: " << PVP_1Loss << "  | |  Loses: " << PVP_2Loss << "  #";
    setpos(0,6);
    std::cout << "#            | |            #";
    setpos(0,7);
    std::cout << "#=================== Return #";

    if(1) { //Starting position: Return
        setpos(0,7);
        std::cout << '\r' << "#=================== ";
        setcolor( 0x03 );
        std::cout << "Return";
        setcolor( 0x07 );
        std::cout << " #";
        position = 0;
    }
    while(1) { //Positioning
        c = getch();
        if(c == KEY_ENTER) { //Goes to pvplayer()
            pvplayer();
            break;
        }
    }
}
void pvcomputer() {                                   //PvC screen                      (Status: COMPLETE)          (Optimized: TRUE)
    int position = 0;
    int c;

    setpos(0,0);
    std::cout << "#======# TIC TAC TOE #======#";
    setpos(0,1);
    std::cout << "#__________Options__________#";
    setpos(0,2);
    std::cout << "#                         --#";
    setpos(0,3);
    std::cout << "#   Levels               |  #";
    setpos(0,4);
    std::cout << "#                        |  #";
    setpos(0,5);
    std::cout << "#   Score                |  #";
    setpos(0,6);
    std::cout << "#                         --#";
    setpos(0,7);
    std::cout << "#=================== Return #";

    if(1) { //Starting position: Levels
        pvcScoreLevel(0x07, 0x03, 0x07);
        position = 2;
    }
    while(1) { //Positioning
        c = getch();
        if(c == KEY_UP) { //Position up
            position++;
        }
        if(c == KEY_DOWN) { //Position down
            position--;
        }

        if(position > 2) { //Position equalizer
            position = 0;
        }
        if(position < 0) { //Position equalizer
            position = 2;
        }

        if(position == 2) { //Position: Levels
            pvcScoreLevel(0x07, 0x03, 0x07);
            if(c == KEY_ENTER) { //Goes to pvcLevels()
                pvcLevels();
                break;
            }
        }
        if(position == 1) { //Position: Score
            pvcScoreLevel(0x03, 0x07, 0x07);
            if(c == KEY_ENTER) { //Goes to pvcScore()
                pvcScore();
                break;
            }
        }
        if(position == 0) { //Position: Return
            pvcScoreLevel(0x07, 0x07, 0x03);
            if(c == KEY_ENTER) { //Goes to gamemodes()
                gamemodes();
                break;
            }
        }
    }
}
void pvplayer() {                                     //PvP screen                      (Status: COMPLETE)          (Optimized: TRUE)
    system("MODE 29,8");
    setcolor( 0x07 );
    int position = 0;
    int c;

    setpos(0,0);
    std::cout << "#======# TIC TAC TOE #======#";
    setpos(0,1);
    std::cout << "#__________Options__________#";
    setpos(0,2);
    std::cout << "#                         --#";
    setpos(0,3);
    std::cout << "#   Play                 |  #";
    setpos(0,4);
    std::cout << "#                        |  #";
    setpos(0,5);
    std::cout << "#   Score                |  #";
    setpos(0,6);
    std::cout << "#                         --#";
    setpos(0,7);
    std::cout << "#=================== Return #";

    if(1) { //Starting position: Play
        pvpScorePlay(0x07, 0x03, 0x07);
        position = 2;
    }
    while(1) { //Positioning
        c = getch();
        if(c == KEY_UP) { //Position up
            position++;
        }
        if(c == KEY_DOWN) { //Position down
            position--;
        }

        if(position > 2) { //Position equalizer
            position = 0;
        }
        if(position < 0) { //Position equalizer
            position = 2;
        }

        if(position == 2) { //Position: Play
            pvpScorePlay(0x07, 0x03, 0x07);
            if(c == KEY_ENTER) { //Goes to pvpChar()
                pvpChar();
                break;
            }
        }
        if(position == 1) { //Position: Score
            pvpScorePlay(0x03, 0x07, 0x07);
            if(c == KEY_ENTER) { //Goes to pvpScore()
                pvpScore();
                break;
            }
        }
        if(position == 0) { //Position: Return
            pvpScorePlay(0x07, 0x07, 0x03);
            if(c == KEY_ENTER) { //Goes to gamemodes()
                gamemodes();
                break;
            }
        }
    }
}
void gamemodes() {                                    //Gamemode screen                 (Status: COMPLETE)          (Optimized: TRUE)
    int c;
    int position = 0;

    setpos(0,0);
    std::cout << "#======# TIC TAC TOE #======#";
    setpos(0,1);
    std::cout << "#_________Gamemodes_________#";
    setpos(0,2);
    std::cout << "#                         --#";
    setpos(0,3);
    std::cout << "#  Player vs Computer    |  #";
    setpos(0,4);
    std::cout << "#                        |  #";
    setpos(0,5);
    std::cout << "#  Player vs Player      |  #";
    setpos(0,6);
    std::cout << "#                         --#";
    setpos(0,7);
    std::cout << "#=================== Return #";

    if(1) { //Starting position: PvC
        pvcPvpColor(0x03, 0x07, 0x07);
        position = 2;
    }
    while(1) { //Positioning
        c = getch();
        if(c == KEY_UP) { //Position up
            position++;
        }
        if(c == KEY_DOWN) { //Position down
            position--;
        }

        if(position > 2) { //Position equalizer
            position = 0;
        }
        if(position < 0) { //Position equalizer
            position = 2;
        }

        if(position == 2) { //Position: PvC
            pvcPvpColor(0x03, 0x07, 0x07);
            if(c == KEY_ENTER) { //Goes to pvcomputer()
                pvcomputer();
                break;
            }
        }
        if(position == 1) { //Position: PvP
            pvcPvpColor(0x07, 0x03, 0x07);
            if(c == KEY_ENTER) { //Goes to pvplayer()
                pvplayer();
                break;
            }
        }
        if(position == 0) { //Position: Return
            pvcPvpColor(0x07, 0x07, 0x03);
            if(c == KEY_ENTER) { //Goes to mainAfter()
                mainAfter();
                break;
            }
        }
    }
}
void guide1() {                                       //Guide page 1 screen             (Status: COMPLETE)          (Optimized: TRUE)
    int c;
    int position;

    setpos(0,0);
    std::cout << "#======# TIC TAC TOE #======#";
    setpos(0,1);
    std::cout << "#_________Selection_________#";
    setpos(0,2);
    std::cout << "#| Select = Enter        >> #";
    setpos(0,3);
    std::cout << "#| Up = Up Arrow            #";
    setpos(0,4);
    std::cout << "#| Down = Down Arrow        #";
    setpos(0,5);
    std::cout << "#| Left = Left Arrow        #";
    setpos(0,6);
    std::cout << "#| Right = Right Arrow      #";
    setpos(0,7);
    std::cout << "#=================== Return #";

    if(1) { //Starting position: >>
        guide1Color(0x03,0x07);
        position = 1;
    }
    while(1) { //Positioning
        c = getch();
        if(c == KEY_UP) { //Position up
            position++;
        }
        if(c == KEY_DOWN) { //Position down
            position--;
        }

        if(position > 1) { //Position equalizer
            position = 0;
        }
        if(position < 0) { //Position equalizer
            position = 1;
        }

        if(position == 1) { //Position: >>
            guide1Color(0x03,0x07);
            if(c == KEY_ENTER) { //Goes to guide2
                guide2();
                break;
            }
        }
        if(position == 0) { //Position: Return
            guide1Color(0x07,0x03);
            if(c == KEY_ENTER) { //Goes to mainAfter
                mainAfter();
                break;
            }
        }
    }
}
void guide2() {                                       //Guide page 2 screen             (Status: COMPLETE)          (Optimized: TRUE)
    int c;
    int position;

    setpos(0,0);
    std::cout << "#======# TIC TAC TOE #======#";
    setpos(0,1);
    std::cout << "#_______Game Controls_______#";
    setpos(0,2);
    std::cout << "#| <<                       #";
    setpos(0,3);
    std::cout << "#|   __A1__|__A2__|__A3__   #";
    setpos(0,4);
    std::cout << "#|   __B1__|__B2__|__B3__   #";
    setpos(0,5);
    std::cout << "#|     C1  |  C2  |  C3     #";
    setpos(0,6);
    std::cout << "#|                          #";
    setpos(0,7);
    std::cout << "#===========================#";

    if(1) { //Starting position: <<
        setpos(0,2);
        std::cout << '\r' << "#| ";
        setcolor( 0x03 );
        std::cout << "<<";
        setcolor( 0x07 );
        std::cout << "                       #";
        position = 1;
    }
    while(1) { //Positioning
        c = getch();
        if(c == KEY_ENTER) {
            guide1();
            break;
        }
    }
}
void mainAfter() {                                    //Title screen                    (Status: COMPLETE)          (Optimized: TRUE)
    setcolor( 0x07 );
    int position = 0;
    int c;

    setpos(0,0);
    std::cout << "#======# TIC TAC TOE #======#";
    setpos(0,1);
    std::cout << "#                           #";
    setpos(0,2);
    std::cout << "#                           #";
    setpos(0,3);
    std::cout << "#           START           #";
    setpos(0,4);
    std::cout << "#                           #";
    setpos(0,5);
    std::cout << "#          _______          #";
    setpos(0,6);
    std::cout << "#         | GUIDE |         #";
    setpos(0,7);
    std::cout << "#===========================#";

    if(1) { //Starting position: START
        mainColor(0x03,0x07);
        position = 1;
    }
    while(1) { //Positioning
        c = getch();
        if(c == KEY_UP) { //Position up
            position++;
        }
        if(c == KEY_DOWN) { //Position down
            position--;
        }

        if(position > 1) { //Position equalizer
            position = 0;
        }
        if(position < 0) { //Position equalizer
            position = 1;
        }

        if(position == 1) { //Position START
            mainColor(0x03,0x07);
            if(c == KEY_ENTER) {
                gamemodes();
                break;
            }
        }
        if(position == 0) { //Position GUIDE
            mainColor(0x07,0x03);
            if(c == KEY_ENTER) {
                guide1();
                break;
            }
        }
    }
}
int main() {                                          //Title screen                    (Status: COMPLETE)          (Optimized: TRUE)
    HWND consoleWindow = GetConsoleWindow();
    SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
    system("MODE 29,8");
    srand(time(NULL));
    int position = 0;
    setcolor( 0x07 );
    setcursor(0,0);
    int xIncr = 22;
    int xDecr = 6;
    int c;

    if(1) { //Displays the title screen
        std::cout << "         ";
        Sleep(100);
        std::string title = "TIC TAC TOE";
        for(int i = 0; i < 11; i++) {
            std::cout << title.at(i);
            Sleep(100);
        }
        setpos(7,0);
        std::cout << "#";
        setpos(21,0);
        std::cout << "#";

        for(; xIncr <= 28 && xDecr >= 0; xIncr++, xDecr--) { //Draws lines next to title
            setpos(xIncr,0);
            std::cout << "=";

            setpos(xDecr,0);
            std::cout << "=";

            if(xDecr == 0) { //Draws the end (LEFT)
                setpos(0,0);
                std::cout << "#";
            }
            if(xIncr == 28) { //Draws the end (RIGHT)
                setpos(28,0);
                std::cout << "#";
            }
            Sleep(50);
        }
        for(int i = 1; i < 8; i++) { //Draws end collumns
            setpos(0,i);
            std::cout << "#";
            setpos(28,i);
            std::cout << "#";
            Sleep(50);
        }
        for(int k = 1; k < 28; k++) { //Draws the bottom lines
            setpos(k,7);
            std::cout << "=";
            Sleep(50);
        }

        Sleep(50);
        setpos(0,1);
        std::cout << '\r' << "#           START           #";
        setpos(0,6);
        std::cout << '\r' << "#          _______          #";
        Sleep(350);
        setpos(0,1);
        std::cout << '\r' << "#                           #";
        setpos(0,2);
        std::cout << '\r' << "#           START           #";
        setpos(0,5);
        std::cout << '\r' << "#          _______          #";
        setpos(0,6);
        std::cout << '\r' << "#         | GUIDE |         #";
        Sleep(350);
        setpos(0,2);
        std::cout << '\r' << "#                           #";
        setpos(0,3);
        std::cout << '\r' << "#           START           #";
    }
    
    Sleep(200);

    if(1) { //Starting position: START
        mainColor(0x03,0x07);
        position = 1;
    }
    while(1) { //Positioning
        c = getch();
        if(c == KEY_UP) { //Position up
            position++;
        }
        if(c == KEY_DOWN) { //Position down
            position--;
        }

        if(position > 1) { //Position equalizer
            position = 0;
        }
        if(position < 0) { //Position equalizer
            position = 1;
        }

        if(position == 1) { //Position START
            mainColor(0x03, 0x07);
            if(c == KEY_ENTER) {
                gamemodes();
                break;
            }
        }
        if(position == 0) { //Position GUIDE
            mainColor(0x07, 0x03);
            if(c == KEY_ENTER) {
                guide1();
                break;
            }
        }
    }
    return 0;
}

/* UI
Start menu
#======# TIC TAC TOE #======#
#                           #
#                           #
#           START           #
#                           #
#          _______          #
#         | GUIDE |         #
#===========================#


Guide
#======# TIC TAC TOE #======#
#_________Selection_________#
#| Select = Enter        >> #
#| Up = Up Arrow            #
#| Down = Down Arrow        #
#| Left = Left Arrow        #
#| Right = Right Arrow      #
#=================== Return #

#======# TIC TAC TOE #======#
#_______Game Controls_______#
#| <<                       #
#|   __A1__|__A2__|__A3__   #
#|   __B1__|__B2__|__B3__   #
#|     C1  |  C2  |  C3     #
#|                          #
#===========================#


Gamemodes
#======# TIC TAC TOE #======#
#_________Gamemodes_________#
#                         --#
#  Player vs Computer    |  #
#                        |  #
#  Player vs Player      |  #
#                         --#
#=================== Return #


PvC score or levels
#======# TIC TAC TOE #======#
#__________Options__________#
#                         --#
#   Levels               |  #
#                        |  #
#   Score                |  #
#                         --#
#=================== Return #


PvP score or play
#======# TIC TAC TOE #======#
#__________Options__________#
#                         --#
#   Play                 |  #
#                        |  #
#   Score                |  #
#                         --#
#=================== Return #


Computer score
#======# TIC TAC TOE #======#
#___________Score___________#
#   Player   | |  Computer  #
#            | |            #
#  Wins:     | |  Wins:     #
#  Loses:    | |  Loses:    #
#            | |            #
#=================== Return #


Player score
#======# TIC TAC TOE #======#
#___________Score___________#
#  Player 1  | |  Player 2  #
#            | |            #
#  Wins:     | |  Wins:     #
#  Loses:    | |  Loses:    #
#            | |            #
#=================== Return #


Computer levels
#======# TIC TAC TOE #======#
#______Computer Levels______#
#                           #
#     1   2   3   4   5     #
#                           #
#      6    7   8    9      #
#                           #
#=================== Return #

Computer level stars
#======# TIC TAC TOE #======#
#__________Level 1__________#
#         _   _   _         #
#- - - - |_| |_| |_| - - - -#
#                           #
#           Start           #
#                           #
#=================== Return #

PvP character
#======# TIC TAC TOE #======#
#_________Character_________#
#  Player 1   |  Player 2   #
#             |             #
#    [   ]    |    [   ]    #
#    *****    |    *****    #
#             |             #
#===========================#

Computer level character
#======# TIC TAC TOE #======#
#_________Character_________#
#               /           #
#              /            #
#           X / O           #
#            /              #
#           /               #
#===========================#

Level game
#==========================# TIC TAC TOE #==========================#
| Level 1       _   _   _  |              |        |       |        #
|--------------|_| |_| |_|-|             G|        |       |        #
#==========================#              | _______|_______|_______ #
#__________Choose__________#             A|        |       |        #
#                          #              |        |       |        #
#   __A1__|__A2__|__A3__   #             M| _______|_______|_______ #
#   __B1__|__B2__|__B3__   #              |        |       |        #
#     C1  |  C2  |  C3     #             E|        |       |        #
#                          #              |        |       |        #
#=============== Return(R) #---{     }---#==========================#

PvP game
#==========================# TIC TAC TOE #==========================#
|  Player X  vs  Player O  |              |        |       |        #
|  X turn                  |             G|        |       |        #
#==========================#              | _______|_______|_______ #
#__________Choose__________#             A|        |       |        #
#                          #              |        |       |        #
#   __A1__|__A2__|__A3__   #             M| _______|_______|_______ #
#   __B1__|__B2__|__B3__   #              |        |       |        #
#     C1  |  C2  |  C3     #             E|        |       |        #
#                          #              |        |       |        #
#=============== Return(R) #---{     }---#==========================#
*/