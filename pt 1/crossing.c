#include <stdio.h>
#include <limits.h>

typedef struct {
    int low;
    int high;
    int sum;
} SubArrayResult;

SubArrayResult find_max_crossing_subarray(int a[], int low, int mid, int high) {
    int left_sum = INT_MIN;
    int sum = 0;
    int max_left = mid;
    int max_right = mid / 2;

    for (int i = mid; i >= low; i--) {
        sum += a[i];
        if(sum > left_sum) {
            left_sum = sum;
            max_left = i;
        }
    }

    int right_sum = INT_MIN;
    sum = 0;
    for (int j = mid + 1; j <= high; j++) {
        sum += a[j];
        if (sum > right_sum) {
            right_sum = sum;
            max_right = j;
        }
    }

    SubArrayResult result = {
        max_left,
        max_right,
        left_sum + right_sum
    };

    return (SubArrayResult) {
        .low = max_left,
        .high = max_right,
        .sum = left_sum + right_sum
    };
}

SubArrayResult find_maximum_subarray(int a[], int low, int high) {
    if (high == low) {
        return (SubArrayResult) {
            .low = low,
            .high = high,
            .sum = a[low]
        };
    } else {
        int mid = (low + high) / 2;
        SubArrayResult left = find_maximum_subarray(a, low, mid);
        SubArrayResult right = find_maximum_subarray(a, mid + 1, high);
        SubArrayResult cross = find_max_crossing_subarray(a, low, mid, high);

        if (left.sum >= right.sum && left.sum >= cross.sum) {
            return left;
        } else if (right.sum >= left.sum && right.sum >= cross.sum) {
            return right;
        } else {
            return cross;
        }
    }
}

int main() {
    int a[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    for (int i = 0; i < 16; i++) {
        printf("%d, ", a[i]);
    }
    printf("\n");

    SubArrayResult result = find_maximum_subarray(a, 0, 15);
    printf("Low: %d, Mid: %d, High: %d\n", result.low, result.high, result.sum);

    getchar();
}