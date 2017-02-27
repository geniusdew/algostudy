/*
	�ۼ��� : 2017-02-23
	�ۼ��� : ���±�
*/

#include<iostream>
#include<set>
#include<memory.h>
#include<queue>
using namespace std;

int check[301][301][301];  // �ߺ�üũ�ϱ� ���� �迭, A: 0 , B: 0 , C : 10 �̶�� check[0][0][10] =1�� �ٲ��� ���� ������ ��������ʱ�����.
int remain[3]; // remain[0] = A�� ���� ���� �� , remain[1] = B�� ���� ���� ��,  remain[2] = C�� ���� ���� ��
int size[3]; // �� ������ �ִ� ���� ��(������)�� �����ص� , size[1] = A������ �ִ� ���差 ,  size[2] = B������ �ִ� ���差, size[3] = C������ �ִ����差



set<int> st; // ����� �����ϴ� �����̳ʷ� set Ȱ��!!
set<int>::iterator st_it; //set ����� ���� �ݺ��� (*it)

int main()
{
	queue<int> aQue; //A�� ���� ���� �� ����
	queue<int> bQue; //B�� ���� ���� �� ����
	queue<int> cQue; //C�� ���� ���� �� ����
	
	memset(check, 0, sizeof(check)); //�迭 �ʱ�ȭ

	for (int i = 0; i < 3; i++)
		cin >> size[i]; //������ �Է�

	aQue.push(0);    // 0
	bQue.push(0);    // 0
	cQue.push(size[2]); // 10
	check[0][0][size[2]] = 1; // check[0][0][10] = 1 

	while (!aQue.empty())
	{

		remain[0] = aQue.front();
		remain[1] = bQue.front();
		remain[2] = cQue.front();
		
		
		if (remain[0]==0) st.insert(remain[2]); //A�� 0�϶����� C�� ���� ������ ����

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i == j || remain[i] == size[i]) continue;
				remain[0] = aQue.front();
				remain[1] = bQue.front();
				remain[2] = cQue.front();
				
				remain[i] += remain[j];
				if (remain[i]>size[i]) remain[j] = remain[i] - size[i], remain[i] = size[i];
				else remain[j] = 0;
				if (check[remain[0]][remain[1]][remain[2]] == 0) 
					check[remain[0]][remain[1]][remain[2]] = 1, aQue.push(remain[0]), bQue.push(remain[1]), cQue.push(remain[2]);
			}
		}
		aQue.pop();
		bQue.pop();
		cQue.pop();
	}
	//���
	for (st_it = st.begin(); st_it != st.end(); st_it++)
	{	
		if (st_it == st.begin()) cout << *st_it;
		else cout << " " << *st_it;
	}
	return 0;
}