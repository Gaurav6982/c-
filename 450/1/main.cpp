//traverse a matrix in sprial way

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        int mat[m][n];
        rep(i,m) rep(j,n) cin>>mat[i][j];
        int min_x=0;
        int max_x=m;
        int min_y=0;
        int max_y=n;
        int i=0;
        while(min_x<max_x || min_y<max_y)
        {
            //to print a rigth move
            for(int j=min_y;j<max_y;j++)
            {
                cout<<mat[min_x][j]<<" ";
            }
            min_x++;
            
            cout<<endl;
            //down move
            for(int j=min_x;j<max_x;j++)
            cout<<mat[j][max_y-1]<<" ";
            max_y--;
cout<<endl;
            // left move
            for(int j=max_y-1;j>=min_y;j--)
            {
                cout<<mat[max_x-1][j]<<" ";
            }
            max_x--;
           cout<<endl; // if(i==0)
            // {
            //     cout<<"\n========="<<endl;
            //     cout<<min_y<<endl;
            //     cout<<"========="<<endl;
            //     cout<<"\n========="<<endl;
            //     cout<<max_x<<" "<<min_x<<endl;
            //     cout<<"========="<<endl;
            // }
            //up move
            for(int j=max_x-1;j>=min_x;j--)
            {
                cout<<mat[j][min_y]<<" ";
            }
            min_y++;
            i++;
            cout<<endl;
        }
        cout<<endl;
    }

}