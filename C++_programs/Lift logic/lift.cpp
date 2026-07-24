#include <iostream>



using namespace std;



class lift

{

	int weight = 500;

	//int story[10] = {1,2,3,4,5,6,7,8,9,10};

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

		void check()

		{

			lift1 = 3;

			lift2 = 5;

			weight1 = 400;

			weight2 = 450;



			//condition checks

			if (weight1 > weight && weight2 > weight)

			{

				cout << "Both lifts are overloaded. Please wait." << endl;

				return;

			}



			bool lift1available = (weight1<weight);

			bool lift2available = (weight2<weight);



			if(!lift1available)

			{

				cout<<"calling lift 2. Lift 1 is overloaded";

				return;

			}

			if(!lift2available)

			{

				cout<<"calling lift 1. Lift 2 is overloaded";

				return;

			}



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

    obj.check();



	return 0;

}