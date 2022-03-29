#include <stdio.h>
#define pf printf
#define sf scanf

struct Member
{
    char name[20];
    int age;
    char address[100];
    char active;
    char married;
    char wname[20];
    int nc;
    char cnames[][20];
};

void input(struct Member *M, int n);
void print(struct Member M);

void main()
{
    int n;
    int counter = 1;
    pf("Enter Number of Members. \n");
    sf("%d", &n);
    struct Member M[n];
    input(M, n);
    pf("\n\t\tAll Members.\n");
    for(int i =0; i<n; i++)
    {
        pf("%d. ", i+1);
        print(M[i]);
    }
    pf("\n\t\tWives' Data.\n");
    for(int i = 0; i<n; i++)
    {
        if((M[i].active == 'Y'||M[i].active == 'y')&&(M[i].married == 'Y'||M[i].married == 'y'))
        {
            pf("%d. ", counter);
            pf("Wife of %s = %s", M[i].name, M[i].wname);
            pf("\n");
            counter++;
        }
    }
}

void input(struct Member *M, int n)
{
    for(int i = 0; i<n; i++)
    {
        pf("Member %d.\n",i+1);
        pf("Enter Name.\n");
        sf("%s", M->name);
        pf("Enter age.\n");
        sf("%d", &M->age);
        pf("Enter Address.\n");
        sf("%s", M->address);
        fflush(stdin);
        pf("Whether Active? (y/n)\n");
        sf("%c", &M->active);
        fflush(stdin);
        pf("Whether Married? (y/n)\n");
        sf("%c", &M->married);
        if(M->married == 'Y'|| M->married == 'y')
        {
            pf("Enter Wife's name.\n");
            sf("%s", M->wname);
            fflush(stdin);
            pf("Enter Number of Children.\n");
            sf("%d", &M->nc);
            for(int j = 0; j<M->nc; j++)
            {   
                pf("Enter Child %d's name.\n",j+1);
                sf("%s", M->cnames[j]);
                fflush(stdin);
            }
        }
        M++;
    }
}

void print(struct Member M)
{
        pf("Name: %s", M.name);
        pf("\nAge: %d", M.age);
        pf("\nAddress: %s", M.address);
        pf("\nActive: %c", M.active);
        if(M.married == 'Y'|| M.married == 'y')
        {
            pf("\nWife's name: %s", M.wname);
            pf("\nNumber of Children:%d", M.nc);
            for(int j = 0; j<M.nc; j++)
                pf("\nChild %d's name: %s", j+1, M.cnames[j]);
        }
        pf("\n");
}