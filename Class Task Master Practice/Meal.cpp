#include <iostream>
#include <string.h>
#include <assert.h>
#include "Meal.h"

Menu::Menu() :id(0), name(nullptr), menu_rating(0.0), category(nullptr), price(0.0), tax(0.0)
{}

Menu::Menu(const Menu& other)
{
	Equal_id(other.id);
	Set_name(other.name);
	Set_category(other.category);
	Set_menu_rating(other.menu_rating);
	Set_price(other.price);
	Set_tax(other.tax);
}

Menu& Menu::operator = (const Menu& other)
{
	Equal_id(other.id);
	Set_name(other.name);
	Set_category(other.category);
	Set_menu_rating(other.menu_rating);
	Set_price(other.price);
	Set_tax(other.tax);

	return *this;
}

Menu::Menu(Menu&& temp) noexcept
{
	this->id = temp.id;
	this->name = temp.name;
	this->category = temp.category;
	this->menu_rating = temp.menu_rating;
	this->price = temp.price;
	this->tax = temp.tax;

	temp.id = 0;
	temp.name = nullptr;
	temp.category = nullptr;
	temp.menu_rating = 0;
	temp.price = 0;
	temp.tax = 0;
}

Menu& Menu::operator = (Menu&& temp) noexcept
{
	if (this != &temp)
	{
		delete[] this->name;
		delete[] this->category;

		this->id = temp.id;
		this->name = temp.name;
		this->category = temp.category;
		this->menu_rating = temp.menu_rating;
		this->price = temp.price;
		this->tax = temp.tax;

		temp.id = 0;
		temp.name = nullptr;
		temp.category = nullptr;
		temp.menu_rating = 0;
		temp.price = 0;
		temp.tax = 0;
	}
	return *this;
}

inline Menu::Menu(const char* name)
{
	Set_name(name);
}

Menu::Menu(const char* name, const float& menu_rating)
	:Menu(name)
{
	Set_menu_rating(menu_rating);
}

Menu::Menu(const char* name, const float& menu_rating, const char* category)
	:Menu(name, menu_rating)
{
	Set_category(category);
}

Menu::Menu(const char* name, const float& menu_rating, const char* category, const double& price)
	:Menu(name, menu_rating, category)
{
	Set_price(price);
}

Menu::Menu(const char* name, const float& menu_rating, const char* category, const double& price,
	const double& tax)
	:Menu(name, menu_rating, category, price)
{
	Set_tax(tax);
	Set_id();
}

void Menu::Set_name(const char* name)
{
	assert(name && "Name is nullptr!");
	this->name = _strdup(name);
}

char* Menu::Get_name() const
{
	return name;
}

void Menu::Set_menu_rating(const float& menu_rating)
{
	assert(menu_rating >= 1 && menu_rating <= 10 && "Minimum Menu Rating is 1!");
	this->menu_rating = menu_rating;
}

float Menu::Get_menu_rating() const
{
	return menu_rating;
}

void Menu::Set_category(const char* category)
{
	assert(category && "Category is nullptr!");
	this->category = _strdup(category);
}

char* Menu::Get_category() const
{
	return category;
}

void Menu::Set_price(const double& price)
{
	assert(price > 1 && "Minimum Price is 10!");
	this->price = price;
}

double Menu::Get_price() const
{
	return price;
}

void Menu::Set_tax(const double& tax)
{
	assert(tax >= 1 && tax < 100 && "Minimum Tax is 1, Maximum Tax is 99!");
	this->tax = tax;
}

double Menu::Get_tax() const
{
	return tax;
}


double Menu::Get_price_with_tax() const
{
	return price + ((price * tax) / (double)100);
}

void Menu::Set_id()
{
	this->id = (rand() % 943243268) + 20 * 3 / 2;
}

int Menu::Get_id() const
{
	return id;
}

void Menu::Equal_id(const int& id)
{
	this->id = id;
}

inline Menu::~Menu()
{
	delete[] name;
	delete[] category;
}

std::ostream& operator << (std::ostream& out, const Menu& menu)
{
	if (menu.Get_name() != nullptr)
	{
		out << "Menu ID: " << menu.Get_id() << '\n';
		out << "Menu Rating: " << menu.Get_menu_rating() << '\n';
		out << "Menu Name: " << menu.Get_name() << '\n';
		out << "Menu Category: " << menu.Get_category() << '\n';
		out << "Menu Price: " << menu.Get_price() << " $" << '\n';
		out << "Menu Tax: " << menu.Get_tax() << " %" << '\n';
		out << "Menu Price with Tax: " << menu.Get_price_with_tax() << " $" << "\n\n";
	}
	else
		out << "No Data!\n";

	return out;
}

std::istream& operator >> (std::istream& in, Menu& menu)
{
	menu.Set_id();
	char* buffer = new char[100];
	std::cout << "Menu Name: ";
	in.getline(buffer, 100);
	menu.Set_name(buffer);
	memset(buffer, ' ', 100);

	std::cout << "Menu Category: ";
	in.getline(buffer, 100);
	menu.Set_category(buffer);
	delete[] buffer;

	double for_enter{};
	std::cout << "Menu Rating: ";
	in >> for_enter;
	menu.Set_menu_rating((float)for_enter);

	std::cout << "Menu Price: ";
	in >> for_enter;
	menu.Set_price(for_enter);

	std::cout << "Menu Tax: ";
	in >> for_enter;
	menu.Set_tax(for_enter);
	in.ignore(1, '\n');

	return in;
}