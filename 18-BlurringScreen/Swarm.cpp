/*
 * Swarm.cpp
 *
 *  Created on: 5 de mai de 2020
 *      Author: rfarah
 */

#include "Swarm.h"

namespace rfh {

Swarm::Swarm(): m_lastTime(0) {
	m_pParticle = new Particle[NPARTICLES];

}

Swarm::~Swarm() {
	delete[] m_pParticle;
}

void Swarm::update(int elapsed) {
	int interval = elapsed - m_lastTime;

	for (int i = 0; i < Swarm::NPARTICLES; i++) {
		m_pParticle[i].update(interval);
	}

	m_lastTime = elapsed;
}

} /* namespace rfh */
