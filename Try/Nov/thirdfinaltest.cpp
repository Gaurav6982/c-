#include <bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int calculate_sij(int Cs[],int pos,int lor,int start,int end,char dir)
{
    int count=0;
    if(dir=='l')
    {
        if(lor<=start)
        {
            count=Cs[pos]-Cs[start+1];
        }
        else
        {
            count=Cs[pos]-Cs[lor+1];
        }
    }
    else if(dir=='r')
    {
        if(lor>=end)
        {
            count=Cs[end-1]-Cs[pos];
        }
        else
        {
            count=Cs[lor-1]-Cs[pos];
        }
    }
    return count;   
}

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
        // cout<<"========================"<<endl;
		int n,k;
        // n=abs(rand())%20+1;
        // k=abs(rand())%5;
		cin>>n>>k;
        // cout<<n<<" "<<k<<endl;
		string given;
		cin>>given;
        // rep(i,n) cout<<given[i]<<" ";cout<<endl;
		vector<int> Xis;

		vector<int> Ms;
		vector<int> Is;
// 		vector<int> Cs;
        int Cs[n];

        Xis.push_back(-1);
		for(int i=0;i<n;i++)
		{
		    if(i>0)
		    Cs[i]=Cs[i-1];
		    else
		    Cs[i]=0;
			if(given[i]=='X')
			Xis.push_back(i);
            else if(given[i]=='M')
            Ms.push_back(i);
            else if(given[i]=='I')
            Is.push_back(i);
            else if(given[i]==':')
            {
                if(i==0)
                Cs[i]=1;
                else
                {
                    
                    Cs[i]++;
                }
            }
		
		}//nums loop end
        // rep(i,n) cout<<i%10<<" ";cout<<endl; 
		// for(int i=0;i<n;i++)
		// cout<<Cs[i]<<" ";
		// cout<<endl;
		Xis.push_back(n);

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
                int left=(pos-k-1);
                int right=(pos+k+1);
                // int sij_left=Cs[n-1]!=0?calculate_sij(Cs,pos,left,start,end,'l'):0;
                // int sij_right=Cs[n-1]!=0?calculate_sij(Cs,pos,right,start,end,'r'):0;
                // cout<<"sij_left "<<sij_left<<"sij_right "<<sij_right<<" ";
                left=(left)>start?(left):start;
                right=(right)<end?(right):end;
                bool found=false;
                // cout<<"pos "<<pos<<" left "<<left<<" right "<<right<<endl;
                //for left
                std::vector<int>::iterator i_left=upper_bound(Is.begin(),Is.end(),left);
                
                if(i_left!=Is.end() && (*i_left)<pos)
                {
                    // cout<<"inhere"<<endl;
                    // cout<<"i_left: "<<(*i_left)<<endl;
                    if((k+1-(pos-(*i_left))-(Cs[pos]-Cs[(*i_left)]))>0)
                    {
                        // cout<<"left:"<<(k+1)<<(pos-(*i_left))<<(Cs[(*i_left)]-Cs[pos])<<endl;
                        found=true;
                        Is.erase(i_left);
                        ans++;
                    }
                }

                //for right
                if(found==false)
                {
                    std::vector<int>::iterator i_right=upper_bound(Is.begin(),Is.end(),pos);
                    
                    if(i_right!=Is.end() && (*i_right)<right)
                    {
                        // cout<<"i_right "<<(*i_right)<<endl;
                        if((k+1-((*i_right)-pos)-(Cs[(*i_right)]-Cs[pos]))>0)
                        {
                            // cout<<"right: "<<(k+1-((*i_right)-pos)-(Cs[pos]-Cs[(*i_right)]))<<endl;
                            Is.erase(i_right);
                            ans++;
                        }
                       
                    }
                }
            }
			
		}//Xis Loop
		cout<<ans<<endl;
	}//t loop
	return 0;
}
