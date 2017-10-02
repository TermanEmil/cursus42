#ifndef MININGBARGE_HPP
# define MININGBARGE_HPP

# include "IMiningLaser.hpp"
# include "IAsteroid.hpp"

class MiningBarge
{
public:
	IMiningLaser * getMiningLaser (int index) const;
	int getMiningLaserCount (void) const;
	
	MiningBarge (void);
	MiningBarge (MiningBarge const & target);
	~MiningBarge (void);
	
	void equip (IMiningLaser * newMiningLaser);
	void mine (IAsteroid * asteroid) const;

	MiningBarge & operator = (MiningBarge const & target);

private:
	static int const _maxMiningLasers;
	IMiningLaser ** _miningLasers;

	void _init(void);
};

std::ostream & operator << (std::ostream & o, MiningBarge const & target);

#endif