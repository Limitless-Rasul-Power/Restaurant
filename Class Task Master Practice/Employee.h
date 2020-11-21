#pragma once

enum Job
{
	Cook = 1, Prep_Cook, Baker, Kitchen_Manager, General_Manager, Host_Hostess, Server, Back_Waiter, Bartender, Cashier
};

class Employee
{

private:
	int id;
	char* name;
	char* surname;
	unsigned short specialization;
	unsigned short age;
	double salary;
	unsigned short work_day_in_week;
	unsigned short work_hour_in_day;
public:

	Employee();

	Employee(const Employee& other);

	Employee& operator = (const Employee& other);

	Employee(Employee&& other) noexcept;

	explicit inline Employee(const char* name);

	Employee(const char* name, const char* surname);

	Employee(const char* name, const char* surname, const short& specialization);

	Employee(const char* name, const char* surname, const short& specialization, const short& age);

	Employee(const char* name, const char* surname, const short& specialization, const short& age, const short& work_day_in_week);

	Employee(const char* name, const char* surname, const short& specialization, const short& age, const short& work_day_in_week,
		const short& work_hour_in_day);

	void Set_name(const char* name);

	char* Get_name() const;

	void Set_surname(const char* surname);

	char* Get_surname() const;


	void Set_specialization(const short& specialization);

	unsigned short Get_specialization() const;

	void Set_age(const short& age);

	unsigned short Get_age() const;

	void Set_salary();

	double Get_salary() const;

	void Equal_salary(const double& salary);

	void Set_work_day_in_week(const short& work_day_in_week);

	unsigned short Get_work_day_in_week() const;

	void Set_work_hour_in_day(const short& work_hour_in_day);

	unsigned short Get_work_hour_in_day() const;

	void Set_id();

	unsigned int Get_id() const;

	void Equal_id(const int& id);

	inline ~Employee();

	friend std::ostream& operator << (std::ostream& out, const Employee& worker);
	friend std::istream& operator >> (std::istream& in, Employee& worker);
};