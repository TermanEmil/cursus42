#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <string>
# include <iostream>

class Enemy
{
public:
	int getHP (void) const;
	int getMaxHP (void) const;
	std::string const & getType (void) const;

	void setHp (int newHp);

	Enemy (void);
	Enemy (Enemy const & target);
	Enemy (int hp, std::string const & type);
	virtual ~Enemy (void);

	virtual void takeDamage (int amount);

protected:
	int _hp;
	int const _maxHP;
	std::string const _type;
};

std::ostream & operator << (std::ostream & o, Enemy const & target);

#endif