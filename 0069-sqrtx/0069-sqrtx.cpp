class Solution {
public:
//when elements are in increasing order their square root is also in increasing order hence we can use binary search in both square ands square root
//25 square root is always less than 25/2 
//hence we can take x/2 not x 
    int mySqrt(int x) {
     int left =1, right=x/2;
     if(x ==1){
        return 1;
     }
     while(left<=right){
        int mid = left+(right-left)/2;
        long long square = (long)(long)mid*mid;
        if(square == x){
         return mid;
        }
        else if(square<x){
            left = mid+1;
        }
        else if(square>x){
            right = mid-1;
        }
     }
     return right;
    }
};
/*if (mid > x / mid) { using this method can be useful if we donot want to use long
    right = mid - 1;
} else {
    left = mid + 1;
}*/