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

// int findMaxPages(int idx, int budget, std::vector<int> &price, std::vector<int> &pages, std::vector<std::vector<int>> &dp){
// 	if(idx == 0){
// 		if(price[0] <= budget) return pages[0];
// 		else return 0;
// 	}

// 	if(dp[idx][budget] != -1) return dp[idx][budget];

// 	int notpick = findMaxPages(idx-1, budget, price, pages, dp);
// 	int pick = -1e9;
// 	if(budget >= price[idx]){
// 		pick = pages[idx] + findMaxPages(idx-1, budget-price[idx], price, pages, dp);
// 	}

// 	return dp[idx][budget] = std::max(pick, notpick);
// }

int findMaxPages(int n, int budget, std::vector<int> &price, std::vector<int> &pages, std::vector<std::vector<int>> &dp){
	for(int b=price[0];b<=budget;b++){
		dp[0][b] = pages[0];
	}

	for(int i=1;i<=n;i++){
		for(int b=0;b<=budget;b++){
			int notpick = dp[i-1][b];
			int pick = -1e9;
			if(b >= price[i]){
				pick = pages[i] + dp[i-1][b-price[i]];
			}

			dp[i][b] = std::max(pick, notpick);
		}
	}

	return dp[n][budget];
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int n, x;
	std::cin>>n>>x;
	std::vector<int> h(n), s(n);

	for(int i=0;i<n;i++){
		std::cin>>h[i];
	}
	for(int i=0;i<n;i++){
		std::cin>>s[i];
	}

	std::vector<std::vector<int>> dp(n, std::vector<int>(x+1, 0));

	std::cout<<findMaxPages(n-1, x, h, s, dp);

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}