#include<iostream>
using namespace std;


class Road
{
	int *arr;
	int size;

	int rear;
	int front;
	int cap;


public:
	Road(int size)
	{
		this->size = size;
		arr = new int[size];
		front = 0;
		rear = 0;
		cap = 0;

	}

	bool isFull()
	{
		if (cap == size)
			return true;
		else
			return false;
	}
	bool isEmpty()
	{
		if (cap == 0)
			return true;
		else
			return false;
	}

	void onRoad(int val)
	{
		if (!isFull())
		{
			arr[rear] = val;
			cap++;
			rear++;

			rear = rear%size;
		}
		else
		{
			cout << "\n Value is not entered";
		}
	}

	int deQueue()
	{
		if (!isEmpty())
		{
			int val;
			val = arr[front];
			front++;


			return val;

			front = front%size;
			cap--;
		}
		else
		{
			return -1;
		}
	}
	int getFront()
	{
		if (!isEmpty())
		{
			int val;
			val = arr[front];
	
			return val;

		}
		else
		{
			return -1;
		}
	}

	void showTrucksOnRoad()
	{
		if (!isEmpty())
		{
			cout << "\nTrucks on the road.\n";
			for (int i = front; i < rear; i++)//check it later
			{
				cout << arr[i]<<"\t";
			}
		}


	}


};
//=====================================================================
							class Garage
							{
							private:
								int *arr;
								int top;
								int size;

							public:
								Garage(int size)
								{
									arr = new int[size];
									this->size = size;

									top = -1;
								}

								void enterGarage(int val)
								{
									

									if (!this->isFull())
									{
										top++;
										arr[top] = val;
									}
									else
										cout << "\nStack is Full\n";

								}
								//
								int exitGarage()
								{
									if (!this->isEmpty())
									{
										int tempVal = arr[top];
										top--;

										return tempVal;
									}
									else
									{
										return -1;
									}
								}
								//
								bool isFull()
								{
									if (top == size - 1)
									{
										return 1;
									}
									else
										return 0;
								}
								//
								bool isEmpty()
								{
									if (top == -1)
										return 1;
									else
										return 0;
								}
								//
								int getTop()
								{
									if (this->isEmpty())
									{
										return -1;
									}
									else
									{
										return arr[top];
									}
								}
								void showTrucksInGarage()
								{
									if (!isEmpty())
									{
										cout << "\nTrucks in the Garage.\n";
										for (int i = 0; i <= top; i++)//check it later
										{
											cout << arr[i] << "\t";
										}
									}


								}

							};


int main()
{

	Road R(10);
	Garage G(10);
	
	M:

	cout << "\n1. Call Function - OnRoad";
	cout << "\n2. Call Function - ShowTrucksOnRoad";
	cout << "\n3. Call Function - ShowTrucksInGarage";
	cout << "\n4. Call Function - EnterInGarage";
	cout << "\n5. Call Function - ExitGarage\n\n";

	int choose;
	cin >> choose;

	switch (choose)
	{
	case 1:
	{
			  int temp2;
			  cout << "\n\nEnter Truck to add OnRoad:";
			  cin >> temp2;

			  R.onRoad(temp2);
			  
			  goto M;
			  break;
	}
	case 2:
	{
			  R.showTrucksOnRoad();

			  goto M;
			  break;
	}
	case 3:
	{
			  G.showTrucksInGarage();


			  goto M;
			  break;
	}
	case 4:
	{
			  int temp2;
			  cout << "\n\nEnter Truck to add Garage:";
			  cin >> temp2;

			  if (R.getFront() == temp2)
			  {
				  R.deQueue();
				  G.enterGarage(temp2);
			  }
			  else
			  {
				  cout << "Value is not at exit";
			  }

			  

			  goto M;
			  break;
	}
	case 5:
	{

			  int temp2;
			  cout << "\nEnter Truck to exit in garage:";
			  cin >> temp2;

			  if (G.getTop() == temp2)
			  {
				  G.exitGarage();

			  }
			  else
			  {
				  cout << "Value is not at exit in Garage";
			  }



			  goto M;
			  break;
	}

	}








	system("pause");
	return 0;
}