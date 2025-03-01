// 자료 구조( data - structure )
// 
// data : int, float, char  *,&,[] // struct, class
// 
// 자료 : 기본 자료형, 복합 자료형
// 기본 자료형 : int, float, double, char...프로그래밍 언어를 사용하기 위한 기본
// 복합 자료형 : 기본 자료형으로 표현하기 힘든 자료형을 새롭게 정의한 것
// 
// 자료 구조 : 데이터를 잘 사용하기 위해서 분류하는 것
// 시간 - 프로그램 실행 시간이 빠를수록 좋다. (0.1초) (0.01초)
// 간단한 예시1. 1개 0.1초, 0.01초 2개의 case 시간이 크게 중요하지 않다.
// 공간 - 100kb 1mb
// 1번째 프로그램을 사용해야겠다.
// 
// 플레이어 개인 창고를 위한 클래스 : Item
// Item item[3];
// 1. 롱소드 2. 방패 3. 갑옷 4. 망치
// item[0] = 롱소드, item[1] = 방패, item[2] = 갑옷 // 배열을 데이터를 처음 선언 후 변경할수 없다.
// item[0] = null, item[1] = 방패, item[2] = 갑옷
// item[0] = 망치, item[1] = 방패, item[2] = 갑옷
// 
// 플레이어가 착용하고 있는 아이템 정보 : item 정보를 전부다 검색
// Item item[2] = new item();
// 아이템의 추가 또는 삭제가 있을때마다 배열을 새로 만들어줘야 한다.
// 
// ★자료 구조를 배우는 이유★
// 데이터를 잘 정리하기 위한 도구.
// 시간, 공간
// 자료구조를 선택한다. 각 자료구조의 장점과 단점을 파악.
// 
// 
// 자료구조의 분류 : 선형 자료구조, 비선형 자료구조
// 
// 0. 배열 : 포인터, 포인터의 연산 - 배열 (ptr + 1) arr[0 + 1]
// 배열의 특징 : 연속적인 메모리 공간에 저장된다.
// 
// ADT ( abstract data type ) 추상 데이터 형식
// 자료형(가변 배열) : 배열인데 길이를 변경할 수 있는 배열. - class MyVector, class vector
// 자료구조는 같은 종류라도 다양한 클래스가 존재할 수 있나요? -> 있습니다.
// 호환성 : 버전이 변경되도 기존 기능을 제공해주는 것. A회사 프로그램 - B회사 프로그램
// 자료구조 : AVector BVector
// 직접 자료구조를 만드는 경우는 드물다. STL(Standard Template Library) <- 사용하는 방법을 익히게 될것임
// 
// 
// 1. 가변 배열(vector)
// 2. 연결 리스트(linked list)
// 3. 스택, 큐
// 4. 힙
// 
// 5. 트리
// 6.그래프
//