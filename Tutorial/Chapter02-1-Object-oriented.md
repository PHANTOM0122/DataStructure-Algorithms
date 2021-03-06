Object-oriented-design 
===============================
## 2.1-1객체지향 설계 목표
* Software 구성에서 **견고성, 적응성, 재활용성**을 달성해야 한다.

#### 견고성(Robustness)
* 정확한 프로그램을 개발
* 예상되는 모든 입력에 대해서 올바른 출력을 만들어야 한다.
* 명백하게 정의되지 않은 예상치 못한 값들도 취급할 수 있어야 한다

#### 적응성(Adaptability)
* 시간이 지나서 주위 환경 조건들의 변화에 맞춰 발전할 필요가 있다
* 이식성이 중요하다

#### 재활용성(Reusability)
* 코드가 다양한 응용에서 다른 시스템의 component로 사용될 수 있어야만 한다.

## 2.1-2 객체지향 설계 원리

#### 추상화(Abstraction)
* 시스템으로부터 가장 근본적인 개념을 추출하고 이를 정확한 언어로 표현하는 것이다.
* **자료구조에 적용함으로써 추상 데이터 타입(ADT)를 유도한다**
* **ADT: 저장된 자료의 타입과 그들을 지원하는 연산들, 각 연산의 매개변수 타입을 규정한 수학적인 모델**
* **ADT는 구체적 자료구조로 실현되며, Class로 모델링된다.**

#### 캡슐화(Encapsulation)
* **소프트웨어 시스템의 구성요소들이 그들 내부 구현사항을 외부로 드러내지 않아야 하는 것**

#### 모듈화(Modularity)
* **system의 구성 요소들이 반드시 올바르게 상호작용 해야 한다는 개념**

## 2.1-3 디자인 패턴
* **algorithm Design pattern**과 **software engineering pattern**으로 나뉜다
* algorithm pattern : 재귀, 분할 상환, 분할 정복, 전지 탐색, 축소 정복, 부르트-포스, 억지 기법, 그리디, 다이내믹 프로그래밍
* Software engineering : 포지션, 어댑터, 반복자, 탬플릿, 복합, 비교자, 장식자
