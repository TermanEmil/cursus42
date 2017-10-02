#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <stdlib.h>
#include <time.h>

void testShrubbery (void) {
	Form * formcSC = new ShrubberyCreationForm ("home");
	Bureaucrat bureaucrat("Emil", 10);
	bureaucrat.signForm(*formcSC);
	formcSC->execute(bureaucrat);

	delete formcSC;

	formcSC = new ShrubberyCreationForm("whatever");

	try
	{
		bureaucrat.executeForm(*formcSC);
	}
	catch (std::exception & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	bureaucrat.signForm(*formcSC);
	bureaucrat.gradeDecrement(140);

	try
	{
		bureaucrat.executeForm(*formcSC);
	}
	catch (std::exception & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	bureaucrat.gradeIncrement(140);
	bureaucrat.executeForm(*formcSC);

	system("chmod u-w whatever_shrubbery");

	try
	{
		bureaucrat.executeForm(*formcSC);
	}
	catch (std::exception & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;	
	}

	system("chmod u+w whatever_shrubbery");

	delete formcSC;
}

void testRobotomy (void) {
	Form * formRobot = new RobotomyRequestForm("Unicorn");
	Bureaucrat bureaucrat("Emil", 10);
	bureaucrat.signForm(*formRobot);
	formRobot->execute(bureaucrat);

	delete formRobot;

	formRobot = new RobotomyRequestForm("Unicorn");


	try
	{
		bureaucrat.executeForm(*formRobot);
	}
	catch (std::exception & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	delete formRobot;
}

int main (void) {
	srand(time(NULL));

	testShrubbery();
	std::cout << "############################" << std::endl;
	testRobotomy();
	return 0;
}