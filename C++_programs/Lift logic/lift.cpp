#include <iostream>
#include <cstdlib>

using namespace std;

class lift
{
	int weight = 500;
	int direction;
	int level;
	int lift1, lift2;
	int weight1, weight2;
	bool direction1, direction2;

	public:

		void getlevel()
		{
			cout<<"Enter level you are on to call the lift"<<endl;
			cin>>level;

			cout<<"Enter direction you want to go in(1 for UP, 0 for DOWN)"<<endl;
			cin>>direction;
		}

		int checkifavailable()
		{
			lift1 = (rand()%10)+1;
			lift2 = (rand()%10)+1;
			weight1 = (rand()%500)+1;
			weight2 = (rand()%500)+1;
			direction1 = rand() % 2;
       		direction2 = rand() % 2;

			//condition checks
			
			bool lift1available = (weight1<weight);
			bool lift2available = (weight2<weight);

			if (weight1 > weight && weight2 > weight)  //condition checks for lift available or not by weight
			{
				cout << "Both lifts are overloaded. Please wait." << endl;
				return 0;
			}
			else
			{
				if(!lift1available)
				{
					cout<<"calling lift 2. Lift 1 is overloaded";
					return 1;
				}
				else if(!lift2available)
				{
					cout<<"calling lift 1. Lift 2 is overloaded";
					return 1;
				}
				else
				{
					return 2;
				}
			}
		}

		void ifavailable()
		{
			int level1 = lift1 - level;
			int level2 = lift2 - level;

			//formatting
			if(level1<0)
			{
				level1 = -level1;
			}

			if(level2<0)
			{
				level2 = -level2;
			}

			bool lift1movingtouser = (level >= level1 && direction1 == 0)||(level >= level1 && direction1 == 1);
			bool lift2movingtouser = (level >= level2 && direction2 == 0)||(level >= level2 && direction2 == 1);

			bool lift1match = (direction1 == direction) && lift1movingtouser;
			bool lift2match = (direction2 == direction) && lift2movingtouser;

			if(lift1match && !lift2match)
			{
				cout<<"Calling lift 1. In your direction";
			}
			else if(lift2match && !lift1match)
			{
				cout<<"Calling lift 2. In your direction";
			}
			else
			{
				if(level1 < level2)
				{
					cout<<"Calling lift 1. It is near";
				}
				else if(level2 < level1)
				{
					cout<<"Calling lift 2. It is near";
				}
				else
				{
					cout<<"calling lift 1. Equidistant";
				}
			}
		}
};

int main()
{
    lift obj;
    obj.getlevel();
    
    int status = obj.checkifavailable();

    if (status == 2) 
	{
        obj.ifavailable(); 
    }
	return 0;
}