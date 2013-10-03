#include<iostream>

#include<stdlib.h>

using namespace std;


class tictactoe;
int chk;
int cnt[3];
int move[9];
int totl_mov;
int pl1,pl2,pl1win,pl2win;
int chance;
void incpl1win();
void incpl2win();

class tictactoe
{
    int a[3][3];

public:

    void rep_mtx();
    void get_ip();
    void chk_mtx();
    bool chk_ip(int);
    void initialize();
};

void tictactoe::initialize()//constructor to initialize
{
   totl_mov=0;
   chance = 1;
   pl1=0;
   pl2=0;
   int i,j,c=48;

 for(i=0;i<9;i++)
  move[i] = 0;
 for(i=0;i<3;i++)
 {
   for(j=0;j<3;j++)
     {
          a[i][j]=(c+=1);
     }
  }
}


void tictactoe::rep_mtx() // function to represent matrix
{

   int i,j,c=0;
cout<<endl;
cout<<"total moves : "<<totl_mov;
cout<<"\t\tplayer 1 moves : "<<pl1<<"\n\t\t\tplayer 2 moves : "<<pl2<<endl;
 cout<<endl;
 cout<<"\t\t-------------"<<endl;

 for(i=0;i<3;i++)
 { cout<<"\t\t| ";
   for(j=0;j<3;j++)
   {  cout<<char(a[i][j])<<" | ";
   }
  cout<<endl;
cout<<"\t\t-------------"<<endl;

  }

 cout<<endl;

}

void tictactoe::chk_mtx() //function to chk matrix after every move for win
{
  chk=0;
  int i,j;

  for(i=0;i<3;i++) //loop1 for case1 as in notebook
  {
      for(j=0;j<3;j++)
      {
         cnt[j]=a[j][i];
      }
      if(cnt[0]==cnt[1] && cnt[1]==cnt[2])
       {
           chk=1;
           break;
       }
  }

  if (chk==1)
  return;

  for(i=0;i<3;i++)//loop2 for case2 as in notebook
  {
      for(j=0;j<3;j++)
      {
          cnt[j]=a[i][j];
      }
      if(cnt[0]==cnt[1] && cnt[1]==cnt[2])
       {
           chk=1;
           break;
       }
  }

  if (chk==1)
  return;

 {
   //loop3 for case3 as in notebook
  for(i=0;i<3;i++)
  {
      cnt[i]=a[i][i];

  }
   if(cnt[0]==cnt[1] && cnt[1]==cnt[2])
       {
           chk=1;
          return;
       }

 }
  if (chk==1)
  return;

  {  //loop4 for case4 as in notebook
      for(i=0;i<3;i++)
      {
       cnt[i]=a[i][3-i-1];

      }
      if(cnt[0]==cnt[1] && cnt[1]==cnt[2])
       {
           chk=1;
          return;
       }
  }
}

void tictactoe:: get_ip() // function to get input
{
    int i,j;
    char input;



        if (chance % 2 == 1 )    // getting input for plyaer 1
        {

            cout<<"Player 1 chance"<<endl;
            player1:
            cout<<"enter position via letter to mark : ";
            cin>>input;

            if(((int(input)>=48 && int(input)<=57) ) && chk_ip(int(input)))
            {
                    move[totl_mov]=int(input);
                    pl1++;
                    for(i=0;i<3;i++)
                {
                    for(j=0;j<3;j++)
                    {
                        if(char(a[i][j])==input)
                        a[i][j]=88;
                    }
                }
            }

            else
                {
                    cout<<"enter valid position"<<endl;
                    goto player1;
                }


        }



     else if (chance % 2 == 0 )  // getting input for player 2
    {
        cout<<"Player 2 chance"<<endl;
        player2:
        cout<<"enter position via letter to mark : ";
        cin>>input;

        if(((int(input)>=48 && int(input)<=57)) && chk_ip(int(input)))
        {
                move[totl_mov]=int(input);
                 pl2++;
                for(i=0;i<3;i++)
            {
                for(j=0;j<3;j++)
                {
                    if(char(a[i][j])==input)
                    a[i][j]=79;
                }
            }
        }

        else
            {
                cout<<"enter valid position"<<endl;
                goto player2;
            }



    }
    totl_mov++;
    chance++;

}

bool tictactoe :: chk_ip(int ip)
{
    int i,chck=0;
    for(i=0;i<9;i++)
     {
         if(move[i]==ip )
            chck=1;

     }

    if(chck==1)
     return 0;
    else
     return 1;

}

int main()
{
   int match;
   tictactoe g1;
  int i=1;
   cout<<"enter no. of match: ";
   cin>>match;


  for(i=1;i<=match;i++)
   {
       g1.initialize();
       cout<<endl;
       cout<<"Match no.: "<<i<<endl;
       cout<<"No. of Match won by player 1: "<<pl1win<<endl;
       cout<<"No. of Match won by player 1: "<<pl2win<<endl;
       g1.rep_mtx();



  while(chk != 1 && totl_mov<9)
  {
     g1.get_ip();

     if (totl_mov>=5)
        g1.chk_mtx();

     g1.rep_mtx();
     //cout<<chk<<endl;

  }

 if (chk==1 && chance % 2 ==0 && totl_mov !=9)
  {
      cout<<endl<<"player 1 wins"<<endl;
      pl1win++;
  }
 else if(chk==1 && chance % 2 ==1 && totl_mov !=9)
  {
      cout<<endl<<"player 2 wins"<<endl;
      pl2win++;
  }
 else if(chk==1 && chance % 2 ==1 && totl_mov ==9)
  {
      cout<<endl<<"player 2 wins"<<endl;
      pl2win++;
  }
 else if(chk==1 && chance % 2 ==0 && totl_mov ==9)
 {
      cout<<endl<<"player 1 wins"<<endl;
      pl2win++;
  }

 else
  cout<<"match drawn"<<endl;

  chk=0;

cout<<"No. of Match won by player 1: "<<pl1win<<endl;
       cout<<"No. of Match won by player 1: "<<pl2win<<endl;

  //cout<<chk;
 cout<<"******************************************************************************************";

   }

  
  return 0;

}

void incpl1win()
{
    pl1win++;
    pl2win--;

    if(pl2win<0)
     pl2win=0;
}



void incpl2win()
{
    pl2win++;
    pl1win--;

    if(pl1win<0)
     pl2win=0;
}




