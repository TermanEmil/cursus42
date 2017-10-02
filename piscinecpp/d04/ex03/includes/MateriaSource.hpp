#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include <string>
# include <iostream>

class MateriaSource : public IMateriaSource
{
public:
	int getCountMatsLearned (void) const;
	AMateria * getMat (int idx) const;

	MateriaSource (void);
	MateriaSource (MateriaSource const & target);
	~MateriaSource (void);

	void learnMateria (AMateria * target);
	AMateria * createMateria (std::string const & type);

	MateriaSource & operator = (MateriaSource const & target);

private:
	static int const _maxMatsToLearn;

	AMateria ** _learnedMateria;
};

std::ostream & operator << (std::ostream & o, MateriaSource const & target);

#endif