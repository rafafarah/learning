/*
 * Particle.h
 *
 *  Created on: 5 de mai de 2020
 *      Author: rfarah
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace rfh {

class Particle {
public:
	double m_x;
	double m_y;

	double m_speed;
	double m_direction;

public:
	Particle();
	virtual ~Particle();

	void update();
};

} /* namespace rfh */

#endif /* PARTICLE_H_ */
