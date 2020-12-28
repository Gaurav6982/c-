#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    while(n--)
    {
        string s;
        cin>>s;
        int l=s.length();
        stack<char> st;
        int ques=0;
        for(int i=0;i<l;i++)
        {
            if(s[i]=='(')
            {
                st.push('(');
            }
            else if(s[i]==')')
            {
                if(st.empty())
                {
                   st.push(')');
                }
                else if(st.top()=='?'|| st.top()=='(')
                st.pop();
            }
            else
            {
                st.push('?');
            ques++;
            }
        }
        if(st.empty())
        cout<<"YES"<<endl;
        else 
        {
            int count=0;
            int brack=0;
            int open_br=0;
            while(!st.empty())
            {
                // cout<<st.top();
                if(st.top()=='?')
                {
                    st.pop();
                    if(!st.empty()&& st.top()=='(')
                    st.pop();
                    else
                    st.push('?');
                    if(st.empty())
                    break;
                }
                if(st.top()=='?')
                count++;
                else
                {
                    if(st.top()=='(')
                    open_br++;
                    brack++;
                }
                st.pop();
            }
            if((brack==0 && count%2==0) || (brack==open_br && open_br==count))
            cout<<"YES"<<endl;
            else
        cout<<"NO"<<endl;

        }

    }
    return 0;
}