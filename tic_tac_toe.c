#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>

int P1_Score;
int P2_Score;
int Match_Draw;
void Reset_Board(char Board[])
{
    for(int i=0;i<9;i++)
        Board[i]=' ';
}

void Show_Board(char board[])
{
    printf("\t\t-------------------\n");
    printf("\t\t|   Tic Tac Toe   |\n");
    printf("\t\t-------------------\n\n");
    printf("\t\t     |        |    \n");
    printf("\t\t %c   |   %c    |  %c\n",board[0],board[1],board[2]);
    printf("\t\t     |        |    \n");
    printf("\t\t-----+--------+-----\n");
    printf("\t\t     |        |    \n");
    printf("\t\t %c   |   %c    |  %c\n",board[3],board[4],board[5]);
    printf("\t\t     |        |    \n");
    printf("\t\t-----+--------+-----\n");
    printf("\t\t     |        |    \n");
    printf("\t\t %c   |   %c    |  %c\n",board[6],board[7],board[8]);
    printf("\t\t     |        |    \n");
            
}

int Winner(char Board[])
{
    // Row
    if(Board[0]==Board[1] && Board[1]==Board[2] && Board[0]!=' ')
        return 1;
    
    if(Board[3]==Board[4] && Board[4]==Board[5] && Board[3]!=' ')
        return 1;
    
    if(Board[6]==Board[7] && Board[7]==Board[8] && Board[6]!=' ')
        return 1;
    
    // Column
    if(Board[0]==Board[3] && Board[3]==Board[6] && Board[0]!=' ')
        return 1;
    
    if(Board[1]==Board[4] && Board[4]==Board[7] && Board[1]!=' ')
        return 1;
    
    if(Board[2]==Board[5] && Board[5]==Board[8] && Board[2]!=' ')
        return 1;
    
    // Digonal
    if(Board[0]==Board[4] && Board[4]==Board[8] && Board[0]!=' ')
        return 1;
    if(Board[2]==Board[4] && Board[4]==Board[6] && Board[2]!=' ')
        return 1;
    
    return 0;
}
int Find_0(char Board[],int index)//find 0
{
    // Column
    if(index==1 || index==4 || index==7)
    {
        
        if(Board[index-1]=='0')
        {
            if(Board[index+1]==' ')
            {
                Board[index+1]='0';
                return 1;
            }
        }
        else if(Board[index+1]=='0')
        {
            if(Board[index-1]==' ')
            {
                Board[index-1]='0';
                return 1;
            }
        }

        
    }
    if(index==0 || index==3 || index==6)
    {
       
        if(Board[index+1]=='0')
        {
            if(Board[index+2]==' ')
            {
                Board[index+2]='0';
                return 1;
            }
        }
        else if(Board[index+2]=='0')
        {
            if(Board[index+1]==' ')
            {
                Board[index+1]='0';
                return 1;
            }
        }
        
    }
    // Row
    if(index==0 || index==1 || index==2)
    {
        
        if(Board[index+3]=='0')
        {
            if(Board[index+6]==' ')
            {
                Board[index+6]='0';
                return 1;
            }
        }
        else if(Board[index+6]=='0')
        {
            if(Board[index+3]==' ')
            {
                Board[index+3]='0';
                return 1;
            }
        }
        
    }
    if(index==3 || index==4 || index==5)
    {
        
        if(Board[index-3]=='0')
        {
            if(Board[index+3]==' ')
            {
                Board[index+3]='0';
                return 1;
            }
        }
        else if(Board[index+3]=='0')
        {
            if(Board[index-3]==' ')
            {
                Board[index-3]='0';
                return 1;
            }
        }
        
    }
    // Digonal
    if(index==2)
    {
        
        if(Board[index+2]=='0')
        {
            if(Board[index+2+2]==' ')
            {
                Board[index+2+2]='0';
                return 1;   
            }
        }
        else if(Board[index+2+2]=='0')
        {
            if(Board[index+2]==' ')
            {
                Board[index+2]='0';
                return 1;
            }
        }
        
    }
    if(index==4)
    {
        
        if(Board[index-2]=='0')
        {
            if(Board[index+2]==' ')
            {
                Board[index+2]='0';
                return 1;
            }
        }
        else if (Board[index+2]=='0')
        {
            if(Board[index-2]==' ')
            {
                Board[index-2]='0';
                return 1;
            }
        }
        if(Board[index-4]=='0')
        {
            if(Board[index+4]==' ')
            {
                Board[index+4]='0';
                return 1;
            }
        }
        else if (Board[index+4]=='0')
        {
            if(Board[index-4]==' ')
            {
                Board[index-4]='0';
                return 1;
            }
        }
    }
    if(index==0)
    {
       
        if(Board[index+4]=='0')
        {
            if(Board[index+8]==' ')
            {
                Board[index+8]='0';
                return 1;
            }
        }
        else if(Board[index+8]=='0')
        {
            if(Board[index+4]==' ')
            {
                Board[index+4]='0';
                return 1;
            }
        }
    
    }
    return 0;
}
int Find_X(char Board[],int index)//find X
{
    // Column
    if(index==1 || index==4 || index==7)
    {
        if(Board[index-1]=='X')
        {
            if(Board[index+1]==' ')
            {
                Board[index+1]='0';
                return 1;
            }
        }
        else if(Board[index+1]=='X')
        {
            if(Board[index-1]==' ')
            {
                Board[index-1]='0';
                return 1;
            }
        }
    }
    if(index==0 || index==3 || index==6)
    {
        if(Board[index+1]=='X')
        {
            if(Board[index+2]==' ')
            {
                Board[index+2]='0';
                return 1;
            }
        }
        else if(Board[index+2]=='X')
        {
            if(Board[index+1]==' ')
            {
                Board[index+1]='0';
                return 1;
            }
        }

    }
    //Row
    if(index==0 || index==1 || index==2)
    {
        if(Board[index+3]=='X')
        {
            if(Board[index+6]==' ')
            {
                Board[index+6]='0';
                return 1;
            }
        }
        else if(Board[index+6]=='X')
        {
            if(Board[index+3]==' ')
            {
                Board[index+3]='0';
                return 1;
            }
        }
    }
    if(index==3 || index==4 || index==5)
    {
        if(Board[index-3]=='X')
        {
            if(Board[index+3]==' ')
            {
                Board[index+3]='0';
                return 1;
            }
        }
        else if(Board[index+3]=='X')
        {
            if(Board[index-3]==' ')
            {
                Board[index-3]='0';
                return 1;
            }
        }
    }
    if(index==6 || index==7 || index==8)
    {
        if(Board[index-6]=='X')
        {
            if(Board[index-3]==' ')
            {
                Board[index-3]='0';
                return 1;
            }
        }
        else if(Board[index-3]=='X')
        {
            if(Board[index-6]==' ')
            {
                Board[index-6]='0';
                return 1;
            }
        }
    }
    // Digonal
    if(index==0)
    {
        if(Board[index+4]=='X')
        {
            if(Board[index+8]==' ')
            {
                Board[index+8]='0';
                return 1;
            }
        }
        else if(Board[index+8]=='X')
        {
            if(Board[index+4]==' ')
            {
                Board[index+4]='0';
                return 1;
            }
        }
    }
    
    if(index==2)
    {
        if(Board[index+2]=='X')
        {
            if(Board[(index+2)+2]==' ')
            {
                Board[(index+2)+2]='0';
                return 1;
            }
        }
        else if(Board[index+2+2]=='X')
        {
            if(Board[index+2]==' ')
            {
                Board[index+2]='0';
                return 1;
            }
        }
    }
    if(index==4)
    {
        if(Board[index-2]=='X')
        {
            if(Board[index+2]==' ')
            {
                Board[index+2]='0';
                return 1;
            }
        }
        else if(Board[index+2]=='X')
        {
            if(Board[index-2]==' ')
            {
                Board[index-2]='0';
                return 1;
            }
        }
        if(Board[index-4]=='X')
        {
            if(Board[index+4]==' ')
            {
                Board[index+4]='0';
                return 1;
            }
        }
        else if(Board[index+4]=='X')
        {
            if(Board[index-4]==' ')
            {
                Board[index-4]='0';
                return 1;
            }
        }
    }
    if(index==6)
    {
        if(Board[index-2]=='X')
        {
            if(Board[index-4]==' ')
            {
                Board[index-4]='0';
                return 1;
            }
        }
        else if(Board[index-4]=='X')
        {
            if(Board[index-2]==' ')
            {
                Board[index-2]='0';
                return 1;
            }
        }
    }
    if(index==8)
    {
        if(Board[index-8]=='X')
        {
            if(Board[index-4]==' ')
            {
                Board[index-4]='0';
                return 1;
            }
        }
        else if(Board[index-4]=='X')
        {
            if(Board[index-8]==' ')
            {
                Board[index-8]='0';
                return 1;
            }
        }
    }
    return 0;
}

// Smart Computer and Evil Computer
void Computer_Vs_Computer(char Board[],char Player_Name[],int Smart_or_evil)
{
    char choice;
    int i=0,flag=0,j,y;
    srand(time(NULL));

    while(i<9)
    {
        int x=1;
        system("cls");
        if(Smart_or_evil)
            printf("Smart Computer\n");
        else
            printf("Evil Computer\n");
        
        Show_Board(Board);
        if(flag==0)
        {
            printf("%s 's Turn [X] ",Player_Name);
            printf("\nSelect Your Position (1-9): ");
            choice=getch();
            choice--;
        
            y=choice-48;
            if(Board[y]==' ' && flag==0)
            {
                Board[y]='X';
                flag=1;
                i++;
            }
        }
        else 
        {
            printf("Computer 's Turn [0] ");
            printf("\nThinking......\n");
            Sleep(800);
            for(j=0;j<9;j++)
            {
                int k=0;
                if(Smart_or_evil==1) // Smart Computer
                {
                    
                    while(k<9)
                    {
                        if(Board[k]=='0')
                        {
                            if(Find_0(Board,k)==1)
                            {
                                flag=0;
                                x=0;
                                i++;
                                break;
                            }
                        }
                        k++;
                    }
                    if(x==0)
                        break;
                    if(Board[j]=='X')
                    {
                        if(Find_X(Board,j)==1)
                        {
                            flag=0;
                            x=0;
                            i++;
                            break;

                        }
                    }
                }//end of smart computer
                else  // Evil Computer
                {
                    
                    if(Board[j]=='0')
                    {
                        if(Find_0(Board,j)==1)
                        {
                            flag=0;
                            x=0;
                            i++;
                            break;
                        }
                    }
                    while(k<9)
                    {
                        if(Board[k]=='X')
                        {
                            if(Find_X(Board,k)==1)
                            {
                                flag=0;
                                x=0;
                                i++;
                            }
                        }
                        k++;
                    }
                    if(x==0)
                        break;
                }// end of Evil Computer
                    
            }
            while(x)
            {
                y=rand()%10;
                if(y!=9 && Board[y]==' ')
                {
                    Board[y]='0';
                    i++;
                    flag=0;
                    break;
                }
            }
        }
        if(Winner(Board))
        {
            system("cls");
            Show_Board(Board);
            if(flag)
            {
                P1_Score++;
                printf("\n%s 's Win!\n",Player_Name);
            }
            else
            {
                printf("\nComputer Win\n");
                P2_Score++;
            }
            getch();
            system("cls");
            return;
        }
    }
    system("cls");
    Show_Board(Board);
    printf("\nMatch Draw\n");
    Match_Draw++;
    getch();
    system("cls");
}

// Players vs Players
void Players_Vs_Players(char Board[],char Player_Name_1[],char Player_Name_2[])
{
    char choice;
    int flag=0,y;
    int i=0;
    while(i<9)
    {
        system("cls");
        printf("%s Vs %s\n",Player_Name_1,Player_Name_2);
        Show_Board(Board);
        if(flag==0)
            printf("%s 's Turn [X] ",Player_Name_1);
        else
            printf("%s 's Turn [0] ",Player_Name_2);
        
        printf("\nSelect Your Position (1-9): ");
        choice=getch();
        choice--;
        
        if(choice>='0' && choice<='8')
        {
            y=choice-48; // Convert Char to Int
            if(Board[y]==' ' && flag==0)
            {
                Board[y]='X';
                flag=1;
                i++;
            }
            else if(Board[y]==' ' && flag==1)
            {
                Board[y]='0';
                flag=0;
                i++;
            }
            else 
            {
                printf("\nNot Empty Cell\n");
                getch();
            }
            if(Winner(Board))
            {
                system("cls");
                Show_Board(Board);
                if(flag)
                {
                    printf("\n%s Win The Game\n",Player_Name_1);
                    P1_Score++;
                }
                else
                {
                    printf("\n%s Win The Game\n",Player_Name_2);
                    P2_Score++;
                }
                getch();
                system("cls");
                return;
            }
        }
    }
    system("cls");
    Show_Board(Board);
    printf("\nMatch Draw\n");
    Match_Draw++;
    getch();
    system("cls");
}

int main()
{
    char Board[10];
    int choice,flag=1,flag1=1,flag2=1,p=0;
    
    char Player_Name_1[20],Player_Name_2[20];
    system("cls");
    printf("Game Rule\n");
    printf("If You Switch From The Current Game To Another The Score Will Be Reset\n");
    getch();
    system("cls");
    
    while(1)
    {
        printf("\nEnter Your Choice: \n");
        printf("Press 1. To Play With Smart Computer: \n");
        printf("Press 2. To Play With Evil Computer:  \n");
        printf("Press 3. To Play With Player:  \n");
        printf("Press 4. Score:  \n");
        printf("Press 5. To Exit:  \n");
        choice=getch();
        Reset_Board(Board);
        switch(choice)
        {
            case '1':
                if(flag1)
                {
                    Match_Draw=P1_Score=P2_Score=0;
                    fflush(stdin);
                    printf("\nEnter Player Name: ");
                    gets(Player_Name_1);
                    
                    flag1=0;
                    flag2=flag=1;
                    p=1;
                }
                Computer_Vs_Computer(Board,Player_Name_1,1); //smart computer
                break;
            case '2':
                if(flag2)
                {
                    Match_Draw=P1_Score=P2_Score=0;
                    fflush(stdin);
                    printf("\nEnter Player Name: ");
                    gets(Player_Name_1);
                    
                    flag1=1;
                    flag=1;
                    flag2=0;
                    p=1;
                }
                Computer_Vs_Computer(Board,Player_Name_1,0);//Evil Computer
                break;
            case '3':
                if(flag)
                {
                    Match_Draw=P1_Score=P2_Score=0;
                    fflush(stdin);
                    printf("\nEnter Player Name_1: ");
                    
                    gets(Player_Name_1);
                    
                    printf("\nEnter Player Name_2: ");
                    
                    gets(Player_Name_2);
                    
                    flag=0;
                    flag2=flag1=1;
                    p=1;
                }
                Players_Vs_Players(Board,Player_Name_1,Player_Name_2);
                break;
            case '4':
                if(flag==0 && p)
                {
                    system("cls");
                    printf("\nMatch Draw   : %d \n",Match_Draw);
                    printf("\n%s 's Score  : %d \n",Player_Name_1,P1_Score);
                    printf("\n%s 's Score  : %d \n",Player_Name_2,P2_Score);
                    getch();
                }
                else if((flag1==0 || flag2==0) && p)
                {
                    system("cls");
                    printf("\nMatch Draw        : %d \n",Match_Draw);
                    printf("\n%s 's Score       : %d \n",Player_Name_1,P1_Score);
                    printf("\nComputer's Score  : %d \n",P2_Score);
                    getch();
                }
                else
                {
                    system("cls");
                    printf("\nFirst Play The Game! \n");
                    getch();
                }
                break;
            case '5':
                return 0;
            default:
                printf("\nInvalid Input!\n");

        }
    }
}