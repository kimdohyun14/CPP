// 다이아몬드 상속(diamond inheritance) 혹은 
// 공포의 다이아몬드 상속(dreadful diamond of derivation)이라고 부르는 다중 상속

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

// 두 가지 특성을 보유한 Me 클래스는, HandsomeHuman과 SmartHuman 클래스 둘 다 상속
// 이 형태는 다이아 몬드 모양이 나오게 된다.
// 상속이 되는 두 개의 클래스가 공통의 베이스 클래스를 포함하고 있는 형태
// 이러한 형태의 상속에 문제점은 보기에도 명백하다.

// 만일 Human에 name이라는 멤버 변수가 있다고 하면,
// HandsomeHuman과 SmartHuman은 모두 Human을 상속 받고 있으므로, 여기에서 name이라는 변수가 있다.
// 그런데 Me가 이 두 개의 클래스를 상속 받으니,
// 결과적으로 볼 때 HandsomeHuman과 SmartHuman을 아무리 안겹치게 만든다고 해도,
// Human의 모든 내용이 중복되는 문제가 발생하게 된다.

// 이를 해결할 수 있는 방법이 있다.
// virtual 키워드를 이용한다.
// class HandsomeHuman : public virtual Human {}
// class SmartHuman : public virtual Human {}
// 이러한 형태로 Human을 virtual로 상속 받는다면, 
// Me에서 다중 상속 시에도, 컴파일러가 언제나 Human을 한 번만 포함하도록 지정할 수 있게 한다.

// 가상 상속 시에, Me의 생성자에서 HandsomeHuman과 SmartHuman의 생성자를 호출함은 물론,
// Human의 생성자 또한 호출해 주어야만 한다.

// 다중 상속은 언제 사용해야 할까?
