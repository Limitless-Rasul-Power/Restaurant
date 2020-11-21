#include <iostream>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "Restaurant.h"

using namespace std;

unsigned short Restaurant::rn_number = 0;

int main()
{
	srand(unsigned short(time(NULL)));

	Employee* e1 = new Employee("Mike", "Johnson", Cook, 22, 4, 3);
	Employee* e2 = new Employee("Tom", "Wolfgan", Server, 24, 5, 4);
	Employee* e3 = new Employee("Tiffany", "Elband", General_Manager, 21, 3, 5);

	Employee** all_e = new Employee * [3]{ e1, e2, e3 };


	Menu* m1 = new Menu("Orange Juice", 9.99f, "Healty Life", 5.60, 10);
	Menu* m2 = new Menu("Sezar Salad", 10.0f, "Healty Life Salad", 15, 20);
	Menu* m3 = new Menu("Greek Salad", 3.2f, "National Dish of Greece", 10, 30);
	Menu* m4 = new Menu("Fish Tacos", 10.0f, "Mexico Healthy food", 15, 15);
	Menu* m5 = new Menu("Green Papaya Salad", 4.8f, "Healthy food", 15, 19);
	Menu* m6 = new Menu("Salmon Fish", 9.99f, "Mental Healthy food", 20, 50);

	Menu** meals = new Menu * [5]{ m1, m2, m3, m4, m5 };

	Restaurant place("1 Day All Life", "Mexico", 994777476666, 10, meals, 5, all_e, 3);	

	Employee* e4 = new Employee("Edward", "Guetta", Bartender, 19, 7, 4);
	
	enum Choice
	{
		Add_Meal, Add_Employee, Delete_Meal, Delete_Employee, Update_Menu, Show_All_Menu, Show_All_Employee,
		Show_All_Restaurant_Information, Exit
	};

	const unsigned short menu_size = 9;
	string menu[menu_size] = { "Add Meal", "Add Employee", "Delete Meal", "Delete Employee", "Update Meal", "Show All Menu",
	"Show All Employee", "Show All Restaurant Information", "Exit" };

	int option = 0;

	
	CONSOLE_CURSOR_INFO cursor_info{};
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
	cursor_info.bVisible = false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);

	COORD coordinate_position = { 47, 10 };

	CONSOLE_FONT_INFOEX console_font{};
	console_font.cbSize = sizeof(console_font);
	console_font.nFont = 0;
	console_font.dwFontSize.X = 0;
	console_font.dwFontSize.Y = 20;
	console_font.FontFamily = FF_MODERN;
	console_font.FontWeight = FW_EXTRALIGHT;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &console_font);
	
	while (true)
	{
		short choice{};
		while (true)
		{
			system("CLS");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { coordinate_position.X -5, coordinate_position.Y});
			cout << "Restaurant: " << place.Get_name() << endl;
			coordinate_position.Y += 2;

			for (unsigned short i = 0; i < menu_size; i++)
			{
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate_position);
				if (option == i)
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), PINK);
				else
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
				cout << menu[i] << endl;
				++coordinate_position.Y;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			coordinate_position.Y -= 11;
			choice = _getch();

			switch (choice)
			{
			case UP:
				if (option == 0)
					option = 8;
				else
					--option;
				break;
			case DOWN:
				if (option == 8)
					option = 0;
				else
					++option;
				break;
			}

			if (choice == ENTER)
				break;
		}

		
		system("CLS");

		switch (option)
		{
		case Add_Meal:
		{
			short number{};
			cout << "How Many Meal Do You Want To Add: "; 
			cin >> number;

			while (number <= 0)
			{
				cout << "You Must Add at Least 1 Meal!\nEnter: ";
				cin >> number;
			}

			cin.ignore(1, '\n');

			for (unsigned short i = 0; i < (unsigned short)number; i++)
				cin >> place;
		}
			break;
		case Add_Employee:
		{
			short number{};
			cout << "How Many Employee Do You Want To Add: ";
			cin >> number;

			while (number <= 0)
			{
				cout << "You Must Add at Least 1 Employee!\nEnter: ";
				cin >> number;
			}

			cin.ignore(1, '\n');

			for (unsigned short i = 0; i < (unsigned short)number; i++)
			{
				Employee* new_employee = new Employee{};
				cin >> *new_employee;
				place.Add_employee(new_employee);
			}
		}
			break;
		case Delete_Meal:
		{
			cout << "Meal IDs' Are: ";
			for (unsigned short i = 0; i < place.Get_maximum_count(); i++)
				cout << place.Get_meals()[i]->Get_id() << " ";

			cout << "\n";
			int ID{};
			cout << "Which ID Do You Want Delete(Meal): ";
			cin >> ID;

			place.Delete_meal(ID);
		}
			break;
		case Delete_Employee:
		{
			cout << "Employee IDs' Are: ";
			for (unsigned short i = 0; i < place.Get_maximum_count(); i++)
				cout << place.Get_workers()[i]->Get_id() << " ";

			cout << "\n";
			int ID{};
			cout << "Which ID Do You Want Delete(Employee): ";
			cin >> ID;

			place.Delete_employee(ID);
		}
			break;
		case Update_Menu:
		{
			cout << "Meal IDs' Are: ";
			for (unsigned short i = 0; i < place.Get_maximum_count(); i++)
				cout << place.Get_meals()[i]->Get_id() << " ";

			cout << "\n";
			int ID{};
			cout << "Which ID Do You Want Upfate(Meal): ";
			cin >> ID;
			
			place.Update_meal(ID);
		}			
			break;
		case Show_All_Menu:
		{
			cout << "Restaurant Meal(s)\n\n";
			Bubble_sort_for_meals(place);
			Print_meals(place);
			system("pause");
		}
			break;
		case Show_All_Employee:
			cout << "Restaurant Employee(s)\n";
			Bubble_sort_for_employees(place);
			Print_employees(place);			
			system("pause");
			break;
		case Show_All_Restaurant_Information:			
			Bubble_sort_for_meals(place);
			Bubble_sort_for_employees(place);
			cout << place;
			system("pause");
			break;
		case Exit:
			cout << "Thank You for Visiting, Bye-Bye\n";
			return 0;
		default:
			cout << "Choose One Of This Choices!!!\n";
		}

	}

	system("pause");
	return 0;
}