class Solution {
public:
int smallestRangeII(vector<int> & n, int k) 
{
	sort(begin(n), end(n));
	int out(n.back()-n.front());
	for(int i{1}; i<size(n); ++i)
		out=min(out, max(n[i-1]+k, n.back()-k)-min(n[i]-k, n.front()+k));
	return out;
}
};
