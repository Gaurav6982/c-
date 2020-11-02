#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
void mul(ll mat[][2],ll mat1[][2])
{
    ll id[2][2];
    id[0][0]=id[1][1]=0;
    id[1][0]=id[0][1]=0;

    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<2;k++)
            {
                id[i][j]+=((mat[i][k]%mod)*(mat1[j][k]%mod))%mod;
            }
        }
    }
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            mat[i][j]=id[i][j];
        }
    }

    
}
void power(ll mat[][2],ll n)
{
    ll id[2][2];
    id[0][0]=id[1][1]=1;
    id[1][0]=id[0][1]=0;

    while(n>0)
    {
        if(n%2!=0)
        {
            mul(id,mat);
            n--;
        }
        else
        {
            mul(mat,mat);
            n/=2;
        }
    }
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            mat[i][j]=id[i][j];
        }
    }
}
ll find(ll n)
{
    if(n==0)
    return 0;
    ll mat[2][2];
    mat[0][0]=0;
    mat[1][0]=mat[0][1]=mat[1][1]=1;
    
    power(mat,n-1);
    // for(int i=0;i<2;i++)
    // {
    //     for(int j=0;j<2;j++)
    //     {
    //         cout<<mat[i][j]<<" ";
    //     }
    //  cout<<endl;
    // }
    return mat[1][1]%mod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    cout<<find(n);
    return 0;
}

//1st term is 0 so [1][1] is result.