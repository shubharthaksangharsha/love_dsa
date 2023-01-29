//https://www.codingninjas.com/codestudio/problems/valid-parenthesis_795104

bool solve(char top, char ans){
    if (top == '(' && ans == ')' || 
       top == '{' && ans == '}' || 
       top == '[' && ans == ']'){
        return true;
    }
    return false;
}

bool isValidParenthesis(string expression)
{
    stack<char>s;
    for(int i = 0; i < expression.size(); i++){
        char ans = expression[i];
        if (ans == '[' || ans == '(' || ans =='{'){
            //opening bracket
            s.push(ans);
        } else {
            //closing bracket 
                if (!s.empty()){
                    char top = s.top();
                    if (solve(top, ans)){
                        s.pop();
                    } else {
                        return false;
                    }
                } else{
                    return false;
                }    
            }
        }
    return (s.empty());
}