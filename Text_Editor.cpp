#include "Text_Editor.h"
#include<iostream>
#include <string>
#include<fstream>
using namespace std;
	
Text_Editor::Text_Editor()
{
		head = NULL;
		count = 0;
}

void Text_Editor::Add_Line(string text)
{
	ofstream output("default.txt",ios::app);  
	node* newNode=new node, * last;
	newNode->data = text;
	output << text << endl;
	if (head == NULL)
	{
		head = newNode;
		newNode->next = NULL;
	}
	else
	{
		last = head;
		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = newNode;
		newNode->next = NULL;
	}
	count++;
	cout << "The Add Line Operation Done Successfully....\n";
	output.close();
}

void Text_Editor::Insert_Line(int index, string text)
{
	index-=1;
	if (IsEmpty()|| index>=count)
	{
		Add_Line(text);
	}
	else
	{
	    node* newNode=new node,*temp,*ptr;
			 newNode->data = text;
		if (index == 0)
		{
			newNode->next = head;
			head = newNode;
		}
		else
		{
			 temp = head;
			 for (int i = 0; i < index; i++)
			 {
				 temp = temp->next;
			 }	
			 newNode->next = temp;
			 ptr=head;
			 for (int i = 0; i < index-1; i++)
			 {
				 ptr = ptr->next;
			 }
			 ptr->next = newNode;
		}
		count++;
		cout << "The Insert Line Operation Done Successfully....\n";

		ofstream output("default.txt");
		node* a = head;
		for (int i = 0; i < count; i++)
		{
			output << a->data << endl;
			a = a->next;
		}
		output.close();
	}

}

bool Text_Editor::IsEmpty()
{
	return (count == 0);
}



string Text_Editor::Get_Line(int index)
{
	index -= 1;
	node*temp;
	temp = head;
	for (int i = 0; i <index; i++)
	{
		temp = temp->next;
	}
	
	if (IsEmpty())
	{
		cout << "Get Line is Invaild, This Text Editor is Empty\n";
		return temp->data;
	}
	else if (index >= count)
	{
		cout << "Get Line is Invaild, The Index You Entered Not Found\n";
		return temp->data;
	}
	else
	{
		return temp->data;
	}

}

void Text_Editor::Delete_Line(int index)
{
	index -= 1;
	node *temp,*ptr;
	if (IsEmpty())
		cout << "Delete Line is Invaild, This Text Editor Already is Empty\n";
	else if	(index>=count)
		cout << "Delete Line is Invaild, The Index You Entered Not Found\n";
	else if (index == 0)
	{
		node *a=head;
		head = head->next;
		delete a;
		count--;
	}
	else
	{
		temp = head;
		for (int i = 0; i < index; i++)
		{
			temp = temp->next;
		}

		ptr = head;
		for (int i = 0; i < index-1; i++)
		{
			ptr = ptr->next;
		}

		ptr->next = temp->next;
		delete temp;
		cout << "The Delete Line Operation Done Successfully....\n";
		count--;
		ofstream output("default.txt");
		node* a = head;
		for (int i = 0; i < count; i++)
		{
			output << a->data << endl;
			a = a->next;
		}
		output.close();
	}
}

void Text_Editor::Update_Line(int index, string text)
{
	index -= 1;
	if(IsEmpty())
		cout << "Update Line is Invaild, This Text Editor is Empty\n";
	else if (index >= count)
		cout << "Delete Line is Invaild, The Index You Entered Not Found\n";
	else
	{
		node* temp;

		temp = head;
		for (int i = 0; i < index; i++)
		{
			temp = temp->next;
		}

		temp->data = text;
		cout << "The Update Line Operation Done Successfully....\n";
		cout << "Your Line After The Update :  ";
		string result = Get_Line(index+1);
		cout << "Your Line is \" " << result << " \"...\n";
		ofstream output("default.txt");
		node* a = head;
		for (int i = 0; i < count; i++)
		{
			output << a->data << endl;
			a = a->next;
		}
		output.close();
	}
}

void Text_Editor::Clear_File()
{
	string s;
	cout << "Hint 1: To Clear Your All Data From a Specific Path Write It Like This Signature: E:\\Visual studio\\Mini Text Editor\\FileName.txt\n";
	cout << "Hint 2: To Clear Your All Data From The default Path Write It Like This Signature: FileName.txt\n\n";
	cout << "\nPlease Write Your Path Here:	";
	getline(cin >> ws, s);
	ifstream input(s);
	if (input.fail())
		cerr << "This File Not Found...\n";
	else
	{
		ofstream output(s);
		output.clear();
		cout << "Hint : There is a BackUp For Your Data IF You Want To Restore From This File: Defult.txt \n\n";
		cout << "\n\Clearing Data Done Successfully....\n\n";
		output.close();
	}
	input.close();
}

void Text_Editor::Clear_Consle()
{
	int c = 0,a=count;
	for (int i = a; i > 0; i--)
	{
		Delete_Line(i);
		c++;
	}
	cout << "\n\Clearing Data Done Successfully....(\" The Number of Lines Removed = " << c << " \")\n\n";
}

void Text_Editor::Load_Lines()
{
	string e; int c = 0;
	cout << "Hint 1: To Load Your Data From a Specific Path Write It Like This Signature: E:\\Visual studio\\Mini Text Editor\\FileName.txt\n";
	cout << "Hint 2: To Load Your Data From The default Path Write It Like This Signature: FileName.txt\n\n";
	cout << "\nPlease Write Your Path Here:	";
	getline(cin >> ws, e);
	ifstream input(e);
	string s; 
	if (input.fail())
	{
		cerr << "This File Not Found...\n";
	}
	else
	{
		while (!input.eof())
		{
			getline(input, s);
			cout << s << endl;
			//Add_Line(s);

			node* newNode = new node, * last;
			newNode->data = s;
			if (head == NULL)
			{
				head = newNode;
				newNode->next = NULL;
			}
			else
			{
				last = head;
				while (last->next != NULL)
				{
					last = last->next;
				}
				last->next = newNode;
				newNode->next = NULL;
			}
			count++;
			c++;
			cout << "The Add Line Operation Done Successfully....\n";
		}
		node* temp = head; node* ptr = head;
		for (int i = 0; i < count-1; i++)
		{
			temp = temp->next;
		}
		for (int i = 0; i < count-2; i++)
		{
			ptr = ptr->next;
		}
		ptr->next = temp->next;
		delete temp;
		count--;
		c--;
		cout << "\n\nLoading Data Done Successfully....(\" The Number of Lines Uploaded = " << c << " \")\n\n";
	}
	input.close();
}

void Text_Editor::Save_Lines()
{
	string s; int c = 0;
	cout << "Hint 1: To Save Your Data In a Specific Path Write It Like This Signature: E:\\Visual studio\\Mini Text Editor\\FileName.txt\n";
	cout << "Hint 2: To Save Your Data In The default Path Write It Like This Signature: FileName.txt\n\n";
	cout << "\nPlease Write Your Path Here:	";
	getline(cin >> ws, s);
	ofstream output(s,ios::app);
		node* a = head;
		for (int i = 0; i < count; i++)
		{
			output << a->data << endl;
			a = a->next;
			c++;
		}
		cout << "\n\Saving Data Done Successfully....(\" The Number of Lines Saved = " << c << " \")\n\n";
	output.close();
}

void  Text_Editor::FindAll(string text)
{
	int* arr = new int[count];

	node* temp=head;
	for (int i = 0; i < count; i++)
	{
		if (temp->data.find(text) != string::npos )
		{
			if((temp->data.find(text)==0) && (temp->data[temp->data.find(text) + text.length()-1] == temp->data[temp->data.length() - 1]))
				arr[i] = i;	  
			else if(((temp->data.find(text)==0) && (temp->data[temp->data.find(text) + text.length()] ==' ')))
				arr[i] = i;
			else if((temp->data[temp->data.find(text) - 1] == ' ') && (temp->data[temp->data.find(text) + text.length()] == ' '))
				arr[i] = i;
			else if((temp->data[temp->data.find(text) - 1] == ' ') &&(temp->data[temp->data.find(text) + text.length() - 1] == temp->data[temp->data.length() - 1]))
				arr[i] = i;
		}
			temp = temp->next;
	}
	cout << endl;
	cout << "The All Numbers Of The Lines That Contains This Text \"" << text << "\" :\n\n";
	bool check = false; int c = 0;
	temp = head;
	for (int i = 0; i < count; i++)
	{
		if (temp->data.find(text) != string::npos )
		{
			if ((temp->data.find(text) == 0) && (temp->data[temp->data.find(text) + text.length() - 1] == temp->data[temp->data.length() - 1]))
			{
				cout << " The Index= " << arr[i] + 1 << "\t,The line is \"" << temp->data << "\"\n";
				check = true;
				c++;
			}
			else if (((temp->data.find(text) == 0) && (temp->data[temp->data.find(text) + text.length()] == ' ')))
			{
				cout <<" The Index= "<< arr[i] + 1 << "\t,The line is \"" << temp->data << "\"\n";
				check = true;
				c++;
			}
			else if ((temp->data[temp->data.find(text) - 1] == ' ') && (temp->data[temp->data.find(text) + text.length()] == ' '))
			{
				cout << " The Index= " << arr[i] + 1 << "\t,The line is \"" << temp->data << "\"\n";
				check = true;
				c++;
			}
			else if ((temp->data[temp->data.find(text) - 1] == ' ') && (temp->data[temp->data.find(text) + text.length() - 1] == temp->data[temp->data.length() - 1]))
			{
				cout << " The Index= " << arr[i] + 1 << "\t,The line is \"" << temp->data << "\"\n";
				check = true;
				c++;
			}
		}
		temp = temp->next;
	}
	if (!check)
	{
		cout << " Find All Lines is Invaild, There's Nothing matches here..." << endl;
	}
	else
	{
		cout << "\n\Find All Data Done Successfully....(\" The Number of Lines Was Finded = " << c << " \")\n\n";
	}
}

void Text_Editor::Find_ReplaceAll(string t1, string t2)
{
	node* temp = head;
	bool check = false,ch=false; int c = 0;
	cout << "The Replace Of The Texts That Contains This Text \"" << t2 << "\" to \"" << t1 << "\" :" << endl;
	for (int i = 0; i < count; i++)
	{
	   for (int j = 0; j < temp->data.length(); j++)
		if (temp->data.find(t2) != string::npos )
		{
			if ((temp->data.find(t2) == 0) && (temp->data[temp->data.find(t2) + t2.length() - 1] == temp->data[temp->data.length() - 1]))
			{
				temp->data.replace(temp->data.find(t2), t2.length(), t1);
				check = true;
				ch = true;
			}
			else if (((temp->data.find(t2) == 0) && (temp->data[temp->data.find(t2) + t2.length()] == ' ')))
			{
				temp->data.replace(temp->data.find(t2), t2.length(), t1);
				check = true;
				ch = true;
			}
			else if((temp->data[temp->data.find(t2) - 1] == ' ') && (temp->data[temp->data.find(t2) + t2.length()] == ' '))
			{
				temp->data.replace(temp->data.find(t2), t2.length(), t1);
				check = true;
				ch = true;
			}
			else if ((temp->data[temp->data.find(t2) - 1] == ' ') && (temp->data[temp->data.find(t2) + t2.length() - 1] == temp->data[temp->data.length() - 1]))
			{
				temp->data.replace(temp->data.find(t2), t2.length(), t1);
				check = true;
				ch = true;
			}
		}
		if (ch)
		{
			c++;
			cout << temp->data << endl;
		}
		temp = temp->next;
		ch = false;
	}
	if (check)
	{
		cout << "\n\Find And Replace Data Done Successfully....(\" The Number of Lines Was Replaced = " << c << " \")\n\n";
	}
	else
	{
		cout << "\n Find And Replace Lines is Invaild, The Old Text You Enterd Dosen't Exist...\n" << endl;	
	}
}

void Text_Editor::Find_Replace_Line(int index,string t1, string t2)
{
	index--;
	node* temp = head;
	bool check = false;
	if (IsEmpty())
		cout << "Find And Replace One Line is Invaild, This Text Editor Already is Empty\n";
	else if (index >= count)
		cout << "Find And Replace One Line is Invaild, The Index You Entered Not Found\n";
	else
	{
		cout << "The Replace Of The Texts That Contains This Text \"" << t2 << "\" to \"" << t1 << "\" :" << endl;
		for (int i = 0; i < index; i++)
		{
			temp = temp->next;
		}
		for (int j = 0; j < temp->data.length(); j++)
			if (temp->data.find(t2) != string::npos)
			{
				if ((temp->data.find(t2) == 0) && (temp->data[temp->data.find(t2) + t2.length() - 1] == temp->data[temp->data.length() - 1]))
				{
					temp->data.replace(temp->data.find(t2), t2.length(), t1);
					check = true;
				}
				else if (((temp->data.find(t2) == 0) && (temp->data[temp->data.find(t2) + t2.length()] == ' ')))
				{
					temp->data.replace(temp->data.find(t2), t2.length(), t1);
					check = true;
				}
				else if ((temp->data[temp->data.find(t2) - 1] == ' ') && (temp->data[temp->data.find(t2) + t2.length()] == ' '))
				{
					temp->data.replace(temp->data.find(t2), t2.length(), t1);
					check = true;
				}
				else if ((temp->data[temp->data.find(t2) - 1] == ' ') && (temp->data[temp->data.find(t2) + t2.length() - 1] == temp->data[temp->data.length() - 1]))
				{
					temp->data.replace(temp->data.find(t2), t2.length(), t1);
					check = true;
				}
			}
		if (check)
		{
			cout << "\nYour Line After The Replacement: \" " << temp->data << " \"\n\n";
			cout << "\n\Find And Replace Data Done Successfully....\n\n";
		}
		else
		{
			cout << "\n Find And Replace Lines is Invaild, The Old Text You Enterd Dosen't Exist...\n" << endl;
		}
	}
}
void Text_Editor::Display()
{
	node* temp = head; 
	for (int i = 0; i<count; i++)
	{
		cout << temp->data << endl;
		temp =temp->next;
	}
	cout << "\n\Displaying Data Done Successfully....(\" The Number of Lines Displayed = " << count << " \")\n\n";
	cout << endl;
}

Text_Editor::~Text_Editor()
{
	node* temp;
	while (!IsEmpty())
	{
		temp = head;
	   for (int i = 0; i < count-1; i++)
	   {
		   temp = temp->next;
	   }
	   delete temp;
	   count--;
	}

}
