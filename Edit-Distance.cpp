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

int minOps(int idx1, int idx2, std::string &s1, std::string &s2, std::vector<std::vector<int>> &dp){
	if(idx1 < 0) return idx2+1;
	if(idx2 < 0) return idx1+1;

	if(dp[idx1][idx2] != -1) return dp[idx1][idx2];


	if(s1[idx1] == s2[idx2]){
		return dp[idx1][idx2] = minOps(idx1-1, idx2-1, s1, s2, dp);
	} else {
		int case1 = 1 + minOps(idx1-1, idx2-1, s1, s2, dp); // replace
		int case2 = 1 + minOps(idx1, idx2-1, s1, s2, dp); // insert
		int case3 = 1 + minOps(idx1-1, idx2, s1, s2, dp); // delete
		return dp[idx1][idx2] = std::min({case1, case2, case3});
	}
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	std::string s1, s2;
	std::cin>>s1>>s2;

	int n = s1.size(), m = s2.size();
	std::vector<std::vector<int>> dp(n, std::vector<int> (m, -1));

	std::cout<<minOps(s1.size()-1, s2.size()-1, s1, s2, dp);


#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}