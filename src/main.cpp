/*
    Counting Sort Algorithm (stable version)

    23.03.2022 | g++ -std=c++11 | https://github.com/Haruno19
*/

#include <iostream>
#include <chrono>
#include <time.h>

const int arrayLength = 1000000;
const int maxValue = 1000000;

int array[arrayLength]; 
double ExecutionTime;

void PrintArray();
int* GenerateArray();
void CountingSort(int* countingArray);


int main()
{
    srand(time(NULL));

    CountingSort(GenerateArray());
    PrintArray();

    return 0;
}

void PrintArray()
{
    std::cout << "\nCounting Sort with " << arrayLength << " elements \n";

   /* for(int i=0;i<arrayLength;i++)
    {
        if(array[i]<10) std::cout << " ";
        std::cout << array[i] << "; ";
    }*/
       
    std::cout << "\nExecution time: " << ExecutionTime << " sec \n\n"; 
}

int* GenerateArray()
{
    for(int i=0;i<arrayLength;i++)
        array[i]=rand()%maxValue+1;

    int* a = new int[maxValue] {0};  

    return a;
}

void CountingSort(int* countingArray)
{
    auto start = std::chrono::steady_clock::now();

    int* bufferArray = new int[arrayLength];

    for(int i=0;i<arrayLength;i++)
    {
        countingArray[array[i]]++;
        bufferArray[i] = array[i];
    }

    for(int i=2;i<maxValue;i++)
        countingArray[i]=countingArray[i]+countingArray[i-1];

    for(int i=arrayLength-1;i>=0;i--)
    {   
        array[countingArray[bufferArray[i]]-1]=bufferArray[i];
        countingArray[bufferArray[i]]--;
    }

    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    ExecutionTime = (std::chrono::duration <double, std::milli> (diff).count())/1000;
}
