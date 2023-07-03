#include <iostream>
#include <fstream>
#include "Text_Editor.h"
#include "Main_Methods.h"
#include <cmath>
#include <string>
using namespace std;



int main()
{
	Text_Editor t;
	
	t.Add_Line("Life is like riding a bicycle , To keep your balance , you must keep moving");
	t.Add_Line("Genius is one percent inspiration , ninety-nine percent perspiration");
	t.Add_Line("All life is an experiment , The more experiments you make the better");
	Main_Methods m;
		m.menu(t);

	return 0;
}

