#include<stdio.h>
#include<string.h>

struct customer
{
    float savings;
    char name[50];
    char address[100];
    long long Account_number;
    long long number;
};

int main()
{
    int n, i, j;
   
    printf("Enter number of Customer");
    scanf(" %d", &n);
   
    struct customer cus[n];
 
    for(i=0; i<n; i++)
    {
        printf("Enter Name of Customer %d: \n", i+1);
        scanf(" %[^\n]", cus[i].name);           //used to read character until new line
        printf("Enter Customer address: \n");
        scanf(" %[^\n]", cus[i].address);
        printf("Enter account number Customer: \n", i);
        scanf(" %lld", &cus[i].Account_number);
        printf("Enter contact details Customer: \n", i);
        scanf(" %lld", &cus[i].number);
        printf("Enter amount in  account: \n", i);
        scanf(" %f\n ", &cus[i].savings);
    }
   
    //sorting the array
    for(j=0; j<n-1; j++)
    {
        for(i=0; i<n-j-1; i++)
        {
            if(cus[i].savings < cus[i + 1].savings)
            {
                struct customer temp = cus[i];
                cus[i] = cus[i + 1];
                cus[i + 1] = temp;
            }
        }
    }
    printf("-----------------------------Details----------------------------------------\n");
    for(i = 0; i < n; i++)
    {
        printf("Customer %d:\n", i+1);
        printf("Name               : %s\n", cus[i].name);
        printf("Address            : %s\n", cus[i].address);
        printf("Account number     : %lld\n", cus[i].Account_number);
        printf("Contact details    : %lld\n", cus[i].number);
        printf("Amount in account  : %.2f\n", cus[i].savings);
        printf("-----------------------------------------------------------------------------\n");
    }
    return 0;
}
