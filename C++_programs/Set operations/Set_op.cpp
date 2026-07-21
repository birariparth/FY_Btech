#include<iostream>
using namespace std;

int main()
{
    int A[10] = {0};
    int B[10] = {0};
    int U[20] = {0};
    int I[10] = {0};
    int S[10];
    int deleteindex = -1;
    int size = 10;
    int sizeA = 5;
    int sizeS = 0;
    int k = 0;
    int found = 0;

    cout<<"\nEnter elements for array 1"<<endl;

    for(int i = 0; i < 5; i++)
    {
        cin>>A[i];
    }

    cout<<"\nEnter elements for array 2"<<endl;

    for(int i = 0; i < 5; i++)
    {
        cin>>B[i];
    }

    //Intersection
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(A[i]==B[j])
            {
                I[k]=A[i];
                k++;
            }
        }
    }

    cout<<"\nIntersection of sets 1 and 2: "<<endl;
    for(int i = 0;i < k;i++)
    {
        cout<<I[i]<<" ";
    }

    //Union
    k=0;
    for(int j = 0; j < 10; j++)
    {
        k++;
        if(k>5)
        {   
            U[j]=B[j-5];
        }
        else
        {
            U[j]=A[j];
        }
    }

    for(int i = 0; i < size; i++)
    {
        for(int j = i+1; j < size; j++)
        {
            if(U[i]==U[j])
            {
                deleteindex = j;

                for(int z = deleteindex; z < size-1; z++)
                {
                    U[z] = U[z+1];
                }
                size--;
                j--;
            }
        }
    }

    cout<<"\nUnion of sets 1 and 2: "<<endl;
    for(int i = 0; i < size; i++)
    {
        cout<<U[i]<<" ";
    }

    //Substraction
    for(int i = 0; i < sizeA; i++)
    {
        found = 0;
        for(int j = 0; j < 5; j++)
        {
            if(A[i]==B[j])
            {
                found = 1;
                break;
            }
        }
        if(found == 0)
        {
            int temp = 0;
            for(int x = 0; x < sizeS; x++)
            {
                if(S[x] == A[i])
                {
                    temp = 1;
                }
            }
            if(temp == 0)
            {
                S[sizeS] = A[i];
                sizeS++;
            }
        }
    }

    cout<<"\nSubstraction of 1-2: "<<endl;
    for(int i = 0; i < sizeS; i++)
    {
        cout<<S[i]<<" ";
    }
    
    return 0;
}