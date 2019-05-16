
#include "pch.h"
#include <iostream>
#include "IVehicle.h"
#include "IWatercraft.h"
#include "IAircraft.h"
#include "superarray.h"


int main()
{
	SuperArray<int> arr1, arr2; // new arrays of integers

	arr1[10] = 20;
	arr1[100] = 34;
	/*arr1[-12] = arr1[2]; // will use the constructor with no arguments to
	// create the item at arr1[2] that did not exist prior
	// to this line. Both items will now contain unknown
	// garbage!
	arr1[100] = 48; // Replaces the value in index 100 to be 48
	// arr1 contains items at -12,2,10,100
	arr1.remove(-12); // remove the item at index -12
	arr1.remove(7); // do nothing (nothing at 7)
	// arr1 contains items at 2,10,100
	arr2 = arr1; // copy entire array
	arr1.remove(); // deletes the entire arr1 array
	arr2[-12] = 7;
	arr2.remove(2); // remove item at index 2
	// go over all allocated items, and sum them.

	// will go over items -12,10,100
	// may not be meaningful for every type

	int sum = 0;
	for (SuperArray<int>::iterator iter = arr2.begin(); iter != arr2.end(); iter++)
		sum += *iter;
	// sum will be 20 + 48 + 7 = 75
	int n = arr2.num_elements(); // n will be 3
	n = arr2.lowest_index(); // n will be -12
	n = arr2.highest_index(); // n will be 100*/
	return 0;
}
