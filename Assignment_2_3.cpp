#include<iostream> 
#include<stack> 
#include<string> 
using namespace std;

bool Balanced(string s){
     stack<char>st; 
     for(int i=0;i<s.length();i++){
        if(s[i]=='{'||s[i]=='('||s[i]=='['){
             st.push(s[i]); 
         }
        else if(s[i]=='}'||s[i]==')'||s[i]==']'){
            if(st.empty()){
                return false;
            }
    if((s[i]=='}'&&st.top()=='{') || 
    (s[i]==')'&&st.top()=='(') || (s[i]==']'&&st.top()=='[')){
      st.pop(); 
    }
    else{
         return false;
    }
}
}
return st.empty();
}
int main(){
    string expression; 
    cout<<"Enter an expression: "; 
    cin>>expression;
    if(Balanced(expression)){
        cout<<"Balanced parenthesis"<<endl;
    }
    else {
    cout<<"Unbalanced parenthesis"<<endl;
    }
    return 0;
}