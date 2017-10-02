#include "OfficeBlock.hpp"

Intern const * OfficeBlock::getIntern (void) const {return _intern;}
Bureaucrat const * OfficeBlock::getSigner (void) const {return _signer;}
Bureaucrat const * OfficeBlock::getExecutor (void) const {return _executor;}

void OfficeBlock::setIntern (Intern & newIntern) {_intern = &newIntern;}
void OfficeBlock::setSigner (Bureaucrat & newSigner) {_signer = &newSigner;}
void OfficeBlock::setExecutor (Bureaucrat & newExec) {_executor = &newExec;}

OfficeBlock::OfficeBlock (void) {
	_intern = NULL;
	_signer = NULL;
	_executor = NULL;
}

OfficeBlock::OfficeBlock (Intern * intern, Bureaucrat * signer, Bureaucrat * executor) {
	_intern = intern;
	_signer = signer;
	_executor = executor;
}

OfficeBlock::~OfficeBlock (void) {}

void OfficeBlock::doBureaucracy(std::string const & formName, std::string const & target) {
	if (_intern == NULL)
		throw NoIntern();
	if (_signer == NULL)
		throw NoSigner();
	if (_executor == NULL)
		throw NoExecutor();
	Form * form;

	form = _intern->makeForm(formName, target);

	try
	{
		_signer->signForm(*form);
	}
	catch (std::exception & e)
	{
		delete form;
		throw e;
	}

	try
	{
		_executor->executeForm(*form);
	}
	catch (std::exception & e)
	{
		delete form;
		throw e;
	}

	delete form;
}

std::ostream & operator << (std::ostream & o, OfficeBlock const & target) {
	o << "OfficeBlock: ";
	
	o << "Intern: ";
	if (target.getIntern() == NULL)
		o << "Empty";
	else
		o << *target.getIntern();


	o << " Signer: ";
	if (target.getSigner() == NULL)
		o << "Empty";
	else
		o << *target.getSigner();

	o << " Executor: ";
	if (target.getExecutor() == NULL)
		o << "Empty";
	else
		o << *target.getExecutor();

	return o;
}

//Exceptions
char const * OfficeBlock::NoIntern::what() const throw() {return "No intern";}
char const * OfficeBlock::NoSigner::what() const throw() {return "No signer";}
char const * OfficeBlock::NoExecutor::what() const throw() {return "No executor";}