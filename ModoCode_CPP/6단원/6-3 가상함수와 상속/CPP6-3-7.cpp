// ���̾Ƹ�� ���(diamond inheritance) Ȥ�� 
// ������ ���̾Ƹ�� ���(dreadful diamond of derivation)�̶�� �θ��� ���� ���

class Human {
	// ...
};

class HandsomeHuman : public Human {
	// ...
};

class SmartHunam : public Human {
	// ...
};

class Me : public HandsomeHuman, public SmartHunam {
	// ...
};

// �� ���� Ư���� ������ Me Ŭ������, HandsomeHuman�� SmartHuman Ŭ���� �� �� ���
// �� ���´� ���̾� ��� ����� ������ �ȴ�.
// ����� �Ǵ� �� ���� Ŭ������ ������ ���̽� Ŭ������ �����ϰ� �ִ� ����
// �̷��� ������ ��ӿ� �������� ���⿡�� ����ϴ�.

// ���� Human�� name�̶�� ��� ������ �ִٰ� �ϸ�,
// HandsomeHuman�� SmartHuman�� ��� Human�� ��� �ް� �����Ƿ�, ���⿡�� name�̶�� ������ �ִ�.
// �׷��� Me�� �� �� ���� Ŭ������ ��� ������,
// ��������� �� �� HandsomeHuman�� SmartHuman�� �ƹ��� �Ȱ�ġ�� ����ٰ� �ص�,
// Human�� ��� ������ �ߺ��Ǵ� ������ �߻��ϰ� �ȴ�.

// �̸� �ذ��� �� �ִ� ����� �ִ�.
// virtual Ű���带 �̿��Ѵ�.
// class HandsomeHuman : public virtual Human {}
// class SmartHuman : public virtual Human {}
// �̷��� ���·� Human�� virtual�� ��� �޴´ٸ�, 
// Me���� ���� ��� �ÿ���, �����Ϸ��� ������ Human�� �� ���� �����ϵ��� ������ �� �ְ� �Ѵ�.

// ���� ��� �ÿ�, Me�� �����ڿ��� HandsomeHuman�� SmartHuman�� �����ڸ� ȣ������ ����,
// Human�� ������ ���� ȣ���� �־�߸� �Ѵ�.

// ���� ����� ���� ����ؾ� �ұ�?
