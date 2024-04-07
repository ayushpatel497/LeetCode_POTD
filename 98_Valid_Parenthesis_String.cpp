class Solution {
public:
    bool checkValidString(string s) {
        int leftPar=0,rightPar=0;
        int star=0;
        for(auto c:s)
        {
            if(c=='(')
                leftPar++;
            else if(c==')')
                rightPar++;
            else 
                star++;
            if(rightPar>leftPar+star)
                return false;
        }
        bool case1 = (leftPar+star>=rightPar);
        leftPar=0;
        rightPar=0;
        star=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]=='(')
                leftPar++;
            else if(s[i]==')')
                rightPar++;
            else 
                star++;
            if(leftPar>rightPar+star)
                return false;
        }
        bool case2 = (rightPar+star>=leftPar);
        return (case1 and case2);
    }
};