#pragma once 
#include <iostream>
#include "../../VectorFiles/Vector3.hpp"
#include "Optimizer.h"

class Atom {
public:
    Vector3 position;
    const uint8_t protons;
    const float neutrons;
    uint8_t electrons;
public:
    inline constexpr Atom(const Vector3 pos = Vector3(0,0,0), const int& p = -1, const int& n = -1, const int& e = -1)
        : position(pos), protons(p), neutrons(n), electrons(e) {
            if (electrons == -1) {
                electrons = p;
            }
        }

    inline uint32_t constexpr valence() {
        switch (this->electrons) {
            case 1: case 3: case 11: case 19: case 37: case 55: case 87:
                return 1;
            case 2: case 4: case 12: case 20: case 38: case 56: case 88:
                return 2;
            case 5: case 13: case 21: case 31: case 39: case 49: case 57: case 71: case 81: case 89: case 103: case 113:
                return 3;
            case 6: case 14: case 22: case 32: case 40: case 50: case 58: case 72: case 82: case 90: case 104: case 114:
                return 4;
            case 7: case 15: case 23: case 33: case 41: case 51: case 59: case 73: case 83: case 91: case 105: case 115:
               return 5;
            case 8: case 16: case 24: case 34: case 42: case 52: case 60: case 74: case 84: case 92: case 106: case 116:
               return 6;
            case 9: case 17: case 25: case 35: case 43: case 53: case 61: case 75: case 85: case 93: case 107: case 117:
               return 7;
            case 10: case 18: case 26: case 36: case 44: case 54: case 62: case 76: case 86: case 94: case 108: case 118:
               return 8;
            case 27: case 45: case 63: case 77: case 95: case 109:
               return 9;
            case 28: case 46: case 64: case 78: case 96: case 110:
               return 10;
            case 29: case 47: case 65: case 79: case 97: case 111:
               return 11;
            case 30: case 48: case 66: case 80: case 98: case 112:
               return 12;
            case 67: case 99:
               return 13;
            case 68: case 100:
               return 14;
            case 69: case 101:
               return 15;
            case 70: case 102:
               return 16;
        }
    }

    inline uint16_t static constexpr ValenceDesired(Atom a) {
        for (int i = 1; i <= 8; ++i) {
            if (a.electrons <= 2 * i*i) {
                if (a.electrons - 2 * (i-1)*(i-1) < 2 * i*i - a.electrons) {
                    return 2 * (i-1)*(i-1);
                }
                else {
                    return 2 * i*i;
                }
            }
        }
        return -1;
    }

    bool inline constexpr operator==(const Atom& rhs) {
        return this->position.x == rhs.position.x && this->position.y == rhs.position.y && this->position.z == rhs.position.z && this->protons == rhs.protons && this->neutrons == rhs.neutrons && this->electrons == rhs.electrons;
    }
};
