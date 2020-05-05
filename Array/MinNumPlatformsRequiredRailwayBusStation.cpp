//
// https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

namespace MinNumPlatformsRequiredRailwayBusStation
{
	int Run(int arr[], int dep[], int numOfArr)
	{
		int max = 0;
		int cur = 0;
		int numOfTrains = 0;

		int i = 0;
		int j = 0;
		while (i < numOfArr)
		{
			if (arr[i] < dep[j])
			{
				cur = arr[i++];
				numOfTrains++;
			}
			else
			{
				cur = dep[j++];
				numOfTrains--;
			}
			if (numOfTrains > max)	max = numOfTrains;
		}

		return max;

	}
};


int MinNumPlatformsRequiredRailwayBusStation_Test()
{
	int arr[] = { 900, 940, 950, 1100, 1500, 1800 };
	int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 };
	int n = sizeof(arr) / sizeof(arr[0]);

	int platforms = MinNumPlatformsRequiredRailwayBusStation::Run(arr, dep, n);

	cout << "Minimum Number of Platforms Required = " << platforms << endl;

	return 0;
}
