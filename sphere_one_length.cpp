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

int num_samples = 1000;
int num_iter = 1000;
int survival_count[N];
double tmp[4];
double max_radius = 25;

void move (double x, double y, double z, double r) {
	double dx = ((double)rand())/RAND_MAX;
	double dy = ((double)rand())/RAND_MAX;
	double x1, y1;
	if (rand() % 2 == 1) x1 = x + dx;
	else x1 = x - dx;
	if (rand() % 2 == 1) y1 = y1 + dy;
	else y1 = y1 - dy;
	double z1 = sqrt(r * r - x1 * x1 - y1 * y1);
	tmp[0] = x1; tmp[1] = y1; tmp[2] = z1;
}

double dis (double x1, double y1, double z1, double x2, double y2, double z2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2);
}

int main () {
	fastIO;
	int i, j, r, flag ;
	double rat_x, rat_y, rat_z, cat_x, cat_y, cat_z;
	for (r = 2; r <= max_radius; r++) {
		for (i = 1; i <= num_samples; i++) {
			rat_x = r; rat_y = 0; rat_z = 0; cat_x = -r; cat_y = 0; cat_z = 0; flag = 1;
			for (j = 0; j <= num_iter; j++) {
				move(rat_x, rat_y, rat_z, r);
				rat_x = tmp[0]; rat_y = tmp[1]; rat_z = tmp[2];
				move(cat_x, cat_y, cat_z, r);
				cat_x = tmp[0]; cat_y = tmp[1]; cat_z = tmp[3];
				if (dis(rat_x, rat_y, rat_z, cat_x, cat_y, cat_z) <= 4) {
					flag = 0;
					break;
				}
			}
			if (flag) survival_count[r]++;
		}
	}
	for (i = 2; i <= max_radius; i++) {
		cout << i << " " << ((double)survival_count[i])/(double)num_samples << "\n";
	}
	return 0;
}