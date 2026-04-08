#include <stdio.h>
#include <stdbool.h>

#define SIZE 30  // 큐의 크기

typedef struct {
    int data[SIZE];  // 고정된 크기의 배열
    int front;  // 큐의 첫 번째 요소 인덱스
    int rear;   // 큐의 마지막 요소 인덱스
} LinearQueue;

// 초기화 함수
void initQueue(LinearQueue* q) {
    q->front = 0;
    q->rear = -1;  // rear를 -1로 설정하여 첫 번째 삽입 시 0이 되도록 함
}

// 큐가 비어 있는지 확인
bool isEmpty(LinearQueue* q) {
    return q->rear < q->front;  // rear가 front보다 작으면 비어 있음
}

// 큐가 가득 찼는지 확인
bool isFull(LinearQueue* q) {
    return q->rear == SIZE - 1;  // rear가 배열 끝에 도달하면 가득 참
}

// 삽입 함수
bool enqueue(LinearQueue* q, int value) {
    if (isFull(q)) {
        printf("큐가 가득 찼습니다.\n");
        return false;
    }
    q->rear++;
    q->data[q->rear] = value;  // rear 위치에 데이터 추가
    return true;
}

// 삭제 함수
int dequeue(LinearQueue* q) {
    if (isEmpty(q)) {
        printf("큐가 비어 있습니다.\n");
        return -1;  // 큐가 비어 있을 때 -1 반환
    }
    int value = q->data[q->front];
    q->front++;
    if (isEmpty(q)) initQueue(q);
    return value;
}

void printQueue(LinearQueue* q) {
    if (isEmpty(q)) {
        printf("큐가 비어 있습니다.\n");
    }
    else {
        for (int i = q->front; i <= q->rear; i++) {
            printf("queue %d번째 데이터: %d\n", i, q->data[i]);
        }
    }
}

int main() {
    LinearQueue q;
    initQueue(&q);
    int menu;
    int data;

    while (1) {
        printf("\n\n=== 메뉴를 선택해주세요. ===\n");
        printf("1. 삽입\n");
        printf("2. 삭제\n");
        printf("3. 데이터 출력\n");
        printf("4. 종료\n");
        scanf("%d", &menu);

        switch (menu) {
        case 1:
            printf("삽입할 데이터 입력: ");
            scanf("%d", &data);
            enqueue(&q, data);
            break;
        case 2:
			data = dequeue(&q);
            if (data != -1)   printf("Dequeue: %d\n", data);
            break;
        case 3:
            printQueue(&q);
            break;
        case 4:
            printf("프로그램을 종료합니다.");
            return 0;
        default:
            printf("잘못된 값입니다.\n");
            break;
        };
    }

    return 0;
}
