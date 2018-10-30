#include <stdio.h>
#include <string.h>
struct item{

    char state[15];
    int population;

};
int main()
{
   struct item data[10];
   char temp[10];
   int r;
    int i=0;
    char *line = NULL;
    size_t len = 0;
    int count = 0;
    int round;

    //printf("Enter state initials to sort\n" );
    //printf("Press ENTER TO ENTER VALUES\n");
    //printf("PRESS Ctrl-D twice to stop\n");

            do
            {
            scanf("%s", data[i].state);
            count ++;
            i++;
            }while(getline(&line,&len,stdin) != EOF);
            
            
            for(round=0;round < count; round++){
                for(i=0;i<count-round;i++){
                    r=strcmp(data[i].state,data[i+1].state);
                     if (r>0){
                        strcpy(temp,data[i].state);
                        strcpy(data[i].state,data[i+1].state);
                        strcpy(data[i+1].state,temp);
                     }
                }
            }



    for (i=0; i<count;i++)
    {
        printf("%s", data[i].state);
        printf("\n");

    }
}