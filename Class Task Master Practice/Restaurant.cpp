#include <iostream>
#include <string.h>
#include <assert.h>
#include <windows.h>
#include "Restaurant.h"

Restaurant::Restaurant() :restoran_no(0), name(nullptr), address(nullptr), phone_number(0), rating(0.0), average_cost(0.0),
max_menu_count(0), meals(nullptr), workers(nullptr), max_employee_count(0)
{}

Restaurant::Restaurant(const Restaurant& other)
{
	Set_current_number(other.restoran_no);
	Set_name(other.name);
	Set_address(other.address);
	Set_phone_number(other.phone_number);
	Set_rating(other.rating);
	Set_max_menu_count(other.max_menu_count);
	Set_current_cost(other);
	Set_meals(other.meals);
}

Restaurant& Restaurant::operator = (const Restaurant& other)
{
	Set_current_number(other.restoran_no);
	Set_name(other.name);
	Set_address(other.address);
	Set_phone_number(other.phone_number);
	Set_rating(other.rating);
	Set_max_menu_count(other.max_menu_count);
	Set_current_cost(other);
	Set_meals(other.meals);

	return *this;
}

Restaurant::Restaurant(Restaurant&& restaurant) noexcept
{
	this->meals = restaurant.meals;
	this->name = restaurant.name;
	this->address = restaurant.address;
	this->max_menu_count = restaurant.max_menu_count;
	this->phone_number = restaurant.phone_number;
	this->rating = restaurant.rating;
	this->restoran_no = restaurant.restoran_no;
	this->average_cost = restaurant.average_cost;
	this->workers = restaurant.workers;
	this->max_employee_count = restaurant.max_employee_count;

	restaurant.meals = nullptr;
	restaurant.name = nullptr;
	restaurant.address = nullptr;
	restaurant.max_menu_count = 0;
	restaurant.phone_number = 0;
	restaurant.rating = 0;
	restaurant.restoran_no = 0;
	restaurant.average_cost = 0;
	restaurant.workers = nullptr;
	restaurant.max_employee_count = 0;
}

Restaurant& Restaurant::operator = (Restaurant&& restaurant) noexcept
{
	if (this != &restaurant)
	{
		this->~Restaurant();

		this->meals = restaurant.meals;
		this->name = restaurant.name;
		this->address = restaurant.address;
		this->max_menu_count = restaurant.max_menu_count;
		this->phone_number = restaurant.phone_number;
		this->rating = restaurant.rating;
		this->restoran_no = restaurant.restoran_no;
		this->average_cost = restaurant.average_cost;

		restaurant.meals = nullptr;
		restaurant.name = nullptr;
		restaurant.address = nullptr;
		restaurant.max_menu_count = 0;
		restaurant.phone_number = 0;
		restaurant.rating = 0;
		restaurant.restoran_no = 0;
		restaurant.average_cost = 0;
	}

	return *this;
}

inline Restaurant::Restaurant(const char* name)
{
	Set_name(name);
}

Restaurant::Restaurant(const char* name, const char* address)
	:Restaurant(name)
{
	Set_address(address);
}

Restaurant::Restaurant(const char* name, const char* address, const long long& phone_number)
	: Restaurant(name, address)
{
	Set_phone_number(phone_number);
}

Restaurant::Restaurant(const char* name, const char* address, const long long& phone_number, const float& rating)
	: Restaurant(name, address, phone_number)
{
	Set_rating(rating);

}

Restaurant::Restaurant(const char* name, const char* address, const long long& phone_number, const float& rating,
	const short& max_menu_count)
	:Restaurant(name, address, phone_number, rating)
{
	Set_max_menu_count(max_menu_count);

}

Restaurant::Restaurant(const char* name, const char* address, const long long& phone_number, const float& rating,
	Menu** meals, const short& max_menu_count)
	:Restaurant(name, address, phone_number, rating, max_menu_count)
{
	Set_meals(meals);
	Set_average_cost();
	Set_restaurant_number();
}

Restaurant::Restaurant(const char* name, const char* address, const long long& phone_number, const float& rating,
	Menu** meals, const short& max_menu_count, const short& max_employee_count)
	:Restaurant(name, address, phone_number, rating, meals, max_menu_count)
{
	Set_max_employee_count(max_employee_count);
}

Restaurant::Restaurant(const char* name, const char* address, const long long& phone_number, const float& rating,
	Menu** meals, const short& max_menu_count, Employee** workers, const short& max_employee_count)
	: Restaurant(name, address, phone_number, rating, meals, max_menu_count, max_employee_count)
{
	Set_workers(workers);
}

void Restaurant::Set_name(const char* name)
{
	assert(name && "Name is nullptr!");
	this->name = _strdup(name);
}

char* Restaurant::Get_name() const
{
	return name;
}


void Restaurant::Set_address(const char* address)
{
	assert(address && "Address is nullptr!");
	this->address = _strdup(address);
}

char* Restaurant::Get_address() const
{
	return address;
}

void Restaurant::Set_phone_number(const long long& phone_number)
{
	assert(phone_number >= 994502000000 && phone_number <= 994999999999 && "Phone Number is not compatible with standarts!");
	this->phone_number = phone_number;
}

long long Restaurant::Get_phone_number() const
{
	return phone_number;
}

void Restaurant::Set_rating(const float& rating)
{
	assert(rating >= 1 && rating <= 10 && "Minimum rating is 1 and maximum is 10!");
	this->rating = rating;
}

float Restaurant::Get_rating() const
{
	return rating;
}

void Restaurant::Set_max_menu_count(const unsigned short& max_menu_count)
{
	assert(max_menu_count > 0 && "Menu count is minimum 1!");
	this->max_menu_count = max_menu_count;
}

unsigned short Restaurant::Get_maximum_count() const
{
	return max_menu_count;
}

void Restaurant::Set_meals(Menu** meals)
{
	this->meals = new Menu * [Get_maximum_count()];

	for (unsigned short i = 0; i < Get_maximum_count(); i++)
	{
		this->meals[i] = new Menu{};
		this->meals[i] = meals[i];
	}
}

Menu** Restaurant::Get_meals() const
{
	return meals;
}

void Restaurant::Set_average_cost()
{
	this->average_cost = 0.0;
	for (unsigned short i = 0; i < Get_maximum_count(); i++)
		this->average_cost += this->meals[i]->Get_price_with_tax();
	this->average_cost /= (double)Get_maximum_count();
}

void Restaurant::Set_current_cost(const Restaurant& other)
{
	this->average_cost = 0.0;
	for (unsigned short i = 0; i < other.Get_maximum_count(); i++)
		this->average_cost += other.meals[i]->Get_price_with_tax();
	this->average_cost /= (double)Get_maximum_count();
}

double Restaurant::Get_average_cost() const
{
	return average_cost;
}

void Restaurant::Set_restaurant_number()
{
	this->restoran_no = ++rn_number;
}

unsigned short Restaurant::Get_restaurant_number() const
{
	return restoran_no;
}

void Restaurant::Set_current_number(const unsigned short& restaurant_no)
{
	assert(restaurant_no > 0 && "Restaurant Number Minimum is 1!");
	this->restoran_no = restaurant_no;
}

void Restaurant::Add_meal(Menu* const& extra)
{
	auto new_menu = new Menu * [Get_maximum_count() + 1];

	for (unsigned short i = 0; i < Get_maximum_count(); i++)
	{
		new_menu[i] = new Menu;
		new_menu[i] = this->meals[i];
	}

	delete[] this->meals;

	new_menu[Get_maximum_count()] = extra;
	Set_max_menu_count(Get_maximum_count() + 1);

	this->meals = new_menu;
	new_menu = nullptr;
	Set_average_cost();
}

void Restaurant::Delete_meal(const unsigned int& id)
{
	bool is_id_exist = false;

	for (unsigned short i = 0; i < Get_maximum_count(); i++)
	{
		if (this->meals[i]->Get_id() == id)
		{
			is_id_exist = true;
			break;
		}
	}

	if (is_id_exist && Get_maximum_count() != 1)
	{
		auto new_menu = new Menu * [Get_maximum_count() - 1];
		unsigned short go_next_meal{ 0 };

		for (unsigned short i = 0; i + go_next_meal < Get_maximum_count(); i++)
		{
			if (this->meals[i]->Get_id() == id)
				++go_next_meal;

			if (i + go_next_meal < Get_maximum_count())
			{
				new_menu[i] = new Menu;
				new_menu[i] = this->meals[i + go_next_meal];
			}
		}

		delete[] this->meals;

		this->meals = new_menu;
		new_menu = nullptr;
		Set_max_menu_count(Get_maximum_count() - 1);
		Set_average_cost();
	}
	else
		std::cout << "ID: " << id << " didn't Exit or You Can't Delete Last Meal!\n";
}


void Restaurant::Update_meal(const int& id)
{
	bool is_id_exist = false;
	unsigned int index{};

	for (unsigned short i = 0; i < Get_maximum_count(); i++)
	{
		if (this->meals[i]->Get_id() == id)
		{
			is_id_exist = true;
			index = i;
			break;
		}
	}

	if (is_id_exist)
	{
		enum Options
		{
			Meal_Name = 1, Meal_Rating, Meal_Category, Meal_Price, Meal_Tax, Exit
		};

		short choice{};
		std::cout << "Choose What You Want to Change\n1)Meal Name\n2)Meal Rating\n\
3)Meal Category\n4)Meal Price\n5)Meal Tax\n6)Exit\nEnter: ";
		std::cin >> choice;

		while (choice < 1 || choice > 8)
		{
			std::cout << "Select One of This Choices: ";
			std::cin >> choice;
		}
		std::cin.ignore(1, '\n');

		switch (choice)
		{

		case Meal_Name:
		{
			char* buffer = new char[100];
			std::cout << "Current Meal Name: " << this->meals[index]->Get_name() << "\nEnter New Meal Name: ";
			delete[] this->meals[index]->Get_name();
			std::cin.getline(buffer, 100);
			this->meals[index]->Set_name(buffer);
			delete[] buffer;
		}
		break;
		case Meal_Rating:
		{
			float new_rating{};
			std::cout << "Current Meal Rating: " << this->meals[index]->Get_menu_rating() << "\nEnter New Meal Rating: ";
			std::cin >> new_rating;
			this->meals[index]->Set_menu_rating(new_rating);
		}
		break;
		case Meal_Category:
		{
			char* buffer = new char[100];
			std::cout << "Current Meal Category: " << this->meals[index]->Get_category() << "\nEnter New Meal Category: ";
			delete[] this->meals[index]->Get_category();
			std::cin.getline(buffer, 100);
			this->meals[index]->Set_category(buffer);
			delete[] buffer;
		}
		break;
		case Meal_Price:
		{
			double new_price{};
			std::cout << "Current Meal Price: " << this->meals[index]->Get_price() << "\nEnter New Meal Price: ";
			std::cin >> new_price;
			this->meals[index]->Set_price(new_price);
		}
		break;
		case Meal_Tax:
		{
			double new_tax{};
			std::cout << "Current Meal Tax: " << this->meals[index]->Get_tax() << "\nEnter New Meal Tax: ";
			std::cin >> new_tax;
			this->meals[index]->Set_tax(new_tax);
		}
		break;
		case Exit:
			std::cout << "Nothing Changed, Thanks for Visiting!\n";
		}

	}
	else
		std::cout << "ID " << id << " didn't Exist!\n";

}


void Restaurant::Set_max_employee_count(const short& max_employee_count)
{
	assert(max_employee_count > 0 && "There must at least 1 Employee!");
	this->max_employee_count = max_employee_count;
}

unsigned short Restaurant::Get_max_employee_count() const
{
	return max_employee_count;
}

void Restaurant::Set_workers(Employee** worker)
{
	this->workers = new Employee * [this->max_employee_count];
	for (unsigned short i = 0; i < this->Get_max_employee_count(); i++)
		this->workers[i] = worker[i];
}

Employee** Restaurant::Get_workers() const
{
	return workers;
}

void Restaurant::Add_employee(Employee* const& added)
{
	this->Set_max_employee_count(++this->max_employee_count);
	auto new_workers = new Employee * [this->Get_max_employee_count()];

	for (unsigned short i = 0; i < this->Get_max_employee_count() - 1; i++)
		new_workers[i] = this->workers[i];

	delete[] this->workers;

	new_workers[this->Get_max_employee_count() - 1] = added;

	this->workers = new_workers;
	new_workers = nullptr;
}

void Restaurant::Delete_employee(const int& id)
{
	short index = -1;
	for (unsigned short i = 0; i < this->Get_max_employee_count(); i++)
	{
		if (id == this->workers[i]->Get_id())
		{
			index = (short)i;
			break;
		}
	}

	if (index != -1 && this->Get_max_employee_count() > 1)
	{
		this->Set_max_employee_count(--this->max_employee_count);
		auto new_workers = new Employee * [this->Get_max_employee_count()];
		short go_next = 0;

		for (unsigned short i = 0; i + go_next < this->Get_max_employee_count() + 1; i++)
		{
			if ((short)i == index)
				++go_next;

			if (i + go_next < this->Get_max_employee_count() + 1)
				new_workers[i] = this->workers[i + go_next];
		}

		delete[] this->workers;
		this->workers = new_workers;
		new_workers = nullptr;
	}
	else
		std::cout << "This " << id << " didn't Exist or We Have 1 Employee and We Don't Remove Last Employee!\n";
}

Restaurant::~Restaurant()
{
	delete[] name;
	delete[] address;

	for (unsigned short i = 0; i < Get_maximum_count(); i++)
		delete this->meals[i];

	delete[] this->meals;

	for (unsigned short i = 0; i < Get_max_employee_count(); i++)
		delete this->workers[i];

	delete[] this->workers;
}

void Bubble_sort_for_meals(Restaurant& restaurant)
{
	bool swap{};
	for (unsigned short i = 0; i < restaurant.Get_maximum_count() - 1; i++)
	{
		swap = false;
		for (unsigned short j = 0; j < restaurant.Get_maximum_count() - 1 - i; j++)
		{
			if (restaurant.Get_meals()[j]->Get_menu_rating() > restaurant.Get_meals()[j + 1]->Get_menu_rating())
			{
				Menu buffer = *(restaurant.Get_meals()[j]);
				*(restaurant.Get_meals()[j]) = *(restaurant.Get_meals()[j + 1]);
				*(restaurant.Get_meals()[j + 1]) = buffer;
				swap = true;
			}
		}
		if (swap == false)
			break;
	}
}

void Bubble_sort_for_employees(Restaurant& restaurant)
{
	bool swap{};
	for (unsigned short i = 0; i < restaurant.Get_max_employee_count(); i++)
	{
		swap = false;
		for (unsigned short j = 0; j < restaurant.Get_max_employee_count() - 1 - i; j++)
		{
			if (restaurant.Get_workers()[j]->Get_salary() > restaurant.Get_workers()[j + 1]->Get_salary())
			{
				Employee buffer = *(restaurant.Get_workers()[j]);
				*(restaurant.Get_workers()[j]) = *(restaurant.Get_workers()[j + 1]);
				*(restaurant.Get_workers()[j + 1]) = buffer;
				swap = true;
			}
		}
		if (swap == false)
			break;
	}
}

std::ostream& operator << (std::ostream& out, const Restaurant& restaurant)
{
	if (restaurant.Get_name() != nullptr)
	{
		out << "Restaurant Number: " << restaurant.Get_restaurant_number() << '\n';
		out << "Restaurant Name: " << restaurant.Get_name() << '\n';
		out << "Restaurant Address: " << restaurant.Get_address() << '\n';
		out << "Restaurant Phone Number: " << restaurant.Get_phone_number() << '\n';
		out << "Restaurant Average Cost: " << restaurant.Get_average_cost() << "\n\n";
		out << "Restaurant Meals\n\n";		
		Print_meals(restaurant);
		out << "============================================\n\n\'" << restaurant.Get_name() << "\' Best EMPLOYEES in The World!!!\n\n";
		Print_employees(restaurant);
	}
	return out;
}

std::istream& operator >> (std::istream& in, Restaurant& restaurant)
{
	Menu* extra = new Menu{};
	in >> *extra;
	restaurant.Add_meal(extra);

	return in;
}

void Print_meals(const Restaurant& restaurant)
{
	for (unsigned short i = 0; i < restaurant.Get_maximum_count(); i++)
	{
		if (restaurant.Get_meals()[i]->Get_menu_rating() > 5)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GOLD);
		else
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);

		std::cout << *(restaurant.Get_meals()[i]);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
}

void Print_employees(const Restaurant& restaurant)
{
	for (unsigned short i = 0; i < restaurant.Get_max_employee_count(); i++)
	{
		if (restaurant.Get_workers()[i]->Get_specialization() == General_Manager)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), AQUA);
		std::cout << *(restaurant.Get_workers()[i]);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
}
