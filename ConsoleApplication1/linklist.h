#include<iostream>

using namespace std;

class node
{
public:
    string data;
    string num;
    node* next;
};

template <class itemtype>
class singlelink_list
{
    node* head;
	tree  tr;
	int counts;
public:
    singlelink_list()
    {
        head = NULL;
    }
    node* insert_beig(itemtype value, itemtype num1)
    {
		counts++;
        node* temp;
        if (head == NULL)
        {
            temp = new node;
            temp->data = value;
            temp->num = num1;
            temp->next = NULL;
            head = temp;
        }
        else {
            temp = new node;
            temp->data = value;
            temp->num = num1;
            temp->next = head;
            head = temp;
        }
      return temp;

    }
   
	void search(string val) {


		bool flag1 = false;
		node* temp = head;
		
		string ab;
		string abcd;
		while (temp != NULL)
		{

			if ((temp->data == val) || (temp->num == val))
			{
				flag1 = true;
				cout << "CONTACT Found!\n";
				cout << "CONTACT Detalis: \n";

				cout <<"Name:"<< temp->data << "\n";
				cout << "Number" << temp->num << endl;
				
			}


			temp = temp->next;


		}
		if (flag1 == false) {

			cout << "Your Contact is not in the list!" << endl;
		}


		





	}
	void modify(string val,string name,string number) {

		bool flag2 = false;
		node* temp = head;
		
		
		while (temp != NULL)
		{
			
			if ((temp->data == val) || (temp->num == val))
			{
				flag2 = true;
				
				cout << endl;
				temp->data = name;
				temp->num = number;
				
				/*q->data = temp->data;
				q->num = temp->num;*/
				
				break;
			}
			
			
			temp = temp->next;

			
		}
		if (flag2 == false) {

			cout << "Your Contact is not in the list!" << endl;
		}
		


	}

	void delete_it(string n) {

	   deleteNode(head,n);
		

	}
	void deleteNode(node* head, string key)
	{

		// Store head node
		node* temp = head;
		node* prev = NULL;

		// If head node itself holds
		// the key to be deleted
		if (temp != NULL && temp->data == key)
		{
			head = temp->next; // Changed head
			delete temp;            // free old head
			
		}

		// Else Search for the key to be deleted,
		// keep track of the previous node as we
		// need to change 'prev->next' */
		else
		{
			while (temp != NULL && temp->data != key)
			{
				prev = temp;
				temp = temp->next;
			}

			// If key was not present in linked list
			if (temp == NULL) {
				cout << "Name not present in the list" << endl;
				return;
			}

			// Unlink the node from linked list
			prev->next = temp->next;

			// Free memory
			delete temp;
		}
	}
    //search by function
	string call_by_number(string val) {
		string test;
		waqt w;
		bool flag1 = false;
		node* temp = head;

		while (temp != NULL)
		{
			if ((temp->num == val))
			{
				flag1 = true;
				cout << endl << "\nCALL IN PROGRESS :) " << temp->data << "     " << temp->num << "   "; w.get_times(); cout << endl;
				test = temp->data + "      " + temp->num;
			}
			temp = temp->next;
		}
		if (flag1 == false) {

			cout << "Your Contact is not in the list!" << endl;
		}

		return test;
	}

    void del_begin()
    {
        if (head == NULL)
        {
            cout << "NO NODES IN THE LINK";
        }
        else
        {
            node* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
    }
    void delete_all()
    {
        cout << endl;
       for(int i=0;i<counts;i++){

            
            del_begin();
            
        }
    }

    void display()
    {
        node* temp = head;
        while (temp != NULL)
        {
			cout << temp->data << "   " << temp->num << endl;
            
            temp = temp->next;
        }
    }
};