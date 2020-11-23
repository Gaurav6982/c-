#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int l;
    cin>>l;
    stack<char> st;
    char s[l];
    // vector<char> occ;
    for(int i=0;i<l;i++)
    {
        cin>>s[i];
        st.push(s[i]);
        if(!st.empty()&&st.top()=='x')
        {
            st.pop();
            if(!st.empty() && st.top()=='o')
            {
                st.pop();
                if(!st.empty()&&st.top()=='f')
                st.pop();
                else
                {
                    st.push('o');
                    st.push('x');
                }
            }
            else
            st.push('x');
        }

    }
    cout<<st.size();
    return 0;
}