// Write a C program to find if a pair exists in an array that sums to a given target and also print their indices if found. [Day: 34]

#include <stdio.h>

int twoSumExists(int n, int arr[], int target) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                return 1;
            }
        }
    }
    return 0;
}

void twoSumIndices(int n, int arr[], int target, int ans[]) {
    ans[0] = -1;
    ans[1] = -1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                ans[0] = i;
                ans[1] = j;
                return;
            }
        }
    }
}

int main() {
    int n, target;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter target sum: ");
    scanf("%d", &target);

    int exists = twoSumExists(n, arr, target);
    if (exists == 1) {
        printf("This is the answer for variant 1: YES\n");
    } else {
        printf("This is the answer for variant 1: NO\n");
    }

    int ans[2];
    twoSumIndices(n, arr, target, ans);
    printf("This is the answer for variant 2: [%d, %d]\n", ans[0], ans[1]);

    return 0;
}
