#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define delimiter "\n------------------------------------------------\n"
#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name,unsigned int age
#define HUMAN_GIVE_PARAMETERS  last_name,first_name,age
#define STUDENT_TAKE_PARAMETERS const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS  speciality,  group, rating, attendance

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
	Human(HUMAN_TAKE_PARAMETERS):last_name(last_name),first_name(first_name),age(age)
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
	Student	(HUMAN_TAKE_PARAMETERS,STUDENT_TAKE_PARAMETERS):Human(HUMAN_GIVE_PARAMETERS)
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
	Teacher	(HUMAN_TAKE_PARAMETERS,	const std::string& specialty, unsigned int experience) :Human(HUMAN_GIVE_PARAMETERS)
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

class Graduate :public Human
{
	std::string practice;
	unsigned int grade;
	std::string specialty;
public:
	const std::string& get_pracrice() const
	{
		return practice;
	}
	unsigned int get_grade()const
	{
		return grade;
	}
	const std::string& get_specialty()const
	{
		return specialty;
	}
	void set_practice(const std::string& practice)
	{
		this->practice = practice;
	}
	void set_grade(unsigned int grade)
	{
		this->grade = grade;
	}
	void set_specialty(const std::string& specialty)
	{
		this->specialty = specialty;
	}
	//		Constructors:
	Graduate(HUMAN_TAKE_PARAMETERS, const std::string& practice, unsigned int grade, const std::string& specialty)
		:Human(HUMAN_GIVE_PARAMETERS)
	{
		set_practice(practice);
		set_grade(grade);
		set_specialty(specialty);
		std::cout << "GConstructor:\t" << this << std::endl;
	}
	~Graduate()
	{
		std::cout << "GDestructor:\t" << this << std::endl;
	}
	//		Methods:
	void print()
	{
		Human::print();
		std::cout << practice << " " << grade <<" " <<specialty<< std::endl;
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
	std::cout << delimiter;
	Graduate grats("Crimer", "John", 24,"DONE",5,"Biology");
	grats.print();
}