#pragma once
#include "Meal.h"
#include "Employee.h"

#define GOLD 14
#define GREEN 10
#define WHITE 7
#define AQUA 11
#define PINK 13
#define RED 12

#define UP 72
#define DOWN 80
#define ENTER 13

class Restaurant
{
private:
	unsigned short restoran_no;
	char* name;
	char* address;
	long long phone_number;
	float rating;
	double average_cost;
	unsigned short max_menu_count;
	Menu** meals;
	Employee** workers;
	unsigned short max_employee_count;

public:
	static unsigned short rn_number;
	
	Restaurant();

	Restaurant(const Restaurant& other);

	Restaurant& operator = (const Restaurant& other);

	Restaurant(Restaurant&& restaurant) noexcept;

	Restaurant& operator = (Restaurant&& restaurant) noexcept;

	explicit inline Restaurant(const char* name);

	Restaurant(const char* name, const char* address);

	Restaurant(const char* name, const char* address, const long long& phone_number);

	Restaurant(const char* name, const char* address, const long long& phone_number, const float& rating);

	Restaurant(const char* name, const char* address, const long long& phone_number, const float& rating,
		const short& max_menu_count);

	Restaurant(const char* name, const char* address, const long long& phone_number, const float& rating,
		Menu** meals, const short& max_menu_count);

	Restaurant(const char* name, const char* address, const long long& phone_number, const float& rating,
		Menu** meals, const short& max_menu_count, const short& max_employee_count);

	Restaurant(const char* name, const char* address, const long long& phone_number, const float& rating,
		Menu** meals, const short& max_menu_count, Employee** workers, const short& max_employee_count);

	void Set_name(const char* name);
	char* Get_name() const;

	void Set_address(const char* address);
	char* Get_address() const;

	void Set_phone_number(const long long& phone_number);
	long long Get_phone_number() const;

	void Set_rating(const float& rating);
	float Get_rating() const;

	void Set_max_menu_count(const unsigned short& max_menu_count);
	unsigned short Get_maximum_count() const;

	void Set_meals(Menu** meals);
	Menu** Get_meals() const;

	void Set_average_cost();
	void Set_current_cost(const Restaurant& other);
	double Get_average_cost() const;

	void Set_restaurant_number();
	unsigned short Get_restaurant_number() const;
	void Set_current_number(const unsigned short& restaurant_no);

	void Add_meal(Menu* const& extra);
	void Delete_meal(const unsigned int& id);
	void Update_meal(const int& id);


	void Set_max_employee_count(const short& max_employee_count);
	unsigned short Get_max_employee_count() const;

	void Set_workers(Employee** worker);
	Employee** Get_workers() const;

	void Add_employee(Employee* const& added);
	void Delete_employee(const int& id);

	inline ~Restaurant();

	friend std::ostream& operator << (std::ostream& out, const Restaurant& restaurant);
	friend std::istream& operator >> (std::istream& in, Restaurant& restaurant);
	friend void Bubble_sort_for_meals(Restaurant& restaurant);
	friend void Bubble_sort_for_employees(Restaurant& restaurant);
	friend void Print_meals(const Restaurant& restaurant);
	friend void Print_employees(const Restaurant& restaurant);
};
