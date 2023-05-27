#pragma once
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include"wtime.h"

using namespace std;
class node1
{

	
public:
	
    string name;
    string num;
    node1* left;
    node1* right;
};
class tree
{
	w_time w;
    node1* root;
public:
    tree() {

         root=NULL;
    }

    
    void make_tree(string n, string num1)
    {
        node1* p = new node1;
        p->name = n;
        p->left = NULL;
        p->right = NULL;
        p->num = num1;

        if (root == NULL)
            root = p;
        else
        {
            insert(p, root);
        }
        

       
    }
    void show() {

        intrav(root);
    }
    /* inserting nodes of a tree */
    void insert(node1* New, node1* root)
    {
        if ((New->name.compare(root->name)) > 0)
        {
            if (root->right == NULL)
                root->right = New;
            else
                insert(New, root->right);
        }
        else if ((New->name.compare(root->name)) < 0)
        {
            if (root->left == NULL)
                root->left = New;
            else
                insert(New, root->left);
        }
        else
        {
            cout << "contact already exists" << endl;
            cout << "Enter Name Again ! ";
            getline(cin, New->name);
            insert(New, root);
        }
    }

    void intrav(node1* tree)
    {
       
        if (tree != NULL)
        {
            intrav(tree->left);
			cout << tree->name << "\t  " << tree->num << endl; 
            intrav(tree->right);
			
        }
    }
	
	void intrav_delete(node1* tree)
	{
		
		if (tree != NULL)
		{
			intrav_delete(tree->left);
			//tree->name << "\t  " << tree->num << endl; 
			intrav_delete(tree->right);

			delete tree;

		}
		root = NULL;
		
	}
	void delete_all()
	{
		if (root == NULL) {
			cout << "There are No contacts in the list" << endl;
		}
		else {
			intrav_delete(root);
		}
		
	}
  
      node1* recursiveSearch_name(node1 * r, string val) {
           
			if (( r==NULL|| r->name == val)) {
				
				return r;

			}
			else if (val.compare(r->name) < 0)
				return recursiveSearch_name(r->left, val);

			else 
				return recursiveSearch_name(r->right, val);
		
        }

	 


	  string search(string n, int p) {

		  string test1;
		  node1* pt1 = NULL;
		  if (p == 1)
		  {

			  pt1 = recursiveSearch_name(root, n);
			  if (pt1 == NULL) {

				  cout << "Contact NOT found!" << endl;
				  return "";
			  }
			  else {
				  cout << endl << "\nCALL IN PROGRESS :) " << pt1->name << "     " << pt1->num << "   "; w.get_times();
				  test1 = pt1->name + "    " + pt1->num;
				  return test1;
			  }
		  }


	  }
	node1* minValueNode(node1 * node) {
		node1* current = node;
		/* loop down to find the leftmost leaf */
		while (current->left != NULL) {
			current = current->left;
		}
		return current;
	}

	void modify_func( string name,string n_name,string no)

	{
		
		deleteNode(root, name);
		
		node1* temp1 = new node1;
		temp1->name = n_name;
		temp1->num = no;
		insert(temp1,root);
	}

	void delete_contact(string s) {

		root=deleteNode(root, s);
		
	}

	node1* deleteNode(node1*  r, string v) {
		// base case 
		if (r == NULL) {
			return NULL;
		}
		// If the key to be deleted is smaller than the root's key, 
		// then it lies in left subtree 
		else if (v < r->name) {
			r->left = deleteNode(r->left, v);
		}
		// If the key to be deleted is greater than the root's key, 
		// then it lies in right subtree 
		else if (v > r->name) {
			r->right = deleteNode(r->right, v);
		}
		// if key is same as root's key, then This is the node to be deleted 
		else {
			// node with only one child or no child 
			if (r->left == NULL) {
				node1* temp = r->right;
				delete r;
				return temp;
			}
			else if (r->right == NULL) {
				node1* temp = r->left;
				delete r;
				return temp;
			}
			else {
				// node with two children: Get the inorder successor (smallest 
				// in the right subtree) 
				node1* temp = minValueNode(r->right);
				// Copy the inorder successor's content to this node 
				r->name = temp->name;
				// Delete the inorder successor 
				r->right = deleteNode(r->right, temp->name);
				//deleteNode(r->right, temp->value); 
			}
		}
		return r;
	}

};



