// Andres Choque Lab 3 polymorphism inheritance

#include <iostream>
#include <string>

	using namespace std;

	class Mammal
	{
	public:

		Mammal()
		{
			name = " ";
			weight = 0;
			cout << "\nInvoking Mammal default constructor";

		}
		Mammal(string Name, int Weight)
		{
			name = Name;
			weight = Weight;
			cout << "\nInvoking Mammal parameterized constructor\n";

		}
		string getName() { return name; }
		int getWeight() { return weight; }

		virtual void speak() { };
		~Mammal() { cout << "\nInvoking Mammal destructor\n"; }

	private:
		string name = "";
		int weight = 0;
	};

	class Dog : public Mammal
	{
	public:
		Dog() : Mammal()
		{
			cout << "Invoking Dog Default constructor\n";
		}
		Dog(string name, int weight) : Mammal(name, weight)
		{
			cout << "Invoking Dog Parameterized Constructor\n";
		}
		void speak() { cout << "Woof\n"; }
		~Dog()
		{
			cout << "Invoking Dog Destructor\n";
		}
	private:
	};

	class Cat : public Mammal
	{
	public:
		Cat() : Mammal()
		{
			cout << "Invoking Cat Default constructor\n";
		}
		Cat(string name, int weight) : Mammal(name, weight)
		{
			cout << "Invoking Cat Parameterized Constructor\n";
		}
		void speak() { cout << "Meow\n"; }
		~Cat()
		{
			cout << "Invoking Cat Destructor\n";
		}
	private:
	};

	class Horse : public Mammal
	{
	public:
		Horse() : Mammal()
		{
			cout << "Invoking Horse Default constructor\n";
		}
		Horse(string name, int weight) : Mammal(name, weight)
		{
			cout << "Invoking Horse Parameterized Constructor\n";
		}
		void speak() { cout << "I'm Mr. Ed\n"; }
		~Horse()
		{
			cout << "Invoking Horse Destructor\n";
		}
	private:
	};

	class Pig : public Mammal
	{
	public:
		Pig() : Mammal()
		{
			cout << "Invoking Pig Default constructor\n";
		}
		Pig(string name, int weight) : Mammal(name, weight)
		{
			cout << "Invoking Pig Parameterized Constructor\n";
		}
		void speak() { cout << "Oink\n"; }
		~Pig()
		{
			cout << "Invoking Pig Destructor\n";
		}
	private:
	};

	int main()
	{
		string mammalName = "";
		int mammalWeight = 0;
		srand(100);
		Mammal* mammals[5];
		int menuChoice = 0;
		for (int i = 0; i <= 4; i++)
		{
			cout << "Please choose an animal from the different numbers\n";
			cout << "(Dog 1, Cat 2, Horse 3, Pig 4)\n";
			cin >> menuChoice;
			cout << "Name?\n";
			cin >> mammalName;	
			mammalWeight = rand() % 151;
			if (menuChoice == 1) mammals[i] = new Dog(mammalName, mammalWeight);
			if (menuChoice == 2) mammals[i] = new Cat(mammalName, mammalWeight);
			if (menuChoice == 3) mammals[i] = new Horse(mammalName, mammalWeight);
			if (menuChoice == 4) mammals[i] = new Pig(mammalName, mammalWeight);
		}
		for (int i = 0; i <= 4; i++)
		{
			cout << "\nName: " << mammals[i]->getName() <<
				"  weight: " << mammals[i]->getWeight() << endl;
			mammals[i]->speak();
		}
		for (int i = 0; i <= 4; i++)
		{
			delete mammals[i];
		}
	}