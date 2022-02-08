//============================================================================
// Name        : ThreadPractice.cpp
// Author      : Hrishikesh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <thread>

#include <mutex>
#include<condition_variable>
using namespace std;

//Shared variable
mutex m1;
condition_variable cond;


int start = 0;
int number = 10;

void printEven()
{

	unique_lock<mutex> unique(m1);

	while(start <= number)
	{
		cond.wait(unique, [] {return (start % 2 == 0);});

		if(start <= number)
		{
			cout<<this_thread::get_id()<<" : "<<start<<endl;
			start++;
		}

		cond.notify_all();

	}

}

void printOdd()
{
	unique_lock<mutex> unique(m1);


	while(start <= number)
	{
		cond.wait(unique, [] { return (start % 2 != 0); });

		if(start <= number)
		{
			cout<<this_thread::get_id()<<" : "<<start<<endl;
			start++;
		}

		cond.notify_all();
	}
}

int main() {

	thread printOddNumber(printOdd);
	thread printEvenNumber(printEven);

	printOddNumber.join();
	printEvenNumber.join();


	return 0;
}
