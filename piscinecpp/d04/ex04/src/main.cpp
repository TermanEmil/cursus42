#include "AsteroKreog.hpp"
#include "KoalaSteroid.hpp"
#include "StripMiner.hpp"
#include "DeepCoreMiner.hpp"
#include "MiningBarge.hpp"

int main(void) {
	MiningBarge barge;

	barge.equip(new StripMiner());
	barge.equip(new DeepCoreMiner());

	barge.equip(new DeepCoreMiner());
	barge.equip(new DeepCoreMiner());
	barge.equip(new DeepCoreMiner());
	
	
	barge.mine(new KoalaSteroid());
	barge.mine(new AsteroKreog());
	barge.mine(NULL);

	return 0;
}