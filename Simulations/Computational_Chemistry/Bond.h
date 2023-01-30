#pragma once
#include "Atom.h"
#include "ElectroNegativityTable.h"

class A_Bonds {
public:
    std::initializer_list<Atom> bonds;
    inline constexpr A_Bonds(const std::initializer_list<Atom>& bond_input) : bonds(bond_input) {}

    inline bool static constexpr CheckPureCovalent(Atom a, Atom b) {
        if (static_cast<float>(Atom::ValenceDesired(a) - a.valence())
            / (Atom::ValenceDesired(b) - b.valence()) == 
            (Atom::ValenceDesired(a) - a.valence()) / (Atom::ValenceDesired(b) - b.valence())
         || static_cast<float>(Atom::ValenceDesired(b) - b.valence())
            / (Atom::ValenceDesired(a) - a.valence()) == 
            (Atom::ValenceDesired(b) - b.valence()) / (Atom::ValenceDesired(a) - a.valence())
         && std::abs(ElectroNegativity::ID(a) - ElectroNegativity::ID(b) < 0.4)) {
            return true;
        }
        return false;
    }

    inline bool static constexpr CheckIonic(Atom a, Atom b) {
        if (
          ((a.valence() - Atom::ValenceDesired(a) > 0 && b.valence() - Atom::ValenceDesired(b) < 0)
        &&  std::abs(b.valence() - Atom::ValenceDesired(b)) <= std::abs(a.valence() - Atom::ValenceDesired(a)))
        
        || ((a.valence() - Atom::ValenceDesired(a) < 0 && b.valence() - Atom::ValenceDesired(b) > 0)
        &&  std::abs(b.valence() - Atom::ValenceDesired(b)) >= std::abs(a.valence() - Atom::ValenceDesired(a)))

        &&  std::abs(ElectroNegativity::ID(a) - ElectroNegativity::ID(b) > 1.8)) {
            return true;
        }
        return false;
    }
};
