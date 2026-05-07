  # Algorithm Visualizer

  터미널에서 정렬 알고리즘의 동작 과정을 **단계별로 시각화**하는 C++ 프로젝트입니다.
  각 정렬 알고리즘이 배열을 어떻게 처리하는지 직접 눈으로 확인할 수 있습니다.

  ---

  ## 기능

  - 5가지 정렬 알고리즘 구현 및 시각화
  - ncurses 기반 터미널 UI (막대 그래프 형태)
  - 현재 비교/스왑 중인 요소 색상 강조
  - 비교 횟수, 스왑 횟수 실시간 표시
  - 재생 속도 조절 및 스텝 단위 이동 지원

  ---

  ## 색상 의미

  | 색상 | 의미 |
  |------|------|
  | 흰색 | 기본 상태 |
  | 빨간색 | 현재 비교 중인 요소 |
  | 노란색 | 현재 스왑 중인 요소 |
  | 초록색 | 정렬 완료된 요소 |

  ---

  ## 구현된 알고리즘

  ### 버블 정렬 (Bubble Sort)
  - 인접한 두 요소를 비교하여 큰 값을 뒤로 밀어내는 방식
  - 매 패스마다 가장 큰 값이 맨 뒤로 확정됨
  - 시간 복잡도: O(n²)

  ### 선택 정렬 (Selection Sort)
  - 매 회차마다 남은 구간에서 최솟값을 찾아 맨 앞과 교환
  - 스왑 횟수가 최소화되는 특징
  - 시간 복잡도: O(n²)

  ### 삽입 정렬 (Insertion Sort)
  - 현재 요소를 이미 정렬된 앞부분의 적절한 위치에 삽입
  - 거의 정렬된 배열에 효율적
  - 시간 복잡도: O(n²) / 최선 O(n)

  ### 퀵 정렬 (Quick Sort)
  - 피벗(마지막 요소)을 기준으로 배열을 분할하고 재귀적으로 정렬
  - 피벗이 최종 위치에 놓이면 초록색으로 확정
  - 시간 복잡도: 평균 O(n log n) / 최악 O(n²)

  ### 병합 정렬 (Merge Sort)
  - 배열을 반으로 나눈 뒤 재귀적으로 정렬하고 합병
  - 합병 단계에서 임시 배열을 사용하여 두 부분을 병합
  - 시간 복잡도: O(n log n) (항상 일정)

  ---

  ## 프로젝트 구조

  ```
  .
  ├── Makefile
  └── src/
      ├── main.cpp            # 진입점, 알고리즘/배열 크기 선택
      ├── sort_step.h         # Step 구조체 정의 (시각화 데이터 단위)
      ├── visualizer.h        # play() 함수 선언
      ├── visualizer.cpp      # ncurses 기반 시각화 구현
      ├── bubble_sort.cpp
      ├── selection_sort.cpp
      ├── insertion_sort.cpp
      ├── quick_sort.cpp
      └── merge_sort.cpp
  ```

  ### Step 구조체

  모든 정렬 알고리즘은 각 동작마다 `Step` 객체를 생성해 반환합니다.
  `visualizer`는 이 Step 리스트를 순서대로 렌더링합니다.

  ```cpp
  struct Step {
      std::vector<int>  array;          // 현재 배열 상태
      int compare_left  = -1;           // 비교 중인 왼쪽 인덱스 (빨강)
      int compare_right = -1;           // 비교 중인 오른쪽 인덱스 (빨강)
      int swap_left     = -1;           // 스왑 중인 왼쪽 인덱스 (노랑)
      int swap_right    = -1;           // 스왑 중인 오른쪽 인덱스 (노랑)
      std::vector<bool> sorted;         // 확정된 인덱스 여부 (초록)
      int compare_count = 0;
      int swap_count    = 0;
  };
  ```

  ---

  ## 의존성

  - g++ (C++17 이상)
  - ncurses 라이브러리

  ```bash
  # Ubuntu/Debian
  sudo apt install libncurses-dev

  # macOS
  brew install ncurses
  ```

  ---

  ## 빌드 및 실행

  ```bash
  make
  ./sort_vis
  ```

  ---

  ## 사용법

  실행하면 두 가지를 선택합니다.

  ```
  === 정렬 알고리즘 선택 ===
  1. 버블 정렬
  2. 선택 정렬
  3. 삽입 정렬
  4. 퀵 정렬
  5. 병합 정렬
  선택:

  === 배열 크기 선택 ===
  1. 10개
  2. 20개
  3. 50개
  크기 선택:
  ```

  선택 후 시각화가 시작됩니다.

  ### 조작키

  | 키 | 동작 |
  |----|------|
  | `Space` | 일시정지 / 재생 |
  | `→` | 다음 스텝으로 이동 |
  | `←` | 이전 스텝으로 이동 |
  | `+` | 재생 속도 증가 |
  | `-` | 재생 속도 감소 |
  | `Q` | 종료 |

  ---

  ## 빌드 정리

  ```bash
  make clean
  ```