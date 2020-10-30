#include <iostream>
#include "s2_p4.h"
using namespace std;
student::student()      //initializing the student's data
{
	ID = 0;
	GPA = 0.0;
	name = " ";
}
student::student(string inputName, int inputID, float inputGPA)     //take data from user and initiate the student's data with it
{
	ID = inputID;
	GPA = inputGPA;
	name = inputName;
}
studentList::studentList()      //initialize the pointers and variables
{
	first = NULL;
	last = NULL;
	current = NULL;
	beforeCurrent = NULL;
	dummy->link = NULL;
	count = 0;
	found = false;
}
void studentList::insert(student obj)
{
	newNode = new student;  //create new node
	newNode->ID = obj.ID;       //save data in it
	newNode->name = obj.name;
	newNode->GPA = obj.GPA;
	if (first == NULL)      //if the list is empty
	{
		first = newNode;    //first will be this new node
		last = newNode;     //also last will be the same node
		first->link = last; //it's first next will be last
		last->link = dummy;     //it's last next will be to dummy
		count++;
	}
	else        //if the list isn't empty
	{
		current = first;    //then the current will refer to first element
		found = false;
		while (current->link != NULL && !found)     //while it didn't reach to the final of the list and can't find the searched item
		{
			if (current->ID >= obj.ID)      //if the current node id is >= to the searched id then found will be true
			{
				found = true;
			}
			else        //else move to the next element and loop again
			{
				beforeCurrent = current;
				current = current->link;
			}
		}
		if (current == first)   //if current = first
		{
			newNode->link = first;      //the new node will be the first node
			first = newNode;
		}
		else
		{      //else then put the node between the current node and the node before it
			newNode->link = current;
			beforeCurrent->link = newNode;

			if (current == dummy)   //if the current stop on the dummy then the element will be the last element
			{
				last = newNode;
			}
		}
		count++;
	}
}
bool studentList::search(int id)    // search by id
{
    found = false;
	current = first;    //start from first element
	while (current->link != NULL && !found)     //while it didn't reach to the final of the list and can't find the searched item
	{
		if (current->ID >= id)  //if the current node id is >= to the searched id then found will be true
		{
			found = true;       //then found = true
		}
		else
		{
			current = current->link;    //if didn't found then go to next element
		}
	}
	if (found)
	{
		found = (current->ID == id);    //if found true beacuse it found the element then found will stay true
	}
	else
	{
		found = false;      //else found will be false
	}
	return found;
}

void studentList::Display()     //function to display all data
{
	student* temp;
	temp = first;
	if (temp == NULL)       //if temp = null this means that list doesn't have any elements
	{
		cout << "There is No any Node" << endl;
	}
	else
	{
		while (temp->link != NULL)  //else print data untill reach to dummy node
		{
			cout << temp->name << " " << temp->ID << " " << temp->GPA << endl;
			temp = temp->link;
		}
	}
}

void studentList::Delete(int id)
{
	current = first;    //current node will be first node
	found = false;
	if (first == NULL)  //if first = null it means the list doesn't have any elements in it
	{
		cout << "The list is empty" << endl;
	}
	else
	{
		while (current->link != NULL && !found)
		{                           //else while u didn't reach to the final of list and still didnt found the element

			if (current->ID >= id)  //if found it or greater than it
			{
				found = true;       //then found = true
			}
			else
			{
				beforeCurrent = current;    //else renew current to be the next element and before current to be before it
				current = current->link;
			}
		}
		if (found && (current->ID == id))   //if found it and current id is the same with what we want to delete
		{
			if (current == first)   //if current is first
			{
				first = first->link;    //then first will be the second element
				delete current; //and delete the first one
			}
			else if (current == last)       //if current is the last element
			{
				beforeCurrent->link = dummy;        //then remove it and connect the element before it with dummy
				last = beforeCurrent;
				delete current;
			}
			else
			{
				beforeCurrent->link = current->link;
				delete current;
			}
		}
		else        //else then the element isn't exist
		{
			cout << "this element isn't in the list" << endl;
		}
	}
}
int main()
{
	studentList list;
	student s1("Ahmed", 20190001, 3.4); //test parametrized constructor
	student s2("menna", 20190010, 3.5); //test parametrized constructor
	student s3("yousef", 20190003, 1.4);    //test parametrized constructor
	list.insert(s1);    //test insert function
	list.insert(s2);    //test insert function
	list.insert(s3);    //test insert function
	list.Delete(20190003);  //test delete function
	cout << list.search(20190001) << endl; //test search function
	cout << list.search(20180088) << endl;  //test search function
	list.Display(); //test display function
	return 0;
}


