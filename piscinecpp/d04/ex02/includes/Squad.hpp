#ifndef SQUAD_HPP
# define SQUAD_HPP

# include "ISquad.hpp"

class Squad : public ISquad
{
public:
	int getCount (void) const;
	ISpaceMarine * getUnit(int i) const;

	Squad (void);
	Squad (Squad const & target);
	~Squad (void);

	int push (ISpaceMarine * newUnit);

	Squad & operator = (Squad const & target);

private:
	ISpaceMarine ** _units;
	int _squad_size;
};

std::ostream & operator << (std::ostream & o, Squad const & target);

#endif