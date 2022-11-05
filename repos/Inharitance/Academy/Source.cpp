#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define delimiter "\n------------------------------------------------\n"

class Human
{
	std::string last_name;
	std::string first_name;
	unsigned int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}

	const std::string& get_firt_name()const
	{
		return first_name;
	}
	unsigned int get_age()const
	{
		return age;
	}
	//		Constructors
	Human(const std::string& last_name, const std::string& first_name,unsigned int age):last_name(last_name), first_name(first_name), age(age)
	{
		std::cout << "HConstructor:\t" << this << std::endl;
	}
	~Human()
	{
		std::cout << "HDestructor:\t" << this <<  std::endl;
	}
	//	Methods
	void print()const
	{
		std::cout << last_name << " " << first_name << " " << age << " лет.\n";
	}
};

class Student : public Human
{
	std::string speciality;
	std::string group;
	double rating;
	double attendance;
public:
	const std::string& get_speciality() const
	{
	return speciality;
	}
	const std::string& get_group()const
	{
		return group;
	}
	double get_rating() const
	{
		return rating;
	}
	double get_attendance()const
	{
		return attendance;
	}
	void set_specialty(const std::string& specialty)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}
	//	Constructors:
	Student
	(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& speciality, const std::string& group, double rating, double attendance
	):Human(last_name,first_name,age)
	{
		this->speciality = speciality;
		this->group = group;
		this->rating = rating;
		this->attendance = attendance;
		std::cout << "SContructor:\t" << this<<std::endl;
	}
	~Student()
	{
		std::cout << "SDestructor:\t" << this << std::endl;
	}
	//		Methods:
	void print()const
	{
		Human::print();
		std::cout << speciality << " " << group << " " << rating << " " << attendance << std::endl;
	}
};
class Teacher :public Human
{
	std::string specialty;
	unsigned int experience;
public:
	const std::string& get_specialty()const
	{
		return specialty;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	void set_specialty(const std::string& specialty)
	{
		this->specialty = specialty;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}
	//		Constructors:
	Teacher
	(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& specialty, unsigned int experience
	) :Human(last_name, first_name, age)
	{
		set_specialty(specialty);
		set_experience(experience);
		std::cout << "TConstructor:\t" << this << std::endl;
	}
	~Teacher()
	{
		std::cout << "TDestructor:\t" << this << std::endl;
	}
	//		Methods:
	void print()
	{
		Human::print();
		std::cout << specialty << " " << experience << std::endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	Human human("Montana", "Petrucho", 49);
	human.print();
	std::cout << delimiter ;
	Student stud("Yaroslav", "Geranov", 21, "Fizik", "14", 90, 95);
	stud.print();
	std::cout<<delimiter;
	Teacher professor("White", "Walter", 55, "Chemistry", 20);
	professor.print();
}