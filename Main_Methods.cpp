#include "Main_Methods.h"
void Main_Methods::Add(Text_Editor t)
{
	system("cls");
	cout << "------------------------------------------------------------------------------------------------------------------------\n\n";
	cout << "\t\t\t\t\t\t   Add Line Operation\n\n";
	cout << "------------------------------------------------------------------------------------------------------------------------\n\n";
	string s;
	cout << "Please Add Your Line Here: ";
	getline(cin >> ws, s);
	t.Add_Line(s);

	customization(t);
}
void Main_Methods::Insert(Text_Editor t)
{
	system("cls");
	cout << "------------------------------------------------------------------------------------------------------------------------\n\n";
	cout << "\t\t\t\t\t\t   Insert Line Operation\n\n";
	cout << "------------------------------------------------------------------------------------------------------------------------\n\n";
	int x; string s1;
	cout << "Please To Insert Your Line Write Your Index Here: ";
	cin >> x;
	cout << "Please To Insert Your Line Write Your Text Here: ";
	//cin.ignore();
	getline(cin >> ws, s1);
	t.Insert_Line(x, s1);

	customization(t);
}
void Main_Methods::Update(Text_Editor t)
{
	system("cls");
	cout << "------------------------------------------------------------------------------------------------------------------------\n\n";
	cout << "\t\t\t\t\t\t   Update Line Operation\n\n";
	cout << "------------------------------------------------------------------------------------------------------------------------\n\n";
	int c; string s2;
	cout << "Please To Update Your Line Write Your Index Here: ";
	cin >> c;
	cout << "Please To Update Your Line Write Your Text Here: ";
	//cin.ignore();
	getline(cin >> ws, s2);
	t.Update_Line(c, s2);

	customization(t);

}
void Main_Methods::Get(Text_Editor t)
{
	system("cls");
	cout << "------------------------------------------------------------------------------------------------------------------------\n\n";
	cout << "\t\t\t\t\t\t   Get Line Operation\n\n";
	cout << "------------------------------------------------------------------------------------------------------------------------\n\n";
	int z;
	cout << "Please To Get Your Line Write Your Index Here: ";
	cin >> z;
	string result = t.Get_Line(z);
	cout << "Your Line is \" " << result << " \"...\n";

	customization(t);
}
void Main_Methods::Delete(Text_Editor t)
{
	system("cls");
	cout << "------------------------------------------------------------------------------------------------------------------------\n\n";
	cout << "\t\t\t\t\t\t   Delte Line Operation\n\n";
	cout << "------------------------------------------------------------------------------------------------------------------------\n\n";
	int v;
	cout << "Please To Delete Your Line Write Your Index Here: ";
	cin >> v;
	t.Delete_Line(v);

	customization(t);
}
void Main_Methods::FindAll(Text_Editor t)
{
	system("cls");
	cout << "------------------------------------------------------------------------------------------------------------------------\n\n";
	cout << "\t\t\t\t\t\t   Find All Texts Operation\n\n";
	cout << "------------------------------------------------------------------------------------------------------------------------\n\n";
	string text;
	cout << "To Find Your Text in All Indexs Please Write Your Text Here: ";
	//cin.ignore();
	getline(cin >> ws, text);
	t.FindAll(text);

	customization(t);
}
void Main_Methods::FindReplaceAll(Text_Editor t)
{
	system("cls");
	cout << "------------------------------------------------------------------------------------------------------------------------\n\n";
	cout << "\t\t\t\t\t\t Find and Replace Text in All Lines Operation\n\n";
	cout << "------------------------------------------------------------------------------------------------------------------------\n\n";
	string t1, t2;

	cout << endl;
	cout << "Please Enter Your Old Text Here: ";
	getline(cin >> ws, t2);
	cout << "Please Enter Your New Text Here: ";
	getline(cin >> ws, t1);
	t.Find_ReplaceAll(t1, t2);

	customization(t);
}
void Main_Methods::FindReplaceLine(Text_Editor t)
{
	system("cls");
	cout << "------------------------------------------------------------------------------------------------------------------------\n\n";
	cout << "\t\t\t\t\t\t Find and Replace Text in One Line Operation\n\n";
	cout << "------------------------------------------------------------------------------------------------------------------------\n\n";
	int x; string t1, t2;

	cout << "Please To Find And Replace a Text in Your Line Write Your Index Here: ";
	cin >> x;
	cout << "Please Enter Your Old Text Here: ";
	getline(cin >> ws, t2);
	cout << "Please Enter Your New Text Here: ";
	getline(cin >> ws, t1);
	t.Find_Replace_Line(x, t1, t2);

	customization(t);
}
void Main_Methods::Display(Text_Editor t)
{
	system("cls");
	cout << "------------------------------------------------------------------------------------------------------------------------\n\n";
	cout << "\t\t\t\t\t\t   Display All Lines Operation\n\n";
	cout << "------------------------------------------------------------------------------------------------------------------------\n\n";
	t.Display();
	customization(t);
}
void Main_Methods::Load(Text_Editor t)
{
	system("cls");
	cout << "------------------------------------------------------------------------------------------------------------------------\n\n";
	cout << "\t\t\t\t\t\t   Load All Lines Operation\n\n";
	cout << "------------------------------------------------------------------------------------------------------------------------\n\n";
	t.Load_Lines();

	customization(t);
}
void Main_Methods::Save(Text_Editor t)
{
	system("cls");
	cout << "------------------------------------------------------------------------------------------------------------------------\n\n";
	cout << "\t\t\t\t\t    Save All Lines Operation\n\n";
	cout << "------------------------------------------------------------------------------------------------------------------------\n\n";
	t.Save_Lines();

	customization(t);
}
void Main_Methods::ClearConsle(Text_Editor t)
{
	system("cls");
	cout << "------------------------------------------------------------------------------------------------------------------------\n\n";
	cout << "\t\t\t\t\t    Clear All Data From The Consle\n\n";
	cout << "------------------------------------------------------------------------------------------------------------------------\n\n";
	t.Clear_Consle();
	customization(t);
}
void Main_Methods::ClearFile(Text_Editor t)
{
	system("cls");
	cout << "------------------------------------------------------------------------------------------------------------------------\n\n";
	cout << "\t\t\t\t\t    Clear All Data From The File\n\n";
	cout << "------------------------------------------------------------------------------------------------------------------------\n\n";
	t.Clear_File();
	customization(t);
}
void Main_Methods::menu(Text_Editor t)
{
	system("cls");
	int x;
	cout << "------------------------------------------------------------------------------------------------------------------------\n\n";
	cout << "\t\t\t\t\t      Welcome To Mini Tex Editor\n\n";
	cout << "------------------------------------------------------------------------------------------------------------------------\n\n";
	cout << "1. To Add a line \n";
	cout << "2. To Insert a line \n";
	cout << "3. To get Your Line By Index \n";
	cout << "4. To Update a line By Index \n";
	cout << "5. To Delete Your line By Index \n";
	cout << "6. To Find Your Text in All Lines And Display The Indexs \n";
	cout << "7. To Find Your Text And Replace it in All Lines\n";
	cout << "8. To Find Your Text And Replace it in One Line\n";
	cout << "9. To Display Your All Lines\n";
	cout << "10. To Load Your All Lines You Enterd Before\n";
	cout << "11. To Save Your All Lines You Enterd\n";
	cout << "12. To Clear Your All Data From The Consle\n";
	cout << "13. To Clear Your All Data From The File\n";
	cout << endl;
	cout << "Please Choose Your Number From The Previous Options: ";
	cin >> x;
	switch (x)
	{
	case 1:
		Add(t);	break;
	case 2:
		Insert(t);	  break;
	case 3:
		Get(t); break;
	case 4:
		Update(t); break;
	case 5:
		Delete(t); break;
	case 6:
		FindAll(t);
	case 7:
		FindReplaceAll(t);	 break;
	case 8:
		FindReplaceLine(t);	 break;
	case 9:
		Display(t);	 break;
	case 10:
		Load(t);
		break;
	case 11:
		Save(t);
		break;
	case 12:
		ClearConsle(t);
		break;
	case 13:
		ClearFile(t);
		break;
	default:
		exit(0);
		break;
	}
}
void Main_Methods::customization(Text_Editor t)
{
	cout << endl;
	int i;
	cout << " 1. To Back To The Main Menu...\n";
	cout << " 2. To Exit From The Application...\n";
	cout << endl;
	cout << "Please Choose Your Number From The Previous Options: ";
	cin >> i;
	switch (i)
	{
	case 1:
		menu(t); break;
	case 2:
		exit(0); break;
	default:
		exit(0);
		break;
	}
}
