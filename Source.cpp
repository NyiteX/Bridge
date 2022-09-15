#include <iostream>

using namespace std;

class BaseLanguage
{
public:
	virtual void Baselanguage() = 0;
};

class LanguageOne:public BaseLanguage
{
public:

	void Baselanguage() override
	{
		cout << "C++.\n";
	}
};
class LanguageTwo :public BaseLanguage
{
public:

	void Baselanguage() override
	{
		cout << "C#.\n";
	}
};

class Programmer
{
protected:
	BaseLanguage* progrlanguage;
public:
	
	Programmer(BaseLanguage* pr):progrlanguage(pr){}
	void setLanguage(BaseLanguage* pr)
	{
		progrlanguage = pr;
	}

	virtual void programmer() = 0;

};

class DoWork: public Programmer
{
public:
	DoWork(BaseLanguage* pr): Programmer(pr){}

	void programmer()override
	{
		progrlanguage->Baselanguage();
		cout << "DoWork.\n";
	}
};

int main()
{
	setlocale(LC_ALL, "ru");

	Programmer* programmer = new DoWork(new LanguageOne);
	programmer->programmer();
	cout << endl;
	programmer->setLanguage(new LanguageTwo);
	programmer->programmer();
}