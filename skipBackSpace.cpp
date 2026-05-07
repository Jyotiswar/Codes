#include<iostream>
#include<algorithm>
using namespace std;

class solution{
    
    bool skipIfSpace(string s, string t){

        int skipS = 0, skipT = 0;
        int i = s.size()-1, j=t.size()-1;
        
        while(i >= 0 || j>=0){

            if(i >= 0 && (s[i] == '#' || skipS > 0)){

                if(s[i] == '#'){
                    skipS++;
                }else{
                    skipS--;
                }
                i--;
                continue;
            }

            if(j >= 0 && (t[j] == '#' || skipT > 0)){
                if(t[j] == '#'){
                    skipT++;
                }else{
                    skipT--;
                }
                j--;
                continue;
            }

            if(i>=0 && j>=0){
                if(s[i] != t[j]) return false;
            }else if((i>=0) != (j>=0)){
                return false;
            }

            i--;
            j--;
        }
        return true;
    } 
};