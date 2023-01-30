#include "Atom.h"
#include "ElectroNegativityTable.h"
#include "Molecule.h"
#include "ErrorHandler.h"
#include "Bond.h"
#include <fstream>

template <class VectorType = Vector3>
std::ofstream& printV(std::ofstream& outputfile, const VectorType& vectordata) {
    if (!outputfile) { std::cerr << "error while outputting to file\n"; }
    static int num_calls = 0;
    num_calls++;
    if constexpr (std::is_same<VectorType, Vector3>::value){
        outputfile << vectordata.x << ", " << vectordata.y << ", " << vectordata.z << '\n';
    }
    return outputfile;
}

std::ofstream& printM(std::ofstream& outputfile, Molecule& m) {
    if (!outputfile) { std::cerr << "error while outputting to file\n"; }
    static int num_calls = 0;
    num_calls++;
    for (int i = 0; i < m.size; ++i) {
        for (int k = 0; k < i; ++k) {
            outputfile << "  ";
        }
        for (int j = i; j < m.size; ++j) {
            outputfile << static_cast<int>(m.Adjacency[i][j]) << ' ';
        }
        outputfile << '\n';
    }
    outputfile << "END" << '\n';
    return outputfile;
}

int main() {
    Atom Atoms1[5] = {
        Atom(Vector3(0, 0, 0), 6, 6, 6),
        Atom(Vector3(0, 0, 1), 1, 0, 1),
        Atom(Vector3(0, 0, 1).rodrigues_rotate(Vector3(1,1,0), 109.47*PI/180), 1, 0, 1),
        Atom(Vector3(0, 0, 1).rodrigues_rotate(Vector3(1,1,0), 109.47*PI/180).rodrigues_rotate(Vector3(0,0,1), 120*PI/180), 1, 0, 1),
        Atom(Vector3(0, 0, 1).rodrigues_rotate(Vector3(1,1,0), 109.47*PI/180).rodrigues_rotate(Vector3(0,0,1), -120*PI/180), 35, 44.904, 35)
    };

    std::initializer_list<std::initializer_list<Atom>> B1 = 
            {
                {Atoms1[1], Atoms1[2], Atoms1[3], Atoms1[4]},
                {Atoms1[0]},
                {Atoms1[0]},
                {Atoms1[0]},
                {Atoms1[0]}
            };

    Molecule CH3Br = Molecule::Create<5>(Atoms1, B1);
    Molecule::printadj(CH3Br);

    Atom Atoms2[2] = {
        Atom(Vector3(0, 1, 0), 1, 0, 1),
        Atom(Vector3(0, 2, 0), 35, 45, 35)
    };

    std::initializer_list<std::initializer_list<Atom>> B2 = 
        {
            {Atoms2[1]},
            {Atoms2[0]}
        };

    Molecule HBr = Molecule::Create<2>(Atoms2, B2);
    Molecule::printadj(HBr);

    std::ofstream file = std::ofstream("positions.txt");

    Molecule pmol = CH3Br;
    for (int i = 0; i < pmol.size; ++i) {
        printV(file, pmol.AtomSet[i].position);
    }

    pmol = HBr;
    for (int i = 0; i < pmol.size; ++i) {
        printV(file, pmol.AtomSet[i].position);
    }
    
    file.close();

    file = std::ofstream("bonds.txt");

    printM(file, CH3Br);
    printM(file, HBr);


    Atom a = Atom(Vector3(0,0,0),11,0,11);
    Atom b = Atom(Vector3(0,0,0),17,0,17);
    std::cout << A_Bonds::CheckPureCovalent(a, b) << '\n';
    std::cout << A_Bonds::CheckIonic(a,b) << '\n';
    std::cout << ElectroNegativity::ID(a) << ' ' << ElectroNegativity::ID(b) << '\n';


    file.close();
}
