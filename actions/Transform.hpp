#ifndef LABO_04_TRANSFORM_HPP
#define LABO_04_TRANSFORM_HPP

#include "Kill.hpp"

/**
 * @authors Lange Yanik, Tomic Mario
 * @brief Specialisation of kill, but for the vampires. A successful kill can spawn vampires
 */
class Transform : public Kill {
public:
    /**
     * Constructor
     * @param humanoid Humanoid to be killed and eventually transformed
     */
    explicit Transform(const std::shared_ptr<Humanoid>& humanoid);

    /**
     * Kills the humanoid and has a 50% chance of transforming it to a vampire
     * @param field Field where the humanoid is on
     */
    void execute(Field& field) override;
};


#endif //LABO_04_TRANSFORM_HPP
