#pragma once
class Menu
{

private:
	unsigned int id;
	char* name;
	float menu_rating;
	char* category;
	double price;
	double tax;

public:

	Menu();

	Menu(const Menu& other);

	Menu& operator = (const Menu& other);

	Menu(Menu&& temp) noexcept;

	Menu& operator = (Menu&& temp) noexcept;

	explicit inline Menu(const char* name);

	Menu(const char* name, const float& menu_rating);

	Menu(const char* name, const float& menu_rating, const char* category);

	Menu(const char* name, const float& menu_rating, const char* category, const double& price);

	Menu(const char* name, const float& menu_rating, const char* category, const double& price,
		const double& tax);

	void Set_name(const char* name);
	char* Get_name() const;

	void Set_menu_rating(const float& menu_rating);
	float Get_menu_rating() const;

	void Set_category(const char* category);
	char* Get_category() const;

	void Set_price(const double& price);
	double Get_price() const;

	void Set_tax(const double& tax);
	double Get_tax() const;
	double Get_price_with_tax() const;

	void Set_id();
	int Get_id() const;
	void Equal_id(const int& id);

	inline ~Menu();

	friend std::ostream& operator << (std::ostream& out, const Menu& menu);
	friend std::istream& operator >> (std::istream& in, Menu& menu);
};
