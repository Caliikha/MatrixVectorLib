#pragma once
#include "../VectorFiles/Vector2.hpp"
#include "../VectorFiles/Vector3.hpp"

template <auto expr>
constexpr const auto compiler_evaluation() { return expr; }

struct Constants {
    static constexpr const float Gravitational_Constant = 0.000081;
    static constexpr const float Radius_Of_Impact_Factor = 0.000000001;
    static constexpr const float Dampening_Factor = -0.00004432;
    static constexpr const Vector3 Universal_Expansion_Force_Factor = Vector3(0.000000000054,0.000000000054,0.000000000054);
};

template <class VectorDimension = Vector3>
class CelestialBody {
public:
    VectorDimension position;
    VectorDimension velocity;
    VectorDimension acceleration;
    VectorDimension der_acceleration;
    const uint32_t mass;

    constexpr CelestialBody (
            const uint32_t& i_mass = 0, 
            const VectorDimension& i_position = VectorDimension(), 
            const VectorDimension& i_velocity = VectorDimension(), 
            const VectorDimension& i_acceleration = VectorDimension(), 
            const VectorDimension& i_der_acceleration = VectorDimension()) 
        : mass(i_mass), position(i_position), velocity(i_velocity), acceleration(i_acceleration), der_acceleration(i_der_acceleration) {}

    CelestialBody(const CelestialBody<VectorDimension>& input) {
        this->position = input.position;
        this->velocity = input.velocity;
        this->acceleration = input.acceleration;
        this->der_acceleration = input.der_acceleration;
    } 

    static inline constexpr Vector3 phy_update_pos(CelestialBody<VectorDimension>& input) noexcept;
    inline constexpr Vector3 phy_update_pairwise_force_interaction(CelestialBody<VectorDimension>& input) noexcept;
    inline bool phy_evaluate_pairwise_collision_factor(CelestialBody<VectorDimension>& input) noexcept;
};

template <class VectorDimension>
constexpr Vector3 CelestialBody<VectorDimension>::phy_update_pos(CelestialBody<VectorDimension>& input) noexcept {
    if (input.mass > 999) { return input.position; }
    input.acceleration += input.der_acceleration;
    input.velocity += input.acceleration; //+ input.position.unitvector().scale(Constants::Universal_Expansion_Force_Factor.magnitude());// - Constants::Dampening_Factor;
    input.acceleration = 0;
    return input.position += input.velocity;
}

template <class VectorDimension>
constexpr Vector3 CelestialBody<VectorDimension>::phy_update_pairwise_force_interaction(CelestialBody<VectorDimension>& input) noexcept {
    const Vector3 pairwise_distance_evaluation = input.position - this->position; 
    return (pairwise_distance_evaluation).scale(input.mass * Constants::Gravitational_Constant / pow(pairwise_distance_evaluation.magnitude(), 3));
}

template <class VectorDimension>
bool CelestialBody<VectorDimension>::phy_evaluate_pairwise_collision_factor(CelestialBody<VectorDimension>& input) noexcept {
    const float Radius_Of_Impact = this->mass * Constants::Radius_Of_Impact_Factor;
        if constexpr (std::is_same<VectorDimension, Vector3>::value){
            return 
                (this->position.x <= input.position.x + Radius_Of_Impact) && (this->position.x > input.position.x - Radius_Of_Impact) &&
                (this->position.y <= input.position.y + Radius_Of_Impact) && (this->position.y > input.position.y - Radius_Of_Impact) &&
                (this->position.z <= input.position.z + Radius_Of_Impact) && (this->position.z > input.position.z - Radius_Of_Impact);
        }
        else if constexpr (std::is_same<VectorDimension, Vector2>::value) {
            return 
                (this->position.x <= input.position.x + Radius_Of_Impact) && (this->position.x > input.position.x - Radius_Of_Impact) &&
                (this->position.y <= input.position.y + Radius_Of_Impact) && (this->position.y > input.position.y - Radius_Of_Impact);
        }
    return false;
}
