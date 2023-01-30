#pragma once
#include "Atom.h"
#include "Optimizer.h"
#include "ErrorHandler.h"
#include "ElectroNegativityTable.h"
#include <iostream>
#include <vector>
#include "../../VectorFiles/Vector3.hpp"

class Molecule {
public:
    Atom* AtomSet;
    uint8_t size;
    uint8_t** Adjacency;
    inline constexpr Molecule(int size_in = 0) {
        this->size = size_in;
        Adjacency = new uint8_t*[size];
        for (uint16_t i = 0; i < size; i++) {
            Adjacency[i] = new uint8_t[size];
        }
    }

    template <std::size_t cardinality>
    inline static Molecule Create(Atom* Atoms_input, std::initializer_list<std::initializer_list<Atom>> Bonds) {
        Molecule new_molecule(Bonds.size());
        new_molecule.AtomSet = Atoms_input;
        new_molecule.size = Bonds.size();

        if (cardinality != Bonds.size()) {
            std::cout << "Atom set and Bond initializer list size mismatch <" << cardinality << "> " << Bonds.size() << '\n';
            return ERROR::MOLECULE_CREATE_ERR;
        }
        // TODO: FIX THIS BAD HACK
        for (uint16_t i = 0; i < Bonds.size(); i++) {
            for (uint16_t j = 0; j < (Bonds.begin() + i)->size(); j++) {
                for (uint16_t k = 0; k < new_molecule.size; k++) {
                    if (*((Bonds.begin() + i)->begin() + j) == Atoms_input[k]){
                        new_molecule.Adjacency[i][k] += 1;
                    }
                }
            }
        }
        return new_molecule;
    }

    inline void static printadj(Molecule& m) {
        for (int i = 0; i < m.size; ++i) {
            for (int j = 0; j < m.size; ++j) {
                std::cout << static_cast<int>(m.Adjacency[i][j]) << ' ';
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }

    inline Vector3 static constexpr ComputeDipole(Molecule& m) {
        Vector3 e = Vector3(0,0,0);
        for (int i = 0; i < m.size; ++i) {
            for (int j = i + 1; j < m.size; ++j) {
                e += (m.AtomSet[i].position - m.AtomSet[j].position).unitvector() 
                   * (ElectroNegativity::ID(m.AtomSet[i]) - ElectroNegativity::ID(m.AtomSet[j]));
            }
        }
        return e;
    }

    inline constexpr ~Molecule() {
        const constexpr uint16_t AtomSet_cardinality = sizeof(AtomSet)/sizeof(*AtomSet);
        if (AtomSet_cardinality > 0) { 
            for (uint16_t i = 0; i < AtomSet_cardinality; i++) {
                if (Adjacency[i] != nullptr) {
                    delete[] Adjacency[i];
                }
            }
            if (Adjacency != nullptr) {
                delete[] Adjacency;
            }
        }
    }
};
