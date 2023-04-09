/*
 * Swarm.cpp
 *
 *  Created on: 5 de mai de 2020
 *      Author: rfarah
 */

#include "Swarm.h"

namespace rfh {

Swarm::Swarm() {
	m_pParticle = new Particle[NPARTICLES];

}

Swarm::~Swarm() {
	delete[] m_pParticle;
}

void Swarm::update() {
	for (int i = 0; i < Swarm::NPARTICLES; i++) {
		m_pParticle[i].update();
	}
}

} /* namespace rfh */
