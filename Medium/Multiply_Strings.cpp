/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

 

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
 

Constraints:

1 <= num1.length, num2.length <= 200
num1 and num2 consist of digits only.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
*/
class Solution {
public:
    string multiply(string num1, string num2) {
     
        
        if(num1 == "0" || num2 == "0") return "0";
        
        vector<int> num(num1.size() + num2.size(),0);
        
        //logic of the program
        for(int i= num1.size()-1; i>=0; i--)
        {
            for(int j = num2.size()-1; j>=0; j--)
            {
                num[i+j+1] += (num1[i]-'0')*(num2[j]-'0');
                num[i+j] += num[i+j+1]/10;
                num[i+j+1] %= 10;
            }
        }
        int i = 0;
        while(i < num.size() && num[i] ==0)
        {
            ++i;
        }
        string res = "";
        while(i < num.size())
        {
            res.push_back(num[i++] + '0');        
        }
        return res;
        
         
    }
};
