// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node
{
public:
	int roll;
	string Name;
	string Dept;
	int Marks;
	Node *next;
};

// Stores the head of the Linked List
Node *head = new Node();

// Check Function to check that if
// Record Already Exist or Not
bool check(int x)
{
	// Base Case
	if (head == NULL)
		return false;

	Node *t = new Node;
	t = head;

	// Traverse the Linked List
	while (t != NULL)
	{
		if (t->roll == x)
			return true;
		t = t->next;
	}

	return false;
}

// Function to insert the record
void Insert_Record(int roll, string Name,
				   string Dept, int Marks)
{
	// if Record Already Exist
	if (check(roll))
	{
		cout << "Student with this "
			 << "record Already Exists\n";
		return;
	}

	// Create new Node to Insert Record
	Node *t = new Node();
	t->roll = roll;
	t->Name = Name;
	t->Dept = Dept;
	t->Marks = Marks;
	t->next = NULL;

	// Insert at Begin
	if (head == NULL || (head->roll >= t->roll))
	{
		t->next = head;
		head = t;
	}

	// Insert at middle or End
	else
	{
		Node *c = head;
		while (c->next != NULL && c->next->roll < t->roll)
		{
			c = c->next;
		}
		t->next = c->next;
		c->next = t;
	}

	cout << "Record Inserted "
		 << "Successfully\n";
}

// Function to search record for any
// students Record with roll number
void Search_Record(int roll)
{
	// if head is NULL
	if (!head)
	{
		cout << "No such Record "
			 << "Avialable\n";
		return;
	}

	// Otherwise
	else
	{
		Node *p = head;
		while (p)
		{
			if (p->roll == roll)
			{
				cout << "Roll Nmuber\t"
					 << p->roll << endl;
				cout << "Name\t\t"
					 << p->Name << endl;
				cout << "Department\t"
					 << p->Dept << endl;
				cout << "Marks\t\t"
					 << p->Marks << endl;
				return;
			}
			p = p->next;
		}

		if (p == NULL)
			cout << "No such Record "
				 << "Avialable\n";
	}
}

// Function to delete record students
// record with given roll number
// if it exist
int Delete_Record(int roll)
{
	Node *t = head;
	Node *p = NULL;

	// Deletion at Begin
	if (t != NULL && t->roll == roll)
	{
		head = t->next;
		delete t;

		cout << "Record Deleted "
			 << "Successfully\n";
		return 0;
	}

	// Deletion Other than Begin
	while (t != NULL && t->roll != roll)
	{
		p = t;
		t = t->next;
	}
	if (t == NULL)
	{
		cout << "Record does not Exist\n";
		return -1;
		p->next = t->next;

		delete t;
		cout << "Record Deleted "
			 << "Successfully\n";

		return 0;
	}
}

// Function to display the Student's
// Record
void Show_Record()
{
	Node *p = head;
	if (p == NULL)
	{
		cout << "No Record "
			 << "Available\n";
	}
	else
	{
		cout << "ROLL\tNAME\tCOURSE"
			 << "\tMarks\n";

		// Until p is not NULL
		while (p != NULL)
		{
			cout << p->roll << " \t"
				 << p->Name << "\t"
				 << p->Dept << "\t"
				 << p->Marks << endl;
			p = p->next;
		}
	}
}
void intro()
{
	cout<<"\n\n\n\t                                         DATA STRUCTURE USING C++ ";
	cout<<"\n\n\t                                  STUDENT RECORD MANAGEMENT SYSTEM PROJECT";
	cout<<"\n\n                                      Centurion University Of Technology And Management";
	cout<<"\n\n\n\n\t\t\t\t       MADE BY : Rakesh Sharma------>190301120079 \n ";
	cout<<"\n\n                                                                                     Press Enter to Continue---->";
	cin.get();
}
// Driver code
int main()
{
	head = NULL;
	string Name, Course;
	int Roll, Marks;
	char Choice;
	intro();
	system("cls");
	// Menu-driven program
	do
	{
		cout << "\n\t\tWelcome to Student Record "
				"Management System\n\n\tPRESS\n\t1 To "
				"Create a New Record\n\t2 To Delete an Existing "
				"Student Record\n\t3 To Search an Existing Student "
				"Record\n\t4 To View all Existing Students "
				"record\n\t5 To Exit\n";
		cout << "\n Please Enter Your Choice : ";
		cin >> Choice;
		system("cls");
		switch (Choice)
		{
		case '1':
			cout << "Enter Name of Student : ";
			cin >> Name;
			cout << "Enter Roll Number of Student : ";
			cin >> Roll;
			cout << "Enter Course of Student : ";
			cin >> Course;
			cout << "Enter Total Marks of Student : ";
			cin >> Marks;
			Insert_Record(Roll, Name, Course, Marks);
			break;

		case '2':
			cout << "Enter Roll Number of Student whose "
					"record is to be deleted : ";
			cin >> Roll;
			Delete_Record(Roll);
			break;

		case '3':
			cout << "Enter Roll Number of Student whose "
					"record you want to Search : ";
			cin >> Roll;
			Search_Record(Roll);
			break;

		case '4':
			Show_Record();
			break;

		case '5':
			exit(0);
			break;

		default:
			cout << "Invalid Choice "
				 << "Try Again\n";
		}

	} while (Choice != '5');
	return 0;
}
