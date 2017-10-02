#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <string>
# include <iostream>

class Victim
{
public:
	static std::string const color;

	std::string const & getName(void) const;

	Victim (Victim const & target);
	Victim (std::string const & name);
	virtual ~Victim (void);

	virtual void GetPolymorphed (void) const;

protected:
	std::string const _name;

	virtual void _init (void);

private:
	Victim (void);
};

std::ostream & operator << (std::ostream & o, Victim const & target);

#endif