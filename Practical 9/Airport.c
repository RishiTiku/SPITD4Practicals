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
int updateRecords(char filename[30], struct flight * f);
void copy(struct flight *f1, struct flight *f2);//Copies f2 into f1
void main()
{
    int origin, des, counter = 0, temp; 
    FILE * fp;
    fp = fopen("Flights.dat", "a");
    pf("Input Mode.\n");
    for(;;)
    {
        printf("Enter Flight details.\n");
        int i = input(&F);
        if(i == -1)
            break;
        fprintf(fp, "%s\0", F.st);
        fprintf(fp, "\n%d\n", F.dep);
        fprintf(fp, "%s\0", F.des);
        fprintf(fp, "\n%d\n", F.arr);
        fprintf(fp, "%d\n", F.seats);
        fprintf(fp, "\n");
    }
    fclose(fp); 
    fp = fopen("Flights.dat", "r");
    pf("Booking Mode.\n");
    pf("Choose Starting point.\n");
    for(int i = 0; i<ncities; i++)
        pf("%d. %s\n", i+1, cities[i]);
    sf("%d", &origin);
    pf("Choose Destination.\n");
    for(int i = 0; i<ncities; i++)
        pf("%d. %s\n", i+1, cities[i]);
    sf("%d",&des);
    pf("\n\nAvailable Flights.\n");
    while(!feof(fp))
    {
        fscanf(fp, "%s\n%d\n%s\n%d\n%d\n\n", &F.st, &F.dep, 
                &F.des, &F.arr, &F.seats);
        if((!strcmpi(F.st, cities[origin-1]))&&(!strcmpi(F.des, cities[des-1]))&&(F.seats>0))
        {
            copy(&flights[counter], &F);
            pf("%d. ", counter+1);
            print(&flights[counter]);
            pf("\n");
            counter++;
        }
    }
    fclose(fp);
    pf("Which flight do you want to register for?(1 - %d)\n",counter);
    scanf("%d", &temp);
    if(temp<=counter&&temp>=1)
    {
        int T = updateRecords("Flights.dat", &flights[temp-1]);
        pf("The flight you've chosen is: \n");
        fp = fopen("Flights.dat", "r");
        fseek(fp, T, 0);
        fscanf(fp, "%s\n%d\n%s\n%d\n%d\n\n", &F.st, &F.dep, 
                &F.des, &F.arr, &F.seats);
        print(&F);
    }
    else
    {
        pf("Wrong Input.\n");
    }
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
    strcpy(f->st, cities[temp-1]);
    pf("Enter Destination. (1 - %d)\n", ncities);
    sf("%d", &temp);
    strcpy(f->des, cities[temp-1]);
    pf("Enter Departure time. (24hour: hhmm)\n");
    sf("%d", &(f->dep));
    pf("Enter Arrival time. (24hour: hhmm)\n");
    sf("%d", &(f->arr));
    pf("Enter Available seats.\n");
    sf("%d", &(f->seats));
    return 0;
}

void print(struct flight * f)
{
    pf("Origin: %s\n", f->st);
    pf("Destination: %s\n", f->des);
    pf("Departure time: %d hours\n", f->dep);
    pf("Arrival time: %d hours\n", f->arr);
    pf("Available seats: %d\n", f->seats);
    return;
}

int updateRecords(char filename[30], struct flight * f)
{
    int t = 0, T = 0;
    FILE * fp1 = fopen(filename, "r");
    FILE * fp2 = fopen("temp.dat", "w");
    struct flight dum;
    while(!feof(fp1))
    {
        t = ftell(fp1);
        fscanf(fp1, "%s\n%d\n%s\n%d\n%d\n\n", &dum.st, &dum.dep, &dum.des, &dum.arr, &dum.seats);
        if(T == 0&&!strcmpi(dum.st, f->st)&&!strcmpi(dum.des, f->des)&&(f->dep==dum.dep))
        {
            T = t;
            fprintf(fp2, "%s\0", f->st);
            fprintf(fp2, "\n%d\n", f->dep);
            fprintf(fp2, "%s\0", f->des);
            fprintf(fp2, "\n%d\n", f->arr);
            fprintf(fp2, "%d\n", (f->seats)-1);
            fprintf(fp2, "\n");
        }
        else
        {
            fprintf(fp2, "%s\0", dum.st);
            fprintf(fp2, "\n%d\n", dum.dep);
            fprintf(fp2, "%s\0", dum.des);
            fprintf(fp2, "\n%d\n", dum.arr);
            fprintf(fp2, "%d\n", dum.seats);
            fprintf(fp2, "\n");
        }
    }    
    fclose(fp1);
    fclose(fp2);
    remove(filename);
    rename("temp.dat", filename);
    return T; 
}

void copy(struct flight * f1, struct flight * f2)
{
    strcpy(f1->des, f2->des);
    strcpy(f1->st, f2->st);
    f1->dep = f2->dep;
    f1->arr = f2->arr;
    f1->seats = f2->seats;
}


