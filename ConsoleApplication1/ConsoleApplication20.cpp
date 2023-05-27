#include<iostream>
#include<conio.h>
#include<string>
#include<iomanip>
#include<math.h>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include"STACK.h"
#include"linklist.h"
#include"queue.h"
#include"bst.h"
#include"wtime.h"
#include <time.h>   
#include <stdio.h>
#include<windows.h>

using namespace std;

/*
Проект включает в себя различные функции, 
в том числе возможность добавлять, удалять и обновлять контакты, 
а также отображать список последних вызовов. 
Эти функции реализуются с использованием различных структур данных,
таких как очереди, стеки и двоичные деревья поиска.
*/

class mobile_directory
{
private:
	string contactName;
	string contactNumber;
	singlelink_list <string> contactList;
	singlelink_list <string> favoriteContacts;
	node bye;
	Queue recentCalls;
	tree bst;
	stack <string> callStack;
	string searchResult;
	int contactCount = 0;
	int favoriteCount = 0;
	w_time w;
	bool isEmpty = true;

public:
	void setContactInfo()
	{
		system("CLS");
		system("Color 05");
		cout << "Enter details" << endl;
		cin.ignore();
		cout << "ENTER NAME:";
		getline(cin, contactName, '\n');
		cout << endl;
		cout << "ENTER NUMBER:";
		getline(cin, contactNumber);
		cout << endl;

	}

	string getContactName()
	{
		return contactName;
	}
	string getContactNumber()
	{
		return contactNumber;
	}

	void createNewContact()
	{
		system("CLS");
		system("Color 05");
		setContactInfo();
		contactList.insert_beig(contactName, contactNumber);
		bst.make_tree(contactName, contactNumber);
		contactCount++;

		cout << endl << "New Contact Created!" << endl;

		cout << "\nSave As Favourite?(Y/N): ";
		char op;
		cin >> op;
		if (op == 'Y' || op == 'y')
		{
			node* favContact = favoriteContacts.insert_beig(contactName, contactNumber);
			recentCalls.Insert(favContact);
			this->isEmpty = false;
		}
	}

	void displayFavoriteContacts()
	{
		system("CLS");
		system("Color 05");
		if (isEmpty) {

			cout << "No contacts in Favourites" << endl;

		}
		else {
			while (!recentCalls.IsEmpty())
			{
				recentCalls.Remove();
			}
		}
	}

	void displayContacts()
	{
		system("Color 05");
		cout << "Total cotacts are " << contactCount << endl;
		cout << "NAME:" << "\t     " << "NUMBER" << endl;
		bst.show();
	}

	void makeCall()
	{
		system("CLS");
		system("Color 05");
		string contact;
		int option;
		cout << endl << "How do you want to call? ";
		cout << "\n1.By name\n2.By number\n";
		cin >> option;
		string contactDetails;
		switch (option)
		{
		case 1:
			cin.ignore();
			cout << "Enter Name: "; getline(cin, contact);

			contactDetails = bst.search(contact, option);
			callStack.Push(contactDetails);
			break;
		case 2:
			cin.ignore();
			cout << "Enter Number: ";
			getline(cin, contact);
			contactDetails = contactList.call_by_number(contact);
			callStack.Push(contactDetails);

			break;
		default:
			break;
		}

	}

	void searchContacts() {
		system("CLS");
		system("Color 05");
		string searchTerm;
		cout << "Enter name or Number to search: ";
		cin >> searchTerm;
		contactList.search(searchTerm);
	}

	void displayRecentCalls() {
		system("CLS");
		system("Color 05");
		cout << endl << "     Recently contacted list" << endl << endl;
		string contactDetails = "";
		cout << "NAME:" << "\t     " << "NUMBER" << endl;
		while (!callStack.isEmpty()) {

			callStack.Pop(contactDetails);
			cout << contactDetails << endl;
		}
	}

	void updateContact() {

		system("CLS");
		system("Color 05");
		cout << endl;
		cout << "Enter contact name to modify: ";
		cin.ignore();
		string oldName, newName, newNumber;
		getline(cin, oldName);

		cin.ignore();
		cout << "Enter new name: " << endl;
		getline(cin, newName);

		cin.ignore();
		cout << "Enter new number: " << endl;
		getline(cin, newNumber);
		bst.modify_func(oldName, newName, newNumber);
		contactList.modify(oldName, newName, newNumber);
		cout << endl << "Contact Modified!" << endl;
	}

	void deleteContact() {
		system("CLS");
		system("Color 05");
		string contact;
		cout << "Enter contact name to delete: " << endl;
		cin >> contact;
		bst.delete_contact(contact);
		contactList.delete_it(contact);
		cout << "The information of contact " << contact << " has been deleted successfully!" << endl << endl;
		contactCount--;
	}

	void deleteAllContacts()
	{
		system("CLS");
		system("Color 05");
		isEmpty = true;
		bst.delete_all();
		contactList.delete_all();
		contactCount = 0;
	}
};

int main()
{
	int choice;
	char option;
	mobile_directory directory;
	while (1) {

		system("Color 05");
		system("CLS");
		cout << "----------------------Phone Directory---------------------------------" << endl << endl;
		cout << endl << endl << "Please select an option: ";
		cout << endl << "1.Create New Contact" << endl;
		cout << "2.Modify a Contact" << endl;
		cout << "3.Delete a Contact" << endl;
		cout << "4.Display All Contacts" << endl;
		cout << "5.Make a Call" << endl;
		cout << "6.Display Recently Contacted List" << endl;
		cout << "7. Search Contact" << endl;
		cout << "8. To Display Favorite Contact:" << endl;
		cout << "9. To Delete All Contacts" << endl;
		cout << "10. Exit" << endl << endl;
		cout << "Enter Your Option: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			do {
				directory.createNewContact();
				cout << "Do you want to create another contact?(Y/N) : ";
				cin >> option;
			} while (option == 'y');
			break;
		case 2:
			do {
				directory.updateContact();
				cout << "Do you want to modify another contact?(Y/N) : ";
				cin >> option;
			} while (option == 'y');
			break;
		case 3:
			do {
				directory.deleteContact();
				cout << "Do you want to delete another contact?(Y/N) : ";
				cin >> option;
			} while (option == 'y');
			break;
		case 4:
			system("CLS");
			directory.displayContacts();
			_getch();
			break;
		case 5:
			do {
				directory.makeCall();
				cout << "Do you want to make another call?(Y/N) : ";
				cin >> option;
			} while (option == 'y');
			break;
		case 6:
			directory.displayRecentCalls();
			_getch();
			break;
		case 7:
			directory.searchContacts();
			_getch();
			break;
		case 8:
			directory.displayFavoriteContacts();
			_getch();
			break;
		case 9:
			directory.deleteAllContacts();
			_getch();
			break;
		case 10:
			exit(0);
			break;
		default:
			break;
		}
	}

	_getch();
	return 0;
}
