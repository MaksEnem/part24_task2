#include <iostream>
#include <vector>

void friends_birthdays_initialization(std::vector <std::string>& vec_name, std::vector <int>& vec_day, std::vector <int>& vec_month, std::vector <int>& vec_year) {

	std::string name_friend;
	int day_Bith;
	int month_Bith;
	int year_Bith;

	do {

		std::cout << "Enter a friend's name: ";
		std::cin >> name_friend;

		if (name_friend != "end") {

			std::cout << "Enter the full date of birth, including the month and year, in the format year/month/day:\n";
			std::cin >> year_Bith >> month_Bith >> day_Bith;

			vec_name.push_back(name_friend);
			vec_day.push_back(day_Bith);
			vec_month.push_back(month_Bith);
			vec_year.push_back(year_Bith);
		}

	} while (name_friend != "end");
}

int main() {	
	
	std::vector <std::string> vec_name(0);
	std::vector <int> vec_day(0); 
	std::vector <int> vec_month(0);
	std::vector <int> vec_year(0);

	friends_birthdays_initialization(vec_name, vec_day, vec_month, vec_year);
	
	std::time_t data = std::time(nullptr);
	std::tm today;
	localtime_s(&today, &data);
	++today.tm_mon;
	today.tm_year = today.tm_year + 1900;

	std::cout << today.tm_year << "/" << today.tm_mon << "/" << today.tm_mday << std::endl;

	for (int i = 0; i < vec_day.size(); ++i) {

		std::cout << vec_name[i] << " " << vec_year[i] << "/" << vec_month[i] << "/" << vec_day[i] << std::endl;

	}

}