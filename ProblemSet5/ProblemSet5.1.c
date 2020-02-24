#include <stdio.h>

int main() {

int nums1[5]; 

for (int i = 0; i < 5; i++) {
    nums1[i] = i + 1;
    printf("Index value %d holds element value %d.\n", i, nums1[i]);
}

int nums2[5];

for (int i = 0, j = 6; j > 1; i++, j--) {
    nums2[i] = j - 1;
    
    printf("Index value %d holds element value %d.\n", i, nums2[i]);
}

int add;

for (int i = 0; i < 5; i++) {
    add = nums1[i] + nums2[i];
    printf ("The addition result of nums1[%d] and nums2[%d] is: %d.\n", i, i, add);
}

return 0;
}