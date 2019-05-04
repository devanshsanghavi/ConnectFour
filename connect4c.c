#include <stdio.h>
//First 5 functions are for colours
void r();
void y();
void d();
void b();
void p();
void display(char a[6][7]);//To display grid
void input(char a[6][7],char p[100],char x);//To accept column no. from user
int check(char a[6][7], char p[100], char x,int f);//To check if the user has got 4 in a row, column or (2)diagonal

void main()
{
	p();
    printf("\nCONNECT4:\nGame developed by Abhishek Sudhir (1811059) and Devansh Sanghavi (1811062)\n\n ");
	d();

    char a[6][7],p1[100],p2[100],x,o,con;
    int i,j,k,l,f=0,c=1,h=1;

    while(c>0)
    {
	x='X',o='O',h=1;

    r();
    printf("\nEnter name of player 1(X):");
    scanf("%s",p1);

    y();
    printf("\nEnter name of player 2(O):");
    scanf("%s",p2);

    printf("\n");

    for(i=0;i<6;i++)
    {
        for(j=0;j<7;j++)
        {
            a[i][j]='-';
        }
    }

    b();
    display(a);

    while(f<42)
    {
        if(f<42 && f%2==0)
        {
        input(a,p1,x);
        f++;
        display(a);
        f=check(a,p1,x,f);
        continue;
        }


        if(f<42 && f%2==1)
        {
        input(a,p2,o);
        f++;
        display(a);
        f=check(a,p2,o,f);
        continue;
        }
    }

    if(f==42)
        printf("\nGame drawn\n");


    while(h>0)
    {
        printf("\n\nDo you want to play again (Y/N)?: ");
        scanf("%s",&con);

    if(con=='Y'||con=='y')
    {
        c++;
        f=0;
        h=0;
    }
    else if(con=='n' || con=='N')
    {
       printf("\nGames played: %d\nThanks for Playing!\n",c);
        c=0;
        h=0;
    }

    else
    {
       printf("\nPlease enter either Y or N\n");
    }
    }
    }
}

    void r()
    {printf("\033[1;31m");}

    void y()
    {printf("\033[1;33m");}

    void d()
    {printf("\033[0m");}

    void b()
    {printf("\033[1;34m");}

    void p()
    {printf("\033[1;35m");}

    void display(char a[6][7])
    {
    int i,j;
    b();
    printf("\n 1  2  3  4  5  6  7\n\n");
    d();
        for(i=0;i<6;i++)
        {
            for(j=0;j<7;j++)
            {
                if(a[i][j]=='-')
                {
                  d();
                  printf(" %c ",a[i][j]);
                }

                else if(a[i][j]=='X')
                {
                  r();
                  printf(" %c ",a[i][j]);
                  d();
                }

                else if(a[i][j]=='O')
                {
                  y();
                  printf(" %c ",a[i][j]);
                  d();
                }
            }
        printf("\n");
        }
    }


    void input(char a[6][7],char p[100],char x)
    {
    int i=5,j,l,k=0;
            while(k<1)
            {
                printf("\n%s's turn. Select which column you want to drop your %c:",p,x);
                scanf("%d",&l);
                j=l-1;

                while(k<1)
                {
                if(j>6 || j<0)
                {
                    printf("\nInvalid column number. Try another column.\n");
                    display(a);
                    break;
                }

                else if(a[i][j]=='-')
                {
                    a[i][j]=x;
                    k++;
                    break;
                }
                else if(i>=0)
                {
                    i--;
                    continue;
                }
                else
                {
                    printf("\nAlready filled. Try another column.\n");
                    display(a);
                    i=5;
                    break;
                }
                }

            }

    }

    int check(char a[6][7], char p[100], char x,int f)
    {
        int i,j,l;
        if(f>6 && f<42)
        {
            for(i=0;i<6;i++)
            {
                for(j=0;j<7;j++)
                {
                    if(a[i][j]==x && ((j<4 && a[i][j+1]==x && a[i][j+2]==x && a[i][j+3]==x)||(i<3 && a[i+1][j]==x && a[i+2][j]==x && a[i+3][j]==x)
                        ||(i<3 && j<4 && a[i+1][j+1]==x && a[i+2][j+2]==x && a[i+3][j+3]==x)||(i>2 && j<4 && a[i-1][j+1]==x && a[i-2][j+2]==x &&
			a[i-3][j+3]==x)))
                    {
                        printf("\n%s wins",p);
                        j=8;
                        i=7;
                        f+=51;     //to get out of the while loop.
                        break;
                    }
                }
            }
        }
        return f;
    }
