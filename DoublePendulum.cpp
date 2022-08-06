#include "DoublePendulum.h"
#include <cmath>

using std::sin;
using std::cos;

void DoublePendulum::step(float dt) {
	float d2omega_1 = (-gravity * (2 * mass_1 + mass_2) * sin(theta_1) - mass_2 * gravity * sin(theta_1 - 2 * theta_2) - 2 * sin(theta_1 - theta_2) * mass_2 * (omega_2 * omega_2 * length_2 + omega_1 * omega_1 * length_1 * cos(theta_1 - theta_2)))
		/ (length_1 * (2 * mass_1 + mass_2 - mass_2 * cos(2 * theta_1 - 2 * theta_2)));

	float d2omega_2 = (2 * sin(theta_1 - theta_2) * (omega_1 * omega_1 * length_1 * (mass_1 + mass_2) + gravity * (mass_1 + mass_2) * cos(theta_1) + omega_2 * omega_2 * length_2 * mass_2 * cos(theta_1 - theta_2)))
		/ (length_2 * (2 * mass_1 + mass_2 - mass_2 * cos(2 * theta_1 - 2 * theta_2)));

	omega_1 += d2omega_1 * dt;
	omega_2 += d2omega_2 * dt;

	theta_1 += omega_1 * dt;
	theta_2 += omega_2 * dt;
}

sf::Vector2f DoublePendulum::getRelativeCoordinatesM1(sf::Vector2f origin)
{
	return origin + sf::Vector2f(length_1 * sin(theta_1), length_1 * cos(theta_1));
}

sf::Vector2f DoublePendulum::getRelativeCoordinatesM2(sf::Vector2f origin)
{
	return getRelativeCoordinatesM1(origin) + sf::Vector2f(length_2 * sin(theta_2), length_2 * cos(theta_2));
}
