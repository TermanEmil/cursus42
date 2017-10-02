#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP

# include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine
{
public:
	TacticalMarine (void);
	TacticalMarine (TacticalMarine const & target);
	~TacticalMarine (void);
	
	ISpaceMarine * clone() const;
	void battleCry (void) const;
	void rangedAttack (void) const;
	void meleeAttack (void) const;

	TacticalMarine & operator = (TacticalMarine const & target);
};

std::ostream & operator << (std::ostream & o, TacticalMarine const & target);

#endif