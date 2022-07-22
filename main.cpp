#include <iostream>
using namespace std;

//Abstract class
class AbstractEmployeee {
	//Abstract/virtual function
	virtual void AskForPromotion() = 0;
};

class Employee:AbstractEmployeee
{
private:
	string Name;
	string Company;
	int Age;

public:
	//Incapsulation
	void setName(string name) {
		Name = name;
	}
	string getName() {
		return Name;
	}

	void setCompany(string company) {
		Company = company;
	}
	string getCompany() {
		return Company;
	}

	void setAge(int age) {
		if (age >= 18) {
			Age = age;
		}
	}
	int getAge() {
		return Age;
	}

	void IntroduceYoureself() {
		cout << "Name - " << Name << endl;
		cout << "Company - " << Company << endl;
		cout << "Age - " << Age << endl;
	}

	//constractor
	Employee(string name, string company, int age) {
		Name = name;
		Company = company;
		Age = age;
	}

	void AskForPromotion() {
		if (Age > 30) {
			cout << Name << " got promoted!" << endl;
		}
		else {
			cout << Name << ", sorry no promotion" << endl;
		}
	}
};


class Developer: Employee {
private:
	string FavPrLang;
public:
	void setFavPrLang(string favprlang) {
		FavPrLang = favprlang;
	}
	string getFavPrLang() {
		return FavPrLang;
	}
	Developer(string name, string company, int age, string favprlang) 
		:Employee(name, company, age)
	{
		FavPrLang = favprlang;
	}

	void FixBug() {
		cout << getName() << " fixed bug using " << FavPrLang << endl;
	}
};



int main() {
	Employee employee1 = Employee("Alessandro", "Twitch", 18);
	Employee employee2 = Employee("Jhon", "Amazon", 35);
	
	employee1.AskForPromotion();
	employee2.AskForPromotion();

	Developer d = Developer("Stefano", "DemidoDev", "34", "Java");
	d.FixBug();
}
