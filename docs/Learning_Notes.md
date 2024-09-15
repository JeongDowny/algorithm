# Learning Notes

## Problem 1780

* 분할 정복
* 재귀

* **코드/로직 관련**

재귀함수를 이용하는데 어렵진 않았지만 다음 재귀함수의 인수로 넘겨주는 과정에서 9등분해 tempPaper를 정의하는데 무려 **4중포문** 을 사용했다.. 이에 문제를 느끼고 실제 9등분한 종이를 넘겨주는 것 대신 1/3 사이즈와 종이의 시작 위치를 알려주는 방법으로 바꿨다.

**4중포문** 을 사용한 기존코드

'''cpp
void slice(int n, vector<vector<int>> paper) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(paper[0][0] != paper[i][j]) {
                vector<vector<int>> tempPaper(n/3, vector<int>(n/3, -2));
                for(int x=0; x<n/3; x++) {
                    for(int y=0; y<n/3; y++) {
                        for(int t=0; t<n/3; t++) {
                            for(int s=0; s<n/3; s++) {
                                int paperX = t+n/3*x;
                                int paperY = s+n/3*x;
                                tempPaper[t][s] = paper[paperX][paperY];
                            }
                        }
                        slice(n/3, tempPaper);
                    }
                }
                return;
            }
        }
    }
'''

수정한 코드

'''cpp
int newSize = n/3;
    for(int i=0; i<3; ++i) {
        for(int j=0; j<3; ++j) {
            slice(newSize, paper, x+i*newSize, y+j*newSize);
        }
    }
}
'''

* **메모리/시간초과 관련**

로직 구성을 통해 예시와 동일한 결과를 얻을 수 있었지만 제출 결과는 시간초과였다. 문제는 함수 인자로 이중벡터 변수인 paper를 객체 그대로 넘겨주는데 있었다. 함수 인자로 받아올 때 복사해오기 떄문에 재귀함수 하나가 실행할 때 마다 paper가 새로 생성되는 것 이었다. 이를 해결하기 위해 함수인자을 주소값으로 수정하였고 통과했다.

기존코드

'''cpp
void slice(int n, vector<vector<int>> paper, int x, int y) {
    ...
}
'''

수정코드

'''cpp
void slice(int n, const vector<vector<int>> &paper, int x, int y) {
    ...
}
'''

* **느낀점**

알고리즘을 배우면 배울수록 기본적인 cs지식이 요구된다는 사실을 깨닫는다.