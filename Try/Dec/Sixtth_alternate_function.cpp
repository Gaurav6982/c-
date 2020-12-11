#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
void rotate(string& a,int i,int j)
{
    while(i<j)
    {
        char temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        i++;
        j--;
    }
}
bool isPalindrome(string a,int i,int j)
{
    while(i<j)
    {
        if(a[i]!=a[j])
        return false;
        i++;
        j--;
    }
    return true;
}
int ones(string a,int i,int j)
{
    int one=0;
    while(i<=j)
    {
        if(a[i]=='1')
        one++;
        i++;
    }
    return one;
}
bool find(string& a,string &b)
{
    int i=0,j=a.length()-1;
    // int l=10;
    while(i<j )
    {
        cout<<a<<" "<<b<<endl;
        if(a[i]==b[i] && a[j]==b[j])
        {
            i++;
            j--;
        }
        else if(a[i]==b[i])
        {
            i++;
        }
        else if(a[j]==b[j])
        {
            j--;
        }
        else
        {
            int ones_in_a=ones(a,i,j);
            int ones_in_b=ones(b,i,j);
            cout<<ones_in_a<<" "<<ones_in_b<<endl;
            if(ones_in_a!=ones_in_b) return false;
            int actual_j=j; 
            if(ones_in_b%2!=0)
            {
                // cout<<"andar aaya"<<endl;
                int k;
                for(k=j;k>=i;k--)
                {
                    if(b[k]=='1')
                    {
                        actual_j=k;
                        if(k!=j)
                        {
                            // cout<<"break hua"<<endl;
                            if(ones(b,i,k)%2==0 && b[k]==a[i])
                            break;
                        }
                    }
                }
                // cout<<k<<" "<<j<<" "<<i<<endl;
                if(k<=i)
                return false;
            }
            else if(isPalindrome(b,i,j))
            {
                // if(ones_in_b==2)
                // return false;

                int k;
                // int temp=2;
                for(k=j;k>=i;k--)
                {
                    // if(ones(b,i,k)%2==0 && b[k]==a[i])
                    // break;
                    if(b[k]==a[i])
                    {
                        actual_j=k;
                        // temp--;
                        if(ones(b,i,k)%2==0)
                        break;
                    }
                }
                if(k<=i)
                return false;
            }
            else if(b[j]!=a[i])
            {
                int k;
                for(k=j;k>=i;k--)
                {
                    if(b[k]==a[i])
                    {
                        actual_j=k;
                        if(k!=j)
                        {
                            // cout<<"break hua"<<endl;
                            break;
                        }
                    }
                }
                // cout<<k<<" "<<j<<" "<<i<<endl;
                if(k<=i)
                return false;
                // cout<<"idhar aaya"<<endl;
            }
            rotate(b,i,actual_j);
        }
    }
    if(a.compare(b)==0)
    return true;
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a,b;
    cin>>a>>b;
    cout<<find(a,b)<<endl;
    // rotate(b,0,b.length()-2);
    cout<<a<<" "<<b;
    return 0;
}