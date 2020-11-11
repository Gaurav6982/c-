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
		
		// cout<<"This is Xis"<<endl;
		// for(int i=0;i<Xis.size();i++)
		// cout<<Xis[i]<<" ";
		// cout<<endl;
		vector<int> Ms;
		vector<int> Is;
		// vector< pair<int,int> > nums;
		// cout<<"This is NUms:"<<endl;
// 		Ms.push_back(-2);
        Xis.push_back(-1);
		for(int i=0;i<n;i++)
		{
			if(given[i]=='X')
			Xis.push_back(i);
            else if(given[i]=='M')
            Ms.push_back(i);
            else if(given[i]=='I')
            Is.push_back(i);
			// cout<<nums[i].first<<" "<<nums[i].second<<endl;
		}//nums loop end
		Xis.push_back(n);
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
			std::vector<int>::iterator m=upper_bound(Ms.begin(),Ms.end(),start);
            for(;m!=Ms.end() && (*m)<end;m++)
            {
                int ind=-1;
                int pos=*m;
                int left=(*m-k-1)>start?(*m-k-1):start;
                int right=(*m+k)<end?(*m+k):end;
                bool found=false;
                // cout<<"pos "<<pos<<" left "<<left<<" right "<<right<<endl;
                //for left
                std::vector<int>::iterator i_left=upper_bound(Is.begin(),Is.end(),left);
                // cout<<"i_left: "<<(*i_left)<<endl;
                if(i_left!=Is.end() && (*i_left)<pos)
                {
                    // cout<<"inhere"<<endl;
                    found=true;
                    given[(*i_left)]='_';
                    ans++;
                }

                //for right
                if(found==false)
                {
                    std::vector<int>::iterator i_right=upper_bound(Is.begin(),Is.end(),pos);
                    // cout<<"wadawd"<<(*i_right)<<endl;
                    if(i_right!=Is.end() && (*i_right)<=right)
                    {
                        given[(*i_right)]='_';
                        ans++;
                    }
                }
            }
			
		}//Xis Loop
		cout<<ans<<endl;
	}//t loop
	return 0;
}
