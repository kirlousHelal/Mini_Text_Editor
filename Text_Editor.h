#pragma once
#include<iostream>
#include <fstream>
using namespace std;

struct node
{
	string data;
	node* next;
};
class Text_Editor
{
	int count;
	node* head;
public:
	Text_Editor();
	void Add_Line(string text);
	void Insert_Line(int line, string text);
	bool IsEmpty();
	string Get_Line(int line);
	void Delete_Line(int line);
	void Update_Line(int line, string text);
	void Clear_File();
	void Clear_Consle();
	void Load_Lines();
	void Save_Lines();
	void  FindAll(string text);
	void Find_ReplaceAll(string t1, string t2);
	void Find_Replace_Line(int index,string t1, string t2);
	void Display();
	~Text_Editor();
};

