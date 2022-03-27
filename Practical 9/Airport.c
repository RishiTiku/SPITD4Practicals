#include <stdio.h>
#include <string.h>
#define pf printf
#define sf scanf

char cities[][4] = {"DEL", "BOM", "BAN", "CHE", "KOL"}; 
int ncities = 5;
struct flight
{
    char st[4];
    char des[4];
    int dep;
    int arr;
    int seats;//avl seats
}F, flights[20];

int input(struct flight *f);
void print(struct flight *f);
void updateRecords(char filename[30], struct flight f);

void main()
{
    int origin, des, counter = 0, temp; 
    FILE * fp;
    fp = fopen("Flights.dat", "a");
    for(;;)
    {
        printf("Enter Flight details.\n");
        int i = input(&F);
        if(i == -1)
            break;
        fprintf(fp, "%s\0,%s\0,%d,%d,%d\n", F.st, F.des, F.dep, F.arr, F.seats);
    }
    fclose(fp);
    
    
    fp = fopen("Flights.dat", "r");
    pf("Choose Starting point.\n");
    for(int i = 0; i<ncities; i++)
    {
        pf("%d. %s\n", i+1, cities[i]);
    }
    sf("%d", &origin);
    pf("Choose Destination.\n");
    for(int i = 0; i<ncities; i++)
    {
        pf("%d. %s\n", i+1, cities[i]);
    }
    sf("%d",&des);
    while(!feof(fp))
    {
        fscanf(fp, "%s,%s,%d,%d,%d\n", &flights[counter].st, &flights[counter].des, 
                &flights[counter].dep, &flights[counter].arr, &flights[counter].seats);
        if(!strcmpi(flights[counter].st, cities[origin])&&!strcmpi(flights[counter].des, cities[des])&&flights[counter].seats>0)
        {
            pf("%d. ", counter+1);
            print(&flights[counter]);
            counter++;
        }
    }
    fclose(fp);


    pf("Which flight do you want to register for?(1 - %d)\n",counter);
    scanf("%d", &temp);
    updateRecords("Flights.dat", flights[temp]);
    
}

int input(struct flight *f)
{
    int temp;
    for(int i = 0; i<ncities; i++)
    {
        pf("%d. %s\n", i+1, cities[i]);
    }
    pf("Enter Origin. (1 - %d) (-1 to skip)\n", ncities);
    sf("%d", &temp);
    if(temp == -1)
    {
        return -1;
    }
    strcpy(f->st, cities[temp]);
    pf("Enter Destination. (1 - %d)\n", ncities);
    sf("%d", &temp);
    strcpy(f->des, cities[temp]);
    pf("Enter Departure time.\n");
    sf("%d", &(f->dep));
    pf("Enter Arrival time.\n");
    sf("%d", &(f->arr));
    pf("Enter Available seats.\n");
    sf("%d", &(f->seats));
    return 0;
}

void print(struct flight * f)
{
    pf("Origin: %s\n", f->st);
    pf("Destination: %s\n", f->des);
    pf("Departure time: %d\n", f->dep);
    pf("Arrival time: %d\n", f->arr);
    pf("Available seats: %d\n", f->seats);
    return;
}

void updateRecords(char filename[30], struct flight f)
{
    FILE * fp1 = fopen(filename, "r");
    FILE * fp2 = fopen("temp.dat", "w");

    while(!feof(fp1))
    {
        fscanf(fp1, "%s,%s,%d,%d,%d\n", &f.st, &f.des, &f.dep, &f.des, &f.seats);
        if("")    

}