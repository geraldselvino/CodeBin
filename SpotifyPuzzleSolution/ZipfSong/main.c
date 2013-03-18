/**********************************************
* Author: Gerald Selvino
* Date: January 11, 2013
* Description: Spotify Zipf Song problem
* Problem ID: zipfsong
* Language: C
***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUTSIZE 100

typedef struct songStruct
{
    float qi;
    char songName[30];
}songStruct;

int main()
{
    int n;
    int m;
    float fi;
    float zi;
    float basefi;
    int temp;
    char temp2[30];
    char songName[30];
    songStruct songNamePool[INPUTSIZE];
    int i;
    int j;

    printf("Enter (n) and (m) separated by spaces: ");
    scanf("%d%d",&n,&m);

    //validation checking
    if(n<1 || n>50000)
    {
        printf("Invalid value for (n)");
        exit(0);
    }
    if(m<1 || m>n)
    {
        printf("Invalid value for (m)");
        exit(0);
    }

    printf("%d %d\n",n,m);

    for(i=0;i<n;i++)
    {
        printf("Input line %d: ",i+1);
        scanf("%f%s",&fi,songName);
        //validation checking
        if(fi<0.0f || fi>10000000000000.0f)
        {
            printf("Invalid value for (fi)");
            exit(0);
        }
        printf("\n");
        if(i==0)
        {
            basefi = fi;
        }
        zi = basefi*(1.0f/(i+1));
        songNamePool[i].qi = fi/zi;
        strcpy(songNamePool[i].songName,songName);
    }

    // sort the songs based on highest qi
    for(i=1;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(songNamePool[j].qi<songNamePool[j+1].qi)
            {
                temp = songNamePool[j].qi;
                strcpy(temp2,songNamePool[j].songName);
                songNamePool[j].qi = songNamePool[j+1].qi;
                strcpy(songNamePool[j].songName,songNamePool[j+1].songName);
                songNamePool[j+1].qi = temp;
                strcpy(songNamePool[j+1].songName,temp2);
            }
        }
    }

    printf ("=====Output=====\n");

    for(i=0;i<n;i++)
    {
        if(m>0)
        {
            printf("%s\n",songNamePool[i].songName);
            --m;
        }
        else
        {
            break;
        }
    }

    return 0;
}
