class Solution {
public:
    string addStrings(string num1, string num2) {
        int size1 = num1.size();
        int size2 = num2.size();
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(), num2.end());
        
        string sum = "";
        int carry = 0;
        
        for(int i = 0; i<max(size1,size2); i++){
            int cur_sum = 0;
            if(i<size1){
                cur_sum+=num1[i]-'0';
            }
            if(i<size2){
                cur_sum+=num2[i]-'0';
            }
            cur_sum+=carry;
            sum+=(cur_sum%10+'0');
            carry = cur_sum/10;
        }
        if(carry)
            sum+=(carry+'0');
        reverse(sum.begin() , sum.end());
        return sum;
        
    }
};
