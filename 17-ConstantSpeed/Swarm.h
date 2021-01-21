/*
 * Swarm.h
 *
 *  Created on: 5 de mai de 2020
 *      Author: rfarah
 */

#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace rfh {

class Swarm {
public:
	const static int NPARTICLES = 5000;

private:
	Particle * m_pParticle;
	int m_lastTime;

public:
	Swarm();
	virtual ~Swarm();

	const Particle * const getParticles() { return m_pParticle; };
	void update(int elapsed);
};

} /* namespace rfh */

#endif /* SWARM_H_ */
