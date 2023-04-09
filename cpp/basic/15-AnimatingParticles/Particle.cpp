/*
 * Particle.cpp
 *
 *  Created on: 5 de mai de 2020
 *      Author: rfarah
 */

#include <stdlib.h>
#include "Particle.h"

namespace rfh {

Particle::Particle() {
	m_x = ((2.0 * rand()) / RAND_MAX) - 1;
	m_y = ((2.0 * rand()) / RAND_MAX) - 1;
	m_xspeed = (0.005 * (((2.0 * rand()) / RAND_MAX) - 1));
	m_yspeed = (0.005 * (((2.0 * rand()) / RAND_MAX) - 1));
}

Particle::~Particle() {
	// TODO Auto-generated destructor stub
}

void Particle::update() {
	m_x += m_xspeed;
	m_y += m_yspeed;

	if (m_x <= -1.0 || m_x >= 1.0) {
		m_xspeed *= -1;
	}

	if (m_y <= -1.0 || m_y >= 1.0) {
		m_yspeed *= -1;
	}
}

} /* namespace rfh */
