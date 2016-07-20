#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct job {
    int start, stop;
    int profit;
};

struct less_than_key
{
    inline bool operator() (const job& struct1, const job& struct2)
    {
        return (struct1.stop < struct2.stop);
    }
};

int main() {
    vector<job> jobs;
    job *job_arr = new job[6];
    job_arr[0] = job{1,3,5};
    job_arr[1] = job{2,5,6};
    job_arr[2] = job{4,6,5};
    job_arr[3] = job{5,8,11};
    job_arr[4] = job{6,7,4};
    job_arr[5] = job{7,9,2};
    for (int i = 0; i < 6; ++i) 
        jobs.push_back(job_arr[i]);
    sort(jobs.begin(), jobs.end(), less_than_key());
    for_each( jobs.begin(), jobs.end(), [](job &j){ cout << j.stop << " "; } );
    cout << endl;
    vector<int> dp(6);
    for (int i = 0; i < 6; ++i) {
        dp[i] = job_arr[i].profit;
    }
    for (int i = 1; i < 6; ++i) {
        for (int j = 0; j < i; ++j) {
            if (jobs[j].stop <= jobs[i].start) {
                dp[i] = max( dp[i], dp[j]+jobs[i].profit );
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
    return 0;
}
