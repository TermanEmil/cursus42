#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP

# include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{
public:
	AssaultTerminator (void);
	AssaultTerminator (AssaultTerminator const & target);
	~AssaultTerminator (void);
	
	ISpaceMarine * clone() const;
	void battleCry (void) const;
	void rangedAttack (void) const;
	void meleeAttack (void) const;

	AssaultTerminator & operator = (AssaultTerminator const & target);
};

std::ostream & operator << (std::ostream & o, AssaultTerminator const & target);

#endif