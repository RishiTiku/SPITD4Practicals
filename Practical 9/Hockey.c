#include <stdio.h>
#include <string.h>
#define pf printf
#define sf scanf

struct hockeyplayers
{
    char name[20];
    int matches;
    int goals;
};

void input(struct hockeyplayers *H, int n);
void print(struct hockeyplayers H);
void swap(struct hockeyplayers *H1, struct hockeyplayers *H2);

void main()
{
    int n;
    pf("Enter Number of Hockey Players.\n");
    sf("%d", &n);
    struct hockeyplayers H[n];
    input(H, n);
    int max, pos = 0;
    for(int i = 0; i<n; i++)
    {
        max = H[i].goals;
        for(int j = i; j<n; j++)//find the max in the subarray
        {   
            if(H[j].goals>max)
            {
                max = H[j].goals;
                pos  = j;
            }
        }
        swap(&H[i], &H[pos]);
    }
    pf("|\tName\t\t|\tMatches\t\t|\tGoals\t\t|\n");
    pf("|\t----\t\t|\t-------\t\t|\t-----\t\t|\n");
    for(int i = 0; i<n; i++)
    {
        print(H[i]);
    }
    return;
}

void input(struct hockeyplayers *H, int n)
{
    for(int i = 0; i<n; i++)//inputs the structures
    {
        pf("Hockey Player %d\n",i+1);
        pf("Enter name of Player: ");
        sf("%s",H[i].name);
        pf("Enter number of matches played: ");
        sf("%d", &H[i].matches);
        pf("Enter number of goals scored: ");
        sf("%d", &H[i].goals);
    }
}

void print(struct hockeyplayers H)
{
    pf("|\t%s\t\t|\t%d\t\t|\t%d\t\t|\n", H.name, H.matches, H.goals);
}

void swap(struct hockeyplayers *H1, struct hockeyplayers *H2)
{
    int temp;
    char A[20];
    strcpy(A, H1->name);
    strcpy(H1->name, H2->name);
    strcpy(H2->name, A);   
    temp = H1->goals;
    H1->goals = H2->goals;
    H2->goals = temp;
    temp = H1->matches;
    H1->matches = H2->matches;
    H2->matches = temp; 
}