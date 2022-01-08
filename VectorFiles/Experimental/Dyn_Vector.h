#pragma once
#include <iostream>
#include <cmath>
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342
class LOG{
public:
    template <typename TYPE>
    void log(TYPE input, std::string extra = ""){
        std::cout << "Console Log: " << input << extra;
    }
};

template <int Size>
class Vector{
public:
    float *vector;
    float vectorSize = Size;
    
    void input(){
        for (int i = 0; i < Size; i++){
            std::cin >> vector[i];
        }
    }

    void printvector(){
        std::cout << "(";
        for (int i = 0; i < Size - 1; i++){
            std::cout << vector[i] << ", ";
        }
        std::cout << vector[Size - 1] << ")\n";
    }
    
   float dotproduct(Vector<Size> inputvctr){
        float result = 0;
        for (int i = 0; i < Size; i++){
            result += vector[i] * inputvctr.vector[i];
        }
        return result;
    }

    float angle(Vector<Size> inputvctr){ // @Incorrect: always outputs value close to 90 degrees given any vector set
        float Product = dotproduct(inputvctr);
        float SQRTvctr1 = 0;
        float SQRTvctr2 = 0;
        
        //for (int i = 0; i < Size; i++){
        //    SQRTvctr1 += pow(vector[i], 2);
        //    SQRTvctr2 += pow(inputvctr.vector[i], 2);
        //}
        SQRTvctr1 = sqrt(pow(vector[0], 2) + pow(vector[1], 2) + pow(vector[2], 2));
        SQRTvctr2 = sqrt(pow(inputvctr.vector[0], 2) + pow(inputvctr.vector[1], 2) + pow(inputvctr.vector[2], 2));
        
        LOG console;
        
        console.log("input: ");
        inputvctr.printvector();
        console.log("current: ");
        printvector();

        console.log(Product, "\n");
        console.log(SQRTvctr1, "\n");
        console.log(SQRTvctr2, "\n");
        

        return acos(Product / (SQRTvctr1 * SQRTvctr2)) * (180 / PI);
    }

    Vector(){
        vector = new (std::nothrow) float[Size]{};
    }
    
    ~Vector(){
        delete[] vector;
        std::cout << "Deleted vector\n";
    }
};
