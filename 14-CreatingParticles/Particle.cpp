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
	m_x = ((2.0 * rand())/RAND_MAX) - 1;
	m_y = ((2.0 * rand())/RAND_MAX) - 1;
}

Particle::~Particle() {
	// TODO Auto-generated destructor stub
}

} /* namespace rfh */
