#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void randomNumber(int nums[],int random[])
{
	srand((unsigned)time (NULL));
	int a,b,c,d;

	//random[0]

	a=rand()%10;	//random index
	random[0]=nums[a];
	for (int i = a; i < 10; ++i)
	{
		nums[i]=nums[i+1];//deleting the already chosen random number
	}
	//random[1]
	
	b=rand()%9;	//random index
	random[1]=nums[b];
	for (int i = b; i < 9; ++i)
	{
		nums[i]=nums[i+1];//deleting the already chosen random number
	}
	//random[2]
	
	c=rand()%8;	//random index
	random[2]=nums[c];
	for (int i = c; i < 8; ++i)
	{
		nums[i]=nums[i+1];//deleting the already chosen random number
	}
	//random[3]
	
	d=rand()%7;	//random index
	random[3]=nums[d];
	for (int i = d; i < 7; ++i)
	{
		nums[i]=nums[i+1];//deleting the already chosen random number
	}
}

void hint(int random[])
{
	for (int i = 0; i < 4; ++i)
	{
		printf("%d  ",random[i] );
	}
}

//--------------------------------------------------------------------------------------------------------------
main(void)
{
	int random[4];//random number
	int nums[10]={0,1,2,3,4,5,6,7,8,9};
	int user[4];//array containing the user's answer
	int ua;//user answer
	int d1,d2,d3,d4;//digits extracted from the user's answer
	int test_b,test_c;//testing variables for Cows and Bulls
	int x,p,occ,test;//testing variables for user's aswer
	
	//--------------------------------------------------------------------

	randomNumber(nums,random);//generating the random number
	hint(random);//printing out the hidden random number

	
	//-------------------------------------------------------------
	printf("\n\nYour try : ");
	do	
	{


		
		do
		{
			printf("\n\n> ");scanf("%d",&ua);//getting the answer from the player

				d1 = ( ua / 1000 );	
				d2 = ( ua % 1000 ) / 100;
				d3 = ( ua / 10 ) % 10;	
				d4 = ( ua % 10 );
			//filling the array with the answer
				user[0] = d1 ;
				user[1] = d2 ;
				user[2] = d3 ;
				user[3] = d4 ;

			
			occ=0;
			test=1;
			p=0;
			while( (test==0)&&(p<4) )
			{
				x=user[p];
				for (int i = 0; i < 4; ++i)
				{
					if (user[i]==x)
					{
						occ +=1;
					}
				}

				if (occ==1)//theres only one copy of the number, which is itself . . .
				{
					test=1;
				}else
				{
					test=0;
				}
				p +=1;
			}
		}while(test=0);



			//------testing for Cows and Bulls-----


			test_b=0;
			test_c=0;

			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					if (random[i]==user[j])
					{
						if (i==j)
						{
							test_b +=1;
						}else
						{
							test_c +=1;
						}
					}
				}
			}


		printf("\n\nU have %dB and %dC",test_b,test_c);

	}while(test_b!=4);//while the answer has bulls in it (not correct)





	getch();
}
