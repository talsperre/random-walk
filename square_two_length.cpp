#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define inf_ll 2000000000000000000LL
#define inf 1000000000
#define eps 1e-8
#define mod 1000000007
#define ff first
#define ss second
#define N 3456789
using namespace std;
typedef long long int ll;
typedef pair <int, int> PII;
int dr_val[4] = {0, 0, 1, -1};
int dc_val[4] = {1, -1, 0, 0};
int num_samples = 100;
int num_iter = 100000;
int tmp[4];
int matrix_size[N];
int survival_count[N];

int move (int r, int c, int n) {
	int rand_move = rand() % 4;
	int dr = dr_val[rand_move], dc = dc_val[rand_move];
	if (r + dr >= 0 && r + dr < n && c + dc >= 0 && c + dc < n) {
		tmp[0] = r + dr; tmp[1] = c + dc;
	}
	else {
		tmp[0] = r - dr; tmp[1] = c - dc;
	}
}

int main () {
	fastIO;
	int i, cat_r, cat_c, rat_r, rat_c, rand_move, j, k, flag, len = 0, l;
	for (i = 1; i * 50 < 1000; i++) {
		matrix_size[i] = i * 50;
		len++;
	}
	for (l = 0; l < 10; l++) {
		for (i = 1; i < len; i++) {
			for (j = 0; j <= num_samples; j++) {
				rat_r = matrix_size[i]/2, rat_c = matrix_size[i]/2, cat_r = matrix_size[i]/2, cat_c = matrix_size[i]/2; flag = 1;
				for (k = 0; k <= num_iter; k++) {
					move(rat_r, rat_c, matrix_size[i]);
					rat_r = tmp[0]; rat_c = tmp[1];
					move(cat_r, cat_c, matrix_size[i]);
					cat_r = tmp[0]; cat_c = tmp[1];
					if (k != 0 && rat_r == cat_r && rat_c == cat_c) {
						flag = 0;
						break;
					}
				}
				if (flag) survival_count[i]++;
			}	
		}
	}
	for (i = 1; i < len; i++) {
		cout << i * 50 << " " << ((double)survival_count[i]/10)/(double)num_samples << "\n";
	}	
	return 0;
}