#include<stdio.h>

int binar(int x)
{
	int nr=7,y=0;
	for (int i = 0; i < x; i++)
	{
		y=y+(1<<nr);
		nr--;
	}
	return y;
}

int main()
{
	int numar_executari;
	int N,a[255], MSK_2;
	unsigned int NET[1000][4];
	unsigned char IP_1[4], IP_2[4], MSK_1[4];
	scanf("%d",&numar_executari);
	for(int executare=1; executare<=numar_executari; executare++)
	{
		scanf("%hhu.%hhu.%hhu.%hhu",&MSK_1[0], &MSK_1[1], &MSK_1[2], &MSK_1[3]);
		scanf("%d ",&MSK_2);
		scanf("%hhu.%hhu.%hhu.%hhu",&IP_1[0], &IP_1[1], &IP_1[2], &IP_1[3]);
		scanf("%hhu.%hhu.%hhu.%hhu",&IP_2[0], &IP_2[1], &IP_2[2], &IP_2[3]);
		scanf("%d",&N);
		for (int i = 0; i < N; i++)
		{
				scanf("%u.%u.%u.%u/%u",&NET[i][0],&NET[i][1],&NET[i][2],&NET[i][3],&NET[i][4]);

		}			
		printf("\n");
		printf("%d\n",executare);
		//Task 0
		printf("-0 ");
		printf("%hhu.%hhu.%hhu.%hhu",IP_1[0], IP_1[1], IP_1[2], IP_1[3]);
		printf("/");
		printf("%d\n",MSK_2);

		//Task1
		int rest;
		printf("-1 ");
		unsigned char MSK2[4];
		if (MSK_2/8==4)
		{
			printf("255.255.255.255\n");
			MSK2[0]=255;
			MSK2[1]=255;
			MSK2[2]=255;
			MSK2[3]=255;		
		}
		else if (MSK_2/8==3)
		{
			rest=MSK_2%8;
			printf("255.255.255.%d\n",binar(rest));
			MSK2[0]=255;
			MSK2[1]=255;
			MSK2[2]=255;
			MSK2[3]=binar(rest);
		}
		else if (MSK_2/8==2)
		{
			rest=MSK_2%8;
			printf("255.255.%d.0\n",binar(rest));
			MSK2[0]=255;
			MSK2[1]=255;
			MSK2[2]=binar(rest);
			MSK2[3]=0;
		}
		else if (MSK_2/8==1)
		{
			rest=MSK_2%8;
			printf("255.%d.0.0\n",binar(rest));
			MSK2[0]=255;
			MSK2[1]=binar(rest);
			MSK2[2]=0;
			MSK2[3]=0;
		}
		else if (MSK_2/8==0)
		{
			rest=MSK_2%8;
			printf("%d.0.0.0\n",binar(rest));
			MSK2[0]=binar(rest);
			MSK2[1]=0;
			MSK2[2]=0;
			MSK2[3]=0;
		}
		//Task2
		printf("-2 ");
		printf("%o.%o.%o.%o ",MSK_1[0],MSK_1[1],MSK_1[2],MSK_1[3]);
		printf("%X.%X.%X.%X \n",MSK_1[0],MSK_1[1],MSK_1[2],MSK_1[3]);

		//Task3
		printf("-3 ");
		printf("%hhu.%hhu.%hhu.%hhu\n",IP_1[0]&MSK2[0],IP_1[1]&MSK2[1],IP_1[2]&MSK2[2],IP_1[3]&MSK2[3]);
	
		//Task4
		printf("-4 ");
		printf("%hhu.%hhu.%hhu.%hhu\n",IP_1[0]|(~MSK2[0]),IP_1[1]|(~MSK2[1]),IP_1[2]|(~MSK2[2]),IP_1[3]|(~MSK2[3]));
		
		//Task5
		printf("-5 ");
		if (((IP_1[0]&MSK2[0])==(IP_2[0]&MSK2[0]))&&((IP_1[1]&MSK2[1])==(IP_2[1]&MSK2[1]))&&((IP_1[2]&MSK2[2])==(IP_2[2]&MSK2[2]))&&((IP_1[3]&MSK2[3])==(IP_2[3]&MSK2[3])))
		 {
			printf("DA\n");
		 }	
		else
		{
			printf("NU\n");
		} 

		//Task6
		printf("-6 ");
		int valid[4];
		if ((MSK_1[0]!=128)&&(MSK_1[0]!=192)&&(MSK_1[0]!=224)&&(MSK_1[0]!=240)&&(MSK_1[0]!=248)&&(MSK_1[0]!=252)&&(MSK_1[0]!=254)&&(MSK_1[0]!=255)&&(MSK_1[0]!=0))
		{
			valid[0]=0;
		}
		else
		{
			valid[0]=1;
		}
		if ((MSK_1[1]!=128)&&(MSK_1[1]!=192)&&(MSK_1[1]!=224)&&(MSK_1[1]!=240)&&(MSK_1[1]!=248)&&(MSK_1[1]!=252)&&(MSK_1[1]!=254)&&(MSK_1[1]!=255)&&(MSK_1[1]!=0))	
		{
			valid[1]=0;
		}
		else
		{
			valid[1]=1;
		}
		if ((MSK_1[2]!=128)&&(MSK_1[2]!=192)&&(MSK_1[2]!=224)&&(MSK_1[2]!=240)&&(MSK_1[2]!=248)&&(MSK_1[2]!=252)&&(MSK_1[2]!=254)&&(MSK_1[2]!=255)&&(MSK_1[2]!=0))	
		{
			valid[2]=0;
		}
		else
		{
			valid[2]=1;
		}
		if ((MSK_1[3]!=128)&&(MSK_1[3]!=192)&&(MSK_1[3]!=224)&&(MSK_1[3]!=240)&&(MSK_1[3]!=248)&&(MSK_1[3]!=252)&&(MSK_1[3]!=254)&&(MSK_1[3]!=255)&&(MSK_1[3]!=0))	
		{
			valid[3]=0;
		}
		else
		{
			valid[3]=1;
		}
		int bit;
		if ((valid[0]==1)&&(valid[1]==1)&&(valid[2]==1)&&(valid[3]==1))
		{
			if (MSK_1[0]>=MSK_1[1]>=MSK_1[2]>=MSK_1[3])
			{
				printf("DA\n");
				bit=1;
			}
			else
			{
				printf("NU\n");
				bit=0;
			}
		}
		else
		{
			printf("NU\n");
			bit=0;
		}

		//Task7
		printf("-7 ");
		int num,i;
		unsigned char msk_1;
		if(bit==1)
		{
			printf("%hhu.%hhu.%hhu.%hhu \n",MSK_1[0],MSK_1[1],MSK_1[2],MSK_1[3]);
		}
		else
		{
			int length;
			unsigned char bin[32];
			int i1,j1=0;
			for(i1=7; i1>=0; i1--)
			{
				bin[j1]=(MSK_1[0]&(1<<i1))!=0;
				j1++;
			}
			for(i1=7; i1>=0; i1--)
			{
				bin[j1]=(MSK_1[1]&(1<<i1))!=0;
				j1++;
			}
			for(i1=7; i1>=0; i1--)
			{
				bin[j1]=(MSK_1[2]&(1<<i1))!=0;
				j1++;
			}
			for(i1=7; i1>=0; i1--)
			{
				bin[j1]=(MSK_1[3]&(1<<i1))!=0;
				j1++;
			}
			for (i = 0; i < j1; i++)
			{
				if (bin[i]==0)
				{
					break;
				}
			}
			for (int j = i; j < j1; j++)
			{
				bin[j]=0;
			}
			unsigned char MSK_task7[4];
			for (i = 0; i <4; i++)
			{
				MSK_task7[i]=0;
			}
			int reversed=0;
			for(i=7; i>=0; i--)
			{
				MSK_task7[0]=MSK_task7[0]+(1<<(i*bin[reversed]));
				reversed++;
			}
			for(i=15; i>=8; i--)
			{	
				if(bin[reversed]==0)
				{
					MSK_task7[1]=MSK_task7[1];
				}
				else
				{
					MSK_task7[1]=MSK_task7[1]+(1<<((i-8)*bin[reversed]));
					reversed++;
				}
			}
			for(i=23; i>=16; i--)
			{
				if(bin[reversed]==0)
				{
					MSK_task7[2]=MSK_task7[2];
				}
				else
				{
					MSK_task7[2]=MSK_task7[2]+(1<<((i-16)*bin[reversed]));
					reversed++;
				}
			}
			for(i=31; i>=24; i--)
			{
				if(bin[reversed]==0)
				{
					MSK_task7[3]=MSK_task7[3];
				}
				else
				{
					MSK_task7[3]=MSK_task7[3]+(1<<((i-24)*bin[reversed]));
					reversed++;
				}
			}
			printf("%hhu.%hhu.%hhu.%hhu\n",(MSK_1[0]&MSK_task7[0]),(MSK_1[1]&MSK_task7[1]),(MSK_1[2]&MSK_task7[2]),(MSK_1[3]&MSK_task7[3]) );
		}

		//Task8
		printf("-8 ");
		for (i = 7; i >=0;i--)
		{
			printf("%d",(IP_1[0]&(1<<i))!=0);
		}
		printf(".");
		for (i = 7; i >=0;i--)
		{
			printf("%d",(IP_1[1]&(1<<i))!=0);
		}
		printf(".");
		for (i = 7; i >=0;i--)
		{
			printf("%d",(IP_1[2]&(1<<i))!=0);
		}
		printf(".");
		for (i = 7; i >=0;i--)
		{
			printf("%d",(IP_1[3]&(1<<i))!=0);
		}
		printf("\n");


		//Task9
		printf("-9 ");
	}
	return 0;
}