#include<iostream>
#include<vector>
using std::string;
using std::vector;
double dzialanie(string text)
{
	vector<double> num;
	vector<char> znak;
	double a = 0;
	for (int i = 0; i < text.length(); i++)
	{
		if (text[i] >= 48 && text[i] <= 57)
		{
			a = a * 10 + text[i] - 48;
		}
		else
		{
			num.push_back(a);
			a = 0;
			znak.push_back(text[i]);
		}
		

	}
	num.push_back(a);

	for (int i = 0; i < znak.size(); i++)
	{
		if (znak[i] == '*')
		{
			num[i] = num[i] * num[i + 1];
			num.erase(num.begin() + i + 1);
			znak.erase(znak.begin() + i);
			i--;

		}
		else if (znak[i] == '/')
		{
			num[i] = num[i] / num[i + 1];
			num.erase(num.begin() + i + 1);
			znak.erase(znak.begin() + i);
			i--;

		}
	}
	for (int i = 0; i < znak.size(); i++)
	{
		if (znak[i] == '+')
		{
			num[i] = num[i] + num[i + 1];
			num.erase(num.begin() + i + 1);
			znak.erase(znak.begin() + i);
			i--;

		}
		else if (znak[i] == '-')
		{
			num[i] = num[i] - num[i + 1];
			num.erase(num.begin() + i + 1);
			znak.erase(znak.begin() + i);
			i--;

		}
	}
	return num[0];
	
	

}
int main()
{
	
	string text;
	std::cout << "podaj dzialanie jakie chcesz obliczyc?\n";
	std::cin >> text;
	std::cout<<dzialanie(text);

	return 0;
}
