
#include "pch.h"
#include <iostream>
#include <string>
#include <typeinfo>
#include "IVehicle.h"
#include "IWatercraft.h"
#include "IAircraft.h"
#include "CAirplane.h"
#include "CHotAirBalloon.h"
#include "superarray.h"

using std::cout;
using std::endl;
using std::string;

template<class T>
void printList(TNode<T>* head);

void Print(int obj);

void PolyPrint(IVehicle* ptr);


int main()
{
		SuperArray<int> arr1, arr2; // new arrays of integers

		arr1[10] = 20;
		arr1[100] = 34;
		arr1[-12] = arr1[2]; // will use the constructor with no arguments to
		// create the item at arr1[2] that did not exist prior
		// to this line. Both items will now contain unknown
		// garbage!
		arr1[100] = 48; // Replaces the value in index 100 to be 48
		// arr1 contains items at -12,2,10,100
		arr1.remove(-12); // remove the item at index -12
		arr1.remove(7); // do nothing (nothing at 7)
		// arr1 contains items at 2,10,100
		arr2 = arr1; // copy entire array
		//printList(arr1.GetHead());
		arr1.remove(); // deletes the entire arr1 array
		arr2[-12] = 7;
		arr2.remove(2); // remove item at index 2
		// go over all allocated items, and sum them.
		// will go over items -12,10,100
		// may not be meaningful for every type
		int sum = 0;

		int n = arr2.num_elements(); // n will be 3
		n = arr2.lowest_index(); // n will be -12
		n = arr2.highest_index(); // n will be 100

	
		SuperArray<IVehicle*> vehicleArray;

		IVehicle* ap1 = new CAirplane("boeing", "747");
		IVehicle* hab1 = new CHotAirBalloon("donkey", "blue and yellow");
		IVehicle* ap2 = new CAirplane("airbus", "323");
		IVehicle* hab2 = new CHotAirBalloon("house", "brown");
		IVehicle* ap3 = new CAirplane("IAI", "F16");
		IVehicle* hab3 = new CHotAirBalloon("cat", "pink");
		IVehicle* ap4 = new CAirplane("boeing", "dreamliner");
		IVehicle* hab4 = new CHotAirBalloon("car", "matt grey");
		IVehicle* ap5 = new CAirplane("rafael", "564");
		IVehicle* hab5 = new CHotAirBalloon("some shape", "blue");

		vehicleArray[0] = ap1;
		vehicleArray[10] = hab1;
		vehicleArray[-30] = ap2;
		vehicleArray[17] = hab2;
		vehicleArray[05] = ap3;
		vehicleArray[50] = hab3;
		vehicleArray[13] = ap4;
		vehicleArray[-4] = hab4;
		vehicleArray[-16] = ap5;
		vehicleArray[-1] = hab5;
		//printList(vehicleArray.GetHead());
		vehicleArray.PntrToFunc(PolyPrint); 

		SuperArray<int> sint;

		try
		{
			sint.remove();
		}
		catch (...)
		{
			//cout << e;
		}



		return 0;
	}

	void PolyPrint(IVehicle* ptr)
	{
		cout << "typeid called: " << typeid(*ptr).name() << endl;
		if (CAirplane* ap = dynamic_cast<CAirplane*>(ptr))
		{
			cout << "its an airplane!" << endl;
		}

		if (CHotAirBalloon* ap = dynamic_cast<CHotAirBalloon*>(ptr))
		{
			cout << "its a hot air balloon!" << endl;
		}



		ptr->Print();
	}


	template<class T>
	void printList(TNode<T>* head)
	{
		TNode<T>* t = head;

		while (t != nullptr)
		{
			cout << t->GetIndex() << endl;
			cout << t->GetData() << endl;
			t = t->GetNext();
		}
	}

	void Print(int obj)
	{
		cout << obj << endl;
	}

