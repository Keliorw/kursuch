#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

struct zap{
	string fio;
	int np;
	string dgn;
};

void Writer(string diagnoz, int PalatNum, zap *sick, int n){
	cout << "\n\n";
	for(int i=0; i<n; i++){
		if(diagnoz == "NULL"){
			if(PalatNum == sick[i].np){
				cout << "�������: " << sick[i].fio << endl;
				cout << "������: " << sick[i].np << endl;
				cout << "�������: " << sick[i].dgn << endl;
				cout << "\n\n";
			}
		} else {
			if(diagnoz == sick[i].dgn){
				cout << "�������: " << sick[i].fio << endl;
				cout << "������: " << sick[i].np << endl;
				cout << "�������: " << sick[i].dgn << endl;
				cout << "\n\n";
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, i, number, palata = 1, PalatNum;
	string diagnoz;
	bool Flag = true;
	cout << "������� ���-�� ���������, ������� ������ ��������: "; cin >> n; cout << "\n\n";
	cout << "--------------------------------------------\n\n";
	zap *sick = new zap[n];
	for (i=0; i<n; i++){
		cout << "������� �������: "; cin >> sick[i].fio;
		sick[i].np = 0;
		cout << "������� �������: "; cin >> sick[i].dgn;
		cout << "\n\n";
	}
	/* ������������� �� ������� */
	for(i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(sick[i].dgn == sick[j].dgn){
				if(sick[j].np != 0){
					sick[i].np = sick[j].np;
					break;
				} else {
					sick[i].np = palata;
					palata++;
					break;
				}
			}
		}
	}
	/* ������������� �� ������� */
	while(Flag){
		cout << "1) ������� ��������� �� ������ ������\n";
		cout << "2) ������� ��������� �� ��������\n";
		cout << "3) �����\n\n";
		cout << "�������� ��������: "; cin >> number;
		switch(number){
			case 1:
				cout << "������� ����� ������: "; cin >> PalatNum;
				Writer("NULL", PalatNum, sick, n);
				break;
			case 2:
				cout << "������� �������: "; cin >> diagnoz;
				Writer(diagnoz, 0, sick, n);
				break;
			case 3:
				Flag = false;
				break;
			default:
				break;
		}
	}
	system("pause");
	return 0;
}