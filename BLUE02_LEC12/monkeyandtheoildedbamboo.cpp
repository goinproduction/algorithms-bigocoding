#include <bits/stdc++.h> 

using namespace std; 

const int MAX_N = 100005; 

int a[MAX_N]; 
int n, test; 

int main () {
	scanf("%d", &test); 

	for (int t = 1; t <= test; t++) {
		printf("Case %d: ", t); 
		scanf("%d", &n); 

		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]); 
		}

		int l = 1; int r = a[n] + 1; 

		int res; 

		while (l <= r) {
			int mid = (l + r) >> 1;
			int k = mid; 

			bool check = true; 
			for (int i = 1; i <= n; i++) {
				if (a[i] - a[i - 1] > k) {
					check = false;
					break; 	
				}	
				else {
					if (a[i] - a[i - 1] == k) {
						k--; 
					}
				}
			}

			if (check == true) {
				res = mid; 
				r = mid - 1; 
			}
			else {
				l = mid + 1; 
			}
		}

		printf("%d\n", res); 
	}
	return 0; 
}