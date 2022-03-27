#include <stdio.h>
#include <string.h>
#define pf printf
#define sf scanf
#define fpf fprintf
#define fsf fscanf

struct vehicles
{
    int reg;
    char oname[30];
    char oaddress[100];
};

void printer();
void reader();

void main()
{
    printer();
    reader();
}

void printer()//Prints records to a file
{
    FILE * fp1 = fopen("Vehicle.dat", "a");
    struct vehicles v;
    for(;;)
    {
        pf("Enter Registration number of vehicle.\n");
        sf("%d", &v.reg);
        fflush(stdin);
        pf("Enter Name of Owner.\n");
        fgets(v.oname, 30, stdin);
        fflush(stdin);
        v.oname[strcspn(v.oname, "\n")] = 0;
        if(strcmpi("End", v.oname)==0)
            break;
        fflush(stdin);
        pf("Enter Address of owner.\n"); 
        fgets(v.oaddress, 100, stdin);
        v.oaddress[strcspn(v.oaddress, "\n")] = 0;
        fpf(fp1, "%d\n%s\0\n%s\0\n\n", v.reg, v.oname, v.oaddress);
    }
    fclose(fp1);
}

void reader()
{
    FILE *fp1 = fopen("Vehicle.dat", "r");
    struct vehicles v;
    char name[30];
    int flag = 0;
    fflush(stdin);
    pf("Enter name of owner.\n");
    fgets(name, 30, stdin);
    name[strcspn(name, "\n")] = 0;
    while(!feof(fp1))
    {
        fsf(fp1, "%d\n%s\n%s\n\n", &v.reg, &v.oname, &v.oaddress);
        if(strcmpi(v.oname, name)==0)
        {
            flag = 1;
            pf("Registration Number: %d\n", v.reg);
            pf("Owner's Name: %s\n", v.oname);
            pf("Address of Owner: %s\n", v.oaddress);
        }
    }
    if(flag == 0)
    {
        pf("Record wasn't found.\n");
    }
    fclose(fp1);
}