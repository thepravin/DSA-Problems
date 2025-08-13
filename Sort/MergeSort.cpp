#include<bits/stdc++.h>
using namespace std;


void merge(vector<int>& vec, int low, int mid, int high)
{
	int left = low;
	int right = mid + 1;
	vector<int> temp;

	while (left <= mid && right <= high)
	{
		if (vec[left] < vec[right])
		{
			temp.push_back(vec[left]);
			left++;
		}
		else
		{
			temp.push_back(vec[right]);
			right++;
		}
	}

	while (left <= mid)
	{
		temp.push_back(vec[left]);
		left++;
	}

	while (right <= high)
	{
		temp.push_back(vec[right]);
		right++;
	}

	int idx=0;
	for (int i = low; i <= high; ++i)
	{
		vec[i] = temp[idx++];
	}
}

void merge_sort(vector<int>& vec, int low, int high)
{
	if (low >= high) return;

	int mid = low + (high - low) / 2;

	merge_sort(vec, low, mid);
	merge_sort(vec, mid + 1, high);

	merge(vec, low, mid, high);
}

int main()
{
	vector<int> vec = {13, 2, 24, 52, 0, 9};

	merge_sort(vec, 0, vec.size() - 1);

	for (int num : vec) cout << num << " ";

	return 0;
}
