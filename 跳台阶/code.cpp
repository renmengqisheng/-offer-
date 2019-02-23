class Solution {
public:
    int jumpFloor(int number) {
        if(number <= 2)
            return number;
        else
            return jumpFloor(number-1) + jumpFloor(number-2);
    }
};
