/**
Time = O(n), n = max(num1.size(), num2.size())
Space = O(1)
**/

class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        auto p1 = getNum(num1);
        auto p2 = getNum(num2);
        int a1 = p1.first;
        int a2 = p2.first;
        int b1 = p1.second;
        int b2 = p2.second;
        
        int real = a1*a2 - b1*b2;
        int img = a1*b2 + a2*b1;
        // cout << a1 << " " << b1 << endl;
        // cout << a2 << " " << b2 << endl;
        string ans = to_string(real)+"+"+to_string(img)+"i";
        return ans;
    }
    
    pair<int,int> getNum(string num){
        int a = 0, b = 0;
        int signA = 1, signB = 1;
        bool seenDigit = 0, firstDone = 0;
        
        for(auto c:num){
            if(!seenDigit && c=='-'){
                signA = -1;
            }
            else if(!firstDone && c>='0' && c<='9'){
                a*=10;
                a+=(c-'0');
                seenDigit = 1;
            }
            else if(!firstDone && seenDigit && !(c>='0' && c<='9')){
                firstDone = 1;
            }
            else if(firstDone && c=='-'){
                signB = -1;
            }
            else if(firstDone && c>='0' && c<='9'){
                b*=10;
                b+=(c-'0');
            }
        }
        return {a*signA, b*signB};
    }
};
