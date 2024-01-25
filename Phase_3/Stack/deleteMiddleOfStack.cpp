#include<iostream>
#include<stack>
using namespace std;

void middleDelete(stack<int> &st,int count){
    if(count == st.size()/2){
        st.pop();
        return;
    }
    int temp  = st.top();
    st.pop();

    middleDelete(st,count++);

    st.push(temp);
}

int main(){
    stack<int> st;
    int count = 1;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(70);
    st.push(80);

    stack<int> st1 = st; 
    for(int i= 0;i<st.size();i++){
        cout<<st1.top()<<" ";
        st1.pop();
    }
    cout<<endl;

    cout<<"Before delete middle size of the stack is"<<endl<<st.size()<<endl;
    middleDelete(st,count);
    cout<<"After delete middle size of the stack is"<<endl<<st.size()<<endl;

    stack<int> st2 = st; 
    for(int i= 0;i<st.size();i++){
        cout<<st2.top()<<" ";
        st2.pop();
    }
    cout<<endl;
    

    return 0;
}