#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int>ans;
        if(k<=0||k>input.size()||input.size()==0)
            return ans;
        int start=0,end=input.size()-1;
        int index=Partition(input,start,end);
        while(index!=k-1)
        {
            if(index<k-1)
                start=index+1;
            else
                end=index-1;
            index=Partition(input,start,end);
        }
        for(int i=0;i<k;i++)
            ans.push_back(input[i]);
        return ans;
    }
    int Partition(vector<int> &input,int iBegin,int iEnd)
    {
        int small=iBegin-1;
        for(int index=iBegin;index<iEnd;index++)
        {
            if(input[index]<input[iEnd])
            {
                small++;
                if(small!=index)
                std::swap(input[small],input[index]);
            }
        }
        ++small;
        std::swap(input[small],input[iEnd]);
        return small;
    }
};
int main()
{
  vector<int>vec,ans;
  int data[]={4,5,1,6,2,7,3,8};
  for(int i=0;i<sizeof(data)/sizeof(int);i++)
    vec.push_back(data[i]);
  Solution s;
  ans=s.GetLeastNumbers_Solution(vec,4);
  for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
  return 0;
}
