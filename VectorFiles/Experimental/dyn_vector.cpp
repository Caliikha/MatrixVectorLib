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
        float SQRTvctr1 = 0;
        float SQRTvctr2 = 0;
        
        for (int i = 0; i < Size; i++){
           SQRTvctr1 += pow(vector[i], 2);
           SQRTvctr2 += pow(inputvctr.vector[i], 2);
        }
//        SQRTvctr1 = sqrt(pow(vector[0], 2) + pow(vector[1], 2) + pow(vector[2], 2)); //        SQRTvctr2 = sqrt(pow(inputvctr.vector[0], 2) + pow(inputvctr.vector[1], 2) + pow(inputvctr.vector[2], 2)); 
        float Product = dotproduct(inputvctr);

//        console.log(Product, "\n");
//        console.log(SQRTvctr1, "\n");
//        console.log(SQRTvctr2, "\n");
        return acos(Product / (sqrt(SQRTvctr1) * sqrt(SQRTvctr2))) * (180 / PI);
    }

    Vector(){
        vector = new (std::nothrow) float[Size]{};
    }
    
    ~Vector(){
        delete[] vector;
        std::cout << "Deleted vector\n";
    }
};

int main()
{
    Vector<3> vec;
    vec.input();
    vec.printvector();
    Vector<3> vec2;
    vec2.input();
    vec2.printvector();
    std::cout << vec.angle(vec2) << "\n";
}
