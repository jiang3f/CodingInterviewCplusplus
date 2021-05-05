//
// https://www.geeksforgeeks.org/amazon-interview-experience-for-sde-ii-virtual-rounds/?ref=feed
// 

/*
*
* 
We are given the costs of a list of pants, shirts, shoes, skirts. We have a certain amount of cash with us, we need to determine the total number of possible combinations which we can buy given that we must buy one and only one of each type.

Eg: pants=[3, 5, 7], shirts = [4, 7, 8],
skirts = [5, 8], shoes = [3], budget = 25

So in the above e.g., apart from the combination [7, 8, 8, 3], all others are possible
* */

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
namespace PantsShirtsShoesSkirts
{
    void printCombine(int pant_shirt, vector<int>& skirts_shoes, int budget)
    {
        for (int i = 0;i < skirts_shoes.size();i ++)
        {
            if ((skirts_shoes[i] + pant_shirt) > budget)    break;

            cout << "pant_shirt:" << pant_shirt << ", skirt_shoe:" << skirts_shoes[i] << endl;
        }
    }

    void Run(int pants[], int npants, int shirts[], int nshirts, int skirts[], int nskirts, int shoes[], int nshoes, int budget)
    {
        // combine pants and shirts
        vector<int> pants_shirts;

        for (int i = 0; i < npants; i++)
        {
            for (int j = 0; j < nshirts; j++)
            {
                int sum = pants[i] + shirts[j];
                if (sum < budget)
                {
                    pants_shirts.push_back(sum);
                }
            }
        }

        sort(pants_shirts.begin(), pants_shirts.end());

        // combine skirts and shoes
        vector<int> skirts_shoes;

        for (int i = 0; i < nskirts; i++)
        {
            for (int j = 0; j < nshoes; j++)
            {
                int sum = skirts[i] + shoes[j];
                if (sum < budget)
                {
                    skirts_shoes.push_back(sum);
                }
            }
        }

        sort(skirts_shoes.begin(), skirts_shoes.end());

        vector<int>::iterator it;

        for (it = pants_shirts.begin(); it != pants_shirts.end(); it++)
        {
            printCombine(*it, skirts_shoes, budget);
        }
    }
};

int PantsShirtsShoesSkirts_Test()
{
    int pants[] = { 3, 5, 7 };
    int shirts[] = { 4, 7, 8 };
    int skirts[] = { 5, 8 };
    int shoes[] = { 3 };
    int budget = 25;

    PantsShirtsShoesSkirts::Run(pants, sizeof(pants) / sizeof(pants[0]), 
        shirts, sizeof(shirts) / sizeof(shirts[0]),
        skirts, sizeof(skirts) / sizeof(skirts[0]),
        shoes, sizeof(shoes) / sizeof(shoes[0]), budget);

    return 0;
}