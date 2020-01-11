
#include <stdio.h>
#include <windows.h>
#include <conio.h>
void display(char arr[][3])
{
    int i, j, k;
    for(i = 0; i < 22; i++)
        printf("-");
    printf("\n");
    for(i = 0; i < 3; i++)
    {
        printf("|");
        for(j = 0; j < 3; j++)
        {
            printf("  %c   |", arr[i][j]);
        }
        printf("\n");
        for(k = 0; k < 22; k++)
            printf("-");
        printf("\n");
    }

}
void input(char arr[][3], char sign);
void player1(char arr[][3])
{
    int choice, flag = 1;
    printf("Player 1 turn: ");
    input(arr, 'X');
}

void input(char arr[][3], char sign)
{
    int flag = 1, choice;
    while(flag)
    {
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            if(arr[0][0] == ' ')
            {
                flag = 0;
                arr[0][0] = sign;
            }
            break;
        case 2:
            if(arr[0][1] == ' ')
            {
                flag = 0;
                arr[0][1] = sign;
            }
            break;
        case 3:
            if(arr[0][2] == ' ')
            {
                flag = 0;
                arr[0][2] = sign;
            }
            break;
        case 4:
            if(arr[1][0] == ' ')
            {
                flag = 0;
                arr[1][0] = sign;
            }
            break;
        case 5:
            if(arr[1][1] == ' ')
            {
                flag = 0;
                arr[1][1] = sign;
            }
            break;
        case 6:
            if(arr[1][2] == ' ')
            {
                flag = 0;
                arr[1][2] = sign;
            }
            break;
        case 7:
            if(arr[2][0] == ' ')
            {
                flag = 0;
                arr[2][0] = sign;
            }
            break;
        case 8:
            if(arr[2][1] == ' ')
            {
                flag = 0;
                arr[2][1] = sign;
            }
            break;
        case 9:
            if(arr[2][2] == ' ')
            {
                flag = 0;
                arr[2][2] = sign;
            }
            break;
        }
  }
}

void player2(char arr[][3])
{
    int flag = 1;
    printf("Player 2 turn: ");
    input(arr, 'O');
}
int checkwin(char arr[][3])
{
    int i, j, flag = 0;
    for(i = 0; i < 2; i++)
    {
        if(arr[i][i] == ' ')
            break;
        else if(arr[i][i] == arr[i+1][i+1])
            flag++;
    }
    if(flag == 2)
        return 1;

    flag = 0;
    for(i =2; i > 0; i--)
    {
        if(arr[2 -i][i] == ' ')
            break;
        if(arr[2 - i][i] == arr[ 2- i + 1][i-1])
            flag++;
    }
    if(flag == 2)
        return 1;

        flag = 0;
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 2; j++)
        {
            if(arr[i][j] == ' ')
                break;
            if(arr[i][j] == arr[i][j+1])
                flag++;
        }
        if(flag == 2)
            return 1;
        else flag = 0;
    }
    for(j = 0; j < 3; j++)
    {
        for(i = 0; i < 2; i++)
        {
            if(arr[i][j] == ' ')
                break;
            if(arr[i][j] == arr[i+1][j])
                flag++;
        }
        if(flag == 2)
            return 1;
        else flag = 0;
    }
    return 0;
}
int main()
{
    char arr[3][3] = {32, 32, 32, 32, 32, 32, 32, 32, 32}, i;
    int win1 = 0, win2 = 0;
      for(i = 0; i < 9; i++)
      {
          display(arr);
          if(i%2 == 0)
          {
              player1(arr);
              win1 = checkwin(arr);
              if(win1 == 1)
                break;
          }
          else
          {
              player2(arr);
              win2 = checkwin(arr);
              if(win2 == 1)
                break;
          }
          system("cls");
      }
      system("cls");
      display(arr);
      getch();
      system("cls");
      if(win1 == 1)
        printf("Player 1 won!");
      else if(win2 == 1)
        printf("Player 2 won!");
      else printf("Draw game!");

    return 0;
}
