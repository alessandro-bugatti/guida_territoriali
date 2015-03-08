#include <iostream>
#include <algorithm>

using namespace std;

int K; //meals in the canteen
int prices[20]; 
int menu_price;
int menu[4];
int T; //meals on the tray
int meals[20];

int meals_in_menu[20][20];
int how_many[20];

int sub_menu_cost(int n)
{
	int tot = 0;
	for(int i = 0; i < 20; i++)
		tot += meals_in_menu[n][i];
	return tot;
}

bool in_menu(int n)
{
	for(int i = 0; i < 4; i++)
		if (n == menu[i])
			return true;
	return false;
}

int main()
{
	int cost = 0;
	cin >> K;
	for(int i = 1; i <= K; i++)
		cin >> prices[i];
	cin >> menu_price;
	for(int i = 0; i < 4; i++)
		cin >> menu[i];
	cin >> T;
	for(int i = 0; i < T; i++)
	{
		cin >> meals[i];
		if (in_menu(meals[i]))
			meals_in_menu[how_many[meals[i]]++][meals[i]] = prices[meals[i]];
		else
			cost += prices[meals[i]];
	}
	int max_menus = *max_element(how_many, how_many+20);
	for(int i = 0; i < max_menus; i++)
		if (sub_menu_cost(i) < menu_price)
			cost += sub_menu_cost(i);
		else
			cost += menu_price;
	cout << cost << endl;
	return 0;
}
