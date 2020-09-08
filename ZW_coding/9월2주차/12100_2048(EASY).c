#include<stdio.h>
int n;
int map[21][21];
int temp[21][21];
int f[21];
int ans = 0;
int sum;

void move(int dir) {

	if (dir == 1) {//down
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 20; j++)
				f[j] = 0;
			for (int j = 0; j < n; j++) {
				if (map[j][i] != 0) {
					for (int k = j - 1; k >= 0; k--) {
						if (map[k][i] != 0) {
							if (map[k][i] == map[j][i]) {
								if (f[k] == 0) {
									map[k][i] *= 2;
									map[j][i] = 0;
									f[k] = 1;
									break;
								}
								else {
									if (k + 1 != j)
									{
										map[k + 1][i] = map[j][i];
										map[j][i] = 0;
									}
									break;
								}

							}
							else
							{
								if (k + 1 != j)
								{
									map[k + 1][i] = map[j][i];
									map[j][i] = 0;
								}
								break;

							}

						}
						else if (k == 0) {
							if (map[k][i] == 0) {
								map[k][i] = map[j][i];
								map[j][i] = 0;
								break;
							}
						}
					}

				}

			}
		}
	}
	if (dir == 2) {//up
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 20; j++)
				f[j] = 0;
			for (int j = n - 1; j >= 0; j--) {
				if (map[j][i] != 0) {
					for (int k = j + 1; k < n; k++) {
						if (map[k][i] != 0) {
							if (map[k][i] == map[j][i]) {
								if (f[k] == 0) {
									map[k][i] *= 2;
									map[j][i] = 0;
									f[k] = 1;
									break;
								}
								else {
									if (k - 1 != j)
									{
										map[k - 1][i] = map[j][i];
										map[j][i] = 0;
									}
									break;
								}
							}
							else
							{
								if (k - 1 != j)
								{
									map[k - 1][i] = map[j][i];
									map[j][i] = 0;
								}
								break;

							}
						}
						else if (k == n - 1) {
							if (map[k][i] == 0) {
								map[k][i] = map[j][i];
								map[j][i] = 0;
								break;
							}
						}

					}

				}

			}
		}
	}
	if (dir == 3) {//LEFT
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < 20; i++)
				f[i] = 0;
			for (int i = 0; i < n; i++) {
				if (map[j][i] != 0) {
					for (int k = i - 1; k >= 0; k--) {
						if (map[j][k] != 0) {
							if (map[j][k] == map[j][i]) {
								if (f[k] == 0) {
									map[j][k] *= 2;
									f[k] = 1;
									map[j][i] = 0;
									break;
								}
								else {
									if (k + 1 != i)
									{
										map[j][k + 1] = map[j][i];
										map[j][i] = 0;
									}
									break;
								}
							}
							else
							{
								if (k + 1 != i)
								{
									map[j][k + 1] = map[j][i];
									map[j][i] = 0;
								}
								break;

							}
						}
						else if (k == 0) {
							if (map[j][k] == 0) {
								map[j][k] = map[j][i];
								map[j][i] = 0;
								break;
							}
						}

					}

				}

			}
		}
	}
	if (dir == 4) {//LEFT
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < 20; i++)
				f[i] = 0;
			for (int i = n - 1; i >= 0; i--) {
				if (map[j][i] != 0) {
					for (int k = i + 1; k < n; k++) {
						if (map[j][k] != 0) {
							if (map[j][k] == map[j][i]) {
								if (f[k] == 0) {
									map[j][k] *= 2;
									f[k] = 1;
									map[j][i] = 0;
									break;
								}
								else {
									if (k - 1 != i)
									{
										map[j][k - 1] = map[j][i];
										map[j][i] = 0;
									}
									break;
								}
							}
							else
							{
								if (k - 1 != i)
								{
									map[j][k - 1] = map[j][i];
									map[j][i] = 0;
								}
								break;

							}
						}
						else if (k == n - 1) {
							if (map[j][k] == 0) {
								map[j][k] = map[j][i];
								map[j][i] = 0;
								break;
							}
						}

					}

				}

			}
		}
	}
}
int sibal(char x) {
	if (x == '1')
		return 1;
	if (x == '2')
		return 2;
	if (x == '3')
		return 3;
	if (x == '4')
		return 4;
}

void go(int i, int dir) {
	if (i == 5) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] > ans) ans = map[i][j];
			}
		}
		if (sum < ans) sum = ans;
		ans = 0;
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp[i][j] = map[i][j];
		}
	}
	move(dir);
	//if (!check()) return;
	for (int j = 1; j <= 4; j++) {
		go(i + 1, j);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = temp[i][j];
		}
	}
}
int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans = ans < map[i][j] ? map[i][j] : ans;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp[i][j] = map[i][j];
		}
	}

	int tw[] = { 1,1,1,1,1 };

	while (1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				map[i][j] = temp[i][j];
			}
		}
		move(tw[0]);
		move(tw[1]);
		move(tw[2]);
		move(tw[3]);
		move(tw[4]);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] > ans) {
					ans = map[i][j];
				}
			}
		}
		tw[0]++;
		if (tw[0] > 4)
		{
			tw[0] = 1;
			tw[1]++;
			if (tw[1] > 4) {
				tw[1] = 1;
				tw[2]++;
				if (tw[2] > 4) {
					tw[2] = 1;
					tw[3]++;
					if (tw[3] > 4)
					{
						tw[3] = 1;
						tw[4]++;
						if (tw[4] > 4) {
							break;

						}
					}
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;


}
