#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define inf (long long int)1e18
#define log(args...)    { std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b) for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<std::endl;
#define vec std::vector
#define vll std::vector<long long int>
#define vi std::vector<int>
#define vb std::vector<bool>
#define pii std::pair<int, int>
#define pllll std::pair<long long int, long long int>
#define loop(i, a, b) for(int i=a;i<=b;i++)
#define rloop(i, a, b) for(int i=a;i>=b;i--)
#define iter_all(el, cont) for(auto &el:cont)

void err(std::istream_iterator<std::string> it) {}
template<typename T, typename... Args>
void err(std::istream_iterator<std::string> it, T a, Args... args) {
	std::cout << *it << " = " << a << std::endl;
	err(++it, args...);
}

void file_i_o() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int n;
	std::cin>>n;
	std::vector<int> arr;
	for(int i=0;i<n;i++){
		int temp;
		std::cin>>temp;
		arr.push_back(temp);
	}
	std::sort(arr.begin(), arr.end());

	std::vector<std::vector<bool>> dp(n, std::vector<bool>(1e6 + 2, 0));
	for(int i=0;i<n;i++){
		dp[i][0] = true;
	}
	dp[0][arr[0]] = true;
	for(int i=1;i<n;i++){
		for(int sum = 0;sum <= 1e6;sum++){
			int notpick = dp[i-1][sum];
			int pick = false;
			if(sum >= arr[i]){
				pick = dp[i-1][sum-arr[i]];
			}
			dp[i][sum] = (pick or notpick);
		}
	}
	std::vector<int> ans;
	for(int i=1;i<=1e6;i++){
		if(dp[n-1][i]) ans.push_back(i);
	}
	std::cout<<ans.size()<<"\n";
	logarr(ans, 0, ans.size()-1);

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}