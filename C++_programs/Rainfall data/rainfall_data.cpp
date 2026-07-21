#include<iostream>

#include<iomanip>

using namespace std;



int main()

{

	int i, j;

	float sum=0;

	float avg;

	float rainfall[3][4];



	for(i=0; i<3; i++)

	{

		cout<<"Enter data for city "<<i+1<<" rainfall in mm"<<endl;

		for(j=0; j<4; j++)

		{

			cout<<"Month "<<j+1<<": "<<endl;

			cin>>rainfall[i][j];

		}

	}



	cout<<"Displaying the data in tabular format"<<endl;



	cout<<left

		<< setw(10)<<"City"

		<< setw(10) <<"Month 1"

		<< setw(10) <<"Month 2"

		<< setw(10) <<"Month 3"

		<< setw(10) <<"Month 4"

		<< setw(15) <<"Average Rainfall"<<endl;



	for(i=0; i<3; i++)

	{

			sum=0;

			cout<<left<< setw(10)<<i+1;

			for(j=0; j<4; j++)

			{

				cout<<left<<setw(10) <<rainfall[i][j];

				sum += rainfall[i][j];

			}

			avg = sum/4;

			cout<< setw(15)<<avg;

			cout<<endl;

		}

	return 0;

}