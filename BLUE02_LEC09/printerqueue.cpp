#include<bits/stdc++.h>
using namespace std;
#define MAX 105

struct node{
	int priority;
	bool flag;
};

int main()
{
	int ntest, total_job, job_index, priority_index, wait;
	int job_priority[MAX];
	int priority[10];
	cin>>ntest;
	while(ntest--)
	{
		wait = 0;
		queue<node> jobQueue;
		memset(priority,0,sizeof(priority));
		cin>>total_job;
		cin>>job_index;
		for(int i=0; i<total_job; i++){
            cin>>job_priority[i]; 
            priority[job_priority[i]]++;
			node index;
			index.priority = job_priority[i];
			(i==job_index)?index.flag = true:index.flag=false;
			jobQueue.push(index);
		}
		priority_index = job_priority[job_index];
		for(int i=9; i>=priority_index; i--)
		{
			if(i==priority_index){
				while(jobQueue.front().flag!=true){
					if(jobQueue.front().priority==priority_index)  wait++;
					jobQueue.pop();
				}
				wait++;
			}
			else
			while(priority[i]--)
			{
				while(jobQueue.front().priority!=i){
					node temp = jobQueue.front();
					jobQueue.pop();
					jobQueue.push(temp);
				}
				jobQueue.pop();
				wait++;
			}
		}
		cout<<wait<<endl;
	}
	return 0;
}