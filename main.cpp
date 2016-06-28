#include <bits/stdc++.h>
#define sflld(n) scanf("%lld",&n)
#define sfulld(n) scanf("%llu",&n)
#define sfd(n) scanf("%d",&n)
#define sfld(n) scanf("%ld",&n)
#define sfs(n) scanf("%s",&n)
#define ll long long
#define s(t) int t; while(t--)
#define ull unsigned long long int
#define pflld(n) printf("%lld\n",n)
#define pfd(n) printf("%d\n",n)
#define pfld(n) printf("%ld\n",n)
#define lt 2*idx
#define rt 2*idx+1
#define f(i,k,n) for(i=k;i<n;i++)
#define MAXN 0
#define FD freopen("out.txt", "w", stdout);
#define FC fclose(stdout);

using namespace std;
char gC(int b)
{
    switch(b)
    {
        case -1:
            return 'X';
        case 0:
            return ' ';
        case 1:
            return 'O';
    }
}

void draw(int b[])
{
    printf(" %c | %c | %c\n",gC(b[0]),gC(b[1]),gC(b[2]));
    printf("---+---+---\n");
    printf(" %c | %c | %c\n",gC(b[3]),gC(b[4]),gC(b[5]));
    printf("---+---+---\n");
    printf(" %c | %c | %c\n",gC(b[6]),gC(b[7]),gC(b[8]));
}

int win(const int b[9])
{
    int i;
    int win[8][3]={{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    f(i,0,8)
     if(b[win[i][0]]!=0&&b[win[i][0]]==b[win[i][1]]&&b[win[i][0]]==b[win[i][2]])
        {
            return b[win[i][2]];
        }
     return 0;
}

int logic(int board[9],int p)
{
    int w=win(board);
    if(w)
        return w*p;
    int loc=-1,scr=-2,i;
    f(i,0,9)
    {
        if(board[i]==0)
        {
            board[i]=p;
            int temp=-logic(board,-1*p);
            if(temp>scr)
            {
                scr=temp;
                loc=i;
            }
            board[i]=0;
        }
    }
    if(loc==-1)
        return 0;
    return scr;
}

void cM(int board[9])
{
    int loc=-1,scr=-2,i;
    f(i,0,9)
    {
        if(board[i]==0)
        {
            board[i]=1;
            int temp=-logic(board,-1);
            if(temp>scr)
            {
                scr=temp;
                loc=i;
            }
            board[i]=0;
        }
    }
        board[loc]=1;
}
void valid(int b[9])
{
    int i;
    printf("You can choose a move from ");
    f(i,0,9)
     if(!b[i])
        printf("%d ",i);
     printf("\n");

}
void pM(int board[9])
{
    int loc = 0;
    do {
        start:
            valid(board);
        sfd(loc);
        if(board[loc] != 0) {
            printf("Invalid Move!\n");
            goto start;
        }

        printf("\n");
    } while (loc >= 9 || loc < 0 && board[loc] == 0);
    board[loc] = -1;
}
int main()
{
    begin :
    int board[9] = {0};
     printf("Computer will take O, You have to take X\nDo you want to play as Player 1 ? Y/N  ");
    int p=0;
    char ch;
    cin>>ch;
    if(ch=='Y')
    {
        cout<<"You are Player 1 please start the game\n";
        p=1;
    }
    else
    {
        cout<<"You are Player 2 Computer will start the game\n";
        p=2;
    }
    printf("\n");
    int t;
    f(t,0,9)
    {
        if(win(board))
            break;
        if((t+p) % 2 == 0)
            cM(board);
        else {
            draw(board);
            pM(board);
        }
    }
    switch(win(board))
    {
        case 0:
            printf("Draw\n");
            break;
        case 1:
            draw(board);
            printf("You lose. Try Again Later\n");
            break;
        case -1:
            printf("You win. #GodLIke\n");
            break;
    }
    cout<<"Do you want to play again ?? Y/N\n";

    cin>>ch;
    if(ch=='Y')
        goto begin;
    else
        cout<<"Thank you";
    return 0;
}
