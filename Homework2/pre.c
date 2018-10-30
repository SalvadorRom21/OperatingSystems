#include <stdio.h>

struct item{

	char state[15];
	int population;


};
int main()
{
	struct item data[10];
	int i=0;
	char *line = NULL;
	size_t len = 0;
	int count = 0;

	//printf("Enter state initials and population (millions of people)\n" );
	//printf("Press ENTER TO ENTER VALUES (STATE POPULATION) format\n");
	//printf("PRESS Ctrl-D twice to stop\n");

		
	do
	{
	scanf("%s %d", data[i].state,&data[i].population);
	count ++;
	i++;
	}while(getline(&line,&len,stdin) != EOF);

	

	for (i=0; i<count;i++)
	{
		
		if (data[i].population > 10)
		{
		printf("%s", data[i].state);
		printf("\n");
		}

	}


	
}