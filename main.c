#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>

int a = 3;   //assigning global variables
int bomblocation_resetter = 0;
int correcthit = 0;
int incorrecthit = 0;
int wordindex = 0;
int wordnumber_counter = 0;
int wordnumber;
int c;
char yesorno_button;
int letternumber_counter = 0;
int newscore = 0;
int plane_totalposition = 0;
int bomb_totalposition = 0;
int bomb_topposition = 4;
int bomb_midposition = 5;
int bomb_botposition = 6;
char bombcrash_selection;
double sleeptime = 200;
char* codewords();
int mainmenu_selection;
int pausemenu_selection;
char* word;

void mainmenu1() //drawing menu
{
    COORD mainmenu1_draw;
    mainmenu1_draw.X = 25;
    mainmenu1_draw.Y = 10;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), mainmenu1_draw);
    printf("1.  New Game");
}

void mainmenu2()
{
    COORD mainmenu2_draw;
    mainmenu2_draw.X = 25;
    mainmenu2_draw.Y = 11;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), mainmenu2_draw);
    printf("2.  Exit");
}

void mainmenu3()
{
    COORD mainmenu3_draw;
    mainmenu3_draw.X = 25;
    mainmenu3_draw.Y = 12;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), mainmenu3_draw);
    printf("Please Select an Action (1,2,3) and Press Enter ->  ");
    scanf_s("%d", &mainmenu_selection);
}

void pausemenu1() //drawing pause menu
{
    COORD pausemenu1_draw;
    pausemenu1_draw.X = 25;
    pausemenu1_draw.Y = 11;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pausemenu1_draw);
    printf("1.  New Game");
}


void pausemenu2()
{
    COORD pausemenu2_draw;
    pausemenu2_draw.X = 25;
    pausemenu2_draw.Y = 12;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pausemenu2_draw);
    printf("2.  Return to Game");
}

void pausemenu3()
{
    COORD pausemenu3_draw;
    pausemenu3_draw.X = 25;
    pausemenu3_draw.Y = 13;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pausemenu3_draw);
    printf("3.  Exit Game");
}

void pausemenu4()
{
    COORD pausemenu4_draw;
    pausemenu4_draw.X = 25;
    pausemenu4_draw.Y = 14;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pausemenu4_draw);
    printf("Please Select Your Action (1,2,3) and Press Enter ->  ");
    scanf_s("%d", &pausemenu_selection);
}

void scoreposition() //drawing scoreboard
{
    COORD scoredraw;
    scoredraw.X = 75;
    scoredraw.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), scoredraw);
    printf("score = %d\n", newscore);
}

void citystructure() //drawing city
{
    COORD citydraw;
    citydraw.X = 0;
    citydraw.Y = 20;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), citydraw);
    printf(" _____        _____    _________________ ________    _________\n|o o o|_______|    |__|               | | # # # |____|o o o o|\n|o o o|* * *|: ::|. . |               |o| # # # |. . |o o o o|\n|o o o|* * *|::  |. . | []  []  []  []|o| # # # |. . |o o o o|\n|o o o|**** |:  :| . .| []  []  []    |o| # # # |. . |o o o o|\n|_[]__|__[]_|_||_|__< |____________;;_|_|___[]__|_.|_|__[]___|\n");
}

void planestopposition() //drawing plane
{
    COORD planetopdraw;
    planetopdraw.X = plane_totalposition;
    planetopdraw.Y = 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), planetopdraw);
    printf("(|__.-. | \n");
}

void planesmidposition()
{
    COORD planemiddraw;
    planemiddraw.X = plane_totalposition;
    planemiddraw.Y = 2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), planemiddraw);
    printf("== ===_]+ \n");
}

void planesbotposition()
{
    COORD planebotdraw;
    planebotdraw.X = plane_totalposition;
    planebotdraw.Y = 3;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), planebotdraw);
    printf("        | \n");
}

void bombstopposition() //drawing bomb
{
    COORD bombtopdraw;
    bombtopdraw.X = bomb_totalposition;
    bombtopdraw.Y = bomb_topposition;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), bombtopdraw);
    printf("<|>\n");
}

void bombsmidposition()
{
    COORD bombmiddraw;
    bombmiddraw.X = bomb_totalposition;
    bombmiddraw.Y = bomb_midposition;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), bombmiddraw);
    printf(" |%s\n", word + wordindex);
}

void bombsbotposition()
{
    COORD bombbotdraw;
    bombbotdraw.X = bomb_totalposition;
    bombbotdraw.Y = bomb_botposition;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), bombbotdraw);
    printf(" *\n");
}

void bombcrash_screen() //drawing gameover screen
{
    COORD bombcrash_screen_draw;
    bombcrash_screen_draw.X = 20;
    bombcrash_screen_draw.Y = 11;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), bombcrash_screen_draw);
    printf("You've lost the game. Do you want to play again? Please press Y or N.");
}

char* codewords() //entering words in codewords for the game in a char pointer
{
    char* words[39] = { "ape",
                        "car",
                        "big",
                        "123",
                        "book",
                        "door",
                        "epic",
                        "band",
                        "test",
                        "apple",
                        "catch",
                        "super",
                        "level",
                        "small",
                        "basket",
                        "abroad",
                        "action",
                        "carbon",
                        "program",
                        "buzzcut",
                        "jimjams",
                        "muzzles",
                        "puzzles",
                        "dazzled",
                        "football",
                        "baseball",
                        "absolute",
                        "campaign",
                        "casualty",
                        "division",
                        "quizzical",
                        "twizzling",
                        "bedazzled",
                        "fuzziness",
                        "maximizer",
                        "strawberry",
                        "friendship",
                        "motivation",
                        "everything",
    };
    if (wordnumber == 3) { //creating randomness for words to show properly
        return words[rand() % 4];
    }
    if (wordnumber == 4) {
        return words[(rand() % 5) + 4];
    }
    if (wordnumber == 5) {
        return words[(rand() % 5) + 9];
    }
    if (wordnumber == 6) {
        return words[(rand() % 4) + 14];
    }
    if (wordnumber == 7) {
        return words[(rand() % 6) + 18];
    }
    if (wordnumber == 8) {
        return words[(rand() % 6) + 24];
    }
    if (wordnumber == 9) {
        return words[(rand() % 5) + 30];
    }
    if (wordnumber == 10) {
        return words[(rand() % 4) + 35];
    }
}

int main()
{
    srand(time(NULL));//random variable function
    //newgamevariables();
    mainmenu1();//calling functions
    //mainmenu2();
    mainmenu2();
    mainmenu3();
    wordnumber = 3;
    word = codewords();
    switch (mainmenu_selection)//first selection
    {
    case 1:;
        for (plane_totalposition = 0; plane_totalposition < 65; plane_totalposition++) {
            if ((plane_totalposition + 1) % 64 == 0) {
                plane_totalposition = 0;
            }//planes movement
            system("cls");
            scoreposition();
            planestopposition();
            planesmidposition();
            planesbotposition();
            bombstopposition();
            bombsmidposition();
            bombsbotposition();
            citystructure();
            if ((plane_totalposition + 1) % 15 != 0) { //bombs movement accordingto plane
                bomb_topposition = bomb_topposition + 1;
                bomb_midposition = bomb_midposition + 1;
                bomb_botposition = bomb_botposition + 1;
                if (bomb_botposition > 20) {//bomb fall situation
                    system("cls");
                    plane_totalposition = 0;
                    bomb_topposition = 18;
                    bomb_midposition = 19;
                    bomb_botposition = 20;
                    bombcrash_screen();
                    enum BombCrash_Screen { yes = 'y', no = 'n' };
                    while (1) {
                        if (_kbhit()) {//getting users answer
                            char keyboardhit = _getch();
                            system("cls");
                            a = 3;
                            newscore = 0;
                            plane_totalposition = 0;
                            bomb_totalposition = 0;
                            bomb_topposition = 4;
                            bomb_midposition = 5;
                            bomb_botposition = 6;
                            bomblocation_resetter = 0;
                            correcthit = 0;
                            incorrecthit = 0;
                            wordindex = 0;
                            wordnumber_counter = 0;
                            letternumber_counter = 0;
                            switch (keyboardhit)
                            {
                            case 'y':;
                                sleeptime = 200;
                                break;

                            case 'n':;
                                sleeptime = 300;

                                return main();
                            }
                            break;
                        }

                    }
                }
            }
            if (bomblocation_resetter >= a) {//corret typed word situation
                wordnumber_counter++;
                if ((wordnumber_counter + 1) % 5 == 1) {
                    wordnumber++;
                    sleeptime = (sleeptime * 19) / 20;
                    a = a + 1;
                    if (wordnumber % 10 == 1) {
                        wordnumber = 10;
                    }
                }
                bomblocation_resetter = 0;
                word = codewords();
                wordindex = 0;
                newscore += (correcthit - incorrecthit);
                correcthit = 0;
                incorrecthit = 0;
                bomb_totalposition = plane_totalposition + 1;
                bomb_topposition = 4;
                bomb_midposition = 5;
                bomb_botposition = 6;
            }
            if (_kbhit()) {//typing words on screen
                char keyboardhit = _getch();
                if (keyboardhit == word[wordindex]) {
                    wordindex++;
                    correcthit++;
                    bomblocation_resetter++;
                }
                else {
                    incorrecthit++;
                    sleeptime = (sleeptime * 9) / 10;
                }

                switch (keyboardhit)//pressin esc
                {
                case 27:;
                    system("cls");
                    pausemenu1();
                    pausemenu2();
                    pausemenu3();
                    pausemenu4();
                    switch (pausemenu_selection)
                    {
                    case 1:;//new game
                        system("cls");
                        a = 3;
                        newscore = 0;
                        plane_totalposition = 0;
                        bomb_totalposition = 0;
                        bomb_topposition = 4;
                        bomb_midposition = 5;
                        bomb_botposition = 6;
                        sleeptime = 200;
                        bomblocation_resetter = 0;
                        correcthit = 0;
                        incorrecthit = 0;
                        wordindex = 0;
                        wordnumber_counter = 0;
                        letternumber_counter = 0;
                        return main();

                    case 2:;//return to game
                        break;

                    case 3:;//exit
                        COORD pausemenu_selectionexit_selection;
                        pausemenu_selectionexit_selection.X = 25;
                        pausemenu_selectionexit_selection.Y = 15;
                        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pausemenu_selectionexit_selection);
                        printf("Game has been exited as you chose.\n\n\n\n");
                        return 0;
                    }
                }
            }

            Sleep(sleeptime);//using sleep and system("cls") for movement effect
            system("cls");
        }

    case 2:;//menuexit selection
        COORD exit_selection;
        exit_selection.X = 25;
        exit_selection.Y = 13;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), exit_selection);
        printf("Game has been exited as you chose.\n\n\n\n");
        return;
        //break;

    default:;//menu misclick
        COORD unknown_selection;
        unknown_selection.X = 25;
        unknown_selection.Y = 13;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), unknown_selection);
        printf("Unknown selection. Please re-enter the game and select again.\n\n\n\n");
        system("cls");
        return main();

    }

    return 0;
}
