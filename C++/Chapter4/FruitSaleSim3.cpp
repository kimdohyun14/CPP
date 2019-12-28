#include <iostream>
using namespace std;

class FruitSeller {
private:
	const int APPLE_PRICE;
	int numOfApples;
	int myMoney;

public:
	FruitSeller(int price, int num, int money)
		:APPLE_PRICE(price), numOfApples(num), myMoney(money) {
		//Member Initializer
	}
	int SaleApples(int money) {
		if (money < 0) {
			cout << "�߸��� ������ ���޵Ǿ� �ǸŸ� ����մϴ�." << endl;
			return 0;
		}
		int num = money / APPLE_PRICE;
		numOfApples -= num;
		myMoney += money;
		return num;
	}
	void ShowSalesResult() const {
		cout << "���� ��� : " << numOfApples << endl;
		cout << "�Ǹ� ����: " << myMoney << endl << endl;
	}
};

class FruitBuyer {
	int myMoney;
	int numOfApples;

public:
	FruitBuyer(int money)
		:myMoney(money), numOfApples(0) {

	}
	void BuyApples(FruitSeller &seller, int money) {
		if (money < 0) {
			cout << "�߸��� ������ ���޵Ǿ� ���Ÿ� ����մϴ�." << endl;
			return;
		}
		numOfApples += seller.SaleApples(money);
		myMoney -= money;
	}
	void ShowBuyResult() const {
		cout << "���� �ܾ� : " << myMoney << endl;
		cout << "��� ���� : " << numOfApples << endl << endl;
	}
};

int main() {
	FruitSeller seller(1000, 20, 0);
	FruitBuyer buyer(5000);
	buyer.BuyApples(seller, 2000); //������ ����!

	cout << "���� �Ǹ����� ��Ȳ" << endl;
	seller.ShowSalesResult();
	cout << "���� �������� ��Ȳ" << endl;
	buyer.ShowBuyResult();
	return 0;
}