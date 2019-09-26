#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

#define ROWS 9
#define COLS 9

void readboard(char board[ROWS][COLS])
{
    int i,j;
    FILE* infile;
    infile=fopen("sudoku_game.txt","r");
    for(i=0;i<ROWS;i++)
    {
        for(j=0;j<COLS;j++)
    		fscanf(infile,"%c", &board[i][j]);
        fscanf(infile,"\n");
    }
    fclose(infile);
}

void printboard(char board[ROWS][COLS])
{
    int i,j;
    FILE* infile;
    infile=fopen("sudoku_result.txt","w");
    fprintf(infile, "Solution:");
    printf("\n");
        fprintf(infile, "\n");
        for (i=0;i<ROWS;i++)
        {
            printf("\t");
            for(j=0;j<COLS;j++)
            {
            	printf("%c ",board[i][j]);
                fprintf(infile, "%c ", board[i][j]);
            }
            printf("\n");
            fprintf(infile, "\n");
        }
    printf("\n");
}

int checkval(char board[ROWS][COLS],int i,int j,char k)
{
    int x,y;
    for (x=0;x<9;x++)
    { 
		if (x!=i)
            if (board[x][j]==k)
				return 0;
    }
    for (y=0;y<9;y++)
    { 
		if (y!=j)
            if (board[i][y]==k)
				return 0;
    }
    for(x=(i/3)*3;x<(i/3)*3+3;x++)
    {    
		for(y=(j/3)*3;y<(j/3)*3+3;y++)
            {
				if ((x!=i)|| (y!=j))
                	if (board[x][y]==k) 
						return 0;
            }
    }
	return 1;
}

int solution(char board[ROWS][COLS],int i,int j)
{
    char k;
    if(j==9)
    {
		j=0;
        i++;
    }
    if (i==9)
    {
		printboard(board);
    	return 1;
    }
    if (board[i][j]!='0')
	{
	   if (solution(board,i,j+1))
           return 0;
    }
    else
    {
		for(k='1';k<='9';k++)
		{
			if(checkval(board,i,j,k))
        	{
				board[i][j]=k;
                    if (solution(board,i,j+1))
                        return 1;
        	}
        	board[i][j]='0';	
		}
    }
return 0;
}
int main(int argc,char *argv[])
{
	char board[ROWS][COLS];
    readboard(board);
    printf("Sudoku : ");
    printboard(board);
    printf("Sudoku result :");
    solution(board,0,0);
	system ("pause");
	return 0;
}

