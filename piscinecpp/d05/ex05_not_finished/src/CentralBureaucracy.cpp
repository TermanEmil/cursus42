#include "CentralBureaucracy.hpp"

int const CentralBureaucracy::maxOfficeBlocks = 20;


OfficeBlock ** CentralBureaucracy::getOfficeBlocks (void) const {return _officeBlocks;}


CentralBureaucracy::CentralBureaucracy (void) {
	_init();
}

CentralBureaucracy::CentralBureaucracy (CentralBureaucracy const & target) {
	*this = target;
}

CentralBureaucracy::~CentralBureaucracy (void) {
	for (int i = 0; i < maxOfficeBlocks; i++)
		if (_officeBlocks[i])
			delete _officeBlocks[i];
	delete _officeBlocks;
}

//Methods
void CentralBureaucracy::feedBureaucrats (Bureaucrat & newBureaucrat) {
	for (int i = 0; i < maxOfficeBlocks; i++) {
		if (_officeBlocks[i]->getSigner() == NULL) {
			_officeBlocks[i]->setSigner(newBureaucrat);
			break;
		} else if (_officeBlocks[i]->getExecutor() == NULL) {
			_officeBlocks[i]->setExecutor(newBureaucrat);
			break;
		}
	}
	throw NoSeatsAvailable();
}

void CentralBureaucracy::_init (void) {
	_officeBlocks = new OfficeBlock * [maxOfficeBlocks];
	for (int i = 0; i < maxOfficeBlocks; i++) {
		Intern * randomIntern = new Intern();
		_officeBlocks[i] = new OfficeBlock();
		_officeBlocks[i]->setIntern(*randomIntern);
	}

	_formQuee = new Form * [0];
	_formQueeCount = 0;
}

//Operators
CentralBureaucracy & CentralBureaucracy::operator = (CentralBureaucracy const & target) {
	for (int i = 0; i < maxOfficeBlocks; i++)
		_officeBlocks[i] = target.getOfficeBlocks()[i];
	return *this;
}

std::ostream & operator << (std::ostream & o, CentralBureaucracy const & target) {
	(void)target;
	return o;
}

//Exceptions
char const * CentralBureaucracy::NoSeatsAvailable::what() const throw() {
	return "No seats avaialable";
}