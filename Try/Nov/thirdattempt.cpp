#include <bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	// int t=abs(rand())%10+1;
    int t;
	cin>>t;
    // cout<<t<<endl;
	while(t--)
	{
// 		cout<<"================="<<endl;
		int n,k;
// 		n=abs(rand())%20+1;
// 		k=abs(rand())%10+1;
		cin>>n>>k;
// 		cout<<n<<" "<<k<<endl;
		string given;
		cin>>given;
// 		char given[n];
// 		char arr[4];
// 		arr[0]='M';
// 		arr[1]='I';
// 		arr[2]='_';
// 		arr[3]='X';
// 		for(int i=0;i<n;i++)
// 		{
// 			int index=abs(rand())%4;
// 			given[i]=arr[index];
// 		}
// 		for(int i=0;i<n;i++)
// 		cout<<given[i]<<" ";
// 		cout<<endl;
		vector<int> Xis;
		Xis.push_back(-1);
		for(int i=0;i<n;i++)
		{
			if(given[i]=='X')
			Xis.push_back(i);
		}
		Xis.push_back(n);
		// cout<<"This is Xis"<<endl;
		// for(int i=0;i<Xis.size();i++)
		// cout<<Xis[i]<<" ";
		// cout<<endl;
		vector<int> Ms;
		vector< pair<int,int> > nums;
		// cout<<"This is NUms:"<<endl;
// 		Ms.push_back(-2);
		for(int i=0;i<n;i++)
		{
			if(given[i]=='M')
			{
				Ms.push_back(i);
				if(i==0)
				{
					nums.push_back(make_pair(1,0));
				}
				else
				{
					int prev1=nums[i-1].first;
					int prev2=nums[i-1].second;
					nums.push_back(make_pair(prev1+1,prev2));
				}
			}
			else if(given[i]=='I')
			{
				if(i==0)
				{
					nums.push_back(make_pair(0,1));
				}
				else
				{
					int prev1=nums[i-1].first;
					int prev2=nums[i-1].second;
					nums.push_back(make_pair(prev1,prev2+1));
				}
				
			}
			else
			{
				if(i==0)
				{
					nums.push_back(make_pair(0,0));
				}
				else
				{
					int prev1=nums[i-1].first;
					int prev2=nums[i-1].second;
					nums.push_back(make_pair(prev1,prev2));
				}
				
			}
			// cout<<nums[i].first<<" "<<nums[i].second<<endl;
		}//nums loop end
// 		cout<<"this is ms"<<endl;
// 		for(int i=0;i<Ms.size();i++)
// 		{
		  //  cout<<Ms[i]<<" ";
// 		}
// 		cout<<endl;
		int ans=0;
		for(int i=0;i<Xis.size()-1;i++)
		{
			// cout<<"ans at each step "<<ans<<endl;
			int start=Xis[i];
			int end=Xis[i+1];
			int range=end-start-1;
			if((range-1)<(k+1))
			{
				int m_1,i_1,m_2,i_2;
				m_1=start==-1?0:nums[start].first;
				i_1=start==-1?0:nums[start].second;
				m_2=end==0?0:nums[end-1].first;
				i_2=end==0?0:nums[end-1].second;
				// cout<<"in if "<<m_1<<" "<<i_1<<" "<<m_2<<" "<<i_2<<endl;
				int num_of_ms=m_2-m_1;
				int num_of_is=i_2-i_1;
				ans+=min(num_of_ms,num_of_is);
			}
			else
			{
				int ans_to_add=0;
				if(k>0)
				{
					std::vector<int>::iterator start_index=upper_bound(Ms.begin(),Ms.end(),start);
				// 	cout<<"this is upper boudn"<<endl;
				// 	cout<<(*start_index)<<endl;
					for(;start_index!=Ms.end() && (*start_index)<end;start_index++)
					{
						bool found=false;
						int e_i=*start_index-1;
						//search on left
						for(int y=e_i-k+1; y<=e_i;y++)
						{
						    if(y<start)
						    {
						        y=start;
						        continue;
						    }
							if(given[y]=='I')
							{
								found=true;
								given[y]='_';
								ans_to_add++;
								break;
							}
						}
						//search on right
						if(found==false)
						for(int y=e_i+2;y<end && y<=e_i+k+1;y++)
						{
							if(given[y]=='I')
							{
								found=true;
								given[y]='_';
								ans_to_add++;
								break;
							}
						}
					}
				}
				ans+=ans_to_add;
			}//if else
			
		}//Xis Loop
		cout<<ans<<endl;
	}//t loop
	return 0;
}
