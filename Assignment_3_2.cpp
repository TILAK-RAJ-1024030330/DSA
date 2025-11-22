#include<iostream> 
#include<stack> 
#include<string> 
using namespace std;
void reverseSentence(string s){
    stack<string>st; 
    string word; 

    for(int i=s.length()-1;i>=0;i--){
        word+=s[i];
    }

st.push(word);

    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
}


int main(){
     string s="DataStructure"; 
     reverseSentence(s); 
     return 0;
}
