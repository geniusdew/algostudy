#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	//N��ġ,�� ������ �Ÿ� ���� ������ vector
	vector<int> npos;
	vector<int> sub;
	int N, K, temp, result = 0;
	cin >> N >> K;

	//���� ��ġ �Է�
	for (int i = 0; i < N; i++)
		cin >> temp, npos.push_back(temp);
	
	//�������� ����
	sort(npos.begin(), npos.end());
	
	//�� ���� �Ÿ� �� ��ġ ����
	for (int i = 1; i < N; i++)
		sub.push_back(npos[i] - npos[i - 1]);

	//�������� ����
	sort(sub.rbegin(), sub.rend());

	// K-1 ��ŭ ��..
	for (int i = 0; i< sub.size() && i < K-1; i++)
		result -= sub[i];

	cout << npos[N - 1] - npos[0] + result;
	return 0;
}