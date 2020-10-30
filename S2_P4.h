#include <iostream>
#ifndef Header_H
#define Header_H
using namespace std;
class student
{
public:
	int ID;     //student id
	float GPA;      //student gpa
	string name;    //student name
	student* link;  //pointer for next node address
	student();      // default constructor
	student(string inputName, int inputID, float inputGPA);         //paramterized constructor
};
class studentList
{
private:
	student* first;     //pointer refer to first element in the list
	student* last;      //pointer refer to last element in the list
	student* dummy = new student;    // dummy node
	student* newNode;       //newNode will be created in a specific conditions
	student* current;       //pointer refer to current node
	student* beforeCurrent;     //pointer refer to the node which is before the current node
	int count;      //counter to count nodes
	bool found;

public:
	studentList();      //default constructor
	void insert(student obj);   //insert function
	bool search(int id);        //search by id in the list
	void Display();         //display all the elements in the list
	void Delete(int id);    //delete element by the id

};



#endif
