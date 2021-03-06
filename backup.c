#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 30
#define N 30
#define dataLeng 30
#define fSize 30
char hash[M][N];

struct shopnode
{
	char shopname[30];
	char floor[20];
	struct shopnode *next;
};
struct node
{
	char data[30];
	struct shopnode *link;
};
struct node chainList[M];
void Welcome()
{
    printf("                                                                                                         \n");
	printf("---------------------------------------------------------------------------------------------------------------\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t**********************************\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t*\t     WELCOME TO \t *\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t*\t SHOPPING CENTER\t *\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t**********************************\t\t\t\t\t\t|\n");
	printf("|\t\t\t\tAll the items at your fingertips\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t      \"WE BELIEVE IN QUALITY\"\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|Press any key to continue.........\t\t\t\t\t\t\t\t\t\t|\n");

	printf("-----------------------------------------------------------------------------------------------------------------\n");

}

void display(struct shopnode *temp)
{
	if(temp==NULL)
	{
		printf("No shops have this item\n");
		return;
	}
	else
	{
		printf("\nYour Desired item is in the following shops with location");
		while(temp!=NULL)
		{
			printf("Floor->%s\n",temp->floor);
			printf("Shop name->%s\n",temp->shopname);
			temp=temp->next;
		}
	}
	
}

int search(char item[],int n)
{
	
	int flag=0;
	char name[30];
	for(int i=0;i<n;i++)
	{
		
		if(strcmpi(item,chainList[i].data)==0)
		{
			display(chainList[i].link);
			flag=1;
		}
		else if(i==n-1 && flag==0)
		{
			printf("\nEnter a valid item name from the list ");
			return 0;
		}
	
	}
	return flag;	
	
}


void chooseItem(int n)
{
	char item[30];
	int success=0;
	int choice;
	do
	{	
		printf("Item List\n");
		for(int i=0;i<n;i++)
			printf("%s\n",chainList[i].data);
		printf("\nEnter the item you want to purchase from the above list");
		gets(item);
		success=search(item,n);
	}while(success==0);
}


void makeHash(char slot[],char shop[],char floor2[])
{
	printf("In make Hash\n");

	puts(slot);
	puts(shop);
	puts(floor2);
	struct shopnode *newnode=(struct shopnode*)malloc(sizeof(struct shopnode));
	newnode->next=NULL;
	strcpy(newnode->floor,floor2);
	strcpy(newnode->shopname,shop);
	for(int i=0;i<M;i++)
	{
		if(strcmpi(chainList[i].data,slot)==0)
		{
			if(chainList[i].link==NULL)
				chainList[i].link=newnode;
			else
			{
				struct shopnode *temp=chainList[i].link;
				while(temp->next!=NULL)
					temp=temp->next;
				temp->next=newnode;
				
			}
		}
	}
	for(int i=0;slot[i]!='\0';i++)
        strcpy(&slot[i],"\0") ;

	printf("Before leaving");
	puts(slot);
	puts(shop);
	puts(floor2);
				
				
}
void disp(int n)
{
	for(int i=0;i<n;i++)
	{
		display(chainList[i].link);
	}
}
void buildHash(FILE *f)
{
	f=fopen("mallOutline.txt","r");
	char curFloor[fSize]={'\0'},curShop[dataLeng]={'\0'},curSlot[dataLeng]={'\0'};
	printf("In build Hash\n");
	int tabCount=0,i=0;
	char line[30]={'\0'};
	char ch=getc(f);
	printf("ab%c",ch);
	while(ch!='\n' && ch!=EOF)
	{
		ch=getc(f);
	}
	printf("pq%c",ch);// \n
	ch=getc(f); //sp1
	//printf("%ccd\n",ch);
	//printf("before while\n");
	curFloor[0]='\0';
	curShop[0]='\0';
	curSlot[0]='\0';
	while(ch!=EOF)
	{
		//printf("In while %d\n",tabCount);
		//0tab
		if(ch!=' ')
		{
			//printf("%cno entry",ch);
			tabCount=0;
			break;			
		}
		else
		{
			tabCount++;
			ch=getc(f); //sp2
			//printf("\nIn else %d",tabCount);
    
			while(ch==' ')
			{
				tabCount++;
				//printf("\nIn else/while  %d ch = %c",tabCount,ch);			
				ch=getc(f);
			}
			// printf("\nIn else after while %d\n",tabCount);
			// printf("next character %c X  ",ch);
			
		
		switch (tabCount)
		{
			case 4:
				//floor
				//strcpy(line,"a");
				curFloor[0]='\0';
				curShop[0]='\0';
				curSlot[0]='\0';
				printf("In Switch 1 ch= %c line =%s  \n",ch,line);
				while(ch!='\n' && ch!=EOF)
				{
					line[i]=ch;
					i++;
					ch=getc(f);
				}
				//printf("line1=%s\n",line);
				strcpy(curFloor,line);
				for(int i=0;line[i]!='\0';i++)
        			strcpy(&line[i],"\0") ;

				ch=getc(f);
				//printf("In Switch 1 ch= %c line1 =%s  \n",ch,line);
				break;

			case 8:
				//shop				
				//printf("In Switch 2 ch =%c line2 =%s\n"+ch,line);
				//printf("\nLine2 = %s", line);
				//strcpy(line,"a");
				//printf("In Switch 2 ch =%c line2 =%s\n"+ch,line);
				for(int i=0;line[i]!='\0';i++)
        		strcpy(&line[i],"\0") ;
				
				//strcpy(line,"a");
				while(ch!='\n' && ch!=EOF)
				{
					line[i]=ch;
					i++;
					ch=getc(f);
				}
				//printf("\nLine 2 = %s", line);
				strcpy(curShop,line);
				for(int i=0;line[i]!='\0';i++)
        		strcpy(&line[i],"\0") ;

				ch=getc(f);
				//printf("In Switch 2 ch= %c line =%s  \n",ch,line);
				break;

			case 12:
				////strcpy(line,"a");
				//slot
				printf("In Switch 3 line =%s\n",line);
				while(ch!='\n' && ch!=EOF)
				{
					line[i]=ch;
					i++;
					ch=getc(f);
				}
				//printf("\nLine 3 = %s", line);
				strcpy(curSlot,line);
				//strcpy(line,"a");
				
				printf("3 before going");
				puts(curFloor);
				puts(curShop);
				puts(curSlot);
				makeHash(curSlot,curShop,curFloor);
				printf("After coming");
				puts(curFloor);
				puts(curShop);
				puts(curSlot);
				ch=getc(f);
				//printf("In Switch 3 ch= %c line3 =%s  \n",ch,line);

				break;				

			// default:
			// 	line[0]='\0';
			// 	printf("\nLine = %s", line);
			// 	printf("\n       It should not 1111111111come here     \n");
			// 	break;
		}
		//strcpy(line,"a");
		tabCount=0;
		for(int i=0;line[i]!='\0';i++)
        		strcpy(&line[i],"\0") ;
		
		//line[0]='\0';
		i=0;
		}
	}
 
    fclose(f);
}

void main()
{
    int i,j,k,l,m,choice;
    i=j=k=0;
	char ch;
    //Welcome();
    printf("\n");

    FILE *sectionPtr=fopen("type.txt","r");
    FILE *mallPtr=fopen("mallOutline.txt","r");
	char line[N];
    if(sectionPtr==NULL)
	{
        printf("Section file does not exist");
		return;
	}
	if(mallPtr==NULL)
	{
        printf("mall file does not exist");
		return;
	}
	//assigning null to all
	for(j=0;j<M;j++)
		for(k=0;k<N;k++)
			hash[j][k]='\0';
	j=0;
    while((ch=getc(sectionPtr))!=EOF)
    {
		while(ch!='\n' && ch!=EOF)
		{
			line[i]=ch;
			i++;
			ch=getc(sectionPtr);
		}
		for(k=0;k<i;k++)
		{
			hash[j][k]=line[k];
			//printf("%c",hash[j][k]);
		}
		i=0;
		j++;
    }
	int n_row=j;

	//printf("\nHash table is\n \n");
	// for(j=0;j<n_row;j++)
	// {
	// 	for(k=0;hash[j][k];k++)
	// 		printf("%c",hash[j][k]);
	// 	printf("\n");
	// }
    


	for(j=0;j<M;j++)
		for(k=0;k<N;k++)
			chainList[j].data[k]='\0';
			

	for(i=0;i<n_row;i++)
		for(k=0;hash[i][k];k++)
			chainList[i].data[k]=hash[i][k];

	
	buildHash(mallPtr);
	disp(n_row);
	chooseItem(n_row);

	fclose(mallPtr);
	

	


}