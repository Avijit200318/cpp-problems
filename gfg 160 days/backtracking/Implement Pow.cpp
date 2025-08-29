// recursion
// class Solution {
//   public:
//     double helper(double b, int e){
//         if(e == 0) return 1;
//         return helper(b, e-1) * b;
//     }
    
//     double power(double b, int e) {
//         if(e == 0) return 1;
//         if(e > 0) return power(b, -e);
     
//         double temp = power(b, e/2);
//     }
// };

// optimal approch
// if the vlue of e is even then we need to return pow(b, e/2) * pow(b, e/2)
// but if it odd then we need to add a 'b' extra. so we need to return return pow(b, e/2) * pow(b, e/2) * b

class Solution {
  public:
    double power(double b, int e) {
        if(e == 0) return 1;
        if(e < 0) return 1/power(b, -e);
     
        double temp = power(b, e/2);
        if(e % 2 == 0) return temp * temp;
        return temp * temp * b;
    }
};
