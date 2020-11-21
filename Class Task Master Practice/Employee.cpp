#include <iostream>
#include <string.h>
#include <assert.h>
#include "Employee.h"

Employee::Employee() :id(0), name(nullptr), surname(nullptr), specialization(0), age(0), salary(0), work_day_in_week(0),
work_hour_in_day(0)
{}

Employee::Employee(const Employee& other)
{
	Equal_id(other.id);
	Set_name(other.name);
	Set_surname(other.surname);
	Set_age(other.age);
	Set_specialization(other.specialization);
	Set_work_hour_in_day(other.work_hour_in_day);
	Set_work_day_in_week(other.work_day_in_week);
	Equal_salary(other.salary);
}

Employee& Employee::operator = (const Employee& other)
{
	Equal_id(other.id);
	Set_name(other.name);
	Set_surname(other.surname);
	Set_age(other.age);
	Set_specialization(other.specialization);
	Set_work_hour_in_day(other.work_hour_in_day);
	Set_work_day_in_week(other.work_day_in_week);
	Equal_salary(other.salary);
	return *this;
}

Employee::Employee(Employee&& other) noexcept
{
	this->id = other.id;
	this->name = other.name;
	this->surname = other.surname;
	this->age = other.age;
	this->specialization = other.specialization;
	this->work_hour_in_day = other.work_hour_in_day;
	this->work_day_in_week = other.work_day_in_week;
	this->salary = other.salary;

	other.id = 0;
	other.name = nullptr;
	other.surname = nullptr;
	other.age = 0;
	other.specialization = 0;
	other.work_hour_in_day = 0;
	other.work_day_in_week = 0;
	other.salary = 0;
}


inline Employee::Employee(const char* name)
{
	Set_name(name);
}

Employee::Employee(const char* name, const char* surname)
	:Employee(name)
{
	Set_surname(surname);
}

Employee::Employee(const char* name, const char* surname, const short& specialization)
	:Employee(name, surname)
{
	Set_specialization(specialization);
}

Employee::Employee(const char* name, const char* surname, const short& specialization, const short& age)
	:Employee(name, surname, specialization)
{
	Set_age(age);
}

Employee::Employee(const char* name, const char* surname, const short& specialization, const short& age, const short& work_day_in_week)
	:Employee(name, surname, specialization, age)
{
	Set_work_day_in_week(work_day_in_week);
}

Employee::Employee(const char* name, const char* surname, const short& specialization, const short& age, const short& work_day_in_week,
	const short& work_hour_in_day)
	:Employee(name, surname, specialization, age, work_day_in_week)
{
	Set_work_hour_in_day(work_hour_in_day);
	Set_id();
	Set_salary();
}

void Employee::Set_name(const char* name)
{
	assert(name && "Name is Null!");
	this->name = _strdup(name);
}

char* Employee::Get_name() const
{
	return name;
}

void Employee::Set_surname(const char* surname)
{
	assert(surname && "Surname is Null!");
	this->surname = _strdup(surname);
}

char* Employee::Get_surname() const
{
	return surname;
}


void Employee::Set_specialization(const short& specialization)
{
	assert(specialization > 0 && specialization < 11 && "We Don't Have This Type of Specialization");
	this->specialization = specialization;
}

unsigned short Employee::Get_specialization() const
{
	return specialization;
}

void Employee::Set_age(const short& age)
{
	assert(age > 16 && "Your Age isn't for Work!");
	this->age = age;
}

unsigned short Employee::Get_age() const
{
	return age;
}

void Employee::Set_salary()
{
	double salary{};

	switch (this->specialization)
	{
	case Cook:
		salary = (32.43 * work_hour_in_day) * work_day_in_week;
		break;
	case Prep_Cook:
		salary = (17.87 * work_hour_in_day) * work_day_in_week;
		break;
	case Baker:
		salary = (15.64 * work_hour_in_day) * work_day_in_week;
		break;
	case Kitchen_Manager:
		salary = (120.45 * work_hour_in_day) * work_day_in_week;
		break;
	case General_Manager:
		salary = (200.87 * work_hour_in_day) * work_day_in_week;
		break;
	case Host_Hostess:
		salary = (10.12 * work_hour_in_day) * work_day_in_week;
		break;
	case Server:
		salary = (13.23 * work_hour_in_day) * work_day_in_week;
		break;
	case Back_Waiter:
		salary = (8.45 * work_hour_in_day) * work_day_in_week;
		break;
	case Bartender:
		salary = (14.98 * work_hour_in_day) * work_day_in_week;
		break;
	case Cashier:
		salary = (12.12 * work_hour_in_day) * work_day_in_week;
	}

	this->salary = salary;
}

double Employee::Get_salary() const
{
	return salary;
}

void Employee::Equal_salary(const double& salary)
{
	this->salary = salary;
}

void Employee::Set_work_day_in_week(const short& work_day_in_week)
{
	assert(work_day_in_week > 0 && work_day_in_week < 8 && "Anybody Doesn't Work 0 or 7+ days in a Week!");
	this->work_day_in_week = work_day_in_week;
}

unsigned short Employee::Get_work_day_in_week() const
{
	return work_day_in_week;
}

void Employee::Set_work_hour_in_day(const short& work_hour_in_day)
{
	assert(work_hour_in_day > 0 && work_hour_in_day < 13 && "Anybody Doesn't Work 0 or 12+ hours in a Day!");
	this->work_hour_in_day = work_hour_in_day;
}

unsigned short Employee::Get_work_hour_in_day() const
{
	return work_hour_in_day;
}

void Employee::Set_id()
{
	this->id = rand() % 8532753279 + 1;
}

unsigned int Employee::Get_id() const
{
	return id;
}

void Employee::Equal_id(const int& id)
{
	this->id = id;
}

inline Employee::~Employee()
{
	delete[] name;
	delete[] surname;
}

std::ostream& operator << (std::ostream& out, const Employee& worker)
{
	if (worker.name != nullptr)
	{
		out << "Employe ID: " << worker.id << '\n';
		out << "Employe Name: " << worker.name << '\n';
		out << "Employe Surname: " << worker.surname << '\n';
		out << "Employe Specialization: ";

		switch (worker.specialization)
		{
		case Cook:
			out << "Cook\n";
			break;
		case Prep_Cook:
			out << "Prep Cook\n";
			break;
		case Baker:
			out << "Baker\n";
			break;
		case Kitchen_Manager:
			out << "Kitchen Manager\n";
			break;
		case General_Manager:
			out << "General Manager\n";
			break;
		case Host_Hostess:
			out << "Host/Hostess\n";
			break;
		case Server:
			out << "Server\n";
			break;
		case Back_Waiter:
			out << "Back Waiter\n";
			break;
		case Bartender:
			out << "Bartender\n";
			break;
		case Cashier:
			out << "Cashier\n";
		}

		out << "Employee Age: " << worker.age << '\n';
		out << "Employee Work Hour in Day: " << worker.work_hour_in_day << '\n';
		out << "Employee Work Day in Week: " << worker.work_day_in_week << '\n';
		out << "Employee Salary in Week: " << worker.salary << "\n\n";
	}

	return out;
}

std::istream& operator >> (std::istream& in, Employee& worker)
{
	worker.Set_id();

	char* buffer = new char[123];
	std::cout << "Enter Employee Name: ";
	in.getline(buffer, 123);
	worker.Set_name(buffer);
	memset(buffer, ' ', 123);

	std::cout << "Enter Employee Surname: ";
	in.getline(buffer, 123);
	worker.Set_surname(buffer);
	delete[] buffer;

	short helper{};
	std::cout << "1)Cook\n2)Prep Cook\n3)Baker\n4)Kitchen Manager\n5)General Manager\n6)Host/Hostess\n7)Server\n8)Back Waiter\n\
9)Bartender\n10)Cashier\n";
	std::cout << "Enter Specialization: ";
	in >> helper;
	worker.Set_specialization(helper);

	std::cout << "Employee Age: ";
	in >> helper;
	worker.Set_age(helper);

	std::cout << "Employee Work Hour in a Day: ";
	in >> helper;
	worker.Set_work_hour_in_day(helper);

	std::cout << "Employee Work Day in a Week: ";
	in >> helper;
	worker.Set_work_day_in_week(helper);
	in.ignore(1, '\n');

	worker.Set_salary();

	return in;
}