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
int matrix_size = 100;
int num_samples = 10000;
int num_iter = 100000;
int survival_count[N], tmp[4];

int move (int r, int c) {
	int rand_move = rand() % 4;
	int dr = dr_val[rand_move], dc = dc_val[rand_move];
	if (r + dr >= 0 && r + dr < matrix_size && c + dc >= 0 && c + dc < matrix_size) {
		tmp[0] = r + dr; tmp[1] = c + dc;
	}
	else {
		tmp[0] = r - dr; tmp[1] = c - dc;
	}
}

int main () {
	fastIO;
	int i, cat_r, cat_c, rat_r, rat_c, rand_move, j;
	for (i = 0; i <= num_samples; i++) {
		rat_r = matrix_size/2, rat_c = matrix_size/2, cat_r = matrix_size/2, cat_c = matrix_size/2;
		for (j = 0; j <= num_iter; j++) {
			move(rat_r, rat_c);
			rat_r = tmp[0]; rat_c = tmp[1];
			move(cat_r, cat_c);
			cat_r = tmp[0]; cat_c = tmp[1];
			if (j != 0 && rat_r == cat_r && rat_c == cat_c) {
				break;
			}
			survival_count[j]++;
		}
	}
	for (i = 0; i <= num_iter; i++) {
		cout << i << " " << ((double)survival_count[i])/(double)num_samples << "\n";
	}
	return 0;
}