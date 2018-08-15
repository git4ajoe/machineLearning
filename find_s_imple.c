/*
Roll : 18CS60R73
NAME : Arun
Assignment 1 (Find-s implementation)
Input file name accepted as command line argument.
*/

#include<stdio.h>
#include<stdlib.h>

#define N 9
#define X 2

void find_s(FILE *fp);

void main(int argc, char *argv[])
{

	FILE *fp;

	if(argc!=2)
	{
		printf("Error in specifying input file\n");
		return;
	}
	
	fp = fopen(argv[1],"r");

	if(fp==NULL)
	{
		printf("Error in opening file\n");
		return;
	}
	
	find_s(fp);		
	
	fclose(fp);	
}

void find_s(FILE *fp)
{
	int general[N]={X};
	int hypothesis[N]={0};
	int i=0,count=0,countdc=0;
	

	//read the first positive example and keep it as the most general one.
	do
	{
		
		if(fscanf(fp,"%d,%d,%d,%d,%d,%d,%d,%d,%d",&general[0],&general[1],&general[2],&general[3]
					,&general[4],&general[5],&general[6],&general[7],&general[8]) !=N)
			break;
		else
			count++;
					
	}while(general[N-1]==0);
	
	if(general[N-1]==0)
	{
		printf("%d number of lines processed\n",count);
		printf("no positive training example given\n");
		return;
	}


	while(fscanf(fp,"%d,%d,%d,%d,%d,%d,%d,%d,%d",&hypothesis[0],&hypothesis[1],&hypothesis[2],&hypothesis[3]
			,&hypothesis[4],&hypothesis[5],&hypothesis[6],&hypothesis[7],&hypothesis[8])==N)	
	{
		count++;		

		if(hypothesis[N-1]==1)
		{
			countdc=0;
			for(i=0;i< N-1;i++)
			{
				if(general[i]!=hypothesis[i])
				{
					general[i]=X;        //don't care
					countdc++;
				}
			}
				
		}
		else 
		; //ignoring negative training examples.
				
	}

	
	/*
		printing the result here.
	*/		
	printf("%d",N-1-countdc);
	for(i=0;i<N-1;i++)
	{
		if(general[i]!=X)
		{
			printf(",");
			if(general[i]==1)
				printf("%d",i+1);
			else	
				printf("-%d",i+1);
		}
	}
	printf("\n");	

	//printf("%d lines processed\n",count);
}
