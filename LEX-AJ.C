#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
FILE *fp,*f1,*f2;
char a[]={'\t',',','\0',' ','(',')','>','<','.',';',',','{','}'};
char key[9][10]={
								"char","double",
								"int","void"};
void check()
{
	int i=0;
	int n=13;
	int f=0;
	char c;
	fp=fopen("a.c","r");
	f1=fopen("id.txt","w");
	while((c=fgetc(fp))!=EOF)
	{
		if(c=='#')
		{
			while((c=fgetc(fp))!='\n');
		}
		else
		{
			for(i=0;i<n;i++)
			{
				if(a[i]==c)
				{
					f=1;
					break;
				}
			}
			if(f==0)
			{
				fprintf(f1,"%c",c);
				continue;
			}
			else
			{
				f=0;
			}
		}
	}
	fclose(fp);
	fclose(f1);
}
void checkkey()
{
	char s[]="";
	int i;
	f1=fopen("id.txt","r");
	f2=fopen("key.txt","w");
	fscanf(f1,"%s",s);
	while(strcmp(s,"")!=0)
	{
		for(i=0;i<32;i++)
		{
			if((strstr(s,key[i]))!=NULL)
			{
				fprintf(f2,"%s : Keyword",s[i]);
			}
		}
		fscanf(f1,"%s",s);
	}
	fclose(f1);
}
void main()
{
	clrscr();
	check();
	checkkey();
	printf("program success");
	getch();
}