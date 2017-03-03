#include <cstdio>
#include <iostream>
#include<algorithm>
#define TRUE 1
#define FALSE 0
int map[7][7];
int dp[7][7];
using namespace std;
//int plane_x=3, plane_y=7;

int MaxFind();
bool GameFailCheck();
int MaxFind()
{
	int coin = dp[0][0];
	if (GameFailCheck()) return -1;
	for (int i = 1; i < 6; i++)
	{
		coin = max(dp[0][i], coin);
	}
	return coin;
}
bool GameFailCheck()
{
	bool check_game_fail = FALSE;
	for (int i = 0; i < 7; i++)
	{
		if (dp[i][0] == 0 && dp[i][1] == 0 && dp[i][2] == 0 && dp[i][3] == 0 && dp[i][4] == 0 && dp[i][5] == 0 && dp[i][6] == 0)
		{
			check_game_fail = TRUE;
		}
	}
	return check_game_fail;

}


void PlayRound()
{
	if (map[6][2] == 1) dp[6][2] = 1;
	if (map[6][3] == 1) dp[6][3] = 1;
	if (map[6][4] == 1) dp[6][4] = 1;




	for (int i = 5; i >= 0; i--)
	{
		if (map[i][0] == 2) dp[i][0] = 0;
		else dp[i][0] = max(dp[i + 1][0], dp[i + 1][1]);
		if (map[i][6] == 2) dp[i][6] = 0;
		else dp[i][6] = max(dp[i + 1][5], dp[i + 1][6]);
		for (int j = 1; j <= 5; j++)
		{
			if (map[i][j] == 2) dp[i][j] = 0;
			else dp[i][j] = max(max(dp[i + 1][j - 1], dp[i + 1][j]), dp[i + 1][j + 1]) + map[i][j];
		}
	}	

}

void print_dp()
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			cout<< dp[i][j];
		}
		cout << endl;
	}
}
void print_map()
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			cout << map[i][j];
		}
		cout << endl;
	}
}
void input_map()
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			cin >> map[i][j];
		}
	}
}


int main(int argc, char** argv) {
	/* �Ʒ� freopen �Լ��� sample_input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� sample_input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� sample_input.txt�� ������ �� freopen �Լ��� ����ϸ�,
	�� �Ʒ����� scanf �Լ� �Ǵ� cin�� ����Ͽ� ǥ���Է� ��� sample_input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž� �մϴ�. */
	freopen("input.txt", "r", stdin);
	memset(map, 0, sizeof(map));
	memset(dp, 0, sizeof(dp));
	/* setbuf �Լ��� ������� ������, ������ ���α׷��� ���� �ð� �ʰ��� ���� ���� �Ǿ��� ��,
	C++���� printf�� ����� ���, printf�� ����� ������ ä������ �ʰ� '0��'�� �� ���� �ֽ��ϴ�.
	���� printf�� ����� ��� setbuf(stdout, NULL) �Լ��� �ݵ�� ����Ͻñ� �ٶ��ϴ�. */
	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);	// Codeground �ý��ۿ����� C++������ scanf �Լ� ����� �����ϸ�, cin�� ����ϼŵ� �˴ϴ�.
	for (test_case = 1; test_case <= T; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
		
		input_map();
		PlayRound();
		MaxFind();
        //print_map();
		print_dp();
	
		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		printf("Case #%d\n", test_case);
		int result = MaxFind();
		printf("%d", result);

	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}