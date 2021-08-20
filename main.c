#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    FILE *f, *f1;
reset_score:
    f = fopen("scoreA.csv", "a");
    f1 = fopen("scoreN.csv", "a");
    int size = 0;
    if (f != NULL)
    {
        fseek(f, 0, SEEK_END);
        size = ftell(f);
        if (size == 0)
            fprintf(f, "Name\t|\tAttempts\n");
    }
    if (f1 != NULL)
    {
        fseek(f1, 0, SEEK_END);
        size = ftell(f1);
        if (size == 0)
            fprintf(f1, "Name\t|\tAttempts\n");
    }
    fclose(f);
    fclose(f1);
mainscreen:
    system("cls");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\tGUESSING GAME\n");
    printf("\t\t\t\t\t==================================================================================================================================================");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t> Press S to start a NEW game\n\n\t\t\t\t\t\t\t\t\t\t\t\t> Press V to view SCORECARD\n\n\t\t\t\t\t\t\t\t\t\t\t\t> Press Q to QUIT\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
    char choice = toupper(getch());
    if (choice == 'Q')
    {
        system("cls");
        printf("\t\t\t\t\t\t\t\t\t\t\tThank You for trying this game. Hope to see you back soon.\n");
        exit(1);
    }
    else if (choice == 'V')
    {
    view_score:
        system("cls");
        int boardchoice = 0;
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t[1] - Number Scoreboard\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t[2] - Alphabet Scoreboard\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
        scanf("%d", &boardchoice);
        if (boardchoice == 1)
        {
            system("cls");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t\tNUMBER SCOREBOARD\t\t\t\t\t\t[R] - Reset\n");
            printf("\t\t\t\t\t>>--------------------------------------------------------------------------------------------------------------------------------------------<<\n\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t\tNAME\t\tATTEMPTS\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t----\t\t--------\n\n");
            FILE *file;
            file = fopen("scoreN.csv", "r");
            char buffer[500];
            int row = 0;
            int column = 0;
            while (fgets(buffer, 500, file))
            {
                column = 0;
                row++;
                if (row == 1)
                    continue;
                char *value = strtok(buffer, ", ");
                while (value)
                {
                    // Column 1
                    if (column == 0)
                    {
                        printf("\t\t\t\t\t\t\t\t\t\t\t\t");
                    }
                    // Column 2
                    if (column == 1)
                    {
                        printf("\t\t   ");
                    }
                    printf("%s", value);
                    value = strtok(NULL, ", ");
                    column++;
                }
                printf("\n");
            }
            fclose(file);
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t[Q]Exit Game\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t[M]Return to Main Menu\n\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
            char Vchoice = toupper(getch());
            if (Vchoice == 'Q')
            {
                system("cls");
                printf("\t\t\t\t\t\t\t\t\t\t\tThank You for trying this game. Hope to see you back soon.\n\n");
                exit(1);
            }
            else if (Vchoice == 'M')
            {
                goto mainscreen;
            }
            else if (Vchoice == 'R')
            {
                printf("\n\t\t\t\t\t\t\t\t\t\t\tAre you sure to reset the scoreboard?(Y/N)");
                char exitchoice = getch();
                if (toupper(exitchoice) == 'Y')
                {
                    remove("scoreN.csv");
                    goto reset_score;
                }
                else
                    goto view_score;
            }
            else
                printf("\n\n\t\t\t\t\t\t\t\t\t\t\tPlease enter a valid choice. Exiting the game.");
        }
        else if (boardchoice == 2)
        {
            system("cls");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t\tALPHALBET SCOREBOARD\t\t\t\t\t\t[R] - Reset\n");
            printf("\t\t\t\t\t>>--------------------------------------------------------------------------------------------------------------------------------------------<<\n\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t\tNAME\t\tATTEMPTS\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t----\t\t--------\n\n");
            FILE *file1;
            file1 = fopen("scoreA.csv", "r");
            char buffer1[500];
            int row = 0;
            int column = 0;
            while (fgets(buffer1, 500, file1))
            {
                column = 0;
                row++;
                if (row == 1)
                    continue;
                char *value1 = strtok(buffer1, ", ");
                while (value1)
                {
                    // Column 1
                    if (column == 0)
                    {
                        printf("\t\t\t\t\t\t\t\t\t\t\t\t");
                    }
                    // Column 2
                    if (column == 1)
                    {
                        printf("\t\t   ");
                    }
                    printf("%s", value1);
                    value1 = strtok(NULL, ", ");
                    column++;
                }
                printf("\n");
            }
            fclose(file1);
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t[Q]Exit Game\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t[M]Return to Main Menu\n\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
            char Vchoice = toupper(getch());
            if (Vchoice == 'Q')
            {
                system("cls");
                printf("\t\t\t\t\t\t\t\t\t\t\tThank You for trying this game. Hope to see you back soon.\n\n");
                exit(1);
            }
            else if (Vchoice == 'M')
                goto mainscreen;
            else if (Vchoice == 'R')
            {
                printf("\n\t\t\t\t\t\t\t\t\t\t\tAre you sure to reset the scoreboard?(Y/N)");
                char exitchoice1 = getch();
                if (toupper(exitchoice1) == 'Y')
                {
                    remove("scoreA.csv");
                    goto reset_score;
                }
                else
                    goto view_score;
            }
            else
                printf("\n\n\t\t\t\t\t\t\t\t\t\t\tPlease enter a valid choice. Exiting the game.");
        }
        else
        {
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\tPlease enter a valid choice. Exiting the game.");
        }
    }
    else if (choice == 'S')
    {
        system("cls");
        printf("\t\t\t\t\t\t\t\t\t\t\t\tDo you want to play with:\t\t\t\t\t\t\t\t\t[3]Exit\n\n \t\t\t\t\t\t\t\t\t\t\t\t\t1) Numbers\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t2) Alphabets\n\n\t\t\t\t\t\t\t\t\t\t\t\tPlease enter your choice: ");
        int gamechoice = 0;
        scanf("%d", &gamechoice);
        switch (gamechoice)
        {
        case 1:
            system("cls");
            char name[20];
            printf("\t\t\t\t\t\t\t\t\t\t\t\tEnter your username: ");
            scanf("%s", &name);
            FILE *file;
            file = fopen("scoreN.csv", "a");
            fprintf(file, "%s\t\t", name);
            system("cls");
            printf("\t\t\t\t\t\t\t\t\t\t\t\tWhich difficulty level would you like?\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t[1]-Easy\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t[2]-Medium\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t[3]-Hard\n");
            int difficulty = 0;
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t");
            scanf("%d", &difficulty);
            switch (difficulty)
            {
            case 1:
                system("cls");
                srand(time(0));
                int target = (rand() % 20) + 1;
                int guess = 0, nGuess = 0;
                printf("\t\t\t\t\t\t\t\t\t\t\t\tChoose a number between 1 and 20: ");
                while (guess != target)
                {
                    scanf("%d", &guess);
                    nGuess++;
                    if (guess == target)
                    {
                        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\tYou are correct. You made it in %d guesses.", nGuess);
                        fprintf(file, "%d\n", nGuess);
                        break;
                    }
                    else if (guess > target)
                    {
                        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\tGuess a lower number: ");
                    }
                    else
                    {
                        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\tGuess a higher number: ");
                    }
                }
                break;
            case 2:
                system("cls");
                srand(time(0));
                target = (rand() % 50) + 1;
                nGuess = 0;
                guess = 0;
                printf("\t\t\t\t\t\t\t\t\t\t\t\tChoose a number between 1 and 50: ");
                while (guess != target)
                {
                    scanf("%d", &guess);
                    nGuess++;
                    if (guess == target)
                    {
                        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\tYou are correct. You made it in %d guesses.", nGuess);
                        fprintf(file, "%d\n", nGuess);
                        break;
                    }
                    else if (guess > target)
                    {
                        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\tGuess a lower number: ");
                    }
                    else
                    {
                        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\tGuess a higher number: ");
                    }
                }
                break;

            case 3:
                system("cls");
                srand(time(0));
                target = (rand() % 100) + 1;
                nGuess = 0;
                guess = 0;
                printf("\t\t\t\t\t\t\t\t\t\t\t\tChoose a number between 1 and 100: ");
                while (guess != target)
                {
                    scanf("%d", &guess);
                    nGuess++;
                    if (guess == target)
                    {
                        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\tYou are correct. You made it in %d guesses.", nGuess);
                        fprintf(file, "%d\n", nGuess);
                        break;
                    }
                    else if (guess > target)
                    {
                        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\tGuess a lower number: ");
                    }
                    else
                    {
                        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\tGuess a higher number: ");
                    }
                }
                break;
            }
            fclose(file);
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t[Q]Exit Game\n\n\t\t\t\t\t\t\t\t\t\t\t\t[M]Return to Main Menu\n\n");
            int Vchoice = toupper(getch());
            if (Vchoice == 'Q')
            {
                system("cls");
                printf("\t\t\t\t\t\t\t\t\t\t\tThank You for trying this game. Hope to see you back soon.\n\n");
                exit(1);
            }
            else if (Vchoice == 'M')
            {
                goto mainscreen;
            }
            break;
        case 2:
            system("cls");
            char name1[20];
            printf("\t\t\t\t\t\t\t\t\t\t\t\tEnter your username: ");
            scanf("%s", &name1);
            FILE *file1;
            file1 = fopen("scoreA.csv", "a");
            fprintf(file1, "%s\t\t", name1);
            system("cls");
            printf("\t\t\t\t\t\t\t\t\t\t\t\tWhich difficulty level would you like?\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t[1]-Beginner\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t[2]-Pro\n\n");
            difficulty = 0;
            printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
            scanf("%d", &difficulty);
            int target, nGuess, Ltarget, Htarget;
            char targ1, targ2;
            char target1, guessAlpha = '*';
            switch (difficulty)
            {
            case 1:
                system("cls");
                srand(time(0));
                target = 0;
                nGuess = 0;
                target = (rand() % 26) + 97;
                target1 = (char)target;
                printf("\t\t\t\t\t\t\t\t\t\t\t\tEnter a lower-case alphabet: ");
                while (guessAlpha != target1)
                {
                    guessAlpha = getch();
                    printf("%c", guessAlpha);
                    nGuess++;
                    if (guessAlpha == target1)
                    {
                        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\tYou are correct. You made it in %d guesses.", nGuess);
                        fprintf(file1, "%d\n", nGuess);
                        break;
                    }
                    else if (guessAlpha < target1)
                        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\tGuess a higher alphabet towards z: ");
                    else
                        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\tGuess a lower alphabet towards a: ");
                }
                break;
            case 2:
                Ltarget = 0, Htarget = 0, nGuess = 0;
                system("cls");
                srand(time(0));
                Ltarget = (rand() % 26) + 97;
                Htarget = (rand() % 26) + 65;
                targ1 = (char)Ltarget;
                targ2 = (char)Htarget;
                printf("\t\t\t\t\t\t\t\t\t\t\t\tEnter any alphabet: ");
                while (guessAlpha != targ1 && guessAlpha != targ2)
                {
                    guessAlpha = getch();
                    printf("%c", guessAlpha);
                    nGuess++;
                    if (guessAlpha == targ1 || guessAlpha == targ2)
                    {
                        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\tYou are correct. You made it in %d guesses.", nGuess);
                        fprintf(file1, "%d\n", nGuess);
                        break;
                    }
                    else if (guessAlpha < 97)
                    {
                        if (guessAlpha < targ2)
                            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\tGuess a uppercase alphabet towards Z: ");
                        else
                            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\tGuess a uppercase alphabet towards A: ");
                    }
                    else if (guessAlpha < targ1)
                        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\tGuess a lowercase alphabet towards z: ");
                    else
                        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\tGuess a lowercase alphabet towards a: ");
                }
                break;
            }
            fclose(file1);
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t[Q]Exit Game\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t[M]Return to Main Menu\n\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
            Vchoice = toupper(getch());
            if (Vchoice == 'Q')
            {
                system("cls");
                printf("\t\t\t\t\t\t\t\t\t\t\tThank You for trying this game. Hope to see you back soon.\n\n");
                exit(1);
            }
            else if (Vchoice == 'M')
            {
                goto mainscreen;
            }
        case 3:
            goto mainscreen;
            break;
        default:
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\tPlease enter a valid choice. Exiting the game.");
        }
    }
    else
    {
        printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tEnter a valid option.\n\n\t\t\t\t\t\t\t\t\t\t\t\tIf you wish to return to mainscreen enter R.\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tPress anything else to quit.\n\n");
        char c;
        c = toupper(getch());
        if (c == 'R')
            goto mainscreen;
        else
        {
            printf("\t\t\t\t\t\t\t\t\t\t\tThank You for trying this game. Hope to see you back soon.\n\n");
            exit(1);
        }
    }
    return 0;
}