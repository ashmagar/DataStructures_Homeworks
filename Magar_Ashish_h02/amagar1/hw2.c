/* A program to
	1. Calculate the minimum fans required to cool the computer with most power effieciency
		given the different fan sizes available, the power consumed by those fans
		and the required cooling power for particular processor.

	2. Find the minimum number of drives needed to compact the data in a high performance computer
		given the total capacities of hard drives and the size used in them

	3. Find the item that has made the company the most money
		given the cost price of item, sell price of item and how many of each item has been sold

by Ashish Magar (amagar1@binghamton.edu)
*/

#include<stdio.h>

//Function Declarations
void getMinFans(int fanSizes[],int numFans,int coolingNum);
int minHardDrives(int used[],int usedSize,int total[],int totalSize);
int findProfit(int cost[], int sales[], int unitSales[],int arraySize);


//main
int main()
{

//1.
	int fanSizes[] = {6,7,8,10};
	int numFans = 4;
	int coolingNum = 16;
	getMinFans(fanSizes,numFans,coolingNum);

//2.
	int used[] = {60,20,30,40};
	int usedSize = 4;
	int total[] = {80,120,120,80};
	int totalSize = 6;
	int minHD = 0;
	minHD = minHardDrives(used,usedSize,total,totalSize);
//	printf("\nThe minimum number of hard drives needed \nto compact the data  would be \n -> %d\n\n",minHD);
	printf("\n%d\n",minHD);

//3.
	int cost[] = {1,2,7};
	int sales[] = {2,6,9};
	int unitSales[] = {1,2,6};
	int arraySize = 3;
	int maxProfitBy = 0;
	maxProfitBy = findProfit(cost,sales,unitSales,arraySize);
//	printf("\nThe max profit from item number (index starting with 0) \n -> %d \n\n",maxProfitBy);
	printf("%d\n",maxProfitBy);

	return 0;
}

//Function Definitions

//1. To calculate fans utilizing minimum power
void getMinFans(int fanSizes[],int numFans,int coolingNum)
{
	int i=0, j=0,k=0,x=0,temp=0;
	int add=0;			//used to perform temperory addtion of powers of fans
	int powRequired = 0;
	int minPower = 9999;
	int temp_array[numFans];
	int array[numFans];		//Stores the final answer

	for(i=0;i<numFans;i++)
        {
                for(j=i+1;j<numFans;j++)
                {
                        if(fanSizes[i]<fanSizes[j])
                        {
                                temp = fanSizes[i];
                                fanSizes[i] = fanSizes[j];
                                fanSizes[j] = temp;
                        }
                }
        }				/*Sorted the given array of fansizes in descending oreder
					 in order to take combinitions in easier way */

	/*The following logic performs the combination of all the elements 
	to get the addition equal to required cooling number */
	for(i=0;i<numFans;i++)
	{
		if(fanSizes[i] > coolingNum) break;
		add = fanSizes[i];
		powRequired = fanSizes[i]*fanSizes[i];
		j=i+1;
		k=1;			//temp variable to traverse the temp array which stores possible fan sizes
		for(x=0;x<4;x++) temp_array[x]=0;
		temp_array[0] = fanSizes[i];

		while(j < numFans)
		{
			add = add + fanSizes[j];

			if(add>coolingNum) add = add - fanSizes[j];
                 	else
			{
				/*if  the addition is less than cooling number then
				square the current element and add to power required then
				add element to the temperory array of possible combinations*/

				powRequired = powRequired + (fanSizes[j]*fanSizes[j]);
				temp_array[k++] = fanSizes[j];
			}
			if(add == coolingNum)
			{
				if(powRequired < minPower)
				{
					minPower = powRequired;
					for(x=0;x<numFans;x++) array[x] = temp_array[x];
				}
				//Resetting the temperory values for next combination with the same value of i
				k=1;
				for(x=1;x<numFans;x++) temp_array[x] = 0;
				add = fanSizes[i];
				powRequired =  fanSizes[i]*fanSizes[i];
			}
			j++;
		}
	}  	//i is incremented and the next set of possible combinations is obtained with the next element in array

//sorting the answer array in ascending order
    	for(i=0;array[i]!=0;i++)
	{
		for(j=0;array[j]!=0;j++)
		{
			if (array[i] < array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}

//printing the answer array
//	    printf("\nThe fans used are \n -> ");
	    for(x=0;array[x]!=0;x++) printf("%d ",array[x]);
//	    printf("\nThe minimum power required by the fans is \n -> %d \n",minPower);

}					//****END OF getMinFans()****



//2. To calculate minimum number of hard drives
int minHardDrives(int used[],int usedSize,int total[],int totalSize)
{
	int i=0, j=0, temp=0;
	int minHD=0, totalData=0;

	//Calculating total used data
	for(i=0;i<usedSize;i++)
	{
		totalData = totalData + used[i];
	}

	//Sorting the total array in descending order 
	for(i=0;i<totalSize;i++)
	{
		for(j=i+1;j<totalSize;j++)
		{
			if(total[i]<total[j])
			{
				temp = total[i];
				total[i] = total[j];
				total[j] = temp;
			}
		}
	}

	minHD = 1;
	for(i=0;i<totalSize;i++)
	{
		totalData = totalData - total[i];
		if (totalData > 0)
		{
			minHD++;
		}
		else
		{
			break;
		}
	}

	return minHD;
}			//****End of minHardDrives()****



//3. To calculate which item has given the mazimum profit
int findProfit(int cost[], int sales[], int unitSales[],int arraySize)
{
	int maxProfit = 0, maxProfitBy = 0;
	int i=0, temp=0;

	for(i=0;i<arraySize;i++)
	{
		temp = (sales[i] - cost[i]) * unitSales[i];
		if (temp > maxProfit)
		{
			maxProfit = temp;
			maxProfitBy = i;
		}
	}

	return maxProfitBy;
}		//****End of findProfit****


// **************************************END OF PROGRAM*************************** //
