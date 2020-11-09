#include <bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int formula(int i,int j,int k){
    return k+1-abs(j-i);
}
int get_range(vector<int> vec,int num)
{
    return upper_bound(vec.begin(),vec.end(),num)-vec.begin();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	// int t=abs(rand())%10+1;
    int t=5;
	// cin>>t;
    cout<<t<<endl;
	while(t--)
	{
		cout<<"================="<<endl;
		int n,k;
		n=abs(rand())%10+1;
		k=abs(rand())%10+1;
		// cin>>n>>k;
		cout<<n<<" "<<k<<endl;
		// string given;
		// cin>>given;
		char given[n];
		char arr[4];
		arr[0]='M';
		arr[1]='I';
		arr[2]='_';
		arr[3]='X';
		for(int i=0;i<n;i++)
		{
			int index=abs(rand())%4;
			given[i]=arr[index];
		}
		for(int i=0;i<n;i++)
		cout<<given[i]<<" ";
		cout<<endl;
		vector<int> Xis;
		Xis.push_back(-1);
		for(int i=0;i<n;i++)
		{
			if(given[i]=='X')
			Xis.push_back(i);
		}
		Xis.push_back(n);
		int ans=0;
		for(int i=0;i<Xis.size()-1;i++)
		{
			int start=Xis[i];
			int end=Xis[i+1];
			// cout<<start<<" "<<end;
			for(int j=start+1;j<end;j++)
			{
				if(given[j]=='M')
				{
					int min_val=INT_MAX;
					int min_ind=n;
					for(int l=start+1;l<end;l++)
					{
						if(given[l]=='I')
						{
							int val=formula(j,l,k);
							if(val>0 && val<min_val)
							{
								min_val=val;
								min_ind=l;
							}
						}
					}
					if(min_ind!=n)
					{
						if(given[min_ind]=='I')
						{
							given[min_ind]='_';
							ans++;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
