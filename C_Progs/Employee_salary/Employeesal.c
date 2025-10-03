#include<stdio.h>
int gettaxbracket(int tax)
{
    int slab;

    if(tax>=1000000)
        slab = 30;
    else if(tax>=500000)
        slab = 20;
    else if(tax>=250000)
        slab = 5;
    else
        slab = 0;

    return slab;
}

int main()
{
    int n, i;
    float sum = 0, avg;
    
    printf("Enter salaries number of employees");
    scanf("%d", &n); 

    float sal[n];
    int emp[n];
    
    printf("Enter salaries for %d employees: \n", n);
    for(i=0; i<n; i++)
    {
      	scanf("%f", &sal[i]);
	    emp[i] = gettaxbracket(sal[i]);
	    sum += sal[i];
    }

    avg = sum/n;
    printf("The average of all %d employee salaries is %f \n", n, avg);

    printf("Tax bracket for employees in %% are : \n");
    for(i=0; i<n; i++)	
    {
	    printf("Employee %d = %d %% \n", i+1, emp[i]);
    }
	return 0;
}
