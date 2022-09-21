//Leet Code
//sum of even numbers after queries
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int sum=0;
        for (int j=0;j<nums.size();j++){
        	if (nums[j]%2==0){
        		sum = sum + nums[j];
			}
		}
		int a,k;
		for (int i=0;i<queries.size();i++){
        	k = queries[i][0];
        	a = queries[i][1];
        	if (nums[a]%2==0){
        		if (k%2==0){
        			sum+=k;
				}
				else{
					sum-=nums[a];
				}
			}
			else{
				if (k%2!=0){
					sum=sum+nums[a]+k;
				}
			}
			nums[a]+=k;
			ans.push_back(sum);
		}
		return ans;
    }
};
int main(){
	vector<int> nums;
	nums = {1,2,3,4};
	vector<vector<int>> queries;
	queries = {{1,0},{-3,1},{-4,0},{2,3}};
	Solution s;
	vector <int> ans;
	ans = s.sumEvenAfterQueries(nums, queries);
	for (int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
}