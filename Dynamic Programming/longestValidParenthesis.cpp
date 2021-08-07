class Solution {
public:
    int longestValidParentheses(string s) {
        int start = 0, cntO = 0, cntC = 0, ans = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ')'){
                cntC++;                
            }
            
            else{
                cntO++;                
            }
            
            if(cntO == cntC)
                ans = max(ans, i-start+1);
            
            if(cntC > cntO){
                start = i+1;
                cntC = cntO = 0;
            }
            
        }
        
        
        cntO = cntC = 0;
        start = s.length()-1;
        
         for(int i = s.length()-1; i >= 0; i--){
            if(s[i] == ')'){
                cntC++;                
            }
            
            else{
                cntO++;                
            }
            
            if(cntO == cntC)
                ans = max(ans, start-i+1);
            
            if(cntO > cntC){
                start = i-1;
                cntC = cntO = 0;
            }
            
        }
        
 
        
        return ans;
    }
    
    // "()(()"
};


//or


public class Solution {

    public int longestValidParentheses(String s) {
        int maxans = 0;
        Stack<Integer> stack = new Stack<>();
        stack.push(-1);
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                stack.push(i);
            } else {
                stack.pop();
                if (stack.empty()) {
                    stack.push(i);
                } else {
                    maxans = Math.max(maxans, i - stack.peek());
                }
            }
        }
        return maxans;
    }



//imp case ()(()